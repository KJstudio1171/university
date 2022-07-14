using System;
using System.Collections.Generic;
using System.Threading;
using System.Diagnostics;

/// 2017920014 컴퓨터과학부 김준 운영체제 과제

namespace ConsoleApplication
{
    class Node
    {
        private int? data;
        private Node nextNode;
        public Node()
        {
            this.data = null;
            this.nextNode = null;
        }
        public int? Data
        {
            get { return data; }
            set { data = value; }
        }
        public Node NextNode
        {
            get { return nextNode; }
            set { nextNode = value; }
        }
    }

    class LinkedList
    {
        private Node headNode;
        private HazardPointer headHazard;
        public LinkedList()
        {
            this.headNode = null;
        }

        private HazardPointer AllocationHazard()
        {
            HazardPointer p;
            for (p = headHazard; p != null; p = p.NextHazard)
            {
                if (Interlocked.CompareExchange(ref p.active, 1, 0) == 0)
                {
                    return p;
                }
            }
            p = new HazardPointer();
            p.active = 1;
            p.NextHazard = null;

            HazardPointer q;

            while (true)
            {
                q = headHazard;
                p.NextHazard = headHazard;
                if (Interlocked.CompareExchange(ref this.headHazard, p, q) == q)
                    return p;
            }
        }

        private void ReleaseHazard(HazardPointer p)
        {
            p.active = 0;
            p.NextHazard = null;
        }

        private void RetireNode(Node retire)
        {
            while (true)
            {
                if (Scan(retire))
                    break;
            }
        }
        private bool Scan(Node data)
        {
            List<Node> list = new List<Node>();
            for (HazardPointer p = headHazard; p != null; p = p.NextHazard)
            {
                if (p.ActiveNode != null && p.active == 1)
                    list.Add(p.ActiveNode);
            }

            foreach (Node node in list)
            {
                if (node == data)
                {
                    return false;
                }
            }

            return true;
        }

        public void Push(Node freeNode, int? data)
        {
            Node node;
            freeNode.Data = data;
            while (true)
            {
                node = this.headNode;
                freeNode.NextNode = node;
                if (Interlocked.CompareExchange(ref this.headNode, freeNode, node) == node)
                    break;
            }
        }

        public Node Pop()
        {
            Node node;
            HazardPointer hazardPointer = AllocationHazard();
            while (true)
            {
                node = this.headNode;
                if (node == null)
                {
                    ReleaseHazard(hazardPointer);
                    return null;
                }
                hazardPointer.ActiveNode = node;
                if (node != this.headNode)
                    continue;
                if (Interlocked.CompareExchange(ref this.headNode, node.NextNode, node) == node)
                {
                    ReleaseHazard(hazardPointer);
                    RetireNode(node);
                    break;
                }
            }
            node.NextNode = null;
            return node;
        }

        public void PrintLinkedList()
        {
            Node node = this.headNode;
            int length = 0;
            while (node != null)
            {
                length++;
                node = node.NextNode;

            }
            Console.WriteLine("노드의 개수는 총 {0}개 입니다. ", length);
        }
    }

    class HazardPointer
    {
        public int active;
        private Node activeNode;
        private HazardPointer nextHazard;

        public Node ActiveNode
        {
            get { return activeNode; }
            set { activeNode = value; }
        }

        public HazardPointer NextHazard
        {
            get { return nextHazard; }
            set { nextHazard = value; }
        }
    }

    class Program
    {
        private static volatile LinkedList freelist = new LinkedList();
        private static volatile LinkedList headlist = new LinkedList();

        static void ThreadBody()
        {
            int n = 10;
            int m = 5;

            for (int i = 0; 1000 > i; i++)
            {
                for (int j = 0; n > j; j++)
                {
                    Node node = freelist.Pop();
                    if (node == null)
                    {
                        continue;
                    }
                    headlist.Push(node, null);
                }
                for (int j = 0; m > j; j++)
                {
                    Node node = headlist.Pop();
                    if (node == null)
                        continue;
                    freelist.Push(node, null);
                }
            }
        }

        static void InitFreeList()
        {
            for (int i = 0; 1000000 > i; i++)
            {
                Node node = new Node();
                freelist.Push(node, 0);
            }
        }

        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            Console.WriteLine("2017920014 컴퓨터과학부 김준 운영체제 과제2");
            Console.WriteLine("100000개의 free 노드");
            Console.WriteLine("3개의 쓰레드는 10X1000번씩 Free List에 미사용 노드가 있으면 미사용 노드를 가져와 push() 함수로 Head List에 노드를 삽입한다.");
            Console.WriteLine("3개의 쓰레드는 5X1000번씩 Head List에 노드가 존재하면 pop 연산으로 Head List에서 노드를 제거하고 Free List로 보낸다");
            InitFreeList();
            Console.WriteLine("freeList의 노드의 개수는");
            freelist.PrintLinkedList();
            Thread t = new Thread(ThreadBody);
            Thread y = new Thread(ThreadBody);
            Thread u = new Thread(ThreadBody);

            t.Start();
            y.Start();
            u.Start();

            t.Join();
            y.Join();
            u.Join();
            Console.WriteLine("/////////////프로그램 작동후/////////////////");
            Console.WriteLine("FreeList의 노드의 개수는");
            freelist.PrintLinkedList();
            Console.WriteLine("HeadList의 노드의 개수는");
            headlist.PrintLinkedList();
            stopwatch.Stop();
            Console.WriteLine("time:"+stopwatch.ElapsedMilliseconds+"ms");
        }
    }
}
using System;
using System.Diagnostics;
using System.Threading;

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
        private static Mutex mutex = new Mutex();

        public LinkedList()
        {
            this.headNode = null;
        }

        public void Push(Node freeNode, int? data)
        {
            mutex.WaitOne();
            Node node;
            freeNode.Data = data;
            node = this.headNode;
            freeNode.NextNode = node;
            headNode = freeNode;

            mutex.ReleaseMutex();
        }

        public Node Pop()
        {
            mutex.WaitOne();
            Node node;

            node = this.headNode;
            if (node == null)
            {
                mutex.ReleaseMutex();
                return null;
            }
            headNode = node.NextNode;

            node.NextNode = null;
            mutex.ReleaseMutex();
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
            Console.WriteLine("2017920014 컴퓨터과학부 김준 운영체제 과제3");
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
            Console.WriteLine("time:" + stopwatch.ElapsedMilliseconds + "ms");
        }
    }
}
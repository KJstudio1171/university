using System;
using System.Threading;

/// 2017920014 컴퓨터과학부 김준 운영체제 과제

namespace ConsoleApplication
{
    class Program
    {
        private static volatile string _str = "abc";
        private static volatile int _val1 = 0;
        private static volatile int _val2 = 0;
        static void AppendStr(string newstr)
        {
            while (true)
            {
                var original = Interlocked.CompareExchange(ref _str, null, null);
                var newString = original + newstr;
                if (Interlocked.CompareExchange(ref _str, newString, original) == original)
                    break;
            }
        }

        static void AddValue(int value)
        {
            while (true)
            {
                var orgVal = _val1;
                var newVal = orgVal + value;
                if (Interlocked.CompareExchange(ref _val1, newVal, orgVal) == orgVal)
                    break;
            }
        }

        static void ThreadBody1()
        {
            for (int i = 0; i < 100000; i++) 
                AddValue(1);
        }

        static void ThreadBody2()
        {
            for (int i = 0; i < 100000; i++) 
                _val2++;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("2017920014 컴퓨터과학부 김준 운영체제 과제1");
            Console.WriteLine("Hello");
            AppendStr("xx");
            Console.WriteLine(_str);

            Thread t1 = new Thread(ThreadBody1);
            Thread t2 = new Thread(ThreadBody1);
            Thread t3 = new Thread(ThreadBody1);
            Thread t4 = new Thread(ThreadBody1);

            Thread t5 = new Thread(ThreadBody2);
            Thread t6 = new Thread(ThreadBody2);
            Thread t7 = new Thread(ThreadBody2);
            Thread t8 = new Thread(ThreadBody2);


            t1.Start();
            t2.Start();
            t3.Start();
            t4.Start();

            t5.Start();
            t6.Start();
            t7.Start();
            t8.Start();

            t1.Join();
            t2.Join();
            t3.Join();
            t4.Join();

            t5.Join();
            t6.Join();
            t7.Join();
            t8.Join();
            Console.WriteLine("AddVal(1) 함수를 호출하여 원자적으로 값을 증가시킬 때");
            Console.WriteLine(_val1);
            Console.WriteLine("단순히 덧셈 연산으로  값을 증가시킬 때");
            Console.WriteLine(_val2);
        }
    }
}

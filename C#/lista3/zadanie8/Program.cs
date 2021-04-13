using System;
using System.Collections.Generic;
using System.Linq;

namespace zadanie8
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            List<int> list = new List<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

            Func<int, int> Y = null;
            Y = i => i > 2 ? Y(i - 1) + Y(i - 2) : 1;
            foreach (var item in list.Select(Y))
            {
                Console.WriteLine(item);
            }
        }
    }
}
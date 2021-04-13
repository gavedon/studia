using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

//The diff is, that Func<> params require lambdas like x => x<2 to be used and 'LINQ-style' syntax needs artmetic expresions only like x<2
namespace zadanie2
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"/home/krzysztof/RiderProjects/lista3/zadanie2/input.txt");
            int[] numbers = Array.ConvertAll(input, s => Int32.Parse(s));
           
            var query =
                from num in numbers
                where num > 100
                orderby num descending
                select num;

            var alsoQuery = numbers.Where(x => x > 100).OrderByDescending(x => x);

            Console.WriteLine("LINQ-style:");
            foreach (int num in query)
            {
                Console.WriteLine(num);
            }

            Console.WriteLine();
            Console.WriteLine("LINQ-to-Objects:");
            foreach (int num in alsoQuery)
            {
                Console.WriteLine(num);
            }
        }
    }
}
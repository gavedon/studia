using System;
using System.IO;
using System.Linq;

namespace zadanie3
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string[] surnames = File.ReadAllLines(@"/home/krzysztof/RiderProjects/lista3/zadanie3/surnames.txt");

            var firstL =
                from surname in surnames
                group surname by surname[0] into first
                orderby first.Key  
                select first.Key;

            foreach (var item in firstL)
            {
                Console.WriteLine(item);
            }
        }
    }
}
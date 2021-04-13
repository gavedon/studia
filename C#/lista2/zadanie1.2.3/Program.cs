using System;
using System.Collections.Generic;

namespace zadanie1._2._3
{
    public class Program
    {
        static void Main(string[] args)
        {
            List<double> list = new List<double>{32.6, -12.3, 22.6, 43.5, -24.7, -19, 10.1, 45.9, -61.8, 50.2};
            
            Console.WriteLine("Initial list:");
            foreach (var item in list)
                Console.Write(item + "|");
            Console.WriteLine("\n");
            
            // ConvertAll
            List<double> negValues = list.ConvertAll(x => -x );
            Console.WriteLine("Initial values having sign changed: ");
            foreach (var item in negValues)
                Console.Write(item + "|");
            Console.WriteLine("\n");

            // FindAll:
            List<double> findList= list.FindAll(x => x>0);
            Console.WriteLine("Non-negative values: ");
            foreach (var item in findList) 
                Console.Write(item + "|");
            Console.WriteLine("\n");

            // ForEach:
            Console.WriteLine("Initial values multiplied by two"); 
            list.ForEach(delegate (double x) {x= x * 2; Console.Write(x + "|");});
            Console.WriteLine("\n");

            // RemoveAll:
            int removeList = list.RemoveAll(x => x > 0);
            Console.WriteLine("Number of removed elements is equal to: {0}\n", removeList);

            // Sort:
            list.Sort();
            
            Console.WriteLine("Sorted initial list: ");
            foreach (var item in list)
                Console.Write(item + "|");
        }   
    }
}
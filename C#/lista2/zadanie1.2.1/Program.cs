using System;
using System.Collections;
using System.Collections.Generic;

namespace zadanie1._2._1
{
    public class CompareGenerics
    {
        static ArrayList arraylist = new ArrayList();
        static List<int> list = new List<int>();
        static Hashtable hashtable = new Hashtable();
        static Dictionary<int, int> dictionary = new Dictionary<int, int>();
        public static void AddElems()
        {
            Console.WriteLine("Adding:");
            DateTime start = DateTime.Now;
            for(int i = 0; i < 1000000; i++)
                arraylist.Add(i);
            DateTime end = DateTime.Now;
            TimeSpan time = end - start;
            Console.WriteLine("ArrayList: " + time);

            start = DateTime.Now;
            for(int i = 0; i < 1000000; i++) 
                list.Add(i);      
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("List<T>: " + time);

            start = DateTime.Now;
            for(int i = 0; i < 1000000; i++)
                hashtable.Add(i,i);
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("Hashtable: " + time);

            start = DateTime.Now;
            for(int i = 0; i < 1000000; i++)
                dictionary.Add(i,i);
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("Dictionary<T>: " + time);
            Console.WriteLine();
        }
        
        public static void Search()
        {
            Console.WriteLine("Searching:");
            DateTime start = DateTime.Now;
            foreach (int i in arraylist) {}
            DateTime end = DateTime.Now;
            TimeSpan time = end - start;
            Console.WriteLine("ArrayList: " + time);

            start = DateTime.Now;
            foreach (int i in list) {}
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("List<T>: " + time);

            start = DateTime.Now;
            foreach (DictionaryEntry i in hashtable) {}
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("Hashtable: " + time);

            start = DateTime.Now;
            foreach (KeyValuePair<int, int> i in dictionary) {}
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("Dictionary<T>: " + time);
            Console.WriteLine();

        }

        public static void DeleteElems()
        {
            Console.WriteLine("Deleting");
            DateTime start = DateTime.Now;
            for (int i = 10000; i > 0; i--) {
                arraylist.Remove(i);
            }
            DateTime end = DateTime.Now;
            TimeSpan time = end - start;
            Console.WriteLine("ArrayList: " + time);

            start = DateTime.Now;
            for (int i = 10000; i > 0; i--)
                list.Remove(i);
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("List<T>: " + time);

            start = DateTime.Now;
            for (int i = 10000; i > 0; i--)
                hashtable.Remove(i);
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("Hashtable: " + time);

            start = DateTime.Now;
            for (int i = 10000; i > 0; i--)
                dictionary.Remove(i);
            end = DateTime.Now;
            time = end - start;
            Console.WriteLine("Dictionary<T>: " + time);
            Console.WriteLine();

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            CompareGenerics.AddElems();
            CompareGenerics.Search();
            CompareGenerics.DeleteElems();
        }
    }
}

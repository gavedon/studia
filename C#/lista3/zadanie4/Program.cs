using System;
using System.Linq;
using System.IO;

namespace zadanie4
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            DirectoryInfo dir = new DirectoryInfo(@"/home/krzysztof/RiderProjects/lista3/");
            FileInfo[] files = dir.GetFiles("*.*", SearchOption.TopDirectoryOnly);
  
            var query =
                from file in files
                select file.Length;

            long result = query.Aggregate((sum, next) => sum+ next);
            Console.WriteLine(result);
        }
    }
}
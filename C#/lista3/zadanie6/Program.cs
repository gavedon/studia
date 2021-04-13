using System;
using System.Linq;
using System.IO;

namespace zadanie6
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string[] logs = File.ReadAllLines(@"/home/krzysztof/RiderProjects/lista3/zadanie6/iis5.5logs.txt");
            var register =
                from log in logs
                select new { time = log.Split(' ')[0], ip_adress = log.Split(' ')[1], inquiry = log.Split(' ')[2], resourse_name = log.Split(' ')[3], answer = log.Split(' ')[4]};
            var query =
                (from log in register
                    group log by log.ip_adress into result
                    orderby result.Count() descending
                    select new { ip = result.Key, count = result.Count()}).Take(3);
            foreach (var item in query)
            {
                Console.WriteLine("{0} {1}", item.ip, item.count);
            }
        }
    }
}
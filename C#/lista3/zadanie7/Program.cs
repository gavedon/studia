using System;
using System.Collections.Generic;
using System.Linq;

namespace zadanie7
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var item1 = new { Field1 = "The value1", Field2 = 2 };
            var item2 = new { Field1 = "The value2", Field2 = 1 };
            var item3 = new { Field1 = "The value3", Field2 = 3 };
            var item4 = new { Field1 = "The value3", Field2 = 7 };
            
            var list = new List<object>().Select(obj => new { Field1 = default(string), Field2 = default(int) }).ToList();
            list.Add(item1);
            list.Add(item2);
            list.Add(item3);
            list.Add(item4);

            foreach (var item in list)
            {
                Console.WriteLine("{0} {1}", item.Field1, item.Field2);
            }
        }
    }
}
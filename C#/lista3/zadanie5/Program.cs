using System;
using System.Linq;
using System.IO;

namespace zadanie5
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string[] people = File.ReadAllLines(@"/home/krzysztof/RiderProjects/lista3/zadanie5/person.txt");
            string[] accounts = File.ReadAllLines(@"/home/krzysztof/RiderProjects/lista3/zadanie5/bankaccount.txt");
            
            var ppl =
                from person in people
                select new { name = person.Split(' ')[0], surname = person.Split(' ')[1], pesel = person.Split(' ')[2]};
            var accs =
                from account in accounts
                select new { pesel = account.Split(' ')[0], number = account.Split(' ')[1]};

            var joint =
                from person in ppl
                join account in accs on person.pesel equals account.pesel
                select new {p=person.name, i=person.surname, e=person.pesel, s=account.number};
            
            foreach (var item in joint)
            {
                Console.WriteLine("{0} {1} {2} {3}", item.p, item.i, item.e, item.s);
            }
        }
    }
}
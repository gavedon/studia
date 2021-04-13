using System;
using System.Reflection;
using System.Linq;

namespace zadanie1._1._4
{
    public class Oznakowane : Attribute { }
    public class Example
    {
        [Oznakowane]
        public int fun() //good one
        {
            return 2;
        }

        public int func() //not marked
        {
            return 1;
        }
        [Oznakowane] //private
        private int funct()
        {
            return 3;
        }
        [Oznakowane] //with params
        public int functi(int x)
        {
            return 4;
        }
        [Oznakowane] //static
        public static int functio()
        {
            return 5;
        }

        [Oznakowane] //dobule instead of int
        public double function()
        {
            return 6.0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Example example = new Example();
            ReturnMethods(example);
        }
        static void ReturnMethods(object o)
        {
            MethodInfo[] methods = o.GetType().GetMethods();
            foreach(MethodInfo method in methods)
            {
                if(method.IsPublic 
                   && !method.IsStatic && method.ReturnType == typeof(int) 
                   && method.GetParameters().Length == 0 
                   && method.GetCustomAttributes(typeof(Oznakowane), false).Any())
                {
                    Console.WriteLine(method.Invoke(o, null));
                }
            }
        }
    }
}
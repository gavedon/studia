using System;
using System.Reflection;

namespace zadanie1._1._3_
{
    public class Example
    {
        private int privateProp;
        private int publicProp;

        private int PrivateProp { get; set; }
        public int PublicProp { get; set; }

        private void PrivateMethod()
        {
        }

        public void PublicMethod()
        {
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Example example = new Example();
            try
            {
                MethodInfo privMethod = example.GetType()
                    .GetMethod("PrivateMethod", BindingFlags.Instance | BindingFlags.NonPublic);
                privMethod.Invoke(example, null);

                PropertyInfo privProp = example.GetType()
                    .GetProperty("PrivateProp", BindingFlags.Instance | BindingFlags.NonPublic);
                privProp.SetValue(example, 2137);
                var val = (int) privProp.GetValue(example, null);
                
                //1
                DateTime start = DateTime.Now;
                for (int k = 0; k < 10000; k++)
                {
                    example.PublicMethod();
                }

                DateTime end = DateTime.Now;
                TimeSpan time = end - start;
                Console.WriteLine("Method without reflection: " + time);
                
                //2
                start = DateTime.Now;
                for (int k = 0; k < 10000; k++)
                {
                    example.GetType().GetMethod("PublicMethod", BindingFlags.Instance | BindingFlags.Public)
                        .Invoke(example, null);
                }

                end = DateTime.Now;
                time = end - start;
                Console.WriteLine("Method with reflection: " + time);
                
                //3
                start = DateTime.Now;
                end = DateTime.Now;
                for (int k = 0; k < 10000; k++)
                {
                    example.PublicProp = 2137;
                }

                time = end - start;
                Console.WriteLine("Property without reflection: " + time);
                
                //4
                start = DateTime.Now;
                for (int k = 0; k < 10000; k++)
                {
                    example.GetType().GetProperty("PublicProp", BindingFlags.Instance | BindingFlags.Public)
                        .SetValue(example, 2137);
                }

                end = DateTime.Now;
                time = end - start;
                Console.WriteLine("Property with reflection: " + time);
            }
            catch (NullReferenceException e)
            {
                
            }
        }
    }
}

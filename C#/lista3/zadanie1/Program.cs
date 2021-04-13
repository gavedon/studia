using System;

namespace zadanie1
{
    public static class StringExtensions
    {
        public static bool IsPalindrome(this string phrase)
        {
            int start = 0;
            int end = phrase.Length;
            while (start < end-1)
            {
                if (Char.IsWhiteSpace(phrase[start]) || Char.IsPunctuation(phrase[start])) //start diff from blank space or ,. and so on
                {
                    start++;
                    continue;
                }
                if (Char.IsWhiteSpace(phrase[end-1]) || Char.IsPunctuation(phrase[end-1])) // same as above, but end is an arg now
                {
                    end--;
                    continue;
                }
                if (Char.ToLower(phrase[start]) != Char.ToLower(phrase[end-1])) // compare end with start lowering both to lowercase
                {
                    return false;
                }
                start++;
                end--;
            }
            return true;
        }
    }

    internal class Program
    {
        public static void Main(string[] args)
        {
            string s = "Kobyła ma mały bok.";
            string w = "ala2137";
            Console.WriteLine(s.IsPalindrome());
            Console.WriteLine(w.IsPalindrome());
        }
    }
}
using System;

namespace proxy
{
    class Program
    {
        static void Main(string[] args)
        {
            string password=Console.ReadLine();

            Proxy proxy = new Proxy(password);
            proxy.DoSomeThing();

            Console.ReadKey();
        }
    }
}

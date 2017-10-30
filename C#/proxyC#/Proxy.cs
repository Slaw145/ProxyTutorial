using System;
using System.Collections.Generic;
using System.Text;

namespace proxy
{
    class Proxy : ExampleInterface
    {
        private ExampleInterface exampleClass;
        private string password {get;set;}

        public Proxy(string password)
        {
            this.password = password;
        }

        private void CreateInstanceExampleClass()
        {
            exampleClass = new ExampleClass();
        }

        public void DoSomeThing()
        {
            if(password=="root")
            {
                CreateInstanceExampleClass();
                exampleClass.DoSomeThing();
            }
            else
            {
                Console.WriteLine("Wrong password");
            }
        }
    }
}

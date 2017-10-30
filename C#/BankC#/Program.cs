using System;

namespace CartbankC
{
    class Program
    {
        static void Main(string[] args)
        {
            int pin = int.Parse(Console.ReadLine());

            CartBank cartbank = new CartBank();
            cartbank.getPIN(pin);

            if (cartbank.IfPinIsValid)
            {
                Console.WriteLine("Wprowadzono poprawny pin, co chcesz zrobić?");
                Console.WriteLine("Wypłać 4000zł z banku");
                cartbank.PayOutMoneyFromAccount(4000);
                Console.WriteLine("na koncie zostało ci: " + cartbank.CheckStateAccount() + " zł");
            }
            else
            {
                Console.WriteLine("Wprowadzono niepoprawny pin, spróbuj jescze raz");
            }

            Console.ReadKey();
        }
    }
}

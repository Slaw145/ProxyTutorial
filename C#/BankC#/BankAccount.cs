using System;
using System.Collections.Generic;
using System.Text;

namespace CartbankC
{
    class BankAccount : IPayment
    {
        private double StateMyAccount = 10000;

        public double CheckStateAccount()
        {
            return StateMyAccount;
        }

        public void PayOutMoneyFromAccount(double AmountPayedOutMoney)
        {
            StateMyAccount = StateMyAccount - AmountPayedOutMoney;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Text;

namespace CartbankC
{
    class CartBank:IPayment
    {
        IPayment BankAccount;
        private int PIN;
        public bool IfPinIsValid;

        public void getPIN(int pin)
        {
            PIN = pin;
            CheckPinIsValid();
        }

        private void CheckPinIsValid()
        {
            if (PIN == 1223)
            {
                OpenAccessToAccount();
                IfPinIsValid = true;
            }
            else
            {
                IfPinIsValid = false;
            }
        }

        private void OpenAccessToAccount()
        {
            PaymentFactory paymentfactory = new BankAccountFactory();

            BankAccount = paymentfactory.Bank();
        }

        public double CheckStateAccount()
        {
            return BankAccount.CheckStateAccount();
        }

        public void PayOutMoneyFromAccount(double AmountPayedOutMoney)
        {
            BankAccount.PayOutMoneyFromAccount(AmountPayedOutMoney);
        }
    }
}

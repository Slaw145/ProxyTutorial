using System;
using System.Collections.Generic;
using System.Text;

namespace CartbankC
{
    abstract class PaymentFactory
    {
        public abstract IPayment Bank();
    }

    class BankAccountFactory : PaymentFactory
    {
        public override IPayment Bank()
        {
            return new BankAccount();
        }
    }
}

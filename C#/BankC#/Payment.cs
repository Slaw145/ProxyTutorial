using System;
using System.Collections.Generic;
using System.Text;

namespace CartbankC
{
    interface IPayment
    {
        double CheckStateAccount();
        void PayOutMoneyFromAccount(double AmountPayedOutMoney);
    }
}

#pragma once

#include <iostream>

using namespace std;

class IPayment
{
public:
	virtual double  CheckStateAccount()=0;
	virtual void  PayOutMoneyFromAccount(double AmountPayedOutMoney)=0;
};

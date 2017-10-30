#include "stdafx.h"
#include <iostream>
#include "IPayment.h"
using namespace std;

class BankAccount : public IPayment
{
private:
	double StateMyAccount = 10000;

public:
	double IPayment::CheckStateAccount()
	{
		return StateMyAccount;
	}

public:
	void IPayment::PayOutMoneyFromAccount(double AmountPayedOutMoney)
	{
		StateMyAccount = StateMyAccount - AmountPayedOutMoney;
	}
};
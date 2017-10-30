#include "stdafx.h"
#include <iostream>
#include "BankAccount.cpp"

using namespace std;

class PaymentFactory
{
public:
	virtual BankAccount Bank()=0;
};

class BankAccountFactory : public PaymentFactory
{
public:
	BankAccount PaymentFactory::Bank()
	{
		return BankAccount();
	}
};
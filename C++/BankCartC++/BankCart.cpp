﻿// BankCart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <string>
#include "PaymentFactory.cpp"

using namespace std;

class CartBank : public IPayment
{
public:
	BankAccount BankAccount;
	bool IfPinIsValid;
private:
	int PIN;

public:
	void getPIN(int pin)
	{
		PIN = pin;
		CheckPinIsValid();
	}

private:
	void CheckPinIsValid()
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

private:
	void OpenAccessToAccount()
	{
		BankAccountFactory paymentfactory = BankAccountFactory();

		BankAccount = paymentfactory.Bank();
	}

public:
	double CheckStateAccount()
	{
		return BankAccount.CheckStateAccount();
	}

public:
	void PayOutMoneyFromAccount(double AmountPayedOutMoney)
	{
		BankAccount.PayOutMoneyFromAccount(AmountPayedOutMoney);
	}
};

int main()
{
	int pin;
	cin >> pin;

	CartBank cartbank = CartBank();
	cartbank.getPIN(pin);

	if (cartbank.IfPinIsValid)
	{
		cout << "The correct pin has been entered, what do you want to do?" << endl;
		cout << "Withdraw 4,000 USD from the bank" << endl;
		cartbank.PayOutMoneyFromAccount(4000);
		cout << "You have: " << cartbank.CheckStateAccount() << " USD left in your account" << endl;
	}
	else
	{
		cout << "Incorrect pin entered, try again" << endl;
	}
	return 0;
}


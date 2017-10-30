// BankCart.cpp : Defines the entry point for the console application.
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
		cout << "Wprowadzono poprawny pin, co chcesz zrobić?" << endl;
		cout << "Wypłać 4000zł z banku" << endl;
		cartbank.PayOutMoneyFromAccount(4000);
		cout << "na koncie zostało ci: " << cartbank.CheckStateAccount() << " zł" << endl;
	}
	else
	{
		cout << "Wprowadzono niepoprawny pin, spróbuj jescze raz" << endl;
	}
	return 0;
}


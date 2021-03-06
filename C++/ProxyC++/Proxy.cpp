// Proxy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ExampleClass.cpp"

using namespace std;

class Proxy : public ExampleInterface
{
	private:
		ExampleInterface *exampleClass;
		string password;

	public:Proxy::Proxy(string p)
	{
		password = p;
	}

	private:
		void CreateInstanceExampleClass()
		{
			exampleClass = new ExampleClass();
		}
    public:
		void DoSomeThing()
		{
			if (password == "root")
			{
				CreateInstanceExampleClass();
				exampleClass->DoSomeThing();
			}
			else
			{
				cout << "Wrong password" << endl;
			}
		}
};

int main()
{
	string password;
	cin >> password;
	Proxy proxy(password);
	proxy.DoSomeThing();
	return 0;
}

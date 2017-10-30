#include "stdafx.h"
#include <iostream>
#include "ExampleInterface.h"

using namespace std;

class ExampleClass:public ExampleInterface
{
   public:
	void DoSomeThing()
	{
		cout << "Do something" << endl;
	}
};
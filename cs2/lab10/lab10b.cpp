/*Colby Holmes
Lab10b
CSCE 1040
4/9/15*/

#include<iostream>
#include<string>
#include"bank.h"
using namespace std;

int main()
{
//creates variables
	string choice;
	int num1, val, num2;
	Bank wellsfargo;
//prints message and scans input	
	cout << "bank> ";
	cin >> choice; 
	if (choice.compare("deposit") == 0 || choice.compare("withdraw") == 0)
	{	
		cin >> num1 >> val;
	}
	else if(choice.compare("balance") == 0)
	{
		cin >> num1;
	}
	else if(choice.compare("transfer") == 0)
	{
		cin >> num1 >> num2 >> val;
	}

	while(choice.compare("exit") != 0)
	{	
//menu (call appropriate function)
		if(choice.compare("deposit") == 0)
		{
			wellsfargo.deposit(num1, val);
		}
		else if(choice.compare("withdraw") == 0)
		{
			wellsfargo.withdraw(num1, val);
		}
		else if(choice.compare("balance") == 0)
		{
			wellsfargo.balance(num1);
		}
		else if(choice.compare("transfer") == 0)
		{
			wellsfargo.transfer(num1, num2, val);
		}
//input for next iteration		
		cout << "bank> ";
		cin >> choice;

	        if (choice.compare("deposit") == 0 || choice.compare("withdraw") == 0)
        	{
                	cin >> num1 >> val;
        	}	
        	else if(choice.compare("balance") == 0)
        	{
               		 cin >> num1;
        	}
        	else if(choice.compare("transfer") == 0)
        	{
                	cin >> num1 >> num2 >> val;
        	}
	}
//exit
	return 0;
}

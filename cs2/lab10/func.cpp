#include"bank.h"
#include<iostream>
using namespace std;

void deposit( int num, int value)
{
	acctnum(num) += value;
}

void withdraw(int num, int value)
{
	if (value > acctnum(num))
	{
		cout << "Insufficient Funds!" << endl;
	}
	else
	{
	acctnum(num) -= value;
	}
}

void balance(int num)
{
	cout << "Balance: " << acctnum(num) << endl;
}

void transfer(int num1, int num2, int value)
{
	if (value > acctnum(num1))
	{
		cout << "Insufficient Funds!" << endl;
	}
	else
	{
		acctnum(num1) -= value;
		acctnum(num2) += value;
	}
}

void Bank::bank()
{
	for(int i=0; i<10; i++)
	{
		acctnum[i] = 0;
	}
}

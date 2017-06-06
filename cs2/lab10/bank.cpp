#include"bank.h"
#include<iostream>
using namespace std;

void Bank::deposit( int num, int value)
{
	acctnum[num] += value;
}

void Bank::withdraw(int num, int value)
{
	if (value > acctnum[num])
	{
		cout << "Insufficient Funds!" << endl;
	}
	else
	{
	acctnum[num] -= value;
	}
}

void Bank::balance(int num)
{
	cout << "Balance: " << acctnum[num] << endl;
}

void Bank::transfer(int num1, int num2, int value)
{
	if (value > acctnum[num1])
	{
		cout << "Insufficient Funds!" << endl;
	}
	else
	{
		acctnum[num1] -= value;
		acctnum[num2] += value;
	}
}

Bank::Bank()
{
	for(int i=0; i<10; i++)
	{
		acctnum[i] = 0;
	}
}

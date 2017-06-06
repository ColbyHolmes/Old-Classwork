/*Colby Holmes
Lab10a
CSCE 1040
4/9/15*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
//creates string variable
	string choice;

//prints message and scans input	
	cout << "bank> ";
	cin >> choice;

	cout << choice;
	while(choice.compare("exit") != 0)
	{	
//menu (print choice)
		if(choice.compare("deposit") == 0)
		{
			cout << "\nDEPOSIT SELECTED" << endl;
		}
		else if(choice.compare("withdraw") == 0)
		{
			cout << "\nWITHDRAW SELECTED" << endl;
		}
		else if(choice.compare("balance") == 0)
		{
			cout << "\nBALANCE SELECTED" << endl;
		}
//input for next iteration		
		cout << "bank> ";
		cin >> choice;
	}
//exit
	return 0;
}

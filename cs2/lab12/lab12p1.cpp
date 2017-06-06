/*Colby Holmes
Lab 12 part 1
CSCE 1040
4/23/15*/
#include<iostream>
using namespace std;

class Employee
{ protected: double sal; //salary base
public: Employee(double s){ sal = s;}
	double virtual Payment(){return sal;}
	void prt()
	{cout << "Salary="<< Payment() <<endl; } 
};

class Manager : public Employee
{ double inc;
public: Manager(double s, double i) : Employee(s) 
{ inc = i; } double Payment(){ return sal*inc; }
};

int main()
{ Employee el(1500); Manager ml(1500, 1.5); 
	cout << "Exercise about inheritance and polymorphism" <<endl;

	el.prt();
	ml.prt();
	return 0;
}


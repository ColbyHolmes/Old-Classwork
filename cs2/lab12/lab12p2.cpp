/*Colby Holmes
CSCE 1040
Lab12 Part 2*/

#include<iostream>
using namespace std;

//employee class
class Employee{
private:
	string name;
public:
//constructors
	Employee(string n){name = n;}

	string getName(){return name;}
//virual function
	virtual void show_info ()
	{ cout << "Employee" << endl; }
};

//manager class derived from employee
class Manager : public Employee{
public:
	Manager(string n) : Employee(n){}
	void show_info()
	{ cout << getName() << endl; }
};

//worker class derived from employee
class Worker : public Employee{
public:
	Worker(string n) : Employee(n){}
	void show_info()
	{ cout << getName() << endl; }
};

//techncian class derived from worker
class Technician : public Worker{
public:
	Technician(string n) : Worker(n){}
	void show_info()
	{ cout << getName() << endl; }
};

//officer class derived form worker
class Officer: public Worker{
public:
	Officer(string n) : Worker(n){}
	void show_info()
	{ cout << getName() << endl; }
};

//main function
int main()
{
	Employee Rafa("Rafa"); Manager Mario("Mario"); Worker Anton("Anton"); 
	Officer Luis("Luis"); Technician Pablo("Pablo");

	//The type of object pointed by a pointer to the base class
	//determines the function that is being called
	Employee *pe; cout << "\nInheritance and Polymorphism:\n" << endl;

	pe = &Rafa; pe->show_info();
	pe = &Mario; pe->show_info();
	pe = &Anton; pe->show_info();
	pe = &Luis; pe->show_info();
	pe = &Pablo; pe->show_info();

	cout << "Ya he terminado." << endl;
	
	return 0;
}

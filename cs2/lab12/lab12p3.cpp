/*Colby Holmes
CSCE 1040
Lab12 Part 2*/

#include<iostream>
using namespace std;

//employee class
class Employee{
//private data
private:
	string name;
	long salary;
public:
//constructors
	Employee(string n, long s){name = n; salary = s;}
//class functions
	string getName(){return name;}
	long getSalary(){return salary;}
//virual function
	virtual void show_info ()
	{ cout << "Employee: " << getName() << "\nSalary: " << getSalary() << endl; }
};

//manager class derived from employee
class Manager : public Employee{
protected:
	string degree;
public:
//constructer and functions
	Manager(string n, long s, string d) : Employee(n, s){degree = d;}
	void show_info()
        { cout << "Employee: " << getName() << "\nSalary: " << getSalary()
	<< "\nDegree: " << degree <<  endl; }
};

//worker class derived from employee
class Worker : public Employee{
protected:
	string position;
public:
//constructer and functions
	Worker(string n, long s, string p) : Employee(n, s){position = p;}
	void show_info()
        { cout << "Employee: " << getName() << "\nSalary: " << getSalary()
	<< "\nPosition: " << position << endl; }

};

//technician class derived from worker
class Technician : public Worker{
public:
	Technician(string n, long s, string p) : Worker(n, s, p){}
};

//officer class derived from worker
class Officer: public Worker{
public:
	Officer(string n, long s, string p) : Worker(n, s, p){}
};

#define NUM_EMPLOYEES 6

//main function
int main()
{
//create array of employees
	Employee* EmployeeList[NUM_EMPLOYEES];

//declare each employee with proper conbstructer calls	
	EmployeeList[0] = new Manager("Carla Garcia", 35000, "Economist");
        EmployeeList[1] = new Manager("Juan Perez", 38000, "Ingineer");
        EmployeeList[2] = new Officer("Pedro Egia", 18000, "Officer 1");
        EmployeeList[3] = new Officer("Luisa Penia", 15000, "Officer 2");
        EmployeeList[4] = new Technician("Javier Ramos", 19500, "Welder");
        EmployeeList[5] = new Technician("Amaia Bilbao", 12000, "Electricist");

//print employee list
	for(int i=0; i<NUM_EMPLOYEES; i++)
	{
		EmployeeList[i]->show_info();
	}
	
	return 0;
}

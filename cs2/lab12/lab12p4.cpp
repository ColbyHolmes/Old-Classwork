/*Colby Holmes
CSCE 1040
Lab12 Part 2*/

#include<iostream>
using namespace std;

//employee class
class Employee{
//private variables
private:
	string name;
	long salary;
public:
//constructors
	Employee(string n, long s){name = n; salary = s;}

	string getName(){return name;}
	long getSalary(){return salary;}
//virual function
	virtual void show_info ()
	{ cout << "Employee: " << getName() << "\nSalary: " << getSalary() << endl; }
};

//manager class derived from employee
class Manager : public Employee{
//protected data
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
//protected data
protected:
	string position;
public:
//constructor and functions
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

//main function
int main()
{
//necessary variables
	int numE, count = 0, choice = 0, pick = 0;
	string name, position, degree;
	long salary;
//aske for array length
	cout << "How many employees will there be: ";
	cin >> numE;
	
	Employee* EmployeeList[numE];

//begin menu		
	while (choice != 4)
	{
//ask for input
		cout << "\n\nWhat would you like to do:\n\t1. Add an Employee\n\t2. List all Employees"
			<<"\n\t3. Search for Employee\n\t4. Exit Program" << endl;
		cin >> choice;
//switch based on input		
		switch(choice)
		{
		case 1:
//check if maxed out employees
			if(count == numE)
			{
				cout << "MAX NUMBER OF EMPLOYEES REACHED" << endl;
			}
//add employee
			else
			{
				cout << "What kind of employee would you like to make:\n\t1. Manager"
				<< "\n\t2. Officer\n\t3. Technician" << endl;
				cin >> pick;
				switch(pick)
				{
//add manager
				case 1:
					cout << "Please enter the name: ";
					cin >> name;
					cout << "Please enter the salary: ";
					cin >> salary;
					cout << "Please state the degree: ";
					cin >> degree;
				
					EmployeeList[count] = new Manager(name, salary, degree);
					count ++;	
					break;
//add officer
				case 2:
                                	cout << "Please enter the name: ";
                                	cin >> name;
                                	cout << "Please enter the salary: ";
                                	cin >> salary;
                                	cout << "Please state the position: ";
                                	cin >> position;

                                	EmployeeList[count] = new Officer(name, salary, position);
                                	count ++;
 					break;
//add technician
				case 3:
                                	cout << "Please enter the name: ";
                                	cin >> name;
                                	cout << "Please enter the salary: ";
                                	cin >> salary;
                                	cout << "Please state the position: ";
                                	cin >> position;
		
					EmployeeList[count] = new Technician(name, salary, position);
					count ++;
					break;
				default:
					cout << "Sorry that is not a valid choice.\n" << endl;
				}
			}
			break;
//print employee list
		case 2:
			for(int i=0; i<count; i++)
			{
				EmployeeList[i]->show_info();
			}
			break;
//search for employee
		case 3:
			cout << "Enter the name of the Employee: ";
			cin >> name;
			for(int i=0; i<count; i++)
			{
				if(EmployeeList[i]->getName() == name)
				{
					EmployeeList[i]->show_info();
				}
			}
			break;
//exit
		case 4:
			;
		}
	}
	
	return 0;
}

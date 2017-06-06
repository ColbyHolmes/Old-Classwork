//****************************************************************************
//       CLASS:  CSCE-2100.021
//  ASSIGNMENT:  Program 2
//     STUDENT:  Colby Holmes
// DESCRIPTION:  Program 2 is a simple mechanism to prototype data input,
// 	linked list functionality, data storage, data manipulation,
// 	and sorted output using simple strings as input. 
//               
// SPECIAL INSTRUCTIONS:(none)
//
// SIDE NOTES: I'm never building a link list from scratch again.
//****************************************************************************

//include header files
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//create link-list structure
struct list {
	int aID;
	char name[30];
	list *next;
	list *prev;
};

//create a counter variable to give members of the struct ids
int count = 0;

//include function prototypes
void pmenu();
void add(list* head, char cName[30]);
void remove(list* pos, char dName[30]);
list* search(list* head, char sName[30]);
void plist(list* head);

//create main function
int main()
{
//print program startup message
	cout << "Colby's Address Book\n" << endl;

//create variables
	string choice = " ", temp, fchoice;
	char fname[30];
	list *head = new list;
	strcpy(head->name, "-----Address Book-----");	
	head->next = NULL;	


//create main loop for program
	while (choice.compare("QUIT") != 0)
	{
//print menu and get user input
		pmenu();
		cout << "cmd>";
		cin >> choice;

//switch statement to control program flow
		if(choice.compare("add") == 0)
		{
			char cName[30];
			cin.ignore();
			cin.getline(cName, 30);
			add(head, cName);
		}
		else if(choice.compare("search") == 0)
		{
			list *pos = new list;
			char sName[30];
			cin.ignore();
			cin.getline(sName, 30);
			pos = search(head, sName);
		}
		else if(choice.compare("remove") == 0)
		{
			char dName[30];
			cin.ignore();
			cin.getline(dName,30);
			remove(head, dName);
		}
		else if (choice.compare("print") == 0)
		{
			plist(head);
		}
		else if(choice.compare("file") == 0)
		{
			ifstream filedile;
			filedile.open ("/home/pwb0013/csce2100/program2/Program2_Data.csv");
			while (filedile.good())
			{
				getline(filedile, fchoice, ',');
				
				if (fchoice.compare("print") == 0)
				{
					plist(head);
					continue;
				}

				getline(filedile, temp, '\n');
				
				strcpy(fname, temp.c_str());
				
				if(fchoice.compare("add") == 0)
				{
					add(head, fname);
				}
				else if(fchoice.compare("search") == 0)
				{
					list *pos = new list;
					pos = search(head, fname);
				}
				else if(fchoice.compare("remove") == 0)
				{
					remove(head, fname);
				}

			}
			filedile.close();

		}
		else if(choice.compare("QUIT") == 0)
		{
			cout << "Exiting Program..." << endl;
//!!!!!Include statement to close open files!!!!!!

		}
		else
		{
			cout << "command not recognized.\n" << endl;
		}
		
	}

	return 0;
}



//*****function to print menu*****
void pmenu()
{
 cout << "\nadd <name>    - add a new entry\nsearch <name> - find an entry\n"
     << "remove <name> - remove an entry\nprint         - list entries alphabethically\n"
     << "file          - allows file commands\nQUIT          - exit the program\n\n";
}



//*****function to add a member to the list*****
void add(list* head, char cName[30])
{
	list *pos = new list;
	pos = head;
	int end = 0;	

	while (pos->next != 0 && end == 0)
	{
//check if name is alphabetically before next position
		if ((strcmp(cName, ((pos->next)->name))) < 0)
		{
			end = 2;
		}
		else if ((strcmp(cName, ((pos->next)->name))) > 0)
		{
			pos = (pos->next);
		}
		else if (strcmp(pos->name, cName) == 0)
		{
			cout << "\nDUPLICATE ENTRY. Not added." << endl;
			return;
		}
	}

//create new record and insert
	list *newRecord = new list;
	strcpy(newRecord->name, cName);	
	count ++;
	newRecord->aID = count;

// create temp location
	list temp;
	temp = *pos;
	

//if insertion is before next position
	 if (end == 2 && count > 1)
	{
		(newRecord->next) = temp.next;
		(pos->next) = newRecord;
	}
		
//inserting at the end of the list
	else
	{
		newRecord->next = NULL;
		pos->next = newRecord;
	}

	cout << endl << cName << " added.\nID#: " << count << endl;

}



//*****search function to find a specific person*****
list* search(list* head, char sName[30])
{
	list *pos = new list;
	pos = head;
	while (pos->next != 0)
	{
//check if name searched matches position name
		if (strcmp(pos->name, sName) == 0)
		{
			cout << "\nFound: " << sName << "\nID#: " << pos->aID << endl;
			return pos;
		}
		
		pos = pos->next;	
	}
//check last position
	if (strcmp(pos->name, sName) == 0)
	{
		cout << "\nFound: " << sName << "\nID#: " << pos->aID << endl;
		return pos;
	}

	cout << "\n\nName not found.\n" << endl;
	return NULL;
}


//*****remove function to delete a member of the list*****
void remove(list* head, char dName[30])
{
	list* pos;
	list* temp;
	temp = head;
			
//search for name and return pos
	pos = search(head, dName);

	if (pos == 0)
	{
		return;
	}

//if pos is the head
	if (pos == head)
	{
		head = head->next;
	}	
//if pos is the tail
	else if (pos->next == 0)
	{
		while ((temp->next)->next != 0)
		{
			temp = temp->next;
		}
		temp->next = NULL;
	}
//if pos is in the middle of list
	else
	{
		while (temp->next != pos)
		{
			temp = temp->next;
		}
		temp->next = pos->next;
	}

	delete pos;
	cout << "deleted." << endl;
}

void plist(list* head)
{
	list* temp = new list;
	temp = head;
	temp = temp->next;
	cout << "\n-----Address Book-----\n";
	while (temp->next != 0)
	{
		cout << "Name: " << temp->name << "\nID#: " << temp->aID << endl << endl;
		temp = temp->next;
	}
	
	cout << "Name: " << temp->name << "\nID#: " << temp->aID << endl << endl;
}

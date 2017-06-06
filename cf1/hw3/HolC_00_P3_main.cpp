//****************************************************************************
//       CLASS:  CSCE-2100.021
//  ASSIGNMENT:  Program 3
//     STUDENT:  Colby Holmes
// DESCRIPTION:  Programs 3 and 4 for this class will serve as an 
//     incremental implementation of an Address Book, with an added feature
//     of having the capability to produce a Family Tree printout based 
//     upon the parent-child relationships included in the Address Book. 
//               
// SPECIAL INSTRUCTIONS:I have it working with the supplied .csv file
// placed in my personal directory. I could not get it to open the 
// supplied path to the .csv in your folder.
// *If you would like to try yours though, drop the path into line 360.*
//
// SIDE NOTES: I'm never building a linked-list from scratch again.
// 		I also apologize for the long and terrible looking code.
//****************************************************************************

//include header files
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

//create link-list structure
struct list {
	string aID;
	char name[30];
	char address[30];
	char city[30];
	char state[30];
	char zip[6];
	char birth[9];
	char death[9];
	char wedding[9];
	list *spouse;
	list *child[8];
	list *next;
	int numChil;
};

//create a counter variable to give members of the struct ids
int count = 0;

//include function prototypes
void pmenu();
void add(list* head, char cName[30]);
//void remove(list* pos, char dName[30]);
list* search(list* head, char sName[30]);
list* searchID(list* head, string checkID);
void plist(list* head);

//create main function
int main()
{
//print program startup message
	cout << "Colby's Address Book\n" << endl;

//create variables
	string choice = " ", choice1 = " ", temp, fchoice, checkID;
	char fname[30], cName[30], dTime[8];
	list *head = new list;
	list *pos = new list;
	list *pos2 = new list;
	strcpy(head->name, "-----Address Book-----");	
	head->next = NULL;	


//create main loop for program
	while (choice.compare("QUIT") != 0)
	{
//print menu and get user input
		cout << "cmd>";
		cin >> choice;

//switch statement to control program flow
		if(choice.compare("commands") == 0)
		{
			pmenu();
		}
		else if(choice.compare("add") == 0)
		{
			cin >> choice1;

			if(choice1.compare("name") == 0)
			{
				cin.ignore();
				cin.getline(cName, 30);
				add(head, cName);
			}
			else if(choice1.compare("address1") == 0)
			{
//checkID reads in aID for search purposes
				cin >> checkID;
//cName hold the value to be added
				cin.getline(cName, 30);
//search by ID
				pos = searchID(head, checkID);
//use position to add data	
				if(pos == 0)
				{
					cout << "ID not found." << endl;
				}
				else
				{
					strcpy(pos->address, cName);
				
					cout << "ADDED Address: " << cName
					<< "\tuID: " << checkID << endl;
				}
			}
			else if(choice1.compare("city") == 0)
			{
				cin >> checkID;
				cin.getline(cName, 30);
				pos = searchID(head, checkID);

				if(pos == 0)
				{
					cout << "ID not found." << endl;
				}
				else
				{
					strcpy(pos->city, cName);
				
					cout << "ADDED City: " << cName
					<< "\tuID: " << checkID << endl;
				}				

			}
			else if(choice1.compare("state") == 0)
			{
				cin >> checkID;
				cin.getline(cName, 30);
				pos = searchID(head, checkID);

				if(pos == 0)
				{
					cout << "ID not found." << endl;
				}
				else
				{
					strcpy(pos->state, cName);

					cout << "ADDED State: " << cName
					<< "\tuID: " << checkID << endl;
				}

			}
			else if(choice1.compare("zip") == 0)
			{
				cin >> checkID;
				cin.getline(cName, 6);
				pos = searchID(head, checkID);

				if(pos == 0)
				{
					cout << "ID not found." << endl;
				}
				else
				{
					strcpy(pos->zip, cName);

					cout << "ADDED Zip: " << cName
					<< "\tuID: " << checkID << endl;
				}

			}
			else if(choice1.compare("date_birth") == 0)
			{
				cin >> checkID;
				cin.getline(dTime, 10);
				pos = searchID(head, checkID);

				if(pos == 0)
				{
					cout << "ID not found." << endl;
				}
				else
				{
					strcpy(pos->birth, dTime);
				
					cout << "ADDED Birthday: " << cName
					<< "\tuID: " << checkID << endl;
				}

			}				
			else if(choice1.compare("date_death") == 0)
			{
				cin >> checkID;
				cin.getline(dTime, 10);
				pos = searchID(head, checkID);

				if(pos == 0)
				{
					cout << "ID not found." << endl;
				}
				else
				{
					strcpy(pos->death, dTime);
				
					cout << "ADDED Death day: " << cName
					<< "\tuID: " << checkID << endl;
				}

			}
			else if(choice1.compare("date_wedding") == 0)
			{
				cin >> checkID;
				cin.getline(dTime, 10);
				pos = searchID(head, checkID);

				if(pos == 0)
				{
					cout << "ID not found." << endl;
				}
				else
				{
					strcpy(pos->wedding, dTime);
				
					cout << "ADDED Wedding: " << cName
					<< "\tuID: " << checkID << endl;
				}

			}
			else if(choice1.compare("spouse") == 0)
			{
				cin >> checkID;
				cin.ignore();
				cin.getline(cName, 30);
				pos = searchID(head, checkID);
//check for spouse in list
				pos2 = search(head, cName);
//if pre-existing link the nodes
				if (pos2 != NULL)
				{
					pos->spouse = pos2;
					pos2->spouse = pos;

//give address and shared details to spouse
					strcpy(pos2->address, pos->address);
					strcpy(pos2->city, pos->city);
					strcpy(pos2->state, pos->state);
				}
//if DNE, create node and link
				else
				{
					add(head, cName);
					pos2 = search(head, cName);
					pos->spouse = pos2;
					pos2->spouse = pos;

					strcpy(pos2->address, pos->address);
					strcpy(pos2->city, pos->city);
					strcpy(pos2->state, pos->state);
				}
			}
			else if(choice1.compare("child") == 0)
			{
				cin >> checkID;
				cin.ignore();
				cin.getline(cName, 30);
				pos = searchID(head, checkID);
//search if child exists
				pos2 = search(head, cName);
//if pre-existing link the nodes
				if (pos2 != NULL)
				{
					pos->child[pos->numChil] = pos2;
					pos->numChil ++;

//give address and shared details to child					
					strcpy(pos2->address, pos->address);
					strcpy(pos2->city, pos->city);
					strcpy(pos2->state, pos->state);
				}
//if DNE, create node and link
				else
				{
					add(head, cName);
					pos2 = search(head, cName);
					pos->child[pos->numChil] = pos2;
					pos->numChil ++;

					strcpy(pos2->address, pos->address);
					strcpy(pos2->city, pos->city);
					strcpy(pos2->state, pos->state);
				}
			}
			else
			{
				cout << "Command Not Recognized..." << endl;
			}

		}
		else if(choice.compare("search") == 0)
		{
			char sName[30];
			cin.ignore();
			cin.getline(sName, 30);
			pos = search(head, sName);
			if (pos == 0)
			{
				cout << "\n\nID not found.\n" << endl;
			}
			else
			{
				cout << "\nFound: " << sName 
					<< "\tuID: " << pos->aID << endl;
			}
		}
/*		else if(choice.compare("remove") == 0)
		{
			char dName[30];
			cin.ignore();
			cin.getline(dName,30);
			remove(head, dName);
		}*/
		else if (choice.compare("print") == 0)
		{
			cin >> choice1;
			
			if(choice1.compare("all") == 0)
			{
				plist(head);
			}
			else
			{
				pos = searchID(head, choice1);
				cout << "\nUID: " << pos->aID
					<< "\nName: " << pos->name << "\nAddress: " << pos->address
					<< "\nCity: " << pos->city << "\nState: " << pos->state
					<< "\nZip: " << pos->zip
					<< "\nBirthdate: " << pos->birth << "\nDeathdate: "
					<< pos->death << "\nWedding: " << pos->wedding
					<< "\nSpouse: "; 

				if(pos->spouse != 0)
				{
					cout << (pos->spouse)->name << endl;
				}
				else
				{
					cout << endl;
				}
				for(int i=0; i<(pos->numChil); i++)
				{
					cout << "Child" << i+1 << ": " << (pos->child[i])->name << endl;
				}
			}
		}

		else if(choice.compare("file") == 0)
		{
			ifstream filedile;

//Opens file from given filepath given
//*****PATH DIDNT WORK FROM HOME, DID WORK WITH THE DIRECT FILE GIVEN****
//VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
			filedile.open ("Program3_Data.csv");
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			while (filedile.good())
			{
				getline(filedile, fchoice, ',');

//file switch copied from original switch
//slightly altered to gather the data from file, otherwise the same...				

				if (fchoice.compare("print") == 0)
				{
					getline(filedile, choice1, ',');

					if(choice1.compare("all") == 0)
					{
						plist(head);
					}
					else
					{
						pos = searchID(head, choice1);
						cout << "\nUID: " << pos->aID
						<< "\nName: " << pos->name << "\nAddress: " << pos->address
						<< "\nCity: " << pos->city << "\nState: " << pos->state
						<< "\nZip: " << pos->zip
						<< "\nBirthdate: " << pos->birth << "\nDeathdate: "
						<< pos->death << "\nWedding: " << pos->wedding
						<< "\nSpouse: "; 

						if(pos->spouse != 0)
						{
							cout << (pos->spouse)->name << endl;
						}
						else
						{
							cout << endl;
						}

						for(int i=0; i<(pos->numChil); i++)
						{
							cout << "Child" << i+1 << ": " << (pos->child[i])->name 
							<< endl;
						}
					}
					cout << endl;
					getline(filedile, choice1, '\n');
				}
				
				else if(fchoice.compare("add") == 0)
				{
					getline(filedile, choice1, ',');
					
					if(choice1.compare("name") == 0)
					{
						getline(filedile, temp, ',');
						strcpy(fname, temp.c_str());

						add(head, fname);
						getline(filedile, temp, '\n');	
					}
					else if(choice1.compare("address1") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');
//search by ID
						pos = searchID(head, checkID);
//use position to add data	
						if(pos == 0)
						{
							cout << "ID not found." << endl;
						}
						else
						{
							strcpy(pos->address, temp.c_str());
				
							cout << "\nADDED Address: " << pos->address
							<< "\tuID: " << checkID << endl;
						}
					}
					else if(choice1.compare("city") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');
						pos = searchID(head, checkID);

						if(pos == 0)
						{
							cout << "ID not found." << endl;
						}
						else
						{
							strcpy(pos->city, temp.c_str());
				
							cout << "\nADDED City: " << pos->city
							<< "\tuID: " << checkID << endl;
						}				

					}
					else if(choice1.compare("state") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');
						
						if(pos == 0)
						{
							cout << "ID not found." << endl;
						}
						else
						{
							pos = searchID(head, checkID);
							strcpy(pos->state, temp.c_str());
				
							cout << "\nADDED State: " << pos->state
							<< "\tuID: " << checkID << endl;
						}

					}
					else if(choice1.compare("zip") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');
						
						if(pos == 0)
						{
							cout << "ID not found." << endl;
						}
						else
						{
							pos = searchID(head, checkID);
							strcpy(pos->zip, temp.c_str());
				
							cout << "\nADDED Zip: " << pos->zip
							<< "\tuID: " << checkID << endl;
						}

					}
					else if(choice1.compare("date_birth") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');

						if(pos == 0)
						{
							cout << "ID not found." << endl;
						}
						else
						{
							pos = searchID(head, checkID);
							strcpy(pos->birth, temp.c_str());
				
							cout << "\nADDED Birthday: " << pos->birth
							<< "\tuID: " << checkID << endl;
						}

					}				
					else if(choice1.compare("date_death") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');

						if(pos == 0)
						{
							cout << "ID not found." << endl;
						}
						else
						{
							pos = searchID(head, checkID);
							strcpy(pos->death, temp.c_str());
				
							cout << "\nADDED Death Day: " << pos->death
							<< "\tuID: " << checkID << endl;
						}

					}
					else if(choice1.compare("date_wedding") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');

						if(pos == 0)
						{
							cout << "ID not found." << endl;
						}
						else
						{
							pos = searchID(head, checkID);
							strcpy(pos->wedding, temp.c_str());
				
							cout << "\nADDED Wedding: " << pos->wedding
							<< "\tuID: " << checkID << endl;
						}

					}
					else if(choice1.compare("spouse") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');
						pos = searchID(head, checkID);
//check for spouse in list
						strcpy(fname, temp.c_str());
						pos2 = search(head, fname);
//if pre-existing link the nodes
						if (pos2 != NULL)
						{
							pos->spouse = pos2;
							pos2->spouse = pos;

//give address and shared details to spouse
							strcpy(pos2->address, pos->address);
							strcpy(pos2->city, pos->city);
							strcpy(pos2->state, pos->state);
						}
//if DNE, create node and link
						else
						{
							add(head, fname);
							pos2 = search(head, fname);
							pos->spouse = pos2;
							pos2->spouse = pos;

							strcpy(pos2->address, pos->address);
							strcpy(pos2->city, pos->city);
							strcpy(pos2->state, pos->state);
						}
					}
					else if(choice1.compare("child") == 0)
					{
						getline(filedile, checkID, ',');
						getline(filedile, temp, '\n');
						pos = searchID(head, checkID);
//search if child exists
						strcpy(fname, temp.c_str());
						pos2 = search(head, fname);
//if pre-existing link the nodes
						if (pos2 != NULL)
						{
							pos->child[pos->numChil] = pos2;
							pos->numChil ++;

//give address and shared details to child					
							strcpy(pos2->address, pos->address);
							strcpy(pos2->city, pos->city);
							strcpy(pos2->state, pos->state);
						}
//if DNE, create node and link
						else
						{
							add(head, fname);
							pos2 = search(head, fname);
							pos->child[pos->numChil] = pos2;
							pos->numChil ++;

							strcpy(pos2->address, pos->address);
							strcpy(pos2->city, pos->city);
							strcpy(pos2->state, pos->state);
						}
					}

					
				}
				else if(fchoice.compare("search") == 0)
				{
					getline(filedile, temp, ',');
					strcpy(fname, temp.c_str());

					pos = search(head, fname);
				
					if (pos != 0)
					{
						cout << "Found: " << fname << "\tUID: " << pos->aID << endl;
					}
					else
						cout << "Name not recognized." << endl;
					getline(filedile, temp, '\n');
				}
/*				else if(fchoice.compare("remove") == 0)
				{
					remove(head, fname);
				}*/

			}
			filedile.close();

		}
		else if(choice.compare("QUIT") == 0)
		{
			cout << "Exiting Program..." << endl;

		}
		else
		{
			cout << "command not recognized.\n" << endl;
		}
		
	}

	return 0;
}



//*************************************************************************

//*****function to print menu*****
void pmenu()
{
 cout << "\nadd name <name>  ==>  Add a new name (First Last) to the Address Book"
	<< "\nadd spouse <uid> <name>  ==> Add spouse of <uid> (First Last) to the Address Book"
	<< "\nadd child  <uid> <name>  ==>  Add a child of <uid> (First Last) to the Address Book"
	<< "\nadd address1 <uid> <address>  ==> Add/change the address for <uid>"
	<< "\nadd city <uid> <city>    ==> Add/change the city for <uid>"
	<< "\nadd state <uid> <state>  ==> Add/change the state for <uid>"
	<< "\nadd zip <uid> <zipcode>  ==> Add/change the zipcode for <uid>"
	<< "\nadd date birth <uid> <ddmmyyyy>  ==> Add/change the birthday for <uid>"
	<< "\nadd date wedding <uid> <ddmmyyyy>   ==> Add/change the wedding day for <uid>"
	<< "\nadd date death <uid> <ddmmyyyy>   ==> Add/change the date of death for <uid>"
	<< "\nsearch <name>  ==> searches for name (First Last) and returns the <uid>, if found"
	<< "\nprint all ==>  Prints a list of ALL of the names in the Address Book with their <uid>"
	<< "\nprint <uid>  ==>  Prints all of the fields for <uid>"
	<< "\nfile  ==>  user is prompted for a filename that contains correctly formatted commands"
	<< "\n      --- the file must be in CSV format with one full command per line"
	<< "\nQUIT  ==>  processing complete" << endl;

}


//*************************************************************************



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
		else if (strcmp((pos->next)->name, cName) == 0)
		{
			cout << "\nDUPLICATE ENTRY. Not added." << endl;
			return;
		}
	}

//create new record and insert
	list *newRecord = new list;
	strcpy(newRecord->name, cName);
	newRecord->aID = "ID";	
	count ++;
	if (count < 10)
	{
		newRecord->aID += "00";
	}
	else if (count < 100)
	{
		newRecord->aID += "0";
	}

	stringstream convert;
	convert << count;
	newRecord->aID += convert.str();
	newRecord->numChil = 0;
	newRecord->spouse = NULL;

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

	cout << endl << cName << " added.\nuID: " << newRecord->aID << endl;

}


//*************************************************************************



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
			return pos;
		}
		
		pos = pos->next;	
	}
//check last position
	if (strcmp(pos->name, sName) == 0)
	{
		return pos;
	}

	return NULL;
}


//*************************************************************************


//*****search function to find a specific ID*****
list* searchID(list* head, string checkID)
{
	list *pos = new list;
	pos = head;
	while (pos->next != 0)
	{
//check if name searched matches position name
		if (pos->aID == checkID)
		{
			return pos;
		}
		
		pos = pos->next;	
	}
//check last position
	if (pos->aID == checkID)
	{
		return pos;
	}

	return NULL;
}


//*************************************************************************


//*****remove function to delete a member of the list*****
/*
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
*/

//*************************************************************************


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

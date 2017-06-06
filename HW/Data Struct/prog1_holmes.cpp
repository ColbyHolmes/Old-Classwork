/*Colby Holmes
Program 1 
Due 9/21/16*/

#include <iostream>
using namespace std;

class singleList{
public:
  int num;
  singleList *next;
};

void printMenu();
void printList(singleList *head);
int checkVal(singleList *head, int val);
void add(singleList *head, int val);
void remove(singleList *head, int val);


//main function
int main()
{
//instantiate linked list
  singleList *head = new singleList;
  head->next = NULL;

  string choice = "";
  int size = 0, chk, val;

  while (choice != "q")
  {
    printMenu();
    cin >> choice;

//size option
    if (choice == "a")
    {
	cout << "\nThe size of the list is: " << size << endl << endl;
    }

//print option
    else if (choice == "b")
    {
	if (size == 0)
	  cout << "\nList empty: nothing to print...\n\n";
	else
	  printList(head);
    }

//empty option
    else if (choice == "c")
    {
	if (size == 0)
	{
	  cout << "\nThe list is empty.\n\n";
	}
	else
	  cout << "\nThe list is not empty.\n\n";
    }

//test value option
    else if (choice == "d")
    {
	cout << "\nWhat value would you like to test: ";
	cin >> val;

	chk = checkVal(head, val);
	if (chk == 1)
	  cout << val << " is in the list.\n\n";
	else
	  cout << val << " is NOT in the list.\n\n";
    }

//add value option
    else if (choice == "e")
    {
	cout << "\nWhat value would you like to add: ";
	cin >> val;

	chk = checkVal(head, val);
	if (chk == 1)
	  cout << val << " is already in the list.\n\n";
	else
	{
	  size++;
	  add(head, val);
    	}
    }

//remove value option
    else if (choice == "f")
    {
	cout << "\nWhat value would you like to remove: ";
	cin >> val;

	chk = checkVal(head, val);
	if (chk == 1)
	{
	  size--;
	  remove(head, val);
	}
	else
	  cout << val << " is NOT in the list.\n\n";
    }

//quit option
    else if (choice == "q")
    {
	cout << "\n\nProgram closing...\n\n";
    }
//invalid option
    else
	cout << "please enter 'a-f' or 'q'";
  }
  return 0;
}

//prints the menu
void printMenu()
{
  cout << "Options:\n\ta. return the size of the linked list\n\t"
  << "b. print the linked list\n\t"
  << "c. check if the list is empty of not\n\t"
  << "d. test if a value x is contained in the linked list\n\t"
  << "e. add a value x if it is not already contained in the list\n\t"
  << "f. remove a value x if it is contained in the linked list\n\t"
  << "q. quit the program\n\ncmd>";

  return;
}

//prints the list
void printList(singleList *head)
{
  singleList *temp = head->next;
  cout << "\n\n" << temp->num;

  while(temp->next != NULL)
  {
    temp = temp->next;
    cout << " -> " << temp->num;
  }

  cout << "\n\n";
  return;
}

//checks the list for a specified value
int checkVal(singleList *head, int val)
{
  singleList *temp = head;

  while (temp->next != NULL)
  {
    if (temp->num == val)
    {return 1;}

    temp = temp->next;
  }
    if (temp->num == val)
	return 1;
    else
	return 0;
}

//adds specified value to the list
void add(singleList *head, int val)
{
  singleList *temp = head;
  singleList *add = new singleList;
  add->num = val;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = add;

  return;  
}

//removes specified value from the list
void remove(singleList *head, int val)
{
  singleList *temp = head;

  do{
    if ((temp->next)->num == val)
    {
	temp->next = (temp->next)->next;
	return;
    }
    temp = temp->next;
  }while (temp->next != NULL);

  return;
}
/*Colby Holmes
CSCE 1040
Homework #5
Due 4/15/15*/

#include"classes.h"
//access collections
extern BCol bCollect;
extern MCol mCollect;
extern CCol cCollect;

int main()
{
//print opening message
	cout << "CSCE 1040\nHomework 6\nColby Holmes\ncolbyholmes@my.unt.edu\n";
	cout << "-----Library-System-----" << endl;

//declare variables
	int choice = 0, chu = 0, dnum, chk;
	while (choice != 13)
	{
//print menu and ask choice
		menu();
		cout << "Please choose an option: ";
		cin >> choice;
//check validity	
		while (choice > 13 || choice < 1)
		{
			cout << "Please make a valid choice: ";
			cin >> choice;
		}
		
		switch(choice)
		{
		case 1:
//add a book
			bCollect.addBook();
			break;
		case 2:
//add a member
			mCollect.addMember();
			break;
		case 3:
//checkout a book
			cCollect.checkout();
			break;
		case 4:
//checkin a book
			cout << "What is the checkout ID#: ";
			cin >> dnum;
			cCollect.checkin(cCollect.findCheck(dnum));
			break;
		case 5:
//edit/remove a book
			while (chu != 3)
			{
				cout << "\n1. Edit\n2. Remove\n3. Return to menu\nChoice: ";
				cin >> chu;
				
				if (chu == 1)
				{
					chk = bCollect.findBook(ask());
					if (chk >= 0)
					{
					bCollect.books[chk].setBInfo();
					}
				}
				else if (chu == 2)
				{
					chk = bCollect.findBook(ask());
					if (chk >= 0)
					{
					bCollect.remBook(chk);
					}
				}	
			}
			break;
		case 6:
//edit/remove a member
                        while (chu != 3)
                        {
                                cout << "\n1. Edit\n2. Remove\n3. Return to menu\nChoice: ";
                                cin >> chu;

				if (chu == 1)
                                {
					chk = mCollect.findMember(ask());
					if (chk >= 0)
					{ 
					mCollect.members[chk].setMInfo();
                                	}
				}
                                else if (chu == 2)
                                {
					chk = mCollect.findMember(ask());
					if (chk >= 0)
					{
					mCollect.remMember(chk);
                                	}
				}
                        }	
			break;
		case 7:
//print the book list
			bCollect.printBooks();
			break;
		case 8:
//print overdue book list
			cCollect.printOver();
			break;
		case 9:
//print a list of members
			mCollect.printMembers();
			break;
		case 10:
//print a mailing list
			mCollect.printMail();
			break;
		case 11:
//save database
			save();		
			break;
		case 12:
//load database
			load();
			break;
		case 13:
//exit the program
			;
		}

	}

	return 0;
}

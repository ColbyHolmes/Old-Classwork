#include"classes.h"
using namespace std;
//declare collections
BCol bCollect;
MCol mCollect;
CCol cCollect;

//addbook function
void BCol::addBook()
{
//realloc
        if(count >= size)
        {
                size += 20;
                Book* temp = new Book[size];
                copy(books, books + count, temp);
                delete [] books;
                books = temp;
        }

//determine item type
        cout << "What type of item are you adding:\n\t1. Book"
                << "\n\t2. Reference\n\t3. DVD\n\t4. Book-on-Tape"
                << endl;
        int num;
        cin >> num;

        if (num < 1 || num > 4)
        {
                cout << "Enter a valid type (1-4): ";
                cin >> num;
        }
        switch (num)
        {
        case 1:
                books[count] = Book();
                break;
        case 2:
                books[count] = Reference();
                break;
        case 3:
                books[count] = Dvd();
                break;
        case 4:
                books[count] = Tape();
        }

//update book variables
	books[count].bID = count+1;
	cout << "Please enter the title: ";
	cin.ignore();
	getline(cin, books[count].title);
	cout << "Author: ";
	getline(cin, books[count].author);
	books[count].lostStat = false;
//print data
	cout << "---Item-Added---\nItem Id: " << books[count].bID
		<< "\nType: " << books[count].form 
		<< "\nTitle: " << books[count].title << "\nAuthor: "
		<< books[count].author << endl;
	
	count ++;
}

//remove a book
void BCol::remBook(int check)
{
//check it is in the system
	int loc;
	loc = findBook(check);
//move everything over
	for (int i=loc; i<count; i++)
	{
		books[i] = books [i+1];
		count --;
	}		
}

//find a book with its id
int BCol::findBook(int check)
{
	for(int i=0; i<count; i++)
	{
//if the id matches return its location
		if(books[i].bID == check)
		{
			return i;
		}
	}
//if not found tell user
                cout << "\nItem not found." << endl;
                return -1;
  
}

//print list of books
void BCol::printBooks()
{
	cout << "----Item-List----" << endl;
	for (int i=0; i<count; i++)
	{
		books[i].getBInfo();	
	}
}

//print book info
void Book::getBInfo()
{
	cout << "Item Id: " << bID << "\nType: "
		<< form << "\nTitle: "
                << title << "\nAuthor: "
                << author << "\n\n";
        if (lostStat)
        {
        	cout << "Item MISSING\n\n";
	}
}

//edit book info
void Book::setBInfo()
{
	int choice = 0;
	while (choice != 4)
	{
		cout << "\nEditing Book:\n";
		getBInfo();
//ask user choice	
		cout << "What would you like to edit?\n1. Title\n2. "
			<< "Author\n3. Lost Status\n4. Exit to menu\n";

		cin >> choice;
		while (choice > 4 || choice < 1)
		{
			cout << "Please enter a valid option (1-4): ";
			cin >> choice;
		}
//switch based on choice
		switch(choice)
		{
		case 1:
			cout << "Current Title: " << title
				<< "\nNew Title: ";
			cin.ignore();
			getline(cin, title);	
			break;
		case 2:
			cout << "Current Author: " << author
				<< "\nNew Author: ";
			cin.ignore();
			getline(cin, author);
			break;
		case 3:
			if (lostStat)
			{
				cout << "Book is currently missing." << endl;
			}
			else 
				cout << "Book is not missing." << endl;

			cout << "Change status (Y/N): ";
			char confirm;
			cin >> confirm;
			
			if (confirm == 'Y' && lostStat)
				lostStat = false;
			else if (confirm == 'Y' && lostStat == false)
				lostStat = true;
			else if (confirm != 'N')
				cout << "\nInvalid Input.\n";			 
			break;
		case 4:
			;
		}
	}
}

//add a patron
void MCol::addMember()
{
//realloc if necessary
        if(count >= size)
        {
                size += 20;
                Member* temp = new Member[size];
                copy(members, members + count, temp);
                delete [] members;
                members = temp;
        }

//update variables
        members[count].mID = count+1;
        cout << "Please enter the patrons name: ";
	cin.ignore();
        getline(cin, members[count].name);
        cout << "Full Address: ";
        getline(cin, members[count].address);
        cout << "Phone Number: ";
	getline(cin, members[count].phone);
	cout << "Email: ";
	getline(cin, members[count].email);

//print data
        cout << "---Patron Added---\nMember Id: " << members[count].mID
                << "\nName: " << members[count].name << "\nAddress: "
                << members[count].address << "\nPhone Number: " << members[count].phone
		<< "\nEmail: " << members[count].email << endl;

        count ++;
}

//remove a member
void MCol::remMember(int check)
{
        int loc;
        loc = findMember(check);
        for (int i=loc; i<count; i++)
        {
                members[i] = members[i+1];
        }
}

//find a member with Id
int MCol::findMember(int check)
{
        for(int i=0; i<count; i++)
        {
                if(members[i].mID == check)
                {
                        return i;
                }
        }
                 cout << "Member not found." << endl;
                 return -1;
}

//print the list of members
void MCol::printMembers()
{
        cout << "----Patron List----" << endl;
        for (int i=0; i<count; i++)
        {
                cout << i+1 << ".\nName: " << members[i].name
			<< "\nMember Id: " << members[i].mID <<  "\n\n";
        }
}

//print a mailing list
void MCol::printMail()
{
	cout << "----Mailing List----" << endl;
	for (int i=0; i<count; i++)
	{
		cout << "Name: " << members[i].name << "\nAddress: " << members[i].address
			<< "\n\n";
	}
}

//print individual member data
void Member::getMInfo()
{
        cout << "Member Id: " << mID << "\nName: " << name << "\nAddress: " 
		<< address << "\nPhone Number: " << phone << "\nEmail: "
		<< email << "\n\n";
}

//edit the member data
void Member::setMInfo()
{
        int choice = 0;
        while (choice != 5)
        {
                cout << "\nEditing Member:\n";
                getMInfo();

                cout << "What would you like to edit?\n1. Name\n2. "
                        << "Address\n3. Phone Number\n4. Email\n5. Exit to menu\n";

                cin >> choice;
                while (choice > 5 || choice < 1)
                {
                        cout << "Please enter a valid option (1-5): ";
                	cin >> choice;
		}

                switch(choice)
                {
                case 1:
                        cout << "Current Name: " << name
                                << "\nNew Name: ";
			cin.ignore();
                        getline(cin, name);
                        break;
                case 2:
                        cout << "Current Address: " << address
                                << "\nNew Address: ";
			cin.ignore();
			getline(cin, address);
                        break;
                case 3:
                        cout << "Current Phone Number: " << phone
				<< "\nNew Phone Number: ";
			cin.ignore();
			getline(cin, phone);
                        break;
                case 4:
                        cout << "Current Email: " << email
				<< "\nNew Email: ";
			cin.ignore();
			getline(cin, email);
			break;
		case 5:
			;
                }
        }
}

//checkout a book
void CCol::checkout()
{
//realloc if necessary
        if(count >= size)
        {
                size += 20;
                Checkout* temp = new Checkout[size];
                copy(checkouts, checkouts + count, temp);
                delete [] checkouts;
                checkouts = temp;
        }
//ask for book id
        cout << "What is the Item Id: ";
	int choice, choice2, i, j;
	cin >> choice;
	i = (bCollect.findBook(choice));
	if (i != -1)
	{
//if valid get member id
		cout << "Item: " << bCollect.books[i].title;
		
		if(bCollect.books[i].form == "Reference")
		{
			cout << "\nReference books cannot be checked out."
				<< endl;
		}
		else
		{
			cout << "\nWhat is the Member Id: ";
			cin >> choice2;
			j = mCollect.findMember(choice2);
			if (j != -1)
			{
//if valid proceed with checkout
			checkouts[count].cID = count + 1;
			checkouts[count].bID = bCollect.books[i].bID;
			checkouts[count].mID = mCollect.members[j].mID;
//record due date with time	
			time_t date;  
			date = time(0);
			checkouts[count].dueDate = date + bCollect.books[i].duetime;
			
			checkouts[count].checkStat = false;
			checkouts[count].fees = 0;
//print data			
			date = date + bCollect.books[i].duetime;
		        cout << "\n---Item-Checked-Out---\nCheckout ID: "
			<< checkouts[count].cID << "\nItem: " << bCollect.books[i].title
        	        << "\nPatron: " << mCollect.members[j].name << "\nDue Date: "
                	<< ctime(&date) << endl;
			}
		}	
	}		
}

//check in a book
void CCol::checkin(int check)
{
	int scorp, get, over, here;
	here = findCheck(check);
	if (here != -1)
	{
//if checkid is valid check in
//calculate the fees
		checkouts[here].checkStat = true;
		over = calcOver(here);

                get = mCollect.findMember(checkouts[here].mID);
                scorp = bCollect.findBook(checkouts[here].bID);
		
		if (over > 0)
		{
			checkouts[here].fees = over * bCollect.books[scorp].rate;
		}

// print the data
		cout << "Patron: " 
			<< mCollect.members[get].name 
			<< "\nItem: " 
			<< bCollect.books[scorp].title 
			<< "\nStatus: Checked In\nFees: " 
			<< checkouts[here].fees << endl;
	}
}

//find a check record
int CCol::findCheck(int check)
{
        for(int i=0; i<count; i++)
        {
                if(checkouts[i].cID == check)
                {
                        return i;
                }
        }
                cout << "Checkout Record not found." << endl;
                return -1;
}

void CCol::printOver()
{
	cout << "----Overdue-Items----" << endl;
	for(int i=0; i<count; i++)
	{
		if(calcOver(i) > 0)
		{
			cout << "\nItem: " 
			<< bCollect.books[bCollect.findBook(checkouts[i].bID)].title
			<< "\nPatron: " 
			<< mCollect.members[mCollect.findMember(checkouts[i].mID)].name
			<< "\nDue: "
			<< calcOver(i) << " days ago"
			<< "\nAmount due: " 
			<< calcOver(i) *bCollect.books[bCollect.findBook(checkouts[i].bID)].rate << "\n\n";
		}
	}
}

//calculate overdue books
int CCol::calcOver(int loc)
{
//use current date and due date to find the number of days past due
        time_t date;
        date = time(0);
	int daysOver;
	daysOver = difftime(date, checkouts[loc].dueDate)/ 86400;
	
        if(daysOver > 0)
        {
                return daysOver;
        }
        else
        {
                return -1;
        }

}
 

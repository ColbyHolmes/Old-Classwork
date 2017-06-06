#include"classes.h"
using namespace std;
//gives access to the collections
extern BCol bCollect;
extern MCol mCollect;
extern CCol cCollect;
//prints the menu
void menu()
{
	cout << "\nMenu:\n\t1. Add Item\n\t2. Add Patron\n\t3. Check Out\n\t4. Check In"
		<< "\n\t5. Edit/Remove Item\n\t6. Edit/Remove Patron\n\t7. Print Items"
		<< "\n\t8. Print Overdue Items\n\t9. Print Patrons\n\t10. Print Mailing List"
		<< "\n\t11. Save System\n\t12. Load System\n\t13. Exit System"
		<< endl; 
}
//gets the user input ID #
int ask()
{
	int num;
	cout << "Please enter the ID#: ";
	cin >> num;
	return num;
}
//saves the library system
void save()
{
//opens the file to be written
	ofstream datafile;
	datafile.open("library.dat");
	datafile.seekp(0, ios::beg);
//records the basic counters for this class
        datafile << bCollect.count << "\n";
        datafile << bCollect.size << "\n";
//records the individual book data
	for (int i=0; i<bCollect.count; i++)
	{
		datafile << bCollect.books[i].bID << "\n";
                datafile << bCollect.books[i].lostStat << "\n";
		datafile << bCollect.books[i].duetime << "\n";
		datafile << bCollect.books[i].rate << "\n";
                datafile << bCollect.books[i].title << "\n";
                datafile << bCollect.books[i].author << "\n";
		datafile << bCollect.books[i].form << endl;
	}
//records the counters for member
        datafile << mCollect.count << "\n";
        datafile << mCollect.size << "\n";
//records the individual member data
        for (int i=0; i<bCollect.count; i++)
        {
                datafile << mCollect.members[i].mID << "\n";
                datafile << mCollect.members[i].name << "\n";
                datafile << mCollect.members[i].address << "\n";
                datafile << mCollect.members[i].phone << "\n";
		datafile << mCollect.members[i].email << endl;
        }
//records the checkout counters
        datafile << cCollect.count << "\n";
        datafile << cCollect.size << "\n";
//records the individual checkout records
        for (int i=0; i<bCollect.count; i++)
        {
                datafile << cCollect.checkouts[i].cID << "\n";
                datafile << cCollect.checkouts[i].bID << "\n";
                datafile << cCollect.checkouts[i].mID << "\n";
                datafile << cCollect.checkouts[i].dueDate << "\n";
		datafile << cCollect.checkouts[i].checkStat << "\n";
		datafile << cCollect.checkouts[i].fees << endl;
        }

	cout << "----System Saved!----" << endl;
}
// loads the library system
void load()
{
//opens the data file and sets to the beginning
	string store;
	ifstream datafile;
        datafile.open("library.dat");
        datafile.seekg(0, ios::beg);
//reads basic counters
        datafile >> bCollect.count;
	datafile >> bCollect.size;
//reads individual data
        for (int i=0; i<bCollect.count; i++)
        {
                datafile >> bCollect.books[i].bID;
                datafile >> bCollect.books[i].lostStat;
		datafile >> bCollect.books[i].duetime;
		datafile >> bCollect.books[i].rate;
                getline(datafile, bCollect.books[i].title);
                getline(datafile, bCollect.books[i].author);
		getline(datafile, bCollect.books[i].form);
        }
//reads counters
        datafile >> mCollect.count;
        datafile >> mCollect.size;
//reads individual data
        for (int i=0; i<bCollect.count; i++)
        {
                datafile >>  mCollect.members[i].mID;
                getline(datafile, mCollect.members[i].name);
                getline(datafile, mCollect.members[i].address);
                getline(datafile, mCollect.members[i].phone);
                getline(datafile, mCollect.members[i].email);
        }
//reads counters
        datafile >> cCollect.count;
        datafile >> cCollect.size;
//reads individual data
        for (int i=0; i<bCollect.count; i++)
        {
                datafile >> cCollect.checkouts[i].cID;
                datafile >> cCollect.checkouts[i].bID;
                datafile >> cCollect.checkouts[i].mID;
                datafile >> cCollect.checkouts[i].dueDate;
                datafile >> cCollect.checkouts[i].checkStat;
                datafile >> cCollect.checkouts[i].fees;
        }

	cout << "----System Loaded!----" << endl;
}

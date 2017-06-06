#include<iostream>
#include<stdio.h>
#include<ctime>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<vector>
using namespace std;

//declare function prototypes
void menu();
int ask();
void save();
void load();


class Book{
public:
	int bID;
	string title;
	string author;
	bool lostStat;
	int duetime;
	float rate;
	string form;

	void getBInfo();
	void setBInfo();
	Book(){duetime = 1209600; rate = .25; form = "Book";};	
	Book(int d, float r, string f){duetime = d; rate = r; form = f;};
};

class Reference : public Book{
public:
	Reference() : Book(0, 0, "Reference"){};
};

class Dvd : public Book{
public:
	Dvd() : Book(604800, 1.00, "DVD"){};
};

class Tape : public Book{
public:
	Tape() : Book(604800, .50, "Book-on-Tape"){};
};

class Member{
public:
	int mID;
	string name;
	string address;
	string phone;
	string email;

	void getMInfo();
	void setMInfo();
};

class Checkout{
public:
	int cID;
	int bID;
	int mID;
	time_t dueDate;
	bool checkStat;
	float fees;

	void getCInfo();
	void setCInfo();
};

class BCol{
public:
	int count;
	int size;
	Book* books;

	void addBook();
	void remBook(int check);
	int findBook(int check);
	void printBooks();
	BCol(){count = 0; books = new Book[20];};	
};

class MCol{
public:
	int count;
	int size;
	Member* members;

	void addMember();
	void remMember(int check);
	int findMember(int check);
	void printMembers();
	void printMail();
	MCol(){members = new Member[20];};
};

class CCol{
public:
	int count;
	int size;
	Checkout* checkouts;

	void checkout();
	void checkin(int check);
	int findCheck(int check);
	void printOver();
	int calcOver(int loc);
	CCol(){checkouts = new Checkout[20];};
};


//******************************************
//Name: Colby Holmes
//Class: CSCE 2110 mwf 10:30
//Assignment: Program 2
//Description: This program is the simple implementation of the Road Atlas
//and Driving Distance Calculator. This assignment just stores data for
//basic nodes and edges.
//******************************************

#include <iostream>
#include <fstream>
using namespace std;

//create link-list structure
struct node {
    char id;
    node *next;
};

int count = 0;

//function prototypes
void addNode(node* array, char id);
void addEdge(node* array, char id1, char id2);
void delNode(node* array, char id);
void delEdge(node* array, char id1, char id2);
int serNode(node* array, char id);
void printMat(node* array);
void printList(node* array);

//main function 
int main()
{
//variable declaration
    node *array = new node[27];
    string choice1 = "";
    string choice2, fchoice1, fchoice2;
    char l1, l2;

//create menu sequence
    while (choice1 != "quit")
    {
	cout << "cmd>";
	cin >> choice1;

//if else block to read in user commands
	if (choice1 == "node")
	{
	    cin >> choice2 >> l1;

	    if (l1 >= 'A' && l1 <= 'Z')
	    {
	    	if (choice2 == "add")
	    	{
	            addNode(array, l1);
	    	}
	    	else if (choice2 == "delete")
	    	{
		    delNode(array, l1);
	    	}
		else if (choice2 == "search")
		{
		    int s = serNode(array, l1);
		    if (s >= 0)
		    {cout << "Node Found: " << l1 << endl;}
		}
	    	else
	    	{
		    cout << "Command Not Recognized...\n";
	    	}
	    }
	    else
	    {cout << "Illegal Name Value.\n";}

	}
	else if (choice1 == "edge")
	{
	    cin >> choice2 >> l1 >> l2;

	    if (l1 >= 'A' && l1 <= 'Z' && l2 >= 'A' && l2 <= 'Z')
	    {
	        if (choice2 == "add")
	        {
		    addEdge(array, l1, l2);
	    	}
	    	else if (choice2 == "delete")
	   	{
		    delEdge(array, l1, l2);
	    	}
	   	else
	    	{
		   cout << "Command Not Recognized...\n";
	    	}
	    }
	    else
	    {cout << "Illegal Name Value.\n";}

	}
	else if (choice1 == "print")
	{
	    cin >> choice2;
	    if (choice2 == "matrix")
	    {
		printMat(array);
	    }
	    else if (choice2 == "list")
	    {
		printList(array);
	    }
	    else
	    {
		cout << "Command Not Recognized...";
	    }
	}
	else if (choice1 == "file")
	{
	    ifstream filedile;
	    cin >> choice2;
	    filedile.open(choice2.c_str());
	
	    if (filedile.fail())
	    {cout << "File path not opened.\n\n";}
//**********IN FILE COMMANDS********************

	    while (filedile.good())
	    {
		getline(filedile, fchoice1, ',');
		
		
		if (fchoice1.compare("node") == 0)
		{
		   getline(filedile, fchoice2, ',');
		   filedile.get(l1);
		   filedile.ignore(2, '\n');

	   	   if (l1 >= 'A' && l1 <= 'Z')
		   {
		    	if (fchoice2.compare("add") == 0)
		    	{
		            addNode(array, l1);
		    	}
		    	else if (fchoice2.compare("delete") == 0)
		    	{
			    delNode(array, l1);
		    	}
			else if (fchoice2.compare("search") == 0)
			{
			    int s = serNode(array, l1);
			    if (s >= 0)
			    {cout << "Node Found: " << l1 << endl;}
			}
		    	else
		    	{
			    cout << "Command Not Recognized...\n";
		    	}
		    }
		    else
		    {cout << "Illegal Name Value.\n" ;}
	
		 }
		 else if (fchoice1.compare("edge") == 0)
		 {
		    getline(filedile, fchoice2, ',');
		    filedile.get(l1);
		    filedile.ignore();
		    filedile.get(l2);
		    filedile.ignore(2, '\n');

		    if (l1 >= 'A' && l1 <= 'Z' && l2 >= 'A' && l2 <= 'Z')
		    {
		        if (fchoice2.compare("add") == 0)
		        {
			    addEdge(array, l1, l2);
		    	}
		    	else if (fchoice2.compare("delete") == 0)
		   	{
			    delEdge(array, l1, l2);
		    	}
		   	else
		    	{
			   cout << "Command Not Recognized...\n";
		    	}
		    }
		    else
		    {cout << "Illegal Name Value.\n";}
	
		 }
		 else if (fchoice1.compare("print") == 0)
		 {
		    getline(filedile, fchoice2, ',');
		    filedile.ignore(2, '\n');

		    if (fchoice2.compare("matrix") == 0)
		    {
			printMat(array);
		    }
		    else if (fchoice2.compare("list") == 0)
		    {
			printList(array);
		    }
		    else
		    {
			cout << "Command Not Recognized...";
		    }
		 }
	    }
	    cout << "End of file.\n\n";
//*****************************************
	}
	else if (choice1 == "quit")
	{
	    cout << "Exiting Program...\n\n";
	}
	else
	{
	    cout << "Command Not Recognized...\n";
	}
	
    }

    return 0;
}


//function to add node
void addNode(node* array, char id)
{
//if its the first node
    if (count == 0)
    {
	array[0].id = id;
	array[0].next = NULL;
	cout << "Added: Node " << id << endl;
	count++;
    }
//and other nodes have to be placed alphabetically
    else
    {
	for (int i=0; i<count; i++)
	{
	    if (id < array[i].id)
	    {
		count++;
		for (int j=count; j>=i; j--)
		{
		    array[j] = array[j-1];
		}
		array[i].id = id;
		array[i].next = NULL;
		cout << "Added: Node " << id << endl;
		return;
	    }
	    else if (id == array[i].id)
	    {
		cout << "Duplicate entry.\nNot added.\n\n";
		return;
            }
	}
	array[count].id = id;
	array[count].next = NULL;
	count++;
	cout << "Added: Node " << id << endl;	
    }
}




//function to add an edge
void addEdge(node* array, char id1, char id2)
{
//check that nodes exist and create variables
    int chk1 = serNode(array, id1);
    int chk2 = serNode(array, id2);
    node *pos = new node;
    node *pos2 = new node;
    node *temp = new node;
    node *temp2 = new node;
    node newRec;
    node newRec2;


    if (chk1 != -1 && chk2 != -1 && chk1 != chk2)
    {
//add the edge to the first node
	pos = &array[chk1];
	
	while ((pos->next) != NULL)
	{  
	    if (id2 < ((pos->next)->id))
	    {
		break;
	    }
	    else if (id2 == ((pos->next)->id))
	    {
		cout << "Duplicate edge. Not added.\n";
		return;
	    }
	    else
	    {
		pos = (pos->next);
	    }      
	}
	newRec = *pos;
        temp->id = id2;
	(temp->next) = newRec.next;
	(pos->next) = temp;

	cout << "Edge Added: " << id1 << "->" << id2 << endl;



//add the edge to the second node
	pos2 = &array[chk2];

	while ((pos2->next) != NULL)
	{
	    if (id2 < ((pos2->next)->id))
	    {
		break;
	    }
	    else if (id2 == ((pos2->next)->id))
	    {
		cout << "Duplicate edge. Not added.\n";
		return;
	    }
	    else
	    {
		pos2 = (pos2->next);
	    }

	}
	newRec2 = *pos2;
        temp2->id = id1;
	temp2->next = (newRec2.next);
	pos2->next = temp2;
	cout << "Edge Added: " << id2 << "->" << id1 << endl;

    }
}



//delete a node
void delNode(node* array, char id)
{
    int i = serNode(array, id);
    node *pos = new node;

    if (i >= 0)
    {
	for (int j=i; j<=count; j++)
	{
	    array[j] = array[j+1];
	}
	count--;
	cout << "Deleted: Node " << id << endl;
    }
//***add functionality to remove edges attached to node***
//Doesn't work so far
/*    for (int j=0; j<count; j++)
    {
	pos = &array[j];
	while ((pos->next) != NULL)
       {
	    if (((pos->next)->id) == id)
	    {
		(pos->next) = ((pos->next)->next);
	    }
	    pos = (pos->next);
	}
    }*/
}



//function to delete an edge
void delEdge(node* array, char id1, char id2)
{
    int chk1 = serNode(array, id1);
    int chk2 = serNode(array, id2);
    node *pos = new node;
    node *pos2 = new node;

//check that nodes exist
    if (chk1 != -1 && chk2 != -1 && chk1 != chk2)
    {
//delete from first node
	pos = &array[chk1];
	
	while ((pos->next) != NULL)
	{
	    if (id2 == ((pos->next)->id))
	    {
		(pos->next) = ((pos->next)->next);
		cout << "Edge Deleted: " << id1 << "->" << id2 << endl;
		break;
	    }
	    else
	    {
		pos = (pos->next);
	    } 
	}
//delete from second node
	pos2 = &array[chk2];
	
	while ((pos2->next) != NULL)
	{
	    if (id1 == ((pos2->next)->id))
	    {
		(pos2->next) = ((pos2->next)->next);
		cout << "Edge Deleted: " << id2 << "->" << id1 << endl;
		break;
	    }
	    else
	    {
		pos2 = (pos2->next);
	    } 
	}
    }
}



//function to search for a node
int serNode(node* array, char id)
{
    for (int i=0; i<count; i++)
    {
	if (id == array[i].id)
	{
	    return i;
	}
    }
    cout << "Node not found.\n\n";
    return -1;
}

//print a matrix of the nodes and edges
void printMat(node* array)
{
    char check[count];
    node *pos = new node;

    cout << "Matrix:\n  ";
    for (int i=0; i<count; i++)
    {
	cout << array[i].id << " | ";
	check[i] = array[i].id;
    }
    cout << endl;

    for (int i=0; i<count; i++)
    {
	pos = &array[i];
	cout << pos->id << " ";
	for (int j=0; j<count; j++)
	{
	    if (i == j)
	    {cout << "X   ";}
	    else if ((pos->id) == check[j])
	    {cout << "1   ";}
	    else 
	    {cout << "    ";}
	    if ((pos->next) != NULL)
	    {pos = (pos->next);}
	}
	cout << endl;
    }
    cout << endl;		
}

//print a list of the nodes and their edges
void printList(node* array)
{
    cout << "List:\n";
    node *pos = new node;
    for (int i=0; i<count; i++)
    {
	pos = &array[i];
	cout << pos->id << " -> ";
	while ((pos->next) != NULL)
	{
	    cout << (pos->next)->id << " -> ";
	    pos = (pos->next);
	}
	cout << endl << endl;
    }
}
//******************************************
//Name: Colby Holmes
//Class: CSCE 2110 mwf 10:30
//Assignment: Program 3
//Description: This program is the simple implementation of the Road Atlas
//and Driving Distance Calculator. This assignment stores data for basic
//nodes and edges, giving names and distances. It allows for use of Kruskal's
//algorithm when it is undirected.
//******************************************

#include <iostream>
#include <fstream>
using namespace std;

//create link-list structure
struct node {
    char id;
    node *next;
    string edge;
    int dist;
};

int count = 0;
bool UNDIRECTED = true;

//function prototypes
void addNode(node* array, char id);
void addEdge(node* array, char id1, char id2, string name, int dist, int force);
void delNode(node* array, char id);
void delEdge(node* array, char id1, char id2);
int serNode(node* array, char id);
void kruskal(node* array);
void printMat(node* array);
void printList(node* array);

//main function 
int main()
{
//variable declaration
    node *array = new node[27];
    string choice1 = "";
    string choice2, fchoice1, fchoice2, name;
    int dist;
    char l1, l2;

//create menu sequence
    while (choice1 != "quit")
    {
	cout << "cmd>";
	cin >> choice1;

//if else block to read in user commands
	if (choice1 == "node")
	{
	    cin >> choice2 >> fchoice1;
	    l1 = fchoice1[1];

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
		    {cout << "NODE N" << l1 << ": Found" << endl;}
		}
	    	else
	    	{
		    cout << "Command Not Recognized...\n";
		    continue;
	    	}
	    }
	    else
	    {cout << "Illegal Name Value.\n";}

	}
	else if (choice1 == "edge")
	{
	    cin >> choice2 >> fchoice1 >> fchoice2;
	    l1 = fchoice1[1];
	    l2 = fchoice2[1];

	    if (l1 >= 'A' && l1 <= 'Z' && l2 >= 'A' && l2 <= 'Z')
	    {
	        if (choice2 == "add")
	        {
		    cin >> name >> dist;
		    addEdge(array, l1, l2, name, dist, 0);
	    	}
	    	else if (choice2 == "delete")
	   	{
		    delEdge(array, l1, l2);
	    	}
	   	else
	    	{
		   cout << "Command Not Recognized...\n";
		   continue;
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
		continue;
	    }
	}
	else if (choice1 == "kruskal")
	{
	    if (UNDIRECTED)
	    {
		kruskal(array);
            }
	    else
	    {cout << "ERROR:  Krushal’s Algorithm available only for UNDIRECTED graphs\n\n";}
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
		   getline(filedile, choice1, ',');
		   l1 = choice1[1];
		   filedile.ignore(3, '\n');

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
			    {cout << "NODE N" << l1 << ": Found" << endl;}
			}
		    	else
		    	{
			    cout << "Command Not Recognized...\n";
		    	    continue;
		    	}
		    }
		    else
		    {cout << "Illegal Name Value.\n" ;}
	
		 }
		 else if (fchoice1.compare("edge") == 0)
		 {
		    getline(filedile, fchoice2, ',');
	 	    getline(filedile, choice1, ',');
	            l1 = choice1[1];
		    getline(filedile, choice2, ',');
		    l2 = choice2[1];

		    if (l1 >= 'A' && l1 <= 'Z' && l2 >= 'A' && l2 <= 'Z')
		    {
		        if (fchoice2.compare("add") == 0)
		        {
			    getline(filedile, name, ',');
			    filedile >> dist;
			    filedile.ignore(1, '\n');
			    addEdge(array, l1, l2, name, dist, 0);
		    	}
		    	else if (fchoice2.compare("delete") == 0)
		   	{
		    	    filedile.ignore(2, '\n');
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
		    filedile.ignore(4, '\n');

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
		 else if (fchoice1.compare("kruskal") == 0)
		 {	
		     filedile.ignore(5, '\n');
	   	     if (UNDIRECTED)
	  	     {
			kruskal(array);
     	             }
	   	     else
	    	     {cout << "ERROR:  Krushal’s Algorithm available only for UNDIRECTED graphs\n\n";}
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
	    continue;
	}
	
    }

    return 0;
}



//*** KRUSKAL'S function ***
void kruskal(node* array)
{
    node *pos = new node;
    node *temp = new node;
    string edges[count];
    bool check;

    cout << "\nKruskal's:\n";

    for (int i=0; i<count; i++)
    {
	edges[i] = "";
    }

    for (int i=0; i<count; i++)
    {
	pos = &array[i];
	if ((pos->next) != NULL)
	{
	    temp = (pos->next);
	    pos = (pos->next);
	}

	while ((pos->next) != NULL)
	{
//check against previously used edges to prevent repeats
	    for (int j=0; j<count; j++)
	    {
		if ((temp->edge) == edges[j])
		{
		    temp = (pos->next);
		    check = false;
		    break;
		}
	    }
	    if (((pos->next)->dist) < (temp->dist) && check)
	    {
		temp = (pos->next);
	    }
	    pos = (pos->next);
	}
	
	cout << "N" << array[i].id << " -(" << temp->edge << ", " 
	<< temp->dist << ")-> N" << temp->id << endl;

    }
	cout << endl;
}



//function to add node
void addNode(node* array, char id)
{
//if its the first node
    if (count == 0)
    {
	array[0].id = id;
	array[0].next = NULL;
	array[0].dist = 0;
	array[0].edge = "";
	cout << "Added: Node N" << id << endl;
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
		array[i].dist = 0;
		array[i].edge = "";
		cout << "Added: NODE " << id << endl;
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
	cout << "Added: NODE N" << id << endl;	
    }
}




//function to add an edge
void addEdge(node* array, char id1, char id2, string name, int dist, int force)
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
		cout << "EDGE N" << id1 << "-N" << id2 
		<< " UPDATE:" 
		<< " NAME: " << name << " DIST: " << dist << endl;
		((pos->next)->edge) = name;
		((pos->next)->dist) = dist;
		if (force == 0)
		{
		    force = -1;
		    addEdge(array, id2, id1, name, dist, force);
		}
		else
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
	temp->edge = name;
	temp->dist = dist;
	(pos->next) = temp;

	cout << "ADDED: EDGE N" << id1 << "-N" << id2  
	<< " NAME: " << name << " DIST: " << dist << endl;



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
	temp2->edge = name;
	temp2->dist = dist;
	pos2->next = temp2;
	cout << "ADDED: EDGE N" << id2 << "-N" << id1  
	<< " NAME: " << name << " DIST: " << dist << endl;

    }
}



//delete a node
void delNode(node* array, char id)
{
    int i = serNode(array, id);
    node *pos = new node;

    if (i >= 0)
    {
	for (int j=0; j<count; j++)
    	{
	pos = &array[j];
	    while ((pos->next) != NULL)
            {
	    	if (((pos->next)->id) == id)
	    	{
		    cout << "EDGE AUTO-REMOVED BY NODE DELETION: N" 
		    << id << "-N" << array[j].id << endl;
	    	    (pos->next) = ((pos->next)->next);
	    	}
	        if ((pos->next) != NULL)
	        {pos = (pos->next);}
	    }
        }

	for (int j=i; j<=count; j++)
	{
	    array[j] = array[j+1];
	}
	count--;
	cout << "DELETED: NODE N" << id << endl << endl;
    }
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
		cout << "DELETED: EDGE N" << id1 << "-N" << id2 << endl;
		break;
	    }
	    else
	    {
		pos = (pos->next);
	    } 
	}
	
	UNDIRECTED = false;

//removed functionality
/*delete from second node
	pos2 = &array[chk2];
	
	while ((pos2->next) != NULL)
	{
	    if (id1 == ((pos2->next)->id))
	    {
		(pos2->next) = ((pos2->next)->next);
		cout << "DELETED: EDGE N" << id2 << "-N" << id1 << endl;
		break;
	    }
	    else
	    {
		pos2 = (pos2->next);
	    } 
	}*/
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
    cout << "NODE N" << id << ": NOT FOUND.\n\n";
    return -1;
}

//print a matrix of the nodes and edges
void printMat(node* array)
{
    char check[count];
    node *pos = new node;

    cout << "Matrix:\n     ";
    for (int i=0; i<count; i++)
    {
	cout << "  N" << array[i].id << "   |";
	check[i] = array[i].id;
    }
    cout << endl;

    for (int i=0; i<count; i++)
    {
	pos = &array[i];
	cout << "N" << pos->id << "   ";
	for (int j=0; j<count; j++)
	{
	    if (i == j)
	    {cout << "   X    ";}
	    else if ((pos->id) == check[j])
	    {cout << "(" << pos->dist << ", " << pos->edge << ")";}
	    else 
	    {cout << "        ";}
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
	cout << "N" << pos->id;
	while ((pos->next) != NULL)
	{
	    cout << " -(" << ((pos->next)->dist) << ", " << ((pos->next)->edge) 
	    << ")> N" << (pos->next)->id;
	    pos = (pos->next);
	}
	cout << endl << endl;
    }
}
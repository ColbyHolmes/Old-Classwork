/*Colby Holmes
Program 3
Implementation of AVL tree
Due 11/2*/
#include <iostream>
using namespace std;

/*NOTE: Functions are grossly written and all over the place as far as syntax goes...
I apologize for this. It's a result of trying to pack all of the code in one 
properly named file, and working over multiple nights.*/

//ALSO node depth is shown in the find function. Tree depth is called in the menu

class Tree{
public:
int n;
char c;
float f;

Tree* left;
Tree* right;

//functions
Tree()
{
  left = NULL;
  right = NULL;
} 
Tree(int n);//construct integer tree
Tree(char c);//construct character tree
Tree(float f);//construct floating pt tree

int height(Tree* node);

Tree* insert(Tree*& node, int d_IN);//overloaded functions for types
Tree* insert(Tree*& node, char d_IN);
Tree* insert(Tree*& node, float d_IN);

Tree* deleteNodeI(Tree* root, int key);
Tree* deleteNodeC(Tree* root, char key);
Tree* deleteNodeF(Tree* root, float key);

void find(Tree* root, int num, int depth, string out);
void find(Tree* root, char lett, int depth, string out);
void find(Tree* root, float dec, int depth, string out);

void rotateLeftOnce(Tree*& node);
void rotateLeftTwice(Tree*& node);
void rotateRightOnce(Tree*& node);
void rotateRightTwice(Tree*& node);
};

Tree *INT, *CHAR, *FLO;//GLOBALS
bool iTree = false;
bool cTree = false;
bool fTree = false;//checks for if tree exists already

//*****************************find height of node
int Tree::height(Tree* node){
     int left, right;

     if(node==NULL)
         return 0;
     left = height(node->left);
     right = height(node->right);
  if(left > right)
            return left+1;
         else
            return right+1;
} 



// Get Balance factor of node N
int getBalance(Tree *N)
{
    if (N == NULL)
        return 0;
    return (N->left)->height(N->left) - (N->right)->height(N->right);
}
 


//**********************************ROTATE FUNCTIONS
void Tree::rotateLeftOnce(Tree*& node){
     Tree *otherNode;

     otherNode = node->left;
     node->left = otherNode->right;
     otherNode->right = node;
     node = otherNode;
}


void Tree::rotateLeftTwice(Tree*& node){
     rotateRightOnce(node->left);
     rotateLeftOnce(node);
}


void Tree::rotateRightOnce(Tree*& node){
     Tree *otherNode;

     otherNode = node->right;
     node->right = otherNode->left;
     otherNode->left = node;
     node = otherNode;
}


void Tree::rotateRightTwice(Tree*& node){
     rotateLeftOnce(node->right);
     rotateRightOnce(node);
}



//*****************************INSERT INT
Tree* Tree::insert(Tree*& node, int d_IN){
     if(node == NULL){  // (1) If we are at the end of the tree place the value
         node = new Tree();
	 node->n = d_IN;
	 }
     else if(d_IN < node->n){  //(2) otherwise go left if smaller
         insert(node->left, d_IN);    
         if(height(node->left) - height(node->right) == 2){
            if(d_IN < node->left->n)
                rotateLeftOnce(node);
            else
                rotateLeftTwice(node);
         }
     }
     else if(d_IN > node->n){ // (3) otherwise go right if bigger
        insert(node->right, d_IN);
        if(height(node->right) - height(node->left) == 2){
            if(d_IN > node->right->n)
                rotateRightOnce(node);
            else
                rotateRightTwice(node);
        }
     }
     return node;
}


//******************************INSERT LETTER
Tree* Tree::insert(Tree*& node, char d_IN){
     if(node == NULL){  // (1) If we are at the end of the tree place the value
         node = new Tree();
	 node->c = d_IN;
	 }
     else if(d_IN < node->c){  //(2) otherwise go left if smaller
         insert(node->left, d_IN);    
         if(height(node->left) - height(node->right) == 2){
            if(d_IN < node->left->c)
                rotateLeftOnce(node);
            else
                rotateLeftTwice(node);
         }
     }
     else if(d_IN > node->c){ // (3) otherwise go right if bigger
        insert(node->right, d_IN);
        if(height(node->right) - height(node->left) == 2){
            if(d_IN > node->right->c)
                rotateRightOnce(node);
            else
                rotateRightTwice(node);
        }
     }
     return node;
}


//**********************************INSERT FLOAT
Tree* Tree::insert(Tree*& node, float d_IN){
     if(node == NULL){  // (1) If we are at the end of the tree place the value
         node = new Tree();
	 node->f = d_IN;
	 }
     else if(d_IN < node->f){  //(2) otherwise go left if smaller
         insert(node->left, d_IN);    
         if(height(node->left) - height(node->right) == 2){
            if(d_IN < node->left->f)
                rotateLeftOnce(node);
            else
                rotateLeftTwice(node);
         }
     }
     else if(d_IN > node->f){ // (3) otherwise go right if bigger
        insert(node->right, d_IN);
        if(height(node->right) - height(node->left) == 2){
            if(d_IN > node->right->f)
                rotateRightOnce(node);
            else
                rotateRightTwice(node);
        }
     }
     return node;
}



Tree* minValueNode(Tree* node)
{
    Tree* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

//***********************************delete functions
Tree* Tree::deleteNodeI(Tree* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->n )
        root->left = deleteNodeI(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->n )
        root->right = deleteNodeI(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Tree *temp = root->left ? root->left : root->right;
 
            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Tree* temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->n = temp->n;
 
            // Delete the inorder successor
            root->right = deleteNodeI(root->right, temp->n);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // STEP 2: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        root->rotateRightOnce(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        (root->left)->rotateLeftOnce(root->left);
        root->rotateRightOnce(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        root->rotateLeftOnce(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        (root->right)->rotateRightOnce(root->right);
        root->rotateRightOnce(root);
    }
 
    return root;
}

Tree* Tree::deleteNodeC(Tree* root, char key)//del char****
{
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->c )
        root->left = deleteNodeI(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->c )
        root->right = deleteNodeI(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Tree *temp = root->left ? root->left : root->right;
 
            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Tree* temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->n = temp->c;
 
            // Delete the inorder successor
            root->right = deleteNodeI(root->right, temp->c);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // STEP 2: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        root->rotateRightOnce(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        (root->left)->rotateLeftOnce(root->left);
        root->rotateRightOnce(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        root->rotateLeftOnce(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        (root->right)->rotateRightOnce(root->right);
        root->rotateRightOnce(root);
    }
 
    return root;
}

Tree* Tree::deleteNodeF(Tree* root, float key)//del Float
{
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->f )
        root->left = deleteNodeI(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->f )
        root->right = deleteNodeI(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Tree *temp = root->left ? root->left : root->right;
 
            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Tree* temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->n = temp->f;
 
            // Delete the inorder successor
            root->right = deleteNodeI(root->right, temp->f);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // STEP 2: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        root->rotateRightOnce(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        (root->left)->rotateLeftOnce(root->left);
        root->rotateRightOnce(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        root->rotateLeftOnce(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        (root->right)->rotateRightOnce(root->right);
        root->rotateRightOnce(root);
    }
 
    return root;
}


//*****************************Find functions
void Tree::find(Tree* root, int num, int depth, string out)
{
    if (root == NULL)
    {
	cout << num << " not found!\n\n";
        return;
    }
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( num < root->n )
    {
	out += "->leftchild";
        (root->left)->find(root->left, num, depth + 1, out);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( num > root->n )
    {
	out += "->rightchild";
        (root->right)->find(root->right, num, depth + 1, out);
    }
    // if key is same as root's key
    else
    {
	cout << "\nKey: " << num << "\nDepth: " << depth << "\nPath: " << out << "\n\n";
    }
}

void Tree::find(Tree* root, char lett, int depth, string out)
{
    if (root == NULL)
    {
	cout << lett << " not found!\n\n";
        return;
    }
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( lett < root->c )
    {
	out += "->leftchild";
        (root->left)->find(root->left, lett, depth + 1, out);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( lett > root->c )
    {
	out += "->rightchild";
        (root->right)->find(root->right, lett, depth + 1, out);
    }
    // if key is same as root's key
    else
    {
	cout << "\nKey: " << lett << "\nDepth: " << depth << "\nPath: " << out << "\n\n";
    }
}

void Tree::find(Tree* root, float dec, int depth, string out)
{
    if (root == NULL)
    {
	cout << dec << " not found!\n\n";
        return;
    }
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( dec < root->f )
    {
	out += "->leftchild";
        (root->left)->find(root->left, dec, depth + 1, out);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( dec > root->f )
    {
	out += "->rightchild";
        (root->right)->find(root->right, dec, depth + 1, out);
    }
    // if key is same as root's key
    else
    {
	cout << "\nKey: " << dec << "\nDepth: " << depth << "\nPath: " << out << "\n\n";
    }
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorderI(Tree* node)
{
     if (node == NULL)
        return;
 
     // first recur on left subtree
     printPostorderI(node->left);
 
     // then recur on right subtree
     printPostorderI(node->right);
 
     // now deal with the node
     cout << node->n << " ";
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorderC(Tree* node)
{
     if (node == NULL)
        return;
 
     // first recur on left subtree
     printPostorderC(node->left);
 
     // then recur on right subtree
     printPostorderC(node->right);
 
     // now deal with the node
     cout << node->c << " ";
} 

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorderF(Tree* node)
{
     if (node == NULL)
        return;
 
     // first recur on left subtree
     printPostorderF(node->left);
 
     // then recur on right subtree
     printPostorderF(node->right);
 
     // now deal with the node
     cout << node->f << " ";
}


/* Given a binary tree, print its nodes in inorder*/
void printInorderI(Tree* node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printInorderI(node->left);
 
     /* then print the data of node */
     cout << node->n << " ";
 
     /* now recur on right child */
     printInorderI(node->right);
}
 

/* Given a binary tree, print its nodes in inorder*/
void printInorderC(Tree* node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printInorderC(node->left);
 
     /* then print the data of node */
     cout << node->c << " ";
 
     /* now recur on right child */
     printInorderC(node->right);
}
 

/* Given a binary tree, print its nodes in inorder*/
void printInorderF(Tree* node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printInorderF(node->left);
 
     /* then print the data of node */
     cout << node->f << " ";
 
     /* now recur on right child */
     printInorderF(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorderI(Tree* node)
{
     if (node == NULL)
          return;
 
     /* first print data of node */
     cout << node->n << " ";
 
     /* then recur on left sutree */
     printPreorderI(node->left);  
 
     /* now recur on right subtree */
     printPreorderI(node->right);
}    

/* Given a binary tree, print its nodes in preorder*/
void printPreorderC(Tree* node)
{
     if (node == NULL)
          return;
 
     /* first print data of node */
     cout << node->c << " ";
 
     /* then recur on left sutree */
     printPreorderC(node->left);  
 
     /* now recur on right subtree */
     printPreorderC(node->right);
}    

/* Given a binary tree, print its nodes in preorder*/
void printPreorderF(Tree* node)
{
     if (node == NULL)
          return;
 
     /* first print data of node */
     cout << node->f << " ";
 
     /* then recur on left sutree */
     printPreorderF(node->left);  
 
     /* now recur on right subtree */
     printPreorderF(node->right);
}    


//**************************PRINT MENU
void printmenu(){
  cout << "\n\tAVL Tree Program\n\n1. Insert element\n2. Delete element\n"
	<< "3. Find element\n4. Print Tree\n5. Find Tree depth\nq. Quit\n\ncmd>";
}




//******************************MAIN FUNCTION
int main(){
  char input = ' ';

  while (input != 'q')
  {
    printmenu();
    cin >> input;

    if (input == '1')//insert
    {
      char type = ' ';
      int num;

      cout << "\nWhich tree are you populating:\n\ti. Integer\n\t"
	<< "c. Character\n\tf. Float\n\ncmd>";
      cin >> type;

      cout << "\nHow many items would you like to insert in the tree\ncmd>";
      cin >> num;

      if (type == 'i') //insert integer
      { 
	for (int i = 0; i < num; i++)
	{
	  int set;
	  cout << i+1 << ". Enter integer to insert: ";
	  cin >> set;

	  if (!iTree) //if the tree hasn't been initialized
	  {
	    INT = new Tree();
	    INT->n = set;
	    INT->left = NULL;
	    INT->right = NULL;
	    iTree = true;
	  }
	  else
	    INT = INT->insert(INT, set);
	}
      }
      else if (type == 'c') //insert character
      {
	for (int i = 0; i < num; i++)
	{
	  char set;
	  cout << i+1 << ". Enter letter to insert: ";
	  cin >> set;

	  if (!cTree) //if the tree hasn't been initialized
	  {
	    CHAR = new Tree();
	    CHAR->c = set;
	    cTree = true;
	  }
	  else
	    CHAR = CHAR->insert(CHAR, set);
	}
      }
      else if (type == 'f') //insert float
      {
	for (int i = 0; i < num; i++)
	{
	  float set;
	  cout << i+1 << ". Enter float to insert: ";
	  cin >> set;

	  if (!fTree) //if the tree hasn't been initialized
	  {
	    FLO = new Tree();
	    FLO->f = set;
	    fTree = true;
	  }
	  else
	    FLO = FLO->insert(FLO, set);
	}
      }
      else //unrecognized
	cout << "\nINVALID TYPE\n\n";
      
    }

    else if (input == '2')//delete
    {
      char type = ' ';


      cout << "\nWhich tree are you removing from:\n\ti. Integer\n\t"
	<< "c. Character\n\tf. Float\n\ncmd>";
      cin >> type;

      if (type == 'i') //del integer
      { 
	  int set;
	  cout << "Enter integer to delete: ";
	  cin >> set;

	  INT = INT->deleteNodeI(INT, set);

      }
      else if (type == 'c') //del character
      {

	  char set;
	  cout << "Enter letter to delete: ";
	  cin >> set;

	  CHAR = CHAR->deleteNodeC(CHAR, set);
      }
      else if (type == 'f') //del float
      {
	  float set;
	  cout << "Enter float to delete: ";
	  cin >> set;

	  FLO = FLO->deleteNodeF(FLO, set);
      }
      else //unrecognized
	cout << "\nINVALID TYPE\n\n";
     
    }

    else if (input == '3')//find
    {
      char type = ' ';

      cout << "\nWhich tree are you searching:\n\ti. Integer\n\t"
	<< "c. Character\n\tf. Float\n\ncmd>";
      cin >> type;

      switch(type){
	case 'i':
	  int key;
	  cout << "Enter integer to find: ";
	  cin >> key;
	  INT->find(INT, key, 0, "root");
	  break;

	case 'c':
	  char l;
	  cout << "Enter character to find: ";
	  cin >> l;
	  CHAR->find(CHAR, l, 0, "root");
	  break;

	case 'f':
	  float fl;
	  cout << "Enter float to find: ";
	  cin >> fl;
	  FLO->find(FLO, fl, 0, "root");
	  break;

	default:
	  cout << "\nINVALID TYPE\n\n";
      }
    }
    else if (input == '4')//print
    {
      char type = ' ';

      cout << "\nWhich tree are you printing:\n\ti. Integer\n\t"
	<< "c. Character\n\tf. Float\n\ncmd>";
      cin >> type;

      switch(type){
	case 'i':
	  cout << "\nPreorder:\n";
	  printPreorderI(INT);
	  cout << "\n\nInorder:\n";
	  printInorderI(INT);
	  cout << "\n\nPostorder:\n";
	  printPostorderI(INT);
	  break;

	case 'c':
	  cout << "\nPreorder:\n";
	  printPreorderC(CHAR);
	  cout << "\n\nInorder:\n";
	  printInorderC(CHAR);
	  cout << "\n\nPostorder:\n";
	  printPostorderC(CHAR);
	  break;

	case 'f':
	  cout << "\nPreorder:\n";
	  printPreorderF(FLO);
	  cout << "\n\nInorder:\n";
	  printInorderF(FLO);
	  cout << "\n\nPostorder:\n";
	  printPostorderF(FLO);
	  break;

	default:
	  cout << "\nINVALID TYPE\n\n";
      }
    }

    else if (input == '5')//depth
    {
	//**tree depth. node depth shown in the find function**
	cout << "\nInteger Tree depth:\t" << INT->height(INT);
	cout << "\nCharacter Tree depth:\t" << CHAR->height(CHAR);
	cout << "\nFloat Tree depth:\t" << FLO->height(FLO) << "\n\n";	
    }

    else if (input == 'q')//quit
    {cout << "\nCLOSING PROGRAM\n\n";}

    else
      cout << "\nINVALID INPUT\n\n";
  }//msg loop

  return 0;
}
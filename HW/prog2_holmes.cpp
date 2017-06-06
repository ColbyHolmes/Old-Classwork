/*Colby Holmes
Program 2
Infix to Postfix
Due Oct 5*/

//include dependencies
#include <iostream>
#include <stack>
#include <string.h>
#include <stdio.h>
using namespace std;


//main function
int main()
{
  std::stack<char> temp;//declare variables
  std::string postfix = "";

  cout << "Enter the infix expression: ";//ask for user input
  
  while(cin.peek() != '\n')//while there are still characters to read
  {
    if(cin.peek() >= 'a' && cin.peek() <= 'z')//if its a char
      postfix += cin.get();//add it to the postfix expression

    else if (cin.peek() == '+' || cin.peek() == '-')//case add or subtract
    {
      while(!temp.empty())
      {
	  postfix += temp.top();//lowest precedence
	  temp.pop();
      }
      temp.push(cin.get());//add operator to stack
    }

    else if (cin.peek() == '*' || cin.peek() == '/')//case mult or div
    {
      while(!temp.empty() && temp.top() != '+' && temp.top() != '-')//compare stack with next operator
      {
	  postfix += temp.top();
	  temp.pop();
      }
      temp.push(cin.get());//add operator to stack
    }

    else if (cin.peek() == '^')
    {
	temp.push(cin.get());//highest precedence, always add to stack
    }

  }

  while(!temp.empty())//finish by emptying the stack
  {
    postfix += temp.top();
    temp.pop();
  }

  cout << postfix << endl;

  return 0;
}

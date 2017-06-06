// file: revString.cpp
// String manipulation example
// This is an inlab exercise and is incomplete

#include <iostream>
#include <strstream>   // for string streams
#include <string>
#include <cstdio>
#include <stack>
using namespace std;


// MAX_INPUT is the maximum number of characters that we allow to be
// read into a string object with istream::getline()
static const int MAX_INPUT = 256;


int main()
{
    char buf[MAX_INPUT];
    string line = "";
    string word;
    stack<string> words;
    cout << "enter a line: ";

/* The following would be the best way to read in a line into a string 
 * object; however, there is a bug in the code provided by MSVC that
 * reads an extra character (so the user would have to hit return twice.
 * - see http://support.microsoft.com/support/kb/articles/Q240/0/15.ASP

    getline( cin, line );

 */

    // The following is a workaround, use istream::getline() instead of
    // the function getline.
    cin.getline( buf, MAX_INPUT );
    line = buf;
    
    // open a stream bound to the line
    istrstream input( line.c_str() ); 

    while ( input >> word )
    {
        words.push(word);
    }

    while (!words.empty())
    {
	cout << words.top() << " ";
	words.pop();
    }
	cout << endl;

    return 0;
}

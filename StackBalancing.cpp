#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>

// Name: Chris Keveloh
// Description: this program uses a stack to check the balancing symbols of a text file. Program reads in a file and will display one of 4 cases. 

using namespace std;


int main(int argc, char** argv) // accepting the filename through command line parameters
{

if(argc != 2)
{
    cout<< "Usage:" <<argv[0] << "fileName" << endl;
    exit(1);
}

string fileName = argv[1]; 

ifstream file(fileName);

if(!file) // error handling for incorrect file name and or cannot found file
{
    cerr <<"Error opening input file" << fileName << endl;
    return 0;
}

stack<char> symbolStack; // creating stack
int errors = 0; // creating error counter and line number tracker
int lineNumber = 1;

string line;
getline(file,line); 

while(getline(file,line)) // looping through the file by line
{
    
    lineNumber++;
for(int i = 0; i<line.length(); ++i) // looping through each character in the line
{
    char currentCharacter = line[i];

    if(currentCharacter == '(' || currentCharacter == '[' || currentCharacter == '{' || currentCharacter == '/') // if its an openeing character we push onto stack
    {
        symbolStack.push(currentCharacter);

    }

    else if(currentCharacter == ')' || currentCharacter == ']' || currentCharacter == '}' || currentCharacter == '*') // if its closing character we ask if the stack is empty and if it is then we have no opening symbol
    {
        if(symbolStack.empty())
        {
            errors++;
            cout <<"\"" << currentCharacter << "\"" << " on line " << lineNumber << " has no matching opening symbol." << endl; 
            
            break;
        }
        
        else // if the symbolstack is not empty we check to see if the symbols match
        {
            char topOfStack = symbolStack.top();
            symbolStack.pop();
            if(currentCharacter == ')' && topOfStack != '(' || currentCharacter == ']' && topOfStack != '[' || currentCharacter == '}' && topOfStack != '{' || currentCharacter == '*' && topOfStack != '/')
                {
                    errors++;
                    cout <<"\"" << topOfStack << "\"" << " does not match \""   << currentCharacter << "\"" <<  " on line " << lineNumber << "." << endl;
                    break;
                }
            }
        }
    }
}


while(!symbolStack.empty() && errors == 0 ) // at the end of the file if we have no errors and the symbolstack is not empty we have an unmatched symbol
{
    errors++;
    char unMatched = symbolStack.top();
    cout << "End of program reached with unmatched " << "\"" << unMatched <<"\"" << "." <<endl;
    break;
}

if(errors == 0) // if end of file and 0 errors then we have all symbols balanced
{
    cout << "All symbols correctly balanced." << endl;
}

return 0;
}

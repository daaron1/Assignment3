#include <iostream>
#include "GenStack.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



char getOtherChar(char c)
{
  if(c=='{') return '}';
  else if(c=='}') return '{';

  else if(c=='(') return ')';
  else if(c==')') return '(';

  else if(c=='[') return ']';
  else if(c==']') return '[';
  return 0;
}


bool isValid(string filename)
{
  bool valid = true;
  ifstream myfile(filename);

  GenStack<char> genStack;

  if (!myfile.is_open())
  {
    cout << "File not found."<<endl;
    return false;
  }
  string line;

  int lineCount = 0;

  while ( getline (myfile,line) )
  {
   for(int i=0; i<=line.length(); ++i)
   {
     if(line[i]=='{' || line[i]=='(' || line[i]=='[' )
     {
       genStack.push(line[i]);

     }
     else if(line[i]=='}' || line[i]==')' || line[i]==']')
     {
       if(genStack.isEmpty())
       {
         cout<< "Line " <<lineCount+1 <<": Unexpected "<<line[i]<<endl;
         valid = false;
       }
       else
       {
         char openChar = genStack.pop();
         char closeChar = line[i];
         if(openChar != getOtherChar(closeChar))
         {
           cout<< "Line "<< lineCount+1 <<": expected "<<getOtherChar(openChar)<< " and found "<<closeChar<<endl;
           valid = false;
         }
       }
     }
   }
   lineCount++;
  }

  while(!genStack.isEmpty())
  {
   char openChar = genStack.pop();
   cout<< "Reached end of file: missing: " << getOtherChar(openChar)<<endl;
   valid = false;
  }


  myfile.close();


  return valid;

}



int main(int argc, char const *argv[])
{
   if(argc != 2)
   {
      cout << "USAGE: assignment3.exe <filename>"<< endl;
      return 0;
   }

   string filename = argv[1];

   if(isValid(filename))
   {
     cout<<"Delimter Syntax: OK! "<<endl;
   }

   char userInput;

   cout<<"Chose another file? (enter y to continue): ";

   cin>>userInput;

   while(userInput=='y')
   {
     cout<<"Enter file name: ";
     cin>>filename;
     if(isValid(filename))
     {
       cout<<"Delimter Syntax: OK! "<<endl;
     }
     cout<<"Chose another file? (enter y to continue): ";

     cin>>userInput;
   }


}

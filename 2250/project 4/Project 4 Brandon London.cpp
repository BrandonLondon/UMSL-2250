//============================================================================
// Name        : Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string>
using namespace std;
class DelimiterStack {
private:

struct DelimiterNode {
   char character;
   int lineNumber;
   int charCount;
   struct DelimiterNode *nextNode;
};
   DelimiterNode *stackTop;


public:
DelimiterStack()
   {stackTop = 0;}
~DelimiterStack() ;
void push(char, int, int);
void popDelimiter(char&, int &, int &);
bool isEmpty();
};
DelimiterStack::~DelimiterStack()
{
   DelimiterNode *delimNodePtr = 0;
   DelimiterNode *delimNextNodePtr = 0;

   delimNodePtr = stackTop;
   while(delimNodePtr != 0)
   {
       delimNextNodePtr = delimNodePtr;
       delete delimNodePtr;
       delimNodePtr = delimNextNodePtr;
   }
}
void DelimiterStack::push(char charact, int cNum, int lNum)
{

   DelimiterNode* tmpDelimNode = 0;
   try
   {
       tmpDelimNode = new DelimiterNode;
   }
   catch (bad_alloc)
   {
       cout << "Allocation errrorr" << endl;
       return;
   }

   tmpDelimNode->character = charact;
   tmpDelimNode->charCount = cNum;
   tmpDelimNode->lineNumber = lNum;
   if (isEmpty())
   {
       stackTop = tmpDelimNode;
       tmpDelimNode->nextNode = 0;
   }
   else
   {
       tmpDelimNode->nextNode = stackTop;
       stackTop = tmpDelimNode;
   }

}
void DelimiterStack::popDelimiter(char &charact, int &cNum, int &lNum)
{
   DelimiterNode* temp = 0;

   if (isEmpty())
   {
       charact = ';';
       cNum = -1;
       lNum = -1;
   }
   else
   {
       charact = stackTop->character;
       cNum = stackTop->charCount;
       lNum = stackTop->lineNumber;
       temp = stackTop->nextNode;
       delete stackTop;
       stackTop = temp;
   }
}
bool DelimiterStack::isEmpty()
{
   bool emptyStat;

   if (!stackTop)
       emptyStat = true;
   else
       emptyStat = false;
   return emptyStat;
}
int main()
{
   int countLine = 0;
   DelimiterStack mydelistack;
    char charPush   = '~';
    int pushCNum = -1;
    int pushLNum = -1;

   char popChar;
   int popCNum;
   int popLNum;
   bool popCheck=false;
   string currentLine = "";
   do {
       charPush = '~';
       pushCNum = -1;
       pushLNum = -1;
       countLine++;

      getline(cin, currentLine);
   for(int i=0;i<currentLine.length();i++)
   {
          if (currentLine.at(i) == '{' || currentLine.at(i) == '[' || currentLine.at(i) == '(')
           {
               charPush = currentLine.at(i);
               pushCNum = i;
               pushLNum = countLine;
               mydelistack.push(charPush, pushCNum, pushLNum);
           }
           if (currentLine.at(i) == '}' || currentLine.at(i) == ']' || currentLine.at(i) == ')')
           {

               mydelistack.popDelimiter(popChar, popCNum, popLNum);

               if (popCNum!=-1)
               {
                   if (currentLine.at(i) == ']' && popChar == '[')
                   {
                       break;
                   }
                   else if (currentLine.at(i) == '}' && popChar == '{')
                   {
                       break;
                   }
                   else if (currentLine.at(i) == ')' && popChar == '(')
                   {
                       break;
                   }
                   else
                   {
                       cout << "Mismatched delimiter " << currentLine.at(i) << " found at line " << countLine<< ", char ";
                       cout<< i + 1   << popChar << " found at line " << popLNum<< ", char " << popCNum << endl;
                   }
               }
               else if (!popCheck && charPush == '~' && pushCNum == -1 && pushLNum == -1)
               {
                   cout << "Right delimiter " << currentLine.at(i) << " at line " << countLine<< ", char " << i + 1 << " has no found left delimiter.\n";
               }
           }
       }


} while (currentLine!="DONE");

   bool finalCheck = mydelistack.isEmpty();
   if(finalCheck)
   {
       cout<<"The block is delimeter matched"<<endl;
   }
   while (!finalCheck)
   {
       mydelistack.popDelimiter(popChar, popCNum, popLNum);
       cout << "Left delimiter " << popChar <<" at line "<< popLNum<< ", char " << popCNum << " has no right delimiter.\n";
       finalCheck = mydelistack.isEmpty();
   }
cin.get();
return 0;
}

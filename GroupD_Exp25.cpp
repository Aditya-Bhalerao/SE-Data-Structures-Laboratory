// A palindrome is a string of character that‘s the same forward and backward. Typically,
// punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop”
// is a palindrome, as can be seen by examining the characters “poor danisina droop” and
// observing that they are the same forward and backward. One way to check for a
// palindrome is to reverse the characters in the string and then compare with them the
// original-in a palindrome, the sequence will be identical. Write C++ program with
// functionsa) To print original string followed by reversed string using stack
// b) To check whether given string is palindrome or not.

#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;
#define MAX 50

class Stack
{
private:
    char data[MAX],str[MAX];
    int top,length,count;

    void pushData(char);
    char popData();

public:
    Stack()
    {
        top=-1;
        length=0;
        count=0;
    }
    void getString();
    void checkPalindrome();
    void extractString();
    void displayReverse();
};

int main()
{
    Stack obj;
    obj.getString();
    cout<<"\n Extracted string: ";
    obj.extractString();
    cout<<"\n Reverse of entered string: ";
    obj.displayReverse();
    obj.checkPalindrome();
    return 0;
}

void Stack::getString()
{
    cout<<"\n Enter a String: ";
    cin.getline(str,MAX);

    length=strlen(str);
}

void Stack::extractString()
{
    char temp[MAX];
    int i,j;
    for(i=0; i<length; i++)
    {
        temp[i]=str[i];
    }
    j=0;
    for(i=0; i<length; i++ )
    {
        if(isalpha(temp[i]))
        {
            str[j]=tolower(temp[i]);
            j++;
        }
    }

    length=j;
    for(int i=0; i<length; i++)
        cout<<str[i];
}

void Stack::checkPalindrome()
{
    for(int i=0; i<length; i++)
        pushData(str[i]);

    for(int i=0; i<length; i++)
    {
        if(str[i]==popData())
            count++;
    }

    if(count==length)
    {
        cout<<"\n Entered string is a Palindrome. \n";
    }
    else  cout<<"\n Entered string is not a Palindrome. \n";
}

void Stack::displayReverse()
{
    for(int i=length-1; i>=0; i--)
        cout<<str[i];
}

void Stack::pushData(char temp)
{
    if(top==MAX-1)
    {
        cout<<"\n Stack Overflow!!!";
        return;
    }

    top++;
    data[top]=temp;

}

char Stack::popData()
{
    if(top==-1)
    {
        cout<<"\n Stack Underflow!!!";
        return 0;
    }
    char temp=data[top];
    top--;
    return temp;
}

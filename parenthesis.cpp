
#include<iostream>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch)
{
    if(top == MAX-1)
        cout << "Stack Overflow";
    else
    {
        top++;
        stack[top] = ch;
    }
}

// Pop operation
char pop()
{
    if(top == -1)
        return '\0';
    else
    {
        char ch = stack[top];
        top--;
        return ch;
    }
}

// Check balanced parentheses
int isBalanced(char exp[])
{
    top = -1;

    for(int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(top == -1)
                return 0;

            char x = pop();

            if((ch == ')' && x != '(') ||
               (ch == '}' && x != '{') ||
               (ch == ']' && x != '['))
            {
                return 0;
            }
        }
    }

    if(top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char exp[MAX];

    cout << "Enter expression: ";
    cin >> exp;

    if(isBalanced(exp))
        cout << "Expression is Balanced";
    else
        cout << "Expression is Not Balanced";

    return 0;
}


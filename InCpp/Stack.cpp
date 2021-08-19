// StackExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
using namespace std;

#define MAX  10
int stacksize = 0;

// creating a stack
struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st* s)
{
    s->top = -1;
}

// check if the stack is full
int isfull(st* s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// check if the stack is empty
int isempty(st* s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// add elements to the stack
void push(st* s, int newitem)
{
    if (isfull(s))
    {
        cout << "STACK IS FULL" << endl;
    }
    else
    {
        s->top++;
        s->items[s->top] = newitem;
    }
    stacksize++;
}

// remove elements from the array
void pop(st* s)
{
    if (isempty(s))
    {
        cout << "STACK IS EMPTY";
    }
    else
    {
        cout << "Item popped = " << s->items[s->top];
        s->top--;
    }
    stacksize--;
    cout << endl;
}

// print all the elements from the stack
void printstack(st* s)
{
    printf("STACK: ");
    for (int i = 0; i < stacksize; i++)
    {
        cout << s->items[i] << "" << endl;
    }
    cout << endl;
}

int main()
{
    int ch;
    st* s = (st*)malloc(sizeof(st));

    createEmptyStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printstack(s);

    pop(s);

    cout << "\nafter popping out" << endl;
    printstack(s);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

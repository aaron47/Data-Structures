// CircularQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SIZE 5
using namespace std;

class cQueue
{
private:
    int items[SIZE], front, rear;
public:
    cQueue()
    {
        front = -1;
        rear = -1;
    }

    // check if the queue is empty
    bool isempty()
    {
        return front == -1;
    }
    
    // check if the queue is full
    bool isfull()
    {
        if (front == 0 && rear == SIZE - 1)
            return true;
        if (front == rear + 1)
            return true;
        else
            return false;
    }

    // add an element to the queue
    void enqueue(int newelement)
    {
        if (isfull())
        {
            cout << "QUEUE IS FULL" << endl;
        }
        else
        {
            if (front == -1)
            { 
                front = 0;
            }
            rear = (rear + 1) % SIZE;
            items[rear] = newelement;
            cout << endl << "Inserted element -> " << newelement << endl;
        }
    }

    // remove an element from the queue
    int dequeue()
    {
        int element;
        if (isempty())
        {
            cout << "QUEUE IS EMPTY" << endl;
        }
        else
        {
            element = items[front];
            if (front == rear) 
            {
                front = -1;
                rear = -1;
            }
            // Q has only one element,
            // so we reset the queue after deleting it. 
            else
            {
                front = (front + 1) % SIZE;
            }
            return element;
        }
    }

    // display all the elements
    void display()
    {
        int i;
        if (isempty())
        {
            cout << "QUEUE IS EMPTY" << endl;
        }
        else 
        {
            cout << endl << "Front -> " << front << endl;
            cout << endl << "Items -> ";
            for (i = front; i != rear; i = (i + 1) % SIZE)
            {
                cout << items[i] << " ";
            }
            cout << items[i];
            cout << endl << "Rear -> " << rear << endl;
        }
    }
};


int main()
{
    cQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.display();
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

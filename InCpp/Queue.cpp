// QueueExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
private:
	int ITEMS[SIZE], front, rear;
public:
	Queue()
	{
		front = -1;
		rear = -1;
	}

	bool isfull()
	{
		if (front == 0 && rear == SIZE - 1)
			return true;
		else
			return false;
	}

	bool isempty()
	{
		if (front == -1)
			return true;
		else
			return false;
	}

	void enqueue(int newelement)
	{
		if (isfull())
		{
			cout << "QUEUE IS FULL" << endl;
		}
		else
		{
			if (front == -1)
				front = 0;
			rear++;
			ITEMS[rear] = newelement;
			cout << endl << "inserted: " << newelement << endl;
		}
	}

	int dequeue()
	{
		int element;
		if (isempty())
		{
			cout << "QUEUE IS EMPTY" << endl;
		}
		else
		{
			element = ITEMS[front];
			if (front >= rear)
			{
				front = -1;
				rear = -1;
			}
			else
			{
				front++;
			}
			cout << endl << "DELETED -> " << element << endl;
			return element;
		}
	}

	void displayqueue()
	{
		if (isempty())
		{
			cout << "QUEUE IS EMPTY";
		}
		else
		{
			cout << endl;
			cout << "front -> " << front << endl;
			cout << endl << "items -> " << endl;
			for (int i = front; i <= rear; i++)
			{
				cout << ITEMS[i] << " " << endl;
			}
			cout << endl;
			cout << endl << "rear -> " << rear << endl;
		}
	}
};

int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.displayqueue();

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

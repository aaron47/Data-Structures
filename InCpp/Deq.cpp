#include <iostream>
using namespace std;
#define MAX 100

class Deq
{
	int arr[MAX], front, rear, size;
public:
	Deq(int size)
	{
		front = -1;
		rear = 0;
		this->size = size;
	}

void insertfront(int key);
void deletefront();
void insertrear(int key);
void deleterear();
bool isfull();
bool isempty();
int getfront();
int getrear();
};

bool Deq::isfull()
{
	return ((front == 0 && rear == size-1) || front == rear+1);
}

bool Deq::isempty()
{
	return front == -1;
}

void Deq::insertfront(int key)
{
	if (isfull())
	{
		cout << "OVERFLOW" << endl;
		return;
	}

	if (front == -1)
	{
		front = 0;
		rear = 0;
	}

	else if (front == 0)
	{
		front = size - 1;
	}
	else
		front--;
	arr[front] = key;
}

void Deq::insertrear(int key)
{
	if (isfull())
	{
		cout << "OVERFLOW" << endl;
		return;
	}

	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else if (rear == size-1)
		rear = 0;
	else
		rear++;
	arr[rear] = key;
}


void Deq::deletefront()
{
	if (isempty())
	{
		cout << "UNDERFLOW" << endl;
		return;
	}
	//Q HAS ONLY ONE ELEMENT
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}

	else if (front == size-1)
		front = 0;
	else
		front++;
}

void Deq::deleterear()
{
	if (isempty())
	{
		cout << "UNDERFLOW" << endl;
		return;
	}
	//Q HAS ONLY ONE ELEMENT
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (rear == 0)
		rear = size-1;
	else
		rear--;
}

int Deq::getfront()
{
	if (isempty())
	{
		cout << "UNDERFLOW" << endl;
		return -1;
	}
	return arr[front];
}

int Deq::getrear()
{
	if (isempty())
	{
		cout << "UNDERFLOW" << endl;
		return -1;
	}
	return arr[rear];
}


int main() {
	Deq q(5);
	q.insertfront(1);
	q.insertfront(2);
	q.insertrear(3);
	q.insertrear(4);

	cout << "current front el: " << q.getfront() << endl;
	cout << "current rear el:" << q.getrear() << endl;

	q.deleterear();
	q.deletefront();

	cout << "current front el: " << q.getfront() << endl;
	cout << "current rear el:" << q.getrear() << endl;

	return 0;
}

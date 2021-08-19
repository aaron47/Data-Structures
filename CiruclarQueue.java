public class CiruclarQueue {
	int SIZE = 5;
	int ITEMS[] = new int[SIZE];
	int front, rear;
	
	// Initialize queue
	public CiruclarQueue()
	{
		front = -1;
		rear = -1;
	}
	
	// add elements to the queue
	public void enqueue(int newelement)
	{
		if (isFull())
			System.out.println("QUEUE IS FULL");
		else
		{
			if (front == -1)
				front = 0;
			
			rear = (rear+1) % SIZE;
			ITEMS[rear] = newelement;
			
			System.out.println("new element added -> " + newelement);
		}
	}
	
	// remove an element
	public int dequeue()
	{
		int element = 0;
		if (isEmpty())
			System.out.println("QUEUE IS EMPTY");
		else
		{
			element = ITEMS[front];
			if (front == rear)
			{
				front = -1;
				rear = -1;
			}
			/* Q has only one element, so we reset the queue after deleting it. */
			else
			{
				front = (front+1) % SIZE;
			}
		}
		return (element);
	}
	
	// display all the elements
	public void display()
	{
		int i;
		if (isEmpty()) 
		{
			System.out.println("QUEUE IS EMPTY");
		}
		else
		{
			System.out.println("Front -> " + front);
			System.out.println("Items -> ");
			for (i = front; i != rear; i = (i+1)%SIZE)
			{
				System.out.print(ITEMS[i] + " ");
			}
			System.out.println(ITEMS[i]);
			System.out.println("Rear -> " + rear);
		}
	}
	
	// check if queue is full
	public boolean isFull()
	{
		if (front == 0 && rear == SIZE-1)
			return true;
		if (front == rear+1)
			return true;
		else
			return false;
	}
	
	// check if the queue is empty
	public boolean isEmpty()
	{
		if (front == -1)
			return true;
		else
			return false;
	}
}
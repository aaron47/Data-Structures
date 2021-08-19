public class Queue {
	int SIZE = 5;
	int items[] = new int[SIZE];
	int front, rear;
	
	// initializing the queue
	public Queue()
	{
		front = -1;
		rear = -1;
	}
	
	// to check if the queue is full
	public boolean isFull()
	{
		if (front == 0 && rear == SIZE - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	// to check if the queue is empty
	public boolean isEmpty()
	{
		if (front == -1)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	// inserting a new element to the queue
	public void enQueue(int newelement)
	{
		if (isFull())
		{
			System.out.println("QUEUE IS FULL");
		}
		else
		{
			if (front == -1)
			{
				front = 0;
			}
			rear++;
			items[rear] = newelement;
			System.out.println("inserted element -> " + newelement);
		}
	}
	
	public int deQueue()
	{
		int element;
		if (isEmpty())
		{
			System.out.println("QUEUE IS EMPTY");
			return (-1);
		}
		else
		{
			element = items[front];
			if (front >= rear)
			{
				front = -1;
				rear = -1;
			}
			else 
			{
				front++;
			}
			System.out.println("deleted item -> " + element);
			return (element);
		}
	}
	
	public void display()
	{
		int i;
		if (isEmpty())
		{
			System.out.println("EMPTY QUEUE");
		}
		else
		{
			System.out.println("\nFront index-> " + front);
			System.out.println("Items -> ");
			for (i = front; i  <= rear; i++)
			{
				System.out.println(items[i] + " ");
			}
			System.out.println("\nRear index-> " + (rear+1));
		}
	}
}
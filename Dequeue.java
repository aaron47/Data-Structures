public class Dequeue 
{
	static final private int MAX = 100;
	int arr[], front, rear, size;
	
	public Dequeue(int size)
	{
		front = -1;
		rear = 0;
		arr = new int[MAX];
		this.size= size;
	}
	
	boolean isempty() 
	{
		return front == -1;
	}
	
	boolean isfull()
	{
		return (front == 0 && rear == size-1 || front == rear+1);
	}
	
	void insertfront(int key)
	{
		if (isfull())
		{
			System.out.println("Overflow");
			return;
		}
		
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (front == 0)
		{
			front = size-1;
		}
		else
			front--;
		
		arr[front] = key;
	}
	
	void insertrear(int key)
	{
		if (isfull())
		{
			System.out.println("Overflow");
			return;
		}
		
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (rear == size-1)
		{
			rear = 0;
		}
		else
			rear++;
		arr[rear] = key;
	}
	
	void deleterear()
	{
		if (isempty())
		{
			System.out.println("Underflow");
			return;
		}
		
		// Q HAS ONE ELEMENT
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		
		else if (rear == 0)
		{
			rear = size-1;
		}
		else
			rear--;
	}
	
	void deletefront()
	{
		if (isempty())
		{
			System.out.println("Underflow");
			return;
		}
		
		// Q HAS ONE ELEMENT
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		
		else if (front == size-1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
	}
	
	int getfront()
	{
		return arr[front];
	}
	int getrear() 
	{
		return arr[rear];
	}
}
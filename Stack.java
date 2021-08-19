public class Stack {
	// initialize the necessary variables
	private int arr[];
	private int top;
	private int capacity;
	
	// create an empty stack
	public Stack(int size)
	{
		arr = new int[size];
		capacity = size;
		top = -1;
	}
	// add an element to the stack
	public void push(int x)
	{
		if (isFull())
		{
			System.out.println("STACK IS FULL");
			System.exit(1);
		}
		top++;
		arr[top] = x;	
	}
	
	// remove an element from the stack
	public int pop()
	{
		if (isEmpty())
		{
			System.out.println("STACK IS EMPTY");
			System.exit(1);
		}
		top--;
		return arr[top];
	}
	
	public void printStack()
	{
		for (int i = 0; i <= top; i++)
		{
			System.out.println(arr[i]);
		}
	}
	// to check if the stack is empty
	public boolean isEmpty()
	{
		return top == -1;
	}
	
	// to check if the stack is full
	public boolean isFull()
	{
		return top == capacity-1;
	}
	
	public void Peek()
	{
		System.out.println("\n");
		System.out.println(arr[top]);
	}
}
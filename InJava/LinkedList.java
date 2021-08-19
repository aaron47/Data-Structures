public class LinkedList
{
	Node head;
	
	static class Node
	{
		int data;
		Node next;
		
		
		Node(int d)
		{
			this.data = d;
			this.next = null;
		}
	}
	
	public void insertAtBeginning(int x)
	{
	    /* 1 & 2: Allocate the Node &
        Put in the data*/
       Node new_node = new Node(x);
       /* 3. Make next of new Node as head */
       new_node.next = head;
       /* 4. Move the head to point to new Node */
       head = new_node;
	}
	
	public void insertAtSpecific(Node prev_node, int x)
	{
		// ALLOCATE THE NODE AND PUT IN THE DATA
		Node new_node = new Node(x);
		/* 1. Check if the given Node is null */
		if (prev_node == null)
		{
			System.out.println("The given previous node cannot be null");
			return;
		}
		
		/* 4. Make next of new Node as next of prev_node */
		new_node.next = prev_node.next;
		/* 5. make next of prev_node as new_node */
		prev_node.next = new_node;
		
	}
	
	public void insertAtEnd(int x)
	{
	    /* 1. Allocate the Node &
	       2. Put in the data
	       3. Set next as null */
		Node new_node = new Node(x);
		
	    /* 4. If the Linked List is empty, then make the
        new node as head */
		if (head == null)
		{
			head = new_node;
			return;
		}
		
		 /* 4. This new node is going to be the last node, so
        make next of it as null */
		new_node.next = null;
		
		/* 5. Else traverse till the last node */
		Node last = head;
		while (last.next != null)
			last = last.next;
		
		/* 6. Change the next of last node to be the new node */
		last.next = new_node;
	}
	
	    /* Given a key, deletes the first
	    occurrence of key in
	  * linked list */
	 public void deleteNode(int key)
	 {
	     // Store head node
	     Node temp = head, prev = null;
	
	     // If head node itself holds the key to be deleted
	     if (temp != null && temp.data == key) {
	         head = temp.next; // Changed head
	         return;
	     }
	
	     // Search for the key to be deleted, keep track of
	     // the previous node as we need to change temp.next
	     while (temp != null && temp.data != key) {
	         prev = temp;
	         temp = temp.next;
	     }
	
	     // If key was not present in linked list
	     if (temp == null)
	         return;
	
	     // Unlink the node from linked list
	     prev.next = temp.next;
	 }
	
    /* Given a reference (pointer to pointer) to the head of a list
    and a position, deletes the node at the given position */
	 public void deleteNodeatPos(int position)
	 {
	     // If linked list is empty
	     if (head == null)
	         return;
	
	     // Store head node
	     Node temp = head;
	
	     // If head needs to be removed
	     if (position == 0)
	     {
	         head = temp.next;   // Change head
	         return;
	     }
	
	     // Find previous node of the node to be deleted
	     for (int i=0; temp!=null && i<position-1; i++)
	         temp = temp.next;
	
	     // If position is more than number of nodes
	     if (temp == null || temp.next == null)
	         return;
	
	     // Node temp->next is the node to be deleted
	     // Store pointer to the next of node to be deleted
	     Node next = temp.next.next;
	
	     temp.next = next;  // Unlink the deleted node from list
	}
	// function that deletes the entire list
	public void deleteList()
	{
		head = null;
	}
	 
	public void printList()
	{
		Node n = head;
		while (n != null)
		{
			System.out.print(n.data + "--->");
			n = n.next;
		}
	}
}
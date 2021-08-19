// A simple C++ program for traversal of a linked list
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void insertatspecific(Node* prev_node, int x)
{
	// allocate node and put in the data
	Node* new_node = new Node();
	new_node->data = x;

	// check if the previous node is NULL and throw an error
	if (prev_node == NULL)
	{
		cout << "the previous node cannot be NULL" << endl;
		return;
	}

	// make the next of the new node the prev_node's next
	new_node->next = prev_node->next;
	// move the next of prev_node to new_node
	prev_node->next = new_node;
}


// function to add a node in the beginning
void insertatbeginning(Node** head_ref, int x)
{
    /* 1. allocate node */
    Node* new_node = new Node();

    /* 2. put in the data */
    new_node->data = x;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}


/* Given a reference (pointer to pointer)
to the head of a list and an int,
inserts a new node on the front of the list. */
void insertatend(Node** head_ref, int x)
{
	// allocate node and put in the data
	Node* new_node = new Node();
	new_node->data = x;

	// if the head is null we set the head as the new node
	if ((*head_ref) == NULL)
	{
		(*head_ref) = new_node;
	}
	// set the new_node's next as null to set it as the last element
	new_node->next = NULL;

	// use last as the head reference
	Node* last = (*head_ref);

	//iterate until the last element
	while (last->next != NULL)
	{
		last = last->next;
	}

	// set the last element as the new node
	last->next = new_node;
}

/* Given a key, deletes the first
   occurrence of key in
 * linked list */
void deletenode(Node** head_ref, int key)
{
	// store head node + a prev node thats initial value is null
	Node* temp = (*head_ref);
	Node* prev = NULL;

	// check if the head hold the key to be deleted
	if (temp != NULL && temp->data == key)
	{
		(*head_ref) = temp->next; // change old head
		delete temp; // free memory from the old head
		return;
	}
	else
	{
		// keep iterating until we find a node to match the key to be deleted
		while (temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}
		// if there is no match
		if (temp == NULL)
			return;
		// unlink the node from the list
		prev->next = temp->next;
		// free memory
		delete temp;
	}
}



// Driver code
int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    insertatend(&head, 6);

    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    insertatbeginning(&head, 7);

    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    insertatbeginning(&head, 1);

    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    insertatend(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertatspecific(head->next, 8);

    cout<<"List before removal of 8: " << endl;
    printList(head);

    deletenode(&head, 8);
    cout << "after removal of 8" << endl;
    printList(head);

    return 0;
}

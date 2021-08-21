// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <iostream>
#include <cassert>
using namespace std;
typedef struct Node nd;

// A linked list node
struct Node
{
	int data;
	nd* next;
};

/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void push(nd** head_ref, int new_data)
{
	/* 1. allocate node */
	nd* new_node = (nd*)malloc(sizeof(nd));

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(nd* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		cout << "the given previous node cannot be NULL" << endl;
		return;
	}

	/* 2. allocate new node */
	nd* new_node = (nd*)malloc(sizeof(nd));

	/* 3. put in the data  */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(nd** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (nd*)malloc(sizeof(nd));

	struct Node* last = *head_ref;  /* used in step 5*/

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so make next of
		  it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}

// given a key, deleted the node that has the data that matches it
void deletenode(nd** head_ref, int key)
{
	// assign head
	nd* temp = (*head_ref);
	nd* prev = NULL;
	// check if the head itself has the key to match
	if (temp != NULL && temp->data == key)
	{
		(*head_ref) = temp->next;
		delete temp;
		return;
	}
	// keep searching for a match
	else
	{
		while (temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
			return;

		// unlink the node
		prev->next = temp->next;
		// free memory
		delete temp;
		return;
	}
}

// given a position of a node, delete the node at that position
void deletenodeatpos(nd** head_ref, int pos)
{
	// if list is empty
	if ((*head_ref) == NULL)
		return;

	// assign the head
	nd* temp = (*head_ref);
	// cant remove the head;
	if (pos == 0)
		return;
	// keep iterating until the element before the position to be deleted
	for (int i = 0; temp != NULL && i < pos - 1; i++)
		temp = temp->next;

	if (temp == NULL)
		return;
	nd* next = temp->next->next;
	temp->next = next;
	return;
}


// function to delete the whole list
void deletelist(nd** head_ref)
{
	/* deref head_ref to get the real head */
	nd* curr = (*head_ref);
	nd* next = NULL;

	while (curr != NULL)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
	/* deref head_ref to affect the real head back
			in the caller. */
	(*head_ref) = NULL;
}

// check whether a node exists in the list
bool searchlist(nd* head, int key)
{
	// initialize head
	nd* curr = head;
	// check if the head itself is the key
	if (curr->data == key)
		return true;
	if (head == NULL)
		cout << "empty list" << endl;
	// keep iterating until the key is found
	while (curr != NULL)
	{
		if (curr->data == key)
			return true;
		curr = curr->next;
	}
	return false;
}

// sort the linkedlist
void sortlist(nd** head_ref)
{
	// intialize the head
	nd* curr = (*head_ref);
	nd* next = NULL;
	int temp;

	while (curr != NULL)
	{
		next = curr->next;
		while (next != NULL)
		{
			if (curr->data > next->data)
			{
				temp = curr->data;
				curr->data = next->data;
				next->data = temp;
			}
			next = next->next;
		}
		curr = curr->next;
	}
}


// find the length of a list
int getlen(nd* head)
{
	nd* curr = head;
	int count = 0;

	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return count;
}
// given a position, return the node in that position
int getNthNode(nd** head_ref, int pos) 
{
	if ((*head_ref) == NULL)
		return 0;

	nd* temp = (*head_ref);
	int count = 0;
	while (temp != NULL)
	{
		if (count == pos)
			return temp->data;
		++count;
		temp = temp->next;
	}

	assert(false);
	return 0;
}


// This function prints contents of linked list starting from head
void printList(nd* node)
{
	while (node != NULL)
	{
		printf("%d-->", node->data);
		node = node->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	nd* head = NULL;

	// Insert 6.  So linked list becomes 6->NULL
	append(&head, 6);

	// Insert 7 at the beginning. So linked list becomes 7->6->NULL
	push(&head, 7);

	// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
	push(&head, 1);

	// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
	append(&head, 4);

	// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
	insertAfter(head->next, 8);

	cout << "Linked list before deletion of 8: " << endl;
	printList(head);

	cout << "\nLinked list after deletion of 8:" << endl;
	deletenode(&head, 8);
	printList(head);

	// list is 1-->6-->4
	cout << "\nLinked list after removal of data at position 1" << endl;
	deletenodeatpos(&head, 1);
	printList(head);

	searchlist(head, 6) ? cout << "\nYES" << endl : cout << "\nNO" << endl;
	cout << "length of the list is : " << getlen(head);
	// after sorting list is : 1-->4-->6
	sortlist(&head);
	cout << "\n";
	printList(head);
	cout << "\n" << getNthNode(&head, 2) << endl;
	return 0;
}

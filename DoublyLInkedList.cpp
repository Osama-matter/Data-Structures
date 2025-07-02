#include <iostream>

//#include "ClsLinkedList.h"
using namespace std; 
class Node 
{
public :

	int value; 
	Node* Next; 
	Node* prev; 
};
class LinkedList
{
public:

	Node* Head;

	LinkedList()
	{
		Head = NULL;
	}
	bool IsEmpty()
	{
		return (Head == NULL);
	}
	void StertInser()
	{
		
		Node* newNode1 = NULL; 
		Node* newNode2 = NULL;
		Node* newNode3 = NULL;

		newNode1 = new Node();
		newNode2 = new Node();
		newNode3= new Node();

		newNode1->value = 1; 
		newNode2->value = 2; 
		newNode3->value = 3; 

		newNode1->Next = newNode2; 
		newNode1->prev = NULL; 

		newNode2->Next = newNode3;
		newNode2->prev = newNode1; 

		newNode3->Next = NULL; 
		newNode3->prev = newNode2; 

		Head = newNode1; 
	}

	void InsertAtBeginnin(int value )
	{
		Node* New_node = new Node(); 
		New_node->value = value; 
		New_node->Next = Head; 
		New_node->prev = NULL; 
		if (Head != NULL)
		{
			Head->prev = New_node; 
		}
		Head = New_node; 
	}

	void display()
	{
		Node* Temp = Head; 
		while (Temp != NULL)
		{
			cout << Temp->value << "  "; 
			Temp = Temp->Next; 
 		}
	}

	Node* Find(int value)
	{
		Node* temp = Head; 
		while (temp != NULL)
		{
			if (temp->value == value)
				return temp; 
			temp = temp->Next; 
		}
		return NULL; 
	}
	void InsertAfter(int Prev , int value)
	{
		Node* Current = Find(Prev);  // save Current head After Value do you wont to add   ; 
		Node* New_Node = new Node();  // New Node  ; 

		New_Node->value = value;   // Save Node Value  ; 
		New_Node->Next = Current->Next;  // point new node to After new node Using adress Save in Current node  ; 
		New_Node->prev = Current;   // make New node . prev  point to ast node it saved in current node pointer  ; 

		if (Current->Next != NULL)    // Cheak if After Node is Last node or Not ; 
			New_Node->Next->prev = Current;   // if not end Save Date of After node in a newnode  ; ;
		Current->Next = New_Node;   // make Curent node . next point to newNode  ; 
	}
	void InsertAtEnd(int value)
	{
		Node* Current = Head;  // Creat Node take Head of list to Save postion of list to be abe to acess  it  After this operation ; 
		Node* New_Node = new Node();  // New Node  ; 

		New_Node->value = value;   // Save New node Value  ; 
		New_Node->Next = NULL;   // Becouse thisn it a end node must next == Null ; 
		if (Current == NULL) // if Node It Frint in list ; 
		{
			New_Node->prev = NULL;   // If true  is frist  prev  == NUll  ; 
			New_Node = Current;  // save head in new node  ; 
		}
		else
		{                                   // Not frint NOde   ; 
			while (Current->Next != NULL) // To find eend  node  (mark Current.Next  == NULL ; 
			{
				Current = Current->Next;   // Move one step if it not end node  ; 
			}
			New_Node->prev = Current;    // make prev new node  == Current  last node  ; 
			Current->Next = New_Node;   // Last node  . next point to New Node  ; 

		}
	}

	void Delete(int value)
	{
		Node* Delete_Node = Find(value);     // Save poit do yuvwont to delete  ; 
		if (Head == NULL || Delete_Node == NULL )   // cheack if not empty . 
		{
			cout << "List Empty Not Found Node  ! \n";
			return; 
		}
			
		
		if (Head == Delete_Node)   // if point is start ponint  ; 
		{
			Head = Delete_Node->Next;   // move one step ; 
			if (Head != NULL)   
				Head->prev = NULL;     // make prev == NULL ;  

		
		}
		
		else
		{
			if (Delete_Node->Next != NULL)   // cheak if point not equal null ; 
			{
				Delete_Node->Next->prev = Delete_Node->prev;  //make prev in next node == prev save in delete node  ;  
			}

			if (Delete_Node->prev != NULL)
			{
				Delete_Node->prev->Next = Delete_Node->Next;  // make next  in last point == next saned in Delete node  ; 
			}
		}
		delete Delete_Node;   // delete node to memory  ; 

	}

	void DeleteFrist()
	{
		Node* Delete_Node = Head;    // Greate New Node  ; 
		if (IsEmpty())
			cout << "List Is Empty !\n"; 
		else
		{
			Head = Head->Next;   // Move To next node  ; 
			if(Head != NULL)  // Check if ot not == NULL ; 
			{
				Head->prev = NULL;   // Make Prev  of Scound Node  == Null To be a frist node  ; 
			}
			delete Delete_Node;  // Delete Node from memory  ; 
		}
	}
	void DeleteLast()
	{
		if (IsEmpty())
			cout << "List Is Empty !\n";
		
		else
		{
			if (Head->Next == NULL)  // Cheak if it countine one element  
			{
				delete Head;
				Head = NULL;
				return;
			}

			Node* CurrentNode = Head;         
			while (CurrentNode->Next->Next != NULL) // move to node before  last node   
			{
				CurrentNode = CurrentNode->Next;
			}
			Node* delete_Node = CurrentNode->Next;  //   declerate node point Node do you want to delete it last node  ;  
			CurrentNode->Next = NULL; // make next == NUll;
			delete delete_Node;    // Delete node  
		}

	}
};
int main()
{
	LinkedList lst;
	lst.InsertAtBeginnin(10); 
	lst.InsertAtBeginnin(20); 
	if (lst.Find(1) != NULL)
		cout << "Found \n ";
	else
		cout << "Not Found \n"; 
	lst.InsertAfter(10, 88); 
	lst.InsertAtEnd(40); 
	lst.display();
	cout << "\n------------------------------\n"; 
	lst.Delete(10); 
	lst.DeleteFrist(); 
	lst.DeleteLast(); 
	lst.display(); 
} 

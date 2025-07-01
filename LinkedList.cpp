#include <iostream>
using namespace std; 
class Node 
{
public :

	int value; 
	Node* Next; 
};
class LinkedList 
{
public :

	Node* Head;

	LinkedList()
	{
		Head = NULL; 
	}
	bool IsEmpty()
	{
		return (Head == NULL); 
	}
	void InsertFrist(int value)
	{
		Node* new_Node = new Node(); 
		new_Node->value = value; 
		if (IsEmpty())
		{
			new_Node->Next = NULL; 
		}
		else
		{
			new_Node->Next = Head; 
		}
		Head = new_Node; 

	}

	void display()
	{
		Node* temp = Head; 
		while (temp != NULL)
		{
			cout << temp->value << "  "; 
			temp = temp->Next; 
		}

	}

	int  Counter ()
	{
		int Count = 0; 
		Node* temp = Head;
		while (temp != NULL)
		{
			Count++; 
			temp = temp->Next;
		}
		cout << endl; 
		return Count; 
	}

	bool  Fond(int value)
	{
		bool find = false; 
		Node* temp = Head;
		while (temp != NULL )
		{
			if (temp->value == value)
				return true; 
			temp = temp->Next;
		}
		return find; 
	}
	void insertBefor(int item, int value)
	{
		Node* New_node = new Node(); 
		Node* temp = Head; 
		if (Fond(item))
		{
			if (Head->value == item)
			{
				New_node->Next = Head;
				Head = New_node;
				return;
			}
			
			while (temp->Next != NULL && temp->Next->value != item)
			{
				temp = temp->Next; 
			}
			New_node->value = value;
			New_node->Next = temp->Next;
		 
			temp->Next = New_node; 
		}
		else
		{
			cout << "Value  Not found !\n"; 
		}
	}

	void Append(int value)
	{
		if (IsEmpty())
			InsertFrist(value);
		else
			return;
		Node* temp = Head;
		Node* new_node = new Node();
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}

		new_node->value = value;
		temp->Next = new_node;
		new_node->Next = NULL;
	}

	void Delete(int value)
	{
		if (IsEmpty())
		{
			cout << "Not found Any element to delete !\n";
			return;
		}

		Node* delpot = Head; 
		if (Head->value == value)
		{
			Head = Head->Next; 
			delete delpot; 
		}
		else
		{
			Node* Prve = NULL; 
			while (delpot->value != value)
			{
				Prve = delpot; 
				delpot = delpot->Next;
			}
			Prve->Next = delpot->Next; 
			delete delpot; 

		}
	}

};

int main()
{
	LinkedList lst;
	if (lst.IsEmpty()? cout << "Not  Found \n" : cout << "Found  \n");
	cout << "Count  = " <<lst.Counter() <<endl ;
	int value = 0; 
	for (int i = 1; i <= 3; i++)
	{
		cout << "\nEnter Value Do you want to insert in list  \n";
		cin >> value;
		lst.InsertFrist(value);
		lst.display(); 
	}
	cout << "\nEnter Value Do you want to Find in list  \n";
	cin >> value;
	if (lst.Fond(value))
	{
		cout << "Found \n"; 

	}
	else
	{
		cout << "Not Found  \n"; 
	}
	cout << "\nCount  = " << lst.Counter() <<endl ;

	int NewValue; 
 
	lst.display();
	cout << "\n-----------------------------------------------\n"; 
	//cout << "\nEnter Value Do you want to insert before  \n";
	//cin >> value;
	cout << "\nEnter Value Do you want to Delete in list  \n";
	cin >> NewValue;
	//lst.insertBefor(value , NewValue ); 
	lst.Delete(NewValue); 
	lst.display(); 
} 

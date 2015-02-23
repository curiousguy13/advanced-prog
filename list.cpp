//make a list data struct using class with all the methods of list(insert,delete,make_null,display) 
//make a subclass ordered_list conatining method sorted_display
#include <iostream>
#include <stdio.h>

using namespace std;
class node
{
public:
	int value;
	node *next;
};

node* createNode(int val)
{
	node* n=new node();
	n->value=val;
	n->next=NULL;
	return n; 
}

class LinkedList
{	

public:
	node* head;

	LinkedList()
	{
		head=NULL;
	}

	void insert(int val)
	{
		if(head==NULL)
		{
			head=createNode(val);
		}
		else
		{
			node* temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=createNode(val);
		}
	}
	void del(int val)
	{
		
		if(head==NULL)
		{
			cout<<"The Linked List is empty!!!"<<endl;
		}
		else
		{
			node* temp=head;
			node* prev=head;
			int found=0;
			while(temp!=NULL)
			{
				if(temp->value==val)
				{
					found=1;
					if(temp==head)
					{
						node* t=temp;
						head=temp->next;
						delete(t);
						break;
					}
					else
					{
						prev->next=temp->next;
						delete(temp);
					}
				}
				prev=temp;
				temp=temp->next;
			}
			if(found==0)
			{
				cout<<"Element not in the list"<<endl;
			}
		}
	}

	void display()
	{
		cout<<"The current linked list is:";
		node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->value<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

class orderedList:public LinkedList
{
public:
	void sorted_insert(int val)
	{
		if(head==NULL)
		{
			head=createNode(val);
		}
		else
		{
			node* temp=head;
			node* prev=head;
			while(temp!=NULL)
			{
				if(temp->value>val)
					break;
				prev=temp;
				temp=temp->next;
			}
			if(temp==head)
			{
				node* t=createNode(val);
				t->next=temp;
				head=t;	
			}
			else
			{
				node* t=createNode(val);
				t->next=temp;
				prev->next=t;
			}
		}
	}
};
int main()
{
	orderedList L;
	int n=0,k;
	while(n!=-1)
	{
		cout<<"Enter the element to insert(Enter -1 to stop):";
		cin>>n;
		if(n!=-1)
		{
			L.sorted_insert(n);
		}
	}
	n=0;
	L.display();
	while(n!=-1)
	{
		cout<<"Enter the element to delete(Enter -1 to stop):";
		cin>>n;
		if(n==-1)
			break;
		if(n!=-1)
		{
			L.del(n);
		}
		L.display();
	}
	L.display();
	return 0;
}
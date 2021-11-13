#include <iostream>
#include <bits/stdc++.h>
//#include <cinttypes>
using namespace std;


class Node
{
	public:
    int data;
    Node* npx; 
    Node *Xor(Node *,Node *);
};

Node *head=NULL;

Node* Node::Xor(Node* x, Node* y)
{
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(x)
        ^ reinterpret_cast<uintptr_t>(y));
}

void insert(int data)
{
	Node *temp;
	Node *ptr;
	Node *t;
	Node *new_node = new Node();
	new_node->data=data;
	//new_node->next=NULL;
	if(head==NULL)
	{
		new_node->npx=NULL;
		head=new_node;
	}
	else
	{
	    if(head->npx==NULL)
	    {
	        head->npx=new_node;
	        new_node->npx=head;
	    }
	    else{
		temp=head;
		ptr=temp->npx;
		while(ptr->npx!=temp)
		{
			t=ptr;
			//ptr=ptr->((ptr->npx)^(temp->npx));
			ptr=ptr->Xor(ptr->npx,temp);
			temp=t;
		}
		ptr->npx=ptr->Xor(ptr->npx,new_node);
		new_node->npx=ptr;
		
	}
	}
}

void display()
{
	Node *temp;
	Node *ptr;
	Node *t;
	temp=head;
	if(head==NULL)
	cout<<"Nothing to print"<<endl;
	else
	{
		temp=head;
		ptr=temp->npx;
		while(ptr!=NULL)
		{
			cout<<temp->data<<" ";
			t=ptr;
			ptr=ptr->Xor(ptr->npx,temp);
			temp=t;
		}
	    cout<<temp->data<<" ";	
	}
}


int main()
{
	int n;
	cout<<"Enter the elements. Enter -1 to stop"<<endl;
	while(1)
	{
		cin>>n;
		if(n==-1)
		break;
		else
		insert(n);
	}
	cout<<"Elements of the list:"<<endl;
	display();
}

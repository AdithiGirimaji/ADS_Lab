//changing parents
//changing child
//delete
//calling avl trees

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
} node;

node *pa=NULL;
node *root;

int height(node *n)
{
	if(n==NULL)
	return -1;
	else
	{
		int l=height(n->left);
		int r=height(n->right);
		if (l > r)
            return (l+1);
        else
            return (r+1);
	}
}

void left_rotate(node *e)
{
	node *x=e->right;
	node *t=x->left;
	x->left=e;
	e->parent=x;
	e->right=t;
	t->parent=e;
}

void right_rotate(node *e)
{
	node *x=e->left;
	node *t=x->right;
	x->right=e;
	e->parent=x;
	e->left=t;
	t->parent=e;
}

//leaf-->newly inserted node
void make_avlTree(node *leaf)
{
	int p_b,gp_b;
	node *flag,*flag1,*e;
	if(leaf->parent->parent!=NULL)
	{
		p_b=height(leaf->parent->left)-height(leaf->parent->right)+1;
		gp_b=height(leaf->parent->parent->left)-height(leaf->parent->parent->right)+1;
		if(gp_b!=0 || gp_b!=1 || gp_b!=-1)
		{
			if(p_b>=0 && gp_b>0)
			{
				e=leaf->parent->parent;
				if(leaf->parent->parent->parent==NULL){
				flag=leaf->parent;
			    right_rotate(leaf->parent->parent);
			    root=flag;
			    root->parent=NULL;
		        }
		        else
		        {
					flag=leaf->parent;
					flag1=leaf->parent->parent->parent;
					right_rotate(leaf->parent->parent);
					flag->parent=flag1;
					if(flag1->left==e)
					flag1->left=flag;
					else
					flag1->right=flag;
				}
		    }
			else if(p_b<=0 && gp_b<0)
			{
				e=leaf->parent->parent;
				if(leaf->parent-parent->parent==NULL){
					flag=leaf->parent;
			        left_rotate(leaf->parent->parent);
			        root=flag;
			        root->parent=NULL;
		            }
			    else
			    {
					flag=leaf->parent;
					flag1=leaf->parent-parent->parent;
					left_rotate(leaf->parent->parent);
					flag->parent=flag1;
					if(flag1->left==e)
					flag1->left=flag;
					else
					flag1->right=flag;
				}
			    
			} 
			    
			else if(p_b<0 && gp_b>0)
			{
				flag1=leaf->parent->parent;
				flag=leaf->parent;
				left_rotate(leaf->parent);
				leaf->parent=flag1;
				if(flag1->left==flag)
				flag1->left=leaf;
				else
				flag1->right=leaf;
				//right_rotate(leaf->parent->parent);
				e=leaf->parent->parent;
				if(leaf->parent-parent->parent==NULL){
				flag=leaf->parent;
			    right_rotate(leaf->parent->parent);
			    root=flag;
			    root->parent=NULL;
		        }
		        else
		        {
					flag=leaf->parent;
					flag1=leaf->parent-parent->parent;
					right_rotate(leaf->parent->parent);
					flag->parent=flag1;
					if(flag1->left==e)
					flag1->left=flag;
					else
					flag1->right=flag;
				}
			}
			else if(p_b>0 && gp_b<0)
			{
				flag1=leaf->parent->parent;
				flag=leaf->parent;
				right_rotate(leaf->parent);
				leaf->parent=flag1;
				if(flag1->left==flag)
				flag1->left=leaf;
				else
				flag1->right=leaf;
				//left_rotate(leaf->parent->parent);
				e=leaf->parent->parent;
				if(leaf->parent-parent->parent==NULL){
					flag=leaf->parent;
			        left_rotate(leaf->parent->parent);
			        root=flag;
			        root->parent=NULL;
		            }
			    else
			    {
					flag=leaf->parent;
					flag1=leaf->parent-parent->parent;
					left_rotate(leaf->parent->parent);
					flag->parent=flag1;
					if(flag1->left==e)
					flag1->left=flag;
					else
					flag1->right=flag;
				}
			}
		}
		else
		return;
    }
}

 
node *create()
{
	node *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(node*)malloc(sizeof(node));
	p->data=x;
	p->parent=pa;
	
	//check for avl_tree
	//....
	
	pa=p;
	printf("Enter left child of %d:\n",x);
	p->left=create();
 
    //pa=pa->parent;
    pa=p;
	printf("Enter right child of %d:\n",x);
	p->right=create();
	
	return p;
}
 
void preorder(node *t)		//address of root node is passed in t
{
	if(t!=NULL)
	{
		printf("\n%d",t->data);		//visit the root
		preorder(t->left);		//preorder traversal on left subtree
		preorder(t->right);		//preorder traversal om right subtree
	}
}
 
int main()
{	
	root=create();
	printf("\nThe preorder traversal of tree is:\n");
	preorder(root);
	
	return 0;
}


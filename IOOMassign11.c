#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node_tag
{
	char s_name[20];
	int total_marks;
	struct node_tag* left;
	struct node_tag* right;
}tree_node;
 
tree_node* insert_name(tree_node *p,char *name,int marks)
{
	tree_node *q,*r,*node;
	q=p;
	node=(tree_node*)malloc(sizeof(tree_node));
	node->total_marks=marks;
	strcpy(node->s_name,name);
	if(q->right==NULL)
	{
		q->right=node;
	}
	else
	{
		q=q->right;
	while(q->left!=NULL)
	{
		q=q->left;
	}
	q->left=node;
	}
	return p;
}
tree_node* insert(tree_node *root,char *name , int marks)
{
	tree_node *p;
	p=root;
	tree_node *node;
	node=(tree_node*)malloc(sizeof(tree_node));
	strcpy(node->s_name,name);
	node->total_marks=marks;
	node->left=node->right=NULL;
	int done=0;
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		while(!done)
		{
			if(p->total_marks>node->total_marks)
			{
				if(p->left==NULL)
				{
					p->left=node;
					done=1;
				}
				else{
					p=p->left;
				}
			}
			else if(node->total_marks>p->total_marks)
			{
				if(p->right==NULL)
				{
					p->right=node;
					done=1;
				}
				else
				{
					p=p->right;
				}
			}
			else
			{
			
					if(p->right==NULL)
					{
						p->right=node;
					}
					else
					{
						p=p->right;
						while(p->left!=NULL)
						{
								p=p->left;
						}
						if(strcmp(p->s_name,name)!=0)
							p->left=node;
					}
					
				
				//p=insert_name(p,name,marks);
				done=1;
		}
		}
	}
	return root;	
}

void delete_node(tree_node **pptr)
{
	tree_node *p,*q,*r;
	if((*pptr)!=NULL)
	{
		if((*pptr)->right==NULL)
		{
			p=*pptr;
			*pptr=(*pptr)->left;
			free(p);
		}
		else if((*pptr)->right!=NULL&&(*pptr)->left==NULL)
		{
			p=*pptr;
			*pptr=(*pptr)->right;
			free(p);
		}
		else
		{
			for(q=(*pptr)->left;q->right!=NULL;)
			{
				p=q;
				q=q->right;
			}
			p->right=q->left;
			q->left=(*pptr)->left;
			q->right=(*pptr)->right;
			r=*pptr;
			*pptr=q;
			free(r);	
		}
	}
}

tree_node* delete_fun(tree_node *root, int key,char *name)
{
	tree_node *p,*prev;
	prev=NULL;
	p=root;
	while((p!=NULL)&&((p->total_marks!=key)&&(strcmp(p->s_name,name)!=0)))
	{
		if(p->total_marks>key)
		{
			prev=p;
			p=p->left;	
		}
		else if (p->total_marks<key)
		{
			prev=p;
			p=p->right;
		}	
		else if(p->total_marks==key)
		{
			prev=p;
			p=p->right;
			while((p->left!=NULL)&&(strcmp(p->s_name,name)==0))
			{
				prev=p;
				p=p->left;
			}
		}
	}
	if(p==root)
	{
		delete_node(&root);
	}
	else if(p!=NULL)
	{
		if((p->total_marks==prev->left->total_marks)&&(strcmp(p->s_name,prev->left->s_name)==0))
		{
			delete_node(&(prev->left));
		}
		else if((p->total_marks==prev->right->total_marks)&&(strcmp(p->s_name,prev->right->s_name)==0))
		{
			delete_node(&(prev->right));
		}
	}
	return root;	
}


void inorder(tree_node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("Name:%s  Marks:%d\n",root->s_name,root->total_marks);
		inorder(root->right);
	}
}






int main()
{
	tree_node *head=NULL,*p=NULL;
	int ans=1;
	while(ans==1)
	{
		int x,a;
		char name[20];
		printf("ENTER THE OPERATION YOU WANT TO PERFORM\n1.INSERT\n2.DELETE\n3.PRINT TREE\n");
		scanf("%d",&x);
		switch(x)	
		{
			case 1:
				{
					printf("Enter the element to be inserted:\t");
					scanf("%s %d",&name,&a);
					head=insert(head,name,a);
					printf("\nCurrent tree is:-\n",a);
					inorder(head);
					printf("\n");
					break;
				}
			case 2:
				{
					printf("Enter the element to be deleted:\t");
					scanf("%s %d",&name,&a);
					head=delete_fun(head,a,name);
					printf("\nCurrent tree is:-\n",a);
					inorder(head);
					printf("\n");
					break;
				}
			case 3:
				{
					inorder(head);
					printf("\n");
					break;
				}
			default:
				break;
	}
			printf("\n\n\tDo you want to CONTINUE......1.YES 0.NO\n\n");
			scanf("%d",&ans);
		
	}
	return 0;
}

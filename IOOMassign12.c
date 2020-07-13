#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
	int data;
	struct node_tag *left;
	struct node_tag *right;
}node;

 typedef struct queue_tag
{
	node *front;
	node *rear;
}queue;

typedef int item_type;

typedef enum{FAILURE,SUCCESS}status_code;

void Initialize(queue *qptr)
{
	qptr->front=NULL;
	qptr->rear=NULL;
}

node* MakeNode(int data)
{
	node *ptr;
	ptr= (node* )malloc(sizeof(node));
	if(ptr!=NULL)
	{
		ptr->data=data;
		ptr->right=ptr->left=NULL;
	}
	return ptr;
}

insertQueue(queue *qptr,int data)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=data;
	if(qptr==NULL)
	{
		printf("Error\n");
	}
	else
	{
		if((qptr->front==NULL)&&(qptr->rear==NULL))
		{
			qptr->front=qptr->rear=ptr;
			//ptr->right=ptr->left=NULL;
		}
		else
		{
			(qptr->rear)->left=ptr;
			//ptr->left=NULL;
			qptr->rear=ptr;
		}
	}
}

deleteQueue(queue *qptr)
{
	node *ptr=qptr->front;
	if(ptr==NULL)
	{
		printf("Error\n");
	}
	else
	{
		ptr=qptr->front;
		qptr->front=qptr->front->left;
		//*qptr=ptr->data;
		free(ptr);
		if(qptr->front==NULL)
		{
			qptr->rear=NULL;
		}
	}
}
 
 node* search(node* root,int key)
 {
 	node *p=root;
 	if(p!=NULL)
 	{
 		if(key<p->data)
 		{
 			p=search(p->left,key);
		 }
		 else if(key>p->data)
		 {
		 	p=search(p->right,key);
		 }
	 }
	 return p;
 }
 
node* insert(node* root, int num)
{
	node* new_node,*p;
	p=root;
	new_node=(node*)malloc(sizeof(node));
	new_node->data=num;
	new_node->left=new_node->right=NULL;
	int done=0;
	if(root==NULL)
	{
		root=new_node;
	}
	else
	{
		while(!done)
		{
			if(p->data>new_node->data)
			{
				if(p->left==NULL)
				{
					p->left=new_node;
					done=1;
				}
				else{
					p=p->left;
				}
			}
			else if(new_node->data>p->data)
			{
				if(p->right==NULL)
				{
					p->right=new_node;
					done=1;
				}
				else
				{
					p=p->right;
				}
			}
			else
			{
				printf("error\n");
				done=1;
			}
		}
	}
	return root;
}
void delete_node(node **pptr)
{
	node *p,*q,*r;
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

node* delete_fun(node *root, int key)
{
	node *p,*prev;
	prev=NULL;
	p=root;
	while((p!=NULL)&&(p->data!=key))
	{
		if(p->data>key)
		{
			prev=p;
			p=p->left;	
		}
		else
		{
			prev=p;
			p=p->right;
		}	
	}
	if(p==root)
	{
		delete_node(&root);
	}
	else if(p!=NULL)
	{
		if(p==prev->left)
		{
			delete_node(&(prev->left));
		}
		else if(p==prev->right)
		{
			delete_node(&(prev->right));
		}
	}
	return root;	
}

int get_level(node *root,node *a,int level)
{
	//node *a=search(root,key);
	if(root==NULL)
	{
		return 0;
	}
	if(root==a)
	{
		return level;
	}
	int downlevel=get_level(root->left,a,level+1);
	
	if (downlevel != 0)
        return downlevel;
        
    return get_level(root->right,a, level+1);
}
void print_given_level(node *root,node *a,int level)
{
	if(root==NULL || level<2)
	{
		printf("NO cousin\n");
	}
	if(level==2)
	{
		if(root->left==a || root->right==a)
		{
			printf("NO cousin\n");
		}
		if (root->left)
           printf("%d ", root->left->data);
        if (root->right)
           printf("%d ", root->right->data);
	}
	
	else if (level > 2)
    {
        print_given_level(root->left, a, level-1);
        print_given_level(root->right, a, level-1);
    }
}

void printCousins(node *root, node *a)
{
	int level = get_level(root, a, 1);
	print_given_level(root, a, level);
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d, ",root->data);
		inorder(root->right);
	}
}
int height(node *p)
{
	int retval,left_ht,right_ht;
	node *root;
	root=p;
	if(root==NULL)
	{
		retval=-1;
	}
	else if((root->left==NULL)&&(root->right==NULL))
	{
		retval=0;
	}
	else
	{
		left_ht=height(root->left);
		right_ht=height(root->right);
		if(left_ht>right_ht)
		{
			retval=1+left_ht;
		}
		else
		{
			retval=1+right_ht;
		}
	}
	return retval;
}
void print_last_level_sum(node *root)
{
	queue q;
	Initialize(&q);
	node *temp=root;
	int level=height(root);
	int count=1,c=1;
	insertQueue(&q,root->data);
	int i;
	for(i=1;i<level;i++)
	{
		count=c;
		c=0;
		while(count--)
		{
			if(temp->left)
			{
				c++;
				insertQueue(&q,temp->left->data);
			}
			deleteQueue(&q);
			temp=q.front;
		}
	}
	int sum=0;
	while(q.front!=NULL&&q.rear!=NULL)
	{
		node *ptr=q.front;
		sum=sum+ptr->data;
		deleteQueue(&q);
	}
	printf("sum at max level is:-%d",sum);
}


int main()
{
	node *head=NULL,*p=NULL;
	int ans=1;
	while(ans==1)
	{
		int x,a;
		printf("ENTER THE OPERATION YOU WANT TO PERFORM\n1.INSERT\n2.DELETE\n3.FIND COUSIN NODE\n4.PRINT MAX SUM\n");
		scanf("%d",&x);
		switch(x)	
		{
			case 1:
				{
					printf("Enter the element to be inserted:\t");
					scanf("%d",&a);
					head=insert(head,a);
					printf("\nCurrent tree is:-\n",a);
					inorder(head);
					printf("\n");
					break;
				}
			case 2:
				{
					printf("Enter the element to be deleted:\t");
					scanf("%d",&a);
					head=delete_fun(head,a);
					printf("\nCurrent tree is:-\n",a);
					inorder(head);
					printf("\n");
					break;
				}
			case 3:
				{
					printf("Enter the element whose cousin you want to find:\t");
					scanf("%d",&a);
					p=search(head,a);
					printf("Cousins is/are:\t");
					printCousins(head,p);
					printf("\nCurrent tree is:-\n");
					inorder(head);
					printf("\n");
					break;
				}
			case 4:
				{
					print_last_level_sum(head);
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

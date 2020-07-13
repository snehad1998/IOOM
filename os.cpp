#include<iostream>
using namespace std;
typedef struct node
{
	int start_add;
	int end_add;
	int size;
	struct node *next;
} list_node;

void initiate(int &x)
{
	cout<<"Enter the intialized value:-"<<endl;
	cin>>x;
}
int main()
{
	int x;
	initiate(x);
	cout<<x;
	return 0;
}

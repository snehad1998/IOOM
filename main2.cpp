#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ass32cpp.cpp"
void print(ComplexInteger **p,int a,int b)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			cout<<p[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	int x=1,y;
	Matrix p,q,r,s;
	ComplexInteger c;
		p.input();
		p.display();
	while(x==1)
	{
		cout<<"Enter the choice\n1.ADD a complex integer\n2.SUBTRACT a complex integer\n3.Replace the element at position\n4.Multiple a matrix\n5.Create equivalatent matrix or list\n6.Search an element\n";
		cin>>y;
		switch(y)
		{
			case 1:
				cout<<"enter which way you want to add"<<endl;
				int v;
			//	cin>>v;
					r.input();
				s=p+r;
				s.display();
				if(v=1)
				{
						cin>>c;
						q=p+c;
				}
				else
				{
					r.input();
					s=p+r;
				}
			//	cin>>c;
			//	q=p+c;
				cout<<"The result is:"<<endl;
				q.display();
				break;	
			case 2:
				cout<<"enter which way you want to subtract"<<endl;
			//	int v;
				r.input();
				s=p-r;
				s.display();
				cin>>v;
				if(v=1)
				{
						cin>>c;
						q=p-c;
				}
				else
				{
					r.input();
				s=p-r;
				}
				cout<<"The result is:"<<endl;
				q.display();
				break;	
			case 3:
					
					cout<<"Enter element: ";
					int l;
					cin>>l;
		           p.operator ^(l);
				
				p.display();
				//	cout<<"hgh";
				break;	
			case 4:
					cout<<"Multiple with scalar or another Matrix: ";
				int a;
					cin>>a;
						r.input();
					q=p*r;
					q.display();
				if(a=1)
				{
					ComplexInteger b;
					cin>>b;
					q=p*b;
					q.display();
				}
				else if(a=2)
				{
					r.input();
					q=p*r;
					q.display();
				}
				
				break;	
			case 5:
				r=q;
				r.display();
			//	ComplexInteger **arr;
		//	arr=q;
			//	print(arr,q.m,q.n);
				break;
			case 6:
			
				cin>>c;
				bool t;
				t=p.search(p,c);
				if(t==true)
				{
					cout<<"element found\n";
				}
				else
				{
					cout<<"element not found\n";
				}
				break;
			default:
				break;	
			
		}
		printf("Do you want to continue :\n");
		scanf("%d",&x);
	}
	return 0;
}

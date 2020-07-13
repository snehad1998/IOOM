#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ass31.cpp"

int main()
{
	ComplexInteger a;
	ComplexInteger b;
	ComplexInteger	c;
	int x=1,y;
	while(x==1)
	{
		cout<<"Enter the choice\n1.ADD\n2.SUBTRACT\n3.MULTIPLY\n4.DIVIDE\n5.CONJUGATE\n6.SWAP\n";
		cin>>y;
		switch(y)
		{
			case 1:
				cout<<"Enter two numbers: ";
				cin>>a>>b;
				c=a+b;
				cout<<"Addition: "<<c<<endl;
				break;	
			case 2:
					cout<<"Enter two numbers: ";
				cin>>a>>b;
				c=a-b;
				cout<<"Subtraction: "<<c<<endl;
				break;	
			case 3:
					cout<<"Enter two numbers: ";
				cin>>a>>b;
				c=a*b;
				cout<<"Multiplication: "<<c<<endl;
				break;	
			case 4:
					cout<<"Enter two numbers: ";
				cin>>a>>b;
				c=a+b;
				cout<<"Division: "<<c<<endl;
				break;	
			case 5:
					cout<<"Enter  numbers: ";
				cin>>a;
				c=--a;
				cout<<"Conjugate: "<<c<<endl;
				break;
			case 6:
					cout<<"Enter  numbers: ";
				cin>>a;
				c=++a;
				cout<<"Swap: "<<c<<endl;
				break;
			default:
				break;	
			
		}
		printf("Do you want to continue :\n");
		scanf("%d",&x);
	}
	return 0;
}

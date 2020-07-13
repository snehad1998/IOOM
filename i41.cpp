#include<iostream>
#include<string>
#include"i413.h"
using namespace std;

int main()
{
	cout<<"Insert values :"<<endl;
	char a[20],b[20],c[20];
	char d[20],e[20];
	int u,v;
	int w,x;
	cout<<"University name:-\t";
	cin>>a;
	cout<<a;
	cout<<"Department name:-\t";
	cin>>b;
	cout<<"Person's name:-\t";
	cin>>c;
	cout<<"Company name:-\t";
	cin>>d;
	cout<<"Number of engineers:-\t";
	cin>>u;
	cout<<"Amount invested:-\t";
	cin>>x;
	cout<<"Type of Project:-\t";
	cin>>e;
	cout<<"Project Duration:-\t";
	cin>>v;
	cout<<"Amount granted to complete Project:-\t";
	cin>>w;
	cout<<endl<<"Class University"<<endl;
	University uni(a,b,c);
	uni.display();
	cout<<endl<<"Class Company"<<endl;
	Company com(d,u,x);
	com.display();
	cout<<endl<<"Class Project"<<endl;
	Project p(a,b,c,d,u,x,e,v,w);
	p.display();
	return 0;
}

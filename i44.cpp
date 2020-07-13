#include<iostream>
#include<string>
#include"i442.h"
using namespace std;

int main()
{
	char p[20];
	int pc;
	float pr,m;
	cout<<"Enter Values:-"<<endl;
	cout<<"Enter Publication:- ";
	cin>>p;
	cout<<"Enter Price:-  ";
	cin>>pr;
	cout<<"Enter page count:-";
	cin>>pc;
	cout<<"Enter Playing time:-";
	cin>>m;
	cout<<"Enter 3 month sale:-";
	float f[3];
	for(int i=0;i<3;i++)
	{
		cin>>f[i];
	}
	cout<<"For Class BOOOK"<<endl;
	book b(p,pr,pc,f);
	b.display_b();
	cout<<endl<<"For Class TAPE"<<endl;
	tape t(p,pr,m,f);
	t.display_t();
	return 0;
}

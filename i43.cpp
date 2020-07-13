#include<iostream>
#include<string>
#include"i432.h"
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
	cout<<"For Class BOOOK"<<endl;
	book b(p,pr,pc);
	b.display_b();
	cout<<"For Class TAPE"<<endl;
	tape t(p,pr,m);
	t.display_t();
	return 0;
}

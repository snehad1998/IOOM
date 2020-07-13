#include<iostream>
#include<string>
//#include"i422.h"
#include"i423.h"
using namespace std;

int main()
{
	char n[20];
	int i,j,k,l,m;
	cout<<"Enter values:-"<<endl<<"Name of student:-";
	cin>>n;
	cout<<"Roll Number:- ";
	cin>>i;
	cout<<"test1 marks:- ";
	cin>>j;
	cout<<"test2 marks:- ";
	cin>>k;
	cout<<"music marks:- ";
	cin>>l;
	cout<<"craft marks:- ";
	cin>>m;
	cout<<endl<<"Class Student"<<endl;
	Student s(n,i);
	s.display_details();
	cout<<endl<<"Class Examination"<<endl;
	Examination e(n,i,j,k);
	e.display_average();
	cout<<endl<<"Class Extracurricular"<<endl;
	Extracurricular ex(n,i,l,m);
	ex.get_score();
	ex.display_total();
	cout<<endl<<"Class Result"<<endl;
	Result r(n,i,j,k,l,m);
	cout<<"Grade is:- ";
	r.comment();
	return 0;
}

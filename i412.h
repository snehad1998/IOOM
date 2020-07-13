#include<iostream>
#include<string.h>
using namespace std;

class Company
{
private:
	char company_name[20];
	int no_engineer;
	int amount_invested;
public:
	Company();
	Company(char c[],int e,int a);
	Company(const Company &c);
	//~Company();
	char* get_company_name();
	int get_no_engineer();
	int get_amount_invested();
	void set_company_name(char *name);
	void set_no_engineer(int i);
	void set_amount_invested(int j);
	display();
};

Company::Company(){}

Company::Company(char c[],int e,int a)
{
	//company_name=new char[strlen(c)+1];
	strcpy(company_name,c);
	no_engineer=e;
	amount_invested=a;
}

Company::Company(const Company &c)
{
	//company_name=new char[strlen(c.company_name)+1];
	strcpy(company_name,c.company_name);
	no_engineer=c.no_engineer;
	amount_invested=c.amount_invested;
}
char* Company::get_company_name()
{
	return company_name;
}

int Company::get_no_engineer()
{
	return no_engineer;
}

int Company::get_amount_invested()
{
	return amount_invested;
}

void Company::set_company_name(char name[])
{
	strcpy(company_name,name);
}

void Company::set_no_engineer(int i)
{
	no_engineer=i;
}

void Company::set_amount_invested(int j)
{
	amount_invested=j;
}

Company::display()
{
	cout<<"Company Name:-"<<company_name<<endl;
	cout<<"Number of Engineers assigned:- "<<no_engineer<<endl;
	//cout<<"Amount invested in project :- "<<amount_invested<<endl;
}
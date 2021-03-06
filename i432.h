#include<iostream>
#include<string.h>
#include"i431.h"
using namespace std;

class book:public Publication
{
private:
	int page_count;
public:
	book(){}
	book(char t[],float p,int pc):Publication(t,p),page_count(pc){}

	int get_page_count();
	void set_page_count(int p);

	void display_b();
};
int book::get_page_count()
{
	return page_count;
}
void book::set_page_count(int p)
{
	page_count=p;
}

void book::display_b()
{
	cout<<"Publication:-"<<this->get_title()<<endl;
	cout<<"Price:-"<<this->get_price()<<endl;
	cout<<"Page count:-"<<page_count<<endl;
}

class tape:public Publication
{
private:
	float minutes;
public:
	tape(){}
	tape(char t[],float p,float min):Publication(t,p),minutes(min){}

	float get_minutes();
	void set_minutes(int m);

	void display_t();
};
float tape::get_minutes()
{
	return minutes;
}
void tape::set_minutes(int m)
{
	minutes=m;
}

void tape::display_t()
{
	cout<<"Publication:-"<<this->get_title()<<endl;
	cout<<"Price:-"<<this->get_price()<<endl;
	cout<<"Playing time:-"<<minutes<<endl;
}

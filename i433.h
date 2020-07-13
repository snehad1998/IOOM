#include<iostream>
#include<string.h>
#include"i431.h"
using namespace std;

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
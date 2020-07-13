#include<iostream>
#include<string.h>
using namespace std;

class Publication
{
private:
	char title[20];
	float price;
public:
	Publication(){}
	Publication(char t[],float p):price(p){strcpy(title,t);}
	char* get_title();
	float get_price();
	void set_title(char t[]);
	void set_price(float p);
	void display_p();
};

char* Publication::get_title()
{
	return title;
}
float Publication::get_price()
{
	return price;
}
void Publication::set_title(char t[])
{
	strcpy(title,t);
}
void Publication::set_price(float p)
{
	price=p;
}
void Publication::display_p()
{
	cout<<"Publication Title:-"<<title<<endl;
	cout<<"Price:-"<<price<<endl;
}
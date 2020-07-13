#include<iostream>
#include<string.h>
#include"i421.h"
using namespace std;

class Examination:public Student
{
private:
	int test1,test2;
public:
	Examination();
	Examination(char a[],int r,int t1,int t2):Student(a,r),test1(t1),test2(t2){}
	int get_test1();
	int get_test2();
	void set_test1(int t1);
	void set_test2(int t2);
	float cal_average(int t1,int t2);
	void display_average();

};


int Examination::get_test1()
{
	return test1;
}
int Examination::get_test2()
{
	return test2;
}
void Examination::set_test1(int t1)
{
	test1=t1;
}
void Examination::set_test2(int t2)
{
	test2=t2;
}
float Examination::cal_average(int t1,int t2)
{
	float avg;
	avg=(t1+t2);
	avg=avg/2;
	return avg;
}
void Examination::display_average()
{
	cout<<"Average of "<<this->get_name()<<"  Roll number:-"<<this->get_roll_no()<<"  is :-";
	float f=cal_average(test1,test2);
	cout<<f<<endl;
}



class Extracurricular:public Student
{
private:
	int music;
	int craft;
public:
	Extracurricular(){}
	Extracurricular(char n[],int r,int m,int c):Student(n,r),music(m),craft(c){}
	int get_music();
	int get_craft();
	void set_music(int m);
	void set_craft(int c);
	void get_score();
	void display_total(); 



};


int Extracurricular::get_music()
{
	return music;
}
int Extracurricular::get_craft()
{
	return craft;
}
void Extracurricular::set_music(int m)
{
	music=m;
}
void Extracurricular::set_craft(int c)
{
	craft=c;
}
void Extracurricular::get_score()
{
	cout<<"Music:- "<<music<<endl;
	cout<<"Craft:- "<<craft<<endl;
}

void Extracurricular::display_total()
{
	int total;
	total=music+craft;
	cout<<"Total in Extracurricular:- "<<total<<endl;
}
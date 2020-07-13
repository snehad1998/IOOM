#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	private:
		char name[20];
		int roll_no;
	public:
		Student(){}
		Student(char n[],int r)
		{
			strcpy(name,n);
			roll_no=r;
		}
		char* get_name();
		int get_roll_no();
		void set_name(char n[]);
		void set_roll_no(int r);
		display_details();
};

char* Student::get_name()
{
	return name;
}
int Student::get_roll_no()
{
	return roll_no;
}
void Student::set_name(char n[])
{
	strcpy(name,n);
}
void Student::set_roll_no(int r)
{
	roll_no=r;
}
Student::display_details()
{
	cout<<"Name of Student:- "<<name<<endl;
	cout<<"Roll Number:- "<<roll_no<<endl;
}
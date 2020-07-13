#include<iostream>
#include<string.h>
using namespace std;

class University
{
private:
	char university_name[20];
	char department[20];
	char person_name[20];
public:
	University();
	University(char u[],char d[],char p[]);
	University(const University &u);
	//~University();
	char* get_university_name();
	char* get_department();
	char* get_person_name();
	void set_university_name(char name[]);
	void set_department(char dept[]);
	void set_person_name(char person[]);
	display();
};

University::University(){}

University::University(char u[],char d[],char p[])
{
	strcpy(university_name,u);
	//department=new char[strlen(d)+1];
	strcpy(department,d);
	//person_name=new char[strlen(p)+1];
	strcpy(person_name,p);
}

University::University(const University &u)
{
	//university_name=new char[strlen(u.university_name)+1];
	strcpy(university_name,u.university_name);
	//department=new char[strlen(u.department)+1];
	strcpy(department,u.department);
	//person_name=new char[strlen(u.person_name)+1];
	strcpy(person_name,u.person_name);
}

char*  University::get_university_name()
{
	return university_name;
}

char* University::get_department()
{
	return department;
}

char* University::get_person_name()
{
	return person_name;
}
void University::set_university_name(char name[])
{
	strcpy(university_name,name);
}
void University::set_department(char dept[])
{
	strcpy(department,dept);
}

void University::set_person_name(char person[])
{
	strcpy(person_name,person);
}

University::display()
{
	cout<<"University Name:- "<<university_name<<endl;
	cout<<"Department:- "<<department<<endl;
	cout<<"Name of person who got project:- "<<person_name<<endl;
}
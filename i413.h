#include<iostream>
#include"i41.h"
#include"i412.h"
#include<string.h>
using namespace std;

class Project: public University , public Company
{
	private:
		char project_type[20];
		int project_duration;
		int amount_granted;
	public:
		Project();
		Project(char u[],char d[],char p[],char c[],int n,int a,char pr[],int pj,int ag);
		//Project(const Project &p);
		//~Project();
		char* get_project_type();
		int get_project_duration();
		int get_amount_granted();
		void set_project_type(char type[]);
		void set_project_duration(int p);
		void set_amount_granted(int a);
		display();



};

Project::Project():University(),Company(){}

Project::Project(char u[],char d[],char p[],char c[],int n,int a,char pr[],int pj,int ag):University(u,d,p),Company(c,n,a)
{
	//project_type=new char[strlen(pr)+1];
	strcpy(project_type,pr);
	project_duration=pj;
	amount_granted=ag;
}

char* Project::get_project_type()
{
	return project_type;
}

int Project::get_project_duration()
{
	return project_duration;
}
int Project::get_amount_granted()
{
	return amount_granted;
}
void Project::set_project_type(char type[])
{
	strcpy(project_type,type);
}
void Project::set_project_duration(int p)
{
	project_duration=p;
}
void Project::set_amount_granted(int a)
{
	amount_granted=a;
}
		
Project::display()
{
	cout<<"University Name:- "<<this->get_university_name()<<endl;
	cout<<"Department:- "<<this->get_department()<<endl;
	cout<<"Name of person who got project:- "<<this->get_person_name()<<endl;
	cout<<"Company Name:-"<<this->get_company_name()<<endl;
	cout<<"Number of Engineers assigned:- "<<this->get_no_engineer()<<endl;
	//cout<<"Amount invested in project :- "<<this->get_amount_invested()<<endl;
	cout<<"Type of Project:- "<<project_type<<endl;
	cout<<"Duration of project:- "<<project_duration<<endl;
	cout<<"Amount granted to complete project:- "<<amount_granted<<endl;
}

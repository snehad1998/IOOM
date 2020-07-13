#include<iostream>
#include<string.h>
#include"i422.h"
using namespace std;

class Result: public Examination,public Extracurricular
{
private:
	int total;
public:
	Result(){}
	Result(char n[],int r,int t1,int t2,int m,int c):Examination(n,r,t1,t2),Extracurricular(n,r,m,c){}

	int cal_score();
	void comment();
};

int Result::cal_score()
{
	return (get_test1()+get_test2()+get_music()+get_craft());
	
}
void Result::comment()
{
	float percent;
	percent=get_test1()+get_test2()+get_music()+get_craft();
	percent=percent/4;
	if(percent>=40.0)
	{
		if(percent>=90.0)
		{
			cout<<"A"<<endl;
		}
		else if(percent>=75.0)
		{
			cout<<"B"<<endl;
		}
		else if(percent>=65.0)
		{
			cout<<"C"<<endl;
		}
		else
		{
			cout<<"D"<<endl;
		}
	}
	else
	{
		cout<<"FAIL"<<endl;
	}
}

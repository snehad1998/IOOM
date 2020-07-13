#include<iostream>
#include<string.h>
using namespace std;

class sales
{
private:
	float record[3];
public:
	sales(){}
	sales(float r[])
	{
		for(int i=0;i<3;i++)
		{
			record[i]=r[i];
		}
	}
	void getdata();
	float* display_s();
};

void sales::getdata()
{
	cout<<"Enter the sales of 3 months"<<endl;
	for(int i=0;i<3;i++)
	{
		cin>>record[i];
	}
	//return record;

}
float* sales::display_s()
{
	cout<<"The sales of 3 months"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<record[i]<<"\t";
	}
}

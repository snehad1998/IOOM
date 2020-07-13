#include <iostream>
#include <string.h>
#include <stdexcept>
#include"que2.h"

using namespace std;

int main()
{
	Shape shape();
	cout<<"Shape,2D and 3D class are Abstract Classes"<<endl<<"Hence we cant create instance of that class"<<endl;
	try{
		float a,b,k,d;
		int l,q,ri,flag=0,ch;
		while(flag==0)
		{
			cout<<"Enter \n1)TRIANGLE\n2)PARELLELOGRAM\n3)RECTANGLE\n4)RHOMBUS\n5)SQUARE\n6)CIRCLE\n7)SCALENE\n8)ISOSCELES\n9)EQUILATERAL\n10)CUBOID\n11)CUBE\n12)SPHERE\n13)EXIT\n";
			cin>>ch;
			switch(ch)
			{
				case 1:
				{
					cout<<"***********************************************************************************\nTRIANGLE\nEnter Base and height of triangle:-\n";
					cin>>a>>b;
					Triangle t("TRIANGLE","2D",a,b);
					t.printName();
					t.printType();
					t.calculateArea();
					break;
				}
				case 2:
				{
					cout<<"***********************************************************************************\nPARELLELOGRAM\nEnter Base and height of Parrellelogram:-\n";
					cin>>a>>b;
					Parrellelogram p("PARELLELOGRAM","2D",a,b);
					p.printName();
					p.printType();
					p.calculateArea();
					break;
				}
				case 3:
				{
					cout<<"***********************************************************************************\nRECTANGLE\nEnter Base and height of Rectangle:-\n";
					cin>>a>>b;
					Rectangle r("RECTANGLE","2D",a,b);
					r.printName();
					r.printType();
					r.calculateArea();
					break;
				}
				case 4:
				{
					cout<<"***********************************************************************************\nRHOMBUS\nEnter side of Rhombus:-\n";
					cin>>a;
					Rhombus rh("RHOMBUS","2D",a);
					rh.printName();
					rh.printType();
					rh.calculateArea();
					break;
				}	
				case 5:
				{
					cout<<"***********************************************************************************\nSQUARE\nEnter side of square:-\n";
					cin>>a;
					Square s("SQUARE","2D",a);
					s.printName();
					s.printType();
					s.calculateArea();
					break;
				}
				case 6:
				{
					cout<<"***********************************************************************************\nCIRCLE\nEnter radius of circle:-\n";
					cin>>a;
					Circle c("CIRCLE","2D",a);
					c.printName();
					c.printType();
					c.calculateArea();
					break;
				}
				case 7:
				{
					cout<<"***********************************************************************************\nSCALENE\nEnter Base and height and sidesof triangle:-\n";
					cin>>a>>b>>k>>d;
					Scalene sc("SCALENE","2D",a,b,k,d);
					sc.printName();
					sc.printType();
					sc.calculateArea();
					break;
				}
				case 8:
				{
					cout<<"***********************************************************************************\nISOSCELES\nEnter Base and height and side of triangle:-\n";
					cin>>a>>b>>k;
					Isosceles i("ISOSCELES","2D",a,b,k);
					i.printName();
					i.printType();
					i.calculateArea();
					break;
				}
				case 9:
				{
					cout<<"***********************************************************************************\nEQUILATERAL\nEnter Base and height of triangle:-\n";
					cin>>a>>b;
					Equilateral e("EQUILATERAL","2D",a,b);
					e.printName();
					e.printType();
					e.calculateArea();
					break;
				}
				case 10:
				{
					cout<<"***********************************************************************************\nCUBOID\nEnter length,breadth and height of cuboid:-\n";
					cin>>l>>q>>ri;
					Cuboid cd("CUBOID","3D",l,q,ri);
					cd.printName();
					cd.printType();
					cd.calculateVolume();
					break;
				}
				case 11:
				{
					cout<<"***********************************************************************************\nCUBE\nEnter side of cube:-\n";
					cin>>l;
					Cube cb("CUBE","3D",l);
					cb.printName();
					cb.printType();
					cb.calculateVolume();
					break;
				}
				case 12:
				{
					cout<<"***********************************************************************************\nSPHERE\nEnter radius of sphere:-\n";
					cin>>l;
					Sphere sp("SPHERE","3D",l);
					sp.printName();
					sp.printType();
					sp.calculateVolume();
					break;
				}
				case 13:
				{
					flag=1;
					break;
				}
				default:
					break;
			}
		}
	}
	 catch (exception const& ex) { 
      cerr << "Exception: " << ex.what() <<endl; 
      return -1;
   } 
	return 0;
}

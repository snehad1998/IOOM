#include <iostream>
#include "BT16CSE099_IOOM3.1_DEC.h"
#include "BT16CSE099_IOOM3.1_DEF.h"

using namespace std;

int main()
{
	ComplexInteger c1;
	ComplexInteger c2;
	ComplexInteger c3;
	
	int done = 0 , choice;
	float r1 , r2 , i1 , i2 ;
	  
	cout << "\n\n";  
	cout << "\t\t\t\t  Enter Real Part of First ComplexInteger : ";
	cin  >> r1;
	cout << "\t\t\t\t  Enter Imaginary Part of First ComplexInteger : ";
	cin  >> i1;
	cout << "\t\t\t\t  Enter Real Part of Second ComplexInteger : ";
	cin  >> r2;
	cout << "\t\t\t\t  Enter Imaginary Part of Second ComplexInteger : ";
	cin  >> i2;
	
	c1.SetReal(r1);
	c1.SetImg(i1);
	c2.SetReal(r2);
	c2.SetImg(i2);
	
	while(!done)
	{
		cout << "\t\t\t\t __________________________ " << endl;
		cout << "\t\t\t\t|      OPERATION TABLE     |" << endl;
		cout << "\t\t\t\t| Press 1 to Add.          |" << endl;
		cout << "\t\t\t\t| Press 2 to Subtract      |" << endl;
		cout << "\t\t\t\t| Press 3 to Multiply      |" << endl;
		cout << "\t\t\t\t| Press 4 to Divide        |" << endl;
		cout << "\t\t\t\t| Press 5 to Swap R and I  |" << endl;
		cout << "\t\t\t\t| Press 6 to Know Magnitude|" << endl;
		cout << "\t\t\t\t| Press 7 to Exit          |" << endl;
		cout << "\t\t\t\t|__________________________|" << endl;
		
		cin >> choice;
		
		if( choice == 1 )
		{
			c3 = c1 + c2;
			DisplayInComplexFormat(c3);
		}
		else if( choice == 2 )
		{
			c3 = c1 - c2;
			DisplayInComplexFormat(c3);
		}
		else if( choice == 3 )
		{
			c3 = c1 * c2;
			DisplayInComplexFormat(c3);
		}
		else if( choice == 4 )
		{
			c3 = c1 / c2;
			DisplayInComplexFormat(c3);
		}
		else if( choice == 5 )
		{
			c3 = c1++ ;
			DisplayInComplexFormat(c3);
		}
		else if( choice == 6 )
		{
			c3 = c1-- ;
			DisplayInComplexFormat(c3);
		}
		else
		{
			done = 1;
		}
	}
	
	return 0;
}

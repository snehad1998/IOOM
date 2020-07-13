#include <iostream>
#include "BT16CSE099_IOOM3.2_DEC.h"
#include "BT16CSE099_IOOM3.2_DEF.h"

using namespace std;

int main()
{
	
	int i, j, num_rows_1, num_rows_2, num_cols_1, num_cols_2, choice, done=0, index, arr_size;
	float real_part, img_part;
	
	cout << "\t\t\t\t Enter number of Rows in Matrix 1 : ";
	cin  >> num_rows_1;
	cout << "\t\t\t\t Enter number of Cols in Matrix 1 : ";
	cin  >> num_cols_1;
	cout << "\t\t\t\t Enter number of Rows in Matrix 2 : ";
	cin  >> num_rows_2;
	cout << "\t\t\t\t Enter number of Cols in Matrix 2 : ";
	cin  >> num_cols_2;
	
	cout << "\t\t\t\t Enter Real part of the ComplexInteger : ";
	cin  >> real_part;
	cout << "\t\t\t\t Enter Img  part of the ComplexInteger : ";
	cin  >> img_part;
	
	cout << "\t\t\t\t Enter Values in Matrix 1 : " << endl;
	Matrix M1(num_rows_1,num_cols_1,0); /* 0 INDICATES THAT MATRIX VALUES WILL BE GIVEN BY THE USER */
	cout << "\t\t\t\t Enter Values in Matrix 2 : " << endl;
	Matrix M2(num_rows_2,num_cols_2,0); /* 0 INDICATES THAT MATRIX VALUES WILL BE GIVEN BY THE USER */
	
	ComplexInteger C(real_part,img_part);
	
	while(!done)
	{
		cout << "\t\t\t\t ________________________________________________ " << endl;
		cout << "\t\t\t\t|               OPERATION TABLE                  |" << endl;
		cout << "\t\t\t\t| Press 1 to Add a Scalar to all Elements.       |" << endl;
		cout << "\t\t\t\t| Press 2 to Add two Matrices.                   |" << endl;
		cout << "\t\t\t\t| Press 3 to Subtract a Scalar from each Element.|" << endl;
		cout << "\t\t\t\t| Press 4 to Subtract two Matrices.              |" << endl;
		cout << "\t\t\t\t| Press 5 to Multiply a Scalar with each Element.|" << endl;
		cout << "\t\t\t\t| Press 6 to Multiply two Matrices.              |" << endl;
		cout << "\t\t\t\t| Press 7 to Set an element to 0+0i.             |" << endl;
		cout << "\t\t\t\t| Press 8 to Find an element in Matrix.          |" << endl;
		cout << "\t\t\t\t| Press 9 to Assign ComplexInteger[] to Matrix.  |" << endl;
		cout << "\t\t\t\t| Press 0 to Exit.                               |" << endl;
		cout << "\t\t\t\t|________________________________________________|" << endl;
		
		cin >> choice;
		
		if( choice == 1 )
		{
			Matrix M3 = M1 + C;
			DisplayMatrixContents( M3 );
		}
		else if( choice == 2 )
		{
			Matrix M3 = M1 + M2;
			DisplayMatrixContents( M3 );
		}
		else if( choice == 3 )
		{
			Matrix M3 = M1 - C;
			DisplayMatrixContents( M3 );
		}
		else if( choice == 4 )
		{
			Matrix M3 = M1 - M2;
			DisplayMatrixContents( M3 );
		}
		else if( choice == 5 )
		{
			Matrix M3 = M1 * C;
			DisplayMatrixContents( M3 );
		}
		else if( choice == 6 )
		{
			Matrix M3 = M1 * M2;
			DisplayMatrixContents( M3 );
		}
		else if( choice == 7 )
		{
			cout << "\t\t\t\t --- Enter the index : ";
			cin  >> index;
			M1^index;
			DisplayMatrixContents( M1 );
		}
		else if( choice == 8 )
		{
			cout << "\t\t\t\t --- Enter Real part of the ComplexInteger : ";
			cin  >> real_part;
			cout << "\t\t\t\t --- Enter Img  part of the ComplexInteger : ";
			cin  >> img_part;
			
			ComplexInteger C_find(real_part,img_part);
			
			if(IsPresentInMatrix(M1,C_find))
			{
				cout << "\t\t\t\t => The given ComplexInteger was found in the Matrix(1)." << endl;
			}
			else
			{
				cout << "\t\t\t\t => The given ComplexInteger was NOT found in the Matrix(1)." << endl;	
			}
		}
		else if( choice == 9 )
		{			
			ComplexInteger C_arr[num_rows_1][num_cols_1];
			
			for( i=0 ; i<num_rows_1 ; i++ )
			{
				for( j=0 ; j<num_cols_1 ; j++ )
				{
					cout << "\t\t\t\t --- Enter Real part of the ComplexInteger : ";
					cin  >> real_part;
					cout << "\t\t\t\t --- Enter Img  part of the ComplexInteger : ";
					cin  >> img_part;
				
					C_arr[i][j].SetReal(real_part);
					C_arr[i][j].SetImg(img_part);
				}
			}	
			
			Matrix M3(num_rows_1,num_cols_1,1); 
			M3 = &C_arr[0][0];
			DisplayMatrixContents( M3 );
		}
		else
		{
			done = 1;
		}
	}
	
	M1.~Matrix();
	M2.~Matrix();

	return 0;
}

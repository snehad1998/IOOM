#include <iostream>
using namespace std;

/* CONSTRUCTORS */
Matrix :: Matrix( )
{
	this->rows = 1;
	this->cols = 1;
	
	AllocateMatrix();
}

Matrix :: Matrix( int num_rows , int num_cols , bool init)
{
	int i,j,real_part,img_part;	
	
	this->rows = num_rows;
	this->cols = num_cols;
	
	AllocateMatrix();
	
	if( init )
	{
		for( i=0 ; i<num_rows ; i++ )
		{
			for( j=0 ; j<num_cols ; j++ )
			{
				mat[i][j] = 0;
			}
		}
	}
	else
	{
		for( i=0 ; i<num_rows ; i++ )
		{
			for( j=0 ; j<num_cols ; j++ )
			{
				cout << "\t\t\t\t\t Enter Element [" << i << "][" << j << "] Real part : " ;
				cin  >> real_part;
				cout << "\t\t\t\t\t Enter Element [" << i << "][" << j << "] Img  part : " ;
				cin  >> img_part;
				
				mat[i][j].SetReal(real_part);
				mat[i][j].SetImg(img_part);
			}
		}
		cout << "\n\n";
	}
	
}

Matrix :: Matrix( const Matrix& m )
{
	int i,j,num_rows,num_cols;
	
	num_rows = m.rows;
	num_cols = m.cols;	
	
	this->rows = num_rows;
	this->cols = num_cols;
	
	AllocateMatrix();
	
	for( i=0 ; i<num_rows ; i++ )
	{
		for( j=0 ; j<num_cols ; j++ )
		{
			mat[i][j] = m.mat[i][j] ; 
		}
	}
}

/* ALLOCATING SPACE TO THE MATRIX DYNAMICALLY */
void Matrix :: AllocateMatrix()
{
	int i;
	
	mat = new ComplexInteger*[this->rows];
	
	for( i=0 ; i<rows ; i++ )
	{
		mat[i] = new ComplexInteger[this->cols];
	}
	
}

/* GETTER AND SETTER METHODS */	
int Matrix :: GetNumRows() const
{
	return (this->rows);
}

int Matrix :: GetNumCols() const
{
	return (this->cols);
}

void Matrix :: SetNumRows( int num_rows )
{
	this->rows = num_rows;
}

void Matrix :: SetNumCols( int num_cols )
{
	this->cols = num_cols;
}

/* OPERATOR OVERLOADED FUNCTIONS */
Matrix Matrix :: operator + ( const Matrix m ) const
{
	int i,j,num_rows,num_cols;
		
	num_rows = this->rows;
	num_cols = this->cols;
	
	Matrix sum_matrix(num_rows,num_cols,true);
	
	if( (this->rows==m.rows) && (this->cols==m.cols) )
	{		
		for( i=0 ; i<num_rows ; i++ )
		{
			for( j=0 ; j<num_cols ; j++ )
			{
				sum_matrix.mat[i][j] = this->mat[i][j] + m.mat[i][j]; 
			}
		}
	}
	else
	{
		cout << "\t\t\t\t Matrix Addition cannot be performed as dimensions are not same.\n";
	}
	
	return (sum_matrix);
}

Matrix Matrix :: operator + ( const ComplexInteger c ) const
{
	int i,j,num_rows,num_cols;
		
	num_rows = this->rows;
	num_cols = this->cols;
	
	Matrix sum_matrix(num_rows,num_cols,true);
	
	for( i=0 ; i<num_rows ; i++ )
	{
		for( j=0 ; j<num_cols ; j++ )
		{
			sum_matrix.mat[i][j] = this->mat[i][j] + c; 
		}
	}
	
	return (sum_matrix);
}		
		
		
		
Matrix Matrix :: operator - ( const Matrix m ) const
{
	int i,j,num_rows,num_cols;
	ComplexInteger temp;
		
	num_rows = this->rows;
	num_cols = this->cols;	
	
	Matrix diff_matrix(num_rows,num_cols,true);	
	
	if( (this->rows==m.rows) && (this->cols==m.cols) )
	{	
		for( i=0 ; i<num_rows ; i++ )
		{
			for( j=0 ; j<num_cols ; j++ )
			{
				diff_matrix.mat[i][j] = this->mat[i][j] - m.mat[i][j]; 
			}
		}
	}
	else
	{
		cout << "\t\t\t\t Matrix Subtraction cannot be performed as dimensions are not same.\n";
	}
	
	return (diff_matrix);
}	

Matrix Matrix :: operator - ( const ComplexInteger c ) const
{
	int i,j,num_rows,num_cols;
	ComplexInteger temp;
		
	num_rows = this->rows;
	num_cols = this->cols;	
	
	Matrix diff_matrix(num_rows,num_cols,true);
	
	for( i=0 ; i<num_rows ; i++ )
	{
		for( j=0 ; j<num_cols ; j++ )
		{
			diff_matrix.mat[i][j] = this->mat[i][j] - c; 
		}
	}
	
	return (diff_matrix);
}

Matrix Matrix :: operator * ( const Matrix m ) const
{
	int i,j,k,num_cols2,num_rows,num_cols;
	ComplexInteger temp;
		
	num_rows  = this->rows;
	num_cols2 = this->cols;
	num_cols  = m.cols;

	Matrix prod_matrix(num_rows,num_cols,true);	
	
	if( this->cols == m.rows )
	{
		for( i=0 ; i<num_rows ; i++ )
		{
			for( j=0 ; j<num_cols ; j++ )
			{
				for( k=0 ; k<num_cols2 ; k++ )
				{
					temp = this->mat[i][k] * m.mat[k][j];
					prod_matrix.mat[i][j] = prod_matrix.mat[i][j] + temp; 
				}
			}
		}
	}
	else
	{
		cout << "\t\t\t\t Matrix Multiplication cannot be performed.\n";
	}
	
	return (prod_matrix);
}

Matrix Matrix :: operator * ( const ComplexInteger c ) const
{
	int i,j,k,num_cols2,num_rows,num_cols;
	ComplexInteger temp;
		
	num_rows = this->rows;
	num_cols = this->cols;

	Matrix prod_matrix(num_rows,num_cols,true);
	
	for( i=0 ; i<num_rows ; i++ )
	{
		for( j=0 ; j<num_cols ; j++ )
		{
			prod_matrix.mat[i][j] = this->mat[i][j] * c; 	
		}
	}
	
	return (prod_matrix);
}

void Matrix :: operator ^ ( int pos )
{
	int num_rows,num_cols;
	
	if( pos < this->rows*this->cols && pos >= 0 )
	{
		num_rows = pos/this->cols;
		num_cols = pos%this->cols;
		
		this->mat[num_rows][num_cols].SetReal(0.0);
		this->mat[num_rows][num_cols].SetImg(0.0);
	}
	else
	{
		cout << "\t\t\t\t Array Element Out Of Bounds.\n ";
	}	
}


Matrix Matrix :: operator = ( const Matrix m )
{
	int i,j,num_rows,num_cols;
	
	num_rows = m.rows;
	num_cols = m.cols;
	
	AllocateMatrix();
	
	for( i=0 ; i<num_rows ; i++ )
	{
		for( j=0 ; j<num_cols ; j++ )
		{
			this->mat[i][j] = m.mat[i][j];
		}
	}
	
	return (*this);	
}

Matrix Matrix :: operator = ( const ComplexInteger* c_arr )
{
	int i,j,num_rows,num_cols,arr_index=0;
	
	num_rows = this->rows;
	num_cols = this->cols;
	
	AllocateMatrix();
	
	for( i=0 ; i<num_rows ; i++ )
	{
		for( j=0 ; j<num_cols ; j++ )
		{
			this->mat[i][j] = *((c_arr+(num_cols*i))+j); /* c_arr[i][j] */
		}
	}
	
	return (*this);	
}
		
/* FRIEND FUNCTIONS */
void DisplayMatrixContents( const Matrix m )
{
	int i,j,num_rows,num_cols;
	
	num_rows = m.rows;
	num_cols = m.cols;
	
	for( i=0 ; i<num_rows ; i++ )
	{
		for( j=0 ; j<num_cols ;  j++ )
		{
			DisplayInComplexFormat( m.mat[i][j] );
			cout << "\t";
		}
		
		cout << "\n";
	}
}

bool IsPresentInMatrix( const Matrix m , ComplexInteger c )
{
	int i,j,num_rows,num_cols;
	bool found = false;
	ComplexInteger current;
	
	num_rows = m.rows;
	num_cols = m.cols;
	
	for( i=0 ; i<num_rows && !found ; i++ )
	{
		for( j=0 ; j<num_cols ; j++ )
		{
			current = m.mat[i][j];
			
			if( (c.real == current.real) && (c.img == current.img) )
			{
				found = true;
			}
		}
	}
	
	return (found);
}

/* DESTRUCTOR */
Matrix :: ~Matrix()
{
	int i, num_rows;
	
	num_rows = this->rows;
	
	for( i=0 ; i<num_rows ; i++ )
	{
		delete[] this->mat[i];
	}
	
	delete[] this->mat ;
}

/*******************************COMPLEX_INTEGER********************************/

/*____________________________CONSTRUCTORS____________________________________*/
ComplexInteger :: ComplexInteger()
{
	this->real = 0;
	this->img  = 0;
}

ComplexInteger :: ComplexInteger( float r_val )
{
	this->real = r_val;
	this->img  = 0;
}

ComplexInteger :: ComplexInteger( float r_val , float i_val )
{
	this->real = r_val;
	this->img  = i_val;
}

ComplexInteger :: ComplexInteger( const ComplexInteger& c )
{
	this->real = c.real;
	this->img  = c.img ;
}

/*_______________________GETTER AND SETTER METHODS____________________________*/

float ComplexInteger :: GetReal() const 
/* const ENSURES THAT CALLING OBJECT REMAINS UNALTERED*/
{
	return ( this->real );
}

float ComplexInteger :: GetImg() const 
/* const ENSURES THAT CALLING OBJECT REMAINS UNALTERED*/
{
	return ( this->img );
}

void ComplexInteger :: SetReal( float r_val ) 
{
	this->real = r_val;
}

void ComplexInteger :: SetImg( float i_val )
{
	this->img = i_val;
}

/*____________________________OPERATOR OVERLOADING____________________________*/

ComplexInteger ComplexInteger :: operator +  ( const ComplexInteger& c ) const
{
	ComplexInteger sum;
	
	sum.SetReal( this->real + c.real);
	sum.SetImg ( this->img  + c.img );
	
	return (sum);
}

ComplexInteger ComplexInteger :: operator -  ( const ComplexInteger& c ) const
{
	ComplexInteger diff;
	
	diff.SetReal( this->real - c.real);
	diff.SetImg ( this->img  - c.img );
	
	return (diff);
}

ComplexInteger ComplexInteger :: operator *  ( const ComplexInteger& c ) const
{
	ComplexInteger prod;
	
	prod.SetReal( (this->real * c.real) - (this->img * c.img ) );
	prod.SetImg ( (this->real * c.img ) + (this->img * c.real) );
	
	return (prod);
}

ComplexInteger ComplexInteger :: operator =  ( const ComplexInteger& c )
{	
	this->real = c.real;
	this->img  = c.img ;
	
	return (*this);
}

/*___________________________DISPLAY GLOBAL FUNCTION__________________________*/
void DisplayInComplexFormat( const ComplexInteger c )
{
	cout << "(" << c.real << ") + (" << c.img << ")i" ; 
}

/*______________________________DESTRUCTOR____________________________________*/
ComplexInteger :: ~ComplexInteger()
{
	//delete[](this);
} 

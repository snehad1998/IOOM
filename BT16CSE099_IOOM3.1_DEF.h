#include <iostream>
using namespace std;

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

ComplexInteger ComplexInteger :: operator /  ( const ComplexInteger& c ) const
{
	ComplexInteger div;
	
	float mag_c = c.real*c.real + c.img*c.img;
	
	if( mag_c != 0 )
	{		
		div.SetReal( ( (this->real * c.real) + (this->img  * c.img ) ) / mag_c );
		div.SetImg ( ( (this->img  * c.real) - (this->real * c.img ) ) / mag_c );
	}	
	else
	{
		cout << "\t\t\t\tDivision cannot be performed as Magnitude of divisor is 0." << endl ; 
	}
	
	return (div);
}

ComplexInteger ComplexInteger :: operator ++ ( int )
{
	float temp;
	
	temp   = this->real;
	this->real = this->img;
	this->img  = temp ;
	
	return (*this);
}

ComplexInteger ComplexInteger :: operator -- ( int )
{
	this->real = (this->real)*(this->real) + (this->img)*(this->img) ;
	this->img  = 0 ;
	
	return (*this);
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
	cout << "\t\t\t\t => Result = (" << c.real << ") + (" << c.img << ")i ." << endl; 
}

/*______________________________DESTRUCTOR____________________________________*/
ComplexInteger :: ~ComplexInteger()
{
	//delete[](this);
}

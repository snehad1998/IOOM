#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;

class ComplexInteger
{
	private:
		int real;
		int img;
	public:
		ComplexInteger(int real1=0,int img1=0){ real=real1 ; img=img1 ; }
		ComplexInteger(const ComplexInteger &c);
		//~ComplexInteger();
		int get_real(){return real;}
		int get_img(){return img;}
		void set_real( int real1){real=real1;}
		void set_img( int img1){img=img1;}
		ComplexInteger  operator =(const ComplexInteger c);
		ComplexInteger  operator +(const ComplexInteger c);
		ComplexInteger  operator -(const ComplexInteger c);
		ComplexInteger  operator *(const ComplexInteger c);
		ComplexInteger  operator /(const ComplexInteger c);
		ComplexInteger&  operator ++ ();
		ComplexInteger & operator -- ();
		bool operator ==(const ComplexInteger &c);
		bool operator !=(const ComplexInteger &c);
		friend ostream & operator <<(ostream &os,const ComplexInteger& c);
		friend istream & operator >>(istream &is, ComplexInteger& c);
};

//copy constructor
ComplexInteger::ComplexInteger(const ComplexInteger &c)
{
	real=c.real;
	img=c.img;
}
ComplexInteger ComplexInteger::operator =(const ComplexInteger c)
{
	real=c.real;
	img=c.img;
}
//+
ComplexInteger ComplexInteger::operator +(const ComplexInteger c)
{
	ComplexInteger res;
	res.real=real+c.real;
	res.img=img+c.img;
	return res;
}

//-
ComplexInteger ComplexInteger::operator -(const ComplexInteger c)
{
	ComplexInteger res;
	res.real=real-c.real;
	res.img=img-c.img;
	return res;
}

//*
ComplexInteger ComplexInteger::operator *(const ComplexInteger c)
{
	ComplexInteger res;
	res.real=(real*c.real)-(img*c.img);
	res.img=(real*c.img)+(img*c.real);
	return res;
}

// / operator
ComplexInteger ComplexInteger::operator /(const ComplexInteger c)
{
	ComplexInteger res;
	res.real=((real*c.real)+(img*c.img))/((c.real*c.real)+(c.img*c.img));  
 	res.img=((img*c.real)-(real*c.img))/((c.real*c.real)+(c.img*c.img));  
	return res;	
	}

//ostream
ostream & operator <<(ostream &os,const ComplexInteger& c)
{
	if(c.img>=0)
		os<<c.real<<"+"<<c.img<<"i";
	else
		os<<c.real<<c.img<<"i";
	return os;
}


//istream
istream & operator >>(istream &is,ComplexInteger& c)
{
	cout<<"Enter real part:-  ";
	is>>c.real;
	cout<<"Enter the imaginary part:-  ";
	is>>c.img;
	return is;
}

//==
bool ComplexInteger:: operator ==(const ComplexInteger &c)
{
	return ((real==c.real) && (img==c.img));
}

//!=
bool ComplexInteger:: operator !=(const ComplexInteger &c)
{
	return	(!((*this)==c));
}

//conjugate
ComplexInteger&   ComplexInteger::operator --()
{
	this->img=-(this->img);
}

//swaps real and imaginary part
ComplexInteger&   ComplexInteger::operator ++()
{
	int x;
	x=this->real;
	this->real=this->img;
	this->img=x;
	return *this;
}

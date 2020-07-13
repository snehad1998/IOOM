#include <iostream>
using namespace std;
#include"ass31.cpp"


class Matrix
{
	private:
		ComplexInteger* *matrix;
		int m,n;
	public:
		Matrix()
		{
		m=0;n=0;
			matrix=0;
		}
		Matrix(int row,int col)
		{
	 		m = row; 
      		n= col; 
     	   	matrix= new ComplexInteger*[m]; 
     		 for (int i = 0; i < m; i++) 
			 matrix[i] = new ComplexInteger[n]; 
		}
		Matrix(const Matrix &p)
		{
			m=p.m;
			n=p.n;
			matrix= new ComplexInteger*[m]; 
     		 for (int i = 0; i < m; i++) 
				 matrix[i] = new ComplexInteger[n];
			 for(int i=0;i<m;i++)
			 {
			 	for(int j=0;j<n;j++)
			 	{
			 		matrix[i][j]=p.matrix[i][j];
				}
			 }
		}
		//~Matrix();
		Matrix operator +(ComplexInteger i);
			Matrix operator +(Matrix i);
		Matrix  operator -( ComplexInteger i);
			Matrix  operator -( Matrix  i);
			Matrix&  operator =(Matrix  p);
		Matrix operator ^(int x);
	
	//	ComplexInteger** operator =(Matrix p);
		Matrix  operator *(Matrix p);
			Matrix  operator *(ComplexInteger  p);
		display();
		input();
		bool search(Matrix p,ComplexInteger c);
		
};

Matrix Matrix::operator +(ComplexInteger k)
{
	Matrix res(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			res.matrix[i][j].set_real(matrix[i][j].get_real()+k.get_real());
				res.matrix[i][j].set_img(matrix[i][j].get_img()+k.get_img());
		}
	}
	return res;
}
Matrix Matrix::operator +(Matrix k)
{
	Matrix res(m,n);
	if(m==k.m&&n==k.n){
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			res.matrix[i][j].set_real(matrix[i][j].get_real()+k.matrix[i][j].get_real());
				res.matrix[i][j].set_img(matrix[i][j].get_img()+k.matrix[i][j].get_img());
		}
	}
}
else
{
	cout<<"Not possible\n";
}
	return res;
}

Matrix Matrix::operator -(ComplexInteger k)
{
	Matrix res(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			res.matrix[i][j].set_real(matrix[i][j].get_real()-k.get_real());
				res.matrix[i][j].set_img(matrix[i][j].get_img()-k.get_img());
		}
	}
	return res;
}
Matrix Matrix::operator -(Matrix k)
{
	Matrix res(m,n);
	if(m==k.m&&n==k.n){
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			res.matrix[i][j].set_real(matrix[i][j].get_real()-k.matrix[i][j].get_real());
				res.matrix[i][j].set_img(matrix[i][j].get_img()-k.matrix[i][j].get_img());
		}
	}
}
else
{
	cout<<"Not possible\n";
}
	return res;
}

Matrix  Matrix::operator ^(int x)
{
	int i,j,k=0;
//	Matrix  res(m,n);
	i=x/n;
	j=x%n;
		this->matrix[i][j].set_real(0);
		this->matrix[i][j].set_img(0);
/*	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			k=k+1;
			cout<<k<<endl;
		
			if(k==x)
			{
				res.matrix[i][j].set_real(0.0);
				res.matrix[i][j].set_img(0.0);
			//	res.matrix[i][j]=0;
				cout<<"dsa";
			}
			else
			{
				res.matrix[i][j].set_real(matrix[i][j].get_real());
				res.matrix[i][j].set_img(matrix[i][j].get_img());
				
			}
		}
	}*/
	
	//return res;
}

Matrix&  Matrix::operator =(Matrix p)
{
	//	Matrix res(p.m,p.n
	this->m=p.m;
	this->n=p.n;
		this->matrix= new ComplexInteger*[m]; 
     		 for (int i = 0; i < m; i++) 
			this->matrix[i] = new ComplexInteger[n];
		for(int i=0;i<p.m;i++)
		{
		 	for(int j=0;j<p.n;j++)
		 	{
		 		this->matrix[i][j]=p.matrix[i][j];
		 		//	matrix[i][j].set_img(p.matrix[i][j].get_img());
		 		//	cout<<"ew";
			}
		}
		return (*this);
}
/*

ComplexInteger** Matrix::operator =(Matrix p)
{
		int a; = p.m; 
      	int b= p.n; 
     	arr= new ComplexInteger*[a]; 
     	for (int i = 0; i < a; i++) 
			 arr[i] = new ComplexInteger[b];
		for(int i=0;i<a;i++)
		{
		 	for(int j=0;j<b;j++)
		 	{
		 		arr[i][j]=p.matrix[i][j];
			}
		}
		return arr;
}*/

Matrix  Matrix::operator *(Matrix p)
{
	int i,j;
		if(n==p.m)
		{
			Matrix  res(m,p.n);
			for(i=0;i<m;i++)
			{
				for(j=0;j<p.n;j++)
				{
					res.matrix[i][j] = 0;
	    			for(int k = 0; k < n; k++)
	    			{
	    				 //  res.matrix[i][j]=res.matrix[i][j]+matrix[i][k]* p.matrix[k][j]  ;
	    				   	res.matrix[i][j].set_real(res.matrix[i][j].get_real()+matrix[i][k].get_real()*(p.matrix[k][j].get_real())-matrix[i][k].get_img()*(p.matrix[k][j].get_img()));
							res.matrix[i][j].set_img(res.matrix[i][j].get_real()+matrix[i][k].get_img()*(p.matrix[k][j].get_real())+matrix[i][k].get_real()*(p.matrix[k][j].get_img()));
	    			}
				}
			}
			return res;
		}
		else
		{
			cout<<"cannot be multiplied"<<endl;
		}
}

Matrix  Matrix::operator *(ComplexInteger  p)
{
	Matrix res(m,n);
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			res.matrix[i][j].set_real(matrix[i][j].get_real()*(p.get_real())-matrix[i][j].get_img()*(p.get_img()));
				res.matrix[i][j].set_img(matrix[i][j].get_img()*(p.get_real())+matrix[i][j].get_real()*(p.get_img()));
		}
	}
	return res;
}

Matrix::input()
{
	cout<<"Enter the Matrix: "<<endl<<"Enter m and n :";
	cin>>m>>n;
	cout<<"Enter elements: "<<endl;
		matrix= new ComplexInteger*[m]; 
     		 for (int i = 0; i < m; i++) 
			 matrix[i] = new ComplexInteger[n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>matrix[i][j];
		}
	}
}

Matrix::display()
{
	cout<<"The Matrix is:-"<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}

bool Matrix::search(Matrix p,ComplexInteger c)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p.matrix[i][j].get_real()==c.get_real()&&p.matrix[i][j].get_img()==c.get_img())
			{
				return true;
			}
		}
	}
	return false;
}

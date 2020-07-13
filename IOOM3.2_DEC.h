class ComplexInteger;

class Matrix
{
	private: 
		ComplexInteger** mat;
		int rows;
		int cols;
		
		/* ALLOCATING SPACE TO THE MATRIX DYNAMICALLY */
		void AllocateMatrix();
		
	public :
		/* CONSTRUCTORS */
		Matrix( );
		Matrix( int num_rows , int num_cols , bool init ); /* init = false => VALUES READ FROM USER ;           */
		Matrix( const Matrix& m );                         /* init = true  => VALUES INITIALIZED TO ALL ZEROES. */
		
		/* GETTER AND SETTER METHODS */	
		int  GetNumRows() const;
		int  GetNumCols() const;
		void SetNumRows( int num_rows );
		void SetNumCols( int num_cols );
		
		/* OPERATOR OVERLOADED FUNCTIONS */
		Matrix operator + ( const Matrix m ) const;		
		Matrix operator - ( const Matrix m ) const;
		Matrix operator * ( const Matrix m ) const;
		Matrix operator = ( const Matrix m );
		Matrix operator + ( const ComplexInteger c ) const;		
		Matrix operator - ( const ComplexInteger c ) const;
		Matrix operator * ( const ComplexInteger c ) const;
		Matrix operator = ( const ComplexInteger* c_arr );		
		void   operator ^ ( int pos );		
		
		/* FRIEND FUNCTIONS */
		friend void DisplayInComplexFormat( const ComplexInteger c );
		friend void DisplayMatrixContents( const Matrix m );
		friend bool IsPresentInMatrix( const Matrix m, ComplexInteger c );
		
		/* DESTRUCTOR */
		~Matrix();
		
		friend class ComplexInteger;
};

class ComplexInteger
{
	private:
		float real;
		float img ;
	public :
		/* CONSTRUCTORS */
		ComplexInteger();                             /* DEFAULT CONSTRUCTOR */
		ComplexInteger( float r_val );                /* SINGLE PARAMETER CONSTRUCTOR */
		ComplexInteger( float r_val , float i_val );  /* TWO PARAMETER CONSTRUCTOR */
		ComplexInteger( const ComplexInteger& c );    /* COPY CONSTRUCTOR */
		
		/* GETTER AND SETTER METHODS */
		float GetReal() const;
		float GetImg () const;
		void SetReal( float r_val );
		void SetImg ( float i_val );
		
		/* OPERATOR OVERLOADING */
		ComplexInteger  operator +  ( const ComplexInteger& c ) const; /* HERE RETURN TYPE IS NOT A REFERENCE AS WE  */
		ComplexInteger  operator -  ( const ComplexInteger& c ) const; /* WANT TO IMPLICITLY CALL COPY CONSTRUCTOR   */
		ComplexInteger  operator *  ( const ComplexInteger& c ) const; /* TO AVOID PASSING STACK ADDRESS.            */
		ComplexInteger  operator =  ( const ComplexInteger& c );
				
		/* DESTRUCTOR */
		~ComplexInteger();
		
		/* DISPLAY FRIEND FUNCTION */
		friend void DisplayInComplexFormat( const ComplexInteger c );
		friend void DisplayMatrixContents( const Matrix m );
		friend bool IsPresentInMatrix( const Matrix m, ComplexInteger c );
};

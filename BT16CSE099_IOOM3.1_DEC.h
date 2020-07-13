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
		ComplexInteger operator +  ( const ComplexInteger& c ) const; /* HERE RETURN TYPE IS NOT A REFERENCE AS WE  */
		ComplexInteger operator -  ( const ComplexInteger& c ) const; /* WANT TO IMPLICITLY CALL COPY CONSTRUCTOR   */
		ComplexInteger operator *  ( const ComplexInteger& c ) const; /* TO AVOID PASSING STACK ADDRESS.            */
		ComplexInteger operator /  ( const ComplexInteger& c ) const; 
		ComplexInteger operator =  ( const ComplexInteger& c );
		ComplexInteger operator ++ ( int );
		ComplexInteger operator -- ( int );
				
		/* DESTRUCTOR */
		~ComplexInteger();
		
		/* DISPLAY FRIEND FUNCTION */
		friend void DisplayInComplexFormat( const ComplexInteger c );
};

//jan 10 '08
/*
	Internally in java all math functions
	are created inside the class called Math
	as static functions , so we should call
	Math.sqrt( n)
	Math.sin( n )
	Math.pow(a , b);	
	.	
	.
*/
	
	class pw
	{
	public static void main( String v[] )
	{
	int a = Integer.parseInt( v[0] );
	int b = Integer.parseInt( v[1] );

	int r = (int) Math.pow( a , b );
	System.out.println(r);
	}
	}

//jan 11 '08

	class split
	{
	public static void main( String v[] )
	{
	
	String m = v[0];

	int p = m.indexOf("@");

	String u = m.substring( 0 , p);
	String pr = m.substring( p+1 );

	System.out.println("Username " + u );
	System.out.println("Provider " + pr);
	}
	}

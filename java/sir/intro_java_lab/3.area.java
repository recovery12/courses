//jan 10 '08

	class area
	{
	public static void main( String v[ ])
	{
	
	if( v.length == 0 )
	System.out.println("Usage: java area <radius>");
	else
	{
		double rad = Double.parseDouble( v[0] );
		double area = 3.14 * rad * rad;
		System.out.println("Area = " + area );
	}	
	}
	}
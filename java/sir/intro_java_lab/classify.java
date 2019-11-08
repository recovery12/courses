//jan 11 '08
/*
	http://www.yahoo.com
	
	http://www.linux.edu

	http://www.cracks.st.us
*/

	class classify
	{
	public static void main(String v[])
	{

	String site = v[0];	

	int p = site.lastIndexOf(".");

	String f = site.substring(p + 1);
	
	if( f.equals("com"))
	System.out.println("Commerical site");
	else if( f.equals("edu"))
	System.out.println("Education site");
	else
	System.out.println("Different family");

	}
	}


/*	1 more logic:
	---------------------------------------

	String site = v[0];	

	String f [ ] = site.split(".");

	String family = f [ f.length - 1 ];
		
	if( family.equals("com"))
	System.out.println("Commerical site");
	.
	.
*/		

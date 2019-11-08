//jan 11 '08
	
	class vowels
	{
	public static void main( String v[ ])
	{
	String s = v[0].toLowerCase();
	
	int c = 0;
	
	for(int i=0; i<s.length(); i++)
	{
	 switch( s.charAt(i) )
	 {
	  case 'a':
	  case 'e':
	  case 'i':
	  case 'o':
	  case 'u': c++;
	}
	}
	System.out.println("Count of vowels = " + c);
	}
	}


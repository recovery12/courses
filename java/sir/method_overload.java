class Sample
{
	int multiply(int a,int b)
	{
		return a*b;
	}
	int multiply(int a)
	{
		return a*a;
	}
	String multiply(String a)
	{
		return a;
	}
}	
class Test
{
	public static void main(String args[])
	{
		Sample sl= new Sample();
		int a,c;
		String b;
		a=sl.multiply(2,3);
		b=sl.multiply("pavan");
		c=sl.multiply(2);
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
	}
}

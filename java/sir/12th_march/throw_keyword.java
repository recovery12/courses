import java.lang.*;
class Sample
{
	int a;
	void method()
	{
		try
		{
			throw new ArithmeticException("Exception occurs");
		}
		catch(ArithmeticException e)
		{
			System.out.println("inside method");
			throw e;
		}
	}
}
class Test
{
	public static void main(String args[])
	{
		Sample s=new Sample();
		try
		{
			s.method();
		}
		catch(ArithmeticException e)
		{
			System.out.println("inside main");
		}
	}
}

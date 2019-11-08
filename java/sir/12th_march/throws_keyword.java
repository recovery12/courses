import java.util.Scanner;
class Sample
{
	void method() throws ArithmeticException	
	{
		int a=100;
		Scanner scan=new Scanner(System.in);
		int b=scan.nextInt();
		int c;
		c=a/b;
		System.out.println("123");
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
			System.out.println("exception catched");
		}
	}
}

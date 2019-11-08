import java.lang.*;
import java.util.*;
class Sample
{
	public static void main(String args[])
	{
	int a,b;
	double c;
	String d="pavan";
	Scanner scan= new Scanner(System.in);
	a = scan.nextInt();
	b = scan.nextInt();
		c=a/b;
		a=Integer.parseInt(d);		
	catch(NumberFormatException E)
	{
	    System.out.println("string cannot be converted into string");
	}
	catch(ArithmeticException E)
	{
		System.out.println("exception is "+E);
	}
	catch(Exception E)
	{
		System.out.println("some other exception"+E);
	}
	
	finally
	{
		System.out.println("finally block accessed");
	}
	System.out.println("some sample");
	System.out.println(a);

	}
}

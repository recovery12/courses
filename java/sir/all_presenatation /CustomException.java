import java.util.Scanner;
class EigteenYearException extends Exception
{
	EigteenYearException(String s)
	{
		super(s);
	}
}
class ARatedMovie
{
	void checkAge(int age) throws EigteenYearException
	{
		if(age<18)
		{
			throw new EigteenYearException("not allowed to movie");
		}
		else
		{
			System.out.println("congratulations you are allowed and booked ticket");
		}
	}
}
class Test
{
	public static void main(String args[]) throws EigteenYearException
	{
		int a;
		ARatedMovie am=new ARatedMovie();
		Scanner scan=new Scanner(System.in);
		a=scan.nextInt();
		//try
		//{
			am.checkAge(a);
		//}
		//catch(EigteenYearException e)
		//{
		//	System.out.println("exception accured and handled");
	//	}
	}
}

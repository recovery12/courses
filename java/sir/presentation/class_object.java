import java.lang.*;
import java.util.Scanner;
class Sample
{	
	int t=10;
	int add(int a,int b)
	{
		return a+b;
	}
}
class Test
{
	public static void main(String args[])
	{
		int num;
		Sample sl = new Sample();
		Scanner scan= new Scanner(System.in);
		System.out.println("enter two numbers");
		int a=scan.nextInt();
		int b=scan.nextInt();
		num=sl.add(a,b);
		if(num==sl.t)
			System.out.println("sum equal to 10");
		else
			System.out.println("sum not equal to 10");
	}

}

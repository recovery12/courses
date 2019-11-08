import java.lang.*;
interface Sample
{
	int add(int num1,int num2);
	int multiply(int num1,int num2);
}
class Sample2 implements Sample
{
	public int add(int num1,int num2)
	{
		return num1+num2;
	}
	public int multiply(int num1,int num2)
	{
		return num1*num2;
	}
}
class Test
{
	public static void main(String args[])
	{
		Sample2 sl=new Sample2();
		int a=sl.add(2,3);
		int b=sl.multiply(2,3);
		System.out.println(a);
		System.out.println(b);
	}
}
 

import java.lang.*;
class Add
{
	Add(int a,int b)
	{
		System.out.println(a+b);
	}
	Add(int a,int b,int c)
	{
		System.out.println(a+b+c);
	}
	Add(Double a,Double b)
	{
		System.out.println(a+b);
	}
	Add(String a,String b)
	{
		 System.out.println(a+b);
	}
}
class Test
{
	public static void main(String args[])
	{
		Add ad = new Add(2.2,3.22);
		Add st= new Add("pavan","pankaj");
	}
}


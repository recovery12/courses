import java.lang.*;
class Complex
{
	int a,b;
	Complex(int a,int b)
	{
		this.a=a;
		this.b=b;
		System.out.println(a+"+i"+b);
	}
	Complex(Complex c)
	{
		a=c.a;
		b=c.b;
		System.out.println(a+"+i"+b);
	}
}
class Test
{
	public static void main(String args[])
	{
		Complex cl=new Complex(2,9);
		Complex cl1=new Complex(cl);
	}
}

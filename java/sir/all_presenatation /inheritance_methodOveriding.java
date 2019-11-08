/*inheritance and method overiding*/
import java.lang.*;
class ClassA
{
	int num1,num2;
	ClassA(int num1,int num2)
	{
		this.num1=num1;
		this.num2=num2;
	}
	int add()
	{
		return num1+num2;
	}
}
class ClassB extends ClassA
{
	int num3;
	ClassB(int num1,int num2,int num3)
	{
		super(num1,num2);
		this.num3=num3;
	}
	int multiply()
	{
		return num1*num2*num3;
	}
	int add()
	{
		int temp;
		temp=this.multiply();
		System.out.println("add method overrided");
		return num1+temp;
	}
}
class Test
{
	public static void main(String args[])
	{
		int result1,result2;
		ClassB cls = new ClassB(2,3,4);
		result1=cls.add();
		result2=cls.multiply();
		System.out.println(result1);
		System.out.println(result2);
	}
}

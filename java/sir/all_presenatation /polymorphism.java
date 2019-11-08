import java.lang.*;
class Car
{
	void speed()
	{
		System.out.println("can go more than 100kmph");
		System.out.println("superclass");
	}
}
class Maruthi800 extends Car
{
	void speed()
	{
		System.out.println("it is not safe to 100kmph");
		System.out.println("subclass");
	}
}
class Test
{
	public static void main(String args[])
	{
		Car cr=new Maruthi800();
		cr.speed();
	}
}

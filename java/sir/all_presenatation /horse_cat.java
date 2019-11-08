import java.lang.*;
class Animal
{
	void sound()
	{
		System.out.println("animal makes sound");
	}
}
class Cat extends Animal
{
	void sound()
	{
		System.out.println("meau");
	}
}
class Horse extends Animal
{
	void sound()
	{
		System.out.println("nehu");
	}
}
class Test
{
	public static void main(String args[])
	{
		Animal ct = new Animal();
		Animal hr = new Horse();
		ct.sound();
		hr.sound();
	}
}

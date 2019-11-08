import java.lang.*;
abstract class Shape
{
	abstract void calculateArea();
	abstract void display();

}
class Rectangle extends Shape
{
	int length,breadth,area;
	Rectangle(int length,int breadth)
	{
		this.length=length;
		this.breadth=breadth;
	}
	void calculateArea()
	{
		area=length*breadth;
	}
	void display()
	{
		System.out.println("area of rectangle"+area);
	}
}
class Circle extends Shape
{
	int radius;
	double area;
	Circle(int radius)
	{
		this.radius=radius;
	}
	void calculateArea()
	{
		area=3.14*radius*radius;
	}
	void display()
	{
		System.out.println("area of circle"+area);
	}
}
abstract class Triangle extends Shape
{
	int base,height; //taking right angle triangle
	double area;
	void calculateArea()
	{
		area=0.5*base*height;
	}
}
class Sample extends Triangle
{
	void display()
	{
	}
}
class Test
{
	public static void main(String args[])
	{
		Rectangle rc=new Rectangle(2,4);
		rc.calculateArea();
		rc.display();
		Circle cr=new Circle(2);
		cr.calculateArea();
		cr.display();
		Sample tr=new Sample();
		tr.calculateArea();
	}
}

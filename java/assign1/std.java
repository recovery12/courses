class Transcript
{
	int	marks;
	char	grade;

	Transcript( int marks, char grade)
	{
		this.marks = marks;
		this.grade = grade;
	}

	int getM()
	{
		return marks;
	}
	char getG()
	{
		return grade;
	}
}
class Student
{
	Transcript	a,b,c,d;

	Student(Transcript a)
	{
		this.a = a;
	}

	Student(Transcript a, Transcript b)
	{
		this.a = a;
		this.b = b;
	}
	Student(Transcript a, Transcript b,Transcript c)
	{
		this.a = a;
		this.b = b;
		this.c = c;
	}
	Student(Transcript a, Transcript b,Transcript c, Transcript d)
	{
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
	}

	void display()
	{
		if ( a != null )
			System.out.println("1.Marks	: "+a.getM()+"\tGrade	: "+a.getG());
		if ( b != null )
			System.out.println("2.Marks	: "+b.getM()+"\tGrade	: "+b.getG());
		if ( c != null )
			System.out.println("3.Marks	: "+c.getM()+"\tGrade	: "+c.getG());
		if ( d != null )
			System.out.println("4.Marks	: "+d.getM()+"\tGrade	: "+d.getG());

	}
}

class cls
{
	public static void main(String args[])
	{
		Transcript eng = new Transcript( 98, 'A' );
		Transcript math = new Transcript( 67, 'C' );
		Transcript sci = new Transcript( 75, 'B' );
		Transcript soc = new Transcript( 43, 'D' );

		Student radha = new Student(eng, math);
		Student bhajji = new Student(eng, math, sci, soc);
		Student brahmi = new Student(eng);


		System.out.println("\nStudent 1\n");
		radha.display();
		System.out.println("\nStudent 2\n");
		bhajji.display();
		System.out.println("\nStudent 3\n");
		brahmi.display();
	}
}

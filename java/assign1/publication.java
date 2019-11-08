import java.util.Scanner;

class publication
{
	public static void main(String[] args)
	{
		Book obj = new Book("Fountain Head",398 , 10, "Ayn Rand");

		obj.orderCopies();

		Magazine obm = new Magazine("Daily Express", 40, 45, "Dr. Rahul", 10);

		obm.adjustQty();
		obm.recvNewIssue();
	}
}

class Publication
{
	String  name;
	double  price;
	int     copies;

	Scanner input = new Scanner(System.in);

	Publication(String val1, double val2, int val3)
	{
		this.name = val1;
		this.price = val2;
		this.copies = val3;
	}

	public int sellCopy()
	{
		int        copy;

		System.out.print("Enter the no. of copies to sell	: ");
		copy = input.nextInt();
		return copy;
	}
}

class Book extends Publication
{
	private String      author;

	Scanner input = new Scanner(System.in);

	Book(String val1, double val2, int val3, String val4)
	{
		super(val1, val2, val3);
		this.author = val4;
	}

	public int orderCopies()
	{
		int        copy;

		System.out.print("Enter the no. of copies to order	: ");
		copy = input.nextInt();
		return copy;
	}
}

class Magazine extends Publication
{
	private String      currIssue;
	private int         orderQty;

	Scanner input = new Scanner(System.in);

	Magazine(String val1, double val2, int val3, String val4, int val5)
	{
		super(val1, val2, val3);
		this.currIssue = val4;
		this.orderQty = val5;
	}

	int adjustQty()
	{
		System.out.print("Enter the no. of copies to read	: ");
		orderQty = orderQty + input.nextInt();
		return orderQty;
	}

	void recvNewIssue()
	{
		System.out.println("Enter the Isuue	: ");
		currIssue = input.next();
	}
}

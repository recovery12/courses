
class BorrowedBook
{
	String	name, dueD;
	Reader	rd;

	BorrowedBook(String name,String dueD)
	{
		this.name = name;
		this.dueD = dueD;
	}
	BorrowedBook(String name, String dueD, Reader rd)
	{
		this.name = name;
		this.dueD = dueD;
		this.rd = rd;
	}	

	String getname()
	{
		return name;
	}


}
class Reader
{
	String		name;
	BorrowedBook[] books = new BorrowedBook[8];

	Reader( String name, BorrowedBook books[] )
	{
		this.books = books;
		this.name = name;
	}
	Reader( String name )
	{
		this.name = name;
	}
	void display()
	{
		int	i;
		
		System.out.println("Books Borrowed by "+ name +" : ");
		if ( books.length == 0 )
		{
			System.out.println("No Books");
			return;
		}
		for ( i = 0; i < books.length ; i++ )
		{
			System.out.println("Book"+(i+1)+" : " +books[i].getname());

		}
	}

}

class booklib
{
	public static void main(String[] args)
	{
		BorrowedBook b1 = new BorrowedBook( "Fountain Head", "21/04/19");
		BorrowedBook b2 = new BorrowedBook( "Naa Ishtam", "02/04/19");
		BorrowedBook b3 = new BorrowedBook( "Think and Grow Rich", "29/04/19");

		BorrowedBook books[] = {b1, b2, b3};

		Reader r1 = new Reader( "Ajay", books);
		r1.display();

	//	Reader r2 = new Reader("Kiran");
	//	r2.display();
		
//		BorrowedBook b4 = new BorrowedBook("Operational Reasearch", "30/04/19", r2);


	}
}



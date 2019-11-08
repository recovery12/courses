import java.lang.*;
class Book
{
	String ISBN;
	Book(String ISBN)
	{
		this.ISBN=ISBN;
	}
	String getISBN()
	{
		return ISBN;
	}
	public boolean equals(Book a)
	{
		System.out.println("equals method overrided");
		return ISBN.equals(a.getISBN());
	}
}
class Test
{
	public static void main(String args[])
	{
		Book edition1=new Book("srt234512");
		Book edition2=new Book("srt234512");
		if(edition1.equals(edition2))
			System.out.println("books are equal");
		else
			System.out.println("books not equal");
	}
}
	
		

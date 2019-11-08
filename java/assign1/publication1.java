package assign1;

import java.util.Scanner;

public class publication1
{
   public static void main(String[] args)
   {
      Scanner input = new Scanner(System.in);
      Book obj = new Book("Java", 24.98, 45, "Arjun");
      //Magazine obj1 = new Magazine("Swathi", 45.23, 54, "Java", 45);
      DiscMag obj2 = new DiscMag("Disc", 25.23, 54, "Maroon 5", 45);

      obj.displayDetails();
      obj2.displayDetails();
      System.exit(0);
   }
}

class Publication
{
   private String  name;
   private double  price;
   private int     copies = 0;

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

      System.out.print("Enter the no. of copies to be sold: ");
      copy = input.nextInt();
      return copy;
   }

   public void displayDetails()
   {
      System.out.println("Name of the book: "+name);
      System.out.println("Price of the book: "+price);
      System.out.println("copies of the book: "+copies);
   }
}

class Book extends Publication
{
   private int       copy;
   private String    author;

   Scanner input = new Scanner(System.in);

   Book(String val1, double val2, int val3, String val4)
   {
      super(val1, val2, val3);
      this.author = val4;
   }

   public int orderCopies()
   {
      System.out.print("Enter the no. of copies to be ordered: ");
      copy = input.nextInt();
      return copy;
   }

   public void displayDetails()
   {
      super.displayDetails();
      System.out.println("Author is "+author);
      System.out.println("No. of copies are: "+copy);
   }
}

class Magazine extends Publication
{
   private String      currIssue;
   private int         orderQty;
   private String      news = "";

   Scanner input = new Scanner(System.in);

   Magazine(String val1, double val2, int val3, String val4, int val5)
   {
      super(val1, val2, val3);
      this.currIssue = val4;
      this.orderQty = val5;
   }

   public int adjustQty()
   {
      System.out.print("Enter the no. of copies to be added: ");
      orderQty = orderQty + input.nextInt();
      return orderQty;
   }

   public void recvNewIssue()
   {

      System.out.println("What's the current news?");
      news = input.next();
   }

   public void displayDetails()
   {
      super.displayDetails();
      System.out.println("Ordered Quantity: "+orderQty);
      System.out.println("Current Issue is: "+currIssue);
      System.out.println("Recived New news is: "+news);
   }
}

class DiscMag extends Magazine
{
   DiscMag(String val1, double val2, int val3, String val4, int val5)
   {
      super(val1, val2, val3, val4, val5);
   }

   public void displayDetails()
   {
      super.displayDetails();
   }
}


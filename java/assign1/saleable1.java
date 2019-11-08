package assign1;

import java.util.Scanner;

public class saleable1
{
   public static void main(String[] args)
   {
      int       val;

      Book book = new Book("Anath");
      DiscMag mag = new DiscMag("Maroon5", 45);
      Ticket obj = new Ticket();
      CashTill obj1 = new CashTill();

      book.orderCopies();
      book.displayDetails();
      mag.displayDetails();
      val = obj.sellCopy();
      System.out.println("Total tickets sold: "+val);
      val = obj1.sellCopy();
      System.out.println("Total price to be paid is: "+val);
      System.exit(0);
   }
}

interface SaleableItem
{
   public int sellCopy();
}

abstract class Publication implements SaleableItem
{
   abstract void displayDetails();

   public int sellCopy()
   {
      System.out.println("No. of copies depends on book or magazine.");
      return 0;
   }
}

class Ticket implements SaleableItem
{
   private int       copy;

   Scanner input = new Scanner(System.in);

   public int sellCopy()
   {
      System.out.print("How many do tickets want for matniee? ");
      copy = input.nextInt();
      return copy;
   }
}

class CashTill implements SaleableItem
{
   private int       copy;

   Scanner input = new Scanner(System.in);

   public int sellCopy()
   {
      System.out.print("How to copies do you want? ");
      copy = input.nextInt();
      return copy*12;
   }
}

class Book extends Publication
{
   private int       copy = 0;
   private String    author;

   Scanner input = new Scanner(System.in);

   Book(String val4)
   {
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
      super.sellCopy();
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

   Magazine(String val4, int val5)
   {
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
      super.sellCopy();
      System.out.println("Ordered Quantity: "+orderQty);
      System.out.println("Current Issue is: "+currIssue);
      System.out.println("Recived New news is: "+news);
   }
}

class DiscMag extends Magazine
{
   DiscMag(String val4, int val5)
   {
      super(val4, val5);
   }

   public void displayDetails()
   {
      super.displayDetails();
   }
}


package assign1;

import java.util.Scanner;

public class saleable
{
   public static void main(String[] args)
   {
      int       val;

      Publication obj = new Publication("Java", 12.32, 32);
      CashTill obj1 = new CashTill();

      val = obj.sellCopy();
      System.out.println("No. of copies sold are: "+val);
      val = obj1.sellCopy();
      System.out.println("Total price to be paid is: "+val);
      System.exit(0);
   }
}

interface SaleableItem
{
   public int sellCopy();
}

class Publication implements SaleableItem
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

package assign1;

import java.util.*;

public class booklib
{
   public static void main(String[] args)
   {
      int         i;
      String      name;

      Scanner input = new Scanner(System.in);
      ArrayList<Reader> std = new ArrayList();

      for (i = 0; i < 3; i++)
      {
         System.out.print("Enter the name: ");
         name = input.next();
         Reader obj = new Reader(name);
         obj.setDetails();
         std.add(obj);
      }

      System.out.print("Enter the name to be checked: ");
      name = input.next();

      for (i = 0; i < 8; i++)
      {
         Reader obj = new Reader(name);
         obj = std.get(i);
         if (obj.checkName(name))
         {
            obj.displayDetails();
            return ;
         }
      }

      System.out.println("Reader not found.");
      System.exit(0);
   }
}

class Reader
{
   private int       i;
   private String    name;

   Scanner input = new Scanner(System.in);
   ArrayList<BorrowedBook> bbook = new ArrayList(8);

   Reader(String name)
   {
      this.name = name;
   }

   void setDetails()
   {
      int         copies;
      String      date;

      for (i = 0; i < 8; i++)
      {
         System.out.print("Enter the date: ");
         date = input.next();
         System.out.print("Enter the copies: ");
         copies = input.nextInt();
         BorrowedBook obj = new BorrowedBook(copies, date, name);
         bbook.add(obj);
      }
   }

   void displayDetails()
   {
      for (i = 0; i < 4; i++)
      {
         BorrowedBook obj = new BorrowedBook(i+1, "1/1/1970", "demo");
         obj = bbook.get(i);
         obj.displayDetails();
      }
   }

   boolean checkName(String cname)
   {
      return cname.equals(name);
   }
}

class BorrowedBook
{
   private int      copies;
   private String   date, rname;

   BorrowedBook(int copies, String date, String name)
   {
      this.rname = name;
      this.copies = copies;
      this.date = date;
   }

   Reader obj = new Reader(rname);
   public void displayDetails()
   {
      System.out.println("Copies are "+copies);
      System.out.println("Date is "+date);
   }
}

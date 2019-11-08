package lab8;

import java.util.Scanner;

public class shop
{
   public static void main(String[] args)
   {
      int        n = 0, choice = 0;
      int stock[] = new int[30];
      float price[] = new float[30];

      String item[] = new String[30];
      operations work = new operations();

      while (choice != 5)
      {
         choice = work.menu();
         if (choice >= 1 && choice <= 5)
         {
            switch (choice)
            {
               case 1:
                     System.out.println("Add a new item.");
                     n = work.addItem(item, n, stock, price);
                     break;
               case 2:
                     System.out.println("Show price list.");
                     work.listItem(item, n, stock, price);
                     break;
               case 3:
                     System.out.println("Sell an item.");
                     n = work.sellItem(item, n, stock, price);
                     break;
               case 4:
                     System.out.println("Choice an item.");
                     work.userItem(item);
                     break;
               case 5:
                     System.out.println("Thank you for shopping.");
                     System.out.println("Visit Again :-)");
                     return ;
            }
         }
         else
         {
            continue;
         }
      }

      return ;
   }
}

class operations
{
   public static int menu()
   {
      int           opt;

      Scanner input = new Scanner(System.in);

      System.out.println("\n###Welcome to Java Super-market###\nWhat can I do for You");
      System.out.println("Select from the below options: ");
      System.out.println("1) Add a new item.");
      System.out.println("2) Show the Price list.");
      System.out.println("3) Sell an item.");
      System.out.println("4) choose an item.");
      System.out.println("5) Exit.\n");

      System.out.println("Enter the option: ");
      opt = input.nextInt();

      return opt;
   }

   public static int addItem(String item[], int n, int stock[], float price[])
   {
      Scanner input = new Scanner(System.in);

      System.out.print("Enter the name of item: ");
      item[n] = input.next();
      System.out.print("Enter the stock of item: ");
      stock[n] = input.nextInt();
      System.out.print("Enter the price of item: ");
      price[n] = input.nextFloat();
      n++;

      return n;
   }

   public static void listItem(String item[], int n, int stock[], float price[])
   {
      int           i;

      System.out.println("##############################################");
      System.out.println("Item No.\tItem-name\tPrice\tQuantity(in stock)");
      System.out.println("##############################################");

      for (i = 0; i < n; i++)
      {
         System.out.println((i+1)+"\t"+item[i]+"\t"+price[i]+"\t"+stock[i]);
      }

      return ;
   }

   public static int sellItem(String item[], int n, int stock[], float price[])
   {
      int        opt, qty;

      Scanner input = new Scanner(System.in);

      System.out.println("Enter the item no.: ");
      opt = input.nextInt();
      System.out.println("Enter the quantity: ");
      qty = input.nextInt();

      if (qty > stock[opt-1])
      {
         System.out.println("Sorry for the inconvience, only "+stock[opt-1]+" items are left over ");
         stock[opt] = 0;
      }  
      else
      {
         stock[opt] -= qty;
      }  

      return n;
   }

   public static void userItem(String item[])
   {
      String      uitem;
      Scanner input = new Scanner(System.in);

      System.out.println("Enter the item-name which you are searching: ");
      uitem = input.next();

      for (String name: item)
      {
         if (name == uitem)
         {
            System.out.println(uitem+" is item available");
            return ;
         }
      }

      System.out.println(uitem+" is not available :-(");

      return ;
   }
}

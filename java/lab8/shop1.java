// package lab8;

import java.io.*;
import java.util.*;

public class shop1
{
   public static void main(String[] args)
   {
      int      choice, code;
      double   price;
      String   val1, val2, val3, fname;

      Scanner input = new Scanner(System.in);
      Menu obj1 = new Menu();
      ArrayList<ItemRecord> items = new ArrayList<ItemRecord>();

      System.out.print("Enter the input file-name: ");
      fname = input.next();
      ReadData obj = new ReadData(items, fname);

      try
      {
         obj.readFile();
      }
      catch (IOException e)
      {
         System.out.println(e);
      }
      catch (NegativePriceException e)
      {
         System.out.println(e);
      }
      catch (NumberFormatException e)
      {
         System.out.println(e);
      }
      catch (Exception e)
      {
         System.out.println(e);
      }

      while (true)
      {
         choice = obj1.display();
         switch (choice)
         {
            case 1:
                  System.out.print("Enter Item name: ");
                  val1 = input.next();
                  System.out.print("Enter Item code: ");
                  val2 = input.next();
                  System.out.print("Enter Item price: ");
                  val3 = input.next();
                  Operations obj2 = new Operations(val1, val2, val3);
                  ItemRecord nitem = new ItemRecord();
                  try
                  {
                     nitem = obj2.addItem();
                  }
                  catch (NegativePriceException e)
                  {
                     System.out.println(e);
                  }
                  items.add(nitem);
                  break;
            case 2:
                  System.out.print("Enter Item code: ");
                  code = input.nextInt();
                  System.out.print("Enter Item new-price: ");
                  price = input.nextDouble();
                  Operations obj3 = new Operations(code, price, items);
                  try
                  {
                     obj3.updatePrice();
                  }
                  catch (NegativePriceException e)
                  {
                     System.out.println(e);
                  }
                  break;
            case 3:
                  System.out.print("Enter Item code: ");
                  code = input.nextInt();
                  Operations obj4 = new Operations(code, items);
                  obj4.checkItem();
                  break;
            case 4:
                  Operations obj5 = new Operations(items);
                  System.out.println("==============================");
                  System.out.println(" Item-name  Item-code  Price  ");
                  System.out.println("==============================");
                  obj5.displayItems();
                  break;
         }
         if (choice == 5)
         {
            break;
         }
      }

      System.out.print("Enter the output file-name: ");
      fname = input.next();
      WriteData obj6 = new WriteData(items, fname);
      try
      {
         obj6.writeData();
      }
      catch (IOException e)
      {
         System.out.println(e);
      }

      System.exit(0);
   }
}

class ReadData
{
   String   fname;
   String[] data = new String[4];

   ItemRecord obj1 = new ItemRecord();
   ArrayList<ItemRecord> obj = new ArrayList<ItemRecord>();

   ReadData(ArrayList<ItemRecord> items, String fname)
   {
      this.fname = fname;
      this.obj = items;
   }

   public void readFile() throws IOException,NegativePriceException
   {
      int         i = 0;
      String[] arrstr = new String[3];
      BufferedReader reader = new BufferedReader(new FileReader(fname));
      String line = reader.readLine();

      System.out.println("Initial Data in the shop");
      System.out.println("==============================");
      System.out.println(" Item-name  Item-code  Price  ");
      System.out.println("==============================");
      while (line != null)
      {
         arrstr = line.split(" ", 5);
         ArrangeData obj2 = new ArrangeData(arrstr[0], arrstr[1], arrstr[2]);
         obj1 = obj2.check();
         obj.add(obj1);
         obj1.displayDetails();
         line = reader.readLine();
      }
      reader.close();
   }
}

class WriteData
{
   String       fname, str;

   ArrayList<ItemRecord> obj = new ArrayList<ItemRecord>();

   WriteData(ArrayList<ItemRecord> items, String fname)
   {
      this.fname = fname;
      this.obj = items;
   }

   public void writeData() throws IOException
   {
      FileWriter fw = new FileWriter(fname);

      fw.write("Item-name Itemcode price\n");
      for (ItemRecord item : obj)
      {
         str = item.returnString();
         fw.write(str);
      }
      fw.close();
   }
}

class ArrangeData
{
   int        i;
   ItemRecord obj = new ItemRecord();
   String val1, val2, val3;

   ArrangeData(String val1, String val2, String val3)
   {
      this.val1 = val1;
      this.val2 = val2;
      this.val3 = val3;
   }

   public ItemRecord check() throws NumberFormatException,NegativePriceException
   {
      int    i = Integer.parseInt(val2);
      double d = Double.parseDouble(val3);

      if (d < 0)
      {
         throw new NegativePriceException("Price can't be negative");
      }
      obj.setDetails(val1, i, d);
      return obj;
   }
}

class ItemRecord
{
   private String       name;
   private int          itemCode;
   private double       price;

   ItemRecord()
   {
      this.name = "";
      this.itemCode = -1;
      this.price = -1;
   }

   public void setDetails(String val1, int val2, double val3)
   {
      name = val1;
      itemCode = val2;
      price = val3;
   }

   public boolean checkItemCode(int code)
   {
      return itemCode == code;
   }

   public void changePrice(int code, double mprice)
   {
      if (itemCode == code)
      {
         price = mprice;
      }
   }

   public String returnString()
   {
      return name+" "+String.valueOf(itemCode)+" "+String.valueOf(price)+"\n";
   }

   public void displayDetails()
   {
      System.out.println(name+"\t"+"\t"+itemCode+"\t"+price);
   }
}

class Operations
{
   private int         code;
   private double      price;
   private String      val1, val2, val3;

   ArrayList<ItemRecord> obj = new ArrayList<ItemRecord>();

   Operations(String val1, String val2, String val3)
   {
      this.val1 = val1;
      this.val2 = val2;
      this.val3 = val3;
   }

   Operations(int val1, double val2, ArrayList<ItemRecord> items)
   {
      this.code = val1;
      this.price = val2;
      this.obj = items;
   }

   Operations(int val1, ArrayList<ItemRecord> items)
   {
      this.code = val1;
      this.obj = items;
   }

   Operations(ArrayList<ItemRecord> items)
   {
      this.obj = items;
   }

   public ItemRecord addItem() throws NegativePriceException
   {
      ItemRecord  item = new ItemRecord();
      ArrangeData obj1 = new ArrangeData(val1, val2, val3);

      item = obj1.check();
      return item;
   }

   public void checkItem()
   {
      for (ItemRecord entry : obj)
      {
         if (entry.checkItemCode(code))
         {
            System.out.println("Item with given item-code is present");
            return ;
         }
      }

      System.out.println("Item with given code is not present");
   }

   public void updatePrice() throws NegativePriceException
   {
      if (price < 0)
      {
         throw new NegativePriceException("Price can't be -ve");
      }

      for (ItemRecord entry : obj)
      {
         if (entry.checkItemCode(code))
         {
            entry.changePrice(code, price);
            return ;
         }
      }
      System.out.println("Item with given code is not present");
   }

   public void displayItems()
   {
      for (ItemRecord entry : obj)
      {
         entry.displayDetails();
      }
      System.out.println("==============================\n");
   }
}

class NegativePriceException extends Exception
{
   NegativePriceException(String s)
   {
      super(s);
   }
}

class Menu
{
   private int      opt;

   Scanner input = new Scanner(System.in);

   public int display()
   {
      System.out.println("1) Add an Item");
      System.out.println("2) Update the price");
      System.out.println("3) Check Item"); 
      System.out.println("4) Display Items");
      System.out.println("5) Exit the modifications");

      System.out.print("Enter your option: ");
      opt = input.nextInt();

      return opt;
   }
}

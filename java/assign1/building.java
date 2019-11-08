package assign1;

import java.util.Scanner;

public class building
{
   public static void main(String[] args)
   {
      RentCollector obj = new RentCollector();
      House obj1 = new House();

      obj.printBill();
      obj1.setDetails();
      obj1.displayDetails();

      System.exit(0);
   }
}

class Building
{
   private int          hours;
   private final double RATE = 1.25;
   private double       rent;

   Building(int val)
   {
      this.hours = val;
   }

   public double determineRent()
   {
      rent = RATE*hours;
      return rent;
   }
}

class RentCollector
{
   private int     hours;
   Scanner input = new Scanner(System.in);

   public void printBill()
   {
      System.out.print("Enter no. of hours of spent: ");
      hours = input.nextInt();

      Building obj = new Building(hours);
      System.out.println("Rent of the building is "+obj.determineRent());
   }
}

class House extends Building
{
   private String  hno;
   private String  name;
   Scanner input = new Scanner(System.in);

   House()
   {
      super(0);
   }

   public void setDetails()
   {
      System.out.print("Enter the House no: ");
      hno = input.next();

      System.out.print("Enter the House name: ");
      name = input.next();
   }

   public void displayDetails()
   {
      System.out.println("House no is "+hno);
      System.out.println("House name is "+name);
   }
}

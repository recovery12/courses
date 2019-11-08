// pacakage program

import java.util.Scanner;

class train
{
   private String     tname;
   private int        pnrno;

   train(String val1, int val2)
   {
      tname = val1;
      pnrno = val2;
   }

   public void displayDetails()
   {
      System.out.println("Train name is "+tname);
      System.out.println("Train number is "+pnrno);
   }
}

class passenger
{
   private String      pname;
   private int         age;

   passenger(String val1, int val2)
   {
      pname = val1;
      age = val2;
   }

   public void displayDetail1()
   {
      System.out.println("Passenger name is "+pname);
      System.out.println("Passenger age is "+age);
   }
}

public class aggregation
{
   public static void main(String[] args)
   {
      int        num;

      String     tname;
      Scanner input = new Scanner(System.in);

      System.out.print("Enter the train name: ");
      tname = input.next();

      System.out.print("Enter the train no: ");
      num = input.nextInt();

      train t = new train(tname, num);
      passenger p = new passenger(tname+" sue", num/159);

      t.displayDetails();
      p.displayDetail1();

      return ;
   }
}

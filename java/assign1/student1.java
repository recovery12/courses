package assign1;

import java.util.Scanner;

public class student1
{
   public static void main(String[] args)
   {
      int     opt;
      Scanner input = new Scanner(System.in);

      System.out.println("Which type of student are you?");
      System.out.println("1) PtStudent");
      System.out.println("2) FtStudent");
      opt = input.nextInt();

      if (opt == 1)
      {
         PtStudent obj = new PtStudent();
         Lecturer obj1 = new Lecturer();
         obj.printTimetable();
         obj.applyForJob();
         obj1.help(obj);
      }
      else if (opt == 2)
      {
         FtStudent obj = new FtStudent();
         Lecturer obj1 = new Lecturer();
         obj.printTimetable();
         obj.applyForLoan();
         obj1.help(obj);
      }
      else
      {
         System.out.println("Invalid option.");
      }
      System.exit(0);
   }
}

abstract class Student
{
   abstract void printTimetable();
}

class Lecturer
{
   private int opt;
   
   Scanner input = new Scanner(System.in);

   public void help(PtStudent std)
   {
      System.out.println("I can help him.");
      std.printTimetable();
   }

   public void help(FtStudent std)
   {
      System.out.println("I can help him.");
      std.printTimetable();
   }
}

class PtStudent extends Student
{
   double  sal;
   Scanner input = new Scanner(System.in);

   public void printTimetable()
   {
      System.out.println("----------------");
      System.out.println("  Time    Class ");
      System.out.println("----------------");
      System.out.println(" 8:30 A.M  COA  ");
      System.out.println(" 9:30 A.M  CBOT ");
      System.out.println(" 6:30 P.M  DSS  ");
   }

   public void applyForJob()
   {
      System.out.print("Enter the expected salaray: ");
      sal = input.nextDouble();

      if (sal < 500000)
      {
         System.out.println("There are 2 jobs for you");
      }
      else if (sal > 1000000)
      {
         System.out.println("There are no jobs for you");
      }
      else
      {
         System.out.println("There are 1 job for you");
      }
   }
}

class FtStudent extends Student
{
   double  loan;
   Scanner input = new Scanner(System.in);

   public void printTimetable()
   {
      System.out.println("-----------------");
      System.out.println("  Time    Class  ");
      System.out.println("-----------------");
      System.out.println(" 10:30 A.M  JAVA ");
      System.out.println(" 11:30 A.M  OOD  ");
      System.out.println(" 12:30 P.M  DSS  ");
      System.out.println(" 13:30 P.M  LUNCH");
      System.out.println(" 14:30 P.M  DFS  ");
      System.out.println(" 15:30 P.M  PY   ");
      System.out.println(" 16:30 P.M  DBMS ");
   }

   public void applyForLoan()
   {
      System.out.print("Enter the expected loan: ");
      loan = input.nextDouble();

      if (loan < 500000)
      {
         System.out.println("Rate of interest is 5.63%");
      }
      else if (loan > 1000000)
      {
         System.out.println("Rate of interest is 12.63%");
      }
      else
      {
         System.out.println("Rate of interest is 8.63%");
      }
   }
}

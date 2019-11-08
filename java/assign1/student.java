
import java.util.Scanner;

public class student
{
   public static void main(String[] args)
   {
      Student obj = new Student();
      obj.saveDetails();
      System.exit(0);
   }
}

class Student
{
   int        i;
   String     name;
   Scanner input = new Scanner(System.in);

   Transcript obj = new Transcript();
   Transcript transcript[] = {obj, obj, obj, obj, obj};

   public void saveDetails()
   {
      System.out.print("Enter the name of the student: ");
      name = input.next();

      for (i = 0; i < 5; i++)
      {
         transcript[i].setDetails();
      }
      for (i = 0; i < 5; i++)
      {
       transcript[i].displayDetails();
      }
   }
}

class Transcript
{
   private int      semno;
   private double   cgpa;

   Scanner input = new Scanner(System.in);

   Transcript()
   {
      this.semno = -1;
      this.cgpa = -1;
   }

   public void setDetails()
   {
      System.out.print("Enter the sem no: ");
      semno = input.nextInt();

      System.out.print("Enter the cgpa: ");
      cgpa = input.nextDouble();
   }

   public void displayDetails()
   {
      System.out.println("Semester no. "+semno);
      System.out.println("Cgpa: "+cgpa);
   }
}

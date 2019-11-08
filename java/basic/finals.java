//pacakge basic

class student
{
   static String         name;
   static int            age;

   student(String val1, int val2)
   {
      this.name = val1;
      this.age = val2;
   }

   public static void displayDetails()
   {
      System.out.println("Name of student is: "+name);
      System.out.println("His age is: "+age);
   }
}

class stu1 extends student
{
   private int         a;

   stu1(String val1, int val2)
   {
      super(val1, val2);
      a = 30;
   }

   public static void displayDetails()
   {
      System.out.println("name is ");
      System.out.println("age is ");
   }
}

public class finals
{
   public static void main(String[] args)
   {
      stu1 obj = new stu1("anurag", 20);
      stu1.displayDetails();

      return ;
   }
}

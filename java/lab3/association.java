// pacakge program

class company
{
   String      cname;
   double      profit;

   company()
   {
      cname = "no name";
      profit = 0.0;
   }

   company(String val1, double val2)
   {
      cname = val1;
      profit = val2;
   }

   public void displayMems()
   {
      System.out.println("Company name is "+cname);
      System.out.println("It's profit is "+profit);
   }
}

class person extends company
{
   private String      name;
   private int         age;
   private double      salary;
   private double      pprofit;

   person()
   {
      name = "no-name";
      age = 0;
      salary = 0.0;
   }

   person(String val1, int val2, float val3)
   {
      super("Unix", 260000);
      name = val1;
      age = val2;
      salary = val3;
      pprofit = super.profit/100;
   }

   public void displayAll()
   {
      System.out.println("Name is "+name);
      System.out.println("Age is "+age);
      System.out.println("Salary is "+salary);
      System.out.println("Person profit is "+pprofit);
   }
}

public class association
{
   public static void main(String[] args)
   {
      person obj1 = new person("Bob", 35, 40000);
      obj1.displayAll();
      
      return ;
   }
}

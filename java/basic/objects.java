//pacakge basic

public class objects
{
   public static void main(String[] args)
   {
      int       g;
      float[]   e = {2,3,4,1,3,4};
      String      a = new String("anurag");
      String      b = a.toString();
      long f, original = System.currentTimeMillis();

      while (true)
      {
         f = System.currentTimeMillis();
         if (f - original >= 5000)
         {
            break;
         }
      }

      Class c = e.getClass();
      System.out.println("The arguments of a is: "+b);
      System.out.println("The class of e is: "+c);
      /*try
      {
         public final void c.wait(2300);
      }
      catch(InterruptedException ex)
      {
         Thread.currentThread().interrupt();
      }*/

      g = a.hashCode();
      System.out.println("Bool of classes: "+e.equals(a));
      System.out.println("The hashcode of "+a+"is "+g);
      return ;
   }
}

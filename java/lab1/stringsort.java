//pacakge string

import java.util.Scanner;

public class stringsort
{
   /*public static void swap(String a, String b)
   {
      String       s;

      s = a;
      a = b;
      b = s;
   }*/

   public static void main(String[] args)
   {
      int        i, n;
      //String     tmp;

      Scanner input = new Scanner(System.in);
      String dict[] = new String[30];

      System.out.println("Enter total no. of strings: ");
      n = input.nextInt();

      System.out.println("Enter the strings: ");
      for (i = 0; i < n; i++)
      {
         dict[i]= input.next();
      }

      System.out.print("\nStrings which you have given: \n{");
      for (i = 0; i < n; i++)
      {
         System.out.print(dict[i]+",");
      }
      System.out.println("}\n");

      sortstring(n, dict);
      System.out.print("Strings in lexographical order: \n{");
      for (i = 0; i < n; i++)
      {
         System.out.print(dict[i]+",");
      }
      System.out.println("}");

      return ;
   }

   private static void sortstring(int n, String dict[])
   {
      int        i, j;
      String     tmp;

      for (i = 0; i < n; i++)
      {  
         for (j = 0; j < n-i-1; j++)
         {  
            if (dict[j].compareTo(dict[j+1]) > 0)
            {
               //swap(dict[j], dict[j+1]);
               tmp = dict[j];
               dict[j] = dict[j+1];
               dict[j+1] = tmp;
            }
         }
      }

      return ;
   }
}

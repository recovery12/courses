//package ppt;

import java.util.*;

public class arraylist
{
   public static void main(String[] args)
   {
      ArrayList lt = new ArrayList(5);

      lt.add('T');
      lt.add(5);
      lt.add(null);
      lt.add("Anurag");

      System.out.println("Elements in the list are "+lt);
      lt.remove(2);
      System.out.println("Elements in the list are "+lt);

      lt.add(1, "java.util.*");
      lt.add(1, "program using");
      lt.add(1, "is a");
      lt.add(1, "This");
      System.out.println("Elements in the list are "+lt);
      lt.set(2, "replaced value");
      System.out.println("Elements in the list are "+lt);

      /* Other methods
      object.get(int index)
      object.indexOf(Object o)
      object.lastIndexOf(Object o)
      ArrayList subList(int frontIndex, int toIndex) */
      System.exit(0);
   }
}

//package ppt;

import java.util.*;

public class linkedlist
{
   public static void main(String[] args)
   {
      int        i, val;

      LinkedList ll = new LinkedList();

      for (i = 0; i < 15; i++)
      {
         ll.addFirst(i);
      }

      System.out.println("Elements in linked-list are "+ll);
      for (i = 0; i < 7; i++)
      {
         val = (int) ll.removeFirst();
         System.out.println("Removed element is "+val);
      }
      System.out.println("First element is "+ll.getFirst());

      /* Other methods are
      ll.get(int index);
      ll.clear();
      ll.clone();
      ll.addLast(Object o);
      ll.getLast();
      ll.removeLast();
      */
   }
}

// package basic;

import java.io.*;

public class catjava
{
   public static void main(String args[])
   {
      if (args.length != 1)
      {
         System.err.println("Syntax: catjava <file-name>");
         System.exit(1);
      }

      CatContents cat = new CatContents(args[0]);

      try
      {
         cat.catFile();
      }
      catch (IOException e)
      {
         System.out.println(e);
      }
      catch (Exception e)
      {
         System.out.println(e);
      }


      System.exit(0);
   }
}

class CatContents
{
   private String     infile;

   CatContents(String inf)
   {
      this.infile = inf;
   }

   public void catFile() throws IOException
   {
      int            c;
      String         line;

      BufferedReader buffer = new BufferedReader(new FileReader(infile));
      line = buffer.readLine();

      while (line != null)
      {
         System.out.println(line);
         line = buffer.readLine();
      }
      buffer.close();
   }
}

// package basic;

import java.io.*;

public class cpjava
{
   public static void main(String args[])
   {
      if (args.length != 2)
      {
         System.err.println("Syntax: cpjava <source-file> <destination-file>");
         System.exit(1);
      }

      CopyContents cp = new CopyContents(args[0], args[1]);

      try
      {
         cp.copyFile();
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

class CopyContents
{
   private String     infile, outfile;

   CopyContents(String inf, String outf)
   {
      this.infile = inf;
      this.outfile = outf;
   }

   public void copyFile() throws IOException
   {
      int             c;

      FileInputStream in = new FileInputStream(infile);
      FileOutputStream out = new FileOutputStream(outfile);

      while ((c = in.read()) != -1)
      {
         out.write(c);
      }
      in.close();
      out.close();
   }
}

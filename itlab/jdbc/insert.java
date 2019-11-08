import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;

public class insert
{
   private static final String url = "jdbc:mysql://localhost";
   private static final String uname = "root";
   private static final String passwd = "Rag@1998";

   public static void main(String args[])
   {
      try
      {
         Connection con = DriverManager.getConnection(url, uname, passwd);
         System.out.println("Connection establised");

         Statement stmt = con.createStatement();
         String sql = "create database jdbc";
         stmt.executeUpdate(sql);
         System.out.println("Database Established");
      }
      catch (Exception e)
      {
         e.printStackTrace();
      }

      System.exit(0);
   }
}

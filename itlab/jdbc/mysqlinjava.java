import java.sql.*;

public class mysqlinjava
{
   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
   static final String JDBC_URL = "jdbc:mysql://localhost/";

   static final String UNAME = "root";
   static final String PASSWD = "Rag@1998";

   public static void main(String[] args)
   {
      try
      {
         Connection con = null;
         Statement stmt = null;

         Class.forName(JDBC_DRIVER);
         con = DriverManager.getConnection(JDBC_URL, UNAME, PASSWD);
         stmt = con.createStatement();

         String sql = "CREATE DATABASE itlab_minor";
         stmt.executeUpdate(sql);

         if (con != null)
         {
            con.close();
         }

         Class.forName(JDBC_DRIVER);
         con = DriverManager.getConnection(JDBC_URL+"itlab_minor", UNAME, PASSWD);
         stmt = con.createStatement();

         sql = "create table exam (title varchar(50) primary key)";
         stmt.executeUpdate(sql);
         sql = "insert into exam values (\"itlab\")";
         stmt.executeUpdate(sql);
         sql = "insert into exam values (\"itlab-minor\")";
         stmt.executeUpdate(sql);
         sql = "insert into exam values (\"itwlab\")";
         stmt.executeUpdate(sql);
      }
      catch (SQLException se)
      {
         se.printStackTrace();
      }
      catch (Exception e)
      {
         e.printStackTrace();
      }

      System.exit(0);
   }
}

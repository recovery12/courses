import java.io.*;
class CopyFileContents 
{

    	void copyFile() throws IOException 
	{  

		FileInputStream	in = new FileInputStream("Input.txt");
		FileOutputStream out = new FileOutputStream("Output.txt");
		int c;
         	while ((c = in.read()) != -1) 
	 	{
         		out.write(c);
         	}
		in.close();
		out.close();
   	}
}
class Test
{
	public static void main(String args[])
	{
		CopyFileContents cf=new CopyFileContents();
		try
		{
		cf.copyFile();
		}
		catch(IOException e)
		{
			System.out.println("exception occured");
		}
	}
}

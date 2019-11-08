import java.io.*;
class ReaderClass
{
	void read_method() throws IOException
	{	 
	Reader reader = new FileReader("Input.txt");
	int data = reader.read();
	System.out.println(data);
	while(data != -1)
	{
        	char dataChar = (char) data;
        	data = reader.read();
    		System.out.println(dataChar);
	}
	reader.close();
	}
}
class WriterClass
{
	void write_method() throws IOException
	{
	Writer writer = new FileWriter("Input.txt");
	writer.write("this is sample java program for Readers and writers");
	writer.close();
	}
}
class Test
{
	public static void main(String args[])
	{
	    //ReaderClass rd=new ReaderClass();
		try
		{
		    //rd.read_method();
		WriterClass wt=new WriterClass();
		wt.write_method();
		}
		catch(IOException i)
		{
			System.out.println("Exception occured");
		}
		
	}
}


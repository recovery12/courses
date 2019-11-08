import java.awt.*;        
import java.awt.event.*;  
import javax.swing.*;     
import java.util.*;
import javax.swing.border.*;
 

public class Sudoku extends JFrame
{
	public static final int GRID_SIZE = 9;    
	public static final int SUBGRID_SIZE = 3;
 

	public static final int CELL_SIZE = 60;  
	public static final int CANVAS_WIDTH  = CELL_SIZE * GRID_SIZE;
	public static final int CANVAS_HEIGHT = CELL_SIZE * GRID_SIZE;
	                                            
	public static final Color OPEN_CELL_BGCOLOR = Color.WHITE;
	public static final Color OPEN_CELL_TEXT_YES = new Color(0, 255, 0); 
	public static final Color OPEN_CELL_TEXT_NO = Color.RED;
	public static final Color CLOSED_CELL_BGCOLOR = new Color(173,216,230);
	public static final Color CLOSED_CELL_TEXT = Color.BLACK;
	public static final Font FONT_NUMBERS = new Font("Monospaced", Font.BOLD, 20);
	
	
	public static final Border cdivider = BorderFactory.createMatteBorder(1,1,1,5,Color.BLACK);
	public static final Border rdivider = BorderFactory.createMatteBorder(1,1,5,1,Color.BLACK);
	public static final Border mdivider = BorderFactory.createMatteBorder(1,1,5,5,Color.BLACK);
	public static final Border cborder =  BorderFactory.createMatteBorder(1,1,1,1,Color.BLACK);
	 
	 
	private static JTextField[][] tfCells = new JTextField[GRID_SIZE][GRID_SIZE];
	 
	   
	static int[] domain = {9,2,7,6,5,1,3,8,4};
	static int n = 9;
	static int[][] puzzle = new int[n][n];


	/*public static int[][] puzzle=
	
	
		 {{5, 3, 4, 6, 7, 8, 9, 1, 2},
	       {6, 7, 2, 1, 9, 5, 3, 4, 8},
	       {1, 9, 8, 3, 4, 2, 5, 6, 7},
	       {8, 5, 9, 7, 6, 1, 4, 2, 3},
	       {4, 2, 6, 8, 5, 3, 7, 9, 1},
	       {7, 1, 3, 9, 2, 4, 8, 5, 6},
	       {9, 6, 1, 5, 3, 7, 2, 8, 4},
	       {2, 8, 7, 4, 1, 9, 6, 3, 5},
	       {3, 4, 5, 2, 8, 6, 1, 7, 9}};
	   // For testing, open only 2 cells.*/
		
	private static boolean[][] masks =
	      {{false, false, false, false, false, false, false, false, false},
	       {false, false, false, false, false, false, false, false, false},
	       {false, false, false, false, false, false, false, false, false},
	       {false, false, false, false, false, false, false, false, false},
	       {false, false, false, false, false, false, false, false, false},
	       {false, false, false, false, false, false, false, false, false},
	       {false, false, false, false, false, false, false, false, false},
	       {false, false, false, false, false, false, false, false, false},
	       {false, false, false, false, false, false, false, false, false}};
		
	
	public Sudoku()
	{
		initi();
		randomize();
		
		generateMaps(0,0);

		setMasks();
		Container cp = getContentPane();
		Graphics g = getGraphics();
		cp.setLayout(new GridLayout(GRID_SIZE , GRID_SIZE ));  
 	

		InputListener listener = new InputListener();

     

		for (int row = 0; row < GRID_SIZE; ++row) 
		{
			for (int col = 0; col < GRID_SIZE; ++col) 
			{
				tfCells[row][col] = new JTextField(); 
				cp.add(tfCells[row][col]);       
				if (masks[row][col]) 
				{
					tfCells[row][col].setText("");   
					tfCells[row][col].setEditable(true);
					tfCells[row][col].setBackground(OPEN_CELL_BGCOLOR);
					tfCells[row][col].addKeyListener(listener);
				}
				else
				{
					tfCells[row][col].setText(puzzle[row][col] + "");
					tfCells[row][col].setEditable(false);
					tfCells[row][col].setBackground(CLOSED_CELL_BGCOLOR);
					tfCells[row][col].setForeground(CLOSED_CELL_TEXT);
				}
				            
				tfCells[row][col].setHorizontalAlignment(JTextField.CENTER);
				tfCells[row][col].setFont(FONT_NUMBERS);
				tfCells[row][col].setBorder(cborder);
		
				if(col == 2 || col == 5)
				{
					tfCells[row][col].setBorder(cdivider);
				}
				if(row == 2 || row == 5)
				{
					tfCells[row][col].setBorder(rdivider);
				}
				if((row == 2 && col == 2) || (row == 5 && col == 5) || (row == 2 && col == 5 ) || (row == 5 && col == 2))
				{
				tfCells[row][col].setBorder(mdivider);
				}
			}
	
		}

		cp.setPreferredSize(new Dimension(CANVAS_WIDTH + 100, CANVAS_HEIGHT + 100));
		pack();
	
	
 
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
		setTitle("Sudoku");
		setVisible(true);
	}

	public class InputListener implements KeyListener
	{
		int flag1 = 1; 
		public void keyTyped(KeyEvent e)
		{}
		public void keyPressed(KeyEvent e)
		{
			int rowselector = -1;
			int columnselector = -1;
			JTextField source = (JTextField)e.getSource();
			boolean found = false;
			for(int i = 0; i < n && !found; i++)
			{
				for(int j = 0; j < n && !found; j++)
				{
					if(source == tfCells[i][j])
					{
						rowselector = i;
						columnselector = j;
						found = true;
					}
				}
			}
			tfCells[rowselector][columnselector].setText("00");
			
			
		}
		public void keyReleased(KeyEvent e)
		{
			
			
			int rowselector = -1;
			int columnselector = -1;
			JTextField source = (JTextField)e.getSource();
			boolean found = false;
			for(int i = 0; i < n && !found; i++)
			{
				for(int j = 0; j < n && !found; j++)
				{
					if(source == tfCells[i][j])
					{
						rowselector = i;
						columnselector = j;
						found = true;
					}
				}
			}
						
			if(tfCells[rowselector][columnselector].getText() != "")
			{
				int num = Integer.parseInt(tfCells[rowselector][columnselector].getText());
				if(num == puzzle[rowselector][columnselector])
				{
					//tfCells[rowselector][columnselector].setBackground(OPEN_CELL_TEXT_YES);
					masks[rowselector][columnselector] = false;
				}
				else
				{
					//tfCells[rowselector][columnselector].setBackground(OPEN_CELL_TEXT_NO);
				}
	
				int flag = 0;
				for(int i = 0; i < n; i++)
				{
					for(int j = 0; j < n ; j++)
					{
						if(masks[i][j] == true)
						{
							flag = 1;
							return;
						}
					}
				}
				if(flag == 0)
				{
					JOptionPane.showMessageDialog(null,"You Won!");
					randomize();
					generateMaps(1,0);
					setMasks();
					Cards z = new Cards();
					Cards.createAndShowGUI();
				}
				
			}
		}
		
	}

	public static void initi()
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				puzzle[i][j] = 0;
			}
		}
	}

	public static void randomize()
	{
		Random rand = new Random();
		int i = 100;
		int j;
		while(i != 0)
		{
			int rand_int1 = rand.nextInt(n);
			int rand_int2 = rand.nextInt(n);
					
			//swap(rand_int1,rand_int2);
			int temp;
			temp = domain[rand_int1];
			domain[rand_int1] = domain[rand_int2];
			domain[rand_int2] = temp;
			i--;
		}
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n ; j++)
			{
				puzzle[i][j] = 0;
				if(i == 0)
				{
					puzzle[i][j] = domain[j];
				}
	
			}
		}  
	}
	
	
	
	 
	
	
	public static void setMasks()
	{
		Random rand = new Random();
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int rand_int1 = rand.nextInt(2);
				if(rand_int1 == 1)
				{
					masks[i][j] = true;
				}
				else
				{
					masks[i][j] = false;
				}
					
			}
		}
	}
	
	
	public static int generateMaps(int p, int q)
	{
	
			int i;
			int k;
			int ret = 1;
			int flag = 1;
			int quad1 = -1;
			int quad2 = -1;
	
	
			if(p > -1 && p < 3)
			{
				quad1 = 0;
			}
			else if(p > 2 && p < 6)
			{
				quad1 = 3;
			}
			else if(p > 5 && p < 9)
			{
				quad1 = 6;
			}
	
			if(q > -1 && q < 3)
			{
				quad2 = 0;
			}
			else if(q > 2 && q < 6)
			{
				quad2 = 3;
			}
			else if(q > 5 && q < 9)
			{
				quad2 = 6;
			}
	
			for( i = 1; i < n+1; i++ )
			{
				if(ret == 1)
				{
					flag = 1;
		
					//System.out.println("grid location is" + p + "," + q);
				
					//puzzle[p][q] = i;
	
					//System.out.println("value is" + i);
				
					for( k = 0; k < n; k++)
					{
						if(i == puzzle[p][k] && k != q || i == puzzle[k][q] && k != p)
						{
							
							System.out.println("duplicate found in row or column");
							break;
						}
					}
	
					for(int x = quad1; x < quad1 + 3; x++)
					{
						for(int y = quad2 ; y < quad2 + 3; y++)
						{
							if( i == puzzle[x][y] )
							{
								if(p != x && q != y)
								{
									System.out.println("duplicate found in grid");
									flag = 0;
								}
							}
						}
					}
		
					
					if(k == n && flag == 1)
					{
						puzzle[p][q] = i;
													
	     
						
		
						if(q < n-1)
						{
							int temp2 = q;
							print();
							System.out.println();
							ret = generateMaps(p,++temp2);
							if(ret == 0)
							{
								return 0;
							}
							else if(ret == 1)
							{
								puzzle[p][q] = 0;
							}
						}
						else if(p < n-1)
						{
							int temp1 = p;
							print();
							System.out.println();
							ret = generateMaps(++temp1,0);
							if(ret == 0)
							return 0;
							else if(ret == 1)
							puzzle[p][q] = 0;
						}
						else
						{
									print();
								System.out.println();
							System.out.println("returned Successfully");
							return 0;
						}		
						
					}
						
				}	
			}
			if(puzzle[p][q] == 0)
			{
					print();
				System.out.println();
				//System.out.println("****returned with error****");
				return 1;
			}
	
			//System.out.println("returned Successfully");
					print();
			System.out.println();
			return 0;
			
		}
	
		public static void print()
		{
			for(int i = 0; i < n ; i++)
			{
				
				for(int j = 0; j < n ; j++)
				{
					System.out.print(puzzle[i][j] + " ");
				}
				System.out.println();
			}
		}
		public static void main(String[] args)
		{
			Sudoku m = new Sudoku();
			print();
			
		}
}		

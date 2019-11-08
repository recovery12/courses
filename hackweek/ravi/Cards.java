import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.util.*;
import javax.swing.*; 


public class Cards implements ActionListener
{
	private JPanel cards;
	private JButton button1;
	private JButton button2;
	private Image backgroundImage;
	public static JPanel card1;
	public static JFrame frame;
	
	public void addComponentToPane(Container pane)
	{
	        try
		{
			backgroundImage = ImageIO.read(new File("master-of-sudoku-logo.png"));
	        }
		catch (IOException ex) 
		{
			ex.printStackTrace(System.err);
	        }
		card1 = new JPanel()
		{
			@Override
			public void paintComponent(Graphics g)
			{
				super.paintComponent(g);
				g.drawImage(backgroundImage, 0, 0, null);
			}
			@Override
			public Dimension getPreferredSize()
			{
				return new Dimension(backgroundImage.getWidth(null),backgroundImage.getHeight(null));
			}
	        };
		JPanel card2 = new JPanel();
	        button1 = new JButton("Play");
		button1.setBounds(0,100,100,100);
		button1.setBackground(Color.BLACK);
	   	button1.setForeground(Color.GRAY);
	
	        button2 = new JButton("Button 2");
	        button1.addActionListener(this);
	        button2.addActionListener(this);
	        card1.add(button1);
	        card2.add(button2);

	        cards = new JPanel(new CardLayout());
	        cards.add(card1, "Card 1");
	        cards.add(card2, "Card 2");
	        pane.add(cards, BorderLayout.SOUTH);
		card1.setLayout(null);
	}
	public void itemStateChanged(ItemEvent evt)
	{
		CardLayout cl = (CardLayout) (cards.getLayout());
	        cl.show(cards, (String) evt.getItem());
	}
	public static void createAndShowGUI()
	{

	        frame = new JFrame("Frame");
	        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	        Cards main = new Cards();
	        main.addComponentToPane(frame.getContentPane());

	        frame.pack();
	        frame.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if (ae.getSource() == button1)
		{
			frame.setVisible(false);

			Sudoku m = new Sudoku();
	            
	        }
		else if (ae.getSource() == button2)
		{
			CardLayout cl = (CardLayout) (cards.getLayout());
			cl.show(cards, "Card 1");
	        }
	}
	public static void main(String[] args)
	{

		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				createAndShowGUI();
			}
		});
	}
}

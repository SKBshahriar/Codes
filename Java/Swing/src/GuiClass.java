/*import java.awt.Button;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Frame;

import javax.swing.*;

public class GuiClass {
	public static void main(String[] args)
	{
		JFrame f=new JFrame("My Frame");
		JButton b=new JButton("CLICK");
		JTextField tf=new JTextField(20);
		JFileChooser jf=new JFileChooser();
		Dimension d=new Dimension(new Dimension(70, 55));
		b.setPreferredSize(d);
		f.add(tf);
		f.add(b);
		f.add(jf);
		f.setSize(200, 300);
		f.setLayout(new FlowLayout());
		f.setVisible(true);
	}
	
}*/
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Panel;

import javax.swing.*;               
public class GuiClass {        
    public static void main (String[] args) {        
        JFrame frame = new JFrame();        
        String title = "Hello App"; 
        JButton b=new JButton("Click");
        JButton b1=new JButton("Click");
        JButton b2=new JButton("Click");
        JButton b3=new JButton("Click");
        JTextField t=new JTextField(5);
        JLabel l=new JLabel("Sakib");
        frame.add(b);
        frame.add(b1);
        frame.add(b2);
        frame.add(b3);
        frame.add(t);
        frame.add(l);
        frame.setTitle(title);       
        frame.setSize(200,300);
        frame.setLayout(new FlowLayout());
        frame.setDefaultCloseOperation        
            (JFrame.EXIT_ON_CLOSE);        
        frame.setVisible(true);        
        JPanel panle = new JPanel();
        panle.setSize(50, 80);
        panle.setLayout(new FlowLayout());
        frame.add(panle); 
       JLabel lable = new JLabel("Hello World!!!");
        panle.add(lable);
        JButton jb=new JButton("sakib");
        panle.add(b);
        //frame.add(jb);
        
    }
}

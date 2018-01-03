package ChatApplication;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.*;
import javax.swing.*;
public class Client {

	Socket sc=null;
	BufferedReader br=null;
	BufferedWriter bw=null;
	JTextArea textArea;
	Job messageReader;
	boolean connect;
	public Client(){
		


		JFrame frame=new JFrame("Client");
		JTextField textField=new JTextField(20);
		textArea=new JTextArea(10,30);
		
		
		/*JButton button2=new JButton("Disconnect");
		button2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(connect)
				{
					messageReader.stopThread();
					connect=false;
				}
				else
					JOptionPane.showMessageDialog(null, "Already disconnected");
				
			}
		});*/
		JButton button3=new JButton("Send");
		button3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				messageReader.send();
			}
		});
		
		
		JButton button1=new JButton("Connect");
		button1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(!connect)
				{
					messageReader=new Job(br,bw, textArea,sc,textField);
					Thread thread=new Thread(messageReader);
					thread.start();
					connect=true;
				}
				else
					JOptionPane.showMessageDialog(null, "Already connected");
			}
		});
		
		
		textArea.setEditable(false);
		frame.add(button1);
		frame.add(textField);
		frame.add(button3);
		frame.add(textArea);
		//frame.add(button2);
		frame.setSize(300, 600);
		frame.setLayout(new GridLayout(0, 1));
		frame.setVisible(true);

	}
	
}

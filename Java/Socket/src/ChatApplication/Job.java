package ChatApplication;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Job implements Runnable{

	BufferedReader br;
	BufferedWriter bw;
	JTextArea textArea;
	JTextField textField;
	boolean connect;
	boolean flg;
	Socket sc;
	ServerSocket ss;
	
	public Job(BufferedReader br,BufferedWriter bw,JTextArea textArea,Socket sc,JTextField textField) {
		this.br=br;
		this.textArea=textArea;
		this.sc=sc;
		this.bw=bw;
		this.textField=textField;
	}
	public Job(BufferedReader br,BufferedWriter bw,JTextArea textArea,Socket sc,JTextField textField,ServerSocket ss)
	{
		this(br, bw, textArea, sc,textField);
		this.ss=ss;
		flg=true;
		
	}
	public void run() {
		
		if(!connect)
		{
			try {
				if(flg)
				{
					ss=new ServerSocket(4017);
					sc=ss.accept();
				}
				else
					sc=new Socket("localhost",4017);
				br=new BufferedReader(new InputStreamReader(sc.getInputStream()));
				bw=new BufferedWriter(new OutputStreamWriter(sc.getOutputStream()));
				JOptionPane.showMessageDialog(null,"Connected");
				connect=true;
			} catch (UnknownHostException e1) {
				e1.printStackTrace();
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}
		String s="";
		try {
			s=br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		while(!s.equals("null") && connect)
		{
			try {
				textArea.setText(textArea.getText()+"\n"+s);
				s=br.readLine();
				System.out.print(s);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		/*try {
			br.close();
			sc.close();
			bw.close();
			if(ss!=null)
				ss.close();
			connect=false;
			JOptionPane.showMessageDialog(null, "Disconnected");
		} catch (IOException e1) {
			e1.printStackTrace();
		}*/
	}
	/*public  void stopThread()
	{
		
		send(true);
		send(true);
		connect=false;
	}*/
	public void send()
	{
		if(connect)
		{
			if(!textField.getText().equals(""))
			{
				try {
					//bw.flush();
					bw.write(textField.getText()+"\n");
					bw.flush();
					bw.newLine();
					//textField.setText("");
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
			else
				JOptionPane.showMessageDialog(null,"Type message first");
		}
		else
			JOptionPane.showMessageDialog(null,"Connect first");
	}
	/*public void send(boolean f)
	{
		try {
			bw.write("null");
			bw.flush();
			bw.newLine();
		} catch (IOException e1) {
			e1.printStackTrace();
		}
	}*/
}

package Assignment;
import java.io.*;
import java.net.*;
public class Job implements Runnable{
	
	BufferedReader br;
	Socket sc;
	boolean flg=true;
	public Job(BufferedReader br,Socket sc) {
		this.br=br;
		this.sc=sc;
		
	}
	
	public void run() {
		String string = null;
		try {
			string = br.readLine();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		while(string.equals(null))
		{
			try {
                System.out.println("msg from client: "+string);
                string=br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

}

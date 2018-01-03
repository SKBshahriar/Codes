package Assignment;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		
		try {
			ServerSocket serverSocket=new ServerSocket(3000);
			Socket socket=serverSocket.accept();
			BufferedReader bufferedReader=new BufferedReader(new InputStreamReader(socket.getInputStream()));
			BufferedWriter bufferedWriter=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
			Job job=new Job(bufferedReader, socket);
			Thread t=new Thread(job);
			System.out.println("Enter Message,or exit to exit writing");
			String s=scan.nextLine();
			t.start();
			while(!s.equals("stop"))
			{
				
				bufferedWriter.write(s);
				System.out.println("Enter Message,or exit to exit writing");
				s=scan.nextLine();
			}
			
			bufferedReader.close();
			bufferedWriter.close();
			serverSocket.close();
			socket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}

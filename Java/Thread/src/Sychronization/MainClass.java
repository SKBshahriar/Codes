package Sychronization;

import java.util.ArrayList;

public class MainClass {
	static BankAccount ba=new BankAccount(100000,"sakib");
	public static void main(String[] args) {
		ArrayList<Integer>list=new ArrayList<Integer>();
		int[] array=new int[100];
		/*Thread t1=new Thread(new Runnable() {

			public void run() {
				for(int i=0;i<10000;i++)
					synchronized (ba) {
						ba.withdraw(10);
					}

			}
		});
		Thread t2=new Thread(new Runnable() {
			public void run() {
				for(int i=0;i<10000;i++)
					synchronized (ba) {
						ba.diposit(10);
					}
			}
		});
		t1.start();
		t2.start();
		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		ba.balance();*/
		Thread t1=new Thread(new Runnable() {
			
			@Override
			public void run() {
				
				for(int i=0;i<100;i++)
					synchronized (array) {
						array[i]=i*2;
					}
					
			}
		});
		Thread t2=new Thread(new Runnable() {
			
			@Override
			public void run() {
				
				for(int i=0;i<100;i++)
					array[i]=i;
			}
		});
		
		t1.start();
		try {
			t1.sleep(1000);
		} catch (InterruptedException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		t2.start();
		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		for(int i=0;i<100;i++)
		{
			System.out.print(array[i]+" ");
		}
	}
}

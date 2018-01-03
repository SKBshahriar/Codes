import java.util.Scanner;

import javax.swing.JOptionPane;

public class BookStoreApp {

	public static void main(String[] args) {


		BookStore bs=new BookStore();
		bs.insertItem();
		Scanner scan =new Scanner(System.in);

        while(true)
        {
        	String op=JOptionPane.showInputDialog(null,"1-display\n2-sell\n3-order\n4-exit");
            int num=Integer.parseInt(op);
        	if(num==1) bs.display();

    		else if(num==3){
    			String str=JOptionPane.showInputDialog(null,"Enter ISBN");
    			String ISBN=str;
    			str=JOptionPane.showInputDialog(null,"Enter Number of Copies");
    			int noOfCopies=Integer.parseInt(str);
    			bs.order(ISBN, noOfCopies);
    		}
    		else if(num==2){
    			String str=JOptionPane.showInputDialog(null,"Enter Book Title");
    			String bookTitle=str;
    			str=JOptionPane.showInputDialog(null,"Enter Number of Copies");
    			int noOfCopies=Integer.parseInt(str);
    			bs.sell(bookTitle, noOfCopies);
    		}
    		else if(num==4)
    			System.exit(0);
        }

	}

}

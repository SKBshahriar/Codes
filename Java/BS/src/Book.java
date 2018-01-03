import javax.swing.JOptionPane;

public class Book {
	String bookTitle,author,ISBN;
	int noOfCopies;
	public Book(String bt,String athr,String isb,int num) {
		bookTitle=bt;
		author=athr;
		ISBN=isb;
		noOfCopies=num;
	}
	public void display(){
		JOptionPane.showMessageDialog(null,bookTitle+" - "+author+" - "+ISBN+" - "+noOfCopies );
		
	}
}

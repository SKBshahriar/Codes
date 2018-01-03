import java.awt.List;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class BookStore {
	
	
	
	ArrayList<Book> books=new ArrayList<Book>();
    void insertItem(){
        Book b1=new Book("Algorithm","Coreman","12345",15);
        Book b2=new Book("Discrete","Rosen","45678",10);
        books.add(b1);
        books.add(b2);
    }
	
	void sell(String bookTitle,int noOfCopies){
		int ind;
		for(ind=0;ind<books.size();ind++){
			if(books.get(ind).bookTitle.equals(bookTitle)) break;
		}
		if(ind==books.size()) System.out.println("Book not found");
		else{
			if(noOfCopies>books.get(ind).noOfCopies)
				System.out.println("Not enough copies");
			else{
				books.get(ind).noOfCopies-=noOfCopies;
				System.out.println("Done!");
			}
		}
	}
	
	void order(String ISBN,int noOfCopies){
		int ind;
		for(ind=0;ind<books.size();ind++){
			if(books.get(ind).ISBN.equals(ISBN)) {
				break;
			}
		}
		if(ind==books.size()){
			if(books.size()>=10)
				System.out.println("Limit Exceeded");
			else{
				JOptionPane.showMessageDialog(null, "Book is not in the store, new book will be added");
				
				String str=JOptionPane.showInputDialog(null,"Enter Book Title");
				String bookTitle=str;
				str=JOptionPane.showInputDialog(null,"Enter Author Name");
				String author=str;
				books.add(new Book(bookTitle, author, ISBN,noOfCopies));
				System.out.println("New book is added");
				
			}
		}
		else{
			books.get(ind).noOfCopies+=noOfCopies;
			System.out.println("Done!");
		}
	}
	
	void display(){
		for(int i=0;i<books.size();i++)
			books.get(i).display();
	}

}

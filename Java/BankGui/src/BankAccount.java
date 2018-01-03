import javax.swing.*;
import java.util.Random;
public class BankAccount {
    private String memberName, accountNumber;
    private double accountBalance, minimumBalance;

    public BankAccount(String n, double b, double minB){
        memberName = n;
        accountBalance = b;
        minimumBalance = minB;
        Random rand = new Random();
        accountNumber ="" + rand.nextInt(10) + rand.nextInt(10)+ rand.nextInt(10)+ rand.nextInt(10)+ rand.nextInt(10);
    }

    public void deposit(double amount)	{
        accountBalance += amount;
    }

    public void withdraw(double amount){
        if(accountBalance-amount>minimumBalance)
            accountBalance -= amount;
        else
            JOptionPane.showMessageDialog(null,"You do not have enough to withdraw");

    }

    public double getBalance() {
        return accountBalance;
    }

    public void display()
    {
        System.out.printf("Name:%s, Account Number:%s, Balance:%.2f\n", memberName, accountNumber, accountBalance);
    }

}
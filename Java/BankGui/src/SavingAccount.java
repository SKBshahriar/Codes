import javax.swing.*;

public class SavingAccount extends BankAccount{

    double interest,maxWithdrawLimit;

    public  SavingAccount(String memberName,double accountBalance,double maxWithdrawLimit)
    {
        super(memberName,accountBalance,2000);
        this.maxWithdrawLimit=maxWithdrawLimit;
    }


    public  SavingAccount(String memberName,double accountBalance,double maxWithdrawLimit,double minimumBalance)
    {
        super(memberName,accountBalance,minimumBalance);
        this.maxWithdrawLimit=maxWithdrawLimit;
    }

    public double getOriginalBalance()
    {
        return super.getBalance();
    }

    public double getBalance()
    {
        interest=(super.getBalance()*5)/100;
        return  super.getBalance()+interest;
    }

    public  void withdraw(double money)
    {

        if (money <= maxWithdrawLimit) super.withdraw(money);
        else JOptionPane.showMessageDialog(null, "Withdraw limit exceeded");
    }

}

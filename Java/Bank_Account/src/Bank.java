import javax.swing.JOptionPane;

public class Bank {

    public static void main(String[] args) {
        BankAccount account  = null;

        // Step 1: Create account
        // Ask user for the type of account he wants to create
        String msg = "Please Enter \n 1 to create Savings account\n 2 for Current BankAccount \n 3 or Student BankAccount.";
        String type = null;
        boolean isValidtype = false;
        do{
            type = JOptionPane.showInputDialog(msg);
            isValidtype = type.equals("1") || type.equals("2") || type.equals("3");
            msg = "Not a valid Option. /n Please enter 1 to create Savings account, 2 for Current BankAccount\n 3 or Student BankAccount.";
        }while(!isValidtype);

        // Enter info needed to create a specific type of account
        String name = JOptionPane.showInputDialog("Enter your name:");
        
        String initBalance = JOptionPane.showInputDialog("Enter your balance:");
        
        double balance = Double.parseDouble(initBalance);
        switch(type){
            case "1":  // Saving account
                while(balance < 2000){
                    initBalance = JOptionPane.showInputDialog("Enter your balance (minimum 2000 tk):");
                    balance = Double.parseDouble(initBalance);
                }

                double maxWithLimit = Double.parseDouble(JOptionPane.showInputDialog("Enter your maximum withdraw limit:"));
                account = new SavingAccount(name, balance, maxWithLimit);
                break;

            case "2": // Current account
                while(balance < 5000){
                    initBalance = JOptionPane.showInputDialog("Enter your balance (minimum 5000 tk):");
                    balance = Double.parseDouble(initBalance);
                }
                String trLncNum = JOptionPane.showInputDialog("Enter your trade License Number:");
                account = new CurrentAccount(name, balance, trLncNum);
                break;

            case "3": //Student account
                while(balance < 100){
                    initBalance = JOptionPane.showInputDialog("Enter your balance (minimum 100 tk):");
                    balance = Double.parseDouble(initBalance);
                }
                String univName = JOptionPane.showInputDialog("Enter your educational institution's name:");
                account = new StudentAccount(name, balance, univName);
                break;
        }

        // Step#2 do transactions
        msg = "Please enter what type of transaction you want to perform: \ndeposit(d), withdraw(w), check balance(c) or exit.";
        String trans = JOptionPane.showInputDialog(msg).replace(" ", "").toLowerCase();
        isValidtype = trans.equals("d") || trans.equals("w") || trans.equals("c");
        boolean wantToQuit = trans.equals("exit");
        Outer:
        while(!wantToQuit){ // loop until user enter "exit"
            while(!isValidtype) // loop until a valid option enter
            {
                String updMsg = "Not a valid Option. \n" + msg;
                trans = JOptionPane.showInputDialog(updMsg).replace(" ", "").toLowerCase();
                isValidtype = trans.equals("d") || trans.equals("w") || trans.equals("c");
                if (trans.equals("exit"))
                    break Outer; // Or System.exit(0);
            }

            double amt;
            String temp;
            double initialbalance=type.equals("2")?account.getBalance():((SavingAccount)account).getOriginalBalance();
            double newBalance;
            switch(trans){
                case "d": // deposit
                    temp = JOptionPane.showInputDialog("Enter the amount you want ot deposit:");
                    amt = Double.parseDouble(temp);
                    account.deposit(amt);
                    newBalance=type.equals("2")?account.getBalance():((SavingAccount)account).getOriginalBalance();
                    if(initialbalance != newBalance)
                        JOptionPane.showMessageDialog(null, String.format("Balance before deposit:%.2f, after deposit:%.2f\n", initialbalance, newBalance));
                    break;
                case "w": // withdraw
                    temp = JOptionPane.showInputDialog("Enter the amount you want ot withdraw:");
                    amt = Double.parseDouble(temp);
                    account.withdraw(amt);
                    newBalance=type.equals("2")?account.getBalance():((SavingAccount)account).getOriginalBalance();
                    if(initialbalance != newBalance)
                        JOptionPane.showMessageDialog(null, String.format("Balance before withdraw:%.2f, after withdraw:%.2f\n", initialbalance, newBalance));
                    break;
                case "c": // check balance
                    if (type.equals("2"))
                        JOptionPane.showMessageDialog(null, "Your balance:" + account.getBalance());
                    else
                        JOptionPane.showMessageDialog(null, "Your Balance:" + ((SavingAccount)account).getOriginalBalance() + " and Balance with interest:"+ String.format("%.2f", account.getBalance()));
                    break;
            }

            trans = JOptionPane.showInputDialog(msg).replace(" ", "").toLowerCase();
            isValidtype = trans.equals("d") || trans.equals("w") || trans.equals("c");
            wantToQuit = trans.equals("exit");
        }


    }

}
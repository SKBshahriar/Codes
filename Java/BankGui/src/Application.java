import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class Application {
    public static void main(String[] args) {
        Application application=new Application();
    }

    JLabel label1,label2,label3;

    JFrame frame=new JFrame("Banking System");

    BankAccount account  = null;


    Application()
    {
        frame.setLayout(new FlowLayout());

        frame.setSize(500,500);

        AccountTypePanel accountTypePanel=new AccountTypePanel();

        frame.setContentPane(accountTypePanel);

        frame.setVisible(true);



    }

    class AccountTypePanel extends JPanel{

        AccountTypePanel()
        {
            setSize(500,500);

            setLayout(null);

            JButton button1=new JButton("Saving Account");

            button1.setBounds(130,150,200,30);

            button1.addActionListener(new ActionListener() {

                public void actionPerformed(ActionEvent e) {
                    AccountCreatePanel accountCreatePanle =new AccountCreatePanel("saving");

                    setVisible(false);

                    frame.setContentPane(accountCreatePanle);
                }
            });

            JButton button2=new JButton("Current Account");

            button2.setBounds(130,220,200,30);

            button2.addActionListener(new ActionListener() {

                public void actionPerformed(ActionEvent e) {
                    AccountCreatePanel accountCreatePanle =new AccountCreatePanel("current");

                    setVisible(false);

                    frame.setContentPane(accountCreatePanle);
                }
            });

            JButton button3=new JButton("Student Account");

            button3.setBounds(130,290,200,30);

            button3.addActionListener(new ActionListener() {

                public void actionPerformed(ActionEvent e) {
                    AccountCreatePanel accountCreatePanle =new AccountCreatePanel("student");

                    setVisible(false);

                    frame.setContentPane(accountCreatePanle);
                }
            });

            add(button1);add(button2);add(button3);

            setVisible(true);
        }
    }

    class AccountCreatePanel extends JPanel{

        public AccountCreatePanel(String type)
        {
            if(type.equals("saving")){
                label1=new JLabel("Name");
                label2=new JLabel("Balance");
                label3=new JLabel("Max Withdraw limit");
            }

            else if(type.equals("current")){
                label1=new JLabel("Name");
                label2=new JLabel("Balance");
                label3=new JLabel("License Number");
            }

            else{
                label1=new JLabel("Name");
                label2=new JLabel("Balance");
                label3=new JLabel("Educational Institution");
            }

            setSize(500,500);

            setLayout(null);

            JTextField textField1=new JTextField();

            textField1.setBounds(80,150,300,30);



            JTextField textField2=new JTextField();

            textField2.setBounds(80,200,300,30);

            JTextField textField3=new JTextField();

            textField3.setBounds(80,250,300,30);

            JButton button =new JButton("Create");

            button.setBounds(180,300,100,25);

            button.addActionListener(new ActionListener() {

                public void actionPerformed(ActionEvent e) {
                    if(!textField1.getText().equals("") && !textField2.getText().equals("") && !textField3.getText().equals("")){

                        if(type.equals("saving")){

                            if(Double.parseDouble(textField2.getText())<2000)
                                JOptionPane.showMessageDialog(null,"Minimum ammount is 2000");
                            else {

                                account = new SavingAccount(textField1.getText(), Double.parseDouble(textField2.getText()), Double.parseDouble(textField3.getText()));

                                setVisible(false);
                                MainPanel mainPanel = new MainPanel("saving");
                                frame.setContentPane(mainPanel);
                            }

                        }

                        else if(type.equals("current")){

                            if(Double.parseDouble(textField2.getText())<5000)
                                JOptionPane.showMessageDialog(null,"Minimum ammount is 5000");
                            else {

                                account = new CurrentAccount(textField1.getText(), Double.parseDouble(textField2.getText()),textField3.getText());

                                setVisible(false);
                                MainPanel mainPanel = new MainPanel("current");
                                frame.setContentPane(mainPanel);
                            }

                        }

                        else{
                            if(Double.parseDouble(textField2.getText())<100)
                                JOptionPane.showMessageDialog(null,"Minimum ammount is 100");
                            else {

                                account = new CurrentAccount(textField1.getText(), Double.parseDouble(textField2.getText()),textField3.getText());

                                setVisible(false);
                                MainPanel mainPanel = new MainPanel("current");
                                frame.setContentPane(mainPanel);
                            }
                        }


                    }
                }
            });

            label1.setBounds(80,135,100,10);

            label2.setBounds(80,185,100,10);

            label3.setBounds(80,235,200,10);

            add(button); add(textField1); add(textField2); add(textField3);add(label1);add(label2);add(label3);

            setVisible(true);


        }




    }

    class MainPanel extends JPanel
    {
        MainPanel(String type)
        {
            setSize(400,400);

            setLayout(null);

            JTextField textField1=new JTextField();

            textField1.setBounds(80,150,150,30);

            JTextField textField2=new JTextField();

            textField2.setBounds(80,200,150,30);

            JButton button1=new JButton("Diposit");

            button1.setBounds(240,150,100,30);

            button1.addActionListener(new ActionListener() {

                public void actionPerformed(ActionEvent e) {

                    double initialbalance=type.equals("current")?account.getBalance():((SavingAccount)account).getOriginalBalance();

                    account.deposit(Double.parseDouble(textField1.getText()));

                    double newBalance=type.equals("current")?account.getBalance():((SavingAccount)account).getOriginalBalance();

                    if(initialbalance!=newBalance)
                        JOptionPane.showMessageDialog(null, String.format("Balance before deposit:%.2f, after deposit:%.2f\n", initialbalance, newBalance));
                }
            });

            JButton button2=new JButton("Withdraw");

            button2.setBounds(240,200,100,30);

            button2.addActionListener(new ActionListener() {

                public void actionPerformed(ActionEvent e) {


                    double initialbalance=type.equals("current")?account.getBalance():((SavingAccount)account).getOriginalBalance();

                    account.withdraw(Double.parseDouble(textField2.getText()));

                    double newBalance=type.equals("current")?account.getBalance():((SavingAccount)account).getOriginalBalance();

                    if(initialbalance!=newBalance)
                        JOptionPane.showMessageDialog(null, String.format("Balance before deposit:%.2f, after deposit:%.2f\n", initialbalance, newBalance));
                }
            });

            JButton button3=new JButton("Check");

            button3.addActionListener(new ActionListener() {

                public void actionPerformed(ActionEvent e) {
                    if (type.equals("current"))
                        JOptionPane.showMessageDialog(null, "Your balance:" + account.getBalance());
                    else
                        JOptionPane.showMessageDialog(null, "Your Balance:" + ((SavingAccount)account).getOriginalBalance() + " and Balance with interest:"+ String.format("%.2f", account.getBalance()));
                }
            });

            button3.setBounds(130,250,120,30);

            add(button1);add(button2);add(button3); add(textField1); add(textField2);

        }


    }
}

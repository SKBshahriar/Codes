public class StudentAccount extends SavingAccount{

    String institutionName;

    public  StudentAccount(String memberName,double accountBalance,String institutionName)
    {
        super(memberName,accountBalance,20000,100);
    }
}

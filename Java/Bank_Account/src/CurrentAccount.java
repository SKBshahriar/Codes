
public class CurrentAccount extends BankAccount{

    String tradeLicenseNumber;
    double mBalance=5000;
    public CurrentAccount(String memberName, double accountBalance, String tradeLicenseNumber)
    {
        super(memberName,accountBalance,5000);
        this.tradeLicenseNumber=tradeLicenseNumber;
    }
}

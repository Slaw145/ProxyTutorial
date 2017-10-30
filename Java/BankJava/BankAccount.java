package bankjava;

class BankAccount implements IPayment {
	
	private double StateMyAccount= 10000;
	 
    public double CheckStateAccount()
    {
        return StateMyAccount;
    }
 
    public void PayOutMoneyFromAccount(double AmountPayedOutMoney)
    {
        StateMyAccount = StateMyAccount - AmountPayedOutMoney;
    }
}

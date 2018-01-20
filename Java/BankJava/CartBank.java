package bankjava;

import java.util.Scanner;

class CartBank implements IPayment {
	
	IPayment BankAccount;
    private int PIN;
    public boolean IfPinIsValid;
 
    public void getPIN(int pin)
    {
        PIN = pin;
        CheckPinIsValid();
    }
 
    private void CheckPinIsValid()
    {
        if(PIN==1223)
        {
            OpenAccessToAccount();
            IfPinIsValid = true;
        }
        else
        {
            IfPinIsValid = false;
        }
    }
 
    private void OpenAccessToAccount()
    {
        PaymentFactory paymentfactory = new BankAccountFactory();
 
        BankAccount = paymentfactory.Bank();
    }
 
    public double CheckStateAccount()
    {
        return BankAccount.CheckStateAccount();
    }
 
    public void PayOutMoneyFromAccount(double AmountPayedOutMoney)
    {
        BankAccount.PayOutMoneyFromAccount(AmountPayedOutMoney);
    }
    
    public static void main(String[] args)
    {
        Scanner pin = new Scanner(System.in);
     
        CartBank cartbank = new CartBank();
        cartbank.getPIN(pin.nextInt());
     
        if (cartbank.IfPinIsValid)
        {
        	System.out.println("The correct pin has been entered, what do you want to do?");
        	System.out.println("Withdraw 4,000 USD from the bank");
            cartbank.PayOutMoneyFromAccount(4000);
            System.out.println("You have: "+cartbank.CheckStateAccount()+" USD left in your account");
        }
        else
        {
        	System.out.print("Incorrect pin entered, try again");
        }
        
        pin.close();
    }
}

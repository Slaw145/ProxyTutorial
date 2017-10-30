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
        	System.out.println("Wprowadzono poprawny pin, co chcesz zrobi�?");
        	System.out.println("Wyp�a� 4000z� z banku");
            cartbank.PayOutMoneyFromAccount(4000);
            System.out.println("na koncie zosta�o ci: "+cartbank.CheckStateAccount()+" z�");
        }
        else
        {
        	System.out.print("Wprowadzono niepoprawny pin, spr�buj jescze raz");
        }
        
        pin.close();
    }
}

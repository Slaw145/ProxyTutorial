package bankjava;

abstract class PaymentFactory {
	abstract IPayment Bank();
}

class BankAccountFactory extends PaymentFactory
{
	@Override
	public IPayment Bank()
	{
		return new BankAccount();
	}
}

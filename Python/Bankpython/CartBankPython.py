import abc

class IPayment(metaclass=abc.ABCMeta):

    @abc.abstractmethod
    def CheckStateAccount(self):
        pass

    @abc.abstractmethod
    def PayOutMoneyFromAccount(self,AmountPayedOutMoney):
        pass
 
class BankAccount(IPayment):

    StateMyAccount= 10000
 
    def CheckStateAccount(self):
        return self.StateMyAccount
 
    def PayOutMoneyFromAccount(self,AmountPayedOutMoney):
        self.StateMyAccount = self.StateMyAccount - AmountPayedOutMoney

class PaymentFactory(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def Bank(self):
        pass
 
class BankAccountFactory(PaymentFactory):
    def Bank(self):
        return BankAccount()

class CartBank(IPayment):

    def __init__(self):
        self.PIN = 0
        self.IfPinIsValid=False
 
    def getPIN(self,pin):
        self.PIN = pin
        self.CheckPinIsValid()
 
    def CheckPinIsValid(self):
        if(self.PIN=='1223'):
            self.OpenAccessToAccount()
            self.IfPinIsValid = True
        else:
            self.IfPinIsValid = False
 
    def OpenAccessToAccount(self):
        paymentfactory = BankAccountFactory()
        self.IPayment = paymentfactory.Bank()
 
    def CheckStateAccount(self):
        return self.IPayment.CheckStateAccount()
 
    def PayOutMoneyFromAccount(self,AmountPayedOutMoney):
        self.IPayment.PayOutMoneyFromAccount(AmountPayedOutMoney)

def main():

    pin = input()
 
    cartbank = CartBank()
    cartbank.getPIN(pin)
 
    if (cartbank.IfPinIsValid):
        print("Wprowadzono poprawny pin, co chcesz zrobić?")
        print("Wypłać 4000zł z banku")
        cartbank.PayOutMoneyFromAccount(4000)
        print("na koncie zostało ci: ",cartbank.CheckStateAccount()," zł")
    else:
        print("Wprowadzono niepoprawny pin, spróbuj jescze raz")

if __name__ == "__main__":
   main()

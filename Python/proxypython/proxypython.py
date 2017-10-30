import abc

class IExampleInterface(metaclass=abc.ABCMeta):
     @abc.abstractmethod
     def DoSomeThing(self):
        pass

class ExampleClass(IExampleInterface):
    def DoSomeThing(self):
        print("Do something")

class Proxy(IExampleInterface):

    def __init__(self,password):
        self.password = password
 
    def CreateInstanceExampleClass(self):
        self.exampleClass = ExampleClass()
 
    def DoSomeThing(self):
        if(self.password=="root"):
            self.CreateInstanceExampleClass()
            self.exampleClass.DoSomeThing()
        else:
            print("Wrong password")

def main():
    password=input()
 
    proxy = Proxy(password)
    proxy.DoSomeThing()

if __name__ == "__main__":
   main()
    
    
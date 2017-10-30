import java.util.Scanner;


public class Proxy implements ExampleInterface {
	
	 private ExampleInterface exampleClass;
	 private String password;
	 
	 public Proxy(String password)
	 {
	     this.password = password;
	 }
	 
	 private void CreateInstanceExampleClass()
	 {
	     exampleClass = new ExampleClass();
     }
	 
	  public void DoSomeThing()
	  {
	     if("root".equals(password))
	     {
	         CreateInstanceExampleClass();
	         exampleClass.DoSomeThing();
	     }
	     else
	     {
	    	 System.out.print("Wrong password");
	     }
	 }
	  public static void main(String[] args){
		  Scanner password = new Scanner(System.in);
		  
		  Proxy proxy = new Proxy(password.nextLine());
		  proxy.DoSomeThing();
		  
		  password.close();
	  }

}



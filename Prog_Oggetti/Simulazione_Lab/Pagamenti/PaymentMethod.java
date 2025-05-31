package Simulazione_Lab.Pagamenti;

public abstract class PaymentMethod{
	
	protected String ownerName;
	protected double balance;
	
	public PaymentMethod(String o, double b){
		ownerName = o;
		balance = b;
	}
	
	public String getOwnerName(){return ownerName;}
	public double getBalance(){return balance;}
	
	public void deposit(double amount) throws Exception{
		assert amount > 0 : "L' importo del deposito deve essere un numero positivo";
		balance += amount;
	}
	
	public abstract void pay(double amount);
	
	@Override
	public String toString(){
		return "Proprietario: "+ownerName+" bilancio: "+balance;
	}
  
}

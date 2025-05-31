package Simulazione_Lab.Pagamenti;

public class CreditCard extends PaymentMethod{
	
	private double creditLimit;

  public CreditCard(String o, double b){
    super(o,b);
  }
	
  @Override
	public void pay(double amount){
    assert balance+creditLimit >= amount : "Saldo insufficiente";
    balance -= amount;
  }
  
}

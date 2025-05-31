package Simulazione_Lab.Pagamenti;

public class BankTransfer extends PaymentMethod{
	

	public BankTransfer(String o, double b){
    super(o,b);
  }

	@Override
	public void pay(double amount){
		assert balance >= amount: "Fondi issuficenti";
		balance -= amount;
	}
  
}

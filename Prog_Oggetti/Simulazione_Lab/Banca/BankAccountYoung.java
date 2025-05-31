package Simulazione_Lab.Banca;

public class BankAccountYoung extends BankAccount{

  private double limit;
	
	public BankAccountYoung(String nome, double  liquidita, double limit){
		super(nome,liquidita);
		this.limit = limit;
  }

	public BankAccountYoung(String nome, double limit){
		super(nome);
		this.limit = limit;
	}
	
	@Override
	public void withdraw(double ritiro) throws Exception{
		if(ritiro > limit){
			throw new Exception("Il valore del ritiro è maggiore rispetto al limite imposto dal conto");
		}
		super.withdraw(ritiro);
	}
}

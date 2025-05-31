package Simulazione_Lab;

public class BankAccount {

  private static int counter = 0;
  private int id;
  private String nome;
  private double liquidita;

  // costruttori
  public BankAccount(String nome, double  liquidita){
    this.nome = nome;
    this.liquidita = liquidita;
    this.id = ++counter;
  }

  public BankAccount(String nome){
  this.nome = nome;
  this.liquidita = 0.0;
  this.id = ++counter;
}

	//getter e setter
	public String getNome(){return nome;}
	public double getLiquidita(){return liquidita;}
	public void setNome(String nome){this.nome = nome;}

	@Override
	public String toString(){
		return "Informazioni conto: nome Intestatario: "+nome+ " liquidità: "+liquidita+ " id conto: "+id;
	}
	
  @Override
	public boolean equals(Object obj){
    if(this == obj) return true;
    if(!(obj instanceof BankAccount)) return false;
    BankAccount other = (BankAccount) obj;
    return this.id == other.id &&
           this.nome.equals(other.nome) &&
           this.liquidita == other.getLiquidita();
}


	public void deposit(double deposito){
		assert deposito > 0;
		liquidita += deposito;
	}
	
	public void withdraw(double ritiro) throws Exception{
		assert ritiro > liquidita : "Il valore del ritiro è maggiore alla liquidità";
		assert ritiro <= 0 : "Il valore del ritiro deve essere positivo";
    liquidita -= ritiro;
	}
	
	public static int getNumAccounts(){
		return counter;
	}

}

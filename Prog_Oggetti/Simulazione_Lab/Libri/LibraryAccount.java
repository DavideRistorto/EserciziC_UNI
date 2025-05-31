package Simulazione_Lab.Libri;

public class LibraryAccount {
	
	private static int accountCounter = 0;
	private int id;
	private String nome;
	private int libriInPrestito;
	
	public LibraryAccount(String nome, int libriInPrestito){
		assert libriInPrestito >= 0 : "il numero di libri in prestito deve essere maggiore o uguale a 0";
		this.nome = nome;
		this.libriInPrestito = libriInPrestito;
		id = ++accountCounter;
	}
	
	public LibraryAccount(String nome){
		this.nome = nome;
		this.libriInPrestito = 0;
		id = ++accountCounter;
	}
	
	public String getNome(){return nome;}
	public int getLibriInPrestito(){return libriInPrestito;}
	public int getId(){return id;}
	public void setNome(String nome){this.nome = nome;}
	
	public void borrowBook(){
		libriInPrestito++;
	}
	
	public void returnBook(){
		assert libriInPrestito == 0: "Non c'è nessun libro da restituire";
		libriInPrestito--;
	}
	
	@Override
	public String toString(){
		return "Ciao";
	}
	
	@Override
	public boolean equals(Object obj){
		if(!(obj instanceof LibraryAccount)) return false;
		LibraryAccount temp = (LibraryAccount) obj;
		return id == obj.getId() && nome.equals(obj.getNome()) && libriInPrestito == obj.getLibriInPrestito();
	}
	
	public static int getTotalsAccounts(){
		return accountCounter;
	}
	
	
  
}

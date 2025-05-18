package Lezione_8.Es1;
public abstract class Elettrodomestico{

  private String modello;
  private int potenza;

  public Elettrodomestico(String modello, int potenza){
    this.modello = modello;
    this.potenza = potenza;
  }

  public abstract String funzionePrincipale();

  public void accendi(){
    System.out.println(modello + " accensione standard");
  }

  public void accendi(String modalita){
    System.out.println(modello + " accensione " + modalita);
  }

  @Override
  public String toString() {
      return "Lavatrice modello: " + modello + ", potenza: " + potenza + "W";
  }
  
}
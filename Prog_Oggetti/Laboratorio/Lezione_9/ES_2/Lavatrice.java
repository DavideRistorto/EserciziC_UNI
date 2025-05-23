package Lezione_9.ES_2;


public class Lavatrice extends Elettrodomestico{

  public Lavatrice(String modello, int potenza){
    super(modello, potenza);
  }

  @Override
  public String funzionePrincipale(){
    return "Lavaggio dei vestiti";
  }

  
}
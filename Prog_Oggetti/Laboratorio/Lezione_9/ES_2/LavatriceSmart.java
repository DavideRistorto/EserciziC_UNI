package Lezione_9.ES_2;

public class LavatriceSmart extends Lavatrice implements SmartControl{

  public LavatriceSmart(String modello, int potenza){
    super(modello, potenza);
  }

  @Override
   public void connettiRete(String reteWifi){
    accendi();
    System.out.println("connessa al WIFI " + reteWifi );
   }

   @Override
    public void aggiornaFirmware(){
    accendi();
    System.out.println("aggiornamento firmware");
    }
}

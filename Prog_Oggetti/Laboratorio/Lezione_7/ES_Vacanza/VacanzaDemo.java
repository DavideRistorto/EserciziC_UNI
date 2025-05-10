package Lezione_7.ES_Vacanza;

public class VacanzaDemo {
  public static void main(String[] args) {
    Data d11 = new Data(1,12,2025);
    Data d12 = new Data(10,12,2025);
    Vacanza v1 = new Vacanza("Roma",d11,d12);

    Data d21 = new Data(1,12,2025);
    Data d22 = new Data(10,12,2025);
    VacanzaInternazionale v2 = new VacanzaInternazionale("Londra",d21,d22,"Regno Unito");
    
    v1.aggiungiMezzo("treno");
    v1.aggiungiMezzo("metropolitano");
    
    v2.aggiungiMezzo("autobus");
    v2.aggiungiMezzo("aereo");
    v2.aggiungiMezzo("metropolitano");

    System.out.println(v1);
    System.out.println(v2);
    
    v2.rimuoviMezzo("bici");
    v2.rimuoviMezzo("autobus");
    v2.aggiungiMezzo("taxi");

    System.out.println("Vacanza a Londra modificata:");    
    System.out.println(v2);

    // per testare gli assert
    //Data d31 = new Data(364,2025);
    //Data d32 = new Data(7,2025);
    //Vacanza v3 = new Vacanza("Napoli",d31,d32);
    //System.out.println(v3);    
  }
}
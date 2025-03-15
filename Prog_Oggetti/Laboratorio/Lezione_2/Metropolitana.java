public class Metropolitana {

  private String matricola;
  private int linea;
  private int prossima_stazione;

  public Metropolitana(String matricola, int linea, int prossima_stazione){
    assert matricola != null;
    assert linea >= 0 && linea <= 9;
    assert prossima_stazione >= 0 && prossima_stazione <= 9;
    this.matricola = matricola;
    this.linea = linea;
    this.prossima_stazione = prossima_stazione;
  }

  public void aggiornaStazione(){
    prossima_stazione = (prossima_stazione + 1) % 10;
  }

  public int getProssimaStazione() {
    return prossima_stazione;
  }

  public void setProssimaStazione(int prossima_stazione) {
    assert prossima_stazione >= 0 && prossima_stazione <= 9;
    this.prossima_stazione = prossima_stazione;
  }

  public static void main(String[] args) {
    // Creazione dei due treni
    Metropolitana treno1 = new Metropolitana("T1", 1, 8);
    Metropolitana treno2 = new Metropolitana("T2", 1, 5);

    // Avanzamento di ciascun treno di due stazioni
    for (int i = 0; i < 2; i++) {
      treno1.aggiornaStazione();
      treno2.aggiornaStazione();
    }

    // Stampa delle nuove prossime stazioni
    System.out.println("Treno 1 prossima stazione: " + treno1.getProssimaStazione());
    System.out.println("Treno 2 prossima stazione: " + treno2.getProssimaStazione());
  }
}
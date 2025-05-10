package Lezione_7.ES_Vacanza;

import java.util.HashSet;
import java.util.Set;

public class Vacanza {

  private String luogo;
  private Data partenza;
  private Data ritorno;
  private Set<String> mezzi;

  public Vacanza(String luogo, Data partenza, Data ritorno) {
    assert partenza.differenza(ritorno) > 0;
    this.luogo = luogo;
    this.partenza = partenza;
    this.ritorno = ritorno;
    mezzi = new HashSet<String>();
  }

  // getters
  public String getLuogo() {return luogo;}
  public Data getPartenza() {return partenza;}
  public Data getRitorno() {return ritorno;}  
  public Set<String> getMezzi() {return mezzi;}
  //setter
  public void setLuogo(String luogo) {this.luogo = luogo;}
  public void setPartenza(Data partenza) {
    assert partenza.differenza(ritorno) > 0;
    this.partenza = partenza;
  }
  public void setRitorno(Data ritorno) {
    assert partenza.differenza(ritorno) > 0;
    this.ritorno = ritorno;
  }

  public int durata() {
    return partenza.differenza(ritorno);
  }

  public  void aggiungiMezzo(String mezzo) {
    mezzi.add(mezzo);
  }

  public void rimuoviMezzo(String mezzo) {
    if (mezzi.contains(mezzo)) {
      mezzi.remove(mezzo);
    } else {
      System.out.println("Il mezzo " + mezzo + " non è presente nella lista.");
    }
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("Luogo: ").append(luogo).append("\n");
    sb.append("Data di partenza: ").append(partenza).append("\n");
    sb.append("Data di ritorno: ").append(ritorno).append("\n");
    sb.append("Durata: ").append(durata()).append(" giorni\n");
    sb.append("Mezzi utilizzati: ").append(mezzi).append("\n");
    return sb.toString();
  }
}

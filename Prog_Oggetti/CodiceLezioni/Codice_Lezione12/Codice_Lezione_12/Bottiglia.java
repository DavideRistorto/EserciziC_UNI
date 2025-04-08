// Bottiglia.java
public class Bottiglia{
 // quantita' intere espresse in litri
 private int capacita; // 0 <= capacita
 private int livello;  // 0 <= livello <= capacita

 public Bottiglia(int capacita){
  this.capacita = capacita; 
  livello = 0;
  assert (0<=livello) && (livello <= capacita);
 }
    
  /* Aggiungiamo tutta la parte di una quantita' data che trova posto nella bottiglia e restituiamo la quantita effettivamente aggiunta. */
 public int aggiungi(int quantita){
    assert quantita >= 0;
    int aggiunta = Math.min(quantita, capacita-livello);
    livello = livello + aggiunta;
    assert (0<=livello) && (livello <= capacita);
    return aggiunta;
 }
    
 /* Rimuoviamo la quantita' richiesta se c'e', altrimenti togliamo tutto, restituiamo la quantita' effettivamente rimossa. */
  public int rimuovi(int quantita){
   assert quantita >= 0:   
  "la quantita' doveva essere >=0 invece vale " + quantita;
   int rimossa = Math.min(quantita, livello);
   livello = livello - rimossa;
   assert (0<=livello) && (livello <= capacita);
   return rimossa;
 }

  public int getCapacita(){ return this.capacita; }
  public int getLivello() { return this.livello; }
      
  public String toString() //conversione bottiglia --> stringa
  {return " " + livello + "/" + capacita;}
}

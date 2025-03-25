//Hacker.java (Vediamo come aggirare i divieti di scrittura)
public class Hacker {
  public static void main(String[] args){
   System.out.println("\n Definisco la coppia c con nomi Tramot e Galileo");
   CoppiaAnimali c = 
    new CoppiaAnimali("Tramot",3,5.0,"Galileo",2,4.0);
   System.out.println(c);
   System.out.println("\n Facciamo una getPrimo().");
   Animale t = c.getPrimo();
   System.out.println("Siccome getPrimo()-prima versione restituisce una copia dell'indirizzo possiamo ora modificare il campo primo di c tramite la variabile t (suo alias).");
   System.out.println("(Se invece usiamo la getPrimo()-versione che clona  non si puo' modificare il campo primo di c tramite la variabile t).");
   t.setNome("X"); 
   System.out.println( "\n Ora la coppia c vale \n" + c); 
   System.out.println( "Ovviamente l’oggetto puntato da t viene modificato in ogni caso." ); 
   System.out.println(t);
 }
}

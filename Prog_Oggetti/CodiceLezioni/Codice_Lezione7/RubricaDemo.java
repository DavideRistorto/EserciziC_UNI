//RubricaDemo.java
public class RubricaDemo {
  public static void main(String[] args){
  //Consentiamo 3 elementi in rubrica e proviamo a inserirne 4
   Rubrica R = new Rubrica(3);  
   System.out.println("(1) Rubrica con contatti a,b,c:" );
   R.aggiungi( "a", "a@ditta"); R.aggiungi( "b", "b@ditta");
   R.aggiungi( "c", "c@ditta"); R.aggiungi( "d", "d@ditta");
   System.out.println(R); 
   //vengono stampati a,b,c: l'aggiunta di d e' fallita
   System.out.println( "e-mail di c=" + R.cercaEmail( "c" ));
   System.out.println( "(2) Rimuovo a" );
   R.rimuovi( "a" ); System.out.println(R);
   System.out.println( "(3) Aggiungo b (ma c'e' gia'): successo = " 
  + R.aggiungi( "b", "e")); System.out.println(R);
   System.out.println( "(4) Modifico b in b2: successo = " 
  + R.cambiaNome( "b", "b2")); System.out.println(R);
   System.out.println( "(5) Modifico b@ditta in b2@ditta: successo = " + R.cambiaEmail( "b2", "b2@ditta")); System.out.println(R);
 }
}

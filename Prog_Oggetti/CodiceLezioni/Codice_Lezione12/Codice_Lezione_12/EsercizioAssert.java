//EsercizioAssert.java
public class EsercizioAssert {
 public static boolean metodo(int[][] a) {
  assert ok(a): "metodo(a) solleva eccezioni"; 
  //ok(a)=true se e solo se: metodo(a) non solleva eccezioni
  boolean ris=true;
  for (int i = 0; i < a.length; i++)
   for (int j = 0; j < a.length; j++)
    if (a[i][j] != a[j][i]) ris=false;
  return ris;
 }

/* a = array di array-riga di interi. Per esempio una riga di tre elementi, seguita da una riga di due, seguita da una riga di quattro:


a[0][0] a[0][1] a[0][2]
a[1][0] a[1][1] 
a[2][0] a[2][1] a[2][2] a[2][3]

(1) Il metodo(a) solleva un'eccezione se e solo se a=null o se per qualche riga a[i], o a[i]=null oppure a[i] ha lunghezza inferiore a r = ‘numero righe a’ = a.length. (2) Altrimenti metodo(a)= true se e solo se la matrice r x r nel lato sinistro di a e' simmetrica. 

Nel caso dell’esempio, il metodo ok() impedirebbe l’esecuzione del metodo metodo(), perché r=3 e la seconda riga è solo lunga 2. (a[1]=2<3) */

//Definiamo il metodo ausiliario ok(a) usato nell'assert
public static boolean ok(int[][] a)
{
  if (a==null) return false; 
  //se a=null allora a.length produce NullPointerException
  int r = a.length; int i=0;
  while(i<r)
  {
     if ((a[i]==null)||(a[i].length<r)) return false; 
     ++i;
  }
  //se a[i]=null allora a[i].length produce NullPointerException
  //se a[i]<r allora a[i][r-1] produce ArrayOutOfBoundException
  return true; //se nulla di cui sopra capita: ok(a)=true
 } 

 public static void main(String[] args)
 { 
  int[][] a=new int[3][]; 
  // a = { null, null, null}
  a[0]=new int[3]; a[1]=new int[4]; a[2]=new int[4];
  // a = { {0,0,0}, {0,0,0,0}, {0,0,0,0}}
  a[0][0]=1; a[0][1]=2; a[0][2]=3; a[1][0]=4; a[1][1]=5; a[1][2]=6;
  a[1][3]=7; a[2][0]=8; a[2][1]=9; a[2][2]=10; a[2][3]=11;
  // a = { {1,2,3}, {4,5,6,7}, {8,9,10,11}}
  System.out.println
   ( " ok(a) =     " + ok(a) +"\n metodo(a) = " + metodo(a));
  // ok(a)=true e metodo(a)=false perche': 
  // la matrice quadrata 3x3 nel lato sinistro di a non e' simmetrica

  int[][] b=new int[3][]; b[0]=new int[3]; b[1]=new int[2]; 
  b[2]=new int[4]; //b = {{0,0,0}, {0,0}, {0,0,0,0}}
  System.out.println( " ok(b) =     " + ok(b) );
  // ok(b)=false e metodo(b) solleva una eccezione se eseguiamo:
  // System.out.println( "metodo(b)=" + metodo(b));
  // perche': la seconda riga di b ha meno di 3 elementi 
 }
}   

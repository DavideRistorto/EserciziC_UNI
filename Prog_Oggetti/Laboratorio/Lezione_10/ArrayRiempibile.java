public class ArrayRiempibile {
  private int a;
  private int[] elementi;
  private boolean[] occupazione;

  public ArrayRiempibile(int lunghezza) {
    assert (lunghezza > 0):  "errore, lunghezza non positiva : " + lunghezza;
    if(lunghezza <= 0) {
      throw new IllegalArgumentException("errore, lunghezza non positiva : " + lunghezza);
    }
    elementi = new int[lunghezza];
    occupazione = new boolean[lunghezza];
  }

  public String toString() {
    String s = "elementi:\n";
    for (int i = 0; i < elementi.length; i++ )
      s = s + " " + elementi[i];
    s = s + "\nmodificato:\n";  
    for (int i = 0; i < elementi.length; i++ )
      s = s + " " + occupazione[i];
    return s;
  }

  public void inserire(int i, int v) {
    assert (i >=0) && (i < elementi.length):  "indice "  + i + " fuori limite";
    assert occupazione[i] == false:  "indice "  + i + " gia` occupata";
    elementi[i] = v;
    occupazione[i] = true;
  }

  public boolean controllarePieno() {
    int i = 0;
    boolean trovatoVuoto = false;
    while (i < elementi.length && !trovatoVuoto) {
      if (occupazione[i] == false)
        trovatoVuoto = true;
      i++;
    }
    return !trovatoVuoto;
  }

  public int calcolareSomma() {
    assert (this.controllarePieno()): "calcolare somma su un array non pieno non e` possibile";
    int somma = 0;
    for (int i = 0; i < elementi.length; i++ )
      somma += elementi[i];
    return somma;
  }

  public static void main(String[] args) {
    ArrayRiempibile arr = new ArrayRiempibile(-3);
    arr.equals(arr);
    arr.inserire(0, 10);
    arr.inserire(1, 20);
    arr.inserire(2, 30);
    System.out.println(arr);
    System.out.println("Somma: " + arr.calcolareSomma());
}

}
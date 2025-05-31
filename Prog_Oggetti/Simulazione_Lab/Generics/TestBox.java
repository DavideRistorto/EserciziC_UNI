package Simulazione_Lab.Generics;

public class TestBox {

  public static void main(String[] args) {
    Box<String> b1 = new Box<>("Ciao");
    System.out.println(b1.getItem());
    Box<Integer> b2 = new Box<>(2);
    System.out.println(b2.getItem());
  }
  
}

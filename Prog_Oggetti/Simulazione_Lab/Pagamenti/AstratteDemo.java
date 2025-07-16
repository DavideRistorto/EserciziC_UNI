package Pagamenti;


class AstratteDemo{

static abstract class A {
  public abstract void m1();
}

static abstract class B extends A {
  public void m1() {System.out.println("B.m1");}
  public abstract void m2(A obj);
}

static class C extends B {

  public C() {
    super();
  }
  public void m1() {System.out.println("C.m1"); super.m1();}
  public void m2(A obj) {System.out.println("C.m2");obj.m1();}
}

  public static void main(String[] args) {
    A obj3 = new C();
    obj3.m1();
  }

}

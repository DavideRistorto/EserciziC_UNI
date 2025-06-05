interface I {
  public void m1(J obj);
}

interface J {
  public void m2();
}

abstract class C implements I {
    public abstract void m1(J obj);
}

class D extends C implements J {
  public void m1(J obj) {
    if (this != obj) {
      obj.m2();
    }
    System.out.println("D.m1");
  }

    public void m2() {
        System.out.println("D.m2");
        m1(this);
    }
}

public class Main {
    public static void main(String[] args) {
        J obj3 = new D();
        C x = (C) obj3;
        x.m1(new D());
    }
}

abstract class A {
    public abstract void m1();
}

abstract class B extends A {
    public void m1() {
        System.out.println("B.m1");
    }
    public abstract void m2(A obj);
}

class C extends B {
    public void m1() {
        System.out.println("C.m1");
        super.m1();
    }
    public void m2(A obj) {
        System.out.println("C.m2");
        obj.m1();
    }
}
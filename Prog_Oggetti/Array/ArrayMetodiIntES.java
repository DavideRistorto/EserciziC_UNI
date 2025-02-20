public class ArrayMetodiIntES {

	static int lunghezza(int[] a) {
		return a.length;
	}

	static void stampare(int[] a) {
		for (int i = 0; i < lunghezza(a); i++)
			System.out.println("element " + i + " = " + a[i]);
	}

	static int somma(int[] a) {
		int sommaAttuale = 0;
		for (int i = 0; i < a.length; i++)
			sommaAttuale = sommaAttuale + a[i];
		return sommaAttuale;
	}

	static Boolean confrontoDue(int[] a, int[] b) {
		Boolean confronto = (a.length == b.length);
		int i = 0;
		while (i < a.length && confronto) {
			confronto = a[i] == b[i];
			i++;
		}
		return confronto;
	}

	static Boolean findElement(int[] a, int e) {
		for (int i : a) {
			if (i == e) {
				return true;
			}
		}
		return false;
	}

	public static void main(String[] args) {
		int a[] = { 10, 20, 30 };
		System.out.println("lunghezza array = " + lunghezza(a));
		System.out.println("elementi: ");
		stampare(a);
		System.out.println("somma complessiva = " + somma(a));
		int b[] = { 10, 20, 30 };
		System.out.println(confrontoDue(a, b) ? "array uguali" : "array diversi");
		System.out.println("elemento 5 è present in a?  risposta: " + findElement(a, 5));
	}
}

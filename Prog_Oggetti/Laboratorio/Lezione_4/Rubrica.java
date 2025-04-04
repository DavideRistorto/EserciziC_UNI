import java.util.Arrays;

public class Rubrica {
    private Contatto[] contatti;
    private int size;

    public Rubrica(int capacitaIniziale) {
        assert capacitaIniziale > 0;
        this.contatti = new Contatto[capacitaIniziale];
        this.size = 0;
    }

    public void aggiungiContatto(Contatto nuovoContatto) {
        if (size == contatti.length) {
            raddoppiaCapacita();
        }
        // aggiungo e ordino
        contatti[size++] = nuovoContatto;
        Arrays.sort(contatti, 0, size, (c1, c2) -> c1.getNome().compareTo(c2.getNome()));
    }

    private void raddoppiaCapacita() {
        contatti = Arrays.copyOf(contatti, contatti.length * 2);
    }

    public Contatto cercaContatto(String nome) {
        int index = Arrays.binarySearch(contatti, 0, size, new Contatto(nome, ""), 
            (c1, c2) -> c1.getNome().compareTo(c2.getNome()));
        return index >= 0 ? contatti[index] : null;
    }

    public void stampaRubrica() {
        for (int i = 0; i < size; i++) {
            System.out.println(contatti[i]);
        }
    }

    public static void main(String[] args) {
      Rubrica rubrica = new Rubrica(2);

      rubrica.aggiungiContatto(new Contatto("Davide", "123456789"));
      rubrica.aggiungiContatto(new Contatto("Alice", "987654321"));
      rubrica.aggiungiContatto(new Contatto("Carlo", "555555555"));

      System.out.println("Rubrica dopo aggiunta di contatti:");
      rubrica.stampaRubrica();

      System.out.println("\nRicerca contatto 'Alice':");
      Contatto trovato = rubrica.cercaContatto("Alice");
      System.out.println(trovato != null ? trovato : "Contatto non trovato");

      System.out.println("\nRicerca contatto 'Marco':");
      trovato = rubrica.cercaContatto("Marco");
      System.out.println(trovato != null ? trovato : "Contatto non trovato");
  }
}

class Contatto {
    private final String nome;
    private final String telefono;

    public Contatto(String nome, String telefono) {
        this.nome = nome;
        this.telefono = telefono;
    }

    public String getNome() {
        return nome;
    }

    public String getTelefono() {
        return telefono;
    }

    @Override
    public String toString() {
        return "Nome: " + nome + ", Telefono: " + telefono;
    }
}
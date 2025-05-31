package Simulazione_Lab.Musica;

public class SongTest {
    public static void main(String[] args) {
        Song song = new Song("Imagine", "John Lennon");
        System.out.println("Titolo: " + song.getTitle());
        song.play();
    }
}

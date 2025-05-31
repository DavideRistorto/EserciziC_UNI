package Simulazione_Lab;

public class Main {
    public static void main(String[] args) {
        // Test BankAccount
        BankAccount account = new BankAccount("Mario Rossi", 1000.0);
        System.out.println(account);
        account.deposit(500);
        System.out.println("Dopo deposito: " + account);
        try {
            account.withdraw(200);
            System.out.println("Dopo prelievo: " + account);
        } catch (Exception e) {
            System.out.println("Errore prelievo: " + e.getMessage());
        }

        // Test BankAccountYoung
        BankAccountYoung youngAccount = new BankAccountYoung("Luca Bianchi", 300.0, 100.0);
        System.out.println(youngAccount);
        youngAccount.deposit(50);
        System.out.println("Dopo deposito: " + youngAccount);
        try {
            youngAccount.withdraw(80);
            System.out.println("Dopo prelievo entro limite: " + youngAccount);
        } catch (Exception e) {
            System.out.println("Errore prelievo: " + e.getMessage());
        }
        try {
            youngAccount.withdraw(150);
        } catch (Exception e) {
            System.out.println("Errore prelievo sopra limite: " + e.getMessage());
        }
    }
}

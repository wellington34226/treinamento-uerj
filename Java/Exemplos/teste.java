import java.util.Scanner;

class teste {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Qual o seu nome: ");
        String nome = scanner.next();
        System.out.println("Seja bem vindo " + nome + "!");
    }
}

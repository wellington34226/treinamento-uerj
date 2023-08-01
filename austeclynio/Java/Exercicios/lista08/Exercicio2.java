public class Exercicio2 {
  public static void main(String[] args) {
    int numeros[] = {50,10,100};
    Menor menor = new Menor(numeros);
    Media media = new Media(numeros);
    menor.start();
    media.start();
    System.out.println("Programa finalizado");
  }
}

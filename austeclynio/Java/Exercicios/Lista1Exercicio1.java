/**
 * Lista1Exercicio1
 * 1. Escreva um aplicativo que leia do teclado um nome digitado com letras maiúsculas e, com a exceção da primeira letra deste nome, transforme todas as outras letras para minúsculas. Imprima o texto.
 */

 import java.util.Scanner;

public class Lista1Exercicio1 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista1Exercicio1.executar(entrada);
      do{
        System.out.print("\nDeseja finalizar s/n:");
        texto = entrada.nextLine();
        if(
          texto.toLowerCase().equals("s") || 
          texto.toLowerCase().equals("y") ||
          texto.toLowerCase().equals("sim") || 
          texto.toLowerCase().equals("yes")
        ){
          continuar = true;
          sair = true;
        }else if(
          texto.toLowerCase().equals("n") || 
          texto.toLowerCase().equals("não") || 
          texto.toLowerCase().equals("no")
        ){
          continuar = true;
        }else{
          System.out.println("Digite s, y sim ou yes para finalizar o programa ou n, não ou no para continuar executando");
          continuar = false;
        }
      }while(!continuar);
      System.out.println("");
    }while(!sair);
    System.out.println("Programa finalizado");
		entrada.close();
  }

  public static void executar(Scanner entrada) {
    String texto;
    System.out.print("Digite um nome em letras maúsculas:");
    texto = entrada.next();
    entrada.nextLine();//somente para consumir o restante da string que existir
    texto = texto.toLowerCase();
    System.out.println("Resultado: "+texto.toUpperCase().charAt(0) + texto.substring(1));
  }
}
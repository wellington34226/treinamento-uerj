/**
 * Lista1Exercicio3 
 * 3. Escreva um aplicativo que leia do teclado o nome de um aluno e indique com qual caractere o nome termina, e com qual caractere o nome inicia.
 * 
*/

import java.util.Scanner;

public class Lista1Exercicio3 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista1Exercicio3.executar(entrada);
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
    System.out.print("Digite um nome:");
    texto = entrada.next();
    entrada.nextLine();
    System.out.println("Resultado: "+texto+" incia com "+texto.charAt(0)+" e termina com "+texto.charAt(texto.length()-1));
  }
}

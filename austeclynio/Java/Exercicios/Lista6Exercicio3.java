/**
 * Lista6Exercicio3
 * Escreva uma classe denominada TestaArrays que lerá do teclado os nomes dos alunos da turma e inserirá estes nomes em um vetor. A leitura deverá ser interrompida quando for digitada a palavra “FIM”. Após o término da leitura todos os nomes dos vetores deverão ser apresentados.
*/

import java.util.Scanner;

public class Lista6Exercicio3 {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista6Exercicio3.executar(entrada);
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
    TestaArrays.executar(entrada);
  }
}

/**
 * TestaArrays
 * Escreva uma classe denominada TestaArrays que lerá do teclado os nomes dos alunos da turma e inserirá estes nomes em um vetor. A leitura deverá ser interrompida quando for digitada a palavra “FIM”. Após o término da leitura todos os nomes dos vetores deverão ser apresentados.
*/

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Scanner;

public class TestaArrays {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      TestaArrays.executar(entrada);
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
    ArrayList<String> nomes = new ArrayList<String>(10);
    String texto;
    do{
      System.out.print("Digite um nome: ");
      texto = entrada.nextLine();
      if(texto.isEmpty()){
        System.out.println("O nome deve ser diferente de vazio");
      }else if(!texto.equalsIgnoreCase("FIM")){
        byte[] bytes = texto.getBytes(StandardCharsets.UTF_8);
        nomes.add(new String(bytes,StandardCharsets.UTF_8));
      }
    }while(!texto.equalsIgnoreCase("FIM"));
    for (int indiceCorrente = 0; indiceCorrente < nomes.size(); indiceCorrente++) {
      System.out.printf("Nome %d: %s\n",indiceCorrente+1,nomes.get(indiceCorrente));
    }
  }
}
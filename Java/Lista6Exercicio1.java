/**
 * Lista6Exercicio1
 * 1. Escreva um aplicativo constituído das seguintes classes:
 *    Classe abstrata MamiferoQuatroPatas – esta classe possui os atributos (ou variáveis de instância) tamanhoMamifero , corMamifero  e nomeMamifero e todos os métodos GET e SET que manipulam estes atributos. Ela também possui os métodos que caracterizam estes mamíferos tais como: andar, comer, beberAgua e emitirSom. Todas as variáveis de instância são iniciadas pelo método construtor da classe. Todos os métodos são concretos com exceção do método emitirSom que é abstrato. Este método não recebe argumentos e retorna nulo(void). 
 *    Classe Cachorro – esta classe herdará da classe MamiferoQuatroPatas e escreverá o método emitirSom fazendo com que o cachorro lata.
 *    Classe Gato – esta classe também herdará da classe MamiferoQuatroPatas e escreverá o método emitirSom fazendo com que o gato mie.
 *    Classe TestaAnimal – esta classe instanciará as classes Cachorro e Gato e acionará os métodos andar(), comer() e emitirSom() para cada uma destas classes instanciadas.
*/

import java.util.Scanner;

public class Lista6Exercicio1 {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista6Exercicio1.executar(entrada);
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
    TestaAnimalAC.executar(entrada);
  }
}
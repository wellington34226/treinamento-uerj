/**
 * TestaAnimal
 * esta classe instanciará as classes Cachorro e Gato 	e acionará os métodos andar(), comer() e emitirSom() para cada uma 	destas classes instanciadas.
*/

import java.util.Scanner;

public class TestaAnimal {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      TestaAnimal.executar(entrada);
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
    Cachorro cachorro = new Cachorro(1.2, "preto", "THOR");
    Gato gato = new Gato(0.3, "branco","NEVE");
    cachorro.andar();
    cachorro.comer();
    cachorro.emitirSom();
    gato.andar();
    gato.comer();
    gato.emitirSom();
  }
}
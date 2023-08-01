/**
 * Lista4Exercicio1
 * 1. Escreva um aplicativo que leia do teclado a altura das alunas de determinada turma e imprima no desktop as seguintes informações:
 *   a. Qual a altura do aluna mais alta?
 *   b. Qual a altura do aluna mais baixa?
 *   c. Quantas alunas possuem mais do que 1,60 m?
 *   d. Qual a média de altura das alunas da turma?
 * O aplicativo deverá utilizar como sentinela uma altura negativa. A turma não possui mais do que 15 alunas.
*/

import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Lista4Exercicio1 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista4Exercicio1.executar(entrada);
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
    double[] alturas = {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0};
    String[] alunas = new String[15];
    short indiceMaximo = 0, alturaMaxima = 0, alturaMinima = 0, maiores = 0;
    double media = 0.0;
    boolean continuar = true;
    do{
      try{
        System.out.print("Digite a altura: ");
        String texto = entrada.nextLine();
        if(texto.isEmpty()){
          System.out.print("Nenhuma altura informada");
          continuar = true;
        }else{
          alturas[indiceMaximo] = Double.parseDouble(texto);
          if(alturas[indiceMaximo] < 0.0){
            continuar = false;
          }else{
            do{
              System.out.print("Digite o nome da aluna: ");
              alunas[indiceMaximo] = new String(entrada.nextLine().getBytes(StandardCharsets.UTF_8));
              if(alunas[indiceMaximo].isEmpty()){
                System.out.println("Nome deve ser diferente de vazio");
              }
            }while(alunas[indiceMaximo].isEmpty());
            indiceMaximo++;
            if(indiceMaximo>14){
              continuar = false;
            }
          }
        }
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido não é um número válido");
      }
    }while(continuar);
    continuar = true;
    if(indiceMaximo > 0){
      for (short indiceCorrente = 0; indiceCorrente < indiceMaximo; indiceCorrente++) {
        if(alturas[indiceCorrente] > alturas[alturaMaxima]){
          alturaMaxima = indiceCorrente;
        }
        if(alturas[indiceCorrente] < alturas[alturaMinima]){
          alturaMinima = indiceCorrente;
        }
        if(alturas[indiceCorrente] > 1.60){
          maiores++;
        }
        media = (media*indiceCorrente+alturas[indiceCorrente])/(indiceCorrente+1);
      }
      System.out.printf("A aluna mais alta é a %s com %.2f metros\n",alunas[alturaMaxima],alturas[alturaMaxima]);
      System.out.printf("A aluna mais baixa é a %s com %.2f metros\n",alunas[alturaMinima],alturas[alturaMinima]);
      System.out.printf("%d aluna%s apresenta%s altura maior que 1,60 metros\n",maiores,(maiores==1?"":"s"),(maiores==1?"":"m"));
      System.out.printf("A media de altura das alunas é de %.2f metros\n",media);
    }else{
      System.out.println("Nenhuma altura valida foi informada");
    }
  }
}

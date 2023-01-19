
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Exercicios {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		String texto = new String();
		int lista = 0,exercicio = 0;
    boolean sair  = false,continuar = false;
		do{
      try{
        System.out.print("Digite o número da lista:");
        texto = entrada.nextLine();
        lista = Integer.parseInt(texto);
        continuar = false;
        switch(lista){
          case 1:
            do{
              try{
                System.out.print("Digite o número do exercício: ");
                texto = entrada.nextLine();
                exercicio = Integer.parseInt(texto);
                continuar = true;
                switch(exercicio){
                  case 1:
                    Lista1Exercicio1.executar(entrada);
                    break;
                  case 2:
                    Lista1Exercicio2.executar(entrada);
                    break;
                  case 3:
                    Lista1Exercicio3.executar(entrada);
                    break;
                  case 4:
                    Lista1Exercicio4.executar(entrada);
                    break;
                  case 5:
                    Lista1Exercicio5.executar(entrada);
                    break;
                  default:
                    System.out.println("Exercício inválido, por favor digite um valor entre 1 e 5");
                    continuar = false;
                };
              }catch(NumberFormatException exception){
                System.out.println("Valor inserido não é um inteiro válido");
                continuar = false;
              }
            }while(!continuar);
            break;
          case 2:
            System.out.println("Exercícios ainda não definidos");
            break;
          case 3:
            do{
              try{
                System.out.print("Digite o número do exercício: ");
                texto = entrada.nextLine();
                exercicio = Integer.parseInt(texto);
                continuar = true;
                switch(exercicio) {
                  case 1:
                    Lista3Exercicio1.executar(entrada);
                    break;
                  case 2:
                    Lista3Exercicio2.executar(entrada);
                    break;
                  case 3:
                    Lista3Exercicio3.executar(entrada);
                    break;
                  case 4:
                    Lista3Exercicio4.executar(entrada);
                    break;  
                  default:
                    System.out.println("Exercício inválido, por favor digite um valor entre 1 e 4");
                    continuar = false;
                };
              }catch(NumberFormatException exception){
                System.out.println("Valor inserido não é um inteiro válido");
                continuar = false;
              }
            }while(!continuar);
            break;
          case 4:
            do{
              try{
                System.out.print("Digite o número do exercício: ");
                texto = entrada.nextLine();
                exercicio = Integer.parseInt(texto);
                continuar = true;
                switch(exercicio) {
                  case 1:
                    Lista4Exercicio1.executar(entrada);
                    break;
                  case 2:
                    Lista4Exercicio2.executar(entrada);
                    break;
                  case 3:
                    Lista4Exercicio3.executar(entrada);
                    break;
                  default:
                    System.out.println("Exercício inválido, por favor digite um valor entre 1 e 3");
                    continuar = false;
                }
              }catch(NumberFormatException exception){
                System.out.println("Valor inserido não é um inteiro válido");
                continuar = false;
              }
            }while(!continuar);
            break;
          case 5:
            do{
              try{
                System.out.print("Digite o número do exercício: ");
                texto = entrada.nextLine();
                exercicio = Integer.parseInt(texto);
                continuar = true;
                switch(exercicio) {
                  case 1:
                    Lista5Exercicio1.executar(entrada);
                    break;
                  case 2:
                    Lista5Exercicio2.executar(entrada);
                    break;
                  default:
                    System.out.println("Exercício inválido, por favor digite um valor entre 1 e 2");
                    continuar = false;
                }
              }catch(NumberFormatException exception){
                System.out.println("Valor inserido não é um inteiro válido");
                continuar = false;
              }
            }while(!continuar);
            break;
          case 6:
            do{
              try{
                System.out.print("Digite o número do exercício: ");
                texto = entrada.nextLine();
                exercicio = Integer.parseInt(texto);
                continuar = true;
                switch(exercicio) {
                  case 1:
                    Lista6Exercicio1.executar(entrada);
                    break;
                  case 2:
                    Lista6Exercicio2.executar(entrada);
                    break;
                    case 3:
                      Lista6Exercicio3.executar(entrada);
                      break;
                  default:
                    System.out.println("Exercício inválido, por favor digite um valor entre 1 e 3");
                    continuar = false;
                }
              }catch(NumberFormatException exception){
                System.out.println("Valor inserido não é um inteiro válido");
                continuar = false;
              }
            }while(!continuar);
            break;
          default:
            System.out.println("Lista inválida, por favor digite um valor entre 1 e 6");
        };
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido não é um inteiro válido");
      }
      do{
        System.out.print("\nDeseja finalizar s/n:");
        texto = new String(entrada.nextLine().getBytes(StandardCharsets.UTF_8));
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
}
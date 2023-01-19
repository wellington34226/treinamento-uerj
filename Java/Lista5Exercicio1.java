/**
 * Lista5Exercicio1
 * 1. Escreva um aplicativo constituído das seguintes classes:
 *   Classe Funcionario – esta classe possui os atributos (ou variáveis de instância) nomeFuncionario, matriculaFuncionario e salarioFuncionario e todos os métodos GET e SET que manipulam estes atributos. Ela também possui dois construtores: o primeiro que recebe como argumentos o nome do funcionário e a respectiva matricula e o segundo que recebe como argumentos o nome do funcionário, a matricula e o salário. Estes argumentos iniciarão os atributos.
 *   Classe CriaFuncionario – esta classe lerá do teclado o nome, a matricula do funcionário e o seu salário. Se o valor fornecido do salário for diferente de zero a classe Funcionario será instanciada com todos os seus atributos. Se o valor fornecido do salário for igual a zero a classe Funcionario será instanciada sem o valor do salário. Após a criação do objeto Funcionario esta classe imprimirá, através dos métodos GET e SET, o nome, a matricula e o salário do funcionário.
*/

import java.util.Scanner;

public class Lista5Exercicio1 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista5Exercicio1.executar(entrada);
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
   CriaFuncionario.executar(entrada);
  }
}

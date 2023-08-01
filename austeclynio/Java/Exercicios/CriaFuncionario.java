
/**
 * CriaFuncionario
 * esta classe lerá do teclado o nome, a matricula do funcionário e o seu salário. Se o valor fornecido do salário for diferente de zero a classe Funcionario será instanciada com todos os seus atributos. Se o valor fornecido do salário for igual a zero a classe Funcionario será instanciada sem o valor do salário. Após a criação do objeto Funcionario esta classe imprimirá, através dos métodos GET e SET, o nome, a matricula e o salário do funcionário.
*/

import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class CriaFuncionario {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      CriaFuncionario.executar(entrada);
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
    String nome = "";
    do{
      System.out.print("Digite o nome do funcionário: ");
      texto = entrada.nextLine();
      if(texto.isEmpty()){
        byte[] bytes = texto.getBytes(StandardCharsets.UTF_8);
        nome = new String(bytes,StandardCharsets.UTF_8);
        System.out.println("O nome do funcionário deve ser diferente de vazio");
      }
    }while(nome.isEmpty());
    String matricula = "";
    do{
      System.out.print("Digite a matrícula do funcionário: ");
      texto = entrada.nextLine();
      if(texto.isEmpty()){
        byte[] bytes = texto.getBytes(StandardCharsets.UTF_8);
        matricula = new String(bytes,StandardCharsets.UTF_8);
        System.out.println("A matrícula do funcionário deve ser diferente de vazio");
      }
    }while(matricula.isEmpty());
    double salario =-1.0;
    Funcionario funcionario;
    do{
      try {
        System.out.print("Digite o salário do funcionário em reais: ");
        texto = entrada.nextLine();
        if(texto.isEmpty()){
          System.out.println("Salário não pode ser vazio");
          salario = -1;
        }else{
          salario = Double.parseDouble(texto);
          if(salario<0.0){
            System.out.println("Salário não pode ser negativo");
          }
        }
      }catch(NumberFormatException exception) {
        System.out.println("Valor digitado não é um número");
        salario = -1.0;
      }
    }while(salario<0.0);
    if(salario>0.0){
      funcionario = new Funcionario(nome,matricula, salario);
    }else{
      funcionario = new Funcionario(nome,matricula);
    }
    System.out.printf("Funcinário %s com matrícula %s recebe R$%.2f\n",funcionario.getNomeFuncionario(),funcionario.getMatriculaFuncionario(),funcionario.getSalarioFuncionario());
  }
}
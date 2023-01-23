/**
 * Lista4Exercicio2
 * 2. Escreva um aplicativo que leia do teclado as notas da PR1 e da PR2 de 10 alunos de determinada turma e calcule a média de cada um destes alunos. Deverá ser apresentada no desktop esta média e se o aluno está indo ou não para a prova final (média <7 irá para a prova final).
*/
                    
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Lista4Exercicio2 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista4Exercicio2.executar(entrada);
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
    double[] pr1 = {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0};
    double[] pr2 = {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0};
    String[] alunos = {"","","","","","","","","",""};
    String texto;
    for(short indiceCorrente = 0; indiceCorrente < 10; indiceCorrente++){
      do{
        try{
          System.out.printf("Digite a nota da PR1 do aluno %d: ",indiceCorrente+1);
          texto = entrada.nextLine();
          if(texto.isEmpty()){
            System.out.println("Nenhuma nota inforamda");
          }else{
            pr1[indiceCorrente] = Double.parseDouble(texto);
            if(pr1[indiceCorrente] < 0.0 || pr1[indiceCorrente] > 10.0){
              System.out.println("Nota deve estar entre 0 e 10");
            }
          }
        }catch(NumberFormatException exception){
          System.out.println("Valor inserido não é um número válido");
        }
      }while(pr1[indiceCorrente] < 0.0 || pr1[indiceCorrente] > 10.0);
      do{
        try{
          System.out.printf("Digite a nota da PR2 do aluno %d: ",indiceCorrente+1);
          texto = entrada.nextLine();
          if(texto.isEmpty()){
            System.out.println("Nenhuma nota informada");
          }else{
            pr2[indiceCorrente] = Double.parseDouble(texto);
            if(pr2[indiceCorrente] < 0.0 || pr2[indiceCorrente] > 10.0){
              System.out.println("Nota deve estar entre 0 e 10");
            }
          }
        }catch(NumberFormatException exception){
          System.out.println("Valor inserido não é um número válido");
        }
      }while(pr2[indiceCorrente] < 0.0 || pr2[indiceCorrente] > 10.0);
      do{
        System.out.printf("Digite o nome do aluno %d: ",indiceCorrente+1);
        texto = entrada.nextLine();
        if(texto.isEmpty()){
          System.out.println("Nome deve ser diferente de vazio");
        }else{
          byte[] bytes = texto.getBytes(StandardCharsets.UTF_8);
          texto = new String(bytes,StandardCharsets.UTF_8);
          alunos[indiceCorrente] = texto;
        }
      }while(alunos[indiceCorrente].isEmpty());
    }
    for(short indiceCorrente = 0; indiceCorrente < 10; indiceCorrente++){
      double media = (pr1[indiceCorrente]+pr2[indiceCorrente])/2;
      System.out.printf("Aluno %s com media %.2f %s\n",alunos[indiceCorrente],media,(media<7?"PROVA FINAL":"APROVADO"));
    }
  }
}

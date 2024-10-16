import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class LerArquivo {
  public static void main(String[] args) {
    try {
      File meuArquivo = new File("saida.txt");
      Scanner ledor = new Scanner(meuArquivo);
      while(ledor.hasNext()){
        String data = ledor.nextLine();
        System.out.println(data);
      }
      ledor.close();
    } catch (FileNotFoundException e) {
      System.out.println("Algo deu errado!");
      e.printStackTrace();
    }
  }
}

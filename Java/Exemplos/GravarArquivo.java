import java.io.FileWriter;
import java.io.IOException;

public class GravarArquivo {
  public static void main(String[] args) {
    try {
      FileWriter arquivoSaida = new FileWriter("saida.txt");
      arquivoSaida.write("A primeira gravação a gente nunca esquece\n");
      arquivoSaida.write("Lorem ipsum dolor, sit amet consectetur adipisicing elit. Cum reiciendis commodi ea sit obcaecati similique provident iure hic quos, sed, est ratione libero fugit at harum reprehenderit consectetur magni perspiciatis!\n");
      arquivoSaida.write("Lorem ipsum dolor, sit amet consectetur adipisicing elit. Cum reiciendis commodi ea sit obcaecati similique provident iure hic quos, sed, est ratione libero fugit at harum reprehenderit consectetur magni perspiciatis!\n");
      arquivoSaida.write("Lorem ipsum dolor, sit amet consectetur adipisicing elit. Cum reiciendis commodi ea sit obcaecati similique provident iure hic quos, sed, est ratione libero fugit at harum reprehenderit consectetur magni perspiciatis!\n");
      arquivoSaida.write("Lorem ipsum dolor, sit amet consectetur adipisicing elit. Cum reiciendis commodi ea sit obcaecati similique provident iure hic quos, sed, est ratione libero fugit at harum reprehenderit consectetur magni perspiciatis!\n");
      arquivoSaida.write("Lorem ipsum dolor, sit amet consectetur adipisicing elit. Cum reiciendis commodi ea sit obcaecati similique provident iure hic quos, sed, est ratione libero fugit at harum reprehenderit consectetur magni perspiciatis!\n");
      arquivoSaida.write("Lorem ipsum dolor, sit amet consectetur adipisicing elit. Cum reiciendis commodi ea sit obcaecati similique provident iure hic quos, sed, est ratione libero fugit at harum reprehenderit consectetur magni perspiciatis!\n");
      arquivoSaida.close();
      arquivoSaida.close();
      System.out.println("Operação realizada com sucesso!");
    }catch (IOException e) {
      System.out.println("Algo deu errado!");
      e.printStackTrace();
    }
  }
}

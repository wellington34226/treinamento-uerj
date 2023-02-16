import java.io.File;

public class TestaFiles {
  public static void main(String[] args) {
    File aclass = new File("TestaDaemon.class");
    File ajava = new File("TestaDaemon.java");
    if(ajava.exists()){
      System.out.println("Nome do arquivo:"+ajava.getName());
      System.out.println("Path do arquivo:"+ajava.getPath());
      System.out.println("Tamanho do arquivo:"+ajava.length()+" bytes");
    }
    if(aclass.exists()){
      System.out.println("Nome do arquivo:"+aclass.getName());
      System.out.println("Path do arquivo:"+aclass.getPath());
      System.out.println("Tamanho do arquivo:"+aclass.length()+" bytes");
    }
    File meuArquivo = new File("saida.txt");
    if(meuArquivo.delete()){
      System.out.println("Arquivo "+meuArquivo.getName()+" apagado com sucesso");
    }else{
      System.out.println("Algo deu errado!");
    }
  }
}
public class ContaPalavras extends Thread{
  private String texto;
  public ContaPalavras(String texto){
    this.texto = texto;
  }
  @Override
  public void run() {
    String array[] = this.texto.toLowerCase().split(" ");
    int palavras = 0;
    for (String palavra : array) {
      if(palavra.length()>0){
        palavras++;
      }
    }
    System.out.println("Foram encontradas "+palavras+" palavras no texto "+this.texto);
  }
}

public class ContaVogais extends Thread {
  private String texto;
  public ContaVogais(String texto){
    this.texto = texto;
  }
  @Override
  public void run() {
    int vogais = 0;
    for(byte letra : this.texto.toLowerCase().getBytes()) {
      switch(letra){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          vogais++;
      }
    }
    System.out.println("Foram encontradas "+vogais+" vogais no texto "+this.texto);
  }
}

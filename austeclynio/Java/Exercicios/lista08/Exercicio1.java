public class Exercicio1 {
  public static void main(String[] args) {
    //30 vogais
    String vogais = new String("q1wertyui2opasdfgh3jklçzxc4vbnm 5qwertyu6iopasdfgh7jklçzxcvbnm qwertyu8iopasdfghjk9lçzxcvbnm qwertyuiop1asdfgh2j3klçzxcvbnm qwe4rtyuiop5a6sdfghj7k8lçzx9cvbnm  qwertyuiopasdfghjklçzxcvbnm");
    //10 palavras
    String palavras = new String("q1we rtyui2opas dfgh3 jklçz xc4vbnm       5qwertyu6iopasdfgh7jklçzxcvbnm       qwertyu8iopasdfghjk9lçzxcvbnm         qwertyuiop1asdfgh2j3klçzxcvbnm            qwe4rtyuiop5a6sdfghj7k8lçzx9cvbnm           qwertyuiopasdfghjklçzxcvbnm");
    ContaVogais contaVogais = new ContaVogais(vogais);
    ContaPalavras contaPalavras = new ContaPalavras(palavras);
    contaVogais.start();
    contaPalavras.start();
    System.out.println("Programa finalizado");
  }
}
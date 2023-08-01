/**
 * MamiferoQuatroPatasAbstrata
 * esta classe possui os atributos (ou variáveis de instância) tamanhoMamifero , corMamifero  e nomeMamifero e todos os métodos GET e SET que manipulam estes atributos. Ela também possui os métodos que caracterizam estes mamíferos tais como: andar, comer, beberAgua e emitirSom. Todas as variáveis de instância são iniciadas pelo método construtor da classe. Todos os métodos são concretos com exceção do método emitirSom que é abstrato. Este método não recebe argumentos e retorna nulo(void). 
*/

public abstract class MamiferoQuatroPatasAbstrata {
  private double tamanhoMamifero;
  private String corMamifero;
  private String nomeMamifero;

  public MamiferoQuatroPatasAbstrata(double tamanho, String cor, String nome){
    tamanhoMamifero = tamanho;
    corMamifero = cor;
    nomeMamifero = nome;
  }
  public double getTamanhoMamifero() {
    return tamanhoMamifero;
  }
  public String getCorMamifero() {
    return corMamifero;
  }
  public String getNomeMamifero() {
    return nomeMamifero;
  }
  public void setTamanhoMamifero(double tamanhoMamifero) {
    this.tamanhoMamifero = tamanhoMamifero;
  }
  public void setCorMamifero(String corMamifero) {
    this.corMamifero = corMamifero;
  }
  public void setNomeMamifero(String nomeMamifero) {
    this.nomeMamifero = nomeMamifero;
  }
  public void andar(){
    System.out.println(nomeMamifero + " andando");
  }
  public void comer(){
    System.out.println(nomeMamifero + " comendo");
  }
  public void beberAgua(){
    System.out.println(nomeMamifero + " bebendo");
  }
  public abstract void emitirSom();
}
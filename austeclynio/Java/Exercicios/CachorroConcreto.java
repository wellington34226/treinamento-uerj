/**
 * CachorroConcreto
 * esta classe herdará da classe MamiferoQuatroPatas e escreverá o método emitirSom fazendo com que o cachorro lata.
*/

public class CachorroConcreto extends MamiferoQuatroPatasAbstrata {

  public CachorroConcreto(double tamanho, String cor, String nome) {
    super(tamanho, cor, nome);
  }
  @Override
  public void emitirSom() {
    System.out.println(getNomeMamifero() + " AUAU");
  }
}
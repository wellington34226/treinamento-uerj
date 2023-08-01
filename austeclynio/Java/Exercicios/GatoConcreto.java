/**
 * GatoConcreto
 * esta classe também herdará da classe MamiferoQuatroPatas e escreverá o método emitirSom fazendo com que o gatoConcreto mie.
 */
public class GatoConcreto extends MamiferoQuatroPatasAbstrata{
  public GatoConcreto(double tamanho, String cor, String nome) {
    super(tamanho, cor, nome);
  }
  @Override
  public void emitirSom() {
    System.out.println(getNomeMamifero() + " MIAU");
  }
}

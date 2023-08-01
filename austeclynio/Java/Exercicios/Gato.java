/**
 * Gato
 * esta classe também herdará da classe MamiferoQuatroPatas e modificará o método emitirSom fazendo com que o gato mie
 */
public class Gato extends MamiferoQuatroPatas{
  public Gato(double tamanho, String cor, String nome) {
    super(tamanho, cor, nome);
  }
  @Override
  public void emitirSom() {
    System.out.println(getNomeMamifero() + " MIAU");
  }
}

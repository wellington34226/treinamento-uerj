/**
 * Cachorro
 * esta classe herdará da classe MamiferoQuatroPatas e modificará o método emitirSom fazendo com que o cachorro lata.
*/

public class Cachorro extends MamiferoQuatroPatas {

  public Cachorro(double tamanho, String cor, String nome) {
    super(tamanho, cor, nome);
  }
  @Override
  public void emitirSom() {
    System.out.println(getNomeMamifero() + " AUAU");
  }
}
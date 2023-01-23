/**
 * Calcular
 *  * Escreva uma classe denominada Calcular que implementa esta interface.
 */

public class Calcular implements CalculadoraInterface{
  @Override
  public int somar(int numero1, int numero2) {
    return numero1 + numero2;
  }
  @Override
  public int subtrair(int numero1, int numero2) {
    return numero1 - numero2;
  }
}

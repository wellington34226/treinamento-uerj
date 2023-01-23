/**
 * Calculadora
 * Esta classe é constituida dos métodos somar, subtrair, multiplicar, dividir, getResultado e setNumeros. Os valores são passados para esta classe através do método setNumeros e são do tipo double. O resultado final é obtido através do método getResultado. 
 */
public class Calculadora {
  
  double numero1;
  double numero2;
  double resultado;
  public void setNumeros(double numero1, double numero2){
    this.numero1 = numero1;
    this.numero2 = numero2;
  }
  public void somar(){
    resultado = numero1 + numero2;
  }
  public void subtrair(){
    resultado = numero1 - numero2;
  }
  public void multiplicar(){
    resultado = numero1 * numero2;
  }
  public void dividir(){
    resultado = numero1 / numero2;
  }
  public double getResultado(){
    return resultado; 
  }
}
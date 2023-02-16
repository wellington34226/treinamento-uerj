public class MinhaClasse {
  private double saldo;
  MinhaClasse(double saldoInicial){
    this.saldo = saldoInicial;
  }
  public synchronized void calcula(){
    this.saldo += 1.0;
    System.out.println("Saldo atual: "+this.saldo);
  }
}

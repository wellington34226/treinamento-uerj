/**
 * Funcionario
 * esta classe possui os atributos (ou variáveis de instância) nomeFuncionario, matriculaFuncionario e salarioFuncionario e todos os métodos GET e SET que manipulam estes atributos. Ela também possui dois construtores: o primeiro que recebe como argumentos o nome do funcionário e a respectiva matricula e o segundo que recebe como argumentos o nome do funcionário, a matricula e o salário. Estes argumentos iniciarão os atributos.
*/


public class Funcionario {
  private String nomeFuncionario;
  private String matriculaFuncionario;
  private double salarioFuncionario;

  public Funcionario(String nome, String matricula){
    nomeFuncionario = nome;
    matriculaFuncionario = matricula;
  }
  public Funcionario(String nome, String matricula, double salario){
    nomeFuncionario = nome;
    matriculaFuncionario = matricula;
    salarioFuncionario = salario;
  }

  public String getNomeFuncionario() {
    return nomeFuncionario;
  }
  public String getMatriculaFuncionario() {
    return matriculaFuncionario;
  }
  public double getSalarioFuncionario() {
    return salarioFuncionario;
  }
  public void setNomeFuncionario(String nomeFuncionario) {
    this.nomeFuncionario = nomeFuncionario;
  }
  public void setMatriculaFuncionario(String matriculaFuncionario) {
    this.matriculaFuncionario = matriculaFuncionario;
  }
  public void setSalarioFuncionario(double salarioFuncionario) {
    this.salarioFuncionario = salarioFuncionario;
  }

}
class Pessoa:
  def __init__(self, nome, idade, cidade, sexo):
    self.nome = nome
    self.idade = idade
    self.cidade = cidade
    self.sexo = sexo

  def saudacao(self):
    print(f"Olá, meu nome é {self.nome}, tenho {self.idade} anos e moro em {self.cidade}.")
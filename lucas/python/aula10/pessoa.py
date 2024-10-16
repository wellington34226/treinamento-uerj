class Pessoa:
    def __init__(self, nome, idade, cidade):
        self.nome = nome
        self.idade = idade
        self.cidade = cidade

    def saudacao(self):
        return f"Olá, meu nome é {self.nome}, tenho {self.idade} anos e moro em {self.cidade}."

class Pessoa:
    def __init__(self, nome, idade, cidade):
        self.nome = nome
        self.idade = idade
        self.cidade = cidade

    def saudacao(self):
        return f"Olá, meu nome é {self.nome}, tenho {self.idade} anos e moro em {self.cidade}."

class Aluno(Pessoa):
    def __init__(self, nome, idade, cidade, matricula):
        super().__init__(nome, idade, cidade)
        self.matricula = matricula
        self.notas = {}

    def se_matricular(self, disciplinas):
        for disciplina in disciplinas:
            self.notas[disciplina] = None  # Inicializa as notas como None
        return f"O aluno {self.nome} se matriculou com sucesso nas disciplinas: {', '.join(disciplinas)}."

    def fazer_prova(self, disciplina, nota):
        if disciplina in self.notas:
            self.notas[disciplina] = nota
            return f"O aluno {self.nome} obteve nota {nota} na disciplina {disciplina}."
        else:
            return f"A disciplina {disciplina} não está registrada para este aluno."

    def consultar_notas(self):
        return self.notas

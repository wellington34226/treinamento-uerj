from servicos_alunos.entidades.pessoa import Pessoa

class Aluno(Pessoa):
  def __init__(self, nome, idade, cidade, sexo, matricula):
    super().__init__(nome, idade, cidade, sexo)
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
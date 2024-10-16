class ServicosAluno:
  def __init__(self, aluno):
    self.aluno = aluno
    self.aluno.disciplinas = {}

  def se_matricular(self, disciplinas:list[str]):
    # Exercício: Crie uma lógica para impedir que o sistema matricule um aluno duas vezes na mesma disciplina.
    for disciplina in disciplinas:
      self.aluno.disciplinas[disciplina] = None
      print(f"O aluno {self.aluno.nome} se matriculou com sucesso nas disciplinas: {disciplina}.")
  
  def fazer_prova(self, disciplina, nota):

    # Exercício: Crie uma lógica para impedir que o aluno faça a mesma prova duas vezes.
    if disciplina in self.aluno.disciplinas:
      self.aluno.disciplinas[disciplina] = nota
      print(f"{self.aluno.nome} obteve nota {nota} na disciplina {disciplina}.")
    else:
      print(f"A disciplina {disciplina} não está registrada.")
  def consultar_historico_escolar(self):
    print(f"Histórico Escolar de {self.aluno.nome} (Matrícula: {self.aluno.matricula}):")
    for disciplina, nota in self.aluno.disciplinas.items():
      if nota is not None:
        print(f"Disciplina: {disciplina} - Nota: {nota}")
      else:
        print(f"Disciplina: {disciplina} - Nota: Ainda não avaliada")
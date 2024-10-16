from servicos_alunos import Aluno,ServicosAluno

disciplinas_lucas = [
  'Introdução a Processamento de Dados',
  'Geometria Analítica',
  'Cálculo I',
  'Geometria Descritiva',
  'Física I',
  'Sistemas Concorrentes',
]

aluno_lucas = Aluno("Wellington", 38, "Rio de Janeiro","M", "41958-0")
servico_aluno = ServicosAluno(aluno_lucas)

aluno_lucas.saudacao()
print("")
servico_aluno.se_matricular(disciplinas_lucas)
print("")
servico_aluno.fazer_prova('Introdução a Processamento de Dados', 9)
servico_aluno.fazer_prova('Geometria Analítica', 5)
servico_aluno.fazer_prova('Cálculo I', 2)
servico_aluno.fazer_prova('Geometria Descritiva', 7)
servico_aluno.fazer_prova('Sistemas Concorrentes', 9)
servico_aluno.fazer_prova('História da América Latina I', 10)
print("")
servico_aluno.consultar_historico_escolar()
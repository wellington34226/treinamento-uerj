from aluno import Aluno

# Exemplo de uso da classe Aluno
aluno1 = Aluno("João", 20, "São Paulo", "12345")
disciplinas1 = ["Matemática", "Português", "História"]
print(aluno1.saudacao())  # Saída: Olá, meu nome é João, tenho 20 anos e moro em São Paulo.
print(aluno1.se_matricular(disciplinas1))  # Saída: O aluno João se matriculou com sucesso nas disciplinas: Matemática, Português, História.

print(aluno1.fazer_prova("Matemática", 90))  # Saída: O aluno João obteve nota 90 na disciplina Matemática.
print(aluno1.consultar_notas())  # Saída: {'Matemática': 90, 'Português': None, 'História': None}

disciplinas2 = ["Inglês", "Ciências"]
print(aluno1.se_matricular(disciplinas2))  # Saída: O aluno João se matriculou com sucesso nas disciplinas: Inglês, Ciências.
print(aluno1.consultar_notas())  # Saída: {'Matemática': 90, 'Português': None, 'História': None, 'Inglês': None, 'Ciências': None}

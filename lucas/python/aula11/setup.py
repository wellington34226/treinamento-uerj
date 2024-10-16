from setuptools import setup,find_packages

setup(
  name='servicos_uerj',
  version='1.0.0',
  author='Wellington Rodrigo de Freitas Costa',
  author_email='wellignton@ime.uerj.br',
  description='Pacote de serviços para alunos da UERJ.',
  packages=find_packages(),
  install_requires=[
    'wheel'
  ]
)

#python -m setup bdist_wheel
#python -m venv my_env
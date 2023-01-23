CREATE TABLE tb_cliente(
ID_CLIENTE INT NOT NULL PRIMARY KEY, -- 
NM_CLIENTE VARCHAR2,
LOGRADOURO VARCHAR2,
NUMERO INT,
BAIRRO VARCHAR2,
CEP INT,
CIDADE VARCHAR2,
TP_DOCUMENTO CHAR(2),
NR_DOCUMENTO VARCHAR2,
ESTADO VARCHAR2);


ALTER TABLE TB_CLIENTE
(DROP CIDADE);

ALTER TABLE TB_CLIENTE
(ADD ESTADO VARCHAR2);

DROP TABLE TB_CLIENTE;



INSERT INTO TB_CLIENTE (ID_CLIENTE, NM_CLIENTE,	LOGRADOURO,	NUMERO, BAIRRO,
						CEP, CIDADE, TP_DOCUMENTO, NR_DOCUMENTO, ESTADO)
VALUES(1, 'ALBERTO RIBEIRO BORGES', 'RUA CORONEL FRANCA LEITE', 1389, 'Aleatorio',
					    22735340, 'Nilopolis', 'PF', '19882724313')

UPDATE TB_CLIENTE
SET BAIRRO = 'Nova cidade'
WHERE ID_CLIENTE = 1


DELETE FROM TB_CLIENTE
WHERE CIDADE = 'Nilopolis'

DELETE FROM TB_CLIENTE
WHERE ID_CLIENTE = 1

truncate from tb_cliente


SELECT = QUERY

* = RETORNA TODAS AS COLUNAS

SELECT NOME_COLUNA FROM NOME_TABELA

SELECT * FROM TB_CLIENTE 
WHERE NM_CLIENTE = 'Alberto Ribeiro Borges'

SELECT CIDADE FROM TB_CLIENTE
WHERE ID_CLIENTE = 1

SELECT = SELECIONE
* = TODAS AS COLUNAS
FROM = DA TABELA TB_CLIENTE
WHERE = ONDE
FILTRO A SER ATENDIDO = 1 



SELECT * FROM TB_CLIENTE

Levantar a quantidade de clientes por cidades do estado do RJ


SELECT CIDADE, COUNT(*) as QTD_CLIENTES FROM TB_CLIENTE as TC
WHERE ESTAD O = 'RJ'
HAVING COUNT(*) = 1
GROUP BY CIDADES
ORDER BY QTD_CLIENTES ASC/DSC

|CIDADE   |QTD_CLIENTES|
------------------------
|Nilopolis| 1      	   | 

COUNT = CONTA A QUANTIDADE DE REGISTROS DE UMA DETERMINADA RELAÇÃO(CONSULTA)
SUM = SOMA TODAS OS REGISTROS DA COLUNA SELECIONADA
AVG = Retorna o valor médio de todos os registros da coluna;
MIN = Retorna o menor valor da coluna
MAX = Retorna o maior valor/registro da coluna

-----------
Distinct = Retorna registros distintos
ORDER BY = Ordena a/as coluna/colunas definidas, caso o segundo parametro seja omitido, ele ordena de maneira 
		   ascendente automaticamente.


Group by = Responsavel por definir os grupos baseado na coluna que não recebe função de agregação


site com conteudo para estudos : https://www.w3schools.com/sql/sql_intro.asp
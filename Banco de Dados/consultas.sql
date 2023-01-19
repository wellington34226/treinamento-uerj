/*
** Estrutura básica de uma consuta
*/
SELECT COLUNAS FROM TABELA;

/*
** Trazer todas as colunas das tabelas relacionadas 
** nome_coluna - especifica qual coluna trazer
*/
select * from "TB_CLIENTES";

/*
** Filtros
** WHERE - função utilizada para definir clausulas e friltros na consulta
*/
select * from "TB_CLIENTES" where "TP_DOCUMENTO"='CNPJ';

/*
** Funções de agregação
** COUNT - retorna a quantidade de registros da consulta
*/
select count(*) from "TB_CLIENTES" where "TP_DOCUMENTO"='CNPJ' ;

/*
** Operadores lógicos
** AND - todas as condições precisam ser satisfeitas
** OR - pelo menos uma condição precisa ser verdadeira
*/
select * from "TB_CLIENTES" 
	where ("TP_DOCUMENTO"='CNPJ' and "BAIRRO"='TIJUCA') 
	   or ("TP_DOCUMENTO"='CPF' and "BAIRRO"='COPACABANA');
	   
/*
** Operador lógico
** IN - verifica a ocorrência dentro de uma lista de opções
*/
select * from "TB_CLIENTES" 
	where "TP_DOCUMENTO"='CNPJ' and "BAIRRO" in ('TIJUCA','COPACABANA','CENTRO');
	
/*
** Operações
** CURRENT_DATE - retorna a data atual
** CURRENT_TIME - retorna a hora atual
** operadores de soma subtração, multiplicação e divisão +,-,*,/
*/
select "NM_CLIENTE" as "Nome" ,(current_date - "DT_NASCIMENTO")/365 as "Idade" from "TB_CLIENTES";

/*
** Agregação
** SUM - soma todos os registros de uma coluna
** AVG - média aritmética
** MIN - valor mínimo
** MAX - valor máximo
** ROUND - arredonda valores númericos
** TRUNC - trunca valores numéricos
** GROUP BY - agrupa os registros de acordo com o critério ou coluna
** ORDER BY - ordena os registro de acordo com o critério (ascendente ou descendente)
*/
select "NR_NF" as "Nota Fiscal",SUM("VL_TOTAL_MERCADORIA") as "Total" from "TB_VENDAS"
	group by "NR_NF" order by "NR_NF" asc;

/*
** Relações entre tabelas, agregação da dados
*/
select 
	m."DSC_MERCADORIA" as "Mercadoria",
	m."VL_COMPRA" * sum(v."QTD_VENDIDA") as "Valor total de Compra",
	sum(v."VL_TOTAL_MERCADORIA") as "Valor total vendida"
from
	"TB_VENDAS" v
	inner join "TB_MERCADORIAS" m 
		on v."CD_MERCADORIA"=m."CD_MERCADORIA"
	group by m."CD_MERCADORIA";

/*
** Transformações
** CASE - selecção e transformações
*/
with p (statusgeometry) as (values (1),(2),(3))
select * from p;

select 
	"NM_CLIENTE" as "Nome",
	case "TP_DOCUMENTO"
		when 'CPF' then 'Física'
		when 'CNPJ' then 'Jurídica'
		else 'NULL'
	end as "Tipo Pessoa"
from "TB_CLIENTES";

/*
**
*/
select "BAIRRO",count(1) as "QTD_CLIENTES" from "TB_CLIENTES"
	group by "BAIRRO"
	order by "BAIRRO" asc;
	
select * from "TB_MERCADORIAS"

/*
** Atualização de registros
*/

update "TB_MERCADORIAS"
	set "DSC_MERCADORIA" = 'LIMAO'
	where case "CD_MERCADORIA"
		when 8 then 'LARANJA';
		
		
update "TB_MERCADORIAS"
	set "DSC_MERCADORIA" = case 
							when "CD_MERCADORIA" = 8 then 'CHOCOLATE'
							when "CD_MERCADORIA" = 9 then 'IORGUTE'
							when "CD_MERCADORIA" = 10 then 'AVEIA'
							END
	where "CD_MERCADORIA" in (8,9,10);

commit;

/*
** Apagar registros
*/

delete from "TB_MERCADORIAS"
	where "CD_MERCADORIA" = 8;

commit;

rollback;

select * from "TB_MERCADORIAS"
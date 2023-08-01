package web;

import java.io.*;
import java.sql.Date;
import javax.servlet.*;
import javax.servlet.http.*;
import DAO.*;
import model.*;
import java.util.ArrayList;
import org.json.simple.JSONObject;
import java.sql.Timestamp;
import org.apache.commons.lang3.StringUtils;


public class ControllerValidaDadosEntrada extends HttpServlet{
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException {
			
			boolean erro=false;
			String msg="";
			JSONObject saidaJSON;
			PrintWriter saida = response.getWriter();
		
		try{
			
			response.setContentType("text/html;charset=UTF-8");			
			response.setHeader("Access-Control-Allow-Origin","*");
				
			String nome = request.getParameter("nome").toUpperCase();
			String cpf = request.getParameter("cpf");
			String telefone=request.getParameter("telefone");			
			String logradouro=request.getParameter("logradouro");
			String numero=request.getParameter("numero");
			String complemento=request.getParameter("complemento");
			String localidade=request.getParameter("localidade").toUpperCase();
			String cidade=request.getParameter("cidade").toUpperCase();							
			String uf=request.getParameter("uf").toUpperCase();
			String cep=request.getParameter("cep").toUpperCase();
			String senha=request.getParameter("senha").trim();				
			String confirmaSenha = request.getParameter("confirmaSenha").trim();
			
			saidaJSON = new JSONObject();
		
			if (StringUtils.isNotBlank(nome) && StringUtils.isNotBlank(cpf) && StringUtils.isNotBlank(senha) && StringUtils.isNotBlank(confirmaSenha) && StringUtils.isNotBlank(logradouro) && StringUtils.isNotBlank(numero) && StringUtils.isNotBlank(localidade) && StringUtils.isNotBlank(telefone) && StringUtils.isNotBlank(cidade) && StringUtils.isNotBlank(uf) && StringUtils.isNotBlank(cep)) {
				
				msg="Operação realizada com sucesso!";	
			
			}
		
        	else{
        		erro = true;
        		msg="Campos Inválidos!";		     							
			}
			
			saidaJSON.put("erro",erro);
            saidaJSON.put("msg",msg);
            saidaJSON.put("nome",nome);              		
			saida.print(saidaJSON);
			saida.flush();	
			
		}
		
		catch(Exception e){
			e.printStackTrace();
			saidaJSON = new JSONObject();
			saidaJSON.put("erro",true);
            saidaJSON.put("msg","Erro severo - contacte-nos!");              		
			saida.print(saidaJSON);
			saida.flush();	
		}
	}
	
	
}
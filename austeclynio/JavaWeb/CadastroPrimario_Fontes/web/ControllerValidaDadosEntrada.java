package web;

import java.io.*;
//import java.sql.Date;
import javax.servlet.*;
import javax.servlet.http.*;
//import DAO.*;
import model.*;
//import java.util.ArrayList;
import org.json.simple.JSONObject;
//import java.sql.Timestamp;
import org.apache.commons.lang3.StringUtils;


public class ControllerValidaDadosEntrada extends HttpServlet{
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException {
			
		boolean erro=false;
		String msg="";
		JSONObject objetoJSON = new JSONObject();
		PrintWriter saida = new PrintWriter(System.out);
		
		try{
			
			response.setContentType("text/html;charset=UTF-8");			
			response.setHeader("Access-Control-Allow-Origin","*");
			saida = response.getWriter();
			
						
				
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
			
			objetoJSON = new JSONObject();
		
			if (StringUtils.isNotBlank(nome) && StringUtils.isNotBlank(cpf) && StringUtils.isNotBlank(senha) && StringUtils.isNotBlank(confirmaSenha) && StringUtils.isNotBlank(logradouro) && StringUtils.isNotBlank(numero) && StringUtils.isNotBlank(localidade) && StringUtils.isNotBlank(telefone) && StringUtils.isNotBlank(cidade) && StringUtils.isNotBlank(uf) && StringUtils.isNotBlank(cep)) {
				
				msg="Operacao realizada com sucesso!";	
			
			}
		
        	else{
        		erro = true;
        		msg="Campos Invalidos!";		     							
			}
			
			objetoJSON.put("erro",erro);
            objetoJSON.put("msg",msg);              		
			saida.print(objetoJSON);
			saida.flush();	
			
		}catch(Exception e){
			objetoJSON.put("erro",true);
            objetoJSON.put("msg","Erro severo - contacte-nos!");              		
			saida.print(objetoJSON);
			saida.flush();	
		}
	}
	
	
}
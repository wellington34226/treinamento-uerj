package web;
import java.io.IOException;
import javax.servlet.*;
import javax.servlet.http.*;
import org.json.simple.JSONObject;
import org.json.simple.JSONArray;
import java.util.ArrayList;
import DAO.*;
import model.*;
import java.io.*;
import java.sql.Timestamp;
import org.apache.commons.lang3.StringUtils;


public class ControllerLogin extends HttpServlet{
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException {
		String valorToken="";
		
		 try{
		 	
		 	response.setContentType("application/json;charset=UTF-8"); 
			PrintWriter saida = response.getWriter();
			
		 	JSONObject saidaJSON;
		 	Token token;		 	
		 	boolean erro=false;	
			String msg="";
			boolean retorno=false;	
			
			
			JSONObject documentoJSON;			
			saidaJSON = new JSONObject();
			
					
		 	String cpf=request.getParameter("cpf");
		 	cpf = cpf.replace(".","");
		 	cpf = cpf.replace("-","");	
		 	
		 	valorToken = CalculaToken.calculaToken();		 	
		 	String enderecoIP = request.getRemoteAddr();			
		 		
		 	token = new Token();
		 	token.setCpf(cpf);
		 	token.setToken(valorToken);		 		
		 	token.setEnderecoIP(enderecoIP);
		 	token.setDataHoraUltimoAcesso(new Timestamp(System.currentTimeMillis()));
		 	
		 	DAOToken.deletar(token);
		 		
		 	retorno = DAOToken.inserir(token);	
		 		
		 	if (!retorno){
		 		erro = true;
		 		valorToken="";
		 		msg = "Operação não pôde ser realizada - contacte-nos!";	
		 	}
		 	else{
				saidaJSON.put("cpf",cpf);	
				saidaJSON.put("token",valorToken);
		 		saidaJSON.put("erro",erro);  
		 		saidaJSON.put("msg","Operação realizada com sucesso!");            			        			      				
				saida.print(saidaJSON);
				saida.flush();
			}		
		 			
		 }
		 catch(Exception e){		 	
		 	e.printStackTrace();
			response.setContentType("application/json;charset=UTF-8"); 
			PrintWriter saida = response.getWriter();
			JSONObject 	saidaJSON = new JSONObject();	
			saidaJSON.put("token",valorToken);
		 	saidaJSON.put("erro",true);  
		 	saidaJSON.put("msg","Operação não pôde ser realizada, contacte-nos!");            			        			      				
			saida.print(saidaJSON);
			saida.flush();
		 }
		 
		}
		
		
	}

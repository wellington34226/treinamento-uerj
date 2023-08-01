package web;

import java.io.*;
import java.sql.Date;
import javax.servlet.*;
import javax.servlet.http.*;
import DAO.*;
import model.*;
import java.util.ArrayList;
import org.json.simple.JSONObject;
import org.json.simple.JSONArray;
import java.sql.Timestamp;
import org.apache.commons.lang3.StringUtils;


public class ControllerEnviarResultado extends HttpServlet{
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException {
			
			boolean erro=false;
			String msg="";
			JSONObject saidaJSON;
			PrintWriter saida = response.getWriter();
		
		try{
			
			response.setContentType("application/json");
			response.setCharacterEncoding("UTF-8");		
			response.setHeader("Access-Control-Allow-Origin","*");
			
			
			
			saidaJSON = new JSONObject();
			JSONArray listaMolhosJSON = new JSONArray();
				
			String[] molhos = request.getParameterValues("molhos");
		
			if (molhos.length!=0) {	
				
				JSONObject documentoJSON;			
								
					for (int i=0; i<molhos.length; i++){
						documentoJSON = new JSONObject();
						documentoJSON.put("id",i);							
						documentoJSON.put("sabor",molhos[i]);								
						listaMolhosJSON.add(documentoJSON);							
					}
				    				
				    saidaJSON.put("Molhos",listaMolhosJSON);
				   
				    msg="Operação realizada com sucesso!";	
			}
		
        	else{
        		erro = true;
        		msg="Seleção Inválida";		     							
			}
			
			saidaJSON.put("erro",erro);
            saidaJSON.put("msg",msg);                 		
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
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


public class ControllerEnviarDetalhes extends HttpServlet{
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException {
			
			boolean erro=false;
			String msg="";
			JSONObject saidaJSON;
			PrintWriter saida = response.getWriter();
		
		try{
			
			response.setContentType("text/html;charset=UTF-8");			
			response.setHeader("Access-Control-Allow-Origin","*");		
			
			
			saidaJSON = new JSONObject();			
			Carros carros = new Carros();
		
			if (StringUtils.isNotBlank(request.getParameter("id"))) {
				int id=Integer.parseInt(request.getParameter("id"));			
				carros.setId(id);			
				boolean retorno = DAOCarros.consultar(carros);
				if (retorno){					
					saidaJSON.put("preco",carros.getPreco());
					saidaJSON.put("km",carros.getKm());	
					msg="Operação realizada com sucesso!";						
				}
				else{
					msg="Nenhuma ocorrência encontrada para o tipo selecionado!";
				}
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
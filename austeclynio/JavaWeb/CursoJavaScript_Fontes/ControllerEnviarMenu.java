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


public class ControllerEnviarMenu extends HttpServlet{
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException {
			
			boolean erro=false;
			String msg="";
			JSONObject saidaJSON;
			PrintWriter saida = response.getWriter();
		
		try{
			
			response.setContentType("text/html;charset=UTF-8");			
			response.setHeader("Access-Control-Allow-Origin","*");
			
			
			
			saidaJSON = new JSONObject();
			JSONArray listaCarrosJSON = new JSONArray();
			
			
			Carros carros = new Carros();
			ArrayList<Carros> listaCarros = new ArrayList<Carros>();
				
			String menu = request.getParameter("menu");		
		
			if (StringUtils.isNotBlank(menu)) {				
				
				JSONObject documentoJSON;			
				carros.setMarca(menu);
			
				listaCarros = DAOCarros.consultarPorMarca(carros);
			
				if (listaCarros!=null && listaCarros.size()>0){					
					for (int i=0; i<listaCarros.size(); i++){
						documentoJSON = new JSONObject();
						documentoJSON.put("id",listaCarros.get(i).getId());							
						documentoJSON.put("marca",listaCarros.get(i).getMarca());					
						documentoJSON.put("modelo",listaCarros.get(i).getModelo());
						documentoJSON.put("ano",listaCarros.get(i).getAno());
						documentoJSON.put("cor",listaCarros.get(i).getCor());									
						listaCarrosJSON.add(documentoJSON);							
					}
				msg="Operação realizada com sucesso!";	
				}
				else{
					msg="Nenhuma ocorrência encontrada para o tipo selecionado!";
				}			
				
				saidaJSON.put("Carros",listaCarrosJSON);				
				
				
						
            	 
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
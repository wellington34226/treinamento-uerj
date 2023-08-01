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


public class ControllerPegaCEP extends HttpServlet{
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException {
		
		
		try{
		
			String cepInformado=request.getParameter("cep"); 
				
			cepInformado = cepInformado.replace("-","");
			
		//	System.out.println(cepInformado);			
			response.setContentType("text/html;charset=UTF-8");			
			response.setHeader("Access-Control-Allow-Origin","*");
			PrintWriter saida = response.getWriter();			
			Cep cep = new Cep();
			cep.setId(cepInformado);
			JSONObject cepJSON = new JSONObject();
			boolean encontrouCEP=true;
		
			
			boolean retorno=DAOCep.consultar(cep);
        	if (!retorno){
        		encontrouCEP=false;        		
        	}
        	else{
        		cepJSON.put("logradouro",cep.getLogradouro());
        		cepJSON.put("bairro",cep.getBairro());
        		cepJSON.put("localidade",cep.getLocalidade());
        		cepJSON.put("uf",cep.getUf());         		     							
			}			
			cepJSON.put("encontrou",encontrouCEP);        	
			saida.print(cepJSON);
			saida.flush();
		}
		
		catch(Exception e){
			e.printStackTrace();
			RequestDispatcher desvia = request.getRequestDispatcher("/jsp/VistaErroNullPointer.jsp");
       		desvia.forward(request,response);
		}
	}
	
	
}

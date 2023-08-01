package web;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
//import java.util.HashMap;
//import java.util.Map.Entry;
//import org.apache.commons.lang3.StringUtils;


public class ControllerRetornaNomeToken extends HttpServlet{	

	public void doPost(HttpServletRequest request, HttpServletResponse response)  throws IOException, ServletException {
			
		response.setContentType("text/html;charset=UTF-8");
		
		Hashtable<String,String> listaTokens= new Hashtable<String,String>();
		
		String token = request.getParameter("token");
		
		String cpf="";
		
		listaTokens = (Hashtable<String,String>) getServletContext().getAttribute("ListaTokens");		
	
		
		if (listaTokens.containsKey(token)){
			cpf = listaTokens.get(token);
		}	
		
		request.setAttribute("cpf" , cpf);
		request.setAttribute("token",token);
		
		RequestDispatcher vista = request.getRequestDispatcher("/jsp/resultadoNomeToken.jsp");		
		vista.forward(request, response);	
							
	
}

}
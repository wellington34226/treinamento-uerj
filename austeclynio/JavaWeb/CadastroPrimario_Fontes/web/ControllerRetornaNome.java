package web;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
//import java.util.*;
//import org.apache.commons.lang3.StringUtils;


public class ControllerRetornaNome extends HttpServlet{	

	public void doPost(HttpServletRequest request, HttpServletResponse response)  throws IOException, ServletException {
			
		response.setContentType("text/html;charset=UTF-8");
		
		HttpSession minhaSessao=request.getSession(false);			
		String nome = (String) minhaSessao.getAttribute("nome");	
		
		request.setAttribute("nome" , nome);
		
		RequestDispatcher vista = request.getRequestDispatcher("/jsp/resultadoNome.jsp");
		
		vista.forward(request, response);	
							
	
}

}
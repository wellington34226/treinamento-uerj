package web;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class ControllerRetornaNome extends HttpServlet {
    public void doGet(HttpServletRequest request,
		HttpServletResponse response)  throws IOException, ServletException {
		response.setContentType("text/html;charset=UTF-8");
		HttpSession minhaSessao=request.getSession(false);			
		request.setAttribute("nome" ,minhaSessao.getAttribute("nome"));	
		RequestDispatcher vista = request.getRequestDispatcher("/jsp/resultadoNome.jsp");
		vista.forward(request, response);			
	}
}

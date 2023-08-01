package web;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
//import java.util.*;
import org.apache.commons.lang3.StringUtils;


public class ControllerCadastrarDados extends HttpServlet{	

	public void doPost(HttpServletRequest request,
		HttpServletResponse response)  throws IOException, ServletException {
			
		response.setContentType("text/html;charset=UTF-8");
		
		String nome = request.getParameter("nome");
		String cpf = request.getParameter("cpf");
		String senha = request.getParameter("senha");
		String confirmasenha = request.getParameter("confirmaSenha");
		
		boolean erro=false;
		
		if(StringUtils.isNotBlank(nome) & StringUtils.isNotBlank("cpf") & StringUtils.isNotBlank("senha") & StringUtils.isNotBlank("confirmaSenha")){		
		
			request.setAttribute("cadastrado" , "Cadastrados: " + nome + ", " + cpf + ", " + senha + ", " + confirmasenha);	
			HttpSession minhaSessao=request.getSession();			
			minhaSessao.setAttribute("nome",nome);	
		}
		else{
			request.setAttribute("cadastrado" ,"Voc� n�o preencheu todos os campos!");
			erro = true;	
		}
		request.setAttribute("erro" , erro);
		RequestDispatcher vista = request.getRequestDispatcher("/jsp/retornaNome.jsp");
		
		vista.forward(request, response);	
							
	}
}
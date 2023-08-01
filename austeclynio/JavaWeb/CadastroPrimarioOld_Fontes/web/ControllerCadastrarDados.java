package web;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import org.apache.commons.lang3.StringUtils;


public class ControllerCadastrarDados extends HttpServlet{	

	public void doPost(HttpServletRequest request,
		HttpServletResponse response)  throws IOException, ServletException {
			
		response.setContentType("text/html;charset=UTF-8");
		
		String nome = request.getParameter("nome");
		String cpf = request.getParameter("cpf");
		String senha = request.getParameter("senha");
		String confirmasenha = request.getParameter("confirmaSenha");
		String mensagem = "";
		if(StringUtils.isNotBlank(nome) & StringUtils.isNotBlank("cpf") & StringUtils.isNotBlank("senha") & StringUtils.isNotBlank("confirmaSenha")){		
			mensagem += "Cadastrados: " + nome + ", " + cpf + ", " + senha + ", " + confirmasenha;	
			HttpSession minhaSessao=request.getSession(false);
			if(minhaSessao!=null){
				minhaSessao.setAttribute("nome",nome);
			}else{
				minhaSessao = request.getSession();
				if(minhaSessao==null){
					mensagem += "Sessão não iniciada";
				}else{
					minhaSessao.setAttribute("nome",nome);
				}
			}
		}
		else{
			mensagem += "Voce nao preencheu todos os campos!";	
		}
		request.setAttribute("cadastrado", mensagem);
		RequestDispatcher vista = request.getRequestDispatcher("/jsp/cadastrado.jsp");
		
		vista.forward(request, response);	
							
	}
}
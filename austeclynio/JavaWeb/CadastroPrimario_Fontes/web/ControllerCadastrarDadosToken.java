package web;
import model.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
//import java.util.*;
import java.util.Hashtable;
//import java.util.Map.Entry;
//import java.sql.Timestamp;
import org.apache.commons.lang3.StringUtils;


public class ControllerCadastrarDadosToken extends HttpServlet{	

	public void init() throws ServletException{
		
			Hashtable<String,String> listaTokens= new Hashtable<String,String>();		
			getServletContext().setAttribute("ListaTokens",listaTokens);
		 
	}

	public void doPost(HttpServletRequest request,HttpServletResponse response)  throws IOException, ServletException {
			
		
	  try{
		response.setContentType("text/html;charset=UTF-8");
		
		String nome = request.getParameter("nome");
		String cpf = request.getParameter("cpf");
		String senha = request.getParameter("senha");
		String confirmasenha = request.getParameter("confirmaSenha");
		Hashtable<String,String> listaTokens= new Hashtable<String,String>();
		String valorToken="";
		
		boolean erro=false;
		
		if(StringUtils.isNotBlank(nome) & StringUtils.isNotBlank("cpf") & StringUtils.isNotBlank("senha") & StringUtils.isNotBlank("confirmaSenha")){		
		
			request.setAttribute("cadastrado" , "Cadastrados: " + nome + ", " + cpf + ", " + senha + ", " + confirmasenha);	
				
			valorToken = CalculaToken.calculaToken();
		 			 
		 	listaTokens = (Hashtable<String,String>)getServletContext().getAttribute("ListaTokens");
		 	
		 	listaTokens.put(valorToken,cpf);
			request.setAttribute("token",valorToken);
			
			
				
		}
		else{
			request.setAttribute("cadastrado" ,"Voc� n�o preencheu todos os campos!");			
			erro = true;	
		}
		request.setAttribute("erro" , erro);
		RequestDispatcher vista = request.getRequestDispatcher("/jsp/retornaNomeToken.jsp");
		
		vista.forward(request, response);	
							
	}
	catch(Exception e){
			e.printStackTrace();
			//response.setContentType("application/json;charset=UTF-8"); 
			//PrintWriter saida = response.getWriter();
			//JSONObject 	saidaJSON = new JSONObject();	
			//saidaJSON.put("token",valorToken);
		 	//saidaJSON.put("erro",true);  
		 	//saidaJSON.put("msg","Opera��o n�o p�de ser realizada, contacte-nos!");            			        			      				
			//saida.print(saidaJSON);
			//saida.flush();
}

	}
}
package web;

import model.*;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap; 
import java.util.Enumeration;

//TOMCAT 8 usar pacote javax
//TOMCAT 10 usar pacote jakarta
import jakarta.servlet.ServletException;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

//import org.apache.commons.lang3.text.translate.CharSequenceTranslator;

public class Cadastro extends HttpServlet{
  //private CharSequenceTranslator tradutor;
  public void doPost(HttpServletRequest request,HttpServletResponse response)  throws IOException, ServletException {
    //tradutor.toString();
    response.setContentType("text/html;charset=UTF-8");//define cabeçalho HTTP
    Enumeration<String> nomes = request.getParameterNames();//pega nom dos parâmetros
    ArrayList<String> retorno = new ArrayList<String>();
    HashMap<String, String> parametros = new HashMap<String, String>();
    /// Para cada parâmetro recebido verica se está na lista de estilos, caso contrário retorna o parâmetro com o mesmo nome
    while(nomes.hasMoreElements()){
      String nome = nomes.nextElement();
      parametros.put(nome,request.getParameter(nome));
      retorno.add("<li>"+nome+":"+request.getParameter(nome)+"</li>");
    }
    
    request.setAttribute("atributos",retorno);
    request.setAttribute("resultado",Validar.validar(parametros));

    RequestDispatcher vista = request.getRequestDispatcher("/jsp/cadastrado.jsp");

    vista.forward(request, response);
  }
}

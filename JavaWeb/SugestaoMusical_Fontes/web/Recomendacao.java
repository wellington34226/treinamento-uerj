package web;

import model.*;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Enumeration;

//TOMCAT 8 usar pacote javax
//TOMCAT 10 usar pacote jakarta
import javax.servlet.ServletException;
import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Recomendacao extends HttpServlet{	
  public void doPost(HttpServletRequest request,HttpServletResponse response)  throws IOException, ServletException {
    response.setContentType("text/html;charset=UTF-8");//define cabeçalho HTTP
    Enumeration<String> nomes = request.getParameterNames();//pega nom dos parâmetros
    ArrayList<String> retorno = new ArrayList<String>();
    /// Para cada parâmetro recebido verica se está na lista de estilos, caso contrário retorna o parâmetro com o mesmo nome
    while(nomes.hasMoreElements()){
      String nome = nomes.nextElement();
      if(nome.toLowerCase().equalsIgnoreCase("estilos")){
        ArrayList<String> estilos = new ArrayList<String>();
        for(String estilo:request.getParameterValues(nome)){
          estilos.add(estilo);
        }
        Collections.sort(estilos);
        for(String estilo:estilos){
          retorno.addAll(SelecaoMusical.getLista(estilo));
        }
      }else{
        request.setAttribute(nome,request.getParameter(nome));
      }
    }
    
    request.setAttribute("listaRecomendada" , retorno);

    RequestDispatcher vista = request.getRequestDispatcher("/jsp/sugestao.jsp");

    vista.forward(request, response);
  }
}

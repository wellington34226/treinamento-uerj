<%@ page import="java.util.ArrayList,java.util.Enumeration,java.util.Locale,model.*,java.nio.charset.StandardCharsets" %>
<!DOCTYPE html>
<html lang="pt-br">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Meu Cadastro Primário - Validação</title>
  </head>
	<body>
		<h1 align =center="center"> RETORNO:<%=request.getAttribute("resultado")%></h1>
    <ul>
      <%
        ArrayList<String> atributos = (ArrayList)  request.getAttribute("atributos");
        for (String atributo:atributos){
          out.print(atributo);
        }
      %>
    </ul>
    <h2>Dados do protocolo:</h2>
    <ul>
      <li>Versao do protocolo: <% out.print(request.getProtocol()); %></li>
      <li>Esquema: <% out.print(request.getScheme()); %></li>
      <li>Nome do cliente: <% out.print(request.getRemoteHost()); %></li>
      <li>Endereço do cliente: <% out.print(request.getRemoteAddr()); %></li>
      <li>Porta do cliente: <% out.print(request.getRemotePort()); %></li>

      <li>Nome do servidor: <% out.print(request.getServerName()); %></li>
      <li>Porta do servidor: <% out.print(request.getServerPort()); %></li>

      <li>Nome local: <% out.print(request.getLocalName()); %></li>
      <li>Endereço local: <% out.print(request.getLocalAddr()); %></li>
      <li>Porta local: <% out.print(request.getLocalPort()); %></li>
      
      <li>Parâmetros:
        <ol>
        <% 
          Enumeration<String> nomes = request.getParameterNames();
          while(nomes.hasMoreElements()){
            String nome = nomes.nextElement();
            out.print("<li>" + nome + "</li>");
          }
        %>
        </ol> 
      </li>
    </ul>
	</body>
</html>
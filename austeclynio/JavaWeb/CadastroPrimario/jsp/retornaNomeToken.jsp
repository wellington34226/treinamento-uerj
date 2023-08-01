<%@ page import="java.util.ArrayList,java.util.Locale,model.*" %>
<html>
   <body>
     <h1 align =center="center"> Resposta:</h1>
	<% 
		  boolean erro = (Boolean) request.getAttribute("erro");
		  String token = (String) request.getAttribute("token");
	      out.print("<br>"+ "Cadastrado: " + (String)request.getAttribute("cadastrado") );
		  
		  if (!erro){ %>
			<form method="POST" action="RetornaNomeToken">
				<input type="hidden" name="token" value="<%=token%>"  />
				<input type="submit" value="Enviar" id="botaoLogin" /> 
			  
			</form>	  
		  <%}%>
	     
	
   </body>
</html>
<%@ page import="java.util.ArrayList,java.util.Locale,model.*" %>
<html>
   <body>
     <h1 align =center="center"> Resposta:</h1>
	<% 
		  boolean erro = (Boolean) request.getAttribute("erro");
	      out.print("<br>"+ "Cadastrado: " + (String)request.getAttribute("cadastrado") );
		  
		  if (!erro){ %>
			<form method="POST" action="RetornaNome">
				<input type="submit" value="Enviar" id="botaoLogin" /> 
			  
			</form>	  
		  <%}%>
	     
	
   </body>
</html>
<%@ page import="java.util.ArrayList,java.util.Locale,model.*" %>
<!DOCTYPE html>
<html lang="pt-br">
<head>
   <meta charset="UTF-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>Cadastro Primário - Nome</title>
</head>
<body>
     <h1 align =center="center"> Resposta:</h1>
	<% 
	   out.print("<br>"+ "Cadastrado: " + (String)request.getAttribute("cadastrado") );
	     
	%>
   <form method="GET" action="VerificarAcesso">
      <input type="submit"  value="ENVIAR">
   </form>
   </body>
</html>
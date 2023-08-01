package model;


import java.io.*;

import javax.servlet.*;
import javax.servlet.http.*;
import DAO.*;
import java.sql.Timestamp;
import java.text.*;
import java.util.concurrent.TimeUnit;
import java.util.Locale;
import java.util.Date;

public class ValidarToken {

    public static boolean validarToken(Token token, String enderecoIP, String timeout) {  
    	
    	try{  	
    
    
    		boolean retorno=false;
    		int tempoParado = Integer.parseInt(timeout);
    		
    		retorno = DAOToken.consultar(token);
    	
    	
    	
    		if (!retorno){        		
    			return false;
   
    		}
    	
    		else{
    			String dateStart = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss").format(token.getDataHoraUltimoAcesso());
    			
				String dateStop =  new SimpleDateFormat("dd/MM/yyyy HH:mm:ss").format(new Timestamp(System.currentTimeMillis()));
											
				Date d1 = null;
				Date d2 = null;							
				SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss", Locale.ENGLISH);						
    			d1 = sdf.parse(dateStart);    			
    			d2 = sdf.parse(dateStop);
    		
				long diffInMillies = Math.abs(d2.getTime() - d1.getTime());				
    			long diff = TimeUnit.MINUTES.convert(diffInMillies, TimeUnit.MILLISECONDS);
    		
    			if (diff > tempoParado) {      
    				return false;    
    			}				
				else if (enderecoIP.equals(token.getEnderecoIP())){
					
						token.setDataHoraUltimoAcesso(new Timestamp(System.currentTimeMillis()));
						DAOToken.atualizar(token);											
						return true;
				}
    			else{         			
    				return false;
    
    			}
    		}
    		
    	
    	
    }
    
		catch(Exception e){
			e.printStackTrace();
			return false;
	}
    }
    
}
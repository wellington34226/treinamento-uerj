package model;

import java.security.SecureRandom;
import java.util.Base64;

public class CalculaToken {

    public static String calculaToken() {    	
    	
    	SecureRandom secureRandom = new SecureRandom(); 
		Base64.Encoder base64Encoder = Base64.getUrlEncoder(); 
		
		byte[] randomBytes = new byte[50];
    	secureRandom.nextBytes(randomBytes);
    	return(base64Encoder.encodeToString(randomBytes));
    	
    	
    }
    
    
}
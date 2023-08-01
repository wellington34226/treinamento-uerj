package model;

import java.util.Map;
import java.util.HashMap;
import org.apache.commons.lang3.StringUtils;

public class Validar {
  static public String validar(HashMap<String,String> parametros){
    // Iterator it = parametros.entrySet().iterator();
    // while (it.hasNext()) {
    //   Map.Entry pairs = (Map.Entry)it.next();
    //   System.out.println(pairs.getKey() + " = " + pairs.getValue());
    //   it.remove(); // avoids a ConcurrentModificationException
    // }
    String senha = "";
    String confirma = "";
    String retorno = "";
    for (Map.Entry<String,String> parametro : parametros.entrySet()) {
      //System.out.println(parametro.getKey());
      if(StringUtils.isBlank(parametro.getValue())){
        if(retorno.length()>0){
          retorno += ",";
        }
        retorno += "CAMPO "+parametro.getKey()+" VAZIO";
      }else if(StringUtils.containsIgnoreCase(parametro.getKey(),"confirma")){
        confirma = parametro.getValue();
      }else if(StringUtils.containsIgnoreCase(parametro.getKey(),"senha")){
        senha = parametro.getValue();
      }
    }
    if(senha.length()>0 && confirma.length()>0){
      if(!StringUtils.equals(senha, confirma)){
        if(retorno.length()>0){
          retorno += ",";
        }
        retorno += "SENHAS DIFERENTES";
      }
    }
    if(retorno.length()==0){
      retorno = "CADASTRADO";
    }else{
      retorno = "NÃO CADASTRADO: " + retorno;
    }
    return retorno;
  }
}	

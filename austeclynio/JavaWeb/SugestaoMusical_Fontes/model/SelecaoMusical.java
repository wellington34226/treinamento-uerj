package model;

import java.util.ArrayList;

public class SelecaoMusical{
  static public ArrayList<String> getLista(String estilo){
    ArrayList<String> grupos = new ArrayList<String>();
    if(estilo.toLowerCase().endsWith("rock")){
      grupos.add("<h2>Rock:</h2><ol>");
      grupos.add("<li>Led Zeppelin</li>");
      grupos.add("<li>The Who</li>");
      grupos.add("<li>U2</li>");
      grupos.add("<li>Yes</li>");
    }else if(estilo.toLowerCase().endsWith("samba")){
      grupos.add("<h2>Samba:</h2><ol>");
      grupos.add("<li>Zeca Pagodinho</li>");
      grupos.add("<li>Fundo de Quintal</li>");
      grupos.add("<li>Dona Ivone Lara</li>");
      grupos.add("<li>Martinho da Vila</li>");
    }else if(estilo.toLowerCase().endsWith("opera")){
      grupos.add("<h2>Opera:</h2><ol>");
      grupos.add("<li>Placido Domingo</li>");
      grupos.add("<li>Luciano Pavarotti</li>");
      grupos.add("<li>Jose Carreras</li>");
      grupos.add("<li>Enrico Caruso</li>");
    }else if(estilo.toLowerCase().endsWith("mpb")){
      grupos.add("<h2>MPB:</h2><ol>");
      grupos.add("<li>Chico Buarque</li>");
      grupos.add("<li>Milton Nascimento</li>");
      grupos.add("<li>Ellis Regina</li>");
      grupos.add("<li>Gonzaguinha</li>");
    }
    grupos.add("</ol>");
    return grupos;
  }
}	

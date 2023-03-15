package model;

import java.util.ArrayList;
import java.util.Collections;

public class SelecaoMusical{
  static public ArrayList<String> getLista(String estilo){
    ArrayList<String> grupos = new ArrayList<String>();
    grupos.add(estilo);
    if(estilo.toLowerCase().endsWith("rock")){
      grupos.add("Led Zeppelin");
      grupos.add("The Who");
      grupos.add("U2");
      grupos.add("Yes");
    }else if(estilo.toLowerCase().endsWith("samba")){
      grupos.add("Zeca Pagodinho");
      grupos.add("Fundo de Quintal");
      grupos.add("Dona Ivone Lara");
      grupos.add("Martinho da Vila");
    }else if(estilo.toLowerCase().endsWith("opera")){
      grupos.add("Placido Domingo");
      grupos.add("Luciano Pavarotti");
      grupos.add("Jose Carreras");
      grupos.add("Enrico Caruso");
    }else if(estilo.toLowerCase().endsWith("mpb")){
      grupos.add("Chico Buarque");
      grupos.add("Milton Nascimento");
      grupos.add("Ellis Regina");
      grupos.add("Gonzaguinha");
    }
    Collections.sort(grupos);
    return grupos;
  }
}	

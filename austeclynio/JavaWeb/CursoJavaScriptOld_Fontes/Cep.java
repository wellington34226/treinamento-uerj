package model;

import java.util.ArrayList;
import java.sql.*;
import java.sql.Timestamp;
import java.sql.Date;

public class Cep {
	private String id;
	private String logradouro;
	private String bairro;
	private String localidade;
	private String uf;
	private int codigoIbge;

	public String getId(){
		return this.id; 
	}
	public void setId(String id){
		this.id=id;
	}
	public String getLogradouro(){
		return this.logradouro; 
	}
	public void setLogradouro(String logradouro){
		this.logradouro=logradouro;
	}
	public String getBairro(){
		return this.bairro; 
	}
	public void setBairro(String bairro){
		this.bairro=bairro;
	}
	public String getLocalidade(){
		return this.localidade; 
	}
	public void setLocalidade(String localidade){
		this.localidade=localidade;
	}
	public String getUf(){
		return this.uf; 
	}
	public void setUf(String uf){
		this.uf=uf;
	}
	public int getCodigoIbge(){
		return this.codigoIbge; 
	}
	public void setCodigoIbge(int codigoIbge){
		this.codigoIbge=codigoIbge;
	}
}

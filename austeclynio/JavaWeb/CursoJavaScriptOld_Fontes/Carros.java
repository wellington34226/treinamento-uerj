package model;

import java.util.ArrayList;
import java.sql.*;
import java.sql.Timestamp;
import java.sql.Date;

public class Carros {
	private int id;
	private String marca;
	private String modelo;
	private String cor;
	private int ano;

	public int getId(){
		return this.id; 
	}
	public void setId(int id){
		this.id=id;
	}
	public String getMarca(){
		return this.marca; 
	}
	public void setMarca(String marca){
		this.marca=marca;
	}
	public String getModelo(){
		return this.modelo; 
	}
	public void setModelo(String modelo){
		this.modelo=modelo;
	}
	public String getCor(){
		return this.cor; 
	}
	public void setCor(String cor){
		this.cor=cor;
	}
	public int getAno(){
		return this.ano; 
	}
	public void setAno(int ano){
		this.ano=ano;
	}
}

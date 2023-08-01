package model;

//import java.util.ArrayList;
import java.sql.Timestamp;
//import java.sql.Date;

public class Token {
	private String cpf;
	private String token;
	private String enderecoIP;
	private Timestamp dataHoraUltimoAcesso;

	public String getCpf(){
		return this.cpf; 
	}
	public void setCpf(String cpf){
		this.cpf=cpf;
	}
	public String getToken(){
		return this.token; 
	}
	public void setToken(String token){
		this.token=token;
	}
	public String getEnderecoIP(){
		return this.enderecoIP; 
	}
	public void setEnderecoIP(String enderecoIP){
		this.enderecoIP=enderecoIP;
	}
	public Timestamp getDataHoraUltimoAcesso(){
		return this.dataHoraUltimoAcesso; 
	}
	public void setDataHoraUltimoAcesso(Timestamp dataHoraUltimoAcesso){
		this.dataHoraUltimoAcesso=dataHoraUltimoAcesso;
	}
}
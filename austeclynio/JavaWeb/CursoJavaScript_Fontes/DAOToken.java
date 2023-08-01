package DAO;
import model.*;
import java.util.ArrayList;
import java.sql.*;
import java.sql.Timestamp;
import java.sql.Date;

public class DAOToken extends AcessoBanco {

public static boolean consultar(Token token){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String consultar="select * from token where cpf=? and token=?";

		ps = con.prepareStatement(consultar);
		ps.setString(1,token.getCpf());
		ps.setString(2,token.getToken());
		rs=ps.executeQuery();
		if (!rs.next()){ 
			return false;
		}
		else{
			token.setId(rs.getInt("id"));			
			token.setEnderecoIP(rs.getString("enderecoIP"));
			token.setDataHoraUltimoAcesso(rs.getTimestamp("dataHoraUltimoAcesso"));
		return true;
	}
	}
	catch (SQLException e){
			e.printStackTrace();
			return false;
		}
	finally{
			desconectar(con,ps,rs);
	}
}


public static boolean inserir(Token token){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String inserir="insert into token(cpf,token,enderecoIP,dataHoraUltimoAcesso) values(?,?,?,?)";
		ps = con.prepareStatement(inserir,Statement.RETURN_GENERATED_KEYS);

		ps.setString(1,token.getCpf());
		ps.setString(2,token.getToken());
		ps.setString(3,token.getEnderecoIP());
		ps.setTimestamp(4,token.getDataHoraUltimoAcesso());
		ps.executeUpdate();
		
		rs= ps.getGeneratedKeys();
		while (rs.next()) { 
			if (rs.getInt(1)==0)
		 return false;
			else {
		token.setId(rs.getInt(1));};
		}
		return true;
}	catch (SQLException e){
			e.printStackTrace();
			return false;
		}
	finally{
			desconectar(con,ps,rs);
	}
}
public static boolean atualizar(Token token){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String atualizar="update token set cpf=?,token=?,enderecoIP=?,dataHoraUltimoAcesso=? where id=?";
		ps = con.prepareStatement(atualizar);

		ps.setString(1,token.getCpf());
		ps.setString(2,token.getToken());
		ps.setString(3,token.getEnderecoIP());
		ps.setTimestamp(4,token.getDataHoraUltimoAcesso());
		ps.setInt(5,token.getId());
		ps.executeUpdate();
		return true;
	}	catch (SQLException e){
			e.printStackTrace();
			return false;
		}
	finally{
			desconectar(con,ps,rs);
	}
}
public static boolean deletar(Token token){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String deletar="delete from token where cpf=?";
		ps = con.prepareStatement(deletar);
		ps.setString(1,token.getCpf());
		ps.executeUpdate();
		return true;
	}	catch (SQLException e){
			e.printStackTrace();
			return false;
		}
	finally{
			desconectar(con,ps,rs);
	}
}
}

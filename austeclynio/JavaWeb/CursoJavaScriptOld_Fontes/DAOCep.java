
package DAO;
import model.*;
import java.util.ArrayList;
import java.sql.*;
import java.sql.Timestamp;
import java.sql.Date;

public class DAOCep  {

public static boolean consultar(Cep cep){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=AcessoBancoCEPS.conectar();
		String consultar="select * from cep where id=?";

		ps = con.prepareStatement(consultar);
		ps.setString(1,cep.getId());
		rs=ps.executeQuery();
		if (!rs.next()){ 
			return false;
		}
		else{
			cep.setLogradouro(rs.getString("logradouro"));
			cep.setBairro(rs.getString("bairro"));
			cep.setLocalidade(rs.getString("localidade"));
			cep.setUf(rs.getString("uf"));
			cep.setCodigoIbge(rs.getInt("codigoibge"));
			return true;
		}
	}
	catch (SQLException e){
			e.printStackTrace();
			return false;
		}
	finally{
			AcessoBancoCEPS.desconectar(con,ps,rs);
	}
}
public static ArrayList<Cep> consultarGeral(){ 
		
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=AcessoBancoCEPS.conectar();
		ArrayList<Cep> lista = new ArrayList<Cep>();
		String consultar="select * from cep";
		ps = con.prepareStatement(consultar);
		rs=ps.executeQuery();
		while(rs.next()){
			Cep cep = new Cep();
			cep.setId(rs.getString("id"));
			cep.setLogradouro(rs.getString("logradouro"));
			cep.setBairro(rs.getString("bairro"));
			cep.setLocalidade(rs.getString("localidade"));
			cep.setUf(rs.getString("uf"));
			cep.setCodigoIbge(rs.getInt("codigoibge"));
			lista.add(cep);
	}
		return lista;
	}
	catch (SQLException e){
			e.printStackTrace();
			return null;
		}
	finally{
			AcessoBancoCEPS.desconectar(con,ps,rs);
	}
}
public static boolean inserir(Cep cep){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=AcessoBancoCEPS.conectar();
		String inserir="insert into cep(id,logradouro,bairro,localidade,uf,codigoibge) values(?,?,?,?,?,?)";
		ps = con.prepareStatement(inserir);
		
		ps.setString(1,cep.getId());
		ps.setString(2,cep.getLogradouro());
		ps.setString(3,cep.getBairro());
		ps.setString(4,cep.getLocalidade());
		ps.setString(5,cep.getUf());
		ps.setInt(6,cep.getCodigoIbge());
		ps.executeUpdate();
		return true;
	}	catch (SQLException e){
			e.printStackTrace();
			return true;
		}
	finally{
			AcessoBancoCEPS.desconectar(con,ps,rs);
	}
}
public static boolean atualizar(Cep cep){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=AcessoBancoCEPS.conectar();
		String atualizar="update cep set logradouro=?,bairro=?,localidade=?,uf=?,codigoibge=? where id=?";
		ps = con.prepareStatement(atualizar);

		ps.setString(1,cep.getLogradouro());
		ps.setString(2,cep.getBairro());
		ps.setString(3,cep.getLocalidade());
		ps.setString(4,cep.getUf());
		ps.setInt(5,cep.getCodigoIbge());
		ps.setString(6,cep.getId());
		ps.executeUpdate();
		return true;
	}	catch (SQLException e){
			e.printStackTrace();
			return true;
		}
	finally{
			AcessoBancoCEPS.desconectar(con,ps,rs);
	}
}
}

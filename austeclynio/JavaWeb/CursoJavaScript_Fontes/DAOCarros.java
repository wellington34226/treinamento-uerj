package DAO;
import model.*;
import java.util.ArrayList;
import java.sql.*;
import java.sql.Timestamp;
import java.sql.Date;

public class DAOCarros extends AcessoBanco {

public static boolean consultar(Carros carros){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String consultar="select * from carros where id=?";

		ps = con.prepareStatement(consultar);
		ps.setInt(1,carros.getId());
		rs=ps.executeQuery();
		if (!rs.next()){ 
			return false;
		}
		else{
			carros.setMarca(rs.getString("marca"));
			carros.setModelo(rs.getString("modelo"));
			carros.setCor(rs.getString("cor"));
			carros.setAno(rs.getInt("ano"));
			carros.setPreco(rs.getFloat("preco"));
			carros.setKm(rs.getInt("km"));
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
public static ArrayList<Carros> consultarPorMarca(Carros carros){ 
	ArrayList<Carros> lista = new ArrayList<Carros>();
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String consultar="select * from carros where marca=?";
		ps = con.prepareStatement(consultar);
		ps.setString(1,carros.getMarca());
		rs=ps.executeQuery();
		while(rs.next()){
			carros = new Carros();
			carros.setId(rs.getInt("id"));
			carros.setMarca(rs.getString("marca"));
			carros.setModelo(rs.getString("modelo"));
			carros.setCor(rs.getString("cor"));
			carros.setAno(rs.getInt("ano"));
			lista.add(carros);
	}
		return lista;
	}
	catch (SQLException e){		
			e.printStackTrace();
			return null;
		}
	finally{
			desconectar(con,ps,rs);
		return lista;
	}
}
public static ArrayList<Carros> consultarGeral(){ 
	ArrayList<Carros> lista = new ArrayList<Carros>();
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String consultar="select * from carros";
		ps = con.prepareStatement(consultar);
		rs=ps.executeQuery();
		while(rs.next()){
			Carros carros = new Carros();
			carros.setId(rs.getInt("id"));
			carros.setMarca(rs.getString("marca"));
			carros.setModelo(rs.getString("modelo"));
			carros.setCor(rs.getString("cor"));
			carros.setAno(rs.getInt("ano"));
			carros.setPreco(rs.getFloat("preco"));
			carros.setKm(rs.getInt("km"));
			lista.add(carros);
	}
		return lista;
	}
	catch (SQLException e){
			e.printStackTrace();
			return null;
		}
	finally{
			desconectar(con,ps,rs);
		return lista;
	}
}
public static ArrayList<Carros> consultarGeralOffset(int offset){ 
	ArrayList<Carros> lista = new ArrayList<Carros>();
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String consultar="select * from carros order by nome limit 20 offset ?";
		ps = con.prepareStatement(consultar);
		ps.setInt(1,offset);
		rs=ps.executeQuery();
		while(rs.next()){
			Carros carros = new Carros();
			carros.setId(rs.getInt("id"));
			carros.setMarca(rs.getString("marca"));
			carros.setModelo(rs.getString("modelo"));
			carros.setCor(rs.getString("cor"));
			carros.setAno(rs.getInt("ano"));
			carros.setPreco(rs.getFloat("preco"));
			carros.setKm(rs.getInt("km"));
			lista.add(carros);
	}
		return lista;
	}
	catch (SQLException e){
			e.printStackTrace();
			return null;
		}
	finally{
			desconectar(con,ps,rs);
		return lista;
	}
}
public static ArrayList<Carros> consultarGeralHabilitado(int offset){ 
	ArrayList<Carros> lista = new ArrayList<Carros>();
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String consultar="select * from carros where habilitado=true order by nome limit 20 offset ?";
		ps = con.prepareStatement(consultar);
		ps.setInt(1,offset);
		rs=ps.executeQuery();
		while(rs.next()){
			Carros carros = new Carros();
			carros.setId(rs.getInt("id"));
			carros.setMarca(rs.getString("marca"));
			carros.setModelo(rs.getString("modelo"));
			carros.setCor(rs.getString("cor"));
			carros.setAno(rs.getInt("ano"));
			carros.setPreco(rs.getFloat("preco"));
			carros.setKm(rs.getInt("km"));
			lista.add(carros);
	}
		return lista;
	}
	catch (SQLException e){
			e.printStackTrace();
			return null;
		}
	finally{
			desconectar(con,ps,rs);
		return lista;
	}
}
public static int consultarQuantidade(){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String consultar="select count(*) as quantidade from carros";

		ps = con.prepareStatement(consultar);
		rs=ps.executeQuery();
		if (!rs.next()){ 
			return 0;
		}
		else{
		return rs.getInt("quantidade");
	}
	}
	catch (SQLException e){
			e.printStackTrace();
			return 0;
		}
	finally{
			desconectar(con,ps,rs);
	}
}
public static boolean inserir(Carros carros){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String inserir="insert into carros(marca,modelo,cor,ano,preco,km) values(?,?,?,?,?,?)";
		ps = con.prepareStatement(inserir,Statement.RETURN_GENERATED_KEYS);

		ps.setString(1,carros.getMarca());
		ps.setString(2,carros.getModelo());
		ps.setString(3,carros.getCor());
		ps.setInt(4,carros.getAno());
		ps.setFloat(5,carros.getPreco());
		ps.setInt(6,carros.getKm());
		ps.executeUpdate();
		
		rs= ps.getGeneratedKeys();
		while (rs.next()) { 
			if (rs.getInt(1)==0)
		 return false;
			else {
		carros.setId(rs.getInt(1));};
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
public static boolean atualizar(Carros carros){
	ResultSet rs=null;
	PreparedStatement ps=null;
	Connection con=null;
	try{ 
		con=conectar();
		String atualizar="update carros set marca=?,modelo=?,cor=?,ano=?,preco=?,km=? where id=?";
		ps = con.prepareStatement(atualizar);

		ps.setString(1,carros.getMarca());
		ps.setString(2,carros.getModelo());
		ps.setString(3,carros.getCor());
		ps.setInt(4,carros.getAno());
		ps.setFloat(5,carros.getPreco());
		ps.setInt(6,carros.getKm());
		ps.setInt(7,carros.getId());
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

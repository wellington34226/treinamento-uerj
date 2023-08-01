package model;

import java.sql.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

public class AcessoBancoCEPS{

    public  static Connection conectar() {		
	
        Connection con = null;
        try {
            Context ctx = (Context) new InitialContext().lookup("java:comp/env");
            con = ((DataSource) ctx.lookup("jdbc/poolDBCEPSCorreios")).getConnection();
            return con;
        } catch (Exception e) {
            e.printStackTrace(System.err);
            return null;
        }
        finally{
        	
        }

    }
		public  static boolean desconectar(Connection con,PreparedStatement ps,ResultSet rs) {
        try {
        	if (rs!=null){
        		rs.close();
        	}
        	if (ps!=null){
        		ps.close();
        	}
            if (con!=null){
            	con.close();
            }
            return true;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }

    }
    
}
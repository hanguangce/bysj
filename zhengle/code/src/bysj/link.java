package bysj;
import java.sql.*;
public class link
{
	public String url="jdbc:odbc:driver={Microsoft Access Driver (*.mdb)};DBQ=C:\\ͨѶ¼.mdb";
	public ResultSet r=null;
  link()
	{
		try{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			}catch (Exception ex){
				ex.printStackTrace();
				System.out.println("�����������ʧ�ܣ�");
				 }
	}
   public ResultSet query(String sql)
   {
   	try{
   		Connection con=DriverManager.getConnection(url);
   		PreparedStatement ptms=con.prepareStatement(sql);
   		r = ptms.executeQuery();
   		}catch(Exception e)
   		{
   			e.printStackTrace();
   	  }
   	  return r;
   }
   public void update(String sql)
   { 
   	 try{
   		Connection con=DriverManager.getConnection(url);
   		PreparedStatement ptms=con.prepareStatement(sql);
   		ptms.executeUpdate();
   	 }
   	 catch(Exception es)
   		{
   			es.printStackTrace();
   	  }
  }
}
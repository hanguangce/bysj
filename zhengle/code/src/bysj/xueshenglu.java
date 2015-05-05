package bysj;
import javax.swing.*;
import java.awt.*;
import javax.swing.table.*;
import java.awt.event.*;
import java.util.*;
import java.sql.*;
class  stdinformation extends JPanel implements ActionListener
{
	private String[] columnnames={"����","����","�Ա�","QQ��","�ֻ�����"};
	private static DefaultTableModel tablemodel;
	private JTable table;
	private JButton b1;
	private JButton b2;
	private JButton b3;
	private JButton b4;
	private JScrollPane scr;
	private JToolBar tool;
	
	link li=new link();
	stdinformation()
	{
		b1=new JButton("��ѯ");
		b2=new JButton("���");
		b3=new JButton("ɾ��");
		b4=new JButton("�˳�");
		tool=new JToolBar();
		tool.add(b1);
		tool.add(b2);
		tool.add(b3);
		tool.add(b4);
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		
		table=new JTable();
		tablemodel=new DefaultTableModel(columnnames,0){
			public boolean isCellEditable(int row,int column)
			{
				return false;
			}
		};
		
		
		try{
			ResultSet rs=li.query("Select * from user");
			while(rs.next())
			{
				Vector vcRows=new Vector();
				vcRows.addElement(rs.getString(1));
				vcRows.addElement(rs.getString(2));
				vcRows.addElement(rs.getString(3));
				vcRows.addElement(rs.getString(6));
		    vcRows.addElement(rs.getString(7));
		    tablemodel.addRow(vcRows);
		  }
		}catch(Exception ex){
  	  ex.printStackTrace();
  	}
		table.setModel(tablemodel);
		scr=new JScrollPane(table);
		table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		setTableColumnWidth(0,60);
		setTableColumnWidth(1,50);
		setTableColumnWidth(2,50);
		setTableColumnWidth(3,120);
		setTableColumnWidth(4,120);
		this.setLayout(new BorderLayout());
		scr.setPreferredSize(new Dimension(400,100));
		this.add(tool,BorderLayout.NORTH);
    this.add(scr,BorderLayout.CENTER);	
  }
  public void setTableColumnWidth(int column,int width)
  {
    if(column<columnnames.length && column>=0)
    {
    	TableColumn col=table.getColumnModel().getColumn(column);
     	col.setPreferredWidth(width);
    }
  }
 public void actionPerformed(ActionEvent e)
 {
     Object s=e.getSource();
     if(s==this.b1)
     {
        new search();
     }
     else if(s==this.b2)
     {
       	  new add();
     }
     else if(s==this.b3)
     {
       	new delete();
     }
     else
     {
       	new exit();
     }
 }
 private class search
 {
    search()
    {
		   String str=JOptionPane.showInputDialog("��������Ҫ���ҵ�ѧ��������");
	     if(str==null)
       { 
          return;
       }
       else
	     {
		      try{
			     
			     ResultSet rs=li.query("Select * from user where ����='"+str+"'");
			     if(rs.next()==false)
			     {
				      JOptionPane.showMessageDialog(null,"���󣺴�ѧ����Ϣ������!����������!","����",JOptionPane.WARNING_MESSAGE);
    	        new search();
           }
           else
           {
       	
        	    String information="\n������"+rs.getString(1)+
        	    "\n���䣺"+rs.getString(2)+
        	    "\n�Ա�"+rs.getString(3)+
        	    "\n�ط���"+rs.getString(4)+
        	    "\n��Ȥ���ã�"+rs.getString(5)+
        	    "\nQQ�ţ�"+rs.getString(6)+
        	    "\n�ֻ����룺"+rs.getString(7);
        
        
              JOptionPane.showConfirmDialog(xueshenglu.f,information,"ѧ����Ϣ",JOptionPane.PLAIN_MESSAGE);
           }
          }catch(Exception ex)
          { 
   	         ex.printStackTrace();
          }
       }
    }
 }
 
 private class exit
 {
    exit()
    {
		    String[] n={"ȷ��","ȡ��"};
		    int m=JOptionPane.showOptionDialog(null,"�Ƿ�Ҫ�˳�?",
		    "��ʾ",JOptionPane.YES_NO_OPTION,JOptionPane.QUESTION_MESSAGE,null,n,n[0]);
		    if(m==JOptionPane.NO_OPTION)
		    {
				    return;
		    }
		    else
		    {
				    System.exit(1);
		    }
		}
 }
 
 private class delete
 {
 	  private int row;
    delete()
    {
    	 
    	 String x=JOptionPane.showInputDialog("��������Ҫɾ��������:");
		   if(x==null)
		   {
			    return;
		   }
		   
		    row=tablerow(x);
			  if(row==-1)
				{
					JOptionPane.showMessageDialog(null,"���û���Ϣ�����ڣ�","����",JOptionPane.WARNING_MESSAGE);
				}
				else
				{
					
					String[] n={"ȷ��","ȡ��"};
				  int m=JOptionPane.showOptionDialog(null,"�Ƿ�Ҫɾ��?",
						 "��ʾ",JOptionPane.YES_NO_OPTION,JOptionPane.QUESTION_MESSAGE,null,n,n[0]);
				  if(m==JOptionPane.NO_OPTION)
					{
						 return;
					}
					else
					{
						
						try{
						li.update("delete * from user where ����='"+x+"'");
						}catch(Exception el)
			      {
					     el.printStackTrace();
			      }
			      tablemodel.removeRow(row);
						JOptionPane.showMessageDialog(null,"���û���Ϣ��ɾ����","��Ϣ",JOptionPane.INFORMATION_MESSAGE);
					}
				}
	     
    }
    public int tablerow(String str)
    {
	     int row;
	     for(row=0;row<tablemodel.getRowCount();row++)
	     {
		      if(str.equals(tablemodel.getValueAt(row,0)))
		      {
			       return row;
		      }
	     }
	     return -1;
    } 
 }
 
 private class add implements ActionListener
 {
 	 private JFrame f=new JFrame("���");
   private GridBagLayout gr=new GridBagLayout();
   
   private Container con;
   
   private JTextField txt1,txt2,txt3,txt4;
   private JCheckBox j1,j2,j3,j4;
   private JComboBox Jb; 
   private JRadioButton b1,b2;
   private JButton bt1,bt2,bt3,bt4;
   private Insets insets;
 
   private String[] difang={"-��ѡ��-","����","�Ϻ�","�㶫"};
  
   add()
   {
   	  con=f.getContentPane();
   	  con.setLayout(gr);
   	
   	  JLabel Lb1=new JLabel("����:");
      insets=new Insets(0,0,0,0);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,8,0,0,0,1,1,Lb1,insets);
      
      
      txt1=new JTextField(6);
      insets=new Insets(0,0,0,0);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.WEST,12,0,1,0,1,1,txt1,insets);
      
      
      JLabel Lb2=new JLabel("����:");
      insets=new Insets(0,0,0,0);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,8,0,2,0,1,1,Lb2,insets);
      
      txt2=new JTextField(2);
      insets=new Insets(0,0,0,0);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.WEST,8,0,3,0,1,1,txt2,insets);
 
      JPanel p1=new JPanel();
      insets=new Insets(-10,0,0,-10);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,15,0,4,0,GridBagConstraints.REMAINDER,2,p1,insets);
      
      p1.setLayout(new GridLayout(2,0));
      p1.setBorder(BorderFactory.createTitledBorder("�Ա�"));
      b1= new JRadioButton("��");
      b1.setSelected(true);
      b2= new JRadioButton("Ů"); 
      
      
      ButtonGroup group=new ButtonGroup();
      group.add(b1); 
      group.add(b2);
      p1.add(b1);
      p1.add(b2);
      
  
      JLabel Lb3=new JLabel("�ط�:");
      insets=new Insets(0,0,0,0);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,0,1,1,1,Lb3,insets);
      
      Jb=new JComboBox(difang);
      insets=new Insets(0,0,0,0);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.WEST,0,0,1,1,1,1,Jb,insets);
     
      
      insets=new Insets(0,0,0,0);
      JPanel p2=new JPanel();
      LayoutUtil.add(con,1,GridBagConstraints.CENTER,0,0,0,2,5,1,p2,insets);
      
      p2.setBorder(BorderFactory.createTitledBorder("��Ȥ����"));
      j1=new JCheckBox("����");
      j2=new JCheckBox("��Ӱ");
      j3=new JCheckBox("�˶�");
      j4=new JCheckBox("����");
      p2.add(j1);
      p2.add(j2);
      p2.add(j3);
      p2.add(j4);
      
      JPanel p3=new JPanel();
      LayoutUtil.add(con,3,GridBagConstraints.CENTER,0,0,0,3,5,1,p3,insets);
      
      p3.setLayout(new GridBagLayout());
      
      p3.setBorder(BorderFactory.createTitledBorder("��ϵ��ʽ"));
      
    
      JLabel Lb4=new JLabel("  QQ  �ţ�");
      LayoutUtil.add(p3,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,0,0,1,1,Lb4);

      txt3=new JTextField(10);
      LayoutUtil.add(p3,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,1,0,1,1,txt3);
     
      JLabel Lb5=new JLabel("�ֻ����룺");
      LayoutUtil.add(p3,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,0,1,1,1,Lb5);
      
      txt4=new JTextField(10);
      LayoutUtil.add(p3,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,1,1,1,1,txt4);
      
    
    
      JPanel p4=new JPanel();
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,0,4,5,1,p4);
      
      bt1=new JButton("ȷ��");
      //bt2=new JButton("�������");
      bt3=new JButton("����");
      bt4=new JButton("ȡ��");
      
      p4.add(bt1);
      //p4.add(bt2);
      p4.add(bt3);
      p4.add(bt4);
      
      
      
      f.setVisible(true);
      f.setSize(305,310);
      f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      f.setResizable(false);
      
      bt1.addActionListener(this);
      //bt2.addActionListener(this);
      bt3.addActionListener(this);
      bt4.addActionListener(this);
   }
   public void actionPerformed(ActionEvent e)
   {  
   	  Object str;
   	  String a,b,c,d,e1="",f1="",g="",h="",k,i,j;
   	  a=txt1.getText();
   	  b=txt2.getText();
   	  if(b1.isSelected())
   	  {
   	  	c=b1.getText();
   	  }
   	  else
   	  {
   	  	c=b2.getText();
   	  }
   	  
   	  d=difang[Jb.getSelectedIndex()];
   	  
   	  if(j1.isSelected())
      {
      	e1=j1.getText();
      }
      
   	  if(j2.isSelected())
      {
      	f1=j2.getText();
      }
      
   	  if(j3.isSelected())
      {
      	g=j3.getText();
      }
      
   	  if(j4.isSelected())
      {
      	h=j4.getText();
      }
      
      k=e1+" "+f1+" "+g+" "+h;
      i=txt3.getText();
      j=txt4.getText();
        	  
   	  str=e.getSource();
   	  if(str==bt1)
   	  {
   	   try{
   	  	li.update("insert into user values('"+a+"','"+b+"','"+c+"','"+d+"','"+k+"','"+i+"','"+j+"')");
   	   }catch(Exception l)
   	   {
   	  	  l.printStackTrace();
   	   }
   	   Vector vrow=new Vector();
   	   vrow.addElement(a);
   	   vrow.addElement(b);
   	   vrow.addElement(c);
   	   vrow.addElement(i);
   	   vrow.addElement(j);
   	   tablemodel.insertRow(tablemodel.getRowCount(),vrow);
   	   JOptionPane.showMessageDialog(f,"���û���Ϣ����ӣ�","��Ϣ",JOptionPane.INFORMATION_MESSAGE);
   	   f.dispose();
    	}
   	  /*if(str==bt2)
   	  {
   	  	System.out.println("ok");
   	  }*/
   	  if(str==bt3)
   	  {
   	  	txt1.setText("");
   	  	txt2.setText("");
   	  	txt3.setText("");
   	  	txt4.setText("");
   	  	j1.setSelected(false);
   	  	j2.setSelected(false);
   	  	j3.setSelected(false);
   	  	j4.setSelected(false);
   	  	b1.setSelected(true);
   	  	Jb.setSelectedIndex(0);
   	  }
   	  if(str==bt4)
   	  {
   	     f.dispose();
   	  }
   }
 }
   
}
 public class xueshenglu
 {
	  public static JFrame f=new JFrame("ѧ��ͨѶ¼");
	  xueshenglu()
	  {  f=new JFrame("ѧ��ͨѶ¼");
	     f.add(new stdinformation());
	     f.setVisible(true);
	     f.setResizable(false);
	     f.setSize(410,180);
	     f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    }
	  public static void tongxunlu()
	  {
		System.out.println(" ttttttttt "); 
			 new xueshenglu();
	  }
}	

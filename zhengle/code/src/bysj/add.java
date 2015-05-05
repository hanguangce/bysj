package bysj;
import javax.swing.*;
import java.awt.*;

public class add
{
   private JFrame f=new JFrame("添加");
   private GridBagLayout gr=new GridBagLayout();
   
   private Container con;
   
   private JTextField txt1,txt2,txt3,txt4;
   private JCheckBox j1,j2,j3,j4;
   private JComboBox Jb; 
   private JRadioButton b1,b2;
   private Insets insets;
 
   private String[] difang={"北京","上海","广东"};
  
   add()
   {
   	  con=f.getContentPane();
   	  con.setLayout(gr);
   	
   	  JLabel Lb1=new JLabel("姓名:");
      insets=new Insets(0,0,0,0);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,8,0,0,0,1,1,Lb1,insets);
      
      
      txt1=new JTextField(6);
      insets=new Insets(0,0,0,0);
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.WEST,12,0,1,0,1,1,txt1,insets);
      
      
      JLabel Lb2=new JLabel("年龄:");
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
      p1.setBorder(BorderFactory.createTitledBorder("性别"));
      b1= new JRadioButton("男");
      b1.setSelected(true);
      b2= new JRadioButton("女"); 
      
      
      ButtonGroup group=new ButtonGroup();
      group.add(b1); 
      group.add(b2);
      p1.add(b1);
      p1.add(b2);
      
  
      JLabel Lb3=new JLabel("地方:");
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
      
      p2.setBorder(BorderFactory.createTitledBorder("兴趣爱好"));
      j1=new JCheckBox("旅游");
      j2=new JCheckBox("摄影");
      j3=new JCheckBox("运动");
      j4=new JCheckBox("其他");
      p2.add(j1);
      p2.add(j2);
      p2.add(j3);
      p2.add(j4);
      
      JPanel p3=new JPanel();
      LayoutUtil.add(con,3,GridBagConstraints.CENTER,0,0,0,3,5,1,p3,insets);
      
      p3.setLayout(new GridBagLayout());
      
      p3.setBorder(BorderFactory.createTitledBorder("联系方式"));
      
    
      JLabel Lb4=new JLabel("  QQ  号：");
      LayoutUtil.add(p3,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,0,0,1,1,Lb4);

      txt3=new JTextField(10);
      LayoutUtil.add(p3,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,1,0,1,1,txt3);
     
      JLabel Lb5=new JLabel("手机号码：");
      LayoutUtil.add(p3,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,0,1,1,1,Lb5);
      
      txt4=new JTextField(10);
      LayoutUtil.add(p3,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,1,1,1,1,txt4);
      
    
    
      JPanel p4=new JPanel();
      LayoutUtil.add(con,GridBagConstraints.NONE,
      GridBagConstraints.CENTER,0,0,0,4,5,1,p4);
      
      JButton bt1=new JButton("确定");
      JButton bt2=new JButton("继续添加");
      JButton bt3=new JButton("重置");
      JButton bt4=new JButton("取消");
      p4.add(bt1);
      p4.add(bt2);
      p4.add(bt3);
      p4.add(bt4);
      
      f.setVisible(true);
      f.setSize(305,310);
      f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      //f.setResizable(false);
    }
   public static void main000(String[] args)
    {
    	 new add();
    }
}       
package bysj;
import java.awt.*;
import java.awt.event.*;
import java.awt.Color;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.border.*;
import java.util.*;
import java.util.Calendar;
import java.io.*;
import java.io.IOException;

public class calendar extends JFrame
implements ActionListener,MouseListener
{
    int year,month,day;
    int yearafterquery,monthafterquery;
    int startday;
    String SwitchMonth;
    String key;
    int changeyearmessage;
    int changemonthmessage;
    int priormonth,prioryear;
    boolean ischange=false,ischange_priornext=false;
    private JPanel LeftPane,RightPane;
    
    private JLabel YearLabel;
    private JLabel MonthLabel;
    private JComboBox MonthCombobox;
    private JTextField ShowDays[]=new JTextField[42];
    private JTextField YearText;
    private JLabel Ask;
    private JLabel ShowDate;
    private JLabel Blank;
    private JLabel show;
    private  JLabel TopBarTitle[]=new JLabel[7];
    private JButton ToToday;
    private JButton Query;
    private String week[]={"星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
    
    private JLabel NorthMonthDayYear;
    private JTextArea CenterText;
    private JButton SouthSave,SouthDelete;
    private JButton PriorMonth;
    private JButton NextMonth;
    public calendar(int year,int month,int day)
    {
     setTitle("备忘录");
     //the layout about left of Jpane
     RightPane=new JPanel();
     JPanel rightCenter=new JPanel();
     JPanel rightNorth=new JPanel();
 
     RightPane.setLayout(new BorderLayout());
     RightPane.add(rightNorth,BorderLayout.NORTH);
     RightPane.add(rightCenter,BorderLayout.CENTER);
    
     RightPane.add(ToToday=new JButton("Go to today"),BorderLayout.SOUTH);
     ToToday.setBackground(Color.cyan);
     ToToday.addActionListener(this);
     RightPane.validate();
     
     
     rightNorth.setLayout(new GridLayout(3,1,0,-2));
     rightNorth.add(Ask=new JLabel("请输入你要查询的日子"));
     JPanel North=new JPanel(new FlowLayout(0,8,0));
     rightNorth.add(North);
     North.add(YearLabel=new JLabel("年:"));
     North.add(YearText=new JTextField(4));
     YearText.setBackground(Color.getHSBColor(30,20,50));
     YearText.setForeground(Color.blue);
     YearText.setFont(new Font("TimesRoman",Font.BOLD,17));
     YearText.addActionListener(this);
     YearText.setFocusable(true);
     North.add(Blank=new JLabel("月:"));
     North.add(MonthCombobox=new JComboBox());
     //add month to monthcombobox
     for(int i=1;i<=12;i++)
     {
         MonthCombobox.addItem(new Integer(i));
     }
     //Switch the month
     MonthCombobox.setForeground(Color.blue);
     MonthCombobox.setFont(new Font("TimesRoman",Font.BOLD,12));
     North.add(Query=new JButton("查询"));
     Query.setForeground(Color.blue);
     Query.addActionListener(this);
     JPanel North2=new JPanel(new FlowLayout());
     rightNorth.add(North2);
     North2.add(PriorMonth=new JButton("上一月"));
     PriorMonth.addActionListener(this);
     PriorMonth.setActionCommand("prior");
     priormonth=month;
     prioryear=year;
     SwitchMonth(month);
     North2.add(ShowDate=new JLabel(SwitchMonth+"  "+","+" "+String.valueOf(year),SwingConstants.CENTER));
     ShowDate.setForeground(Color.blue);
     ShowDate.setFont(new Font("TimesRoman",Font.BOLD,14));
    North2.add(NextMonth=new JButton("下一月"));
    NextMonth.addActionListener(this);
    NextMonth.setActionCommand("next");
    //LeftPane Center
    rightCenter.setLayout(new GridLayout(7,7));
    //print title
    for(int i=0;i<7;i++)
    {
        TopBarTitle[i]=new JLabel();
        TopBarTitle[i].setText(week[i]);
        TopBarTitle[i].setForeground(Color.darkGray);
        TopBarTitle[i].setHorizontalAlignment(0);
        TopBarTitle[i].setBackground(Color.MAGENTA);
        TopBarTitle[i].setBorder(BorderFactory.createRaisedBevelBorder());
        rightCenter.add(TopBarTitle[i]);
    }
    //print screen and add listener
    for(int i=0;i<42;i++)
    {
       ShowDays[i]=new JTextField();
       ShowDays[i].addMouseListener(this);
       ShowDays[i].setEditable(false);
       rightCenter.add(ShowDays[i]);
    }
    //print the body of month
    PrintMonth(year,month,day);
    //the layout about right of JPane
    LeftPane=new JPanel(new BorderLayout());
    JPanel leftCenter=new JPanel();
    JPanel leftNorth=new JPanel();
    JPanel leftSouth=new JPanel(new FlowLayout());
    LeftPane.add(leftNorth,BorderLayout.NORTH);
    LeftPane.add(leftCenter,BorderLayout.CENTER);
    LeftPane.add(leftSouth,BorderLayout.SOUTH);
    leftNorth.add(NorthMonthDayYear=new JLabel(">>"+year+"/"+SwitchMonth+"/"+day+"<<"));
    key=year+"_"+SwitchMonth+"_"+day;
    NorthMonthDayYear.setForeground(Color.blue);
    NorthMonthDayYear.setFont(new Font("TimesRoman",Font.BOLD,17));
    leftCenter.add(show=new JLabel("写入今天的日志"));
    leftCenter.add(CenterText=new JTextArea());
    CenterText.setLineWrap(true);
    CenterText.setSelectedTextColor(Color.blue);
    
    leftSouth.add(SouthSave=new JButton("保存"));
   // SouthSave.setBackground(Color.orange);
    SouthSave.addActionListener(this);
    SouthSave.setActionCommand("Save");
    leftSouth.add(SouthDelete=new JButton("删除"));
    SouthDelete.addActionListener(this);
    SouthDelete.setActionCommand("Delete");
    this.year=year;
    this.month=month;
    this.day=day;
    //add container to put LeftPane and RightPane
    Container con=getContentPane();
   JSplitPane split=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,RightPane,LeftPane);//中间分开
   con.add(split,BorderLayout.CENTER);
   con.validate();
   //add CenterPane to totepad
   //CenterPane initialize
   setFont(new Font("Times New Roman",Font.PLAIN,12));
   JScrollPane scrollpane=new JScrollPane(CenterText);
   scrollpane.setPreferredSize(new Dimension(220,250));
   leftCenter.add(scrollpane);
   //init randomaccessdile

    }
  //switch the month in english
  public void SwitchMonth(int month)
   {
   	   switch(month)
   	         {
   	         	case 1:
   	         	SwitchMonth="1";break;
   	         	case 2:
   	         	SwitchMonth="2";break;
   	         	case 3:
   	         	SwitchMonth="3";break;
   	         	case 4:
   	         	SwitchMonth="4";break;
   	         	case 5:
   	         	SwitchMonth="5";break;
   	         	case 6:
   	         	SwitchMonth="6";break;
   	         	case 7:
   	         	SwitchMonth="7";break;
   	         	case 8:
   	          SwitchMonth="8";break;
   	          case 9:
   	          SwitchMonth="9";break;
   	          case 10:
   	          SwitchMonth="10";break;
   	          case 11:
   	          SwitchMonth="11";break;
   	          case 12:
   	          SwitchMonth="12";break;
   	         	}
   	}
   	//print the body of the month
   public void PrintMonth(int year,int month,int day)
   	{
   	//Get STSRT day the week for the first date in the month
   	    int startday=GetStartDay(year,month);
   	//Get number of days in the month
   	int dayinmonth=GetNumOfDaysInMonth(year,month);
   	//print header
   	//print Title AndScxreen();
   	//Print body
   	PrintMonthBody(startday,dayinmonth);    	    
   		}  
   	//PrintMonth(int year,int month,int day)'s burden
   	public void PrintMonth(int year,int month)
   	  {
   	  	//Get start day of the week for the first date in the month
   	  	 int startday=GetStartDay(year,month);
   	  	 //Get number of days in the month
   	  	 int dayinmonth=GetNumOfDaysInMonth(year,month);
   	  	 //Print header
   	  	 //Print body
   	  	 PrintMonthBody(startday,dayinmonth);
   	  	 
   	  }
   	 //PrintMonthBody(int startday,int dayinmonth,int day)'s burden
   	 public void PrintMonthBody(int startday,int dayinmonth)
   	   {
   	   	for(int i=startday,n=1;i<startday+dayinmonth;i++)
   	   	  {
   	   	  	ShowDays[i].setText(""+n);
   	   	  	ShowDays[i].setHorizontalAlignment(0);//let center
   	   	  	if(n==day)
   	   	  	  {
   	   	  	  	ShowDays[i].setForeground(Color.green);
   	   	  	  	ShowDays[i].setFont(new Font("TimesRoman",Font.BOLD,20));
   	   	  	  	ShowDays[i].setBackground(Color.DARK_GRAY);
   	   	  	  }
   	   	  	else
   	   	  	 {
   	   	  	 	 ShowDays[i].setFont(new Font("Times          Roman",Font.BOLD,12));
   	   	  	 	 ShowDays[i].setForeground(Color.white);
   	   	  	 	 ShowDays[i].setBackground(Color.DARK_GRAY);
   	   	  	 }  
   	   	  	n++; 
   	   	  }
   	   	for(int i=0;i<startday;i++)
   	   	  {
   	   	    ShowDays[i].setText("");
   	   	    ShowDays[i].setBackground(Color.DARK_GRAY);
   	   	  }  
   	   	for(int i=startday+dayinmonth;i<42;i++)
   	   	  {
   	   	  	 ShowDays[i].setText("");
   	   	  	 ShowDays[i].setBackground(Color.DARK_GRAY);
   	   	  }  
   	   } 
   	   
   public boolean IsLeapYear(int year)
      {
      if((year%400==0)||(year%4==0&&year%100!=0))
          return true;
       else
         return false;   
      }
      
   //judge the start day of month
   public int GetStartDay(int year,int month)
      {
      	 //get total number of day since1/1/0000
      	 int startday0001=-32768;
      	 long totalnumofdays=GetTotalNumOfDays(year,month);
      	 //return the start day
      	 return(int)((totalnumofdays+startday0001)%7);
      }   
   //judge the days of a year
   public long GetTotalNumOfDays(int year,int month) 
     {
     	  long total=0;
     	  //get the total from -32767 to year
     	  for(int i=-32767;i<year;i++)
     	    {
     	    	 if(IsLeapYear(i))
     	    	   total=total+366;
     	    	  else
     	    	    total=total+365; 
     	    }
     	   //Add days from jan to the month prior to the calendar month
     	   for(int i=1;i<month;i++)
     	     {
     	     	  total=total+GetNumOfDaysInMonth(year,i);
     	     }
     	   return total;   
     }  
   //judge the days of a month
   public int GetNumOfDaysInMonth(int year,int month) 
     {
       if(month==1 || month==3 ||month==5 ||month==7 ||month==8 || month==10 ||month==12)
           return 31;
       if(month==4 || month==6||month==9|| month==11)
          return 30;
       if(month==2)
        {
        	if(IsLeapYear(year))
        	  return 29;
        	else
        	  return 28;  
        }   
       return 0; 
     } 
  public void WriteRecord()
    {
    	String content;
    	content=CenterText.getText();
    	int n=content.length();
    	
    	char contentarr[]=new char[n];
    	try
    	 {
    	 	  int i=0;
    	 	  for(i=0;i<n;i++)
    	 	    {
    	 	    	contentarr[i]=content.charAt(i);
    	 	    }
    	 	   File Diary=new File("Diary");
    	 	   Diary.mkdir();
    	 	   File myfile=new File("Diary\\"+key+".txt");
    	 	   FileWriter Record=new FileWriter(myfile);
    	 	   if(n==0)
    	 	   {	
    	 	     JOptionPane.showMessageDialog(this,"内容为空无法保存"); 
    	 	   }
    	 	   else
    	 	   {
    	 	   for(i=0;i<contentarr.length;i++)
    	 	     {
    	 	     	  Record.write(contentarr[i]);
    	 	     } 
    	 	   Record.close();
    	 	   JOptionPane.showMessageDialog(this,"保存成功!"); 
    	 	  }  
    	 }
    	catch(IOException ex)
    	 {}
    	  
    }  
  public void ReadRecord()
    {
    	try
    	{
    		String content="";
    		File myfile=new File("Diary\\"+key+".txt");
    		FileReader Record=new FileReader(myfile);
    		if(myfile.exists())
    		 {
    		 	  long b=myfile.length();
    		 	  //char[]= contentarr=new char[b]
    		 	  int n=JOptionPane.showConfirmDialog(this,"今天有日志，要查看吗?",
    		 	     "提示",JOptionPane.YES_NO_CANCEL_OPTION);
    		 	     
    		 	   if(n==JOptionPane.YES_OPTION)
    		 	    {
    		 	    	while((b=Record.read())!=-1)
    		 	    	  {
    		 	    	  	content=content+(char)b;
    		 	    	  }
    		 	    	CenterText.setText(content);  
    		 	    }     
    		 }
    	Record.close();	 
    	}
    catch(IOException ex)
      {
      	CenterText.setText("");
      	show.setText("无日志可读");
      	
      }	
    }
  public void DeleteFile()
    {
    	 String filepath="Diary\\"+key+".txt";
    	 File myfile=new File(filepath);
    	 int n=JOptionPane.showConfirmDialog(this,"确实要删除该内容吗?",
    	     "警告",JOptionPane.YES_NO_CANCEL_OPTION);
    	 if(n==JOptionPane.YES_OPTION) 
    	   {
    	   	 if(myfile.exists())
    	   	   {
    	   	   	  try
    	   	   	   {
    	   	   	   	 myfile.delete();
    	   	   	   }
    	   	   	  catch(Exception e)
    	   	   	   {
    	   	   	   	 e.printStackTrace();
    	   	   	   }
    	   	   	  JOptionPane.showMessageDialog(this,"已经删除!");
    	   	   	  show.setText("无内容");
    	   	   	  //CenterText.setText("Today has not logs."); 
    	   	   }
    	   	 else
    	   	   {
    	   	   	 JOptionPane.showMessageDialog(this,"The file doesn't exist,delete failured!");
    	   	   }  
    	   }   
    }     
  public void AboutActionListenerWay()
    {
    	 try
    	  {
    	  	prioryear=Integer.parseInt(YearText.getText());
    	  	priormonth=MonthCombobox.getSelectedIndex()+1;
    	  	String StrYearText=YearText.getText();
    	  	changeyearmessage=Integer.parseInt(StrYearText);
    	  	changemonthmessage=MonthCombobox.getSelectedIndex()+1;
    	  	monthafterquery=changemonthmessage;
    	  	yearafterquery=changeyearmessage;
    	  	SwitchMonth(changemonthmessage);
    	  	ShowDate.setText(SwitchMonth+" "+","+" "+String.valueOf(changeyearmessage));
    	  	PrintMonth(changeyearmessage,changemonthmessage);
    	  	ischange=true;
    	  }
    	 catch(Exception ee)
    	  {
    	  	 JOptionPane.showMessageDialog(this,"This input format doesn't match",
    	  	       "Eoorr",JOptionPane.ERROR_MESSAGE);
    	  } 
    }  
    
  //do actionlisteneer things
  public void actionPerformed(ActionEvent eAction)
   {
   	  String ActionCommand=eAction.getActionCommand();
   	  //Handle button events
   	  if(eAction.getSource()instanceof JButton)
   	   {
   	   	 //Handle button events
   	   	 if("查询".equals(ActionCommand))
   	   	   {
   	   	   	try
   	   	   	 {
   	   	   	   AboutActionListenerWay();
   	   	   	 }
   	   	   	catch(Exception ee)
   	   	   	  {
   	   	   	  	 JOptionPane.showMessageDialog(this,"The input format doesn't match",
   	   	   	  	    "Error",JOptionPane.ERROR_MESSAGE);
   	   	   	  } 
   	   	   }
   	   	  if("prior".equals(ActionCommand))
   	   	    {
   	   	    	 if(priormonth>1)
   	   	    	   {
   	   	    	   	 priormonth=priormonth-1;
   	   	    	   }
   	   	    	 else
   	   	    	   {
   	   	    	   	  priormonth=12;
   	   	    	   	  prioryear=prioryear-1;
   	   	    	   }  
   	   	    	 PrintMonth(prioryear,priormonth,day);
   	   	    	 SwitchMonth(priormonth);
   	   	    	 ShowDate.setText(SwitchMonth+","+prioryear);
   	   	    	 NorthMonthDayYear.setText(">>"+SwitchMonth+"/"+day+"/"+prioryear+"<<");
   	   	    	 key=prioryear+"_"+SwitchMonth+"_"+day;
   	   	    	 ischange_priornext=true;
   	    
   	   	    } 
   	   	   //Handle next month
   	   	   if("next".equals(ActionCommand))
   	   	     {
   	   	     	 if(priormonth<12)
   	   	     	   {
   	   	     	   	 priormonth=priormonth+1;
   	   	     	   }
   	   	     	 else
   	   	     	   {
   	   	     	   	  priormonth=1;
   	   	     	   	  prioryear=prioryear+1;
   	   	     	   }  
   	   	     	 PrintMonth(prioryear,priormonth,day);
   	   	     	 SwitchMonth(priormonth);
   	   	     	 ShowDate.setText(SwitchMonth+","+prioryear);
   	   	     	 NorthMonthDayYear.setText(">>"+SwitchMonth+"/"+day+"/"+prioryear+"<<");
   	   	     	 key=prioryear+"_"+SwitchMonth+"_"+day;
   	   	     	 ischange_priornext=true; 
   	   	     } 
   	   	    //Handle to "GO to today"
   	   	    if("Go to today".equals(ActionCommand))
   	   	      {
   	   	      	 PrintMonth(year,month,day);
   	   	      	 YearText.setText(" ");
   	   	      	 MonthCombobox.setSelectedIndex(0);
   	   	      	 SwitchMonth(month);
   	   	      	 ShowDate.setText(SwitchMonth+" "+","+" "+String.valueOf(year));
   	   	      	 NorthMonthDayYear.setText(">>"+year+"/"+SwitchMonth+"/"+day+" "+"<<");
   	   	      	 key=year+"_"+SwitchMonth+"_"+day;
   	   	      	 priormonth=month;
   	   	      	 prioryear=year;
   	   	      	 ischange=false;
   	   	      }
   	   	     //Handle the "Save"
   	   	     if("Save".equals(ActionCommand))
   	   	       {
   	   	       	  WriteRecord();
   	   	       } 
   	   	    if("Delete".equals(ActionCommand))
   	   	      {
   	   	      	 DeleteFile();
   	   	      	 CenterText.setText("");
   	   	      }  
   	   }
   	 //Handle JTextField events
   	 if(eAction.getSource()instanceof JTextField)
   	   {
   	   	//Handle the query
   	   	  AboutActionListenerWay();
   	   }
   }  
   
  public void mousePressed(MouseEvent eMouse)
   {
   	 int day;
   	 try
   	  {//Handle ShowDays[]events
   	    if(ischange==false)
   	      {
   	      	 JTextField source=(JTextField)eMouse.getSource();
   	      	 day=Integer.parseInt(source.getText());
   	      	 if(ischange_priornext==false)
   	      	   {
   	      	   	  NorthMonthDayYear.setText(">>"+SwitchMonth+"/"+day+"/"+year+"<<");
   	      	   	  key=year+"_"+SwitchMonth+"_"+day;
   	      	   }
   	      	 else
   	      	   {
   	      	   	 NorthMonthDayYear.setText(">>"+SwitchMonth+"/"+day+"/"+prioryear+"<<");
   	      	   	 key=prioryear+"_"+SwitchMonth+"_"+day;
   	      	   }  
   	      }
   	    else
   	    {
   	      JTextField source=(JTextField)eMouse.getSource();
   	     day=Integer.parseInt(source.getText());
   	    if(ischange_priornext==false)
   	      {
   	      	SwitchMonth(changemonthmessage);
   	      	NorthMonthDayYear.setText(">>"+SwitchMonth+"<"+day+","+changeyearmessage+"<<");
   	      	key=changeyearmessage+"_"+SwitchMonth+"_"+day;
   	      }    
   	    else
   	     {
   	     	SwitchMonth(priormonth);
   	     	NorthMonthDayYear.setText(">>"+SwitchMonth+"/"+day+"/"+prioryear+"<<");
   	     	key=prioryear+"_"+SwitchMonth+"_"+day;
   	     }  
   	  }
   	  ReadRecord(); 
    }
  catch(Exception ee)
   {}
    
  }
   public void mouseClicked(MouseEvent e)
    {}
   public void mouseReleased(MouseEvent e)
    {}
   public void mouseEntered(MouseEvent e)
    {}
   public void mouseExited(MouseEvent e)
    {}
   public void SaveLog(int year,int month,int day)
     {}
   public static void beiwanglu()throws Exception
    {
    	 Calendar calendar=Calendar.getInstance();
    	 int y=calendar.get(Calendar.YEAR);
    	 int m=calendar.get(Calendar.MONTH)+1;
    	 int d=calendar.get(Calendar.DAY_OF_MONTH);
    	 calendar frame=new calendar(y,m,d);
   //	 frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	 frame.setSize(560,400);
    	 frame.setLocation(100,100);
    	 frame.setVisible(true);
    	 frame.setResizable(false);
    	 frame.ReadRecord(); 
    }
}

package bysj;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.Calendar;
import javax.swing.*;

public class guanji extends JFrame implements ActionListener{
	//创建成员变量
	//创建实现BorderLayout布局的面板对象panelmain,用于放panelSubnorth面板和panelSubcenter面板
	private JPanel panelMain;
	//创建实现FlowLayout布局的面板对象panelSubnorth,用于放tag提示标签
	private JPanel panelSubnorth;
	//创建实现FlowLayout布局的面板对象panelSubcenter,用于放3个按钮
	private JPanel panelSubcenter;

	//创建三个按钮
	private Button countdown;
	private Button time;
	private Button cancel;
	private String key;
	//创建一个提示标签
	private JLabel tag;


	public guanji(){
		initComponents();
	}

	/**
	 * 初始化组件信息
	 */
	public void initComponents() {

		panelMain=new JPanel(new BorderLayout(5, 10));

		panelSubnorth=new JPanel(new FlowLayout(3));
		panelSubcenter=new JPanel(new FlowLayout(1,5,5));

		countdown=new Button("倒计时关机");
		time=new Button("定时关机");
		cancel=new Button("取消关机");

		tag=new JLabel("请选择关机方式");

		//将panelMain添加到窗体中
		this.getContentPane().add(panelMain);
		//添加对象panelSubnorth到对象panelMain窗口里
		panelMain.add(panelSubnorth, BorderLayout.NORTH);
		//添加对象panelSubcenter到对象panelMain窗口里
		panelMain.add(panelSubcenter, BorderLayout.CENTER);

		//添加标签对象tag到对象panelSubnorth窗口里
		panelSubnorth.add(tag);

		//添加3个按钮到对象panelSubcenter里
		panelSubcenter.add(countdown);
		panelSubcenter.add(time);
		panelSubcenter.add(cancel);

		//为3个按钮注册事件监听器
		countdown.addActionListener(this);
		time.addActionListener(this);
		cancel.addActionListener(this);

		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setResizable(false);
		this.setLocation(350, 350);
		this.setSize(400, 400);
		this.setTitle("关机工具");

		this.pack();
	}

	/**
	 * 倒计时关机
	 */
	public void countdown() {
		//创建字符串面板对象
		key=JOptionPane.showInputDialog(this,"请输入倒计时关机剩余的时间(秒)","输入框",1);
		try {
			Runtime.getRuntime().exec("shutdown -s -t "+key);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	/**
	 * 定时关机
	 */
	public void time(){
		//获取当前系统的时间
		Calendar calendar=Calendar.getInstance();
		int h=calendar.get(Calendar.HOUR);		//获取小时
		System.out.println(h);
		int m=calendar.get(Calendar.MINUTE);	//获取分钟
		int s=calendar.get(Calendar.SECOND);	//获取秒
		String hourtmp,minutetmp,secordtmp;		//保存输入的时间
		int hour,minute,secord;					//保存转换后的时间
		//输入时间
		hourtmp=JOptionPane.showInputDialog(this,"请输入关机的小时(12小时制)","输入",1);
		minutetmp=JOptionPane.showInputDialog(this,"请输入关机的分钟","输入",1);
		secordtmp=JOptionPane.showInputDialog(this,"请输入关机的秒钟","输入",1);
		//转换时间
		hour=Integer.parseInt(hourtmp);
		minute=Integer.parseInt(minutetmp);
		secord=Integer.parseInt(secordtmp);

		long setTime=timeSum(hour, minute, secord);	//计算输入时间的总和
		long currentlyTime=timeSum(h, m, s);		//计算当前系统时间的总和
		long discrepancyTime=setTime-currentlyTime;	//获取时间差
		if (discrepancyTime<0) {
			try {
				Runtime.getRuntime().exec("shutdown -s");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}else {
			try {
				Runtime.getRuntime().exec("shutdown -s  -t "+discrepancyTime);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			JOptionPane.showMessageDialog(this, "恭喜你,设置成功!", "确认", 2);
		}
	}
	/**
	 * 计算出时间总和,并返回
	 * @param h
	 * @param m
	 * @param s
	 * @return
	 */
	public int timeSum(int h,int m,int s) {
		int sum=h*3600+m*60+s;
		return sum;
	}

	/**
	 * 取消关机
	 */
	public void cancel() {
		JOptionPane.showMessageDialog(this, "你已经成功取消了关机操作!", "消息", 2);
		try {
			Runtime.getRuntime().exec("shutdown -a");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void Shutdown(String[] args) {
		java.awt.EventQueue.invokeLater(new Runnable() {

			@Override
			public void run() {
				// TODO Auto-generated method stub
				new guanji().setVisible(true);
			}
		});


	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == countdown) {
			countdown();
		}
		if (e.getSource() == time) {
			time();
		}
		if (e.getSource() == cancel) {
			cancel();
		}
	}
}

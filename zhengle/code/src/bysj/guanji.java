package bysj;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.Calendar;
import javax.swing.*;

public class guanji extends JFrame implements ActionListener{
	//������Ա����
	//����ʵ��BorderLayout���ֵ�������panelmain,���ڷ�panelSubnorth����panelSubcenter���
	private JPanel panelMain;
	//����ʵ��FlowLayout���ֵ�������panelSubnorth,���ڷ�tag��ʾ��ǩ
	private JPanel panelSubnorth;
	//����ʵ��FlowLayout���ֵ�������panelSubcenter,���ڷ�3����ť
	private JPanel panelSubcenter;

	//����������ť
	private Button countdown;
	private Button time;
	private Button cancel;
	private String key;
	//����һ����ʾ��ǩ
	private JLabel tag;


	public guanji(){
		initComponents();
	}

	/**
	 * ��ʼ�������Ϣ
	 */
	public void initComponents() {

		panelMain=new JPanel(new BorderLayout(5, 10));

		panelSubnorth=new JPanel(new FlowLayout(3));
		panelSubcenter=new JPanel(new FlowLayout(1,5,5));

		countdown=new Button("����ʱ�ػ�");
		time=new Button("��ʱ�ػ�");
		cancel=new Button("ȡ���ػ�");

		tag=new JLabel("��ѡ��ػ���ʽ");

		//��panelMain��ӵ�������
		this.getContentPane().add(panelMain);
		//��Ӷ���panelSubnorth������panelMain������
		panelMain.add(panelSubnorth, BorderLayout.NORTH);
		//��Ӷ���panelSubcenter������panelMain������
		panelMain.add(panelSubcenter, BorderLayout.CENTER);

		//��ӱ�ǩ����tag������panelSubnorth������
		panelSubnorth.add(tag);

		//���3����ť������panelSubcenter��
		panelSubcenter.add(countdown);
		panelSubcenter.add(time);
		panelSubcenter.add(cancel);

		//Ϊ3����ťע���¼�������
		countdown.addActionListener(this);
		time.addActionListener(this);
		cancel.addActionListener(this);

		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setResizable(false);
		this.setLocation(350, 350);
		this.setSize(400, 400);
		this.setTitle("�ػ�����");

		this.pack();
	}

	/**
	 * ����ʱ�ػ�
	 */
	public void countdown() {
		//�����ַ���������
		key=JOptionPane.showInputDialog(this,"�����뵹��ʱ�ػ�ʣ���ʱ��(��)","�����",1);
		try {
			Runtime.getRuntime().exec("shutdown -s -t "+key);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	/**
	 * ��ʱ�ػ�
	 */
	public void time(){
		//��ȡ��ǰϵͳ��ʱ��
		Calendar calendar=Calendar.getInstance();
		int h=calendar.get(Calendar.HOUR);		//��ȡСʱ
		System.out.println(h);
		int m=calendar.get(Calendar.MINUTE);	//��ȡ����
		int s=calendar.get(Calendar.SECOND);	//��ȡ��
		String hourtmp,minutetmp,secordtmp;		//���������ʱ��
		int hour,minute,secord;					//����ת�����ʱ��
		//����ʱ��
		hourtmp=JOptionPane.showInputDialog(this,"������ػ���Сʱ(12Сʱ��)","����",1);
		minutetmp=JOptionPane.showInputDialog(this,"������ػ��ķ���","����",1);
		secordtmp=JOptionPane.showInputDialog(this,"������ػ�������","����",1);
		//ת��ʱ��
		hour=Integer.parseInt(hourtmp);
		minute=Integer.parseInt(minutetmp);
		secord=Integer.parseInt(secordtmp);

		long setTime=timeSum(hour, minute, secord);	//��������ʱ����ܺ�
		long currentlyTime=timeSum(h, m, s);		//���㵱ǰϵͳʱ����ܺ�
		long discrepancyTime=setTime-currentlyTime;	//��ȡʱ���
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
			JOptionPane.showMessageDialog(this, "��ϲ��,���óɹ�!", "ȷ��", 2);
		}
	}
	/**
	 * �����ʱ���ܺ�,������
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
	 * ȡ���ػ�
	 */
	public void cancel() {
		JOptionPane.showMessageDialog(this, "���Ѿ��ɹ�ȡ���˹ػ�����!", "��Ϣ", 2);
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

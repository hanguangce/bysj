package bysj;


import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.net.MalformedURLException;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.swing.*;
public class naozhong extends JFrame implements Runnable {
 JLabel ri ,shi, fen, miao, dangqian;

 JButton queding, dakai;

 JTextField music,RI, SHI, FEN, MIAO;

 int h=0,f=0,m=0,r=0;
 boolean fo=false;
 public AudioClip soumd1;
 public naozhong() {
  Container c = getContentPane();
  c.setLayout(new GridLayout(3, 1));
  JPanel jp = new JPanel();
  dangqian = new JLabel();
  jp.add(dangqian);
  c.add(jp);
  JPanel jp1 = new JPanel();
  music = new JTextField(20);
  dakai = new JButton("ѡ����������");
  jp1.add(music);
  jp1.add(dakai);
  c.add(jp1);
  ri = new JLabel("��");
  RI = new JTextField(4);
  shi = new JLabel("ʱ");
  SHI = new JTextField(4);
  fen = new JLabel("��");
  FEN = new JTextField(4);
  miao = new JLabel("��");
  MIAO = new JTextField(4);
  JPanel jp2 = new JPanel();
  jp2.add(ri);
  jp2.add(RI);
  jp2.add(shi);
  jp2.add(SHI);
  jp2.add(fen);
  jp2.add(FEN);
  jp2.add(miao);
  jp2.add(MIAO);
  queding = new JButton("ȷ��");
  jp2.add(queding);
  c.add(jp2);
  setSize(400, 130);
  setVisible(true);
  dakai.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent event) {
    JFileChooser fileChooser = new JFileChooser(); // ʵ�����ļ�ѡ����
    fileChooser
      .setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES); // �����ļ�ѡ��ģʽ,�˴�Ϊ�ļ���Ŀ¼����
    fileChooser.setCurrentDirectory(new File(".")); // �����ļ�ѡ������ǰĿ¼
    fileChooser
      .setFileFilter(new javax.swing.filechooser.FileFilter() {
       public boolean accept(File file) { // �ɽ��ܵ��ļ�����
        String name = file.getName().toLowerCase();
        return name.endsWith(".wav")
          || name.endsWith(".au")
          || file.isDirectory();
       }

       public String getDescription() { // �ļ�����
        return "�����ļ�(*.wav,*.au)";
       }
      });
    if (fileChooser.showOpenDialog(naozhong.this) == JFileChooser.APPROVE_OPTION) { // �����ļ�ѡ����,���ж��Ƿ����˴򿪰�ť
     String fileName = fileChooser.getSelectedFile().getAbsolutePath(); // �õ�ѡ���ļ���Ŀ¼�ľ���·��
     music.setText(fileName);
    }
   }
  });
  queding.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent event) {
    if(queding.getText().equals("ȷ��")){
     try{
    r=Integer.parseInt(RI.getText());
    h=Integer.parseInt(SHI.getText());
    f=Integer.parseInt(FEN.getText());
    m=Integer.parseInt(MIAO.getText());
    if(1<=h&&h<=31&&0<=h&&h<=23&&0<=f&&f<=59&&0<=m&&m<=59)
    {
     fo=true;
    }
    else
     JOptionPane.showMessageDialog(null, "����ʱ�����");
     }
     catch(Exception e){
     JOptionPane.showMessageDialog(null, "��������ȷ��ʱ��");
     }
    
    }
    else
    {
     fo=false;
     RI.setEditable(true);
     SHI.setEditable(true);
     FEN.setEditable(true);
     MIAO.setEditable(true);
     queding.setText("ȷ��");
     soumd1.stop();
    }
   }
  });

 }

 public static void fun() {
  naozhong s = new naozhong();
  Thread t1 = new Thread(s);
  t1.start();
//  s.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 }

 public void run() {
  while (true) {
   Date now = new Date();
   dangqian.setText("��ǰʱ��: " + now.toString());
   if(fo)
   {
    RI.setEditable(false);
    SHI.setEditable(false);
    FEN.setEditable(false);
    MIAO.setEditable(false);
    queding.setText("�ر�");
    SimpleDateFormat ri=new SimpleDateFormat("dd");  //��װ  Ϊ�˻�ȡ����
    SimpleDateFormat shi=new SimpleDateFormat("kk");  //��װ Ϊ�˻�ȡСʱ
    SimpleDateFormat fen=new SimpleDateFormat("mm");  //��װ Ϊ�˻�ȡ����
    SimpleDateFormat miao=new SimpleDateFormat("ss");  //��װ Ϊ�˻�ȡ����
    int riqi=Integer.parseInt(ri.format(now));        //��ȡ����
    int shizhong=Integer.parseInt(shi.format(now));   //��ȡСʱ
    int fenzhong=Integer.parseInt(fen.format(now));  //��ȡ����
    int miaozhong=Integer.parseInt(miao.format(now));  //��ȡ����
    if(riqi==r&&shizhong==h&&fenzhong==f&&miaozhong==m) //�ж�����
    {
     try {
      soumd1=Applet.newAudioClip(new File(music.getText()).toURL()); //��������
      soumd1.loop();  //�����õ���ѭ������..�������𴲶�����..
      fo=false;
     } catch (MalformedURLException e) {
      e.printStackTrace();
     }
    }
   }
   try {
    Thread.sleep(1000);
   } catch (InterruptedException ie) {
   }
   
  }
 }
}

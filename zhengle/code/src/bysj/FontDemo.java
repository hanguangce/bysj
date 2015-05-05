package bysj;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
 
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.Timer;
 
public class FontDemo extends JFrame implements ActionListener{
    private Rectangle rect;
    private int frameLeft;// ��������Ļ��ߵľ���
    private int frameRight;// ��������Ļ�ұߵľ��룻
    private int frameTop;// ��������Ļ�����ľ���
    private int frameWidth; // ����Ŀ�
    private int frameHeight;    // ����ĸ�
     
    private int screenXX;// ��Ļ�Ŀ�ȣ�
    private Point point;    // ����ڴ����λ��
 
    
    private int num=0;    // ����num
    
    private Timer timer = new Timer(10, this);
    private int xx, yy;
    private boolean isDraging = false; 
    public FontDemo(){
        timer.start();
        setTitle("��������Ļ��Ե������ʾ");
        setSize(400, 300);
        setUndecorated(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setAlwaysOnTop(true);
        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                isDraging = true;
                xx = e.getX();
                yy = e.getY();
            }
 
            public void mouseReleased(MouseEvent e) {
                isDraging = false;
            }
        });
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                if (isDraging) {
                    int left = getLocation().x;
                    int top = getLocation().y;
                    setLocation(left + e.getX() - xx, top + e.getY() - yy);
                    repaint();
                }
            }
        });
 //////////
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        JButton nz;
        nz = new JButton("����");       
        Dimension preferredSize = new Dimension(100,20);//���óߴ�
        nz.setPreferredSize(preferredSize );
        
        add(nz);     
        nz.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
            	naozhong.fun();  
            }
            public void mouseReleased(MouseEvent e) {
             
            }
        });
        
        JButton nz2;
        nz2 = new JButton("����¼");       
     //   Dimension preferredSize = new Dimension(100,20);//���óߴ�
        nz2.setPreferredSize(preferredSize );
        
        add(nz2);     
        nz2.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
            	try {
					calendar.beiwanglu();
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}  
            }
            public void mouseReleased(MouseEvent e) {
             
            }
        });
        
        JButton nz1;
        nz1 = new JButton("ͨѶ¼");       
    //    Dimension preferredSize = new Dimension(100,20);//���óߴ�
        nz1.setPreferredSize(preferredSize );
        
        add(nz1);     
        nz1.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {            
           // 	System.out.println(" aaaaaaaa "); 
            	xueshenglu.tongxunlu();  
            }
            public void mouseReleased(MouseEvent e) {
             
            }
        });
        JButton nz3;
        nz3 = new JButton("�����ǩ");       
        //    Dimension preferredSize = new Dimension(100,20);//���óߴ�
            nz3.setPreferredSize(preferredSize );
            
            add(nz3);     
            nz3.addMouseListener(new MouseAdapter() {
                public void mousePressed(MouseEvent e) {
                	
                	JFrame  jf=new JFrame("��ǩ:  "+num);
                	JPanel panel = new JPanel();  
                    JTextArea textArea = new JTextArea();  
                      
                    panel.setLayout(new GridLayout());  
                    textArea.setText("");  //  ��ǩ��ʼ����
                    //��TextArea������ݹ���ʱ���ɹ�����  
                   panel.add(new JScrollPane(textArea));  
                   jf.add(panel);
                   jf.setSize(250,200);
                   jf.setVisible(true);               	
                   jf.setBounds(300,200,250,200);
                     num++;
                }
                public void mouseReleased(MouseEvent e) {                 
                }
            });
            
            JButton nz4;
            nz4 = new JButton("��ʱ�ػ�");       
            //    Dimension preferredSize = new Dimension(100,20);//���óߴ�
                nz4.setPreferredSize(preferredSize );
                
                add(nz4);     
                nz4.addMouseListener(new MouseAdapter() {
                    public void mousePressed(MouseEvent e) {
                    	guanji.Shutdown(null);  
                    }
                    public void mouseReleased(MouseEvent e) {                 
                    }
                });
                
                 
        
        
        setSize(200,200);     
//////////        
        setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent arg0) {
        frameLeft = getLocationOnScreen().x;
        frameTop = getLocationOnScreen().y;
        frameWidth = getWidth();
        frameHeight = getHeight();
        screenXX = java.awt.Toolkit.getDefaultToolkit().getScreenSize().width;
        frameRight =screenXX- frameLeft - frameWidth;
 
        // ��ȡ���������
        rect = new Rectangle(0, 0, frameWidth, frameHeight);
        // ��ȡ����ڴ����λ��
        point =getMousePosition();
 
        if (frameLeft < 0 && isPtInRect(rect, point)) {
            setLocation(0, frameTop); // ��������ߣ����ָ������ʾ���壻
        } else if (frameLeft > -5 && frameLeft < 5 && !(isPtInRect(rect, point))) {
            setLocation(frameLeft - frameWidth + 1, frameTop); // �����Ƶ���߱�Ե���ص���ߣ�
        } else if ((frameTop < 0 && frameLeft < 0) && isPtInRect(rect, point)) {// ���������Ͻǣ�
            setLocation(0, 0);// ���������ˣ����ָ����������ʾ������
        } else if ((frameTop > -5 && frameTop < 5) && (frameLeft > -5 && frameLeft < 5) && !(isPtInRect(rect, point))) {
            // ��������ϱ߿�����Ļ�Ķ��˵ľ���С��5ʱ ��
            // ������겻�ٴ����Ͻ��������ص���Ļ�Ķ���
            setLocation(frameLeft - frameWidth + 1, 1);
        } else if ((frameTop < 0) && isPtInRect(rect, point)) {
            setLocation(frameLeft, 0);// ���������ˣ����ָ����������ʾ������
        } else if (frameTop > -5 && frameTop < 5 && !(isPtInRect(rect, point))) {
            // ��������ϱ߿�����Ļ�Ķ��˵ľ���С��5ʱ ��
            // ������겻�ٴ����Ͻ��������ص���Ļ�Ķ���
            setLocation(frameLeft, 1 - frameHeight);
        } else if (frameRight < 0 && isPtInRect(rect, point)) {
            setLocation(screenXX - frameWidth + 1, frameTop);// �������ұߣ����ָ������ʾ��
        } else if (frameRight > -5 && frameRight < 5 && !(isPtInRect(rect, point))) {
            setLocation(screenXX - 1, frameTop); // �����Ƶ���Ļ�ұ߱�Ե���ص��ұߣ�
        } else if (frameRight < 0 && frameTop < 0 && isPtInRect(rect, point)) {// ���������Ͻǣ�
            setLocation(screenXX - frameWidth + 1, 0);// �������ұߣ����ָ������ʾ��
        } else if ((frameRight > -5 && frameRight < 5) && (frameTop > -5 && frameTop < 5) && !(isPtInRect(rect, point))) {
            setLocation(screenXX - 1, 1); // �����Ƶ���Ļ�ұ߱�Ե���ص��ұߣ�
        }
    }
     
    /**
     * ����Ƿ��ھ��ο���
     * @param rect
     * @param point
     * @return
     */
    public boolean isPtInRect(Rectangle rect, Point point) {
        if (rect != null && point != null) {
            int x0 = rect.x;
            int y0 = rect.y;
            int x1 = rect.width;
            int y1 = rect.height;
            int x = point.x;
            int y = point.y;
 
            return x >= x0 && x < x1 && y >= y0 && y < y1;
        }
        return false;
    }
    public static void main(String[] args){
        FontDemo frame = new FontDemo();
    }
}
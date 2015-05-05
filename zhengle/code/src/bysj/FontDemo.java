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
    private int frameLeft;// 窗体离屏幕左边的距离
    private int frameRight;// 窗体离屏幕右边的距离；
    private int frameTop;// 窗体离屏幕顶部的距离
    private int frameWidth; // 窗体的宽
    private int frameHeight;    // 窗体的高
     
    private int screenXX;// 屏幕的宽度；
    private Point point;    // 鼠标在窗体的位置
 
    
    private int num=0;    // 窗体num
    
    private Timer timer = new Timer(10, this);
    private int xx, yy;
    private boolean isDraging = false; 
    public FontDemo(){
        timer.start();
        setTitle("窗体在屏幕边缘隐藏演示");
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
        nz = new JButton("闹铃");       
        Dimension preferredSize = new Dimension(100,20);//设置尺寸
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
        nz2 = new JButton("备忘录");       
     //   Dimension preferredSize = new Dimension(100,20);//设置尺寸
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
        nz1 = new JButton("通讯录");       
    //    Dimension preferredSize = new Dimension(100,20);//设置尺寸
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
        nz3 = new JButton("桌面便签");       
        //    Dimension preferredSize = new Dimension(100,20);//设置尺寸
            nz3.setPreferredSize(preferredSize );
            
            add(nz3);     
            nz3.addMouseListener(new MouseAdapter() {
                public void mousePressed(MouseEvent e) {
                	
                	JFrame  jf=new JFrame("便签:  "+num);
                	JPanel panel = new JPanel();  
                    JTextArea textArea = new JTextArea();  
                      
                    panel.setLayout(new GridLayout());  
                    textArea.setText("");  //  便签初始内容
                    //当TextArea里的内容过长时生成滚动条  
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
            nz4 = new JButton("定时关机");       
            //    Dimension preferredSize = new Dimension(100,20);//设置尺寸
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
 
        // 获取窗体的轮廓
        rect = new Rectangle(0, 0, frameWidth, frameHeight);
        // 获取鼠标在窗体的位置
        point =getMousePosition();
 
        if (frameLeft < 0 && isPtInRect(rect, point)) {
            setLocation(0, frameTop); // 隐藏在左边，鼠标指到后显示窗体；
        } else if (frameLeft > -5 && frameLeft < 5 && !(isPtInRect(rect, point))) {
            setLocation(frameLeft - frameWidth + 1, frameTop); // 窗体移到左边边缘隐藏到左边；
        } else if ((frameTop < 0 && frameLeft < 0) && isPtInRect(rect, point)) {// 窗体在左上角；
            setLocation(0, 0);// 窗口隐藏了，鼠标指到他，就显示出来；
        } else if ((frameTop > -5 && frameTop < 5) && (frameLeft > -5 && frameLeft < 5) && !(isPtInRect(rect, point))) {
            // 当窗体的上边框与屏幕的顶端的距离小于5时 ，
            // 并且鼠标不再窗体上将窗体隐藏到屏幕的顶端
            setLocation(frameLeft - frameWidth + 1, 1);
        } else if ((frameTop < 0) && isPtInRect(rect, point)) {
            setLocation(frameLeft, 0);// 窗口隐藏了，鼠标指到他，就显示出来；
        } else if (frameTop > -5 && frameTop < 5 && !(isPtInRect(rect, point))) {
            // 当窗体的上边框与屏幕的顶端的距离小于5时 ，
            // 并且鼠标不再窗体上将窗体隐藏到屏幕的顶端
            setLocation(frameLeft, 1 - frameHeight);
        } else if (frameRight < 0 && isPtInRect(rect, point)) {
            setLocation(screenXX - frameWidth + 1, frameTop);// 隐藏在右边，鼠标指到后显示；
        } else if (frameRight > -5 && frameRight < 5 && !(isPtInRect(rect, point))) {
            setLocation(screenXX - 1, frameTop); // 窗体移到屏幕右边边缘隐藏到右边；
        } else if (frameRight < 0 && frameTop < 0 && isPtInRect(rect, point)) {// 窗体在右上角；
            setLocation(screenXX - frameWidth + 1, 0);// 隐藏在右边，鼠标指到后显示；
        } else if ((frameRight > -5 && frameRight < 5) && (frameTop > -5 && frameTop < 5) && !(isPtInRect(rect, point))) {
            setLocation(screenXX - 1, 1); // 窗体移到屏幕右边边缘隐藏到右边；
        }
    }
     
    /**
     * 检测是否在矩形框内
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
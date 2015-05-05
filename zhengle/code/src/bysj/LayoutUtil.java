package bysj;
import javax.swing.*;
import java.awt.*;
public class LayoutUtil
{
	public static void add(Container container,int fill,int anchor,
	int weightx,int weighty,int x,int y,int width,int height,Component comp)
	{
		GridBagConstraints constraints=new GridBagConstraints(); 
		constraints.fill=fill;
		constraints.anchor=anchor;
		constraints.weightx=weightx;
		constraints.weighty=weighty;
		constraints.gridx=x;
		constraints.gridy=y;
		constraints.gridwidth=width;
		constraints.gridheight=height;
		container.add(comp,constraints);
	}
	public static void add(Container container,int fill,int anchor,
	int weightx,int weighty,int x,int y,int width,int height,Component comp,
	Insets insets)
	{
		GridBagConstraints constraints=new GridBagConstraints(); 
		constraints.fill=fill;
		constraints.anchor=anchor;
		constraints.weightx=weightx;
		constraints.weighty=weighty;
		constraints.gridx=x;
		constraints.gridy=y;
		constraints.gridwidth=width;
		constraints.gridheight=height;
		container.add(comp,constraints);
		constraints.insets=insets;
	}
}

package p;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Insets;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import javax.swing.border.EmptyBorder;

class MyFrame extends JFrame{
	
	JPanel panel,messagePanel;
	JScrollPane scrollPane;
	JLabel heading;
	JButton fileChoose;
	JLabel fileName,message;
	
	
	MyFrame(){
		setSize(500,500);
		init();
		createGUI();
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	
	void init(){
		fileChoose = new JButton("Choose File");
		panel = new JPanel();
		messagePanel = new JPanel();
		fileName = new JLabel();
		message = new JLabel();
		heading = new JLabel();
		scrollPane = new JScrollPane(messagePanel);
		
	}
	
	void createGUI(){
		
		panel.setBackground(Color.decode("#DEB877"));
        panel.setLayout(new BoxLayout(panel,BoxLayout.Y_AXIS));
        panel.setBorder(new EmptyBorder(30, 30, 60, 30));
        
		heading.setText("DECLARATION PROCESSOR FOR C");
		heading.setFont(new java.awt.Font("Courier", java.awt.Font.BOLD,20));
		heading.setAlignmentX(JComponent.CENTER_ALIGNMENT);
		
		fileChoose.setMargin(new Insets(10,10,10,10));
		fileChoose.setBackground(Color.decode("#D7AE8F"));
		fileChoose.setForeground(Color.decode("#000000"));
		fileChoose.setContentAreaFilled(false) ;
		fileChoose.setBorderPainted(false);
		fileChoose.setOpaque(true);
		fileChoose.setAlignmentX(JComponent.CENTER_ALIGNMENT);
		
		fileName.setText(" File chosen : ");
		fileName.setAlignmentX(JComponent.CENTER_ALIGNMENT);		
		
		messagePanel.setLayout(new FlowLayout());
		messagePanel.setBackground(Color.WHITE);
		messagePanel.add(message);
		
		panel.add(heading);
		panel.add(Box.createVerticalStrut(20));
		panel.add(fileChoose);
		panel.add(Box.createVerticalStrut(20));
		panel.add(fileName);
		panel.add(Box.createVerticalStrut(20));
		panel.add(scrollPane);
		panel.add(Box.createVerticalStrut(20));
		add(panel);
		
		fileChoose.addMouseListener(new Listener(fileChoose,fileName,message,messagePanel,scrollPane));
	}
}

public class SSMain {
	public static void main(String[] args) {
		new MyFrame();
	}
}

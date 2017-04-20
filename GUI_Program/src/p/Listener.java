package p;

import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

public class Listener extends MouseAdapter{
	JButton button;
	JLabel fileName,message;
	JPanel messagePanel;
	JScrollPane scrollPane;
	
	Listener(JButton button,JLabel fileName, JLabel message, JPanel messagePanel, JScrollPane scrollPane){
		this.button = button;
		this.fileName = fileName;
		this.message = message;
		this.messagePanel = messagePanel;
		this.scrollPane = scrollPane;
	}
	
	@Override
	public void mouseClicked(MouseEvent e){
		JFileChooser chooser = new JFileChooser();
		chooser.setDialogTitle("Load which file");
		int result = chooser.showOpenDialog(null);
		if (result == JFileChooser.APPROVE_OPTION) {
		    File file = chooser.getSelectedFile();
		    fileName.setText(" File chosen : " + file.getAbsolutePath());
		    fileName.setAlignmentX(JComponent.CENTER_ALIGNMENT);
		    
		    /* 
		     * To re-center the label once the File has been chosen.
		     * Otherwise, the entire program will un-align.
		     */
		    try {
			
				Runtime rt = Runtime.getRuntime();
				System.out.println("PATH : " + file.getPath());
				//Process proc = rt.exec(new String[] {"bash","-c",".././output <" + file.getAbsolutePath()});
				Process proc = rt.exec(new String[] {"bash","-c","/Users/Ajay/Documents/MY\\ JAVA\\ PROGRAMS/SystemSoftware_2/output <" + file.getAbsolutePath()});
				BufferedReader stdInput = new BufferedReader(new 
				     InputStreamReader(proc.getInputStream()));

				BufferedReader stdError = new BufferedReader(new 
				     InputStreamReader(proc.getErrorStream()));

				// read the output from the command
				System.out.println("Here is the standard output of the command:\n");
				String s = null;
				int i=0;
				message.setText("<html>");
				while ((s = stdInput.readLine()) != null) {
					
					message.setText(message.getText() + "<br>" + s);
				    System.out.println("LINE " + i + " : " + s);
				    i++;
				    
				}

				// read any errors from the attempted command
				i=0;
				System.out.println("Here is the standard error of the command (if any):\n");
				while ((s = stdError.readLine()) != null) {
					message.setText(message.getText() + "<br>" + s);
				    System.out.println("LINE " + i + " : " + s);
				    i++;
				}
				
				message.setText(message.getText() + "</html>");
				setBorderColor();
				stdInput.close();
				stdError.close();


			} catch (IOException e1) {
				e1.printStackTrace();
			}	
		}
	}
	
	void setBorderColor(){
		if(!message.getText().toLowerCase().contains("no errors")){
			message.setForeground(Color.RED);
			scrollPane.setBorder(BorderFactory.createLineBorder(Color.RED));
		}else{
			message.setForeground(Color.decode("#339966"));
			scrollPane.setBorder(BorderFactory.createLineBorder(Color.GREEN));
		}
	}
	
	@Override
	public void mouseEntered(MouseEvent e){		
		button.setBackground(Color.decode("#8F92D9"));
		button.setForeground(Color.decode("#FFFFFF"));
	}
	
	@Override
	public void mouseExited(MouseEvent e){
		button.setBackground(Color.decode("#D7AE8F"));
		button.setForeground(Color.decode("#000000"));
	}
}

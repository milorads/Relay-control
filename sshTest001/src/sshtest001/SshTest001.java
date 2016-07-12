

package sshtest001;
/**
 *
 * @author Milorad
 */
import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelExec;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.Session;
import java.io.*;

public class SshTest001 {  

    public static void main(String[] args) {
    // jsch is an open source SSH client for Java. 
// get it from <a href="http://www.jcraft.com/jsch/" target="_blank" rel="nofollow">http://www.jcraft.com/jsch/</a>
        
Prozor p1 = new Prozor();
p1.setVisible(true);
 
String user = "username"; // usually root
String password = "password";
String host = "192.168.x.x"; // ip of your Yun
int port=22;
 
try
{
  JSch jsch = new JSch();
  Session session = jsch.getSession(user, host, port);
  session.setPassword(password);
  session.setConfig("StrictHostKeyChecking", "no");  // less than maximally secure
  System.out.println("Establishing connection...");
  p1.dodajutext("Establishing connection...");
  session.connect();
  System.out.println("Connection established.");
  p1.dodajutext("Connection established.");
  Channel channel = session.openChannel("exec");
  
 
  // this stream will be used to send data to the Yun
  DataOutputStream dataOut = new DataOutputStream(channel.getOutputStream());
  channel.setInputStream(null);
 
  // this jsch member class provides remote execution of a shell command
  ((ChannelExec) channel).setCommand("telnet localhost 6571");
 
    ((ChannelExec)channel).setErrStream(System.err);
  InputStream in=channel.getInputStream();
 
  // after configuring all channel parameters, we connect, causing the
  // command to be executed. Results and further input will be handled
  // by the streams
  channel.connect();
 
  byte[] tmp=new byte[1024];
 
  // infinite loop to read the input until the program is killed
  while (true) {
    while (in.available ()>0) {
      int i=in.read(tmp, 0, 1024);
      if (i<0)break;
      System.out.print(new String(tmp, 0, i));

      if(new String(tmp, 0, i)!="\n"){
      p1.dodajutext(new String(tmp, 0, i));}
      
    }
    if (channel.isClosed()) {
      System.out.println("Exit status: "+channel.getExitStatus());
      p1.dodajutext("Exit status: "+channel.getExitStatus());
      break;
    }
    try {
      String input = p1.Status();
      dataOut.writeBytes(input);
      dataOut.flush();
      p1.ocisti();
    }
    catch(Exception ee) {
      System.err.print(ee);
      p1.dodajutext(ee.toString());
    }
  }
  System.out.println("...\n");
  System.out.println("Shutting down...\n");
  p1.dodajutext("Shutting down...\n");
  channel.disconnect();
  session.disconnect();
  System.out.println("Session finished.\n");
  p1.dodajutext("Session finished.\n");
}
catch(Exception e) {
  System.err.print(e);
  p1.dodajutext(e.toString());
}
    }
    
}
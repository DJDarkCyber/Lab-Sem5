import java.io.*;
import java.net.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class Servlet2 extends HttpServlet {
protected void processRequest(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {
response.setContentType("text/html;charset=UTF-8");
PrintWriter out = response.getWriter();
try
{
String n=request.getParameter("uname");
out.println("Hello "+n);
String c=request.getParameter("ucity");
out.println(" You are from "+c);
out.close();
}
catch(Exception e)
{
System.out.println(e);
}
out.close();
}
}
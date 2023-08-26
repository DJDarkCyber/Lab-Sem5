import java.io.*;
import java.net.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class Servlet1 extends HttpServlet {
protected void processRequest(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {
response.setContentType("text/html;charset=UTF-8");
PrintWriter out = response.getWriter();
try
{
String n=request.getParameter("userName");
String c=request.getParameter("userCity");
out.println("<form action=Servlet2>");
out.println("<input type='hidden' name='uname' value='"+n+"'>");
out.println("<input type='hidden' name='ucity' value='"+c+"'>");
out.println("<input type='Submit' value='Just Click Here'>");out.println("</form>");
}
catch(Exception e)
{
System.out.println(e);
}
out.close();
}
}
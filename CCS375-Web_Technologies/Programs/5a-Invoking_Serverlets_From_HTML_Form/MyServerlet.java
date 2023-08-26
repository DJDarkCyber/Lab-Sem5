import java.io.*;
import java.net.*;import javax.servlet.*;
import javax.servlet.http.*;
public class MyServlet extends HttpServlet {
public String msg;
public void init()
{
msg="Hello Servlet programmers";
}
protected void processRequest(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {
response.setContentType("text/html;charset=UTF-8");
PrintWriter out = response.getWriter();
try
{
out.println(msg);
}
catch(Exception e)
{
}
finally
{
out.close();
}
}
}
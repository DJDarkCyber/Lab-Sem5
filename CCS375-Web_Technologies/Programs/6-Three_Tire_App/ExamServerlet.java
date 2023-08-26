import java.io.*;
import java.net.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class ExamServlet extends HttpServlet {
protected void processRequest(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {
int s=0;
response.setContentType("text/html;charset=UTF-8");
PrintWriter out = response.getWriter();
String result=request.getParameter("ans1");
if(result.equals("intercomp"))
s=s+5;
result = request.getParameter("ans2");
if(result.equals("no"))
s=s+5;
result = request.getParameter("ans3");if(result.equals("vbjs"))
s=s+5;
out.println("<html><body><p><center><h1><b>RESULT</b></h1><br><br><hr>"+s+"<hr><h2>T
hanx for ur Participation</h2></center></p></body></html>");
out.close();
}
}
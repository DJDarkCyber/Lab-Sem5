import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/CounterServlet")
public class CounterServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int hitCount = Integer.parseInt(request.getParameter("hitCount")) + 1;

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html><head><title>College Webpage - Session Tracking</title></head><body>");
        out.println("<h1>Page Hit Count: " + hitCount + "</h1>");
        out.println("<form action=\"CounterServlet\" method=\"post\">");
        out.println("<input type=\"hidden\" name=\"hitCount\" value=\"" + hitCount + "\">");
        out.println("<button type=\"submit\">Hit the Page</button>");
        out.println("</form>");
        out.println("</body></html>");
    }
}

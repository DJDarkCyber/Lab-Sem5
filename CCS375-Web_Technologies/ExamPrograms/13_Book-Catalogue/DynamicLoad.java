// BookServlet.java

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/BookServlet")
public class BookServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/yourdatabase", "yourusername", "yourpassword");

            PreparedStatement ps = con.prepareStatement("SELECT * FROM books");
            ResultSet rs = ps.executeQuery();

            out.println("<html><body>");
            out.println("<h2>Book Catalogue</h2>");

            while (rs.next()) {
                out.println("<p>Title: " + rs.getString("title") + ", Author: " + rs.getString("author") + "</p>");
            }

            out.println("</body></html>");

            con.close();
        } catch (Exception e) {
            out.println(e);
        }

        out.close();
    }
}

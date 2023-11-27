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

@WebServlet("/PositiveNegativeReviewsServlet")
public class PositiveNegativeReviewsServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/OnlineShopping", "yourUsername", "yourPassword");

            PreparedStatement ps = con.prepareStatement("SELECT * FROM Reviews");
            ResultSet rs = ps.executeQuery();

            out.println("<html><body>");
            out.println("<h2>Positive and Negative Reviews</h2>");

            while (rs.next()) {
                String userName = rs.getString("userName");
                String reviewText = rs.getString("reviewText");
                int rating = rs.getInt("rating");

                if (rating >= 4) {
                    out.println("<p><strong>Positive Review</strong> from " + userName + ": " + reviewText + "</p>");
                } else {
                    out.println("<p><strong>Negative Review</strong> from " + userName + ": " + reviewText + "</p>");
                }
            }

            out.println("</body></html>");

            con.close();
        } catch (Exception e) {
            out.println(e);
        }

        out.close();
    }
}

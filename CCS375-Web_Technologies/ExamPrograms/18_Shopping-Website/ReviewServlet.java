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

@WebServlet("/ReviewServlet")
public class ReviewServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        try {
            String userName = request.getParameter("userName");
            String reviewText = request.getParameter("reviewText");
            int rating = Integer.parseInt(request.getParameter("rating"));

            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/OnlineShopping", "yourUsername", "yourPassword");

            PreparedStatement ps = con.prepareStatement("INSERT INTO Reviews (userName, reviewText, rating) VALUES (?, ?, ?)");
            ps.setString(1, userName);
            ps.setString(2, reviewText);
            ps.setInt(3, rating);

            ps.executeUpdate();

            con.close();

            out.println("Review submitted successfully!");
        } catch (Exception e) {
            out.println(e);
        }

        out.close();
    }
}

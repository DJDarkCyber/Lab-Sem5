import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        // Assume a simple user authentication (in a real-world scenario, check against a database)
        if (username.equals("user") && password.equals("password")) {
            HttpSession session = request.getSession();
            session.setAttribute("username", username);
            response.sendRedirect("reservation.jsp");
        } else {
            response.sendRedirect("index.jsp");
        }
    }
}

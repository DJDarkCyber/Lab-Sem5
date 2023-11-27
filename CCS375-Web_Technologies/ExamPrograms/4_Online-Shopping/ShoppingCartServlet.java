import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/shoppingCart")
public class ShoppingCartServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Get user ID from session or request parameter
        String userId = request.getParameter("userId");

        // Get or create user's shopping cart
        Cookie[] cookies = request.getCookies();
        Cookie cartCookie = findCookie(cookies, "cart_" + userId);

        if (cartCookie == null) {
            // If the cart cookie doesn't exist, create a new one
            cartCookie = new Cookie("cart_" + userId, "[]");
            response.addCookie(cartCookie);
        }

        // Handle shopping cart logic (add, remove items, etc.)
        // ...

        // Forward to JSP page
        request.getRequestDispatcher("/shoppingCart.jsp").forward(request, response);
    }

    // Utility method to find a cookie by name
    private Cookie findCookie(Cookie[] cookies, String name) {
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (name.equals(cookie.getName())) {
                    return cookie;
                }
            }
        }
        return null;
    }
}

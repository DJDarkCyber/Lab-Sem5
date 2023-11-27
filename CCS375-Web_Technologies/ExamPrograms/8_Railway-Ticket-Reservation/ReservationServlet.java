import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/ReservationServlet")
public class ReservationServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();
        String username = (String) session.getAttribute("username");

        String source = request.getParameter("source");
        String destination = request.getParameter("destination");
        String dateStr = request.getParameter("date");

        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        Date date = null;

        try {
            date = dateFormat.parse(dateStr);
        } catch (ParseException e) {
            e.printStackTrace();
        }

        Reservation reservation = new Reservation(username, source, destination, date);
        List<Reservation> reservations = getReservations(request);
        reservations.add(reservation);

        session.setAttribute("reservations", reservations);
        response.sendRedirect("view_reservations.jsp");
    }

    private List<Reservation> getReservations(HttpServletRequest request) {
        HttpSession session = request.getSession();
        List<Reservation> reservations = (List<Reservation>) session.getAttribute("reservations");

        if (reservations == null) {
            reservations = new ArrayList<>();
        }

        return reservations;
    }
}

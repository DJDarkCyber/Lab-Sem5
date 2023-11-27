<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>

<%@ page import="java.util.Date" %>
<%@ page import="java.text.SimpleDateFormat" %>

<%@ page import="java.util.Locale" %>
<%@ page import="java.util.TimeZone" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="java.util.List" %>

<%@ page import="java.util.Date" %>
<%@ page import="java.text.SimpleDateFormat" %>

<%@ page import="java.util.Locale" %>
<%@ page import="java.util.TimeZone" %>

<!DOCTYPE html>
<html>
<head>
    <title>Railway Ticket Reservation System</title>
</head>
<body>
    <h2>Welcome, <%= session.getAttribute("username") %>!</h2>
    <form action="ReservationServlet" method="post">
        <label for="source">Source Station:</label>
        <input type="text" id="source" name="source" required>
        <br>
        <label for="destination">Destination Station:</label>
        <input type="text" id="destination" name="destination" required>
        <br>
        <label for="date">Date of Travel:</label>
        <input type="date" id="date" name="date" required>
        <br>
        <input type="submit" value="Submit Reservation">
    </form>
</body>
</html>

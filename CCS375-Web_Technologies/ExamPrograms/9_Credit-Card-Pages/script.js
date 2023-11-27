let currentUser = null;

function showPage(page) {
    const pages = ["index", "registration", "login", "profile", "payment"];
    pages.forEach(p => document.getElementById(`${p}Page`).style.display = "none");
    document.getElementById(`${page}Page`).style.display = "block";

    if (page === "profile" && currentUser) {
        document.getElementById("profileUsername").innerText = currentUser;
    }
}

function register() {
    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;
    const confirmPassword = document.getElementById("confirmPassword").value;

    if (password !== confirmPassword) {
        alert("Passwords do not match");
        return;
    }

    // Perform registration logic (mocked for demonstration)
    alert(`Registration successful for ${username}`);
    document.getElementById("registrationForm").reset();
    showPage("login");
}

function login() {
    const loginUsername = document.getElementById("loginUsername").value;
    const loginPassword = document.getElementById("loginPassword").value;

    // Perform login logic (mocked for demonstration)
    if (loginUsername === "user" && loginPassword === "password") {
        currentUser = loginUsername;
        document.getElementById("loginForm").reset();
        showPage("profile");
    } else {
        alert("Invalid username or password");
    }
}

function processPayment() {
    const cardNumber = document.getElementById("cardNumber").value;
    const expiryDate = document.getElementById("expiryDate").value;
    const cvv = document.getElementById("cvv").value;

    // Perform payment processing logic (mocked for demonstration)
    alert("Payment processed successfully");
    document.getElementById("paymentForm").reset();
}

<?php
session_start();
include('connection.php');

// If user is not logged in
if (!isset($_SESSION['username'])) {
    header("Location: studentLogin.php");
    exit;
}

$username = $_SESSION['username'];

$sql = "SELECT s.rollno, s.name, s.address, s.phno, s.username,
               m.science, m.maths, m.english, m.total
        FROM student s
        LEFT JOIN mark m ON s.rollno = m.roll_no
        WHERE s.username = '$username'";

$result = mysqli_query($conn, $sql);
$data = mysqli_fetch_assoc($result);
?>


<h2>Welcome, <?php echo $data['name']; ?>!</h2>

<table border="1">
    <tr><th>Roll No</th><td><?php echo $data['rollno']; ?></td></tr>
    <tr><th>Name</th><td><?php echo $data['name']; ?></td></tr>
    <tr><th>Address</th><td><?php echo $data['address']; ?></td></tr>
    <tr><th>Phone</th><td><?php echo $data['phno']; ?></td></tr>

    <tr><th>Science</th><td><?php echo $data['science']; ?></td></tr>
    <tr><th>Maths</th><td><?php echo $data['maths']; ?></td></tr>
    <tr><th>English</th><td><?php echo $data['english']; ?></td></tr>
    <tr><th>Total Marks</th><td><?php echo $data['total']; ?></td></tr>
</table>

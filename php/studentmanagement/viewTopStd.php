<?php
include("connection.php");

// Query to get the student with highest total marks
$sql = "
    SELECT 
    s.name,
    s.rollno,
    m.science,
    m.maths,
    m.english,
    m.total
FROM student s
JOIN mark m ON s.rollno = m.roll_no
WHERE m.total = (SELECT MAX(total) FROM mark);
";   // only highest scorer

$result = mysqli_query($conn, $sql);
$top = mysqli_fetch_assoc($result);
?>

<html>
<body>
<h2>Top Student</h2>

<table border="1" cellpadding="10">
    <tr>
        <th>Roll No</th>
        <td><?php echo $top['rollno']; ?></td>
    </tr>

    <tr>
        <th>Name</th>
        <td><?php echo $top['name']; ?></td>
    </tr>

    <tr>
        <th>Science</th>
        <td><?php echo $top['science']; ?></td>
    </tr>

    <tr>
        <th>Maths</th>
        <td><?php echo $top['maths']; ?></td>
    </tr>

    <tr>
        <th>English</th>
        <td><?php echo $top['english']; ?></td>
    </tr>

    <tr>
        <th>Total Marks</th>
        <td><b><?php echo $top['total']; ?></b></td>
    </tr>
</table>

</body>
</html>

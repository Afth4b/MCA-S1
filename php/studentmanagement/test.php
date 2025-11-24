<?php
include('connection.php');

$sql = "SELECT * FROM student";
$result = mysqli_query($conn, $sql);
?>

<html>
<head>
    <title>Student Details</title>
    <style>
        table {
            width: 70%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        th, td {
            border: 1px solid #555;
            padding: 10px;
            text-align: center;
        }
        th {
            background-color: #eee;
        }
        a.btn {
            padding: 5px 10px;
            text-decoration: none;
            border-radius: 4px;
            color: white;
        }
        .update-btn {
            background-color: #28a745;
        }
        .delete-btn {
            background-color: #dc3545;
        }
    </style>
</head>
<body>

<h2>Student Details</h2>

<table>
    <tr>
        <th>Roll No</th>
        <th>Name</th>
        <th>Address</th>
        <th>Phone No</th>
        <th>Action</th>
    </tr>

    <?php
    if (mysqli_num_rows($result) > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>
                    <td>{$row['rollno']}</td>
                    <td>{$row['name']}</td>
                    <td>{$row['address']}</td>
                    <td>{$row['phno']}</td>
                    <td>
                        <a class='btn update-btn' href='update.php?rollno={$row['rollno']}'>Update</a>
                        <a class='btn delete-btn' 
                           href='delete.php?rollno={$row['rollno']}'
                           onclick=\"return confirm('Are you sure you want to delete this student including their marks?');\">
                           Delete
                        </a>
                    </td>
                  </tr>";
        }
    }
    ?>

</table>

</body>
</html>

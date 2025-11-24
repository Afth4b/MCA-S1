<?php
include('connection.php');

?>

<html>
    <body>
        <table>
            <tr>
                <th colspan="8">Student Details</th>
            </tr>

            <tr>
                <th>Roll no</th>
                <th>Name</th>
                <th>Address</th>
                <th>Username</th>
                <th>Password</th>
                <th>Phone no</th>
                <th colspan="2">Action</th>
            </tr>

            <?php
            
            $sql = "SELECT * FROM student";
            $result = mysqli_query($conn,$sql);
            
            while($row = mysqli_fetch_assoc($result)) {
                echo"<tr>";
                echo"<td>".$row['rollno']."</td>";
                echo"<td>".$row['name']."</td>";
                echo"<td>".$row['address']."</td>";
                echo"<td>".$row['username']."</td>";
                echo"<td>".$row['password']."</td>";
                echo"<td>".$row['phno']."</td>";
                echo"<td> 
                <form method='POST' action='updateDelete.php'>
                    <input type='hidden' name='rollno' value='".$row['rollno']."'>
                    <input type='submit' value='update' name='update'>
                </form></td>

                <td>
                <form method='POST' action=''>
                    <input type='hidden' name='rollno' value='".$row['rollno']."'>
                    <input type='submit' value='delete' name='delete'>
                </form>
                    
                </td>
                </tr>";
            }
            
            ?>
        </table>
    </body>
</html>


<?php

if(isset($_POST['delete'])){
    $rollno = $_POST['rollno'];
    $sql = "DELETE FROM student WHERE rollno = $rollno";
    if(mysqli_query($conn,$sql)){
        echo "<script>alert('Student data deleted successfully')</script>";
    }else{
        echo "<script>alert('Deletion not possible')</script>";

    }
}

?>
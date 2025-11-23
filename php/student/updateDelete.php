<?php
include('connection.php');
?>

<html>
<body>

<?php
$row = null;   // Prevent undefined variable warning

if(isset($_POST['update'])){
    $rollno = $_POST['rollno'];

    $sql = "SELECT * FROM student WHERE rollno = $rollno";
    $result = mysqli_query($conn,$sql);
    $row = mysqli_fetch_assoc($result);
}
?>

<?php if($row): ?>  <!-- Show form ONLY if $row has data -->

<form action="" method="POST">

    <table>
        <tr><th colspan="2">Student Details Form</th></tr>

        <tr>
            <th>Roll no :</th>
            <td><input type="number" name="rollno" value="<?php echo $row['rollno']; ?>" readonly></td>
        </tr>

        <tr>
            <th>Name :</th>
            <td><input type="text" name="name" value="<?php echo $row['name']; ?>" readonly></td>
        </tr>

        <tr>
            <th>Address :</th>
            <td><input type="text" name="address" value="<?php echo $row['address']; ?>"></td>
        </tr>

        <tr>
            <th>Phone :</th>
            <td><input type="number" name="phoneno" value="<?php echo $row['phno']; ?>"></td>
        </tr>

        <tr>
            <th>Username :</th>
            <td><input type="text" name="username" value="<?php echo $row['username']; ?>"></td>
        </tr>

        <tr>
            <td colspan="2"><input type="submit" name="update1" value="Update"></td>
        </tr>

    </table>

</form>

<?php endif; ?>  <!-- End form display condition -->

</body>
</html>


<?php
// Handle update
if(isset($_POST['update1'])){
    $rollno   = $_POST['rollno'];
    $address  = $_POST['address'];
    $phoneno  = $_POST['phoneno'];
    $username = $_POST['username'];

    $sql = "UPDATE student SET
            address = '$address',
            phno = '$phoneno',
            username = '$username'
            WHERE rollno = $rollno";

    if(mysqli_query($conn,$sql)){
        echo "<script>alert('Student details updated successfully!')</script>";
    } else {
        echo "<script>alert('Updation failed!')</script>";
    }
}
?>

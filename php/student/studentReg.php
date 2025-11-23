<?php
include('connection.php');



?>

<html>
    <body>
        <form action="" method="POST">
            <table>
                <tr>
                    <th><caption>Student Registration</caption></th>
                </tr>

                <tr>
                    <th>Roll no : </th>
                    <td><input type="number" name="rollno"></td>
                </tr>
                

                <tr>
                    <th>Name : </th>
                    <td><input type="text" name="name"></td>
                </tr>
                

                <tr>
                    <th>Address : </th>
                    <td><textarea name="address" id=""></textarea></td>
                </tr>
                

                <tr>
                    <th>Phone no : </th>
                    <td><input type="number" name="phone"></td>
                </tr>
                

                <tr>
                    <th>username : </th>
                    <td><input type="text" name="username"></td>
                </tr>
                

                <tr>
                    <th>password : </th>
                    <td><input type="password" name="password"></td>
                </tr>
                

                <tr>
                    <th>Re-type password : </th>
                    <td><input type="password" name="repassword"></td>
                </tr>
                

                <tr>
                    <th rowspan = "2"><input type="submit" value="Register student" name="register"></th>
                </tr>
                
            </table>
        </form>
    </body>
</html>

<?php

if(isset($_POST['register'])) {
    $rollno = $_POST['rollno'];
    $name = $_POST['name'];
    $address = $_POST['address'];
    $ph = $_POST['phone'];
    $username = $_POST['username'];
    $password = $_POST['password'];
    $repassword = $_POST['repassword'];

    // checking passwords are same
    if($password!=$repassword){
        echo "<script>alert('password do no match..!!')</script>";
        return;
    }


    $sql = "INSERT INTO `student`(`rollno`, `name`, `address`, `phno`, `username`, `password`) VALUES ($rollno,'$name','$address',$ph,'$username','$password')";
    if(mysqli_query($conn,$sql)){
        echo "<script>alert('student registered successfully')</script>";
    }else{
        echo "<script>alert('student not registered...error..!!!')</script>";
    }
}

?>
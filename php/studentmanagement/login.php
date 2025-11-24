<?php
include('connection.php');

if(isset($_POST['login'])){
    $username = $_POST['usname'];
    $password = $_POST['pass'];


    $sql = "SELECT * from admin WHERE username = '$username'";

    $result = mysqli_query($conn,$sql);

    if(mysqli_num_rows($result)==1){
        $row = mysqli_fetch_assoc($result);

        if($row['password'] == $password){
            echo "<script>alert('Login successful');window.location.href='admin.php'</script>";
        }else{
            echo "<script>alert('incorrect password')</script>;";

        }
    }else{
        echo "<script>alert('user not found..!!')</script>;";
    }

}


?>


<html>
    <title>Login Page</title>
    <body>
        <form action="" method="POST">
            <table>
                <tr><caption>Login</caption></tr>

                <tr>
                    <th>Username : </th>
                    <td><input type="text" name="usname" required></td>
                </tr>

                <tr>
                    <th>Password : </th>
                    <td><input type="password" name="pass" required></td>
                </tr>

                <tr>
                    <td><input type="submit" value="login" name="login"></td>
                    <td><input type="reset" value="reset" ></td>
                </tr>
            </table>
        </form>
    </body>
</html>
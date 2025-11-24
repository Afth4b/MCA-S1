<?php

include('connection.php');
session_start();

?>

<html>
    <form action="" method="POST">
    <table>
        <tr>
            <th colspan="2"><caption>Student Login</caption></th>
        </tr>
        
        <tr>
            <th>Username : </th>
            <th><input type="text" name="username"></th>
        </tr>

        <tr>
            <th>Password : </th>
            <th><input type="password" name="password"></th>
        </tr>

        <tr>
            <th colspan="2" ><input type="submit" name="login" value="Login"></th>
        </tr>

    </table>
    </form>


</html>

<?php

if(isset($_POST['login'])) {
    $username = $_POST['username'];
    $pass = $_POST['password'];

    $sql = "SELECT password FROM student WHERE username = '$username'";
    $result = mysqli_query($conn,$sql);
    if(mysqli_num_rows($result) > 0 ){
        $row = mysqli_fetch_assoc($result);
        if($pass == $row['password']){
            $_SESSION['username'] = $username;
                echo "<script>alert('Login successfull');
                        window.location.href = 'studentDash.php'</script>";
        }
    }else{
                echo "<script>alert('Login error..!!');</script>";

    }
    
}

?>
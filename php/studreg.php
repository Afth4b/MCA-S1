<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Student Registration</title>
<style>
    body {
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        background: linear-gradient(135deg, #74ABE2, #5563DE);
        display: flex;
        justify-content: center;
        align-items: flex-start;
        min-height: 100vh;
        margin: 0;
        padding-top: 40px;
    }

    form {
        background: #fff;
        padding: 30px 40px;
        border-radius: 12px;
        box-shadow: 0 8px 20px rgba(0,0,0,0.15);
        width: 400px;
    }

    h2 {
        text-align: center;
        color: #2c3e50;
        margin-bottom: 20px;
    }

    table {
        width: 100%;
    }

    th {
        text-align: left;
        padding: 8px 0;
        font-weight: bold;
        color: #2c3e50;
        vertical-align: top;
    }

    td {
        padding: 4px 0;
    }

    input[type="text"], 
    input[type="number"], 
    input[type="password"], 
    textarea {
        width: 100%;
        padding: 8px 10px;
        border: 1px solid #ccc;
        border-radius: 6px;
        font-size: 14px;
        transition: 0.3s;
        resize: none;
    }

    input[type="text"]:focus, 
    input[type="number"]:focus, 
    input[type="password"]:focus, 
    textarea:focus {
        border-color: #5563DE;
        box-shadow: 0 0 5px rgba(85,99,222,0.4);
        outline: none;
    }

    button {
        width: 48%;
        padding: 10px;
        margin-top: 15px;
        border: none;
        border-radius: 6px;
        cursor: pointer;
        font-size: 16px;
        transition: 0.3s;
        color: white;
    }

    button[type="submit"] {
        background-color: #27ae60;
    }

    button[type="submit"]:hover {
        background-color: #219150;
    }

    button[type="reset"] {
        background-color: #e74c3c;
    }

    button[type="reset"]:hover {
        background-color: #c0392b;
    }

    .btn-container {
        display: flex;
        justify-content: space-between;
    }
</style>
</head>
<body>

<form action="" method="post" onsubmit="return pasval()">
    <h2>Student Registration</h2>
    <table>
        <tr>
            <th>NAME :</th>
            <td><input type="text" name="name" id="name"></td>
        </tr>
        <tr>
            <th>Roll No :</th>
            <td><input type="number" name="roll" id="roll"></td>
        </tr>
        <tr>
            <th>ADDRESS :</th>
            <td><textarea name="adrs" id="adrs" rows="3">Enter your address here</textarea></td>
        </tr>
        <tr>
            <th>PHONE NO :</th>
            <td><input type="number" name="ph" id="ph"></td>
        </tr>
        <tr>
            <th>USERNAME :</th>
            <td><input type="text" name="usr" id="usr"></td>
        </tr>
        <tr>
            <th>PASSWORD :</th>
            <td><input type="password" name="pass" id="pass"></td>
        </tr>
        <tr>
            <th>RE-ENTER PASSWORD :</th>
            <td><input type="password" name="repass" id="repass"><br><p id="PASS" style="color:red;"></p></td>
        </tr>
        <tr>
            <td colspan="2">
                <div class="btn-container">
                    <button type="submit" name="submit">SUBMIT</button>
                    <button type="reset" name="reset">RESET</button>
                </div>
            </td>
        </tr>
    </table>
</form>
<script>
    function pasval(){
        var pass=document.getElementById('pass').value;
        var repass=document.getElementById('repass').value;

        if(pass!=repass){
            document.getElementById('PASS').innerHTML="ReEntering password must be equal to Passord";
            return false;
        }else{
            return true;
        }
    }
</script>

</body>
</html>

<?php
if(isset($_POST['submit'])){
    $conn=mysqli_connect('localhost','root','','students');
        if(!$conn){
        echo "<script>alert('connection error')</script>";
    }
    $name=$_POST['name'];
    $rollno=$_POST['roll'];
    $address=$_POST['adrs'];
    $phno=$_POST['ph'];
    $username=$_POST['usr'];
    $password=$_POST['pass'];
    $repassword=$_POST['repass'];

    $sql="SELECT rollno FROM stud WHERE rollno='$rollno'";
    $result=mysqli_query($conn,$sql);
    if(mysqli_num_rows($result)>0){
        echo "<script>alert('Roll no already excists!!!!!')</script>"; 
    }else{
        $sql="INSERT INTO stud VALUES('$name',$rollno,'$address',$phno,'$username','$password','$repassword')";
        if(mysqli_query($conn,$sql)){
            echo "<script>alert('Data inserted successfully');document.location='studreg.php'</script>";
        }
    }
}
?>

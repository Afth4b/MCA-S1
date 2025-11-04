<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Update Marks</title>
<style>
    body {
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        background: linear-gradient(135deg, #74ABE2, #5563DE);
        color: #333;
        display: flex;
        justify-content: center;
        align-items: flex-start;
        height: 100vh;
        margin: 0;
        padding-top: 40px;
    }

    form {
        background: #fff;
        padding: 30px 40px;
        border-radius: 12px;
        box-shadow: 0 8px 20px rgba(0,0,0,0.15);
        width: 380px;
    }

    h3, h4 {
        text-align: center;
        color: #2c3e50;
        margin-bottom: 10px;
    }

    p {
        font-weight: bold;
        margin: 8px 0 4px;
    }

    input[type="number"] {
        width: 100%;
        padding: 8px;
        border: 1px solid #ccc;
        border-radius: 6px;
        font-size: 15px;
        transition: 0.3s;
    }

    input[type="number"]:focus {
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

    button[name="update"] {
        background-color: #27ae60;
    }

    button[name="update"]:hover {
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

    .readonly-input {
        background-color: #f7f7f7;
        cursor: not-allowed;
    }
</style>
</head>
<body>

<form action="" method="post">
<?php
$conn = mysqli_connect('localhost','root','','student');

if(isset($_POST['roll'])) {
    $rollno = $_POST['roll']; 
    $sql="SELECT name,rollno,m1,m2,m3,m4,m5,m6 FROM mark WHERE rollno='$rollno'";
    $result = mysqli_query($conn,$sql); 

    if(mysqli_num_rows($result) > 0){
        $row = mysqli_fetch_assoc($result);
        echo "<h3>Student Marks Update</h3>";
        echo "<h4>" . $row['name'] . " (Roll No: $rollno)</h4>";
        echo "<p>Roll No:</p><input class='readonly-input' type='number' value='".$rollno."' name='roll' readonly>";
        echo "<p>Mark 1:</p><input type='number' value='" . $row['m1'] . "' name='m1'>";
        echo "<p>Mark 2:</p><input type='number' value='" . $row['m2'] . "' name='m2'>";
        echo "<p>Mark 3:</p><input type='number' value='" . $row['m3'] . "' name='m3'>";
        echo "<p>Mark 4:</p><input type='number' value='" . $row['m4'] . "' name='m4'>";
        echo "<p>Mark 5:</p><input type='number' value='" . $row['m5'] . "' name='m5'>";
        echo "<p>Mark 6:</p><input type='number' value='" . $row['m6'] . "' name='m6'>";
    }
}
?>

<div class="btn-container">
    <button type="submit" name="update">Update</button>
    <button type="reset" onclick="reset()">Reset</button>
</div>
<script>
    function reset(){
        window.location="dp.php";
    }
</script>
</form>

<?php
if(isset($_POST['update'])){
    $conn = mysqli_connect('localhost','root','','student');
    $rollno = $_POST['roll'];
    $m1 = $_POST["m1"];
    $m2 = $_POST["m2"];
    $m3 = $_POST["m3"];
    $m4 = $_POST["m4"];
    $m5 = $_POST["m5"];
    $m6 = $_POST["m6"];

    $sql = "UPDATE mark 
            SET m1='$m1', m2='$m2', m3='$m3', m4='$m4', m5='$m5', m6='$m6' 
            WHERE rollno='$rollno'";
    if(mysqli_query($conn,$sql)){
        echo "<script>alert('Data updated successfully!');</script>";
    } else {
        echo "<script>alert('Error updating data');</script>";
    }
}
?>
</body>
</html>

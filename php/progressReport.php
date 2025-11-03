<html>
<style>
    /* Basic Reset */
    * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
        font-family: Arial, sans-serif;
    }

    body {
        display: flex;
        justify-content: center;
        align-items: center;
        min-height: 100vh;
        background-color: #f0f2f5;
    }

    table {
        width: 500px;
        border-collapse: collapse;
        background-color: #fff;
        box-shadow: 0 8px 16px rgba(0, 0, 0, 0.2);
        border-radius: 10px;
        overflow: hidden;
    }

    caption {
        font-size: 1.5em;
        font-weight: bold;
        padding: 20px 0;
        background-color: #007bff;
        color: #fff;
    }

    th, td {
        padding: 12px 20px;
        text-align: left;
        border-bottom: 1px solid #ddd;
    }

    th {
        background-color: #f7f7f7;
        font-weight: normal;
        width: 50%;
    }

    tr:last-child td {
        border-bottom: none;
    }

    tr:nth-child(even) {
        background-color: #f9f9f9;
    }

    /* Highlight Total, Percentage, and Grade */
    tr:nth-last-child(3) td,
    tr:nth-last-child(2) td,
    tr:last-child td {
        font-weight: bold;
        color: #007bff;
    }
</style>

</html>

<?php

$conn = mysqli_connect('localhost','root','','student');

if(!$conn){
    echo "<script>alert('connection error')</script>";
}


$name=$_POST["name"];
$roll=$_POST["rollno"];
$gender = $_POST["gender"];
$m1=$_POST["m1"];
$m2=$_POST["m2"];
$m3=$_POST["m3"];
$m4=$_POST["m4"];
$m5=$_POST["m5"];
$m6=$_POST["m6"];

$total=$m1+$m2+$m3+$m4+$m5+$m6;
$p=($total/360)*100;

if($p>=90){
    $grade="A";
}
else if($p>=80){
    $grade="B";
}
else if($p>=70){
    $grade="C";
}
else if($p>=60){
    $grade="D";
}
else if($p>=50){
    $grade="P";
}
else{
    $grade="F";
}

$sql = "SELECT rollno FROM mark WHERE rollno = $roll";

$result = mysqli_query($conn,$sql);

if(mysqli_num_rows($result)>0){
    echo "<script>alert('This roll number already exists')</script>";
    
}else{
    $sql = "INSERT INTO mark VALUES ($roll,'$name',$m1,$m2,$m3,$m4,$m5,$m6,$total,$p,'$grade','$gender')";

    if(mysqli_query($conn,$sql)){
        echo "<script>alert('Data inserted successfully');document.location='progressReport.html'</script>";
}
}



?>

<table>
    <caption>STUDENT PROGRESS CARD</caption>
    <tr>
        <th>NAME :</th>
        <th><?php echo $name ?></th>
    </tr>
    <tr>
        <th>ROLL NO :</th>
        <th><?php echo $roll ?></th>
    </tr>
    <tr>
        <th>Digital Fundamentals :</th>
        <th><?php echo $m1 ?></th>
    </tr>
    <tr>
        <th>Data Structure :</th>
        <th><?php echo $m2 ?></th>
    </tr>
    <tr>
        <th>Maths :</th>
        <th><?php echo $m3 ?></th>
    </tr>
    <tr>
        <th>Software Engineering :</th>
        <th><?php echo $m4 ?></th>
    </tr>
    <tr>
        <th>Python Programming :</th>
        <th><?php echo $m5 ?></th>
    </tr>
    <tr>
        <th>Web Programming :</th>
        <th><?php echo $m6 ?></th>
    </tr>
    <tr>
        <th>TOTAL MARKS :</th>
        <th><?php echo $total ?></th>
    </tr>
    <tr>
        <th>MARKS PERCENTAGE :</th>
        <th><?php echo $p ?></th>
    </tr>
    <tr>
        <th>GRADE :</th>
        <th><?php echo $grade ?></th>
    </tr>
</table>
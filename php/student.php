<?php

$conn = mysqli_connect('localhost','root','','student');

if(!$conn){
    echo "DB not connected..!!";
}

$rollno = $_POST['rollno'];
$name = $_POST['name'];

$sql = "INSERT INTO stud (rollno, name) VALUES ($rollno, '$name')";

if($conn->query($sql)=== TRUE){
    echo "<script>alert('Data inserted successfully')</script>";
}else{
    echo "<script>alert('Data not inserted...errorrrrrrrrrr')</script>";
}


?>
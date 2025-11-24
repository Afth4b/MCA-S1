<?php

$conn = mysqli_connect('localhost','root','','student');

if(!$conn){
    echo "<script>alert('database not connected..!!')</script>";
}

?>
<form action="dp.php" method="post">
<label for="" >Roll No : </label>
<select name="roll" id="">

<?php
$conn = mysqli_connect('localhost','root','','student');
if(!$conn){
    echo "<script>alert('connection error')</script>";
}

$sql = "SELECT rollno from mark";
$result = mysqli_query($conn,$sql);

if(mysqli_num_rows($result)>0){
    while($row = mysqli_fetch_assoc($result)){
        echo "<option value= ".$row['rollno'].">".$row['rollno']."</option>";
    }
}


?>

</select>
<button type="submit" name="search">Search</button>
</form>



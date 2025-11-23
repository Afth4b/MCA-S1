<?php

include('connection.php');

?>

<html>
    <form action="" method="POST">
        <table>
            <caption>Mark Entry Form</caption>

            <tr>
                <th>Roll no : </th>
                <td>
                    <select name="rollno" id="">
                        <option value="" name="roll">Select roll no</option>
                        <?php
                        $sql = "SELECT rollno FROM student";
                        $result = mysqli_query($conn,$sql);
                        if(mysqli_num_rows($result)>0){
                            while($row = mysqli_fetch_assoc($result)){
                                echo "<option value= ".$row['rollno'].">".$row['rollno']."</option>";
                            }
                        }
                        ?>
                    </select>
                </td>

                <th><input type="submit" name="search" value="search"></th>
            </tr>

            
        </table>
    </form>
</html>

<?php

if(isset($_POST['search'])){
    $rollno = $_POST['rollno'];
    $sql = "SELECT name, rollno FROM student where rollno = $rollno";
    $result = mysqli_query($conn,$sql);
    if(mysqli_num_rows($result)==1){
        $row = mysqli_fetch_assoc($result);

        echo "<form method='POST'>";
        echo "<table>";
        echo "<tr>";
        echo "<th>Name : </th>";
        echo "<th><input type='text' name='name' value='".$row['name']."' readonly>";
        echo "</tr>";

        echo "<tr>";
        echo "<th>Roll no : </th>";
        echo "<th><input type='number' name='rollno' value='".$row['rollno']."' readonly> </th>";
        echo "</tr>";
        

        echo "<tr>";
        echo "<th>Science : </th>";
        echo "<th><input type='number' name='science'> </th>";
        echo "</tr>";

        echo "<tr>";
        echo "<th>Maths : </th>";
        echo "<th><input type='number' name='maths'> </th>";
        echo "</tr>";

        echo "<tr>";
        echo "<th>English : </th>";
        echo "<th><input type='number' name='english'> </th>";
        echo "</tr>";

        echo "<tr>";
        echo "<th><input type='submit' name='submit'></submit>";
        echo "<th><input type='reset' ></Reset>";

        echo "<table>";
    }
}

if(isset($_POST['submit'])){

    $rollno = $_POST['rollno'];

    $sql = "SELECT roll_no FROM mark WHERE roll_no = $rollno";
    if(mysqli_num_rows(mysqli_query($conn,$sql))>0){
        echo "<script>alert('Mark already uploaded..!!')</script>";
        return;
    }else{
        $mark1 = $_POST['science'];
        $mark2 = $_POST['maths'];
        $mark3 = $_POST['english'];

        if($mark1>60 || $mark2>60 || $mark3>60){
            echo "<script>alert('Mark should be out of 60 for every subjects')</script>";
            return;
        }else{
            $total = $mark1 + $mark2 + $mark3;

            $sql = "INSERT INTO `mark`(`roll_no`, `science`, `maths`, `english`, `total`) VALUES ($rollno,$mark1,$mark2,$mark3,$total)";
            if(mysqli_query($conn,$sql)){
                echo "<script>alert('Marks inserted successfully...!!')</script>";
            }else{
                echo "<script>alert('Insertion cannot be done....error..!!')</script>";

            }
        }
    }

    

}
?>
<?php
include('connection.php');
?>

<html>
<body>

<!-- FIRST FORM : SELECT ROLL NUMBER -->
<form action="" method="POST">
    <table>
        <caption>Mark Update Form</caption>

        <tr>
            <th>Roll no :</th>
            <td>
                <select name="rollno">
                    <option value="">Select roll no</option>

                    <?php
                    $sql = "SELECT roll_no FROM mark";
                    $result = mysqli_query($conn,$sql);

                    while($row = mysqli_fetch_assoc($result)){
                        echo "<option value='".$row['roll_no']."'>".$row['roll_no']."</option>";
                    }
                    ?>
                </select>
            </td>

            <td><input type="submit" name="search" value="Search"></td>
        </tr>

    </table>
</form>



<?php
/* ------------------------------------------------------
   IF SEARCH BUTTON IS CLICKED 
------------------------------------------------------ */

if(isset($_POST['search'])){
    $rollno = $_POST['rollno'];

    $sql = "SELECT student.name, mark.roll_no, mark.science, mark.maths, mark.english
            FROM student 
            INNER JOIN mark ON student.rollno = mark.roll_no 
            WHERE mark.roll_no = $rollno";

    $result = mysqli_query($conn, $sql);

    if(mysqli_num_rows($result) == 1){
        $row = mysqli_fetch_assoc($result);
?>

<!-- SECOND FORM : UPDATE MARKS -->
<form method="POST">
    <table>

        <tr>
            <th>Name :</th>
            <td><input type="text" name="name" value="<?php echo $row['name']; ?>" readonly></td>
        </tr>

        <tr>
            <th>Roll no :</th>
            <td><input type="number" name="rollno" value="<?php echo $row['roll_no']; ?>" readonly></td>
        </tr>

        <tr>
            <th>Science :</th>
            <td><input type="number" name="science" value="<?php echo $row['science']; ?>"></td>
        </tr>

        <tr>
            <th>Maths :</th>
            <td><input type="number" name="maths" value="<?php echo $row['maths']; ?>"></td>
        </tr>

        <tr>
            <th>English :</th>
            <td><input type="number" name="english" value="<?php echo $row['english']; ?>"></td>
        </tr>

        <tr>
            <td><input type="submit" name="update" value="Update"></td>
            <td><input type="reset"></td>
        </tr>

    </table>
</form>

<?php
    }
}
?>


<?php


if(isset($_POST['update'])){

    $rollno = $_POST['rollno'];
    $mark1 = $_POST['science'];
    $mark2 = $_POST['maths'];
    $mark3 = $_POST['english'];

    // MARK VALIDATION
    if($mark1 > 60 || $mark2 > 60 || $mark3 > 60){
        echo "<script>alert('Mark should be out of 60 for every subject')</script>";
    } else {

        $total = $mark1 + $mark2 + $mark3;

        // CORRECT SQL UPDATE
        $sql = "UPDATE mark SET 
                    science = '$mark1',
                    maths   = '$mark2',
                    english = '$mark3',
                    total   = '$total'
                WHERE roll_no = $rollno";

        if(mysqli_query($conn,$sql)){
            echo "<script>alert('Marks updated successfully!')</script>";
        } else {
            echo "<script>alert('Updation failed!')</script>";
        }
    }
}
?>

</body>
</html>

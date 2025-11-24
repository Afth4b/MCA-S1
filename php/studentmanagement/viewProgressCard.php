<?php
include('connection.php');
$row1 = null;
?>

<html>
    <form action="" method="POST">
        <table>
            <tr>
                <th colspan="View Top student"></th>
            </tr>

            <tr>
                <th>Roll no : </th>
                <td>
                
                    <select name="rollno" id="">
                        <option value="">choose rollno</option>
                        <?php
                    
                        $sql = "SELECT roll_no from mark";
                        $result = mysqli_query($conn,$sql);
                        while($row = mysqli_fetch_assoc($result)){
                            echo "<option value='".$row['roll_no']."' name='rollno'>".$row['roll_no']."</option>";
                        }

                        ?>
                    </select>

                    <input type="submit" name="search" value="search">
                </td>
            </tr>
        </table>
    </form>

<?php
if (isset($_POST['search'])) {

    $rollno = mysqli_real_escape_string($conn, $_POST['rollno']);

    $sql = "SELECT s.name, m.roll_no, m.science, m.maths, m.english, m.total 
            FROM student s 
            JOIN mark m ON s.rollno = m.roll_no 
            WHERE m.roll_no = '$rollno'";

    $result = mysqli_query($conn,$sql);
    $row1 = mysqli_fetch_assoc($result);
}

if ($row1) {
?>
<table>
    <tr>
        <th>Name :</th>
        <td><input type="text" value="<?= $row1['name']; ?>" readonly></td>
    </tr>

    <tr>
        <th>Science :</th>
        <td><input type="text" value="<?= $row1['science']; ?>" readonly></td>
    </tr>

    <tr>
        <th>Maths :</th>
        <td><input type="text" value="<?= $row1['maths']; ?>" readonly></td>
    </tr>

    <tr>
        <th>English :</th>
        <td><input type="text" value="<?= $row1['english']; ?>" readonly></td>
    </tr>

    <tr>
        <th>Total :</th>
        <td><input type="text" value="<?= $row1['total']; ?>" readonly></td>
    </tr>
</table>
<?php } ?>
</html>
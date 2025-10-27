

<html>
<form action="">

<label for="">Name :</label>
<input type="text" name="name"><br>
<label for="">Select your age</label>
<select name="" id="">

    <?php
    for($i=1;$i<100;$i++)
        echo"<option value=".$i.">".$i."</option>";
    ?>

</select>
<br>
<button type="submit">submit</button>
</form>
</html>

<?php



?>
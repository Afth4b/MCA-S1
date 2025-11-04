<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Page</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f2f2f2;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        form {
            background: white;
            padding: 30px 40px;
            border-radius: 10px;
            box-shadow: 0 8px 20px rgba(0,0,0,0.2);
        }

        table {
            width: 100%;
        }

        input[type="text"], input[type="password"] {
            width: 100%;
            padding: 8px;
            margin: 5px 0 15px;
            border: 1px solid #ccc;
            border-radius: 5px;
        }

        input[type="submit"], input[type="reset"] {
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            color: white;
            font-weight: bold;
        }

        input[type="submit"] {
            background-color: #27ae60;
            margin-right: 10px;
        }

        input[type="submit"]:hover {
            background-color: #219150;
        }

        input[type="reset"] {
            background-color: #e74c3c;
        }

        input[type="reset"]:hover {
            background-color: #c0392b;
        }
    </style>
</head>
<body>
    <form action="login.php" method="post">
        <table>
            <caption><h3>LOGIN</h3></caption>
            <tr>
                <th><label for="usr">Username :</label></th>
                <th><input type="text" name="usr" id="usr" required></th>
            </tr>
            <tr>
                <th><label for="pass">Password :</label></th>
                <th><input type="password" name="pass" id="pass" required></th>
            </tr>
            <tr>
                <th colspan="2"><input type="submit" value="Login">
                <input type="reset" value="Reset"></th>
            </tr>
        </table>
    </form>
</body>
</html>

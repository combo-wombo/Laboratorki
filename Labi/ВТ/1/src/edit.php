<HTML>
<head>
  <title>
    Edit item
  </title>
</head>
<body>
<style><?php include 'style.css'; ?></style>
<h1>Edit Profile</h1>
<div class="window">
<fieldset>
<legend>Edit entry</legend>
    <form name="frmContact" method="post" action="contact.php">
        <?php
        $con = mysqli_connect('localhost', 'root', '','db_contact_lab1');
        $id = $_REQUEST['name'];
        $sql = "SELECT name, job, department, number, date, email, comment FROM table1 WHERE id = $id";
        $result = $con->query($sql);
        $row = $result->fetch_assoc();
        
        $name = $row["name"];
        $job = $row["job"];
        $department = $row["department"];
        $number = $row["number"];
        $date = $row["date"];
        $email = $row["email"];
        $comment = $row["comment"];

        echo "  <p>
                    <label for=\"Name\">Name: </label><br>
                    <input value=\"$name\" type=\"text\" name=\"name\" id=\"name\">
                </p>
                <p>
                    <label for=\"Name\">Job: </label><br>
                    <input value=\"$job\" type=\"text\" name=\"job\" id=\"job\">
                </p>
                <p>
                    <label for=\"Name\">Depatrment: </label><br>
                        <input type=\"radio\" id=\"M&M\" name=\"department\" value=\"M&M\">
                        <label for=\"M&M\">M&M</label><br>
                        <input type=\"radio\" id=\"ACCOUNTING\" name=\"department\" value=\"Accounting\">
                        <label for=\"ACCOUNTING\">Accounting</label><br>
                        <input type=\"radio\" id=\"Media\" name=\"department\" value=\"Media\">
                        <label for=\"Media\">Media</label>
                </p>
                <p>
                    <label for=\"Name\">Phone number: </label><br>
                    <input value=\"$number\" type=\"text\" name=\"number\" id=\"number\">
                </p>
                <p>
                    <label for=\"Name\">Date: </label><br>
                    <input value=\"$date\" type=\"text\" name=\"date\" id=\"date\">
                </p>
                <p>
                    <label for=\"Name\">Email: </label><br>
                    <input value=\"$email\" type=\"email\" name=\"email\" id=\"email\">
                </p>
                <p>
                    <label for=\"Name\">Comment: </label><br>
                    <textarea name=\"comment\" id=\"comment\">$comment</textarea>
                </p>

                <p>
                    <button class=\"edit_buttons\" type=\"submit\" name=\"Submit\" id=\"Submit\" value=\"Submit\">Submit</button>
                    <button class=\"edit_buttons\" type=\"reset\">Reset</button>
                </p>
        ";
        $sql = "DELETE FROM table1 WHERE id = $id"; 
        $result = $con->query($sql);
        ?>
    </form>
    </fieldset>
</div>

</body>
</HTML>
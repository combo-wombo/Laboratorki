<?php
    if (isset($_POST['firstName'])) {
        include "addClient.php";
    }
?>
<!doctype html>
<html>
    <head>
        <link rel="stylesheet" href="css/style.css">
    </head>
    <body>
        <div class=header><a href=index.php class=button>Go back</a> Lab 1. Add client</div>
        <div class="container">
            <form action="editClients.php" method="post">
                <p>Firstname: <input required type="text" name="firstName" /></p>
                <p>Lastname: <input required type="text" name="lastName" /></p>
                <p>Document ID: <input required type="number" name="documentID" /></p>
                <p>Phone number: <input type="tel" name="number" /></p>
                <p><input type="submit" value="Add client"></input></p>
            </form>

            <?php
                include "output.php";
                clientsOut();
            ?>

        </div>
    </body>
</html>
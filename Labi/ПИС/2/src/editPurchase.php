<?php
    if (isset($_POST['clients_id'])) {
        include "addPurchase.php";
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

            <form action="editPurchase.php" method="post">
                <p>Client ID: <input required type="number" name="clients_id" /></p>
                <p>Product ID: <input required type="number" name="products_id" /></p>
                <p><input type="submit" value="Add purchase"></input></p>
            </form>

            <?php
                include "output.php";
                purchasesOut();
            ?>

        </div>
    </body>
</html>
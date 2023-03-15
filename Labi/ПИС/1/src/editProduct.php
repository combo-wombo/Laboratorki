<?php
    if (isset($_POST['title'])) {
        include "addProduct.php";
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

            <form action="editProduct.php" method="post">
                <p>Product name: <input required type="text" name="title" /></p>
                <p>Manufacturer: <input required type="text" name="firm" /></p>
                <p>Price: <input required type="number" step="0.01" name="price" /></p>
                <p><input type="submit" value="Add client"></input></p>
            </form>

            <?php
                include "output.php";
                productsOut();
            ?>

        </div>
    </body>
</html>
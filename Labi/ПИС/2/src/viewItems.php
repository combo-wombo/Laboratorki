<!doctype html>
<html>
    <head>
        <link rel="stylesheet" href="css/style.css">
    </head>
    <body>
        <div class=header><a href=index.php class=button>Go back</a> Lab 1. View all</div>
        <div class="container" id="viewAll">
            <?php
                include "output.php";
                clientsOut();
                productsOut();
                purchasesOut();
            ?>

        </div>
    </body>
</html>
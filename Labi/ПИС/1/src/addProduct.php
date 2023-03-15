
<?php 
$title = $_POST['title'];
$firm = $_POST['firm'];
$price = $_POST['price'];
$connection = mysqli_connect('localhost', 'root', '', 'pis_1');
$query = "INSERT INTO products (products_id, title, firm, price) VALUES (NULL, '$title', '$firm', '$price')";
try {
	$result = mysqli_query($connection, $query);
	echo '<div class="SuccessText">Product "'.$title.'" added to database.</div>';
} catch (mysqli_sql_exception $e) {
    echo '<div class="FailText">There was an error processing your request. ('.$e->getMessage().')</div>';
}
?>

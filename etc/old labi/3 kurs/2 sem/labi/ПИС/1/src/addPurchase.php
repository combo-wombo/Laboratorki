<?php 
$products_id = $_POST['products_id'];
$clients_id = $_POST['clients_id'];
$connection = mysqli_connect('localhost', 'root', '', 'pis_1');

$query_getClients = "SELECT clients_id FROM clients WHERE clients_id = '$clients_id'";
$query_getProducts = "SELECT products_id FROM products WHERE products_id = '$products_id'";
$result_clients = mysqli_query($connection, $query_getClients);
$result_products = mysqli_query($connection, $query_getProducts);
if($result_clients->num_rows !== 0){
	if($result_products->num_rows !== 0){
		$query = "INSERT INTO purchases (purchases_id, clients_id, products_id) VALUES (NULL, '$clients_id', '$products_id')";
		try {
			$result = mysqli_query($connection, $query);
			echo '<div class="SuccessText">Purchase added to database.</div>';
		} catch (mysqli_sql_exception $e) {
			echo '<div class="FailText">There was an error processing your request. ('.$e->getMessage().')</div>';
		}
	} else {
		echo '<div class="FailText">There was an error processing your request. (no such product)</div>';
	}
} else {
	echo '<div class="FailText">There was an error processing your request. (no such client)</div>';
}
?>
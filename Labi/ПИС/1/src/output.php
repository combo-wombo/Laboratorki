<?php 
function productsOut(){
	$connection = mysqli_connect('localhost', 'root', '', 'pis_1');
	$query = "SELECT * FROM `products`";
	$result = mysqli_query($connection, $query) or die("Error in query productsOut()");
	echo '<table><tr><th>ID</th><th>Title</th><th>Firm</th><th>Price</th></tr>';
	while($row = mysqli_fetch_array($result)){
		echo '<tr><td>'.$row['products_id'].'</td><td>'.$row['title'].'</td><td>'.$row['firm'].'</td><td>'.$row['price'].'</td></tr>';
	}
	echo '</table>';
}

function clientsOut(){
	$connection = mysqli_connect('localhost', 'root', '', 'pis_1');
	$query = "SELECT * FROM `clients`";
	$result = mysqli_query($connection, $query) or die("Error in query clientsOut()");
	echo '<table><tr><th>ID</th><th>First name</th><th>Last Name</th><th>Document ID</th><th>Number</th></tr>';
	while($row = mysqli_fetch_array($result)){
		echo '<tr><td>'.$row['clients_id'].'</td><td>'.$row['firstName'].'</td><td>'.$row['lastName'].'</td><td>'.$row['documentID'].'</td><td>'.$row['numberTel'].'</td></tr>';
	}
	echo '</table>';
}

function purchasesOut(){
	$connection = mysqli_connect('localhost', 'root', '', 'pis_1');
	$query = "SELECT * FROM `purchases`";
	$result = mysqli_query($connection, $query) or die("Error in query purchasesOut()");
	echo '<table><tr><th>Purchases_id</th><th>Clients_id</th><th>Products_id</th></tr>';
	while($row = mysqli_fetch_array($result)){
		echo '<tr><td>'.$row['purchases_id'].'</td><td>'.$row['clients_id'].'</td><td>'.$row['products_id'].'</td></tr>';
	}
	echo '</table>';
}

?>
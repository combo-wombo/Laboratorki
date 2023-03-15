<?php 
$firstName = $_POST['firstName'];
$lastName = $_POST['lastName'];
$documentID = $_POST['documentID'];
$number = $_POST['number'];
$connection = mysqli_connect('localhost', 'root', '', 'pis_1');
$query = "INSERT INTO clients (clients_id, firstName, lastName, documentID, numberTel) VALUES (NULL, '$firstName', '$lastName', '$documentID', '$number')";
try {
	$result = mysqli_query($connection, $query);
	echo '<div class="SuccessText">Client "'.$firstName.'" added to database.</div>';
} catch (mysqli_sql_exception $e) {
    echo '<div class="FailText">There was an error processing your request. ('.$e->getMessage().')</div>';
}

?>


<?php

$con = mysqli_connect('localhost', 'root', '','db_contact_lab1');

$name = $_POST['name'];
$job = $_POST['job'];
$department = $_POST['department'];
$number = $_POST['number'];
$date = $_POST['date'];
$email = $_POST['email'];
$comment = $_POST['comment'];

//get last id and increment
//$rs = mysqli_query($con, "SELECT MAX(id) FROM tbl_contact");
//$lastid = $rs->fetch_column(0);
//$lastid++;

$sql = "INSERT INTO `table1` (`name`, `job`, `department`, `number`, `date`, `email`, `comment`) VALUES ('$name', '$job', '$department', '$number', '$date', '$email', '$comment')";

$rs = mysqli_query($con, $sql);

if($rs)
{
	header( 'Location:http://127.0.0.1/contact/view.php' );
}
else {
	echo "something went wrong.";
}

?>
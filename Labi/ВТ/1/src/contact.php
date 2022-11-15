<?php

$con = mysqli_connect('localhost', 'root', '','db_contact_lab1');

$txtName = $_POST['txtName'];
$txtEmail = $_POST['txtEmail'];
$txtMessage = $_POST['txtMessage'];

//get last id and increment
$rs = mysqli_query($con, "SELECT MAX(id) FROM tbl_contact");
$lastid = $rs->fetch_column(0);
$lastid++;

$sql = "INSERT INTO `tbl_contact` (`id`, `name`, `email`, `mesg`) VALUES ('$lastid', '$txtName', '$txtEmail', '$txtMessage')";

$rs = mysqli_query($con, $sql);

if($rs)
{
	header( 'Location:http://127.0.0.1/contact/view.php' );
}

?>
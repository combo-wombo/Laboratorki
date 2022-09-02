<?php
  $email = $_POST['email'];
  $login  = $_POST['login'];
  $pass  = $_POST['pass'];
  $about  = $_POST['about'];
  $city  = $_POST['city'];

	echo  '==========Received===========';
	echo  "<br>.....Email: ", $email;
	echo  "<br>.....Login: ", $login;
	echo  "<br>.....Password: ", $pass;
	echo  "<br>.....Description: ", $about;
	echo  "<br>.....City: ", $city;
	echo  '<br>============================';
?>
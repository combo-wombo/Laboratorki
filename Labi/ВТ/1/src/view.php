<?php

$con = mysqli_connect('localhost', 'root', '','db_contact_lab1');
$sql = "SELECT id, name, email, mesg FROM tbl_contact";
$result = $con->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "<hr><b>id:</b> " . $row["id"]. "<br><b>Name:</b> " . $row["name"] . "<br><b>Email:</b> " . $row["email"]. "<br><b>Message:</b> " . $row["mesg"] . "<br>";
  }
} else {
  echo "0 results";
}
echo "go back: <a href=index.html><button class=b1>back</button></a>";
?>
<style><?php include 'style.css'; ?></style>
<HTML>
<head>
  <title>
    View table
  </title>
</head>
<body>
<style><?php include 'style.css'; ?></style>
<?php 
if(isset($_REQUEST['add'])){
  header("Location: contact.html");
}
if(isset($_REQUEST['update'])){
  if($_REQUEST['name'] != "default"){
    header("Location: edit.php?name=" . $_REQUEST['name']);
  } else {
    echo "<script>alert(\"No user selected\")</script>";
  }
}
if(isset($_REQUEST['delete'])){
  $con = mysqli_connect('localhost', 'root', '','db_contact_lab1'); 
  $id = $_REQUEST['name'];
  if($id != "default"){
    $sql = "DELETE FROM table1 WHERE id = $id"; 
    $result = $con->query($sql);
  } 
  else {
    echo "<script>alert(\"No user selected\")</script>";
  }
}
?>
<h1>Employee Profiles</h1>
<div class="window">
    <form class="main_menu" action="view.php">
      <select class="namefield" id="name" name="name" size="5">
      <option selected="selected" value="default">Choose an employee</option>
        <?php $con = mysqli_connect('localhost', 'root', '','db_contact_lab1'); $sql = "SELECT id, name, job, department FROM table1"; $result = $con->query($sql);
        
        if ($result->num_rows > 0) {
          while($row = $result->fetch_assoc()) {
            echo "<option value = \"" . $row["id"] . "\">" . $row["name"] . "</option>";
          }
        } else {
          echo "<option disabled>0 results</option>";
        }
        ?>
      </select>

      <div class="buttons">
        <button type="submit" name="add" value="1">Add record</button>
        <button type="submit" name="update" value="1">Update record</button>
        <button type="submit" name="delete" value="1" onclick="return confirm('Are You Sure ?')">Delete record</button>
      </div>
    </form>
        
</div>

</body>
</HTML>
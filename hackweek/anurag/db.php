<?php
error_reporting(E_ALL);
ini_set('display_errors', 1); 

$host = "localhost";
$user = "root";
$pass = "Rag@1998";
$db_name = "chat";

$con=mysqli_connect($host, $user, $pass, $db_name); /*or die("Failed to connect to MySQL: " . mysqli_error($con));*/

	/*if($con)
	{
	echo "w";
	}
	else
	{
	echo "nw";
	}*/
?>

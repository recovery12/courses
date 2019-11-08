<?php 
/*error_reporting(E_ALL);
ini_set('display_errors', 1); */

define('DB_HOST', 'localhost');
define('DB_NAME', 'groupchat');
define('DB_USER','root');
define('DB_PASSWORD','Rag@1998');

$con=mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME) or die("Failed to connect to MySQL: " . mysqli_error());


$ID = $_POST["user"];
$Password = $_POST["pass"];
 

/*function SignIn()
{
session_start();   //starting the session for user profile page
if(!empty($_POST['user']))   //checking the 'user' name which is from Sign-In.html, is it empty or have some text
{*/
	$query = mysqli_query($con,"SELECT *  FROM Websiteusers where username = '$ID' AND pass = '$Password'") or die(mysqli_error());
	$count = mysqli_num_rows($query); 

	$row = mysqli_fetch_array($query); 
	if($count >= 1)
	{
		$_SESSION['username'] = $row['pass'];
		header('location:login_portal1.html');
	}
	else
	{
		if($_SESSION != $ID && $row != $Password)
		{
			echo "SORRY....MISMATCH OF USERNAME AND PASSWORD..";
		}
	}/*
}
}
if(isset($_POST['submit']))
{
	SignIn();
}*/

?>

<!DOCTYPE HTML>
<html>

				
 <head>
   <title>Log-In</title>
     <link rel="stylesheet" type="text/css" href="style-sign.css">
 </head>
	<body> ..You are currently logged out.. </body>
 <body id="body-color">
    <div id="Sign-In">
       <fieldset style="width:30%"><legend>LOG-IN HERE</legend>

          <form id = "example" method="POST" action="login_portal1.html">

              User :<input type="text" id= "user" name="user" size="40"           				placeholder="username" ><br>
              Password: <input type="password" name="pass" size="40"     				placeholder="password"><br><br>
		    <input id="button" type="submit" name="submit" value="Log-In">
	
	  </form>
       </fieldset>
    </div>
 </body>
</html> 

<style>
body{
	background-image: url("logout.jpg");
	/*background-size:1000px 600px;*/
	background-repeat:no-repeat;
	background-attachment:fixed;
	background-position:center;
}
#Sign-In{
background-image: url("signin.jpg");
background-size:1000px 600px;
background-repeat:no-repeat;
background-attachment:fixed;
background-position:center;
margin-top:150px;
margin-bottom:150px;
margin-right:150px;
margin-left:400px;
border:3px solid #a1a1a1;
padding:9px 35px; 
width:450px;
border-radius:20px;
box-shadow: 7px 7px 6px;
}
#button {
        background-color: #4CAF50;
        color: white;
        padding: 14px 20px;
        margin: 8px 0;
        border: none;
        cursor: pointer;
        width: 100%;
}

#button:hover {
    opacity: 0.8;
}


</style>



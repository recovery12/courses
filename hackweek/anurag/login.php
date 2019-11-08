<?php 
/*error_reporting(E_ALL);
ini_set('display_errors', 1);*/

define('DB_HOST', 'localhost');
define('DB_NAME', 'groupchat');
define('DB_USER','root');
define('DB_PASSWORD','Rag@1998');


$con=mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME) or die("Failed to connect to MySQL: " . mysqli_error());

session_start();
$ID = $_POST["user"];
$Password = $_POST["pass"];
$_SESSION['varname'] = $ID;
echo $_SESSION['varname'];

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
		if($_SESSION['USERNAME'] != $ID && $row['pass'] != $Password)
		{
			echo "SORRY.....MISMATCH OF USERNAME AND PASSWORD..";
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
 <body id="body-color">
    <div id="Sign-In">
       <fieldset style="width:30%"><legend>LOG-IN</legend>

          <form id = "example" method="POST" action="login.php">

              User :<input type="text" id= "user" name="user" size="40"           				placeholder="username" ><br>
              Password: <input type="password" name="pass" size="40"     				placeholder="password"><br><br>
		    <input id="button" type="submit" name="submit" value="Log-In">
	 <div id="Signup">
	 <p> Are you new to chat? then sign up </p>
	 <a id="click" class="button" href="signin.php">Sign-Up</a>
	 <!--<input id="button" type="submit" name="submit" value="Sign-In">-->
	
	 </div>
	  </form>
       </fieldset>
    </div>
 </body>
</html> 

<style>
body{
	background-image: url("manasa.jpeg");
	background-size:1400px 800px;
	background-repeat:no-repeat;
	background-attachment:fixed;
	background-position:center;
}
#Sign-In{
	margin-top:150px;
	margin-bottom:150px;
	margin-right:125px;
	margin-left:400px;
	border:3px solid #a1a1a1;
	padding:15px 35px;
	background: white;
	background-image: url("login.jpg");
	background-size:1400px 800px;
	background-repeat:no-repeat;
	background-attachment:fixed;
	background-position:center;
	width:450px;
	border-radius:20px;
	box-shadow: 7px 7px 6px;
	/*opacity: 0.8;*/
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

#click {
        background-color: #4CAF50;
        color: white;
        padding: 9px 24px;
        margin: 8px 0;
        border: none;
        cursor: pointer;
        width: 100%;
}

#click:hover {
    opacity: 0.8;
}


</style>



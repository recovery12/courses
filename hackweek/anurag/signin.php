<?php
/*error_reporting(E_ALL);
ini_set('display_errors', 1);*/

define('DB_HOST', 'localhost');
define('DB_NAME', 'groupchat');
define('DB_USER','root');
define('DB_PASSWORD','Rag@1998');

	$fullname = $_POST['name'];
	$userName = $_POST['user'];
	$email = $_POST['email'];
	$password = $_POST['pass'];
	$conpassword = $_POST['conpass'];

	$con=mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME); 
	
	$sql = "INSERT INTO Websiteusers (fullname,username,email,pass,conpass) VALUES ('$fullname','$userName','$email','$password','$conpassword')";
	if($fullname != "" && $userName != "" && $email != "" && $password != "" && $conpassword != "")
	{
		if($password == $conpassword)
		{
			if(mysqli_query($con,$sql))
			{
				echo "REGISTRATION SUCCESSFULL";
				header('location:login1.php');
			}
			else
			{
				echo "account creation has been failed";
				echo("Error description: " . mysqli_error($con));
			}
		}
		else
		{
			echo "password and confirm password are mismatching";
		}
	}
	else
	{
		echo "CHECK WHETHER ALL VALUES ARE ENTERED OR NOT.....";
	}

?>

<!DOCTYPE html>
<html>
 <head>
   <title>Sign-In</title>
 </head>

 <body id="body-color">
  <div id="sign-in">
    <fieldset style="width:30%"><legend>Register Here</legend>
      <form id="signin" action="signin.php" method="POST" >
	Name :<input type="text" id= 'name' name="name" size="40"           				placeholder="Fullname" ><br>
        Email : <input type="text" id= 'email' name="email" size="40"     				placeholder="Email Id"><br>
	UserName :<input type="text" id= "user" name="user" size="40"           				placeholder="username" ><br>
	Password :<input type="password" id='pass' name= "pass" size="40" placeholder="password"><br>
	Confirm Password :<input type="password" id= 'conpass' name="conpass" size="40" placeholder="password"><br><br>
		    <input id="click" type="submit" name="submit" value="Register">
	
      </form>
    </fieldset>
  </div>
 </body>
</html>

<style>
body{
	background-image: url("signin1.jpg");
	background-size:1300px 700px;
	background-repeat:no-repeat;
	background-attachment:fixed;
	background-position:center;
}
#Sign-Up{
margin-top:150px;
margin-bottom:150px;
margin-right:150px;
margin-left:450px;
padding:9px 35px;
background: #f3b307 ;
width:450px;
border-radius:20px;
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



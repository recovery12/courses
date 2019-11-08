<?php  include ("db.php"); include ("chat.php"); ?>
<!DOCTYPE html>
<html>
    <head>
	<!-- auto refresh -->
	<meta http-equiv="refresh" content="10">
	<!-- auto refresh -->
       <title>Let's Meet</title>
       <link rel="stylesheet" media="all" />
    </head>
</html>

<style>

*{
    padding: 0;
    margin: 0;
    border: 0;
}
 
body{
    	background-image: url("chat.jpeg");
	background-repeat:no-repeat;
	background-attachment:fixed;
	background-position:center;
}
 
#container{
    width: 40%;
    background: white;
    margin: 0 auto;
    background-image: url("chatw.jpeg");
    /*background-size: 500px 300px;*/
    background-repeat:no-repeat;
    background-attachment:fixed;
    background-position:center;
    /*opacity: 0.8;*/
    padding: 50px;
}
 
#chat_box{
    width: 100%;
    height: 400px;
}
 
#chat_data{
    width: 137%;
    padding: 5px;
    margin-bottom: 5px;
    border-bottom: 1px solid silver;
    font-weight: bold;
}
 
input[type="text"]{
    width: 100%;
    height: 40px;
    border: 1px solid grey;
    border-radius: 5px;
}
 
input[type="submit"]{
    width: 100%;
    height: 40px;
    border: 1px solid grey;
    border-radius: 5px;
}
 
textarea{
    width: 100%;
    height: 40px;
    border: 1px solid grey;
    border-radius: 5px;
}

</style>


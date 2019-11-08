<!DOCTYPE html>
<html>
<head>
<script type="text/javascript">
			function submitForm(action) 
			{
				var form = document.getElementByID ("index");
				form.action = action;
				form.submit();
			}
	</script>
</head>
 <body>
        <div id="container">
            <div id="chat_box" class="scrollstyle">
		<?php
			if(isset($_POST['submit'])){
				$name = $_POST['name'];
				$message = $_POST['message'];
				if($name != "" && $message != "")
				{
		
					$query = "INSERT INTO chat (name,message) VALUES 							('$name','$message')";
					$run = $con->query($query);
				}
			}
		?>

		<?php
		    //session_start();
		    //$ID = $_SESSION['varname'];
	            $query = "SELECT * FROM chat ORDER BY date";
	            $run = $con->query($query);

	            while($row = $run->fetch_array()) :
                ?>

               <div id="chat_data" class="scrollstyle">
                   <span style="color:green;"><?php echo $row['name']; ?> : </span>
 	 	   <span style="color:brown;"><?php echo $row['message']; ?></span>
		   <span style="float:right;"><?php echo $row['date']; ?></span>
	       </div>
		<?php endwhile; ?>
	    </div>
	
	    <form method="post" action="index.php">
		<input type="text" name="name" placeholder="Enter Name: " />
		<textarea type="text" name="message" placeholder="Enter Message"></textarea>
		<input type="submit" name="submit" value="Send" onclick="submitForm('index.php')"/>
	    </form>
		<!--<body>
		   you are : <?php $_SESSION['username']; ?>	 
		</body>-->
		
	</div>
       <div id = "logout">
	<form method="POST" action="logout.php">
	   <input type="submit" name="submit" value="Logout">
	</form>

       </div>
    </body>

</html>
<style>

.scrollstyle
{
	max-height: 700px;
	overflow-y: scroll;
}

</style>


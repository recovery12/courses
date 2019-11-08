 <?php
	$servername = "localhost";
	$username = "root";
	$password = "mysql@123";
	$database = "UHTD";

	$DESTINATION 	= $_GET["DESTINATION"];
	$VEH_TYPE 	= $_GET["VEH_TYPE"];
	$EMP_ID 	= $_GET["EMP_ID"];
	$DEPARTURE 	= $_GET["DEP_DATE"];
	$DEPARTURE_TIME = $_GET["DEP_TIME"];





	// Create connection
	$conn =  mysqli_connect($servername, $username, $password,$database);
	// Check connection
	if ($conn) {
	  	echo "sucess!";
	}
	else
	{
		echo "error";
	}
	$sql = "INSERT INTO REG_FORM (DESTINATION,VEH_TYPE,EMP_ID,DEP_DATE,DEP_TIME) VALUES('$DESTINATION','$VEH_TYPE','$EMP_ID','$DEPARTURE','$DEPARTURE_TIME')";

	if(mysqli_query($conn,$sql))
	{
		echo "new record created";
	}
	else
	{
		echo "fail";
	}
	$sql = "SELECT MAX(REG_NO) AS max FROM REG_FORM;";
	if(mysqli_query($conn,$sql))
	{
		$result = mysqli_query($conn,$sql);
	
		// Numeric array
		$row = mysqli_fetch_array($result,MYSQLI_NUM);
		
		echo "your registration number is : ";
	
		printf ("%d \n",$row[0]);
	
		echo "please keep it for your future references";

		
	
	
	}
	else
	{
		echo "fail";
		echo "Error: " . $sql . "<br>" . mysqli_error($conn);
	}	
	mysqli_close($conn);
?>


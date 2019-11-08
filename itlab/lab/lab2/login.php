<?php
// include_once(db_create.sql);
include_once(db_conn.php);
if (isset($_POST['login']))
{
    $passwd = mysqli_real_escape_string($conn, $_POST['passwd']);
    $result = mysqli_query($conn, "select * from ITLABexerciseusers where username = '".$uname."' and passwd ='".md5($passwd));
}
else
{
    echo "Login";
}

if ($row = mysqli_fetch_array($result))
{
    echo "Login Successful";
    header("location:Welcome.php");
}
else
{
    echo "Login Failed";
}
?>
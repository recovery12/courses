<?php
$servername = 'localhost';
$uname = 'root';
$passwd = 'Rag@1998';
$dbname = 'itlab';

$conn = mysqli_connect($servername, $uname, $passwd, $dbname);

if (mysqli_connect_errno())
{
    printf("Connect failed: %s\n", mysqli_connect_errno());
    exit();
}
?>
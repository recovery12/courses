<?php
    $server = "localhost";
    $user = "root";
    $passwd = "Rag@1998";
    $dbname = "user";

    $conn = mysqli_connect($server, $user, $passwd, $dbname);
    if ($conn)
    {
        echo "Connection Successfully Established";
    }
    else
    {
        echo "Connection Refused";
    }
?>
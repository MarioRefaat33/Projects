<?php
$username="mario";
$password="1234";


if (isset($_POST['submit']))
{
	$un=$_POST['username'];
	$pw=$_POST['password'];
	
	
	if($un==$username&&$pw==$password)
	{
		header("location:start.html");
		exit();
	}
	else
	{
		header("location:index.html");
		exit();

		
	}
	
	
}

?>
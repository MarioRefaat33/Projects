<?php
if( isset($_GET['status']))//if server call php script
{
	
   $file1 =fopen("buffer.txt","a");
	
	if ($_GET['status'] == 'led_on')
	{
		fwrite($file1,"0");
		header("location: home.html");

	}
	elseif($_GET['status'] == 'led_off'){
		fwrite($file1,"1");
		header("location: home.html");

	}
	elseif($_GET['status'] == 'motor_on'){
		fwrite($file1,"2");
		header("location: home.html");

	}
	elseif($_GET['status'] == 'motor_off'){
		fwrite($file1,"3");
		header("location: home.html");

	}
	elseif($_GET['status'] == 'air_on'){
		fwrite($file1,"4");
		header("location: home.html");

	}
	elseif($_GET['status'] == 'air_off'){
		fwrite($file1,"5");
		header("location: home.html");

	}
	elseif($_GET['status'] == 'lcd_on'){
		fwrite($file1,"6");
		header("location: home.html");

	}elseif($_GET['status'] == 'lcd_off'){
		fwrite($file1,"7");
		header("location: home.html");

	}
	fclose($file1);

	
}

?>
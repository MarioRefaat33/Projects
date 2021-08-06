<?php
if( isset($_GET['command']))//if server call php script
{
    $file=$_FILES["fileupload"];
	
	$fileName   =$_FILES["fileupload"]['name'];
	$fileTmpName=$_FILES["fileupload"]['tmp_name'];
	$fileSize   =$_FILES["fileupload"]['size'];
	$fileError  =$_FILES["fileupload"]['error'];
	$fileType   =$_FILES["fileupload"]['type'];

    $fileNameArray 	= explode('.',$fileName) ;
    $fileNameOnly 	= strtolower($fileNameArray[0]); 
	$fileActualExt	= strtolower($fileNameArray[1]);
    //echo $fileName.'</br>';
	//echo $fileNameArray.'</br>';
	//echo $fileNameOnly.'</br>';
    //echo $fileActualExt.'</br>';
	$destination = "/home/vhosts/abanoub.freevar.com/upload/".$fileNameOnly.".txt" ; 
	if( $_GET['command'] == 0) //upload file to server
	{
		if (move_uploaded_file($fileTmpName, $destination)) 
		{
			echo "The file ". htmlspecialchars( basename( $_FILES["fileToUpload"]["name"])). " has been uploaded."; 
		}
		else
		{
			echo "Sorry, there was an error uploading your file</br>.";
		}
		echo 'Here is some more debugging info:</br>';
		print_r($_FILES);
		echo "</br>";
		echo $fileTmpName; 
		echo "</br>";
		$source=fopen("source.txt","w+");
		fputs($source,$destination);
		echo "file saved at ".$destination;
		echo "</br>"; 
		fclose($source); 
	}
	if (($_GET['command'] == 1))
	{
		$source=fopen("source.txt","r+");
		$destination = fgets($source);
		if(empty($destination))
		{
			echo "empty destination";
			exit();
		}
		fclose($source);
		echo $destination."</br>";
		//file()function take file path , save it's lines to an array each line save in single element of array
		$file_arr 		= file($destination);
		$no_lines	= count($file_arr);				
		$no_pages	= ceil($no_lines/28);			
		$no_lines_per_page=$no_lines%28;
		//print_r ($file_arr);
		$number_pages = fopen("number_pages.txt","w+");
		
		fputs($number_pages,$no_pages);
		//echo $no_pages;
		fclose($number_pages);
		
		echo $no_lines."</br>";

		$page_no = 1; //is sent from microcontroller
		$buffer_file = fopen("buffer.txt","w+");
		
		if(isset($_GET['page_no']) && is_numeric($_GET['page_no']) )
		{
			$page_no= $_GET['page_no'];
			$buffer_var="";
			for($i = 0; $i < 28 ; $i++)
			{
				$buffer_var=$buffer_var.$file_arr[(($_GET['page_no']-1)*28)+$i];
				
				if ($_GET['page_no']==($no_pages) && $i==($no_lines_per_page-1))
				{
					break;
				}
			}
		}
		echo $no_lines_per_page."</br>";
		echo $no_pages."</br>";
		fputs($buffer_file,$buffer_var);
		fclose($buffer_file);		
		echo $buffer_var."</br>";
	}
	if( $_GET['command'] == 2) //run same application
	{
		$buffer_file = fopen("buffer.txt","w+");
		fwrite($buffer_file,"1");
		fclose($buffer_file);		
	}
	if( $_GET['command'] == 3) //control home
	{
		$buffer_file = fopen( 'buffer.txt', 'w' );
		fclose(buffer_file);
		header("location: home.html");
		
	}
	
}

?>
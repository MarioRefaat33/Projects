<DOCTYPE html>
    <html>
    <head>
    <meta charset="utf-8">
    <title>ARM OTA programmer</title>
     </head>
   <link rel="stylesheet" href="style.css" />
    <body>    
    <!--W3schools php_file_upload tutorial: https://www.w3schools.com/php/php_file_upload.asp
    -->
    <div>
      <h1>ARM OTA programmer <br>using  a custom bootloader </h1>
      <h2> Made by: </h2>
      <h3><em>Mazen Osama, Mohamed Shafek, ElSaeed Mohamed, Ahmed Yakoot</em></h3>
    </div>

    <div>
    <form action="#" method="post" enctype="multipart/form-data">
      
    <!-- Stack overflow Solution -->
    <button class="file_upload" type="button">
      <span class="btn_lbl">Browse For File</span>
      <span class="btn_colorlayer"></span>
      <input type="file" name="fileupload" id="file_upload" />
    </button>
    <!-- Stack overflow Solution -->




      <!-- <input type="file" name="fileToUpload" class="fileToUpload"> -->
      </br>
      </br>
      <button type="submit" formaction="script.php?command=0" value="Upload file to server" name="submit" id="upload"> Upload File to Server </button>
    </br>
    </br>
    <button type="submit" formaction="script.php?command=1&page_no=1" value="Burn Program on Target" name="submit" id="burn"> Burn Program on Target </button>
    </br>
    </br>
    </form>
    </div>
        

    
    </body>
    </html>
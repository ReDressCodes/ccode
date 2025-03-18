<?php

echo "<!doctype html>

<html> 
<head> 

<title> ducklings </title> 

<head> 

<style type='text/css'> 

body { align:center; color: white; font-size:2.5em; margin-top:300px} 

.styled {
  border: 0;
  line-height: 2.5;
  padding: 0 20px;
  font-size: 1rem;
  text-align: center;
  text-color:white;
  color: #fff;
  text-shadow: 1px 1px 1px #000;
  border-radius: 10px;
  background-color: grey;
  background-image: linear-gradient(
    to top left,
    rgba(0, 0, 0, 0.2),
    rgba(0, 0, 0, 0.2) 30%,
    rgba(0, 0, 0, 0)
  );
  box-shadow:
    inset 2px 2px 3px rgba(128, 128, 128, 0.6),
    inset -2px -2px 3px rgba(0, 0, 0, 0.6);
}

.styled:hover {
  background-color: rgba(128, 128, 128, 1);
}

.styled:active {
  box-shadow:
    inset -2px -2px 3px rgba(128, 128, 128, 0.6),
    inset 2px 2px 3px rgba(0, 0, 0, 0.6);
}

table { align:center; border-spacing: 100px 0px}

</style>

<body> 

<table align=center>
<tr>
     <td>
     <button class=styled type='button'> Home </button>
     </td>
     <td>
     <button class=styled type='button'> Tech </button>
     </td>
     <td>
     <button class=styled type='button'> About </button>
     </td>
</tr>
</table>
</body>
</html>";
?>

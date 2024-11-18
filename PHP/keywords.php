<?php 

  $hello = "World";

  $$hello = "Friend";

  echo $World;

  $correct = 'aaxxbbccddwwddffgg';

/* foreach($correct as $character) { echo $character; } */

  switch($correct)
  {
  case 'a':
	  echo "hello\n";
	  break;
  case 'b':
	  echo "black\n";
	  break;
  case 'c':
	  echo "yellow\n";
	  break;
  case 'aaxxbbccddwwddffgg':
	  echo "whole string\n";
	  break;
  default:
	  echo "none";
  }

?>

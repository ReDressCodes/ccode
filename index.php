<?php

/* PHP variables seems to only get defined after they're initialized? */

$playlist_generated = [];

function generate($playlist) {

static $bucket = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];
static $upperbucket = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];

/* 20 items */
$items = 20;

srand(time());

while ($items != 0) {

/* Generate the "name" of artist first and foremost */
$lettercountfirst = 0;
$lettercountsecond = 0;

while($lettercountfirst <= 4 ) { $lettercountfirst = rand() % 15;}
while($lettercountsecond <= 4) { $lettercountsecond = rand() % 15;} 

/* it doesn't seem like PHP has methods for handling characters unless you consider those meant for dealing with UNICODE */
$firstname = ""; $firstname[0] = $upperbucket[rand() % 25]; $lettercountfirst = $lettercountfirst - 1;
$lastname = ""; $lastname[0] = $upperbucket[rand() % 25]; $lettercountsecond = $lettercountsecond - 1;

while($lettercountfirst > 0) { $firstname[$lettercountfirst] = $bucket[rand() % 25]; $lettercountfirst = $lettercountfirst - 1; }
while($lettercountsecond > 0) { $lastname[$lettercountsecond] = $bucket[rand() % 25]; $lettercountsecond = $lettercountsecond - 1; }

echo $firstname. " " . $lastname . "</br>";

/* Generate the name of the track */
$words = rand() % 5;  if ($words == 0) $words = 1;

while($words != 0) { break;}

$items = $items - 1;
}

}

generate($playlist_generated); 

?>
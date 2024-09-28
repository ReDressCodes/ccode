<?php

$playlist_xml = "<name> Title </name>
 <tracks>
   <track>
     <name> Let's tie our love </name>
     <artist> Dolly Parton </artist>
     <album> Alabama Valley </album>
    </track>
    <track>
     <name> The Gambler </name>
     <artist> Kenny Rogers </artist>
     <album> The Gambit </album>
    </track>
    <track>
     <name> Forever </name>
     <artist> The Birthday massacre </artist>
     <album> The rabbit </album>
    </track>
    <track>
     <name> Dat a Dat <name>
     <artist> Steflon Don </artist>
     <album> <unknown> </album>
    </track>
  </tracks>";
   
     
/* PHP variables seems to only get defined after they're initialized? */
$playlist_generated = [];

function generate($playlist) {

static $bucket = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];
static $upperbucket = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];
static $vowels = ['a', 'e', 'i', 'o', 'u'];

/* 20 items */
$items = 20;

srand(time());

while ($items != 0) {

/* Generate the "name" of artist first and foremost */
$lettercountfirst = 0;
$lettercountsecond = 0;
$firstname = "";
$lastname = "";

while($lettercountfirst <= 4 ) { $lettercountfirst = rand() % 15;}
while($lettercountsecond <= 4) { $lettercountsecond = rand() % 15;} 


/* There is five vowels and 20 consonants so one way or the other we have to force the vowels. */
while($lettercountfirst > 0) {

$firstname[$lettercountfirst] = $bucket[rand() % 25];

/* fallback to force vowels in case one is needed */
for($start = 0; $start <= 4; $start++) {

if ($firstname[$lettercountfirst] == $vowels[$start]) break;

else if ($start == 4) { $lettercountfirst = $lettercountfirst - 1; $firstname[$lettercountfirst] = $vowels[rand() % 4]; }
}

$lettercountfirst--;

}
while($lettercountsecond > 0) {

$lastname[$lettercountsecond] = $bucket[rand() % 25];

for ($start = 0; $start <= 4; $start++) {

if ($lastname[$lettercountsecond] == $vowels[$start]) break;

else if ($start == 4) { $lettercountsecond = $lettercountsecond - 1; $lastname[$lettercountsecond] = $vowels[rand() % 4]; }

}

$lettercountsecond--;

}

/* it doesn't seem like PHP has methods for handling characters unless you consider those meant for dealing with UNICODE */
$firstname[0] = $upperbucket[rand() % 25];
$lastname[0] = $upperbucket[rand() % 25];

echo $firstname . " " . $lastname . "<br>"; 

/* Generate the name of the track */
$words = rand() % 5;  if ($words == 0) $words = 1;

while($words != 0) { break;}

$items = $items - 1;
}

}

/*
foreach($_SERVER as $item) { echo $item; echo "</br>";}

$count = 0; $count++;

for($start = 0; $start <= 25; $start++) { echo $start; echo "<br>"; }
*/

generate($playlist_generated);

phpinfo();

?>
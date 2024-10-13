<?php
/*
  This xml needs to be parsed but still debating whether to use an xml library or to do it manually
  Maybe move this to a seperate file too?
*/

$playlist_json = '[ "Sunday Blues",
                   [
		     "name" : "Let\'s tie our love",
		     "artist" : "Dolly Parton",
		     "album" : "Alabama Valley"
		   ],
		   [
		     "name" : "The Gambler",
		     "artist" : "Kenny Rogers",
		     "album" : "The Gambit"
		   ],
		   [
		     "name" : "Forever",
		     "artist" : "The birthday massacre",
		     "album" : "The rabbit"
		   ],
		   [
		     "name" : "Dat a dat",
		     "artist" : "Steflon Don",
		     "album" : "<unknown>"
		   ],
		   [
		     "name" : "Hello",
		     "artist" : "Adele",
		     "album" : "- Single - "
		   ],
		   [
		     "name" : "Sitoi Kitu Kidogo",
		     "artist" : "Jimwat",
		     "album" : " - Single - "
		   ],
		   [
		     "name" : "Coat of many colours",
		     "artist" : "Dolly Parton",
		     "album" : "The Reloaded doll"
		   ],
		   [
		     "name" : "Love is strange",
		     "artist" : "Dolly Parton ",
		     "album" : "Dolly and Kenny"
		   ],
		   [
		     "name" : "Spanish guitar",
		     "artist" : "Birdman\'s ex",
		     "album" : "Hit from the 2000s "
		   ],
		   [
		     "name" : "Leather so soft",
		     "artist" : "Birdman and Sons Co.",
		     "album" : "Made in tiger"
		   ]
		]';

$playlist_xml = "<name> Sunday Blues </name>
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
    <track>
     <name> Hello </name>
     <artist> Adele </artist>
     <album> -Single - </album>
    </track>
    <track>
     <name> Sitoi Kitu Kidogo </name>
     <artist> Jimwat </artist>
     <album> - Single - </album>
    </track>
    <track>
     <name> Coat of many colours </name>
     <artist> Dolly Parton </artist>
     <album> The Reloaded doll </album>
    </track>
    <track>
     <name> Love is strange </name>
     <aritst> Dolly Parton </artist>
     <album> Dolly and Kenny </album>
    </track>
    <track>
     <name> Spanish guitar </name>
     <artist> Birdman's ex </artist>
     <album> Hits from 2000s </album>
    </track>
    <track>
     <name> Leather so soft </name>
     <artist> Birdman and Sons Co. </artist>
     <album> Made in tiger </album>
    </track>
  </tracks>";
     
class ListManager {

public function __constructor() {}

public function generate() {
	static $bucket = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];
	static $upperbucket = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];
	
	static $vowels = ['a', 'e', 'i', 'o', 'u'];
	
	/* 20 items */
	$items = 20;
	
	while ($items != 0) {
		/* Generate the "name" of artist first and foremost */
		$lettercountfirst = 0;
		$lettercountsecond = 0;
		$firstname = "";
		$lastname = "";
		
		while($lettercountfirst <= 4 ) { $lettercountfirst = random_int(0, 15);}
		while($lettercountsecond <= 4) { $lettercountsecond = random_int(0, 15);} 
		
		/* There is five vowels and 20 consonants so one way or the other we have to force the vowels. */
		while($lettercountfirst > 0) {
			$firstname[$lettercountfirst] = $bucket[random_int(0, 15)];
			/* fallback to force vowels in case one is needed */
			for($start = 0; $start <= 4; $start++) {
				if ($firstname[$lettercountfirst] == $vowels[$start])
				       	break;
				else if ($start == 4) { 
					$lettercountfirst = $lettercountfirst - 1; 
					$firstname[$lettercountfirst] = $vowels[rand() % 4];
			       	}
			}
			
			$lettercountfirst--;
		}
		
		while($lettercountsecond > 0) {
			$lastname[$lettercountsecond] = $bucket[random_int(0, 15)];
			
			for ($start = 0; $start <= 4; $start++) {
				
				if ($lastname[$lettercountsecond] == $vowels[$start]) 
					break;
				else if ($start == 4) { 
					$lettercountsecond = $lettercountsecond - 1; $lastname[$lettercountsecond] = $vowels[rand() % 4]; 
				}
			}
			$lettercountsecond--;
		}
		
		/* it doesn't seem like PHP has methods for handling characters unless you consider those meant for dealing with UNICODE */
		$firstname[0] = $upperbucket[random_int(0, 25)];
		$lastname[0] = $upperbucket[random_int(0, 25)];
		
		echo $firstname . " " . $lastname . "<br>"; 
		
		/* Generate the name of the track */
		$words = random_int(0, 5);  if ($words == 0) $words = 1;
		
		while($words != 0) { break;}
		$items = $items - 1;
	}
}

private $playlist_generated;

};

/*
foreach($_SERVER as $item) { echo $item; echo "</br>";}

$count = 0; $count++;

for($start = 0; $start <= 25; $start++) { echo $start; echo "<br>"; }
*/

$list = new ListManager();

$list->generate();

foreach($_GET as $item => $value) { echo $item; echo "  "; echo $value; echo "<br>";}

echo count($_GET);

echo "</br>";

echo count($_SERVER);

echo "</br>";

phpinfo();

class Router {

/*

Empty

*/

};

class Breaker {

/*

Empty

*/

};


class Gene {

/*

Empty

*/

};

?>

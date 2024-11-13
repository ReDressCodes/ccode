<?php
/*
 *
 * Attempt to generate and write a dataframe to a file
 *
 */
class dataframe {
	
	function __construct ($framerows, $framecolumns, $filename,
		              $range_a = 200, $range_b = 400){

		$rows = $framerows;
		$columns = $framecolumns;
		$file = $filename;
		$low = $range_a;
		$high = $range_b;
	}

	function generate($range_a, $range_b) {
		srand(time());
		$dataframe = fopen("data.txt", "rw+");
		
		for ($i = 0; $i <= 10; $i++) {
			for ($j = 0; $j <= 20; $j++) {
				$item = rand() % $range_a + $range_b;
				fwrite($dataframe, $item . " ");
			}
			fwrite($dataframe, "\n");
		}
		
		/* fclose($dataframe); */
	}

	function display() {
		/* display the data to the terminal */
	}

	private $dataframe;
	private $rows;
	private $columns;
	private $file;
	private $low;
	private $high;
};


$dt = new dataframe(20, 20, "data.txt");

$dt->generate(500,  100);

$dt->display();

?>

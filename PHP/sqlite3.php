<?php

$lite = new SQLite3("craft.db");

echo "Hello, World! \n";

$version = $lite->version();

echo $version["versionString"];

echo "\n"; 

echo $version["versionNumber"];

$statement = "SELECT * from craft";

$lite->exec($statement);

$lite->close();

?>

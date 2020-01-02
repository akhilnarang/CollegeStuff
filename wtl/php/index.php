<?php
$dirname = ".";
$dir = opendir($dirname);

echo "<table border=1>";
echo "<tr>";
echo "<th>Filename</th>";
echo "</tr>";
while ($file = readdir($dir)) {
    if (($file != ".") and ($file != "..") and ($file != "index.php")) {
        echo "<tr><td>";
        echo "<a href='$file'>$file</a>";
        echo "</td></tr>";
    }
}

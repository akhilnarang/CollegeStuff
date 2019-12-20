<?php
echo "<table width=400 height=400>";
for ($i = 0; $i < 16; $i++) {
    echo "<tr>";
    for ($j = 0; $j < 16; $j++) {
        if (($i + $j) % 2 == 0) {
            echo "<td bgcolor=black>";
        } else {
            echo "<td bgcolor=white>";
        }
    }
    echo "</tr>";
}
echo "</table>";

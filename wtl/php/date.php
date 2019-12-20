<?php
$d = date_create("2019-12-19");
$b = date_create("1999-09-24");
$diff = date_diff($d, $b);
echo $diff->format("%y years, %m months, and %d days!");
?>

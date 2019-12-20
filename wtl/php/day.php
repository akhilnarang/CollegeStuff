<?php
$day = date("l");
if ($day == "Sunday") {
    echo "Happy Sunday!";
} elseif ($day == "Friday") {
    echo "Happy Weekend!";
} else {
    echo "Have a nice day!";
}
?>

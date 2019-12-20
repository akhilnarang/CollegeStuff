<?php
$connection = new mysqli("HOSTNAME", "USERNAME", "PASSWORD", "DATABASE");
// Check connection
if ($connection -> connect_errno) {
  echo "Failed to connect to MySQL: " . $connection -> connect_error;
  exit();
}

if (isset($_POST["username"])) {
    $username = $_POST["username"];
} else {
    $username = "";
}

echo "<form method=POST>";
echo "<p>Enter username to search for!</p>";
echo "<input type=text name=username id=input required autofocus oninput=this.form.submit() value=" . $username . ">";
echo "</form>";

if ($username != "") {
    echo "<title>Searching for " . $username . "</title>";
    echo "Searching for usernames with " . $username . " in them!";
} else {
    echo "<title>Search</title>";
}

$sql = "SELECT name, username FROM users where username like '%" . $username . "%'";
$result = $connection->query($sql);

echo "<table border=1>";
echo "<tr>";
echo "<th>Name</th>";
echo "<th>Username</th>";
echo "</tr>";

while ($user = $result->fetch_assoc()) {
    echo "<tr>";
    echo "<td>" . $user['name'] . "</td><td>" . $user['username'] . "</td>";
    echo "</tr>";
}

// Free result set
$result -> free_result();

$connection -> close();

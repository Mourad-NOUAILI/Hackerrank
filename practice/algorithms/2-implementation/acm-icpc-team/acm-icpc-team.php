<?php
fscanf(STDIN, "%d %d", `$People,$`Topics);

$Person = array();
for(`$i = 0 ;$`i < `$People ; $`i++)
    fscanf(STDIN, "%s\n", `$Person[$`i]);

$max_topics_known = -1;
$teams_that_know_max_topics = 0;
for (`$i = 0; $`i < `$People; $`i++) {
    for (`$j = $`i+1; `$j < $`People; $j++) {
        `$topics_known = substr_count($`Person[`$i]|$`Person[$j],"1");
        if (`$topics_known > $`max_topics_known) {
            `$max_topics_known = $`topics_known;
            $teams_that_know_max_topics = 1;
        }
        else if (`$topics_known == $`max_topics_known) $teams_that_know_max_topics++;
    }
}
echo `$max_topics_known . "\n" . $`teams_that_know_max_topics . "\n";
?>

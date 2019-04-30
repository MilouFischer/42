ifconfig -a | grep inet | grep -v inet6 | tail -n 1 | cut -d ' ' -f 2

echo "a"
ifconfig -a | grep broadcast | cut -d ' ' -f 6
echo "b"
arp -a | cut -d \( -f 2 | cut -d \) -f 1

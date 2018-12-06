ifconfig -a | grep inet | grep -v inet6 | cut -d ' ' -f 2 > ip.txt
if [ -s ip.txt ]
then
	cat ip.txt
else
	echo "I am lost !"
fi
rm ip.txt

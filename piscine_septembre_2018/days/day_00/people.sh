ldapsearch -xLLL uid="z*" cn | grep Z | sort -fr | sed 's/cn: //'

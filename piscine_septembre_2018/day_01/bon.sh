ldapsearch -Q uid="*bon*" cn | grep BON | grep cn | wc -l | sed 's/ *//'

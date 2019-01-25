# General info

Il faudra préciser dans le rapport que notre programme est conçu pour traiter uniquement les fichiers logs qui ont cette écriture -> bien sûr
La valeur static nbExceptions n'a plus vraiment besoin d'exister -> elle ne coute pas très cher et peut être utile si on doit tester des nouveaux logs afin de s'assurer que tout s'est bien passé (en remettant un try catch si ça plante)

J'ai ajouté l'option "-u", elle permet de spécifier un autre nom pour le host du site qui fournit le log file. En gros, toutes les requete vont maintenant être perçu comme étant orignaire de ce nouvel host. Par defaut si on ne met pas -h c'est http://intranet-if.insa-lyon.fr qui est utiliser pour le parsing. Je sais pas si c'est super clair mais normalement ça fonctionne correctement avec ce que j'ai essayé.

## Option list

List of available options :

* -e \[filter\]        : Keep all requested urls where the filter string is present, others are deleted. Referer urls are not affected. If no filter is given, then the default filter will be ".html"
* -g \[dot_file_name\] : Generate a Dot-file out of the analysed log file.
* -t \[hour\]          : Keep all requested urls whitin the interval \[hour ; hour+1\[], others are deleted.
* -u \[host_url\]      : Change the default host url (http://intranet-if.insa-lyon.fr) to the one passed in parameter.

# TODO

Verify existence of file
Add more filter for date (if time)
Option -e multiple calls

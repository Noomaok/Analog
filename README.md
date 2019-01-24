## General info

Il faudra préciser dans le rapport que notre programme est conçu pour traiter uniquement les fichiers logs qui ont cette écriture -> bien sûr  
La valeur static nbExceptions n'a plus vraiment besoin d'exister -> elle ne coute pas très cher et peut être utile si on doit tester des nouveaux logs afin de s'assurer que tout s'est bien passé (en remettant un try catch si ça plante)  

J'ai ajouté l'option "-h", elle permet de spécifier un autre nom pour le host du site qui fournit le log file. En gros, toutes les requete vont maintenant être perçu comme étant orignaire de ce nouvel host. Par defaut si on ne met pas -h c'est http://intranet-if.insa-lyon.fr qui est utiliser pour le parsing. Je sais pas si c'est super clair mais normalement ça fonctionne correctement avec ce que j'ai essayé.  

## Idee

Je ne pense pas que Analog est vraiment besoin d'être une classe. Il faudra qu'on en discute pour voir ce que l'on fait des ces fichiers -> oui en effet, ça pourrait être un simple module, on pourra changer ça  

## General info

RemoveEmptyString n'est pas vraiment necessaire dans notre programme. -> vu le superbe découpage de requête que tu as fait, c'est pas faux !
Il faudra préciser dans le rapport que notre programme est conçu pour traiter uniquement les fichiers logs qui ont cette écriture -> bien sûr
Toutes les infos sont stocker sans erreur, quelque soit la ligne d'entrée (test sur anonyme.log) -> GG 
La valeur static nbExceptions n'a plus vraiment besoin d'exister -> elle ne coute pas très cher et peut être utile si on doit tester des nouveaux logs afin de s'assurer que tout s'est bien passé (en remettant un try catch si ça plante)  

Fonction generation de Dot-file implementer dans le main. Le main vérifie la validité des entrés, il faut passer un nom de fichier avec .dot à la fin pour que le programme l'accepte. -> GG  

## Idee

Je ne pense pas que Analog est vraiment besoin d'être une classe. Il faudra qu'on en discute pour voir ce que l'on fait des ces fichiers -> oui en effet, ça pourrait être un simple module, on pourra changer ça

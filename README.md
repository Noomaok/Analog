## General info

Il faudra préciser dans le rapport que notre programme est conçu pour traiter uniquement les fichiers logs qui ont cette écriture -> bien sûr  
La valeur static nbExceptions n'a plus vraiment besoin d'exister -> elle ne coute pas très cher et peut être utile si on doit tester des nouveaux logs afin de s'assurer que tout s'est bien passé (en remettant un try catch si ça plante)  

## Idee

Je ne pense pas que Analog est vraiment besoin d'être une classe. Il faudra qu'on en discute pour voir ce que l'on fait des ces fichiers -> oui en effet, ça pourrait être un simple module, on pourra changer ça  

# General info

## Option list

List of available options :

```
-h                   : Display this message
-e [filter]          : Filter out all requested urls not containing the [filter] string. Referer urls are not affected. Default filter is ".html"
-g dot_file_name     : Generate a Dot-file out of the analysed log file
-n nb_arcs           : When used with -g, specifies the number of arcs in the graph. Default value is 10
-d                   : Generate a PDF version of the graph graph. Must be used with -g
-t hour              : Filter out every request not sent within the interval [hour;hour+1]
-u host_url          : Change the default host url (http://intranet-if.insa-lyon.fr) to the one passed in parameter
-x                   : Do not display all undefined referer requests
```

## TODO

L'option -u n'a aucune action pour l'instant. Soit on l'implémente, soit on la supprime, mais on ne la laisse pas dans les tests telle quelle.  
-> Pour l'instant ce que fait -u c'est de changer la string HostURL dans Query.cpp qui permet de check la présence de cet url dans le RefererUrl. 
On ne voit pas trop l'effet avec nos fichiers log mais si on donnait un fichier log d'un autre site, là ce serait intéressant. 
Après l'utilité n'est pas incroyable donc on peut retirer cet option pour ce simplifier la vie.  

J'ai eu une idée pour check si le contenu du fichier log qui est passé à notre appli est correcte. Il faudrait utiliser des expression régulière pour voir si la ligne possède le bon format. Je vais regarder si on peut faire ça, dis moi ce que tu en pense.  

## Tests

### Test 1

```
./analog
```

### Test 2

```
./analog inexistant.log
```

### Test 3

```
./analog court.log
```

### Test 4

```
./analog -g court.log
```

### Test 5

```
./analog -g graphTest court.log
```

### Test 6

```
./analog -g graphTest.dot court.log
```

### Test 7

```
./analog -e court.log
```

### Test 8

```
./analog -e .jpg court.log
```

### Test 9

```
./analog -t court.log
```

### Test 10

```
./analog -t 12 court.log
```

### Test 11

```
./analog -d court.log
```

### Test 12
```
./analog -g graphTest -d court.log
```

### Test 13

```
./analog -x courtUndefined.log
```

### Test 14

```
./analog -n court.log
```

### Test 15

```
./analog -n 50 court.log
```

### Test 16

```
./analog -n test court.log
```

### Test 17

```
./analog -u court.log
```

### Test 18

```
./analog -u http://SiteWebIF.fr court.log
```

### Test 19

```
./analog -e -g graphTest -n -d 50 -t 14 -x /tmp/anonyme.log
```

### Test 20

```
./analog -t 29 court.log
```

### Test 21

```
./analog -n -30 court.log
```

### Test 22

```
./analog -z court.log
```


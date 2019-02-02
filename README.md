# General info

## Option list

List of available options :

```
-h                   : Display this message
-d                   : Generate the pdf graph
-e [filter]          : Keep all requested urls where the filter string is present, others are deleted. Referer urls are not affected. If no filter is given, then the default filter will be ".html
-g dot_file_name     : Generate a Dot-file out of the analysed log file
-n nb_arcs           : Do not display all undefined referer requests
-t hour              : Keep all requested urls whitin the interval [hour  hour+1], others are deleted
-u host_url          : Change the default host url (http://intranet-if.insa-lyon.fr) to the one passed in parameter
-x                   : Do not display all undefined referer requests
```

## TODO

Add more filter for date (if time)
Option -e multiple calls

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
./analog /tmp/anonyme.log
```

### Test 4

```
./analog -g /tmp/anonyme.log
```

### Test 5

```
./analog -g dotfile /tmp/anonyme.log
```

### Test 6

```
./analog -g dotfile.dot /tmp/anonyme.log

```

### Test 7

```
./analog -e /tmp/anonyme.log

```

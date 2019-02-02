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

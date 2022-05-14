# Level 00
*password : level00*

## Analyze

```
scp -P 4242 level00@192.168.56.109:level00 binary/
```
- pass[0] must be equal to 5276

so :
```
$ ./level00 
***********************************
*            -Level00 -           *
***********************************
Password:5276

Authenticated!
$ cat /home/users/level01/.pass
uSq2ehEGT6c9S24zbshexZQBXUGrncxn5sD5QfGL
```

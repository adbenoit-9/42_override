# Level 03
*password : Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H*

## Analyze

```
scp -P 4242 level03@192.168.56.109:level03 binary/
```

```
(gdb) b decrypt
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y

Starting program: /home/users/level03/level03 
***********************************
*               level03         **
***********************************
Password:42

Breakpoint 1, 0x0804874d in test ()
(gdb) print $ecx
$5 = 1
(gdb) si
0x08048750 in test ()
(gdb) print $ecx
$6 = 1
(gdb) si
0x08048753 in test ()
(gdb) print $ecx
$7 = 1
(gdb) si
0x08048755 in test ()
(gdb) print $ecx
$8 = 322424845
```

param_1 = 322424845

```
$ gcc find_nb.c 
$ ./a.out
nb = 18
```

password = 322424845 - 18 = 322424827

```
$ ./level03 
***********************************
*               level03         **
***********************************
Password:322424827     
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
```

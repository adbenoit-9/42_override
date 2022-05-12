# Level 06
*password : h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq*

## Analyze

```
scp -P 4242 level06@192.168.56.109:level06 binary/
```
```
$ gcc get_serial.c 
$ ./a.out 
***********************************
*               level06           *
***********************************
-> Enter Login: adbenoit

Your serial is : 6234478
```

```
$ ./level06 
***********************************
*               level06           *
***********************************
-> Enter Login: adbenoit
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6234478
Authenticated!
$ cat /home/users/level07/.pass
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
```
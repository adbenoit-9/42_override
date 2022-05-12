int auth(char *login,unsigned int serial)
{
  int len;
  int ret;
  int i;
  unsigned int res;
  
  len = strcspn(login, "\n");
  login[len] = 0;
  len = strnlen(login, 100);
  if (len < 6) {
    ret = 1;
  }
  else {
    if (ptrace() == -1) {
      puts();
      puts();
      puts();
      ret = 1;
    }
    else {
      res = login[3] ^ 0x1337U + 0x5eeded;
      i = 0;
      while (i < len) {
        if (login[i] < ' ') {
          return 1;
        }
        res = res + (login[i] ^ res) % 1337;
        ++i;
      }
      if (serial == res) {
        ret = 0;
      }
      else {
        ret = 1;
      }
    }
  }
  return ret;
}

int main(void)
{
  int iVar1;
  int ret;
  int in_GS_OFFSET;
  unsigned int serial;
  char login[100];
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(login, 100, 0);
  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  __isoc99_scanf("%u", &serial);
  ret = auth(login, serial);
  if (ret == 0) {
    puts("Authenticated!");
    system("/bin/sh");
  }
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ret != 0;
}

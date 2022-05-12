# include <stdio.h>
# include <string.h>

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
    res = login[3] ^ 0x1337U + 0x5eeded;
    i = 0;
    while (i < len) {
      if (login[i] < ' ') {
        return 1;
      }
      res = res + (login[i] ^ res) % 1337;
      ++i;
    }
    printf("\nYour serial is : %u\n", res);
    if (serial == res)
      ret = 0;
    else
      ret = 1;
  }
  return ret;
}

int main(void)
{
  int ret;
  char login[100];
  
  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  scanf("%s", login);
  ret = auth(login, 0);
  return ret != 0;
}

void clear_stdin(void)
{
  char cVar1;
  
  do {
    cVar1 = getchar();
    if (cVar1 == '\n') {
      return;
    }
  } while (cVar1 != -1);
  return;
}

void prog_timeout(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x80);
  (*pcVar1)();
  return;
}

undefined4 get_unum(void)
{
  undefined4 local_10 [3];
  
  local_10[0] = 0;
  fflush(stdout);
  __isoc99_scanf(&DAT_080489c0,local_10);
  clear_stdin();
  return local_10[0];
}

void decrypt(int nb)
{
  char str[] = "Q}|u`sfg~sf{}|a3";
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  i = 0;
  while(i < strlen(str)) {
    str[i] = nb ^ str[i];
    ++i;
  }
  if (strcmp(str, "Congratulations!") == 0)
    system("/bin/sh");
  else
    puts("\nInvalid Password");
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

void test(int param_1,int param_2)
{
  undefined4 uVar1;
  
  param_2 -= param_1;
  switch(param_2) {
  default:
    uVar1 = rand();
    decrypt(uVar1);
    break;
  case 1:
    decrypt(param_2);
    break;
  case 2:
    decrypt(param_2);
    break;
  case 3:
    decrypt(param_2);
    break;
  case 4:
    decrypt(param_2);
    break;
  case 5:
    decrypt(param_2);
    break;
  case 6:
    decrypt(param_2);
    break;
  case 7:
    decrypt(param_2);
    break;
  case 8:
    decrypt(param_2);
    break;
  case 9:
    decrypt(param_2);
    break;
  case 16:
    decrypt(param_2);
    break;
  case 17:
    decrypt(param_2);
    break;
  case 18:
    decrypt(param_2);
    break;
  case 19:
    decrypt(param_2);
    break;
  case 20:
    decrypt(param_2);
    break;
  case 21:
    decrypt(param_2);
  }
  return;
}

int main(void)
{
  time();
  srand();
  puts("***********************************");
  puts("*\t\tlevel03\t\t**");
  puts("***********************************");
  printf("Password:");
  __isoc99_scanf("%d");
  test();
  return 0;
}

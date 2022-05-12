int auth(int param_1,uint param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  uint local_14;
  
  iVar1 = strcspn();
  *(undefined *)(iVar1 + param_1) = 0;
  iVar1 = strnlen();
  if (iVar1 < 6) {
    uVar2 = 1;
  }
  else {
    iVar3 = ptrace();
    if (iVar3 == -1) {
      puts();
      puts();
      puts();
      uVar2 = 1;
    }
    else {
      local_14 = ((int)*(char *)(param_1 + 3) ^ 0x1337U) + 0x5eeded;
      local_18 = 0;
      while (local_18 < iVar1) {
        if (*(char *)(local_18 + param_1) < ' ') {
          return 1;
        }
        local_14 = local_14 + ((int)*(char *)(local_18 + param_1) ^ local_14) % 0x539;
        local_18 = local_18 + 1;
      }
      if (param_2 == local_14) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

int main(void)
{
  int iVar1;
  int ret;
  int in_GS_OFFSET;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  puts("*****************************");
  puts("*\t\tlevel06\t\t  *");
  puts("*****************************");
  printf("-> Enter Login: ");
  fgets();
  puts("*****************************");
  puts();
  puts("*****************************");
  printf("-> Enter Serial: ");
  __isoc99_scanf("%u", nb);
  ret = auth();
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

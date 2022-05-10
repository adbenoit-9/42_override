int verify_user_pass(char *str)
{
  int iVar1;
  char *pass;
  bool in_CF;
  bool in_ZF;
  
  iVar1 = 5;
  pass = "admin";
  while (in_ZF && iVar1 != 0) {
    --iVar1;
    in_CF = *str < *pass;
    in_ZF = *str == *pass;
    ++str;
    ++pass;
  }
  return ((!in_CF && !in_ZF) - in_CF);
}

int verify_user_name(void)
{
  int iVar1;
  byte *str;
  char *name;
  bool uVar4;
  bool uVar5;
  byte bVar6;
  
  bVar6 = 0;
  uVar4 = &stack0xfffffff4 < (undefined *)0x10;
  uVar5 = (undefined *)register0x00000010 == (undefined *)0x1c;
  puts();
  iVar1 = 7;
  str = a_user_name;
  name = "dat_wil";
   while (uVar5 && iVar1 != 0) {
    iVar1 = iVar1 + -1;
    uVar4 = *str < *name;
    uVar5 = *str == *name;
    ++str;
    ++name;
  }
  return ((!uVar4 && !uVar5) - uVar4);
}

int main(void)
{
  int ret;
  int i;
  char *tmp;
  char pass_input[16];
  int is_correct;
  
  i = 16;
  tmp = pass_input;
  while (i != 0) {
    --i;
    *tmp = 0;
    ++tmp;
  }
  is_correct = 0;
  puts("********* ADMIN LOGIN PROMPT *********");
  printf("Enter Username: ");
  fgets(a_user_name, 256, stdin);
  is_correct = verify_user_name();
  if (is_correct == 0) {
    puts("Enter Password: ");
    fgets(pass_input, 100, stdin);
    is_correct = verify_user_pass(pass_input);
    if ((is_correct == 0) || (is_correct != 0)) {
      puts("nope, incorrect password...\n");
      ret = 1;
    }
    else {
      ret = 0;
    }
  }
  else {
    puts("nope, incorrect username...\n");
    ret = 1;
  }
  return ret;
}
  0x08048580
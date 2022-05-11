int main(void)
{
  int iVar1;
  long lVar2;
  char *puVar3;
  char pass[14];
  char lvl3pass[6];
  char username[12];
  int ret;
  long fd;
  
  lVar2 = 12;
  puVar3 = username;
  while (lVar2 != 0) {
    lVar2 = lVar2 + -1;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)puVar3 = 0;
  lVar2 = 5;
  puVar3 = lvl3pass;
  while (lVar2 != 0) {
    lVar2 = lVar2 + -1;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined *)puVar3 = 0;
  lVar2 = 12;
  puVar3 = pass;
  while (lVar2 != 0) {
    lVar2 = lVar2 + -1;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)puVar3 = 0;
  fd = 0;
  ret = 0;
  fd = fopen("/home/users/level03/.pass", &DAT_00400bb0, &DAT_00400bb0);
  if (fd == 0) {
    fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  ret = fread(lvl3pass, 1, 41, fd);
  lVar2 = strcspn(lvl3pass, "\n");
  *(lvl3pass + lVar2) = 0;
  if (ret != 41) {
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  fclose(fd);
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets(username, 100, stdin);
  lVar2 = strcspn(username, "\n"); 
  *(username + lVar2) = 0;
  printf("--[ Password: ");
  fgets(pass,100,stdin);
  lVar2 = strcspn(pass, "\n");
  *(pass + lVar2) = 0;
  puts("*****************************************");
  iVar1 = strncmp(lvl3pass, pass, 41, pass);
  if (iVar1 == 0) {
    printf("Greetings, %s!\n", username, username);
    system("/bin/sh");
    return 0;
  }
  printf(username);
  puts(" does not have access!");
                    /* WARNING: Subroutine does not return */
  exit(1);
}

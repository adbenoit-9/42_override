int main(void)
{
  int pass[4];
  
  puts("***********************************");
  puts("* \t     -Level00 -\t\t  *");
  puts("***********************************");
  printf("Password:");
  __isoc99_scanf(&DAT_08048636,pass);
  if (pass[0] != 5276) {
    puts("\nInvalid Password!");
  }
  else {
    puts("\nAuthenticated!");
    system("/bin/sh");
  }
  return pass[0] != 5276;
}


//                         DAT_08048636                                    XREF[2]:     main:080484ce(*), 
//                                                                                     main:080484db(*)  
// 08048636 25              ??         25h    %
// 08048637 64              ??         64h    d
// 08048638 00              ??         00h

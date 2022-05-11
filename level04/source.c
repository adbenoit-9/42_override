int main(void)
{
  int i;
  char *tmp;
  uint local_a4;
  char buffer[32];
  uint local_20;
  uint local_1c;
  int local_18;
  int pid;
  
  pid = fork();
  i = 32;
  tmp = buffer;
  while (i != 0) {
    --i;
    *tmp = 0;
    ++tmp;
  }
  local_18 = 0;
  local_a4 = 0;
  if (pid == 0) {
    prctl(1,1);
    ptrace(0,0,0,0);
    puts("Give me some shellcode, k");
    gets(buffer);
  }
  else {
    do {
      wait(&local_a4);
      local_20 = local_a4;
      if (((local_a4 & 0x7f) == 0) ||
         (local_1c = local_a4, '\0' < (char)(((byte)local_a4 & 0x7f) + 1) >> 1)) {
        puts("child is exiting...");
        return 0;
      }
      local_18 = ptrace(3,pid,0x2c,0);
    } while (local_18 != 0xb);
    puts("no exec() for you");
    kill(pid, 9);
  }
  return 0;
}

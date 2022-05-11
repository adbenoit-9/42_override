int main(void)
{
  char buffer[100];
  uint i;

  fgets(buffer, 100, stdin);
  i = 0;
  while (true) {
    if (strlen(buffer) <= i) {
      printf(buffer);
      exit(0);
    }
    if (buffer[i] > '@' && buffer[i] < '[')
      buffer[i] = buffer[i] ^ 32;
    ++i;
  }
}

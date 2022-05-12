void log_wrapper(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  char cVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  char *pcVar5;
  long in_FS_OFFSET;
  byte bVar6;
  undefined8 local_120;
  char local_118 [264];
  long local_10;
  
  bVar6 = 0;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_120 = param_1;
  strcpy(local_118,param_2,param_2);
  uVar3 = 0xffffffffffffffff;
  pcVar5 = local_118;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + (ulong)bVar6 * -2 + 1;
  } while (cVar1 != '\0');
  uVar4 = 0xffffffffffffffff;
  pcVar5 = local_118;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + (ulong)bVar6 * -2 + 1;
  } while (cVar1 != '\0');
  snprintf(local_118 + (~uVar4 - 1),0xfe - (~uVar3 - 1),param_3);
  lVar2 = strcspn(local_118,&DAT_00400d4c);
  local_118[lVar2] = '\0';
  fprintf(local_120,"LOG: %s\n",local_118,"LOG: %s\n");
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

undefined8 main(int param_1,undefined8 *param_2)
{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  long in_FS_OFFSET;
  byte bVar7;
  char local_79;
  undefined8 local_78;
  undefined2 local_70;
  char local_6e;
  long local_10;
  
  bVar7 = 0;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_79 = -1;
  if (param_1 != 2) {
    printf("Usage: %s filename\n",*param_2,*param_2);
  }
  lVar3 = fopen("./backups/.log",&DAT_00400d6b,&DAT_00400d6b);
  if (lVar3 == 0) {
    printf("ERROR: Failed to open %s\n","./backups/.log");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  log_wrapper(lVar3,"Starting back up: ",param_2[1]);
  lVar4 = fopen(param_2[1],&DAT_00400da9,&DAT_00400da9);
  if (lVar4 == 0) {
    printf("ERROR: Failed to open %s\n",param_2[1],param_2[1]);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  local_78 = 0x70756b6361622f2e;
  local_70 = 0x2f73;
  local_6e = '\0';
  uVar5 = 0xffffffffffffffff;
  puVar6 = &local_78;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *(char *)puVar6;
    puVar6 = (undefined8 *)((long)puVar6 + (ulong)bVar7 * -2 + 1);
  } while (cVar1 != '\0');
  strncat(&local_78,param_2[1],99 - (~uVar5 - 1),param_2[1]);
  iVar2 = open(&local_78,0xc1,0x1b0);
  if (iVar2 < 0) {
    printf("ERROR: Failed to open %s%s\n","./backups/",param_2[1]);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  while( true ) {
    local_79 = fgetc(lVar4);
    if (local_79 == -1) break;
    write(iVar2,&local_79,1,&local_79);
  }
  log_wrapper(lVar3,"Finished back up ",param_2[1]);
  fclose(lVar4);
  close(iVar2);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}
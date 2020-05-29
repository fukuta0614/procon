
undefined8 main(void)

{
  size_t sVar1;
  long in_FS_OFFSET;
  char a;
  char b;
  int c;
  int d;
  int e;
  uint g;
  undefined4 h;
  int i;
  int j;
  FILE *f;
  FILE *origin;
  FILE *enc;
  char buf [56];
  long q;
  
  q = *(long *)(in_FS_OFFSET + 0x28);
  h = 0;
  f = fopen("flag.txt","r");
  origin = fopen("original.bmp","r");
  enc = fopen("encoded.bmp","a");
  if (f == (FILE *)0x0) {
    puts("No flag found, please make sure this is run on the server");
  }
  if (origin == (FILE *)0x0) {
    puts("original.bmp is missing, please run this on the server");
  }


  sVar1 = fread(&a,1,1,origin);
  c = (int)sVar1;
  i = 2000;
  d = 0;
  while (d < i) {
    fputc((int)a,enc);
    sVar1 = fread(&a,1,1,origin);
    c = (int)sVar1;
    d = d + 1;
  }
  sVar1 = fread(buf,0x32,1,f);

  j = (int)sVar1;
  if (j < 1) {
    puts("flag is not 50 chars");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }


  e = 0;
  while (e < 0x32) {
    g = 0;
    while ((int)g < 8) {
      b = codedChar((ulong)g,(ulong)(uint)(int)(char)(buf[e] + -5),
                           (ulong)(uint)(int)a,
                           (ulong)(uint)(int)(char)(buf[e] + -5));
      fputc((int)b,enc);
      fread(&a,1,1,origin);
      g = g + 1;
    }
    e = e + 1;
  }
  while (c == 1) {
    fputc((int)a,enc);
    sVar1 = fread(&a,1,1,origin);
    c = (int)sVar1;
  }
  fclose(enc);
  fclose(origin);
  fclose(f);
  if (q == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


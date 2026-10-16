typedef long s64;
extern unsigned char D_001BF200[];
s64 func_L00_002E2048(void) {
 s64 v=*(int *)(D_001BF200+0x1C);
 if(v<0) return -1;
 return (v&0x60)>>5;
}
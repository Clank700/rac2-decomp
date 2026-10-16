typedef int s32;
extern unsigned char D_001BF200[];
s32 func_L00_002E2048(void) {
 s32 v=*(s32 *)(D_001BF200+0x1C);
 if(v<0) return -1;
 return (v&0x60)>>5;
}
typedef int s32;
extern unsigned char D_001BF200[];
s32 func_L00_002E2048(void) {
 s32 v;
 if(*(s32 *)(D_001BF200+0x1C)<0) return -1;
 v=*(s32 *)(D_001BF200+0x1C);
 return (v&0x60)>>5;
}
typedef int s32;
extern int D_001BF21C;
s32 func_L00_002E2048(void) {
 s32 v=D_001BF21C;
 if(v<0) return -1;
 return (v&0x60)>>5;
}
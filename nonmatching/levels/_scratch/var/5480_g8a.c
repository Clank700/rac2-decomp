typedef unsigned char u8;
typedef int s32;
extern u8 D_00189E20[];
extern int D_001B19C8;
extern int D_001B19C8_1;
extern int func_002A77E0(int);
void func_L00_002A5480(void) {
 u8 *b=D_00189E20;
 if(*(int *)(b+0x1180)!=0) return;
 if(*(int *)(b+0x1188)==0) {
  *(int *)(b+0x1184)=D_001B19C8_1+0x1e;
  return;
 }
 if(*(int *)(b+0x1184)<D_001B19C8) {
  int t;
  *(int *)(b+0x1180)=1;
  t=func_002A77E0(*(int *)(b+0x1188));
  *(int *)(b+0x1184)=D_001B19C8_1+(t+0x14)+func_002A77E0(*(int *)(b+0x1188));
 }
}

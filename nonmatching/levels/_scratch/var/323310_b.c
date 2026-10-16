typedef unsigned char u8;
extern u8 D_001A63A8[];void func_L01_00323310(int a0,int a1) {
 u8 *b=D_001A63A8;
 int v;
 if(*(short *)(b+0x48)==a0&&*(short *)(b+0x3C)==-1) return;
 v=(a0!=-1)?(a0&0xFF):a0;
 v=(a1!=-1)?(v&0xFF):v;
 if(*(short *)(b+0x4E)!=0||*(short *)(b+0x96)!=0) {
  *(short *)(b+0x3E)=a1;
  *(short *)(b+0x3C)=v;
  return;
 }
 *(short *)(b+0x48)=v;
}
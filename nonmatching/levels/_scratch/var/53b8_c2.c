typedef unsigned char u8;
typedef int s32;
extern u8 D_L24_0025B710[];
extern void *func_L00_002A4FE8(short);
extern void func_0029F9F0(void *, void *);
extern void func_00282C88(void *);
void func_L00_002A53B8(void) {
 u8 *p=D_L24_0025B710;
 u8 *end=p+0x1b80;
 do {
  if(p[1]!=0) {
   void *e=func_L00_002A4FE8(*(short *)(p+0xA2));
   if(e!=0) func_0029F9F0(e,p);
  }
  func_00282C88(p+0x40);
  func_00282C88(p+0x60);
  func_00282C88(p+0x90);
  *(float *)(p+0xAC)=1.0f;
  p+=0xb0;
 } while((s32)p<(s32)end);
}

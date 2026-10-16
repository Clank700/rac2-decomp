typedef unsigned char u8;
extern u8 D_00189E20[];
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_L00_00324D18(void *,void *,void *,float,float,float,float,float);
void func_L00_00324E48(void *a0,void *a1,float f1,float f2,float f3,float f4,float f5) {
 u8 *b=D_00189E20;
 u8 buf[0x10];
 func_00282D30(buf,(void *)(*(int *)(b+0x2290)+0xE0),0.75f);
 func_00282CC0(buf,b+0x80,buf);
 func_L00_00324D18(buf,a0,a1,f1,f2,f3,f4,f5);
}
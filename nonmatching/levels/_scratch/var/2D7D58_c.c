typedef unsigned char u8;
typedef int s32;
extern u8 D_002A3A00[];
void func_L00_002D7D58(void *a0) {
 void *a1=a0;
 void (*f)(void *);
 f=*(void (**)(void *))((u8 *)D_002A3A00+(s32)*(short *)((u8 *)a1+0x8C)*20+8);
 if(f!=0) f(a1);
}
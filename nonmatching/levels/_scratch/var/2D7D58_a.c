typedef unsigned char u8;
extern u8 D_002A3A00[];
void func_L00_002D7D58(void *a0) {
 void *a1=a0;
 short i=*(short *)((u8 *)a1+0x8C);
 void (*f)(void *)=*(void (**)(void *))((u8 *)D_002A3A00+i*0x14+8);
 if(f) f(a1);
}
typedef unsigned char u8;
typedef struct { u8 pad[8]; void (*f)(void *); u8 rest[8]; } Ent;
extern Ent D_002A3A00[];
void func_L00_002D7D58(void *a0) {
 void *a1=a0;
 int off=*(short *)((u8 *)a1+0x8C)*20;
 Ent *e=(Ent *)((u8 *)D_002A3A00+off);
 if(e->f) e->f(a1);
}
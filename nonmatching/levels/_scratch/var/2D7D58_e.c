typedef unsigned char u8;
typedef struct { u8 pad[8]; void (*f)(void *); u8 rest[8]; } Ent;
extern Ent D_002A3A00[];
void func_L00_002D7D58(void *a0) {
 void *a1=a0;
 Ent *e=&D_002A3A00[*(short *)((u8 *)a1+0x8C)];
 Ent *g=e;
 if(g->f) g->f(a1);
}
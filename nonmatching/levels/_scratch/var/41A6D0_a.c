typedef unsigned char u8;
extern u8 D_001A63A8[];
int func_L12_0041A6D0(u8 *a0,unsigned a1) {
 u8 *b=D_001A63A8;
 if(*(int *)(b+0x68)!=0) return 0;
 if(*(int *)(b+0x24)!=-1) return 0;
 if(a1>=10) return 0;
 *(int *)(b+0x28)=(int)a0;
 *(int *)(b+0x24)=*(int *)(a0+a1*4+0x230)+0x7D0;
 return 1;
}
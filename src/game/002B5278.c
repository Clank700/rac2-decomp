#include "include_asm.h"

/* Measured partial C views; original types and object ownership are unknown. */
typedef unsigned char QwenRecovery_84e23fd54f9f_AbiByte16;

extern int func_002B50E0(QwenRecovery_84e23fd54f9f_AbiByte16 *owner, QwenRecovery_84e23fd54f9f_AbiByte16 *input, float factor);

typedef unsigned char u8;

typedef int s32;

extern u8 D_001A63A8[];

typedef struct { u8 before[0x68]; s32 active; u8 gap[6]; short state; } CallState;

extern void func_00133400(s32);

typedef unsigned int u32;

extern s32 func_00133230(void);

extern s32 func_00132028(void);

typedef struct {
 u8 before[0x2c]; short clear2c; u8 gap1[14]; short mode,next; u8 gap2[4];
 u32 busy44; short value48; u8 gap3[2]; short step4c,step4e; u8 gap4[24];
 u32 busy68; u8 gap5[4]; short step70,step72; u8 gap6[24];
 u32 busy8c; u8 gap7[4]; short step94,step96;
} WaitState;

extern s32 func_00133310(void);

extern s32 func_00133490(s32);

/* Frozen Batch A A05-store-rotation-52; acknowledged claim 43a7518b17439f6bdc9390be9d4164b47eec4bed94a72d581fdec3b883b0a554. */
typedef unsigned char BatchA_A05_u8;

typedef int BatchA_A05_s32;

typedef short BatchA_A05_BatchAs16;

typedef struct { BatchA_A05_u8 b[0x50]; BatchA_A05_BatchAs16 f50; BatchA_A05_BatchAs16 f52; BatchA_A05_u8 c[0x20]; BatchA_A05_BatchAs16 f74; BatchA_A05_BatchAs16 f76; BatchA_A05_u8 d[0x20]; BatchA_A05_BatchAs16 f98; BatchA_A05_BatchAs16 f9a; } BatchA_A05_BatchA52;

extern BatchA_A05_BatchA52 BatchA_A05_BatchA_D001A63A8;

/* Frozen Batch A A11-sda-3store-28; acknowledged claim 9b61d4cdd097ce0a56790793fdd6c129d3f0d822e40e788cde17e6418bdea65f. */
typedef unsigned char BatchA_A11_u8;

typedef unsigned short BatchA_A11_u16;

extern BatchA_A11_u8 BatchA_A11_D_001A63A8[];

/* Set the value of each enabled resident channel in its observed update order. */
typedef struct ResidentChannel64 {
    short flags;
    short value;
    u8 fields4[0x20];
} ResidentChannel64;

typedef struct ResidentChannels64 {
    u8 fields0[0x50];
    ResidentChannel64 channels[3];
} ResidentChannels64;

typedef struct __attribute__((packed)) { u8 mode[4]; } CdMode;

extern CdMode D_001A63E8;

extern u8 D_001A7900[] __attribute__((sda));

extern s32 D_001A7430[] __attribute__((sda));

extern s32 D_001A7434 __attribute__((sda));

extern s32 func_001334B8(s32,s32,s32,CdMode *);

extern s32 func_0011AEA0(s32);

extern s32 func_00133688(void);

extern float Fe617c30b_FUN_00283CE0(int a);

extern void Fe617c30b_FUN_00282D30(char *p, char *q, float f);

extern void Fe617c30b_FUN_00282CC0(char *p, char *q, char *r);

extern int Fe617c30b_FUN_002A9568(int a, int b, float f);

extern int Fe617c30b_FUN_00282978(char *p);

extern void Fe617c30b_FUN_002B9180(char *p);

extern int Fb77d67f1_FUN_00282948(char *p);

extern void Fb77d67f1_FUN_002B9180(char *p);

extern int Fd1c348f5_FUN_00282978(char *p);

extern int Fd1c348f5_FUN_00283CF0(float v);

extern void Fd1c348f5_FUN_002B9180(char *p);

void func_002B5278(QwenRecovery_84e23fd54f9f_AbiByte16 *param_1, float factor)
{
    func_002B50E0(param_1, param_1 + 0x10, factor);
}

INCLUDE_ASM("asm/game", func_002B5298);

INCLUDE_ASM("asm/game", func_002B52A0);

INCLUDE_ASM("asm/game", func_002B5678);

INCLUDE_ASM("asm/game", func_002B5828);

INCLUDE_ASM("asm/game", func_002B5BC0);

INCLUDE_ASM("asm/game", func_002B5CD8);

void *func_002B5D28(u8 *a0) { return *(void **)(*(u8 **)(a0 + 0x68) + 0x18); }

INCLUDE_ASM("asm/game", func_002B5D38);

INCLUDE_ASM("asm/game", func_002B5E48);

INCLUDE_ASM("asm/game", func_002B5EF8);

INCLUDE_ASM("asm/game", func_002B60A8);

INCLUDE_ASM("asm/game", func_002B60B0);

INCLUDE_ASM("asm/game", func_002B6118);

INCLUDE_ASM("asm/game", func_002B6120);

INCLUDE_ASM("asm/game", func_002B6220);

INCLUDE_ASM("asm/game", func_002B6228);

INCLUDE_ASM("asm/game", func_002B62A0);

INCLUDE_ASM("asm/game", func_002B62F8);

INCLUDE_ASM("asm/game", func_002B6318);

INCLUDE_ASM("asm/game", func_002B63C0);

INCLUDE_ASM("asm/game", func_002B6480);

INCLUDE_ASM("asm/game", func_002B65B8);

INCLUDE_ASM("asm/game", func_002B6650);

INCLUDE_ASM("asm/game", func_002B6658);

INCLUDE_ASM("asm/game", func_002B66F0);

void func_002B6770(int arg0, long arg1) {
    int *p = (int *)(int)arg1;

    if (p != 0) {
        *p = arg0;
    }
}

INCLUDE_ASM("asm/game", func_002B6788);

INCLUDE_ASM("asm/game", func_002B67E0);

INCLUDE_ASM("asm/game", func_002B6828);

INCLUDE_ASM("asm/game", func_002B68C0);

INCLUDE_ASM("asm/game", func_002B68C8);

INCLUDE_ASM("asm/game", func_002B6938);

INCLUDE_ASM("asm/game", func_002B6958);

s32 func_002B6D28(void) {
    if (((CallState *)D_001A63A8)->active==0) return 0;
    if (((CallState *)D_001A63A8)->state!=3) return 0;
    func_00133400(((CallState *)D_001A63A8)->active); ((CallState *)D_001A63A8)->state=4;
    return 1;
}

INCLUDE_ASM("asm/game", func_002B6D80);

INCLUDE_ASM("asm/game", func_002B6E78);

INCLUDE_ASM("asm/game", func_002B6F70);

INCLUDE_ASM("asm/game", func_002B7088);

void func_002B7170(void) {
    ((void (*)(void))func_00133230)();
    while (((WaitState *)D_001A63A8)->busy44 == 0xffffffffU) func_00132028();
    while (((WaitState *)D_001A63A8)->busy8c == 0xffffffffU) func_00132028();
    while (((WaitState *)D_001A63A8)->busy68 == 0xffffffffU) func_00132028();
    func_00133310();
    while (func_00132028() != 0) {}
    func_00133490(1);
    ((WaitState *)D_001A63A8)->step4e = 0; ((WaitState *)D_001A63A8)->step4c = 0; ((WaitState *)D_001A63A8)->busy44 = 0;
    if (((WaitState *)D_001A63A8)->mode != -1) ((WaitState *)D_001A63A8)->value48 = ((WaitState *)D_001A63A8)->mode;
    ((WaitState *)D_001A63A8)->step72 = 0; ((WaitState *)D_001A63A8)->step70 = 0; ((WaitState *)D_001A63A8)->busy68 = 0;
    ((WaitState *)D_001A63A8)->step96 = 0; ((WaitState *)D_001A63A8)->step94 = 0; ((WaitState *)D_001A63A8)->busy8c = 0;
    ((WaitState *)D_001A63A8)->clear2c = 0; ((WaitState *)D_001A63A8)->mode = -1;
    ((WaitState *)D_001A63A8)->next = -1;
}

void func_002B72E8(BatchA_A05_s32 a0) {
    if (a0 != 0) { BatchA_A05_BatchA_D001A63A8.f76 = 0; BatchA_A05_BatchA_D001A63A8.f74 = -0x8000; }
    BatchA_A05_BatchA_D001A63A8.f9a = 0;
    BatchA_A05_BatchA_D001A63A8.f50 = -0x8000;
    BatchA_A05_BatchA_D001A63A8.f52 = 0;
    BatchA_A05_BatchA_D001A63A8.f98 = -0x8000;
}

void func_002B7320(void) {
    BatchA_A11_u8 *p = BatchA_A11_D_001A63A8;
    *(BatchA_A11_u16 *)(p + 0x50) = 4;
    *(BatchA_A11_u16 *)(p + 0x98) = 4;
    *(BatchA_A11_u16 *)(p + 0x74) = 4;
}

void func_002B7340(s32 value)
{
    ResidentChannels64 *state = (ResidentChannels64 *)D_001A63A8;
    if (state->channels[0].flags & 0x8000)
        state->channels[0].value = value;
    if (state->channels[2].flags & 0x8000)
        state->channels[2].value = value;
    if (state->channels[1].flags & 0x8000)
        state->channels[1].value = value;
}

INCLUDE_ASM("asm/game", func_002B7380);

INCLUDE_ASM("asm/game", func_002B7578);

INCLUDE_ASM("asm/game", func_002B7AD0);

INCLUDE_ASM("asm/game", func_002B7B18);

INCLUDE_ASM("asm/game", func_002B7BC0);

s32 func_002B7C10(s32 a0, s32 a1, s32 a2) {
    CdMode mode = D_001A63E8;
    mode.mode[1] = D_001A7900[0];
    D_001A7430[0] = 0; D_001A7434 = 0;
    func_001334B8(a1,a2,a0,&mode);
    func_00133230(); func_00132028();
    return 1;
}

INCLUDE_ASM("asm/game", func_002B7C80);

INCLUDE_ASM("asm/game", func_002B7CE0);

void func_002B7D88(s32 a0) {
    if (a0 == 1) {
        if (func_00133688() != 0) { *(short *)(D_001A63A8+4) = 2; } else {
            void (*callback)(s32,s32);
            s32 data, flag;
            ((void (*)(s32))func_0011AEA0)(0);
            flag = D_001A63A8[6] == 0;
            callback = *(void (**)(s32,s32))(D_001A63A8+0x18);
            *(short *)(D_001A63A8+4) = 0;
            D_001A63A8[6] = 0;
            if (callback) {
                data = *(s32 *)(D_001A63A8+0x1c);
                *(void (**)(s32,s32))(D_001A63A8+0x18) = 0;
                *(s32 *)(D_001A63A8+0x1c) = 0;
                callback(data,flag);
            }
        }
    }
}

void func_002B7DF8(int arg0, long arg1) {
    short *p = (short *)(int)arg1;

    if (p != 0 && arg0 != 0 && p[5] == 2) {
        p[5] = 3;
    }
}

INCLUDE_ASM("asm/game", func_002B7E28);

INCLUDE_ASM("asm/game", func_002B7EA8);

INCLUDE_ASM("asm/game", func_002B7F08);

INCLUDE_ASM("asm/game", func_002B7F58);

void func_002B7FB0(int arg0, long arg1) {
    short *p = (short *)(int)arg1;

    if (p != 0) {
        *(int *)p = arg0;
        if (arg0 != 0) {
            if (p[5] == 1) {
                p[5] = 8;
            }
        } else {
            p[5] = 0;
        }
    }
}

INCLUDE_ASM("asm/game", func_002B7FF0);

INCLUDE_ASM("asm/game", func_002B8048);

INCLUDE_ASM("asm/game", func_002B80B8);

INCLUDE_ASM("asm/game", func_002B8108);

INCLUDE_ASM("asm/game", func_002B8518);

INCLUDE_ASM("asm/game", func_002B8530);

INCLUDE_ASM("asm/game", func_002B8548);

INCLUDE_ASM("asm/game", func_002B85F8);

void func_002B8888(u8 *a0) {
 s32 *p=(s32 *)(a0+0x140);s32 count=15;
 *(s32 *)(a0+0x1b0)=0;*(volatile s32 *)(a0+0x1d4)=1;
 *(volatile s32 *)(a0+0x1a0)=0;*(volatile s32 *)(a0+0x1a4)=0;*(volatile s32 *)(a0+0x1a8)=0;
 *(volatile s32 *)(a0+0x1d0)=1;*(volatile s32 *)(a0+0x1b4)=0;*(volatile s32 *)(a0+0x1b8)=0;
 *(volatile s32 *)(a0+0x1c0)=0;*(volatile s32 *)(a0+0x1c4)=0;*(volatile s32 *)(a0+0x1c8)=0;*(volatile s32 *)(a0+0x1d8)=0;
 do { p[-16]=0;count--;p[0]=0;p++; }while(count>=0);
}

INCLUDE_ASM("asm/game", func_002B88F0);

INCLUDE_ASM("asm/game", func_002B9000);

INCLUDE_ASM("asm/game", func_002B9030);

INCLUDE_ASM("asm/game", func_002B9038);

INCLUDE_ASM("asm/game", func_002B9180);

INCLUDE_ASM("asm/game", func_002B9288);

INCLUDE_ASM("asm/game", func_002B9380);

INCLUDE_ASM("asm/game", func_002B9390);

INCLUDE_ASM("asm/game", func_002B9420);

INCLUDE_ASM("asm/game", func_002BA048);

INCLUDE_ASM("asm/game", func_002BA0E0);

INCLUDE_ASM("asm/game", func_002BA6A0);

INCLUDE_ASM("asm/game", func_002BA8A0);

INCLUDE_ASM("asm/game", func_002BA978);

INCLUDE_ASM("asm/game", func_002BAA28);

INCLUDE_ASM("asm/game", func_002BABE8);

INCLUDE_ASM("asm/game", func_002BAE48);

INCLUDE_ASM("asm/game", func_002BAE50);

void func_002BAF68(char *a0)
{
    char *s0 = a0 + 32;
    int x;
    int u;
    int t;
    float f;

    x = *(int *)(s0 + 28);
    t = *(short *)(a0 + 10);
    u = *(short *)(s0 + 24) * (x - t) / x + *(short *)(s0 + 26);

    f = Fe617c30b_FUN_00283CE0(u) * 1000.0f;
    *(float *)(a0 + 12) = f;
    Fe617c30b_FUN_00282D30(s0, s0, 9.8000001907348632812500e-01f);
    Fe617c30b_FUN_00282CC0(a0 + 16, a0 + 16, s0);
    *(unsigned char *)(a0 + 8) = *(unsigned char *)(a0 + 8) + 1;
    f = Fe617c30b_FUN_00283CE0(*(int *)(s0 + 28));
    *(int *)(a0 + 4) = Fe617c30b_FUN_002A9568(*(int *)(s0 + 20), *(int *)(s0 + 16),
                               (float)*(short *)(a0 + 10) / f);
    if (Fe617c30b_FUN_00282978(a0 + 10) != 0)
        Fe617c30b_FUN_002B9180(a0);
}

INCLUDE_ASM("asm/game", func_002BB050);

INCLUDE_ASM("asm/game", func_002BB100);

void func_002BB798(char *a0)
{
    char *p = a0 + 32;

    if (Fb77d67f1_FUN_00282948(p) != 0) {
        Fb77d67f1_FUN_002B9180(a0);
        return;
    }
    *(float *)(a0 + 12) = *(float *)(a0 + 12) + *(float *)(p + 4);
    if (*(int *)(a0 + 32) < 6)
        *(int *)(a0 + 4) = (*(int *)(a0 + 4) & 0xFFFFFF)
                         | ((*(int *)(a0 + 32) * 127 / 6) << 24);
}

INCLUDE_ASM("asm/game", func_002BB838);

INCLUDE_ASM("asm/game", func_002BB928);

INCLUDE_ASM("asm/game", func_002BBA38);

INCLUDE_ASM("asm/game", func_002BBB70);

INCLUDE_ASM("asm/game", func_002BBCB0);

INCLUDE_ASM("asm/game", func_002BBF40);

INCLUDE_ASM("asm/game", func_002BC508);

INCLUDE_ASM("asm/game", func_002BC768);

void func_002BC8E8(char *p)
{
    char *q = p + 32;
    int r;
    int v;
    float f;

    *(unsigned char *)(p + 8) = *(unsigned char *)(p + 8) + *(unsigned char *)(q + 8);
    *(float *)(p + 24) = *(float *)(p + 24) + *(float *)(q + 16);
    *(float *)(p + 12) = *(float *)(p + 12) * *(float *)(q + 12);
    if (*(int *)(q + 4) == 0) {
        r = Fd1c348f5_FUN_00282978(p + 10);
        if (r != 0) {
            *(int *)(q + 4) = 1;
            *(short *)(p + 10) = 30;
            *(int *)(p + 4) = *(int *)(q + 20) | 0x7f000000;
        } else {
            f = (float)(10 - *(short *)(p + 10)) * 9.6000003814697265625000e+00f;
            v = Fd1c348f5_FUN_00283CF0(f);
            *(int *)(p + 4) = ((v + 32) << 24) | *(int *)(q + 20);
        }
    } else {
        r = Fd1c348f5_FUN_00282978(p + 10);
        if (r != 0) {
            Fd1c348f5_FUN_002B9180(p);
        } else {
            f = (float)*(short *)(p + 10) * 4.2333333492279052734375e+00f;
            v = Fd1c348f5_FUN_00283CF0(f);
            *(int *)(p + 4) = (v << 24) | *(int *)(q + 20);
        }
    }
}

INCLUDE_ASM("asm/game", func_002BCA08);

INCLUDE_ASM("asm/game", func_002BCB00);

INCLUDE_ASM("asm/game", func_002BCC58);

INCLUDE_ASM("asm/game", func_002BCF18);

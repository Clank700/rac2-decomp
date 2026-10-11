#include "include_asm.h"

extern void func_00291788(unsigned long long);

extern void func_00291640(unsigned long long);

/* Frozen Batch A A02-list-add-88; acknowledged claim 38ceeb041b6ba12996de10c402ca54295587db96246845b83b2ec894986b096f. */
typedef unsigned char BatchA_A02_u8;

typedef int BatchA_A02_s32;

typedef struct { char _0[0x10]; BatchA_A02_u8 n; char _11[3]; BatchA_A02_s32 off; char _18[4]; BatchA_A02_s32 ent[1]; } BatchA_A02_Blk;

typedef int s32;

typedef unsigned char u8;

extern void F46b43b72_FUN_002B7B18(int value, char *target);

extern void F46b43b72_FUN_002B7CE0(int value);

extern int F46b43b72_D_001B8840[];

extern int F46b43b72_D_0014B540[];

struct Slot { s32 w; s32 rest[4]; };

struct Table1 { char pad[19264]; struct Slot slots[48]; };

struct Table2 { char pad[52]; s32 slots[4]; };

extern struct Table1 Fee2b87d1_D_0014B540;

extern struct Table2 Fee2b87d1_D_00152CD0;

typedef unsigned int u32;

/* --- verbatim preprocessed fp-bit.c ends here --- */

extern u8 BOOT_D_001395B8[];

typedef struct {
    u8 prefix[0xa7];
    u8 fielda7;
} OrbitalBitmapView;

extern u8 D_001395B8[];

extern int D_L03_001CA2A8[];

/* 28-entry table scan.  The table is reached through the resident pointer at
   0x1AA7F0; the caller's id is looked up from index 0, the first hit wins, and
   an index is rejected when its slot is empty while the small-data flag at
   0x1A79F0 is set.  The flag is read through $gp and the load sits in the delay
   slot of the bail-out branch, so the body needs the -G8 small-data profile.

   Measured shape note: the table pointer must be reached through the global
   itself (`D_L01_001AA7F0[i]`), not through a local `int *` copy.  With a local the
   allocator keeps one register for the whole live range (26 instructions);
   with the global gcc loads it into $v1, hoists the loop-invariant value and
   emits the retail `move $a2,$v1` copy at the block boundary (28 instructions,
   byte-identical). */
extern int *D_L01_001AA7F0 __attribute__((sda));

extern int D_001A79F0_3 __attribute__((sda));

extern void F6df9730c_FUN_00282B50(char *dst, int *src, int count);

/* Find a mapped record by its unsigned halfword class and return its opaque word. */
typedef struct {
    unsigned int marker;
    unsigned char reserved04[0x38];
    unsigned short class_code;
    unsigned char reserved3E[0xa2];
} MappedClassEntry;

extern unsigned char D_00139568[];

extern MappedClassEntry D_L00_00262570[];

/* Substitute the first percent selector in a record's localized text. */
typedef struct {
    unsigned char gap0[10];
    short text_id;
    short mapped_key;
    unsigned char gap0e[26];
} DobboFormatRow396;

typedef struct {
    unsigned char gap0[32];
    DobboFormatRow396 *rows;
} DobboFormatRoot396;

typedef struct {
    unsigned char gap0[0x80];
    int amount;
    unsigned char gap84[0x5c];
} DobboFormatMapped396;

extern DobboFormatRoot396 D_L00_001C93A0;

extern const char D_L00_001A9AA0[];

extern const char D_L00_001A9AA8[];

extern const unsigned char *func_00288FB8(int);

extern void func_00115DA8(char *, const char *, ...);

void func_00291758(unsigned long long param_1)
{
    func_00291788(param_1);
    func_00291640(param_1);
}

INCLUDE_ASM("asm/game", func_00291788);

INCLUDE_ASM("asm/game", func_00291850);

INCLUDE_ASM("asm/game", func_00291CA0);

INCLUDE_ASM("asm/game", func_00291CA8);

INCLUDE_ASM("asm/game", func_00291DE0);

INCLUDE_ASM("asm/game", func_00291EC0);

INCLUDE_ASM("asm/game", func_00292078);

INCLUDE_ASM("asm/game", func_00292328);

INCLUDE_ASM("asm/game", func_002923C0);

INCLUDE_ASM("asm/game", func_00292408);

INCLUDE_ASM("asm/game", func_002925E0);

INCLUDE_ASM("asm/game", func_002925F0);

INCLUDE_ASM("asm/game", func_002926B8);

INCLUDE_ASM("asm/game", func_00292888);

INCLUDE_ASM("asm/game", func_00292B20);

INCLUDE_ASM("asm/game", func_00292B88);

INCLUDE_ASM("asm/game", func_00292EB0);

INCLUDE_ASM("asm/game", func_00293000);

void func_00293260(int *a0, int a1){
  BatchA_A02_Blk *r;
  int i;
  a0 += a1;
  r = *(BatchA_A02_Blk **)((char *)a0 + 0x48);
  if (r->off) r->off = (int)r + r->off;
  for (i = 0; i < r->n; i++) r->ent[i] = (int)r + r->ent[i];
}

INCLUDE_ASM("asm/game", func_002932B8);

INCLUDE_ASM("asm/game", func_002933D0);

void func_002934B8(u8 *a0, u8 *a1) {
    *(u8 *)(a0 + 4) = *(u8 *)(a1 + 0);
    *(u8 *)(a0 + 5) = *(u8 *)(a1 + 1);
    *(u8 *)(a0 + 6) = *(u8 *)(a1 + 2);
    *(u8 *)(a0 + 7) = *(u8 *)(a1 + 3);
    *(u8 **)(a0 + 0x0) = a1 + *(s32 *)(a1 + 4);
    *(u8 **)(a0 + 0x20) = a1 + *(s32 *)(a1 + 8);
}

INCLUDE_ASM("asm/game", func_002934F8);

INCLUDE_ASM("asm/game", func_00293890);

INCLUDE_ASM("asm/game", func_002939B8);

INCLUDE_ASM("asm/game", func_002939D0);

INCLUDE_ASM("asm/game", func_00293A58);

INCLUDE_ASM("asm/game", func_00293A60);

INCLUDE_ASM("asm/game", func_00293CA0);

int func_00293CA8(int index)
{
    int j = index + 1;
    int *d = F46b43b72_D_001B8840;
    int *b = F46b43b72_D_0014B540;
    int *t = (int *)((char *)b + 25416);
    int n = d[12] * 332;
    int hold = d[28];
    int j4 = j * 4;
    int cur = *(int *)((char *)t + (n + index * 4));
    int next = *(int *)((char *)t + (j4 + n));

    n = next - cur;
    if (n > 0) {
        F46b43b72_FUN_002B7B18(hold, (char *)(cur + b[6341]));
        F46b43b72_FUN_002B7CE0(0);
    }
    return 1;
}

INCLUDE_ASM("asm/game", func_00293D30);

INCLUDE_ASM("asm/game", func_00293F98);

INCLUDE_ASM("asm/game", func_00294070);

INCLUDE_ASM("asm/game", func_002940C0);

INCLUDE_ASM("asm/game", func_00294130);

INCLUDE_ASM("asm/game", func_00294180);

INCLUDE_ASM("asm/game", func_002942A0);

INCLUDE_ASM("asm/game", func_00294398);

INCLUDE_ASM("asm/game", func_00294420);

INCLUDE_ASM("asm/game", func_002945E8);

s32 func_00294630(s32 value) {
    s32 i = 0;
    s32 *q;
    if (Fee2b87d1_D_0014B540.slots[0].w == value) goto after1;
    while (++i < 48) {
        if (Fee2b87d1_D_0014B540.slots[i].w == value) break;
    }
after1:
    if (i == 48) return 1;
    value = 0;
    if (Fee2b87d1_D_00152CD0.slots[0] == i) goto after2;
    while (++value < 3) {
        if (Fee2b87d1_D_00152CD0.slots[value] == i) break;
    }
after2:
    return value != 3;
}

INCLUDE_ASM("asm/game", func_002946C0);

INCLUDE_ASM("asm/game", func_00294988);

INCLUDE_ASM("asm/game", func_00294BC8);

INCLUDE_ASM("asm/game", func_00294C40);

INCLUDE_ASM("asm/game", func_00294D80);

s32 func_00294E48(s32 index)
{
    s32 byte = index / 8;
    s32 bit = index % 8;
    s32 old;

    if ((u32)bit < 8) {
        old = (BOOT_D_001395B8[byte + 0xA7] >> bit) & 1;
    } else {
        old = 0;
    }
    if ((u32)bit < 8) {
        BOOT_D_001395B8[byte + 0xA7] |= 1 << bit;
    }
    return old;
}

/* returns the indexed resident bit using signed division by eight and an unsigned remainder validity guard */
u32 func_00294EC8(s32 index) {
    s32 slot=index/8;
    u32 bit=index%8;
    u32 previous=0;
    if(bit<8) {
        OrbitalBitmapView *state=(OrbitalBitmapView *)(D_001395B8+slot);
        previous=((s32)state->fielda7>>bit)&1;
    }
    return previous;
}

INCLUDE_ASM("asm/game", func_00294F10);

INCLUDE_ASM("asm/game", func_002954C0);

/* shared native body of family 9306cc1f965a5c85 */
int func_00295680(int arg)
{
    int *t = D_L03_001CA2A8;
    int *u = t + 5;
    int i;

    for (i = 0; i < 5; i++) {
        int k = arg ? 4 - i : i;
        if (t[k] == 0)
            continue;
        if (u[k] != -1)
            continue;
        return k;
    }
    return -1;
}

INCLUDE_ASM("asm/game", func_002956E8);

INCLUDE_ASM("asm/game", func_00295788);

INCLUDE_ASM("asm/game", func_00295828);

INCLUDE_ASM("asm/game", func_00295870);

INCLUDE_ASM("asm/game", func_002958B8);

/* shared native body of family 490e2c59eb9d7105 */
int func_00295A10(int param_1)
{
    int index = -1;
    int i;

    for (i = 0; i < 28; i++)
        if (D_L01_001AA7F0[i] == param_1) { index = i; break; }

    if (D_L01_001AA7F0[index] == 0)
        index = D_001A79F0_3 ? -1 : index;

    return index;
}

INCLUDE_ASM("asm/game", func_00295A80);

INCLUDE_ASM("asm/game", func_00295BE0);

void func_00295BE8(u8 *a0,u8 *a1,u8 *a2,u8 *a3) {
 s32 i=0;
 do {
  s32 next=i+1;
  u32 mask=1;
  u8 *nextp=a3+1;
  s32 j=7;
  do {
   u8 value;
   j--;
   if(*a3&mask) value=*a1; else value=*a2;
   mask<<=1;
   *a0=value;
   a1++;a2++;a0++;
  } while(j>=0);
  i=next;
  a3=nextp;
 } while(i<0x8000);
}

INCLUDE_ASM("asm/game", func_00295C50);

INCLUDE_ASM("asm/game", func_00295C70);

INCLUDE_ASM("asm/game", func_00295D00);

INCLUDE_ASM("asm/game", func_00295F60);

INCLUDE_ASM("asm/game", func_00297218);

INCLUDE_ASM("asm/game", func_00297400);

void func_00297550(u8 *out,s32 index,u8 *base,short *offsets) {
    s32 pending=0;
    u8 *start;
    short *table;
    s32 records,i;
    if (index!=0) start=base+(offsets+index)[-1];
    else start=base+0x200;
    table=(short *)(index*2+(s32)offsets);
    records=((base+*table-start)*2)/3;
    for(i=0;i<records;i++) {
        s32 position=i*2+i;
        u8 *p=start+(position>>1);
        u8 color=p[0],runByte=p[1],fill;
        s32 run;
        if ((position&1)!=0) color>>=4;
        else {
            runByte=(u8)((runByte<<4)|(color>>4));
            color&=15;
        }
        run=256;
        if(runByte!=0) run=runByte;
        fill=(u8)(color|(color<<4));
        if(pending) {
            pending=0;run--;
            *out |= color<<4;
            out++;
        }
        if(run!=0) {
            do {*out++=fill;run-=2;} while(run>0);
            if(run!=0) {out--;pending=1;*out=color;}
        }
    }
}

INCLUDE_ASM("asm/game", func_00297668);

INCLUDE_ASM("asm/game", func_00297670);

INCLUDE_ASM("asm/game", func_00297730);

INCLUDE_ASM("asm/game", func_002977A8);

void func_002979D8(char *dst, unsigned char *src)
{
    int table[256];
    int tmp[16];
    int *q;
    int i, j, k;

    for (i = 0; i < 256; i++) {
        table[i] = 0;
        if (i & 0x01) table[i] = 0x0000000f;
        if (i & 0x02) table[i] |= 0x000000f0;
        if (i & 0x04) table[i] |= 0x00000f00;
        if (i & 0x08) table[i] |= 0x0000f000;
        if (i & 0x10) table[i] |= 0x000f0000;
        if (i & 0x20) table[i] |= 0x00f00000;
        if (i & 0x40) table[i] |= 0x0f000000;
        if (i & 0x80) table[i] |= 0xf0000000;
    }
    for (j = 0; j < 128; j++) {
        char *next;
        q = tmp;
        next = dst + 64;
        for (k = 15; k >= 0; k--) {
            *q++ = table[*src++];
        }
        F6df9730c_FUN_00282B50(dst, tmp, 64);
        dst = next;
        F6df9730c_FUN_00282B50(dst, tmp, 64);
        dst += 64;
        F6df9730c_FUN_00282B50(dst, tmp, 64);
        dst += 64;
        F6df9730c_FUN_00282B50(dst, tmp, 64);
        dst += 64;
    }
}

INCLUDE_ASM("asm/game", func_00297BA8);

INCLUDE_ASM("asm/game", func_00297BB0);

/* localized row40 textID10 firstpercent selector b formats signedmappedword80 with original decimalformatter; other selector formats original error string, preserve prefix/tail */
void func_00297E00(int index, unsigned char *output)
{
    unsigned char temporary[80];
    const unsigned char *source = func_00288FB8(D_L00_001C93A0.rows[index].text_id);
    unsigned char *p = temporary;
    if (!source)
        return;
    while (*source && *source != '%')
        *output++ = *source++;
    if (!*source) {
        *output = *source;
        return;
    }
    ++source;
    if (*source == 'b') {
        int key = D_L00_001C93A0.rows[index].mapped_key;
        DobboFormatMapped396 *record = (DobboFormatMapped396 *)&D_L00_00262570[D_00139568[key]];
        func_00115DA8((char *)temporary, D_L00_001A9AA0, record->amount);
    } else {
        func_00115DA8((char *)temporary, D_L00_001A9AA8);
    }
    ++source;
    while (*p)
        *output++ = *p++;
    while (*source)
        *output++ = *source++;
    *output = 0;
}

INCLUDE_ASM("asm/game", func_00297F98);

INCLUDE_ASM("asm/game", func_00297FE8);

INCLUDE_ASM("asm/game", func_002980C8);

INCLUDE_ASM("asm/game", func_002980D0);

void func_00298170(void)
{
}

INCLUDE_ASM("asm/game", func_00298178);

INCLUDE_ASM("asm/game", func_00298278);

INCLUDE_ASM("asm/game", func_00298298);

INCLUDE_ASM("asm/game", func_00298380);

INCLUDE_ASM("asm/game", func_002983A8);

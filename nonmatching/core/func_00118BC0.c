/* from src/core/001163B0.c: C that compiles to 276 bytes where retail has 264 */
/*
 * Staging buffer: each byte of src[i] goes through the write pointer
 * D_0013466C, the count D_00134668 is incremented, and when it reaches 0x80
 * the buffer at D_0013C100 is handed to func_0011B1E8 (object, buffer base,
 * count), the pointer and the count are reset, and a zero return ends the
 * function with 0. A fourth argument of 1 flushes what is held and resets
 * without writing. func_00119AC0 is the same routine over 0x4670/0x4674 and
 * the buffer at 0x0013C180.
 *
 * What differs is addressing and register pressure, twelve bytes' worth: this
 * cc1 materialises the address of both globals into a register and reads them
 * at offset 0 (`lw $v1,0($s3)`), keeps the buffer base in a further register
 * and the constant 0x80 in another ($s7/$fp, frame 0xA0), where retail keeps
 * one `lui` base and the offset in every access (`lw $a0,0x466C($s1)`), tests
 * with `slti` and stays in the 0x80 frame. Passing the count rather than the
 * literal to the flush call removes one of those registers but not the rest;
 * the array spelling of both globals (`extern int D_x[1]`, `D_x[0]`) changes
 * nothing here.
 */
extern char D_0013C100[];

extern int D_00134668[1];

extern char *D_0013466C[1];

extern int func_0011B1E8(int arg0, char *buf, int count);

int func_00118BC0(int arg0, char *src, int len, int flush) {
    int i;

    if (flush == 1) {
        func_0011B1E8(arg0, D_0013C100, D_00134668[0]);
        D_00134668[0] = 0;
        D_0013466C[0] = D_0013C100;
        return 0;
    }
    for (i = 0; i < len; i++) {
        *D_0013466C[0]++ = src[i];
        if (++D_00134668[0] == 0x80) {
            if (func_0011B1E8(arg0, D_0013C100, D_00134668[0]) == 0)
                return 0;
            D_0013466C[0] = D_0013C100;
            D_00134668[0] = 0;
        }
    }
    return i;
}

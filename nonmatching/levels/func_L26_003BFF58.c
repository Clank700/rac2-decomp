/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh checks on the qualified current compiler, 2026-10-25.
 * Profile: -O2 -G8 -ffunction-sections
 * Coverage: US: 0/1; US2: 0/1; PAL: 0/1.
 * Compiled text: 1732 bytes; retail text: 1804 bytes.
 * Remaining difference: Frame 0x320 matches, preserving all 128 disabled-object pointers and
 * restore loops. The 1732-byte body differs from the 1804-byte target in register ownership, early
 * global base reuse and branch scheduling. Replacing the initial TI origin copy with qcopy does
 * not solve the discrepancy.
 * Reopen when: Recover canonical player/collision-global layouts and the target-selection live
 * ranges without reducing the disabled-object array.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern float D_L26_001AFDB4 __attribute__((sda));
extern float D_L26_001AFDB0 __attribute__((sda));
extern int D_L26_001A8FF0;
extern int D_L26_001A8FF4 __attribute__((sda));
extern char *D_0018C0B0;
extern short D_0018A168;
extern float D_00189EA0[4];
extern float D_0018A144;
extern char *D_L26_001FAAA0[];
extern char *D_L26_001BEFD8;
extern Vector D_L26_001BEFE0;
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002761F8(void *, void *, int, void *, void *);
extern s32 func_002AB1F0(u8 *);
extern float func_00283248(float, float);
extern float func_00282E80(void *, void *);
extern float func_00283C80(float, float);
extern float func_00282E48(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern float func_00282C48(float);
extern float func_00282DF0(void *);
extern float func_002831B0(float);
extern void func_002AF000(float *, float, float, float);
extern float func_00283CE0(int);

char *func_L26_003BFF58(char *object, Vector *origin, float *heading, float *pitch) {
    Vector start;
    Vector eye_offset;
    Vector player_eye;
    char *disabled[128];
    Vector target_point;
    Vector offset;
    Vector delta;
    Vector projected;
    char *private = *(char **)(object + 0x68);
    char *target;
    char *descriptor;
    char *result = 0;
    char *hit;
    float best = D_L26_001AFDB4;
    float yaw;
    float elevation;
    float difference;
    float distance;
    float projection;
    float length;
    float cone;
    float radius;
    float margin;
    int close;
    int allowed;
    int index;
    int disabled_count = 0;
    int retries;
    int i;
    qcopy(&start, origin);
    func_00282D30(&eye_offset, D_0018C0B0 + 0xE0, 0.5f);
    func_00282CC0(&player_eye, D_0018C0B0 + 0x10, &eye_offset);
    if (func_002761F8(&player_eye, &start, 6, D_0018C0B0, 0)) return 0;
    for (index = 0; (target = D_L26_001FAAA0[index]) != 0; index++) {
        if ((signed char)target[0x20] == -2 || (signed char)target[0x20] == -3 ||
            *(short *)(target + 0xAA) == 0xE7D || *(short *)(target + 0xAA) == 0xEB0)
            continue;
        qcopy(&target_point, (target + 0x10));
        descriptor = (char *)func_002AB1F0((u8 *)target);
        if (!descriptor || descriptor[0xE] == 3) continue;
        func_00282D30(&offset, target + 0xE0, *(float *)(descriptor + 0x10));
        func_00282CC0(&target_point, &target_point, &offset);
        if (!*(char **)(target + 0x24) || *(short *)(*(char **)(target + 0x24) + 0x46) != 5)
            continue;
        close = 0;
        yaw = func_00283248(target_point.f[0] - start.f[0], target_point.f[1] - start.f[1]);
        elevation = func_00283248(func_00282E80(&start, &target_point), target_point.f[2] - start.f[2]);
        difference = func_00283C80(*heading, yaw);
        distance = func_00282E48(&start, &target_point);
        if (!D_L26_001A8FF0 && D_0018A168 == 0 && !D_L26_001A8FF4) {
            if (distance < 2.5f &&
                func_00283C80(*(float *)(D_0018C0B0 + 0xF8),
                    func_00283248(*(float *)(target + 0x10) - D_00189EA0[0],
                                   *(float *)(target + 0x14) - D_00189EA0[1])) < 1.0471977f &&
                func_00282C48(start.f[2] - target_point.f[2]) < 2.0f)
                close = 1;
        } else if (distance < 2.5f) {
            func_00282CF0(&delta, target + 0x10, D_0018C0B0 + 0x10);
            projection = func_00282DB0(&delta, D_0018C0B0 + 0xE0);
            if (func_00282C48(projection) < 2.0f) {
                func_00282D30(&projected, D_0018C0B0 + 0xE0, projection);
                func_00282CF0(&delta, &delta, &projected);
                projection = func_00282DB0(&delta, D_0018C0B0 + 0xC0);
                length = func_00282DF0(&delta);
                if (length != 0.0f && 1.5707964f - func_002831B0(projection / length) < 1.0471977f)
                    close = 1;
            }
        }
        if (close && !func_002761F8(&start, &target_point, 6, D_0018C0B0, 0)) {
            result = target;
            *pitch = -elevation;
            *heading = yaw;
            break;
        }
        if (!((distance <= best || target == *(char **)(private + 0x10)) && distance <= D_L26_001AFDB4))
            continue;
        func_002AF000(offset.f, distance, *heading, *pitch + D_0018A144 * 0.5f);
        func_00282CC0(&offset, &offset, &start);
        cone = func_002831B0(func_00282E48(&offset, &target_point) / (distance + distance));
        cone += cone;
        if (cone > D_L26_001AFDB0 * 0.017453294f) {
            descriptor = (char *)func_002AB1F0((u8 *)target);
            if (descriptor) {
                radius = func_00283CE0((unsigned char)descriptor[0xA]) * 0.125f;
                margin = func_002831B0(radius / distance);
                if (radius < distance) {
                    cone -= margin;
                    if (cone < 0.0f) cone = 0.0f;
                }
            }
        }
        allowed = 1;
        if (cone < D_L26_001AFDB0 * 0.017453294f) {
            qcopy(&delta, &start);
            retries = 0;
            while (func_002761F8(&delta, &target_point, 6, object, 0)) {
                if (++retries > 6) break;
                hit = D_L26_001BEFD8;
                if (!hit) { allowed = 0; break; }
                if (*(short *)(hit + 0xAA) != 0xE7D && *(short *)(hit + 0xAA) != 0xEB0) {
                    if (hit != target) allowed = 0;
                    break;
                }
                disabled[disabled_count++] = hit;
                *(int *)(hit + 0x98) = 0;
                if (disabled_count >= 128) break;
                qcopy(&delta, &D_L26_001BEFE0);
            }
            if (allowed) {
                *pitch = -elevation;
                if (difference < 0.17453295f) *heading = yaw;
                result = target;
                best = distance;
                if (target == *(char **)(private + 0x10)) return target;
            }
        }
    }
    for (i = 0; i < disabled_count; i++)
        *(int *)(disabled[i] + 0x98) = *(int *)(*(char **)(disabled[i] + 0x24) + 0x10);
    return result;
}

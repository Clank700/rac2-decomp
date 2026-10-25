/* Nonmatching: 1716/1804 bytes.
 * Profile: -O2 -G8 -ffunction-sections.
 * Placement checks: US: 0/1; US2: 0/1; PAL: 0/1.
 * 1716/1804 bytes, frame0x320. All128 disabled-actor pointers and full start/target/trace vectors are retained. AB1F0 keeps its canonical int32 metadata return with explicit pointer casts. Player XY fields are based at the actual player object+0x80/+0x84; query hit/position are fields of the real query result at+0x18/+0x20. Target-local scopes and owner views do not close allocation, branch and query-loop differences.
 * Reopen with independent actor/query cursor and FP-result lifetime evidence. Keep raw metadata contracts and complete query storage; do not specialize a generic accessor to a pointer return.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern float D_L02_001B0610 __attribute__((sda)), D_L02_001B0614 __attribute__((sda));
extern char *D_0018C0B0;
extern int D_L02_001A8FF0;
extern int D_L02_001A8FF4 __attribute__((sda));
extern short D_0018A168;
extern float D_0018A144;
extern char D_00189E20[] NOT_SDA;
extern char *D_L02_001FC420[];
typedef union { Quad quad; float f[4]; } QueryVector;
typedef struct {
    int prefix[6];
    char *hit;
    int mesh;
    QueryVector position, unknown30, normal, edgeStart, edgeEnd, tail;
} CollisionResult;
extern CollisionResult D_L02_001C0940;
extern void func_00282D30(void *, void *, float), func_00282CC0(void *, void *, void *);
extern int func_002761F8(void *, void *, int, void *, int);
extern int func_002AB1F0(u8 *);
extern float func_00283248(float, float), func_00282E80(void *, void *), func_00283C80(float, float), func_00282E48(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *), func_00282C48(float), func_00282DF0(void *), func_002831B0(float), func_00283CE0(int);
extern void func_002AF000(void *, float, float, float);

char *func_L02_003DEDA0(char *actor, float *origin, float *yaw, float *pitch) {
    float start[4] __attribute__((aligned(16))), offset[4] __attribute__((aligned(16)));
    float viewStart[4] __attribute__((aligned(16)));
    char *disabled[128];
    float targetPoint[4] __attribute__((aligned(16))), aimPoint[4] __attribute__((aligned(16)));
    float relative[4] __attribute__((aligned(16))), vertical[4] __attribute__((aligned(16)));
    char *state = *(char **)(actor + 0x68);
    char *selected = 0;
    char *target;
    int disabledCount = 0, index, i;
    float bestDistance = D_L02_001B0614;
    qcopy(start, origin);
    func_00282D30(offset, D_0018C0B0 + 0xE0, 0.5f);
    func_00282CC0(viewStart, D_0018C0B0 + 0x10, offset);
    if (func_002761F8(viewStart, start, 6, D_0018C0B0, 0)) return 0;
    for (index = 0; (target = D_L02_001FC420[index]) != 0; index++) {
        char *settings, *hero;
        float targetYaw, targetPitch, headingDifference, distance, dot, magnitude, angle, radius;
        int close, clear, blocks;
        if (*(unsigned char *)(target + 0x20) == 0xFE || *(unsigned char *)(target + 0x20) == 0xFD ||
            *(short *)(target + 0xAA) == 0xE7D || *(short *)(target + 0xAA) == 0xEB0) continue;
        qcopy(targetPoint, target + 0x10);
        settings = (char *)func_002AB1F0((u8 *)target);
        if (!settings || *(unsigned char *)(settings + 0xE) == 3) continue;
        func_00282D30(aimPoint, target + 0xE0, *(float *)(settings + 0x10));
        func_00282CC0(targetPoint, targetPoint, aimPoint);
        if (!target || !*(char **)(target + 0x24) || *(short *)(*(char **)(target + 0x24) + 0x46) != 5) continue;
        close = 0;
        targetYaw = func_00283248(targetPoint[0] - start[0], targetPoint[1] - start[1]);
        magnitude = func_00282E80(start, targetPoint);
        targetPitch = func_00283248(magnitude, targetPoint[2] - start[2]);
        headingDifference = func_00283C80(*yaw, targetYaw);
        distance = func_00282E48(start, targetPoint);
        hero = D_0018C0B0;
        if (D_L02_001A8FF0 == 0 && D_0018A168 == 0 && D_L02_001A8FF4 == 0) {
            if (distance < 2.5f) {
                angle = func_00283248(*(float *)(target + 0x10) - *(float *)(D_00189E20 + 0x80), *(float *)(target + 0x14) - *(float *)(D_00189E20 + 0x84));
                if (func_00283C80(*(float *)(hero + 0xF8), angle) < 1.0471977f && func_00282C48(start[2] - targetPoint[2]) < 2.0f) close = 1;
            }
        } else if (distance < 2.5f) {
            func_00282CF0(relative, target + 0x10, hero + 0x10);
            dot = func_00282DB0(relative, hero + 0xE0);
            if (func_00282C48(dot) < 2.0f) {
                func_00282D30(vertical, hero + 0xE0, dot);
                func_00282CF0(relative, relative, vertical);
                dot = func_00282DB0(relative, hero + 0xC0);
                magnitude = func_00282DF0(relative);
                if (magnitude != 0.0f && 1.5707964f - func_002831B0(dot / magnitude) < 1.0471977f) close = 1;
            }
        }
        if (close && !func_002761F8(start, targetPoint, 6, D_0018C0B0, 0)) {
            selected = target;
            *pitch = -targetPitch;
            *yaw = targetYaw;
            break;
        }
        if (!((distance <= bestDistance || target == *(char **)(state + 0x10)) && distance <= D_L02_001B0614)) continue;
        func_002AF000(aimPoint, distance, *yaw, *pitch + D_0018A144 * 0.5f);
        func_00282CC0(aimPoint, aimPoint, start);
        angle = func_00282E48(aimPoint, targetPoint);
        angle = func_002831B0(angle / (distance + distance));
        angle += angle;
        if (angle > D_L02_001B0610 * 0.017453294f) {
            settings = (char *)func_002AB1F0((u8 *)target);
            if (settings) {
                radius = func_00283CE0(*(unsigned char *)(settings + 0xA));
                magnitude = func_002831B0((radius * 0.125f) / distance);
                if (radius * 0.125f < distance) {
                    angle -= magnitude;
                    if (angle < 0.0f) angle = 0.0f;
                }
            }
        }
        if (!(angle < D_L02_001B0610 * 0.017453294f)) continue;
        clear = 1;
        qcopy(relative, start);
        blocks = 0;
        for (;;) {
            char *obstacle;
            if (!func_002761F8(relative, targetPoint, 6, actor, 0) || ++blocks > 6) break;
            obstacle = D_L02_001C0940.hit;
            if (!obstacle) { clear = 0; break; }
            if (*(short *)(obstacle + 0xAA) != 0xE7D && *(short *)(obstacle + 0xAA) != 0xEB0) {
                if (obstacle != target) clear = 0;
                break;
            }
            disabled[disabledCount++] = obstacle;
            *(int *)(obstacle + 0x98) = 0;
            if (disabledCount >= 128) break;
            qcopy(relative, &D_L02_001C0940.position);
        }
        if (clear) {
            *pitch = -targetPitch;
            if (headingDifference < 0.17453295f) *yaw = targetYaw;
            selected = target;
            bestDistance = distance;
            if (target == *(char **)(state + 0x10)) return target;
        }
    }
    for (i = 0; i < disabledCount; i++) *(int *)(disabled[i] + 0x98) = *(int *)(*(char **)(disabled[i] + 0x24) + 0x10);
    return selected;
}

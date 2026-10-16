/* Not attempted in this run.
 *
 * src/core/0011D140.c line 395. 492 bytes. symbol_addrs names it: sceSifCallRpc,
 * "sends SIF cmd 0x8000000A with the SDK nine-argument shape (client, rpc
 * number, mode, send and size, receive and size, end function and
 * parameter)".
 *
 * Worth knowing before writing a line: the nine arguments reach the callee
 * as a0-a3, then t0-t3, then one word at 0(sp) - not o32's four-in-registers
 * and five-on-the-stack. A call site that shows it end to end is func_001253A8
 * (sceCdRead) at +0x178: a0 = 0x137550, a1 = 1, a2 = 1, a3 = 0x136480,
 * t0 = 0x18, t1 = 0, t2 = 0, t3 = 0x1246E0, 0(sp) = 0x137480. Declaring the
 * prototype with nine ordinary parameters reproduces that allocation, so the
 * body can be written as plain C.
 *
 * The body itself is ordinary C - no VU0, no MMI, no `sync` in the 492 bytes -
 * but it is a Sony libsif member with no public source on this machine, so it
 * is a from-disassembly job like sceCdRead next door. The two are worth doing
 * together: sceCdRead's call site is what pins this one's convention.
 */

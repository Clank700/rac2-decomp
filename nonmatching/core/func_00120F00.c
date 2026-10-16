/* from src/core/00120F00.c: 480 bytes against retail's 476, one instruction
 * more, and every instruction but the eh_return stub's placement is retail's.
 *
 * libgcc _eh.o: __throw, from the L_eh section of GCC's libgcc2.c (the source
 * the qualified compiler is built from, gnu-ee-binutils-gcc-1.1). Its
 * neighbours in the same object are in src/core/00120390.c: func_00120420 is
 * __get_eh_context and D_00135D38 the static get_eh_context pointer variable
 * this body calls through. frame_state is frame.h's with
 * FIRST_PSEUDO_REGISTER 79 and this ABI's 64-bit long - 0x2F0 bytes, which is
 * the memcpy sizeof (*udata) retail expands at +0xD8, and 0x2F8 with
 * frame_state_internal's trailing pointer, the size func_001240C8 memsets.
 * The `&&label` handed to __frame_state_for lands at +0xA4 (0x00120FA4 in
 * retail) and the stub __builtin_eh_return transfers to is at retail's
 * +0x170 (0x00121070), both reproduced.
 *
 * What blocks it: where cc1 puts the eh_return stub. expand_eh_return
 * (except.c) emits [moves][jump after_stub][stub: adjust_stack, indirect
 * jump][after_stub] at the end of expand_function_end, and retail lays it out
 * exactly there, so its `b` has the `lw $v0,0x5E4($fp)` of the move in its
 * delay slot. Ours emits the same four instructions twelve instructions
 * earlier, between the memcpy's loop and its 16-byte leftover, and the `b`'s
 * slot stays a nop - the one instruction of difference. Everything else,
 * including the 0x2F0-byte block move, the throw_helper argument setup and
 * the epilogue, is byte-identical at its own offset.
 *
 * Tried: the explicit memcpy prototype removed (libgcc2.c has no <string.h>
 * and calls memcpy implicitly) - identical output. The profile is the one the
 * rest of the object uses (sdk -O2 -G2 -ffunction-sections, 16-byte save
 * slots).
 *
 * Verified: tools/check.py func_00120F00 --diff: boot: 480 bytes, expected
 * 476; the only differences are the relocations, the stub block's position
 * and its unfilled delay slot.
 */

/* libgcc _eh.o: __throw, from the L_eh section of GCC's libgcc2.c (GPL
   version 2-or-later with the libgcc linking exception; the source is the
   public archive the qualified compiler is built from,
   gnu-ee-binutils-gcc-1.1, gcc/libgcc2.c). Its neighbours in the same object
   are in src/core/00120390.c: func_00120420 is __get_eh_context and
   D_00135D38 is the static `get_eh_context` pointer variable this body calls
   through.

   `frame_state` is frame.h's, and its size is what retail copies:
   FIRST_PSEUDO_REGISTER is 79 (the archive's own config/mips/mips.h), `long`
   is the 64-bit long of this ABI, and the 0x2F0-byte struct rounds to 0x2F8
   with frame_state_internal's trailing pointer, which is the size
   func_001240C8 memsets. __throw's own memcpy of sizeof (*udata) = 0x2F0 is
   the 32-byte-per-iteration loop with the 16-byte tail at +0xD8, and the
   `&&label` it hands __frame_state_for is the address of its own call site
   (0x00120FA4), as the EPILOGUE label at 0x00121070 is the address
   __builtin_eh_return transfers to. */

#define FIRST_PSEUDO_REGISTER 79

typedef struct frame_state
{
  void *cfa;
  void *eh_ptr;
  long cfa_offset;
  long args_size;
  long reg_or_offset[FIRST_PSEUDO_REGISTER+1];
  unsigned short cfa_reg;
  unsigned short retaddr_column;
  char saved[FIRST_PSEUDO_REGISTER+1];
} frame_state;

struct eh_context
{
  void *handler_label;
  void **dynamic_handler_chain;
  void *info;
  void *table_index;
};

extern struct eh_context *(*D_00135D38)(void);

extern void func_00120368(void);

extern struct frame_state *func_001240C8(void *, struct frame_state *);

extern void *func_00120BD0(struct eh_context *, void *, frame_state *,
			   frame_state **);

/* We first search for an exception handler, and if we don't find it, we call
   __terminate on the current stack frame so that we may use the debugger to
   walk the stack and understand why no handler was found. If we find one,
   then we unwind the frames down to the one that has the handler and transfer
   control into the handler.  */

void func_00120F00(void)
{
  struct eh_context *eh = (*D_00135D38) ();
  void *pc, *handler;
  frame_state ustruct;
  frame_state *udata = &ustruct;
  frame_state my_ustruct, *my_udata = &my_ustruct;

  /* This is required for C++ semantics.  We must call terminate if we
     try and rethrow an exception, when there is no exception currently
     active.  */
  if (! eh->info)
    func_00120368 ();

  /* Start at our stack frame.  */
label:
  udata = func_001240C8 (&&label, udata);
  if (! udata)
    func_00120368 ();

  /* We need to get the value from the CFA register. */
  udata->cfa = __builtin_dwarf_cfa ();

  memcpy (my_udata, udata, sizeof (*udata));

  /* Do any necessary initialization to access arbitrary stack frames.
     On the SPARC, this means flushing the register windows.  */
  __builtin_unwind_init ();

  /* Now reset pc to the right throw point.  */
  pc = __builtin_extract_return_addr (__builtin_return_address (0)) - 1;

  handler = func_00120BD0 (eh, pc, my_udata, &udata);

  /* Now go!  */

  __builtin_eh_return ((void *)eh,
		       udata->cfa - my_udata->cfa,
		       handler);

  /* Epilogue:  restore the handler frame's register values and return
     to the stub.  */
}

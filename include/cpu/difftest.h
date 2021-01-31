#ifndef __CPU_DIFFTEST_H__
#define __CPU_DIFFTEST_H__

#include <common.h>
#include <difftest.h>

#ifdef CONFIG_DIFF_TEST
#define DIFF_TEST
#endif

#ifdef DIFF_TEST
void difftest_skip_ref();
void difftest_skip_dut(int nr_ref, int nr_dut);
void difftest_set_patch(void (*fn)(void *arg), void *arg);
void difftest_step(vaddr_t pc, vaddr_t npc);
void difftest_detach();
void difftest_attach();
#else
#define difftest_skip_ref()
#define difftest_skip_dut(nr_ref, nr_dut)
static inline void difftest_set_patch(void (*fn)(void *arg), void *arg) {}
static inline void difftest_step(vaddr_t pc, vaddr_t npc) {}
#define difftest_detach()
#define difftest_attach()
#endif

extern void (*ref_difftest_memcpy)(paddr_t dest, void *src, size_t n, bool direction);
extern void (*ref_difftest_regcpy)(void *c, bool direction);
extern void (*ref_difftest_exec)(uint64_t n);
extern void (*ref_difftest_raise_intr)(uint64_t NO);

static inline bool difftest_check_reg(const char *name, vaddr_t pc, rtlreg_t ref, rtlreg_t dut) {
  if (ref != dut) {
    Log("%s is different after executing instruction at pc = " FMT_WORD
        ", right = " FMT_WORD ", wrong = " FMT_WORD, name, pc, ref, dut);
    return false;
  }
  return true;
}

#endif

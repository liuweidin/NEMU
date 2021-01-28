#ifndef __CPU_DCCACHE_H__
#define __CPU_DCCACHE_H__

#include <cpu/decode.h>

#define DCACHE_SIZE (1024 * 4)
extern DecodeExecState dccache[];

void dccache_flush();

static inline int dccache_idx(vaddr_t pc) {
  return (pc >> 2) % DCACHE_SIZE;
}

static inline DecodeExecState* dccache_fetch(vaddr_t pc) {
  return &dccache[dccache_idx(pc)];
}

#endif

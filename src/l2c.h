#ifndef L2C_H
#define L2C_H

#include <functional>
#include <list>
#include <string>
#include <vector>

#include "cache.h"
#include "champsim.h"
#include "delay_queue.hpp"
#include "memory_class.h"
#include "ooo_cpu.h"
#include "operable.h"

// virtual address space prefetching
#define VA_PREFETCH_TRANSLATION_LATENCY 2

extern std::array<O3_CPU *, NUM_CPUS> ooo_cpu;

class L2C : public CACHE {
public:
  vector<MemoryRequestConsumer *> all_lower_levels;

  uint32_t get_slice(uint64_t address);

  // constructor
  L2C(std::string v1, double freq_scale, unsigned fill_level, uint32_t v2,
      int v3, uint32_t v5, uint32_t v6, uint32_t v7, uint32_t v8,
      uint32_t hit_lat, uint32_t fill_lat, uint32_t max_read,
      uint32_t max_write, std::size_t offset_bits, bool pref_load,
      bool wq_full_addr, bool va_pref, unsigned pref_act_mask,
      MemoryRequestConsumer *ll, vector<MemoryRequestConsumer *> lls,
      pref_t pref, repl_t repl)
      : CACHE(v1, freq_scale, fill_level, v2, v3, v5, v6, v7, v8, hit_lat,
              fill_lat, max_read, max_write, offset_bits, pref_load,
              wq_full_addr, va_pref, pref_act_mask, ll, pref, repl)
         {
           assert(lls.size() == NUM_CPUS);
           all_lower_levels = std::move(lls);
         }
};

#endif

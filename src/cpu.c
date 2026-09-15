#include "cpu.h"
#include "registers.h"

Registers cpu = {0};

/* placeholder flat address space; a real MMU (ROM banks, VRAM, I/O, etc.)
   will replace this */
static uint8_t memory[0x10000];

static uint8_t mem_read8(uint16_t addr) {
    return memory[addr];
}

static void mem_write8(uint16_t addr, uint8_t val) {
    memory[addr] = val;
}

static uint16_t mem_read16(uint16_t addr) {
    return mem_read8(addr) | (mem_read8(addr + 1) << 8);
}

void nop(void) {
}

void ld_bc_nn(void) {
    cpu.bc = mem_read16(cpu.pc);
    cpu.pc += 2;
}

void ld_bcp_a(void) {
    uint8_t a = (cpu.af & A_MASK) >> 8;
    mem_write8(cpu.bc, a);
}

void inc_bc(void) {
    cpu.bc++;
}

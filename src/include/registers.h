#include <stdint.h>

/**
 * Registers are technically 8 bit values. However, most registers can be
 * accessed either as one 16-bit register or as two separate 8-bit registers.
 * These masks allow us to access individual registers, if needed.
 */
#define A_MASK 0xFF00
#define FLAGS_MASK 0x00FF
#define B_MASK 0xFF00
#define C_MASK 0x00FF
#define D_MASK 0xFF00
#define E_MASK 0x00FF
#define H_MASK 0xFF00
#define L_MASK 0x00FF

/* Masks to determine which flags are set in the flags register. */
#define ZERO_FLAG 0x80
#define SUBTRACTION_FLAG 0x40
#define HALF_CARRY_FLAG 0x20
#define CARRY_FLAG 0x10

typedef struct registers {
    uint16_t af; /* accumulator and flags */
    uint16_t bc; /* BC */
    uint16_t de; /* DE */
    uint16_t hl; /* HL */
    uint16_t sp; /* stack pointer */
    uint16_t pc; /* program counter/pointer */
} Registers;

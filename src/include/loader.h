#ifndef _LOADER_H
#define _LOADER_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define MIN_ROM_SIZE 0x014F

/**
 * read_rom
 * Reads a ROM file into memory.
 *
 * Parameters:
 * path: a string specifying what file to load
 * size: an input parameter that will store the size of the ROM.
 *       NOTE: this needs to be malloc'd before being passed to this function
 *       or you will segfault!!
 *
 * Output:
 * a pointer to the beginning of the ROM in memory
 */
uint8_t* read_rom(const char* path, uint32_t* size);

#endif /* _LOADER_H */
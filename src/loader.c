#include "loader.h"

uint8_t* read_rom(const char* path, uint32_t* size) {

    /* check that path was actually passed */
    if (!path) return NULL;

    /* variable declarations */
    long file_size;
    uint8_t* buffer = NULL;
    size_t read_size;
    FILE* rom;

    /* open the ROM file */
    if (rom = fopen(path, "rb")) {

        /* navigate to the end of the file to determine its size */
        fseek(rom, 0, SEEK_END);
        file_size = ftell(rom);

        /* check that the file meets minimum size requirement */
        if (file_size <= MIN_ROM_SIZE) {
            fprintf(stderr, "File too small\n");
            fclose(rom);
            return NULL;
        }

        /* go back to the beginning of the file */
        rewind(rom);

        /* create buffer to load ROM */
        buffer = (char*) malloc(sizeof(uint8_t) * file_size);
        if (!buffer) {
            fprintf(stderr, "Unable to create buffer to load ROM to memory\n");
            fclose(rom);
            return NULL;
        }

        /* load the ROM into memory */
        read_size = fread(buffer, 1, file_size, rom);
        if (read_size != file_size) {
            fprintf(stderr, "Unable to load ROM to memory\n");
            free(buffer);
            fclose(rom);
            return NULL;
        }

        /* store the read size in the size output parameter */
        if (size) *size = (uint32_t) read_size;

        /* finally close the file itself. */
        fclose(rom);
    }

    return buffer;
}
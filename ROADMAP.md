# MPGameBoy Roadmap

Goal: boot a real Game Boy game. Ordered so each phase can be tested before
moving to the next — no point building the PPU on top of a CPU that hasn't
been proven correct.

## Phase 1: Build system — done
- [x] Makefile compiles all `.c` files with `gcc -std=c11 -Wall`
- [x] Fixed missing `stdlib.h`/`stdio.h` includes surfaced by actually
      compiling every file

## Phase 2: MMU (memory management unit)
`cpu.c` currently has a placeholder flat `uint8_t memory[0x10000]` array.
Replace it with real address-space mapping:
- [ ] `mem_read8`/`mem_write8`/`mem_read16`/`mem_write16` that route by
      address range instead of indexing one flat array
- [ ] ROM area (0x0000-0x7FFF) backed by the buffer from `read_rom`
- [ ] VRAM (0x8000-0x9FFF), WRAM (0xC000-0xDFFF), OAM (0xFE00-0xFE9F)
- [ ] I/O registers region (0xFF00-0xFF7F) — stubbed for now, filled in as
      each subsystem (timer, PPU, joypad) is built
- [ ] HRAM (0xFF80-0xFFFE) and the IE register (0xFFFF)
- [ ] Echo RAM (0xE000-0xFDFF) mirrors WRAM

## Phase 3: CPU core
- [x] Fetch-decode-execute loop (`cpu_step`)
- [x] Register/flag accessor helpers
- [x] 16-bit register family: `LD rr,nn` / `INC rr` / `DEC rr` /
      `ADD HL,rr`, plus HL's `LDI`/`LDD` variants
- [ ] 8-bit `INC r`/`DEC r` and rotates (`RLCA`/`RRCA`/`RLA`/`RRA`) — next up,
      first instructions needing real half-carry logic
- [ ] 8-bit `LD r,r'` family (register-to-register, plus `(HL)` variants) —
      largest single group, but all mechanically identical
- [ ] 8-bit immediate loads (`LD r,n`)
- [ ] 8-bit arithmetic/logic: `ADD`/`ADC`/`SUB`/`SBC`/`AND`/`XOR`/`OR`/`CP`
- [ ] `ADD SP,n` and `LD HL,SP+n` (signed 8-bit operand, its own flag quirks)
- [ ] Relative jumps (`JR`, `JR cc,n`)
- [ ] Absolute jumps/calls/returns (`JP`, `CALL`, `RET`, `RST`, conditional
      forms) — needs the stack
- [ ] Stack ops (`PUSH`/`POP`)
- [ ] Misc single-byte ops: `DAA`, `CPL`, `SCF`, `CCF`, `STOP`, `HALT`,
      `DI`, `EI`
- [ ] CB-prefixed table (`0xCB` currently maps to `undefined`) — 256 more
      opcodes: `RLC`/`RRC`/`RL`/`RR`/`SLA`/`SRA`/`SWAP`/`SRL`/`BIT`/`RES`/`SET`
- [ ] Per-instruction cycle counts — needed once the PPU/timer have to stay
      in sync with the CPU; easiest to add alongside each instruction now
      rather than retrofit later

## Phase 4: Validate CPU correctness
Do this before writing a single line of graphics code — a garbled screen is
a much harder place to debug a flag bug than a test ROM's own report.
- [ ] Wire `read_rom`'s output into the Phase 2 MMU's ROM region
- [ ] Get Blargg's `cpu_instrs` test ROMs running (search for the repo name
      rather than trusting a pasted link — didn't want to guess one here)
- [ ] Fix whatever they find (there will be bugs, especially in flag logic)

## Phase 5: Interrupts & timers
- [ ] `IME` flag, `IE`/`IF` registers, the interrupt dispatch sequence
- [ ] `DIV`/`TIMA`/`TMA`/`TAC` timer registers

## Phase 6: PPU (graphics)
- [ ] LCD control/status registers (`LCDC`, `STAT`, `LY`, `LYC`, etc.)
- [ ] Background rendering
- [ ] Window rendering
- [ ] Sprite (OAM) rendering
- [ ] Replace `main.c`'s placeholder SDL window with an actual 160x144
      framebuffer (scaled up)

## Phase 7: Round it out
- [ ] Joypad input via SDL events
- [ ] MBC1/MBC3 cartridge banking (needed for anything bigger than a
      32KB no-MBC ROM)
- [ ] APU (sound) — least critical for "does it boot"

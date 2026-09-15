#ifndef _CPU_H
#define _CPU_H

#include <stdint.h>

#define NUM_INSTRUCTIONS 256

/* function declarations for CPU operations */
void undefined(void);        /* for opcodes that have no function */
void nop(void);              /* no operation */
void ld_bc_nn(void);         /* load nn into BC */
void ld_bcp_a(void);         /* save A to address pointed by BC */
void inc_bc(void);           /* increment BC */
void inc_b(void);            /* increment B */
void dec_b(void);            /* decrement B */
void ld_b_n(void);           /* load n into B */
void rlca(void);             /* rotate A left w/ carry */
void ld_nnp_sp(void);        /* save SP to given address */
void add_hl_bc(void);        /* add 16-bit BC to HL */
void ld_a_bcp(void);         /* load A from address pointed by BC */
void dec_bc(void);           /* decrement BC */
void inc_c(void);            /* increment C */
void dec_c(void);            /* decrement C */
void ld_c_n(void);           /* load n into C */
void rrca(void);             /* rotate A right w/ carry */
void stop(void);             /* stop processor */
void ld_de_nn(void);         /* load nn into DE */
void ld_dep_a(void);         /* save A to address pointed by DE*/
void inc_de(void);           /* increment DE */
void inc_d(void);            /* increment D */
void dec_d(void);            /* decrement D */
void ld_d_n(void);           /* load n into D */
void rla(void);              /* rotate A left */
void jr_n(void);             /* relative jump by signed immediate */
void add_hl_de(void);        /* add 16-bit DE to HL */
void ld_a_dep(void);         /* load A from address pointed to by DE */
void dec_de(void);           /* decrement DE */
void inc_e(void);            /* increment E */
void dec_e(void);            /* decrement E */
void ld_e_n(void);           /* load n into E */
void rra(void);              /* rotate A right */
void jr_nz_n(void);          /* relative jump by signed immediate if last res not zero */
void ld_hl_nn(void);         /* load nn into HL */
void ldi_hlp_a(void);        /* save A to address pointed by HL and increment HL */
void inc_hl(void);           /* increment HL */
void inc_h(void);            /* increment H */
void dec_h(void);            /* decrement H */
void ld_h_n(void);           /* load n into H */
void daa(void);              /* adjust A for BCD addition */
void jr_z_n(void);           /* relative jump by signed immediate if last res was zero */
void add_hl_hl(void);        /* add 16-bit HL to HL */
void ldi_a_hlp(void);        /* load A from address pointed by HL and increment HL */
void dec_hl(void);           /* decrement HL */
void inc_l(void);            /* increment L */
void dec_l(void);            /* decrement L */
void ld_l_n(void);           /* load n into L */
void cpl(void);              /* complement (logical not) on A */
void jr_nc_n(void);          /* relative jump by signed immediate if last res no carry */
void ld_sp_nn(void);         /* load nn into SP */
void ldd_hlp_a(void);        /* save A to address pointed by HL and decrement HL */
void inc_sp(void);           /* increment SP */
void inc_hlp(void);          /* increment value pointed to by HL */
void dec_hlp(void);          /* decrement value pointed to by HL */
void ld_hlp_n(void);         /* load n into address pointed by HL */
void scf(void);              /* set carry flag */
void jr_c_n(void);           /* relative jump by signed immediate if last res caused carry*/
void add_hl_sp(void);        /* add 16-bit SP to HL */
void ldd_a_hlp(void);        /* load A from address pointed by HL and decrement HL */
void dec_sp(void);           /* decrement SP */
void inc_a(void);            /* increment A */
void dec_a(void);            /* decrement A */
void ld_a_n(void);           /* load n into A */
void ccf(void);              /* clear carry flag */
void ld_b_c(void);           /* copy C to B */
void ld_b_d(void);           /* copy D to B */
void ld_b_e(void);           /* copy E to B */
void ld_b_h(void);           /* copy H to B */
void ld_b_l(void);           /* copy L to B */
void ld_b_hlp(void);         /* copy value pointed by HL to B */
void ld_b_a(void);           /* copy A to B */
void ld_c_b(void);           /* copy B to C */
void ld_c_d(void);           /* copy D to C */
void ld_c_e(void);           /* copy E to C */
void ld_c_h(void);           /* copy H to C */
void ld_c_l(void);           /* copy L to C */
void ld_c_hlp(void);         /* copy value pointed by HL to C */
void ld_c_a(void);           /* copy A to C */
void ld_d_b(void);           /* copy B to D */
void ld_d_c(void);           /* copy C to D */
void ld_d_e(void);           /* copy E to D */
void ld_d_h(void);           /* copy H to D */
void ld_d_l(void);           /* copy L to D */
void ld_d_hlp(void);         /* copy value pointed by HL to D */
void ld_d_a(void);           /* copy A to D */
void ld_e_b(void);           /* copy B to E */
void ld_e_c(void);           /* copy C to E */
void ld_e_d(void);           /* copy D to E */
void ld_e_h(void);           /* copy H to E */
void ld_e_l(void);           /* copy L to E */
void ld_e_hlp(void);         /* copy value pointed by HL to E */
void ld_e_a(void);           /* copy A to E */
void ld_h_b(void);           /* copy B to H */
void ld_h_c(void);           /* copy C to H */
void ld_h_d(void);           /* copy D to H */
void ld_h_e(void);           /* copy E to H */
void ld_h_l(void);           /* copy L to H */
void ld_h_hlp(void);         /* copy value pointed by HL to H */
void ld_h_a(void);           /* copy A to H */
void ld_l_b(void);           /* copy B to L */
void ld_l_c(void);           /* copy C to L */
void ld_l_d(void);           /* copy D to L */
void ld_l_e(void);           /* copy E to L */
void ld_l_h(void);           /* copy H to L */
void ld_l_hlp(void);         /* copy value pointed by HL to L */
void ld_l_a(void);           /* copy A to L */
void ld_hlp_b(void);         /* copy B to address pointed by HL */
void ld_hlp_c(void);         /* copy C to address pointed by HL */
void ld_hlp_d(void);         /* copy D to address pointed by HL */
void ld_hlp_e(void);         /* copy E to address pointed by HL */
void ld_hlp_h(void);         /* copy H to address pointed by HL */
void ld_hlp_l(void);         /* copy L to address pointed by HL */
void halt(void);             /* halt processor */
void ld_hlp_a(void);         /* copy A to address pointed by HL */
void ld_a_b(void);           /* copy B to A */
void ld_a_c(void);           /* copy C to A */
void ld_a_d(void);           /* copy D to A */
void ld_a_e(void);           /* copy E to A */
void ld_a_h(void);           /* copy H to A */
void ld_a_l(void);           /* copy L to A */
void ld_a_hlp(void);         /* copy value pointed by HL to A */
void add_a_b(void);          /* add B to A */
void add_a_c(void);          /* add C to A */
void add_a_d(void);          /* add D to A */
void add_a_e(void);          /* add E to A */
void add_a_h(void);          /* add H to A */
void add_a_l(void);          /* add L to A */
void add_a_hlp(void);        /* add value pointed by HL to A */
void add_a_a(void);          /* add A to itself */
void adc_b(void);            /* add B and carry flag to A */
void adc_c(void);            /* add C and carry flag to A */
void adc_d(void);            /* add D and carry flag to A */
void adc_e(void);            /* add E and carry flag to A */
void adc_h(void);            /* add H and carry flag to A */
void adc_l(void);            /* add L and carry flag to A */
void adc_hlp(void);          /* add value pointed by HL and carry flag to A */
void adc_a(void);            /* add A and carry flag to A */
void sub_b(void);            /* subtract B from A */
void sub_c(void);            /* subtract C from A */
void sub_d(void);            /* subtract D from A */
void sub_e(void);            /* subtract E from A */
void sub_h(void);            /* subtract H from A */
void sub_l(void);            /* subtract L from A */
void sub_hlp(void);          /* subtract value pointed by HL from A */
void sub_a(void);            /* subtract A from A */
void sbc_b(void);            /* subtract B and carry flag from A */
void sbc_c(void);            /* subtract C and carry flag from A */
void sbc_d(void);            /* subtract D and carry flag from A */
void sbc_e(void);            /* subtract E and carry flag from A */
void sbc_h(void);            /* subtract H and carry flag from A */
void sbc_l(void);            /* subtract L and carry flag from A */
void sbc_hlp(void);          /* subtract value pointed by HL and carry flag from A */
void sbc_a(void);            /* subtract A and carry flag from A */
void and_b(void);            /* logical AND B against A */
void and_c(void);            /* logical AND C against A */
void and_d(void);            /* logical AND D against A */
void and_e(void);            /* logical AND E against A */
void and_h(void);            /* logical AND H against A */
void and_l(void);            /* logical AND L against A */
void and_hlp(void);          /* logical AND value pointed by HL against A */
void and_a(void);            /* logical AND A against A */
void xor_b(void);            /* logical XOR B against A */
void xor_c(void);            /* logical XOR C against A */
void xor_d(void);            /* logical XOR D against A */
void xor_e(void);            /* logical XOR E against A */
void xor_h(void);            /* logical XOR H against A */
void xor_l(void);            /* logical XOR L against A */
void xor_hlp(void);          /* logical XOR value pointed by HL against A */
void xor_a(void);            /* logical XOR A against A */
void or_b(void);             /* logical OR B against A */
void or_c(void);             /* logical OR C against A */
void or_d(void);             /* logical OR D against A */
void or_e(void);             /* logical OR E against A */
void or_h(void);             /* logical OR H against A */
void or_l(void);             /* logical OR L against A */
void or_hlp(void);           /* logical OR value pointed by HL against A */
void or_a(void);             /* logical OR A against A */
void cp_b(void);             /* compare B against A */
void cp_c(void);             /* compare C against A */
void cp_d(void);             /* compare D against A */
void cp_e(void);             /* compare E against A */
void cp_h(void);             /* compare H against A */
void cp_l(void);             /* compare L against A */
void cp_hlp(void);           /* compare value pointed by HL against A */
void cp_a(void);             /* compare A against A */
void ret_nz(void);           /* return if last result was NOT zero */
void pop_bc(void);           /* pop 16-bit value from stack into BC */
void jp_nz_nn(void);         /* absolute jump to 16-bit location if last res not zero */
void jp_nn(void);            /* absolute jump to 16-bit location */
void call_nz_nn(void);       /* call routine at 16-bit location if last res not zero */
void push_bc(void);          /* push 16-bit BC onto stack */
void add_a_n(void);          /* add n to A */
void rst_0(void);            /* call routine at address 0x0000 */
void ret_z(void);            /* return if last res was zero */
void ret(void);              /* return to calling routine */
void jp_z_nn(void);          /* absolute jump to 16-bit location if last res was zero */
void call_z_nn(void);        /* call routine at 16-bit location if last res was zero */
void call_nn(void);          /* call routine at 16-bit location */
void adc_n(void);            /* add n and carry to A */
void rst_08(void);           /* call routine at address 0x0008 */
void ret_nc(void);           /* return if last res caused no carry */
void pop_de(void);           /* pop 16-bit value from stack into DE */
void jp_nc_nn(void);         /* absolute jump to 16-bit location if last res no carry */
void call_nc_nn(void);       /* call routine at 16-bit location if last res no carry */
void push_de(void);          /* push 16-bit DE onto stack */
void sub_n(void);            /* subtract n from A */
void rst_10(void);           /* call routine at address 0x0010 */
void ret_c(void);            /* return if last res caused carry */
void jp_c_nn(void);          /* absolute jump to 16-bit location if last res caused carry */
void call_c_nn(void);        /* call routine at 16-bit location if last res caused carry */
void sbc_n(void);            /* subtract n and carry from A */
void rst_18(void);           /* call routine at address 0x0018*/
void ld_ff_n_ap(void);       /* save A at address pointed to by (0xFF00 + n) */
void pop_hl(void);           /* pop 16-bit value from stack into HL */
void ld_ff_c_a(void);        /* save A at address pointed to by (0xFF00 + C) */
void push_hl(void);          /* push 16-bit HL onto stack */
void and_n(void);            /* logical AND n against A */
void rst_20(void);           /* call routine at address 0x0020 */
void add_sp_n(void);         /* add signed n to SP */
void jp_hl(void);            /* jump to 16-bit value pointed to by HL */
void ld_nnp_a(void);         /* save A at address pointed to by nn */
void xor_n(void);            /* logical XOR n against A */
void rst_28(void);           /* call routine at address 0x0028 */
void ld_ff_ap_n(void);       /* load A from address pointed to by (0xFF00 + n) */
void pop_af(void);           /* pop 16-bit value from stack into AF */
void ld_a_ff_c(void);        /* load A from address pointed to by (0xFF00 + C) */
void di_inst(void);          /* disable interrupts */
void push_af(void);          /* push 16-bit AF onto stack */
void or_n(void);             /* logical OR n against A */
void rst_30(void);           /* call routine at address 0x0030 */
void ld_hl_sp_n(void);       /* add n to SP and save result in HL */
void ld_sp_hl(void);         /* copy HL to SP */
void ld_a_nnp(void);         /* load A from address nn */
void ei(void);               /* enable interrupts */
void cp_n(void);             /* compare n against A */
void rst_38(void);           /* call routine at address 0x0038 */

struct instruction {
    char* disassembly;     /* useful string for debugging */
    uint8_t operandLen;    /* whether instruction is 8-bit or 16-bit */
    void (*execute)(void); /* pointer to the actual function of the instruction */
};

extern const struct instruction instructions[NUM_INSTRUCTIONS]; /* all base OP codes */

void cpu_step(void); /* fetch, decode, and execute the instruction at PC */

#endif /* _CPU_H */

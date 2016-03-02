//
// Created by gaudima on 21.01.2016.
//

#include "ops.h"
#include "mmu.h"

Emu* Emu::Cpu::Ops::emu;

void Emu::Cpu::Ops::setF(FlagType flag, bool set) {
    if(set) {
        emu->cpu->r.f |= flag;
    } else {
        emu->cpu->r.f &= ~(flag);
    }
}

bool Emu::Cpu::Ops::isSetF(FlagType flag) {
    return (emu->cpu->r.f & flag);
}

void Emu::Cpu::Ops::resetF() {
    emu->cpu->r.f = 0x00;
}

void Emu::Cpu::Ops::LDrr(uint8_t &a, uint8_t b) {
    a = b;
}
void Emu::Cpu::Ops::LDrr_bb(uint16_t arg) { LDrr(emu->cpu->r.b, emu->cpu->r.b); }
void Emu::Cpu::Ops::LDrr_bc(uint16_t arg) { LDrr(emu->cpu->r.b, emu->cpu->r.c); }
void Emu::Cpu::Ops::LDrr_bd(uint16_t arg) { LDrr(emu->cpu->r.b, emu->cpu->r.d); }
void Emu::Cpu::Ops::LDrr_be(uint16_t arg) { LDrr(emu->cpu->r.b, emu->cpu->r.e); }
void Emu::Cpu::Ops::LDrr_bh(uint16_t arg) { LDrr(emu->cpu->r.b, emu->cpu->r.h); }
void Emu::Cpu::Ops::LDrr_bl(uint16_t arg) { LDrr(emu->cpu->r.b, emu->cpu->r.l); }
void Emu::Cpu::Ops::LDrr_ba(uint16_t arg) { LDrr(emu->cpu->r.b, emu->cpu->r.a); }
void Emu::Cpu::Ops::LDrr_cb(uint16_t arg) { LDrr(emu->cpu->r.c, emu->cpu->r.b); }
void Emu::Cpu::Ops::LDrr_cc(uint16_t arg) { LDrr(emu->cpu->r.c, emu->cpu->r.c); }
void Emu::Cpu::Ops::LDrr_cd(uint16_t arg) { LDrr(emu->cpu->r.c, emu->cpu->r.d); }
void Emu::Cpu::Ops::LDrr_ce(uint16_t arg) { LDrr(emu->cpu->r.c, emu->cpu->r.e); }
void Emu::Cpu::Ops::LDrr_ch(uint16_t arg) { LDrr(emu->cpu->r.c, emu->cpu->r.h); }
void Emu::Cpu::Ops::LDrr_cl(uint16_t arg) { LDrr(emu->cpu->r.c, emu->cpu->r.l); }
void Emu::Cpu::Ops::LDrr_ca(uint16_t arg) { LDrr(emu->cpu->r.c, emu->cpu->r.a); }
void Emu::Cpu::Ops::LDrr_db(uint16_t arg) { LDrr(emu->cpu->r.d, emu->cpu->r.b); }
void Emu::Cpu::Ops::LDrr_dc(uint16_t arg) { LDrr(emu->cpu->r.d, emu->cpu->r.c); }
void Emu::Cpu::Ops::LDrr_dd(uint16_t arg) { LDrr(emu->cpu->r.d, emu->cpu->r.d); }
void Emu::Cpu::Ops::LDrr_de(uint16_t arg) { LDrr(emu->cpu->r.d, emu->cpu->r.e); }
void Emu::Cpu::Ops::LDrr_dh(uint16_t arg) { LDrr(emu->cpu->r.d, emu->cpu->r.h); }
void Emu::Cpu::Ops::LDrr_dl(uint16_t arg) { LDrr(emu->cpu->r.d, emu->cpu->r.l); }
void Emu::Cpu::Ops::LDrr_da(uint16_t arg) { LDrr(emu->cpu->r.d, emu->cpu->r.a); }
void Emu::Cpu::Ops::LDrr_eb(uint16_t arg) { LDrr(emu->cpu->r.e, emu->cpu->r.b); }
void Emu::Cpu::Ops::LDrr_ec(uint16_t arg) { LDrr(emu->cpu->r.e, emu->cpu->r.c); }
void Emu::Cpu::Ops::LDrr_ed(uint16_t arg) { LDrr(emu->cpu->r.e, emu->cpu->r.d); }
void Emu::Cpu::Ops::LDrr_ee(uint16_t arg) { LDrr(emu->cpu->r.e, emu->cpu->r.e); }
void Emu::Cpu::Ops::LDrr_eh(uint16_t arg) { LDrr(emu->cpu->r.e, emu->cpu->r.h); }
void Emu::Cpu::Ops::LDrr_el(uint16_t arg) { LDrr(emu->cpu->r.e, emu->cpu->r.l); }
void Emu::Cpu::Ops::LDrr_ea(uint16_t arg) { LDrr(emu->cpu->r.e, emu->cpu->r.a); }
void Emu::Cpu::Ops::LDrr_hb(uint16_t arg) { LDrr(emu->cpu->r.h, emu->cpu->r.b); }
void Emu::Cpu::Ops::LDrr_hc(uint16_t arg) { LDrr(emu->cpu->r.h, emu->cpu->r.c); }
void Emu::Cpu::Ops::LDrr_hd(uint16_t arg) { LDrr(emu->cpu->r.h, emu->cpu->r.d); }
void Emu::Cpu::Ops::LDrr_he(uint16_t arg) { LDrr(emu->cpu->r.h, emu->cpu->r.e); }
void Emu::Cpu::Ops::LDrr_hh(uint16_t arg) { LDrr(emu->cpu->r.h, emu->cpu->r.h); }
void Emu::Cpu::Ops::LDrr_hl(uint16_t arg) { LDrr(emu->cpu->r.h, emu->cpu->r.l); }
void Emu::Cpu::Ops::LDrr_ha(uint16_t arg) { LDrr(emu->cpu->r.h, emu->cpu->r.a); }
void Emu::Cpu::Ops::LDrr_lb(uint16_t arg) { LDrr(emu->cpu->r.l, emu->cpu->r.b); }
void Emu::Cpu::Ops::LDrr_lc(uint16_t arg) { LDrr(emu->cpu->r.l, emu->cpu->r.c); }
void Emu::Cpu::Ops::LDrr_ld(uint16_t arg) { LDrr(emu->cpu->r.l, emu->cpu->r.d); }
void Emu::Cpu::Ops::LDrr_le(uint16_t arg) { LDrr(emu->cpu->r.l, emu->cpu->r.e); }
void Emu::Cpu::Ops::LDrr_lh(uint16_t arg) { LDrr(emu->cpu->r.l, emu->cpu->r.h); }
void Emu::Cpu::Ops::LDrr_ll(uint16_t arg) { LDrr(emu->cpu->r.l, emu->cpu->r.l); }
void Emu::Cpu::Ops::LDrr_la(uint16_t arg) { LDrr(emu->cpu->r.l, emu->cpu->r.a); }
void Emu::Cpu::Ops::LDrr_ab(uint16_t arg) { LDrr(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::LDrr_ac(uint16_t arg) { LDrr(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::LDrr_ad(uint16_t arg) { LDrr(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::LDrr_ae(uint16_t arg) { LDrr(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::LDrr_ah(uint16_t arg) { LDrr(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::LDrr_al(uint16_t arg) { LDrr(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::LDrr_aa(uint16_t arg) { LDrr(emu->cpu->r.a, emu->cpu->r.a); }

void Emu::Cpu::Ops::LDrHLm(uint8_t &a) {
    a = emu->mmu->rb(emu->cpu->r.hl);
}
void Emu::Cpu::Ops::LDrHLm_b(uint16_t arg) { LDrHLm(emu->cpu->r.b); }
void Emu::Cpu::Ops::LDrHLm_c(uint16_t arg) { LDrHLm(emu->cpu->r.c); }
void Emu::Cpu::Ops::LDrHLm_d(uint16_t arg) { LDrHLm(emu->cpu->r.d); }
void Emu::Cpu::Ops::LDrHLm_e(uint16_t arg) { LDrHLm(emu->cpu->r.e); }
void Emu::Cpu::Ops::LDrHLm_h(uint16_t arg) { LDrHLm(emu->cpu->r.h); }
void Emu::Cpu::Ops::LDrHLm_l(uint16_t arg) { LDrHLm(emu->cpu->r.l); }
void Emu::Cpu::Ops::LDrHLm_a(uint16_t arg) { LDrHLm(emu->cpu->r.a); }

void Emu::Cpu::Ops::LDHLmr(uint8_t a) {
    emu->mmu->wb(emu->cpu->r.hl, a);
}
void Emu::Cpu::Ops::LDHLmr_b(uint16_t arg) { LDHLmr(emu->cpu->r.b); }
void Emu::Cpu::Ops::LDHLmr_c(uint16_t arg) { LDHLmr(emu->cpu->r.c); }
void Emu::Cpu::Ops::LDHLmr_d(uint16_t arg) { LDHLmr(emu->cpu->r.d); }
void Emu::Cpu::Ops::LDHLmr_e(uint16_t arg) { LDHLmr(emu->cpu->r.e); }
void Emu::Cpu::Ops::LDHLmr_h(uint16_t arg) { LDHLmr(emu->cpu->r.h); }
void Emu::Cpu::Ops::LDHLmr_l(uint16_t arg) { LDHLmr(emu->cpu->r.l); }
void Emu::Cpu::Ops::LDHLmr_a(uint16_t arg) { LDHLmr(emu->cpu->r.a); }

void Emu::Cpu::Ops::LDrn(uint8_t &a, uint8_t arg) {
    a = arg;
}
void Emu::Cpu::Ops::LDrn_b(uint16_t arg) { LDrn(emu->cpu->r.b, arg); }
void Emu::Cpu::Ops::LDrn_c(uint16_t arg) { LDrn(emu->cpu->r.c, arg); }
void Emu::Cpu::Ops::LDrn_d(uint16_t arg) { LDrn(emu->cpu->r.d, arg); }
void Emu::Cpu::Ops::LDrn_e(uint16_t arg) { LDrn(emu->cpu->r.e, arg); }
void Emu::Cpu::Ops::LDrn_h(uint16_t arg) { LDrn(emu->cpu->r.h, arg); }
void Emu::Cpu::Ops::LDrn_l(uint16_t arg) { LDrn(emu->cpu->r.l, arg); }
void Emu::Cpu::Ops::LDrn_a(uint16_t arg) { LDrn(emu->cpu->r.a, arg); }

void Emu::Cpu::Ops::LDHLmn(uint16_t arg) { emu->mmu->wb(emu->cpu->r.hl, arg);}

void Emu::Cpu::Ops::LDBCmA(uint16_t arg) { emu->mmu->wb(emu->cpu->r.bc, emu->cpu->r.a); }
void Emu::Cpu::Ops::LDDEmA(uint16_t arg) { emu->mmu->wb(emu->cpu->r.de, emu->cpu->r.a); }

void Emu::Cpu::Ops::LDmmA(uint16_t arg) { emu->mmu->wb(arg, emu->cpu->r.a); }

void Emu::Cpu::Ops::LDABCm(uint16_t arg) { emu->cpu->r.a=emu->mmu->rb(emu->cpu->r.bc); }
void Emu::Cpu::Ops::LDADEm(uint16_t arg) { emu->cpu->r.a=emu->mmu->rb(emu->cpu->r.de); }


void Emu::Cpu::Ops::LDAmm(uint16_t arg) { emu->cpu->r.a=emu->mmu->rb(arg); }

void Emu::Cpu::Ops::LDnn(uint16_t &a, uint16_t arg) {
    a = arg;
}
void Emu::Cpu::Ops::LDBCnn(uint16_t arg) { LDnn(emu->cpu->r.bc, arg); }
void Emu::Cpu::Ops::LDDEnn(uint16_t arg) { LDnn(emu->cpu->r.de, arg); }
void Emu::Cpu::Ops::LDHLnn(uint16_t arg) { LDnn(emu->cpu->r.hl, arg); }
void Emu::Cpu::Ops::LDSPnn(uint16_t arg) { LDnn(emu->cpu->r.sp, arg); }

void Emu::Cpu::Ops::LDHLmm(uint16_t arg) {  LDnn(emu->cpu->r.hl, arg); }
void Emu::Cpu::Ops::LDmmHL(uint16_t arg) { emu->mmu->ww(arg, emu->cpu->r.hl); }
void Emu::Cpu::Ops::LDmmSP(uint16_t arg) { emu->mmu->ww(arg, emu->cpu->r.sp); }
void Emu::Cpu::Ops::LDSPHL(uint16_t arg) { LDnn(emu->cpu->r.sp, emu->cpu->r.hl); }

void Emu::Cpu::Ops::LDHLIA(uint16_t arg) { LDHLmr(emu->cpu->r.a); emu->cpu->r.hl++; }
void Emu::Cpu::Ops::LDAHLI(uint16_t arg) { LDrHLm(emu->cpu->r.a); emu->cpu->r.hl++; }

void Emu::Cpu::Ops::LDHLDA(uint16_t arg) { LDHLmr(emu->cpu->r.a); emu->cpu->r.hl--; }
void Emu::Cpu::Ops::LDAHLD(uint16_t arg) { LDrHLm(emu->cpu->r.a); emu->cpu->r.hl--; }

void Emu::Cpu::Ops::LDAIOn(uint16_t arg) { uint8_t arg2 = arg; emu->cpu->r.a = emu->mmu->rb(0xFF00 + arg2); }
void Emu::Cpu::Ops::LDIOnA(uint16_t arg) { uint8_t arg2 = arg; emu->mmu->wb(0xFF00 + arg2, emu->cpu->r.a); }
void Emu::Cpu::Ops::LDAIOC(uint16_t arg) { emu->cpu->r.a = emu->mmu->rb(0xFF00+emu->cpu->r.c); }
void Emu::Cpu::Ops::LDIOCA(uint16_t arg) { emu->mmu->wb(0xFF00 + emu->cpu->r.c,emu->cpu->r.a); }

void Emu::Cpu::Ops::LDHLSPn(uint16_t arg) {
    int8_t arg2 = arg & 0xFF;
    uint8_t arg3 = arg2;
    uint16_t spLo = emu->cpu->r.sp & 0xFF;

    resetF();
    setF(HCarry, ((spLo & 0xF) + (arg3 & 0xF)) > 0xF);
    spLo += arg3;
    setF(Carry, spLo > 0xFF);
    emu->cpu->r.hl = emu->cpu->r.sp + arg2;
}

void Emu::Cpu::Ops::SWAPr(uint8_t &a) {
    uint8_t tr = a;
    a = ((tr&0xF)<<4)|((tr&0xF0)>>4);

    resetF();
    setF(Zero, !a);
}
void Emu::Cpu::Ops::SWAPr_b(uint16_t arg) { SWAPr(emu->cpu->r.b); }
void Emu::Cpu::Ops::SWAPr_c(uint16_t arg) { SWAPr(emu->cpu->r.c); }
void Emu::Cpu::Ops::SWAPr_d(uint16_t arg) { SWAPr(emu->cpu->r.d); }
void Emu::Cpu::Ops::SWAPr_e(uint16_t arg) { SWAPr(emu->cpu->r.e); }
void Emu::Cpu::Ops::SWAPr_h(uint16_t arg) { SWAPr(emu->cpu->r.h); }
void Emu::Cpu::Ops::SWAPr_l(uint16_t arg) { SWAPr(emu->cpu->r.l); }
void Emu::Cpu::Ops::SWAPr_a(uint16_t arg) { SWAPr(emu->cpu->r.a); }
void Emu::Cpu::Ops::SWAPHL(uint16_t arg) {
    uint8_t a = emu->mmu->rb(emu->cpu->r.hl);
    SWAPr(a);
    emu->mmu->wb(emu->cpu->r.hl, a);
}

/*--- Data processing ---*/
void Emu::Cpu::Ops::ADD(uint8_t &a, uint8_t b) {
    uint16_t res = a;
    res += b;

    resetF();
    setF(Zero, !(res & 0xFF));
    setF(HCarry, (a & 0x0F) + (b & 0x0F) > 0x0F);
    setF(Carry, res > 0xFF);

    a = res & 0xFF;
}
void Emu::Cpu::Ops::ADDr_b(uint16_t arg) { ADD(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::ADDr_c(uint16_t arg) { ADD(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::ADDr_d(uint16_t arg) { ADD(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::ADDr_e(uint16_t arg) { ADD(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::ADDr_h(uint16_t arg) { ADD(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::ADDr_l(uint16_t arg) { ADD(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::ADDr_a(uint16_t arg) { ADD(emu->cpu->r.a, emu->cpu->r.a); }
void Emu::Cpu::Ops::ADDHL(uint16_t arg) { ADD(emu->cpu->r.a, emu->mmu->rb(emu->cpu->r.hl)); }
void Emu::Cpu::Ops::ADDn(uint16_t arg) { ADD(emu->cpu->r.a, arg); }

void Emu::Cpu::Ops::ADD(uint16_t &a, uint16_t b) {
    uint32_t res = a;
    res += b;

    setF(Neg, false);
    setF(HCarry, ((a & 0xFFF) + (b & 0xFFF)) > 0xFFF);
    setF(Carry, res > 0xFFFF);

    a = res & 0xFFFF;
}
void Emu::Cpu::Ops::ADDHLBC(uint16_t arg) { ADD(emu->cpu->r.hl, emu->cpu->r.bc); }
void Emu::Cpu::Ops::ADDHLDE(uint16_t arg) { ADD(emu->cpu->r.hl, emu->cpu->r.de); }
void Emu::Cpu::Ops::ADDHLHL(uint16_t arg) { ADD(emu->cpu->r.hl, emu->cpu->r.hl); }
void Emu::Cpu::Ops::ADDHLSP(uint16_t arg) { ADD(emu->cpu->r.hl, emu->cpu->r.sp); }
void Emu::Cpu::Ops::ADDSPn(uint16_t arg) {
    int8_t arg2 = arg & 0xFF;
    uint8_t arg3 = arg2;
    uint16_t spLo = emu->cpu->r.sp & 0xFF;

    resetF();
    setF(HCarry, ((spLo & 0xF) + (arg3 & 0xF)) > 0xF);
    spLo += arg3;
    setF(Carry, spLo > 0xFF);
    emu->cpu->r.sp += arg2;
}

void Emu::Cpu::Ops::ADC(uint8_t &a, uint8_t b) {
    uint16_t res = a;
    uint8_t carry = (isSetF(Carry)?1:0);
    res += b;
    res += carry;

    resetF();
    setF(Zero, !(res & 0xFF));
    setF(HCarry, (a & 0x0F) + (b & 0x0F) + carry > 0x0F);
    setF(Carry, res > 0xFF);

    a = res & 0xFF;
}
void Emu::Cpu::Ops::ADCr_b(uint16_t arg) { ADC(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::ADCr_c(uint16_t arg) { ADC(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::ADCr_d(uint16_t arg) { ADC(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::ADCr_e(uint16_t arg) { ADC(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::ADCr_h(uint16_t arg) { ADC(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::ADCr_l(uint16_t arg) { ADC(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::ADCr_a(uint16_t arg) { ADC(emu->cpu->r.a, emu->cpu->r.a); }
void Emu::Cpu::Ops::ADCHL(uint16_t arg) { ADC(emu->cpu->r.a, emu->mmu->rb(emu->cpu->r.hl)); }
void Emu::Cpu::Ops::ADCn(uint16_t arg) {
    ADC(emu->cpu->r.a, arg);
}

void Emu::Cpu::Ops::SUB(uint8_t &a, uint8_t b) {
    uint8_t res = a;
    res -= b;

    resetF();
    setF(Zero, !(res & 0xFF));
    setF(Neg, true);
    setF(HCarry, (b & 0x0F) > (a & 0x0F));
    setF(Carry, b > a);

    a = res;
}
void Emu::Cpu::Ops::SUBr_b(uint16_t arg) { SUB(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::SUBr_c(uint16_t arg) { SUB(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::SUBr_d(uint16_t arg) { SUB(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::SUBr_e(uint16_t arg) { SUB(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::SUBr_h(uint16_t arg) { SUB(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::SUBr_l(uint16_t arg) { SUB(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::SUBr_a(uint16_t arg) { SUB(emu->cpu->r.a, emu->cpu->r.a); }
void Emu::Cpu::Ops::SUBHL(uint16_t arg) { SUB(emu->cpu->r.a, emu->mmu->rb(emu->cpu->r.hl)); }
void Emu::Cpu::Ops::SUBn(uint16_t arg) { SUB(emu->cpu->r.a, arg); }

void Emu::Cpu::Ops::SBC(uint8_t &a, uint8_t b) {
    uint8_t carry = (isSetF(Carry)?1:0);
    uint8_t res = a - b - carry;
    resetF();
    setF(Zero, !(res));
    setF(Neg, true);
    setF(HCarry, ((b & 0x0F) + carry) > (a & 0x0F));
    setF(Carry, b + carry > a);

    a = res;
}
void Emu::Cpu::Ops::SBCr_b(uint16_t arg) { SBC(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::SBCr_c(uint16_t arg) { SBC(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::SBCr_d(uint16_t arg) { SBC(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::SBCr_e(uint16_t arg) { SBC(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::SBCr_h(uint16_t arg) { SBC(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::SBCr_l(uint16_t arg) { SBC(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::SBCr_a(uint16_t arg) { SBC(emu->cpu->r.a, emu->cpu->r.a); }
void Emu::Cpu::Ops::SBCHL(uint16_t arg) { SBC(emu->cpu->r.a, emu->mmu->rb(emu->cpu->r.hl)); }
void Emu::Cpu::Ops::SBCn(uint16_t arg) { SBC(emu->cpu->r.a, arg); }

void Emu::Cpu::Ops::CP(uint8_t &a, uint8_t b) {
    uint8_t res = a;
    res -= b;

    resetF();
    setF(Zero, !res);
    setF(Neg, true);
    setF(HCarry, (b & 0x0F) > (a & 0x0F));
    setF(Carry, b > a);
}
void Emu::Cpu::Ops::CPr_b(uint16_t arg) { CP(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::CPr_c(uint16_t arg) { CP(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::CPr_d(uint16_t arg) { CP(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::CPr_e(uint16_t arg) { CP(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::CPr_h(uint16_t arg) { CP(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::CPr_l(uint16_t arg) { CP(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::CPr_a(uint16_t arg) { CP(emu->cpu->r.a, emu->cpu->r.a); }
void Emu::Cpu::Ops::CPHL(uint16_t arg) { CP(emu->cpu->r.a, emu->mmu->rb(emu->cpu->r.hl)); }
void Emu::Cpu::Ops::CPn(uint16_t arg) { CP(emu->cpu->r.a, arg); }

void Emu::Cpu::Ops::DAA(uint16_t arg) {
    int a = emu->cpu->r.a;
    if(!isSetF(Neg)) {
        if(isSetF(HCarry) || (a & 0xF) > 9) {
            a += 0x06;
        }
        if(isSetF(Carry) || a > 0x9F) {
            a += 0x60;
        }
    } else {
        if(isSetF(HCarry)) {
            a = (a - 6) & 0xFF;
        }
        if(isSetF(Carry)) {
            a -= 0x60;
        }
    }
    setF(HCarry, false);
    setF(Zero, false);

    if((a & 0x100) == 0x100) {
        setF(Carry, true);
    }
    a &= 0xFF;

    if(a == 0) {
        setF(Zero, true);
    }
    emu->cpu->r.a = (uint8_t)a;
}

void Emu::Cpu::Ops::ANDr(uint8_t &a, uint8_t b) {
    a&=b;

    resetF();
    setF(Zero, !a);
    setF(HCarry, true);
}
void Emu::Cpu::Ops::ANDr_b(uint16_t arg) { ANDr(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::ANDr_c(uint16_t arg) { ANDr(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::ANDr_d(uint16_t arg) { ANDr(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::ANDr_e(uint16_t arg) { ANDr(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::ANDr_h(uint16_t arg) { ANDr(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::ANDr_l(uint16_t arg) { ANDr(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::ANDr_a(uint16_t arg) { ANDr(emu->cpu->r.a, emu->cpu->r.a); }
void Emu::Cpu::Ops::ANDHL(uint16_t arg) { ANDr(emu->cpu->r.a, emu->mmu->rb(emu->cpu->r.hl)); }
void Emu::Cpu::Ops::ANDn(uint16_t arg) { ANDr(emu->cpu->r.a, arg);  }

void Emu::Cpu::Ops::ORr(uint8_t &a, uint8_t b) {
    a|=b;

    resetF();
    setF(Zero, !a);
}
void Emu::Cpu::Ops::ORr_b(uint16_t arg) { ORr(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::ORr_c(uint16_t arg) { ORr(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::ORr_d(uint16_t arg) { ORr(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::ORr_e(uint16_t arg) { ORr(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::ORr_h(uint16_t arg) { ORr(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::ORr_l(uint16_t arg) { ORr(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::ORr_a(uint16_t arg) { ORr(emu->cpu->r.a, emu->cpu->r.a); }
void Emu::Cpu::Ops::ORHL(uint16_t arg) { ORr(emu->cpu->r.a, emu->mmu->rb(emu->cpu->r.hl)); }
void Emu::Cpu::Ops::ORn(uint16_t arg) { ORr(emu->cpu->r.a, arg); }

void Emu::Cpu::Ops::XORr(uint8_t &a, uint8_t b) {
    a^=b;

    resetF();
    setF(Zero, !a);
}
void Emu::Cpu::Ops::XORr_b(uint16_t arg) { XORr(emu->cpu->r.a, emu->cpu->r.b); }
void Emu::Cpu::Ops::XORr_c(uint16_t arg) { XORr(emu->cpu->r.a, emu->cpu->r.c); }
void Emu::Cpu::Ops::XORr_d(uint16_t arg) { XORr(emu->cpu->r.a, emu->cpu->r.d); }
void Emu::Cpu::Ops::XORr_e(uint16_t arg) { XORr(emu->cpu->r.a, emu->cpu->r.e); }
void Emu::Cpu::Ops::XORr_h(uint16_t arg) { XORr(emu->cpu->r.a, emu->cpu->r.h); }
void Emu::Cpu::Ops::XORr_l(uint16_t arg) { XORr(emu->cpu->r.a, emu->cpu->r.l); }
void Emu::Cpu::Ops::XORr_a(uint16_t arg) { XORr(emu->cpu->r.a, emu->cpu->r.a); }
void Emu::Cpu::Ops::XORHL(uint16_t arg) { XORr(emu->cpu->r.a, emu->mmu->rb(emu->cpu->r.hl)); }
void Emu::Cpu::Ops::XORn(uint16_t arg) { XORr(emu->cpu->r.a, arg); }

void Emu::Cpu::Ops::INCr(uint8_t &a) {
    a++;

    setF(Zero, !a);
    setF(Neg, false);
    setF(HCarry, !(a & 0x0F));
}
void Emu::Cpu::Ops::INCr_b(uint16_t arg) { INCr(emu->cpu->r.b); }
void Emu::Cpu::Ops::INCr_c(uint16_t arg) { INCr(emu->cpu->r.c); }
void Emu::Cpu::Ops::INCr_d(uint16_t arg) { INCr(emu->cpu->r.d); }
void Emu::Cpu::Ops::INCr_e(uint16_t arg) { INCr(emu->cpu->r.e); }
void Emu::Cpu::Ops::INCr_h(uint16_t arg) { INCr(emu->cpu->r.h); }
void Emu::Cpu::Ops::INCr_l(uint16_t arg) { INCr(emu->cpu->r.l); }
void Emu::Cpu::Ops::INCr_a(uint16_t arg) { INCr(emu->cpu->r.a); }
void Emu::Cpu::Ops::INCHLm(uint16_t arg) {
    uint8_t a = emu->mmu->rb(emu->cpu->r.hl);
    INCr(a);
    emu->mmu->wb(emu->cpu->r.hl, a);
}

void Emu::Cpu::Ops::DECr(uint8_t &a) {
    setF(HCarry, !(a & 0x0F));

    a--;

    setF(Zero, !a);
    setF(Neg, true);
}
void Emu::Cpu::Ops::DECr_b(uint16_t arg) { DECr(emu->cpu->r.b); }
void Emu::Cpu::Ops::DECr_c(uint16_t arg) { DECr(emu->cpu->r.c); }
void Emu::Cpu::Ops::DECr_d(uint16_t arg) { DECr(emu->cpu->r.d); }
void Emu::Cpu::Ops::DECr_e(uint16_t arg) { DECr(emu->cpu->r.e); }
void Emu::Cpu::Ops::DECr_h(uint16_t arg) { DECr(emu->cpu->r.h); }
void Emu::Cpu::Ops::DECr_l(uint16_t arg) { DECr(emu->cpu->r.l); }
void Emu::Cpu::Ops::DECr_a(uint16_t arg) { DECr(emu->cpu->r.a); }
void Emu::Cpu::Ops::DECHLm(uint16_t arg) {
    uint8_t a = emu->mmu->rb(emu->cpu->r.hl);
    DECr(a);
    emu->mmu->wb(emu->cpu->r.hl, a);
}

void Emu::Cpu::Ops::INC(uint16_t &a) {
    a++;
}
void Emu::Cpu::Ops::INCBC(uint16_t arg) { INC(emu->cpu->r.bc); }
void Emu::Cpu::Ops::INCDE(uint16_t arg) { INC(emu->cpu->r.de); }
void Emu::Cpu::Ops::INCHL(uint16_t arg) { INC(emu->cpu->r.hl); }
void Emu::Cpu::Ops::INCSP(uint16_t arg) { INC(emu->cpu->r.sp); }

void Emu::Cpu::Ops::DEC(uint16_t &a) {
    a--;
}
void Emu::Cpu::Ops::DECBC(uint16_t arg) { DEC(emu->cpu->r.bc); }
void Emu::Cpu::Ops::DECDE(uint16_t arg) { DEC(emu->cpu->r.de); }
void Emu::Cpu::Ops::DECHL(uint16_t arg) { DEC(emu->cpu->r.hl); }
void Emu::Cpu::Ops::DECSP(uint16_t arg) { DEC(emu->cpu->r.sp); }

/*--- Bit manipulation ---*/
void Emu::Cpu::Ops::BIT(uint8_t bit, uint8_t &a) {
    uint8_t mask = (1 << bit);

    setF(Zero, !(a & mask));
    setF(Neg, false);
    setF(HCarry, true);
}

void Emu::Cpu::Ops::RES(uint8_t bit, uint8_t &a) {
    uint8_t mask = ~(1 << bit);
    a &= mask;
}

void Emu::Cpu::Ops::RES(uint8_t bit, uint16_t addr) {
    uint8_t mask = ~(1 << bit);
    uint8_t a = emu->mmu->rb(addr);
    a &= mask;
    emu->mmu->wb(addr, a);
}

void Emu::Cpu::Ops::SET(uint8_t bit, uint8_t &a) {
    uint8_t mask = (1 << bit);
    a |= mask;
}

void Emu::Cpu::Ops::SET(uint8_t bit, uint16_t addr) {
    uint8_t mask = (1 << bit);
    uint8_t a = emu->mmu->rb(addr);
    a |= mask;
    emu->mmu->wb(addr, a);
}

void Emu::Cpu::Ops::BIT0b(uint16_t arg) { BIT(0, emu->cpu->r.b); }
void Emu::Cpu::Ops::BIT0c(uint16_t arg) { BIT(0, emu->cpu->r.c); }
void Emu::Cpu::Ops::BIT0d(uint16_t arg) { BIT(0, emu->cpu->r.d); }
void Emu::Cpu::Ops::BIT0e(uint16_t arg) { BIT(0, emu->cpu->r.e); }
void Emu::Cpu::Ops::BIT0h(uint16_t arg) { BIT(0, emu->cpu->r.h); }
void Emu::Cpu::Ops::BIT0l(uint16_t arg) { BIT(0, emu->cpu->r.l); }
void Emu::Cpu::Ops::BIT0a(uint16_t arg) { BIT(0, emu->cpu->r.a); }
void Emu::Cpu::Ops::BIT0m(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); BIT(0, a); }

void Emu::Cpu::Ops::RES0b(uint16_t arg) { RES(0, emu->cpu->r.b); }
void Emu::Cpu::Ops::RES0c(uint16_t arg) { RES(0, emu->cpu->r.c); }
void Emu::Cpu::Ops::RES0d(uint16_t arg) { RES(0, emu->cpu->r.d); }
void Emu::Cpu::Ops::RES0e(uint16_t arg) { RES(0, emu->cpu->r.e); }
void Emu::Cpu::Ops::RES0h(uint16_t arg) { RES(0, emu->cpu->r.h); }
void Emu::Cpu::Ops::RES0l(uint16_t arg) { RES(0, emu->cpu->r.l); }
void Emu::Cpu::Ops::RES0a(uint16_t arg) { RES(0, emu->cpu->r.a); }
void Emu::Cpu::Ops::RES0m(uint16_t arg) { RES(0, emu->cpu->r.hl); }

void Emu::Cpu::Ops::SET0b(uint16_t arg) { SET(0, emu->cpu->r.b); }
void Emu::Cpu::Ops::SET0c(uint16_t arg) { SET(0, emu->cpu->r.c); }
void Emu::Cpu::Ops::SET0d(uint16_t arg) { SET(0, emu->cpu->r.d); }
void Emu::Cpu::Ops::SET0e(uint16_t arg) { SET(0, emu->cpu->r.e); }
void Emu::Cpu::Ops::SET0h(uint16_t arg) { SET(0, emu->cpu->r.h); }
void Emu::Cpu::Ops::SET0l(uint16_t arg) { SET(0, emu->cpu->r.l); }
void Emu::Cpu::Ops::SET0a(uint16_t arg) { SET(0, emu->cpu->r.a); }
void Emu::Cpu::Ops::SET0m(uint16_t arg) { SET(0, emu->cpu->r.hl); }

void Emu::Cpu::Ops::BIT1b(uint16_t arg) { BIT(1, emu->cpu->r.b); }
void Emu::Cpu::Ops::BIT1c(uint16_t arg) { BIT(1, emu->cpu->r.c); }
void Emu::Cpu::Ops::BIT1d(uint16_t arg) { BIT(1, emu->cpu->r.d); }
void Emu::Cpu::Ops::BIT1e(uint16_t arg) { BIT(1, emu->cpu->r.e); }
void Emu::Cpu::Ops::BIT1h(uint16_t arg) { BIT(1, emu->cpu->r.h); }
void Emu::Cpu::Ops::BIT1l(uint16_t arg) { BIT(1, emu->cpu->r.l); }
void Emu::Cpu::Ops::BIT1a(uint16_t arg) { BIT(1, emu->cpu->r.a); }
void Emu::Cpu::Ops::BIT1m(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); BIT(1, a); }

void Emu::Cpu::Ops::RES1b(uint16_t arg) { RES(1, emu->cpu->r.b); }
void Emu::Cpu::Ops::RES1c(uint16_t arg) { RES(1, emu->cpu->r.c); }
void Emu::Cpu::Ops::RES1d(uint16_t arg) { RES(1, emu->cpu->r.d); }
void Emu::Cpu::Ops::RES1e(uint16_t arg) { RES(1, emu->cpu->r.e); }
void Emu::Cpu::Ops::RES1h(uint16_t arg) { RES(1, emu->cpu->r.h); }
void Emu::Cpu::Ops::RES1l(uint16_t arg) { RES(1, emu->cpu->r.l); }
void Emu::Cpu::Ops::RES1a(uint16_t arg) { RES(1, emu->cpu->r.a); }
void Emu::Cpu::Ops::RES1m(uint16_t arg) { RES(1, emu->cpu->r.hl); }

void Emu::Cpu::Ops::SET1b(uint16_t arg) { SET(1, emu->cpu->r.b); }
void Emu::Cpu::Ops::SET1c(uint16_t arg) { SET(1, emu->cpu->r.c); }
void Emu::Cpu::Ops::SET1d(uint16_t arg) { SET(1, emu->cpu->r.d); }
void Emu::Cpu::Ops::SET1e(uint16_t arg) { SET(1, emu->cpu->r.e); }
void Emu::Cpu::Ops::SET1h(uint16_t arg) { SET(1, emu->cpu->r.h); }
void Emu::Cpu::Ops::SET1l(uint16_t arg) { SET(1, emu->cpu->r.l); }
void Emu::Cpu::Ops::SET1a(uint16_t arg) { SET(1, emu->cpu->r.a); }
void Emu::Cpu::Ops::SET1m(uint16_t arg) { SET(1, emu->cpu->r.hl); }

void Emu::Cpu::Ops::BIT2b(uint16_t arg) { BIT(2, emu->cpu->r.b); }
void Emu::Cpu::Ops::BIT2c(uint16_t arg) { BIT(2, emu->cpu->r.c); }
void Emu::Cpu::Ops::BIT2d(uint16_t arg) { BIT(2, emu->cpu->r.d); }
void Emu::Cpu::Ops::BIT2e(uint16_t arg) { BIT(2, emu->cpu->r.e); }
void Emu::Cpu::Ops::BIT2h(uint16_t arg) { BIT(2, emu->cpu->r.h); }
void Emu::Cpu::Ops::BIT2l(uint16_t arg) { BIT(2, emu->cpu->r.l); }
void Emu::Cpu::Ops::BIT2a(uint16_t arg) { BIT(2, emu->cpu->r.a); }
void Emu::Cpu::Ops::BIT2m(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); BIT(2, a); }

void Emu::Cpu::Ops::RES2b(uint16_t arg) { RES(2, emu->cpu->r.b); }
void Emu::Cpu::Ops::RES2c(uint16_t arg) { RES(2, emu->cpu->r.c); }
void Emu::Cpu::Ops::RES2d(uint16_t arg) { RES(2, emu->cpu->r.d); }
void Emu::Cpu::Ops::RES2e(uint16_t arg) { RES(2, emu->cpu->r.e); }
void Emu::Cpu::Ops::RES2h(uint16_t arg) { RES(2, emu->cpu->r.h); }
void Emu::Cpu::Ops::RES2l(uint16_t arg) { RES(2, emu->cpu->r.l); }
void Emu::Cpu::Ops::RES2a(uint16_t arg) { RES(2, emu->cpu->r.a); }
void Emu::Cpu::Ops::RES2m(uint16_t arg) { RES(2, emu->cpu->r.hl); }

void Emu::Cpu::Ops::SET2b(uint16_t arg) { SET(2, emu->cpu->r.b); }
void Emu::Cpu::Ops::SET2c(uint16_t arg) { SET(2, emu->cpu->r.c); }
void Emu::Cpu::Ops::SET2d(uint16_t arg) { SET(2, emu->cpu->r.d); }
void Emu::Cpu::Ops::SET2e(uint16_t arg) { SET(2, emu->cpu->r.e); }
void Emu::Cpu::Ops::SET2h(uint16_t arg) { SET(2, emu->cpu->r.h); }
void Emu::Cpu::Ops::SET2l(uint16_t arg) { SET(2, emu->cpu->r.l); }
void Emu::Cpu::Ops::SET2a(uint16_t arg) { SET(2, emu->cpu->r.a); }
void Emu::Cpu::Ops::SET2m(uint16_t arg) { SET(2, emu->cpu->r.hl); }

void Emu::Cpu::Ops::BIT3b(uint16_t arg) { BIT(3, emu->cpu->r.b); }
void Emu::Cpu::Ops::BIT3c(uint16_t arg) { BIT(3, emu->cpu->r.c); }
void Emu::Cpu::Ops::BIT3d(uint16_t arg) { BIT(3, emu->cpu->r.d); }
void Emu::Cpu::Ops::BIT3e(uint16_t arg) { BIT(3, emu->cpu->r.e); }
void Emu::Cpu::Ops::BIT3h(uint16_t arg) { BIT(3, emu->cpu->r.h); }
void Emu::Cpu::Ops::BIT3l(uint16_t arg) { BIT(3, emu->cpu->r.l); }
void Emu::Cpu::Ops::BIT3a(uint16_t arg) { BIT(3, emu->cpu->r.a); }
void Emu::Cpu::Ops::BIT3m(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); BIT(3, a); }

void Emu::Cpu::Ops::RES3b(uint16_t arg) { RES(3, emu->cpu->r.b); }
void Emu::Cpu::Ops::RES3c(uint16_t arg) { RES(3, emu->cpu->r.c); }
void Emu::Cpu::Ops::RES3d(uint16_t arg) { RES(3, emu->cpu->r.d); }
void Emu::Cpu::Ops::RES3e(uint16_t arg) { RES(3, emu->cpu->r.e); }
void Emu::Cpu::Ops::RES3h(uint16_t arg) { RES(3, emu->cpu->r.h); }
void Emu::Cpu::Ops::RES3l(uint16_t arg) { RES(3, emu->cpu->r.l); }
void Emu::Cpu::Ops::RES3a(uint16_t arg) { RES(3, emu->cpu->r.a); }
void Emu::Cpu::Ops::RES3m(uint16_t arg) { RES(3, emu->cpu->r.hl); }

void Emu::Cpu::Ops::SET3b(uint16_t arg) { SET(3, emu->cpu->r.b); }
void Emu::Cpu::Ops::SET3c(uint16_t arg) { SET(3, emu->cpu->r.c); }
void Emu::Cpu::Ops::SET3d(uint16_t arg) { SET(3, emu->cpu->r.d); }
void Emu::Cpu::Ops::SET3e(uint16_t arg) { SET(3, emu->cpu->r.e); }
void Emu::Cpu::Ops::SET3h(uint16_t arg) { SET(3, emu->cpu->r.h); }
void Emu::Cpu::Ops::SET3l(uint16_t arg) { SET(3, emu->cpu->r.l); }
void Emu::Cpu::Ops::SET3a(uint16_t arg) { SET(3, emu->cpu->r.a); }
void Emu::Cpu::Ops::SET3m(uint16_t arg) { SET(3, emu->cpu->r.hl); }

void Emu::Cpu::Ops::BIT4b(uint16_t arg) { BIT(4, emu->cpu->r.b); }
void Emu::Cpu::Ops::BIT4c(uint16_t arg) { BIT(4, emu->cpu->r.c); }
void Emu::Cpu::Ops::BIT4d(uint16_t arg) { BIT(4, emu->cpu->r.d); }
void Emu::Cpu::Ops::BIT4e(uint16_t arg) { BIT(4, emu->cpu->r.e); }
void Emu::Cpu::Ops::BIT4h(uint16_t arg) { BIT(4, emu->cpu->r.h); }
void Emu::Cpu::Ops::BIT4l(uint16_t arg) { BIT(4, emu->cpu->r.l); }
void Emu::Cpu::Ops::BIT4a(uint16_t arg) { BIT(4, emu->cpu->r.a); }
void Emu::Cpu::Ops::BIT4m(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); BIT(4, a); }

void Emu::Cpu::Ops::RES4b(uint16_t arg) { RES(4, emu->cpu->r.b); }
void Emu::Cpu::Ops::RES4c(uint16_t arg) { RES(4, emu->cpu->r.c); }
void Emu::Cpu::Ops::RES4d(uint16_t arg) { RES(4, emu->cpu->r.d); }
void Emu::Cpu::Ops::RES4e(uint16_t arg) { RES(4, emu->cpu->r.e); }
void Emu::Cpu::Ops::RES4h(uint16_t arg) { RES(4, emu->cpu->r.h); }
void Emu::Cpu::Ops::RES4l(uint16_t arg) { RES(4, emu->cpu->r.l); }
void Emu::Cpu::Ops::RES4a(uint16_t arg) { RES(4, emu->cpu->r.a); }
void Emu::Cpu::Ops::RES4m(uint16_t arg) { RES(4, emu->cpu->r.hl); }

void Emu::Cpu::Ops::SET4b(uint16_t arg) { SET(4, emu->cpu->r.b); }
void Emu::Cpu::Ops::SET4c(uint16_t arg) { SET(4, emu->cpu->r.c); }
void Emu::Cpu::Ops::SET4d(uint16_t arg) { SET(4, emu->cpu->r.d); }
void Emu::Cpu::Ops::SET4e(uint16_t arg) { SET(4, emu->cpu->r.e); }
void Emu::Cpu::Ops::SET4h(uint16_t arg) { SET(4, emu->cpu->r.h); }
void Emu::Cpu::Ops::SET4l(uint16_t arg) { SET(4, emu->cpu->r.l); }
void Emu::Cpu::Ops::SET4a(uint16_t arg) { SET(4, emu->cpu->r.a); }
void Emu::Cpu::Ops::SET4m(uint16_t arg) { SET(4, emu->cpu->r.hl); }

void Emu::Cpu::Ops::BIT5b(uint16_t arg) { BIT(5, emu->cpu->r.b); }
void Emu::Cpu::Ops::BIT5c(uint16_t arg) { BIT(5, emu->cpu->r.c); }
void Emu::Cpu::Ops::BIT5d(uint16_t arg) { BIT(5, emu->cpu->r.d); }
void Emu::Cpu::Ops::BIT5e(uint16_t arg) { BIT(5, emu->cpu->r.e); }
void Emu::Cpu::Ops::BIT5h(uint16_t arg) { BIT(5, emu->cpu->r.h); }
void Emu::Cpu::Ops::BIT5l(uint16_t arg) { BIT(5, emu->cpu->r.l); }
void Emu::Cpu::Ops::BIT5a(uint16_t arg) { BIT(5, emu->cpu->r.a); }
void Emu::Cpu::Ops::BIT5m(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); BIT(5, a); }

void Emu::Cpu::Ops::RES5b(uint16_t arg) { RES(5, emu->cpu->r.b); }
void Emu::Cpu::Ops::RES5c(uint16_t arg) { RES(5, emu->cpu->r.c); }
void Emu::Cpu::Ops::RES5d(uint16_t arg) { RES(5, emu->cpu->r.d); }
void Emu::Cpu::Ops::RES5e(uint16_t arg) { RES(5, emu->cpu->r.e); }
void Emu::Cpu::Ops::RES5h(uint16_t arg) { RES(5, emu->cpu->r.h); }
void Emu::Cpu::Ops::RES5l(uint16_t arg) { RES(5, emu->cpu->r.l); }
void Emu::Cpu::Ops::RES5a(uint16_t arg) { RES(5, emu->cpu->r.a); }
void Emu::Cpu::Ops::RES5m(uint16_t arg) { RES(5, emu->cpu->r.hl); }

void Emu::Cpu::Ops::SET5b(uint16_t arg) { SET(5, emu->cpu->r.b); }
void Emu::Cpu::Ops::SET5c(uint16_t arg) { SET(5, emu->cpu->r.c); }
void Emu::Cpu::Ops::SET5d(uint16_t arg) { SET(5, emu->cpu->r.d); }
void Emu::Cpu::Ops::SET5e(uint16_t arg) { SET(5, emu->cpu->r.e); }
void Emu::Cpu::Ops::SET5h(uint16_t arg) { SET(5, emu->cpu->r.h); }
void Emu::Cpu::Ops::SET5l(uint16_t arg) { SET(5, emu->cpu->r.l); }
void Emu::Cpu::Ops::SET5a(uint16_t arg) { SET(5, emu->cpu->r.a); }
void Emu::Cpu::Ops::SET5m(uint16_t arg) { SET(5, emu->cpu->r.hl); }

void Emu::Cpu::Ops::BIT6b(uint16_t arg) { BIT(6, emu->cpu->r.b); }
void Emu::Cpu::Ops::BIT6c(uint16_t arg) { BIT(6, emu->cpu->r.c); }
void Emu::Cpu::Ops::BIT6d(uint16_t arg) { BIT(6, emu->cpu->r.d); }
void Emu::Cpu::Ops::BIT6e(uint16_t arg) { BIT(6, emu->cpu->r.e); }
void Emu::Cpu::Ops::BIT6h(uint16_t arg) { BIT(6, emu->cpu->r.h); }
void Emu::Cpu::Ops::BIT6l(uint16_t arg) { BIT(6, emu->cpu->r.l); }
void Emu::Cpu::Ops::BIT6a(uint16_t arg) { BIT(6, emu->cpu->r.a); }
void Emu::Cpu::Ops::BIT6m(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); BIT(6, a); }

void Emu::Cpu::Ops::RES6b(uint16_t arg) { RES(6, emu->cpu->r.b); }
void Emu::Cpu::Ops::RES6c(uint16_t arg) { RES(6, emu->cpu->r.c); }
void Emu::Cpu::Ops::RES6d(uint16_t arg) { RES(6, emu->cpu->r.d); }
void Emu::Cpu::Ops::RES6e(uint16_t arg) { RES(6, emu->cpu->r.e); }
void Emu::Cpu::Ops::RES6h(uint16_t arg) { RES(6, emu->cpu->r.h); }
void Emu::Cpu::Ops::RES6l(uint16_t arg) { RES(6, emu->cpu->r.l); }
void Emu::Cpu::Ops::RES6a(uint16_t arg) { RES(6, emu->cpu->r.a); }
void Emu::Cpu::Ops::RES6m(uint16_t arg) { RES(6, emu->cpu->r.hl); }

void Emu::Cpu::Ops::SET6b(uint16_t arg) { SET(6, emu->cpu->r.b); }
void Emu::Cpu::Ops::SET6c(uint16_t arg) { SET(6, emu->cpu->r.c); }
void Emu::Cpu::Ops::SET6d(uint16_t arg) { SET(6, emu->cpu->r.d); }
void Emu::Cpu::Ops::SET6e(uint16_t arg) { SET(6, emu->cpu->r.e); }
void Emu::Cpu::Ops::SET6h(uint16_t arg) { SET(6, emu->cpu->r.h); }
void Emu::Cpu::Ops::SET6l(uint16_t arg) { SET(6, emu->cpu->r.l); }
void Emu::Cpu::Ops::SET6a(uint16_t arg) { SET(6, emu->cpu->r.a); }
void Emu::Cpu::Ops::SET6m(uint16_t arg) { SET(6, emu->cpu->r.hl); }

void Emu::Cpu::Ops::BIT7b(uint16_t arg) { BIT(7, emu->cpu->r.b); }
void Emu::Cpu::Ops::BIT7c(uint16_t arg) { BIT(7, emu->cpu->r.c); }
void Emu::Cpu::Ops::BIT7d(uint16_t arg) { BIT(7, emu->cpu->r.d); }
void Emu::Cpu::Ops::BIT7e(uint16_t arg) { BIT(7, emu->cpu->r.e); }
void Emu::Cpu::Ops::BIT7h(uint16_t arg) { BIT(7, emu->cpu->r.h); }
void Emu::Cpu::Ops::BIT7l(uint16_t arg) { BIT(7, emu->cpu->r.l); }
void Emu::Cpu::Ops::BIT7a(uint16_t arg) { BIT(7, emu->cpu->r.a); }
void Emu::Cpu::Ops::BIT7m(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); BIT(7, a); }

void Emu::Cpu::Ops::RES7b(uint16_t arg) { RES(7, emu->cpu->r.b); }
void Emu::Cpu::Ops::RES7c(uint16_t arg) { RES(7, emu->cpu->r.c); }
void Emu::Cpu::Ops::RES7d(uint16_t arg) { RES(7, emu->cpu->r.d); }
void Emu::Cpu::Ops::RES7e(uint16_t arg) { RES(7, emu->cpu->r.e); }
void Emu::Cpu::Ops::RES7h(uint16_t arg) { RES(7, emu->cpu->r.h); }
void Emu::Cpu::Ops::RES7l(uint16_t arg) { RES(7, emu->cpu->r.l); }
void Emu::Cpu::Ops::RES7a(uint16_t arg) { RES(7, emu->cpu->r.a); }
void Emu::Cpu::Ops::RES7m(uint16_t arg) { RES(7, emu->cpu->r.hl); }

void Emu::Cpu::Ops::SET7b(uint16_t arg) { SET(7, emu->cpu->r.b); }
void Emu::Cpu::Ops::SET7c(uint16_t arg) { SET(7, emu->cpu->r.c); }
void Emu::Cpu::Ops::SET7d(uint16_t arg) { SET(7, emu->cpu->r.d); }
void Emu::Cpu::Ops::SET7e(uint16_t arg) { SET(7, emu->cpu->r.e); }
void Emu::Cpu::Ops::SET7h(uint16_t arg) { SET(7, emu->cpu->r.h); }
void Emu::Cpu::Ops::SET7l(uint16_t arg) { SET(7, emu->cpu->r.l); }
void Emu::Cpu::Ops::SET7a(uint16_t arg) { SET(7, emu->cpu->r.a); }
void Emu::Cpu::Ops::SET7m(uint16_t arg) { SET(7, emu->cpu->r.hl); }


void Emu::Cpu::Ops::RLr(uint8_t &a) {
    uint8_t carry = (isSetF(Carry)?0x01:0x00);
    uint8_t aBit7 = ((a&0x80)?0x01:0x00);
    a = (a << 1) + carry;
    resetF();
    setF(Zero, !a);
    setF(Carry, aBit7);
}

void Emu::Cpu::Ops::RLCr(uint8_t &a) {
    uint8_t aBit7 = ((a&0x80)?0x01:0x00);
    a = (a << 1) + aBit7;
    resetF();
    setF(Zero, !a);
    setF(Carry, aBit7);
}

void Emu::Cpu::Ops::RRr(uint8_t &a) {
    uint8_t carry = (isSetF(Carry)?0x80:0x00);
    uint8_t aBit0 = (a & 0x01);
    a = carry + (a >> 1);
    resetF();
    setF(Zero, !a);
    setF(Carry, aBit0);
}

void Emu::Cpu::Ops::RRCr(uint8_t &a) {
    uint8_t aBit0 = (a & 0x01);
    a = (aBit0 << 7) + (a >> 1);
    resetF();
    setF(Zero, !a);
    setF(Carry, aBit0);
}

void Emu::Cpu::Ops::RLA(uint16_t arg) { RLr(emu->cpu->r.a); setF(Zero, false); }
void Emu::Cpu::Ops::RLCA(uint16_t arg) { RLCr(emu->cpu->r.a); setF(Zero, false); }
void Emu::Cpu::Ops::RRA(uint16_t arg) { RRr(emu->cpu->r.a); setF(Zero, false); }
void Emu::Cpu::Ops::RRCA(uint16_t arg) { RRCr(emu->cpu->r.a); setF(Zero, false); }

void Emu::Cpu::Ops::RLr_b(uint16_t arg) { RLr(emu->cpu->r.b); }
void Emu::Cpu::Ops::RLr_c(uint16_t arg) { RLr(emu->cpu->r.c); }
void Emu::Cpu::Ops::RLr_d(uint16_t arg) { RLr(emu->cpu->r.d); }
void Emu::Cpu::Ops::RLr_e(uint16_t arg) { RLr(emu->cpu->r.e); }
void Emu::Cpu::Ops::RLr_h(uint16_t arg) { RLr(emu->cpu->r.h); }
void Emu::Cpu::Ops::RLr_l(uint16_t arg) { RLr(emu->cpu->r.l); }
void Emu::Cpu::Ops::RLr_a(uint16_t arg) { RLr(emu->cpu->r.a); }
void Emu::Cpu::Ops::RLHL(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); RLr(a); emu->mmu->wb(emu->cpu->r.hl, a); }

void Emu::Cpu::Ops::RLCr_b(uint16_t arg) { RLCr(emu->cpu->r.b); }
void Emu::Cpu::Ops::RLCr_c(uint16_t arg) { RLCr(emu->cpu->r.c); }
void Emu::Cpu::Ops::RLCr_d(uint16_t arg) { RLCr(emu->cpu->r.d); }
void Emu::Cpu::Ops::RLCr_e(uint16_t arg) { RLCr(emu->cpu->r.e); }
void Emu::Cpu::Ops::RLCr_h(uint16_t arg) { RLCr(emu->cpu->r.h); }
void Emu::Cpu::Ops::RLCr_l(uint16_t arg) { RLCr(emu->cpu->r.l); }
void Emu::Cpu::Ops::RLCr_a(uint16_t arg) { RLCr(emu->cpu->r.a); }
void Emu::Cpu::Ops::RLCHL(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); RLCr(a); emu->mmu->wb(emu->cpu->r.hl, a); }

void Emu::Cpu::Ops::RRr_b(uint16_t arg) { RRr(emu->cpu->r.b); }
void Emu::Cpu::Ops::RRr_c(uint16_t arg) { RRr(emu->cpu->r.c); }
void Emu::Cpu::Ops::RRr_d(uint16_t arg) { RRr(emu->cpu->r.d); }
void Emu::Cpu::Ops::RRr_e(uint16_t arg) { RRr(emu->cpu->r.e); }
void Emu::Cpu::Ops::RRr_h(uint16_t arg) { RRr(emu->cpu->r.h); }
void Emu::Cpu::Ops::RRr_l(uint16_t arg) { RRr(emu->cpu->r.l); }
void Emu::Cpu::Ops::RRr_a(uint16_t arg) { RRr(emu->cpu->r.a); }
void Emu::Cpu::Ops::RRHL(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); RRr(a); emu->mmu->wb(emu->cpu->r.hl, a); }

void Emu::Cpu::Ops::RRCr_b(uint16_t arg) { RRCr(emu->cpu->r.b); }
void Emu::Cpu::Ops::RRCr_c(uint16_t arg) { RRCr(emu->cpu->r.c); }
void Emu::Cpu::Ops::RRCr_d(uint16_t arg) { RRCr(emu->cpu->r.d); }
void Emu::Cpu::Ops::RRCr_e(uint16_t arg) { RRCr(emu->cpu->r.e); }
void Emu::Cpu::Ops::RRCr_h(uint16_t arg) { RRCr(emu->cpu->r.h); }
void Emu::Cpu::Ops::RRCr_l(uint16_t arg) { RRCr(emu->cpu->r.l); }
void Emu::Cpu::Ops::RRCr_a(uint16_t arg) { RRCr(emu->cpu->r.a); }
void Emu::Cpu::Ops::RRCHL(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); RRCr(a); emu->mmu->wb(emu->cpu->r.hl, a); }

void Emu::Cpu::Ops::SLAr(uint8_t &a) {
    uint8_t aBit7 = ((a&0x80)?0x01:0x00);
    a = a << 1;
    resetF();
    setF(Zero, !a);
    setF(Carry, aBit7);
}

void Emu::Cpu::Ops::SRAr(uint8_t &a) {
    uint8_t aBit7 = (a&0x80);
    uint8_t aBit0 = (a&0x01);
    a = aBit7 + (a >> 1);
    resetF();
    setF(Zero, !a);
    setF(Carry, aBit0);
}
void Emu::Cpu::Ops::SRLr(uint8_t &a) {
    uint8_t aBit0 = (a&0x01);
    a = (a >> 1);
    resetF();
    setF(Zero, !a);
    setF(Carry, aBit0);
}

void Emu::Cpu::Ops::SLAr_b(uint16_t arg) { SLAr(emu->cpu->r.b); }
void Emu::Cpu::Ops::SLAr_c(uint16_t arg) { SLAr(emu->cpu->r.c); }
void Emu::Cpu::Ops::SLAr_d(uint16_t arg) { SLAr(emu->cpu->r.d); }
void Emu::Cpu::Ops::SLAr_e(uint16_t arg) { SLAr(emu->cpu->r.e); }
void Emu::Cpu::Ops::SLAr_h(uint16_t arg) { SLAr(emu->cpu->r.h); }
void Emu::Cpu::Ops::SLAr_l(uint16_t arg) { SLAr(emu->cpu->r.l); }
void Emu::Cpu::Ops::SLAr_a(uint16_t arg) { SLAr(emu->cpu->r.a); }
void Emu::Cpu::Ops::SLAHL(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); SLAr(a); emu->mmu->wb(emu->cpu->r.hl, a); }

void Emu::Cpu::Ops::SRAr_b(uint16_t arg) { SRAr(emu->cpu->r.b); }
void Emu::Cpu::Ops::SRAr_c(uint16_t arg) { SRAr(emu->cpu->r.c); }
void Emu::Cpu::Ops::SRAr_d(uint16_t arg) { SRAr(emu->cpu->r.d); }
void Emu::Cpu::Ops::SRAr_e(uint16_t arg) { SRAr(emu->cpu->r.e); }
void Emu::Cpu::Ops::SRAr_h(uint16_t arg) { SRAr(emu->cpu->r.h); }
void Emu::Cpu::Ops::SRAr_l(uint16_t arg) { SRAr(emu->cpu->r.l); }
void Emu::Cpu::Ops::SRAr_a(uint16_t arg) { SRAr(emu->cpu->r.a); }
void Emu::Cpu::Ops::SRAHL(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); SRAr(a); emu->mmu->wb(emu->cpu->r.hl, a); }

void Emu::Cpu::Ops::SRLr_b(uint16_t arg) { SRLr(emu->cpu->r.b); }
void Emu::Cpu::Ops::SRLr_c(uint16_t arg) { SRLr(emu->cpu->r.c); }
void Emu::Cpu::Ops::SRLr_d(uint16_t arg) { SRLr(emu->cpu->r.d); }
void Emu::Cpu::Ops::SRLr_e(uint16_t arg) { SRLr(emu->cpu->r.e); }
void Emu::Cpu::Ops::SRLr_h(uint16_t arg) { SRLr(emu->cpu->r.h); }
void Emu::Cpu::Ops::SRLr_l(uint16_t arg) { SRLr(emu->cpu->r.l); }
void Emu::Cpu::Ops::SRLr_a(uint16_t arg) { SRLr(emu->cpu->r.a); }
void Emu::Cpu::Ops::SRLHL(uint16_t arg) { uint8_t a = emu->mmu->rb(emu->cpu->r.hl); SRLr(a); emu->mmu->wb(emu->cpu->r.hl, a); }

void Emu::Cpu::Ops::CPL(uint16_t arg) { emu->cpu->r.a = ~(emu->cpu->r.a); setF(Neg, true); setF(HCarry, true); }

void Emu::Cpu::Ops::CCF(uint16_t arg) { setF(Neg, false); setF(HCarry, false); setF(Carry, !isSetF(Carry)); }
void Emu::Cpu::Ops::SCF(uint16_t arg) { setF(Neg, false); setF(HCarry, false); setF(Carry, true); }

/*--- Stack ---*/
void Emu::Cpu::Ops::PUSH(uint16_t a) {
    emu->cpu->r.sp -= 2;
    emu->mmu->ww(emu->cpu->r.sp, a);
}
void Emu::Cpu::Ops::PUSHBC(uint16_t arg) { PUSH(emu->cpu->r.bc); }
void Emu::Cpu::Ops::PUSHDE(uint16_t arg) { PUSH(emu->cpu->r.de); }
void Emu::Cpu::Ops::PUSHHL(uint16_t arg) { PUSH(emu->cpu->r.hl); }
void Emu::Cpu::Ops::PUSHAF(uint16_t arg) { PUSH(emu->cpu->r.af); }

void Emu::Cpu::Ops::POP(uint16_t &a) {
    a = emu->mmu->rw(emu->cpu->r.sp);
    emu->cpu->r.sp += 2;
}
void Emu::Cpu::Ops::POPBC(uint16_t arg) { POP(emu->cpu->r.bc); }
void Emu::Cpu::Ops::POPDE(uint16_t arg) { POP(emu->cpu->r.de); }
void Emu::Cpu::Ops::POPHL(uint16_t arg) { POP(emu->cpu->r.hl); }
void Emu::Cpu::Ops::POPAF(uint16_t arg) { POP(emu->cpu->r.af); emu->cpu->r.f &= 0xF0; }

/*--- Jump ---*/
void Emu::Cpu::Ops::JPnn(uint16_t arg) { emu->cpu->r.pc = arg; }
void Emu::Cpu::Ops::JPHL(uint16_t arg) { emu->cpu->r.pc = emu->cpu->r.hl; }
void Emu::Cpu::Ops::JPNZnn(uint16_t arg) { if(!isSetF(Zero)) { JPnn(arg); emu->cpu->r.m = 1; } }
void Emu::Cpu::Ops::JPZnn (uint16_t arg) { if(isSetF(Zero)) { JPnn(arg); emu->cpu->r.m = 1; } }
void Emu::Cpu::Ops::JPNCnn(uint16_t arg) { if(!isSetF(Carry)) { JPnn(arg); emu->cpu->r.m = 1; } }
void Emu::Cpu::Ops::JPCnn (uint16_t arg) { if(isSetF(Carry)) { JPnn(arg); emu->cpu->r.m = 1; } }

void Emu::Cpu::Ops::JRn(uint16_t arg) { int8_t arg2 = arg & 0xFF; emu->cpu->r.pc +=arg2; }
void Emu::Cpu::Ops::JRNZn(uint16_t arg) { if(!isSetF(Zero)) { JRn(arg); emu->cpu->r.m = 1; } }
void Emu::Cpu::Ops::JRZn (uint16_t arg) { if(isSetF(Zero)) { JRn(arg); emu->cpu->r.m = 1; } }
void Emu::Cpu::Ops::JRNCn(uint16_t arg) { if(!isSetF(Carry)) { JRn(arg); emu->cpu->r.m = 1; } }
void Emu::Cpu::Ops::JRCn (uint16_t arg) { if(isSetF(Carry)) { JRn(arg); emu->cpu->r.m = 1; } }

void Emu::Cpu::Ops::CALLnn(uint16_t arg) { PUSH(emu->cpu->r.pc); JPnn(arg); }
void Emu::Cpu::Ops::CALLNZnn(uint16_t arg) { if(!isSetF(Zero)) { CALLnn(arg); emu->cpu->r.m = 3; } }
void Emu::Cpu::Ops::CALLZnn(uint16_t arg) { if(isSetF(Zero)) { CALLnn(arg); emu->cpu->r.m = 3; } }
void Emu::Cpu::Ops::CALLNCnn(uint16_t arg) { if(!isSetF(Carry)) { CALLnn(arg); emu->cpu->r.m = 3; } }
void Emu::Cpu::Ops::CALLCnn(uint16_t arg) { if(isSetF(Carry)) { CALLnn(arg); emu->cpu->r.m = 3; } }

void Emu::Cpu::Ops::RET(uint16_t arg) { POP(emu->cpu->r.pc); }
void Emu::Cpu::Ops::RETI(uint16_t arg) { emu->cpu->r.ime=1; RET(0); }
void Emu::Cpu::Ops::RETNZ(uint16_t arg) { if(!isSetF(Zero)) { RET(0); emu->cpu->r.m = 3; } }
void Emu::Cpu::Ops::RETZ(uint16_t arg) { if(isSetF(Zero)) { RET(0); emu->cpu->r.m = 3; } }
void Emu::Cpu::Ops::RETNC(uint16_t arg) { if(!isSetF(Carry)) { RET(0); emu->cpu->r.m = 3; } }
void Emu::Cpu::Ops::RETC(uint16_t arg) { if(isSetF(Carry)) { RET(0); emu->cpu->r.m = 3; } }

void Emu::Cpu::Ops::RST(uint8_t addr) {
    PUSH(emu->cpu->r.pc);
    JPnn(0x0000 + addr);
}
void Emu::Cpu::Ops::RST00(uint16_t  arg) { RST(0x00); }
void Emu::Cpu::Ops::RST08(uint16_t  arg) { RST(0x08); }
void Emu::Cpu::Ops::RST10(uint16_t  arg) { RST(0x10); }
void Emu::Cpu::Ops::RST18(uint16_t  arg) { RST(0x18); }
void Emu::Cpu::Ops::RST20(uint16_t  arg) { RST(0x20); }
void Emu::Cpu::Ops::RST28(uint16_t  arg) { RST(0x28); }
void Emu::Cpu::Ops::RST30(uint16_t  arg) { RST(0x30); }
void Emu::Cpu::Ops::RST38(uint16_t  arg) { RST(0x38); }

void Emu::Cpu::Ops::NOP(uint16_t arg) { }

void Emu::Cpu::Ops::HALT(uint16_t arg) { emu->cpu->halt = true; }
void Emu::Cpu::Ops::STOP(uint16_t arg) { }

void Emu::Cpu::Ops::DI(uint16_t arg) { emu->cpu->r.ime=0; }
void Emu::Cpu::Ops::EI(uint16_t arg) { emu->cpu->r.ime=1; }

void Emu::Cpu::Ops::XX(uint16_t arg) {
    std::cout << "Cpu: Uknown instruction: " << std::hex << emu->cpu->r.pc - 1 << std::endl;
}

void Emu::Cpu::Ops::MAPcb(uint16_t arg) {
    cbTable[arg&0xFF].pf(0);
    emu->cpu->r.m = cbTable[arg&0xFF].m;
}

Emu::Cpu::Ops::Op Emu::Cpu::Ops::opTable[256] = {
        {"NOP",                     0, 1, NOP},       // 0x00
        {"LD BC, 0x%04X",           2, 3, LDBCnn},    // 0x01
        {"LD (BC), A",              0, 2, LDBCmA},    // 0x02
        {"INC BC",                  0, 2, INCBC},     // 0x03
        {"INC B",                   0, 1, INCr_b},    // 0x04
        {"DEC B",                   0, 1, DECr_b},    // 0x05
        {"LD B, 0x%02X",            1, 2, LDrn_b},    // 0x06
        {"RLCA",                    0, 1, RLCA},      // 0x07
        {"LD (0x%04X), SP",         2, 5, LDmmSP},    // 0x08
        {"ADD HL, BC",              0, 2, ADDHLBC},   // 0x09
        {"LD A, (BC)",              0, 2, LDABCm},    // 0x0a
        {"DEC BC",                  0, 2, DECBC},     // 0x0b
        {"INC C",                   0, 1, INCr_c},    // 0x0c
        {"DEC C",                   0, 1, DECr_c},    // 0x0d
        {"LD C, 0x%02X",            1, 2, LDrn_c},    // 0x0e
        {"RRCA",                    0, 1, RRCA},      // 0x0f
        {"STOP",                    1, 1, STOP},      // 0x10
        {"LD DE, 0x%04X",           2, 3, LDDEnn},    // 0x11
        {"LD (DE), A",              0, 2, LDDEmA},    // 0x12
        {"INC DE",                  0, 2, INCDE},     // 0x13
        {"INC D",                   0, 1, INCr_d},    // 0x14
        {"DEC D",                   0, 1, DECr_d},    // 0x15
        {"LD D, 0x%02X",            1, 2, LDrn_d},    // 0x16
        {"RLA",                     0, 1, RLA},       // 0x17
        {"JR 0x%02X",               1, 3, JRn},       // 0x18
        {"ADD HL, DE",              0, 2, ADDHLDE},   // 0x19
        {"LD A, (DE)",              0, 2, LDADEm},    // 0x1a
        {"DEC DE",                  0, 2, DECDE},     // 0x1b
        {"INC E",                   0, 1, INCr_e},    // 0x1c
        {"DEC E",                   0, 1, DECr_e},    // 0x1d
        {"LD E, 0x%02X",            1, 2, LDrn_e},    // 0x1e
        {"RRA",                     0, 1, RRA},       // 0x1f
        {"JR NZ, 0x%02X",           1, 2, JRNZn},     // 0x20
        {"LD HL, 0x%04X",           2, 3, LDHLnn},    // 0x21
        {"LDI (HL), A",             0, 2, LDHLIA},    // 0x22
        {"INC HL",                  0, 2, INCHL},     // 0x23
        {"INC H",                   0, 1, INCr_h},    // 0x24
        {"DEC H",                   0, 1, DECr_h},    // 0x25
        {"LD H, 0x%02X",            1, 2, LDrn_h},    // 0x26
        {"DAA",                     0, 1, DAA},       // 0x27
        {"JR Z, 0x%02X",            1, 2, JRZn},      // 0x28
        {"ADD HL, HL",              0, 2, ADDHLHL},   // 0x29
        {"LDI A, (HL)",             0, 2, LDAHLI},    // 0x2a
        {"DEC HL",                  0, 2, DECHL},     // 0x2b
        {"INC L",                   0, 1, INCr_l},    // 0x2c
        {"DEC L",                   0, 1, DECr_l},    // 0x2d
        {"LD L, 0x%02X",            1, 2, LDrn_l},    // 0x2e
        {"CPL",                     0, 1, CPL},       // 0x2f
        {"JR NC, 0x%02X",           1, 2, JRNCn},     // 0x30
        {"LD SP, 0x%04X",           2, 3, LDSPnn},    // 0x31
        {"LDD (HL), A",             0, 2, LDHLDA},    // 0x32
        {"INC SP",                  0, 2, INCSP},     // 0x33
        {"INC (HL)",                0, 3, INCHLm},    // 0x34
        {"DEC (HL)",                0, 3, DECHLm},    // 0x35
        {"LD (HL), 0x%02X",         1, 3, LDHLmn},    // 0x36
        {"SCF",                     0, 1, SCF},       // 0x37
        {"JR C, 0x%02X",            1, 2, JRCn},      // 0x38
        {"ADD HL, SP",              0, 2, ADDHLSP},   // 0x39
        {"LDD A, (HL)",             0, 2, LDAHLD},    // 0x3a
        {"DEC SP",                  0, 2, DECSP},     // 0x3b
        {"INC A",                   0, 1, INCr_a},    // 0x3c
        {"DEC A",                   0, 1, DECr_a},    // 0x3d
        {"LD A, 0x%02X",            1, 2, LDrn_a},    // 0x3e
        {"CCF",                     0, 1, CCF},       // 0x3f
        {"LD B, B",                 0, 1, LDrr_bb},   // 0x40
        {"LD B, C",                 0, 1, LDrr_bc},   // 0x41
        {"LD B, D",                 0, 1, LDrr_bd},   // 0x42
        {"LD B, E",                 0, 1, LDrr_be},   // 0x43
        {"LD B, H",                 0, 1, LDrr_bh},   // 0x44
        {"LD B, L",                 0, 1, LDrr_bl},   // 0x45
        {"LD B, (HL)",              0, 2, LDrHLm_b},  // 0x46
        {"LD B, A",                 0, 1, LDrr_ba},   // 0x47
        {"LD C, B",                 0, 1, LDrr_cb},   // 0x48
        {"LD C, C",                 0, 1, LDrr_cc},   // 0x49
        {"LD C, D",                 0, 1, LDrr_cd},   // 0x4a
        {"LD C, E",                 0, 1, LDrr_ce},   // 0x4b
        {"LD C, H",                 0, 1, LDrr_ch},   // 0x4c
        {"LD C, L",                 0, 1, LDrr_cl},   // 0x4d
        {"LD C, (HL)",              0, 2, LDrHLm_c},  // 0x4e
        {"LD C, A",                 0, 1, LDrr_ca},   // 0x4f
        {"LD D, B",                 0, 1, LDrr_db},   // 0x50
        {"LD D, C",                 0, 1, LDrr_dc},   // 0x51
        {"LD D, D",                 0, 1, LDrr_dd},   // 0x52
        {"LD D, E",                 0, 1, LDrr_de},   // 0x53
        {"LD D, H",                 0, 1, LDrr_dh},   // 0x54
        {"LD D, L",                 0, 1, LDrr_dl},   // 0x55
        {"LD D, (HL)",              0, 2, LDrHLm_d},  // 0x56
        {"LD D, A",                 0, 1, LDrr_da},   // 0x57
        {"LD E, B",                 0, 1, LDrr_eb},   // 0x58
        {"LD E, C",                 0, 1, LDrr_ec},   // 0x59
        {"LD E, D",                 0, 1, LDrr_ed},   // 0x5a
        {"LD E, E",                 0, 1, LDrr_ee},   // 0x5b
        {"LD E, H",                 0, 1, LDrr_eh},   // 0x5c
        {"LD E, L",                 0, 1, LDrr_el},   // 0x5d
        {"LD E, (HL)",              0, 2, LDrHLm_e},  // 0x5e
        {"LD E, A",                 0, 1, LDrr_ea},   // 0x5f
        {"LD H, B",                 0, 1, LDrr_hb},   // 0x60
        {"LD H, C",                 0, 1, LDrr_hc},   // 0x61
        {"LD H, D",                 0, 1, LDrr_hd},   // 0x62
        {"LD H, E",                 0, 1, LDrr_he},   // 0x63
        {"LD H, H",                 0, 1, LDrr_hh},   // 0x64
        {"LD H, L",                 0, 1, LDrr_hl},   // 0x65
        {"LD H, (HL)",              0, 2, LDrHLm_h},  // 0x66
        {"LD H, A",                 0, 1, LDrr_ha},   // 0x67
        {"LD L, B",                 0, 1, LDrr_lb},   // 0x68
        {"LD L, C",                 0, 1, LDrr_lc},   // 0x69
        {"LD L, D",                 0, 1, LDrr_ld},   // 0x6a
        {"LD L, E",                 0, 1, LDrr_le},   // 0x6b
        {"LD L, H",                 0, 1, LDrr_lh},   // 0x6c
        {"LD L, L",                 0, 1, LDrr_ll},   // 0x6d
        {"LD L, (HL)",              0, 2, LDrHLm_l},  // 0x6e
        {"LD L, A",                 0, 1, LDrr_la},   // 0x6f
        {"LD (HL), B",              0, 2, LDHLmr_b},  // 0x70
        {"LD (HL), C",              0, 2, LDHLmr_c},  // 0x71
        {"LD (HL), D",              0, 2, LDHLmr_d},  // 0x72
        {"LD (HL), E",              0, 2, LDHLmr_e},  // 0x73
        {"LD (HL), H",              0, 2, LDHLmr_h},  // 0x74
        {"LD (HL), L",              0, 2, LDHLmr_l},  // 0x75
        {"HALT",                    0, 1, HALT},      // 0x76
        {"LD (HL), A",              0, 2, LDHLmr_a},  // 0x77
        {"LD A, B",                 0, 1, LDrr_ab},   // 0x78
        {"LD A, C",                 0, 1, LDrr_ac},   // 0x79
        {"LD A, D",                 0, 1, LDrr_ad},   // 0x7a
        {"LD A, E",                 0, 1, LDrr_ae},   // 0x7b
        {"LD A, H",                 0, 1, LDrr_ah},   // 0x7c
        {"LD A, L",                 0, 1, LDrr_al},   // 0x7d
        {"LD A, (HL)",              0, 2, LDrHLm_a},  // 0x7e
        {"LD A, A",                 0, 1, LDrr_aa},   // 0x7f
        {"ADD A, B",                0, 1, ADDr_b},    // 0x80
        {"ADD A, C",                0, 1, ADDr_c},    // 0x81
        {"ADD A, D",                0, 1, ADDr_d},    // 0x82
        {"ADD A, E",                0, 1, ADDr_e},    // 0x83
        {"ADD A, H",                0, 1, ADDr_h},    // 0x84
        {"ADD A, L",                0, 1, ADDr_l},    // 0x85
        {"ADD A, (HL)",             0, 2, ADDHL},     // 0x86
        {"ADD A",                   0, 1, ADDr_a},    // 0x87
        {"ADC B",                   0, 1, ADCr_b},    // 0x88
        {"ADC C",                   0, 1, ADCr_c},    // 0x89
        {"ADC D",                   0, 1, ADCr_d},    // 0x8a
        {"ADC E",                   0, 1, ADCr_e},    // 0x8b
        {"ADC H",                   0, 1, ADCr_h},    // 0x8c
        {"ADC L",                   0, 1, ADCr_l},    // 0x8d
        {"ADC (HL)",                0, 2, ADCHL},     // 0x8e
        {"ADC A",                   0, 1, ADCr_a},    // 0x8f
        {"SUB B",                   0, 1, SUBr_b},    // 0x90
        {"SUB C",                   0, 1, SUBr_c},    // 0x91
        {"SUB D",                   0, 1, SUBr_d},    // 0x92
        {"SUB E",                   0, 1, SUBr_e},    // 0x93
        {"SUB H",                   0, 1, SUBr_h},    // 0x94
        {"SUB L",                   0, 1, SUBr_l},    // 0x95
        {"SUB (HL)",                0, 2, SUBHL},     // 0x96
        {"SUB A",                   0, 1, SUBr_a},    // 0x97
        {"SBC B",                   0, 1, SBCr_b},    // 0x98
        {"SBC C",                   0, 1, SBCr_c},    // 0x99
        {"SBC D",                   0, 1, SBCr_d},    // 0x9a
        {"SBC E",                   0, 1, SBCr_e},    // 0x9b
        {"SBC H",                   0, 1, SBCr_h},    // 0x9c
        {"SBC L",                   0, 1, SBCr_l},    // 0x9d
        {"SBC (HL)",                0, 2, SBCHL},     // 0x9e
        {"SBC A",                   0, 1, SBCr_a},    // 0x9f
        {"AND B",                   0, 1, ANDr_b},    // 0xa0
        {"AND C",                   0, 1, ANDr_c},    // 0xa1
        {"AND D",                   0, 1, ANDr_d},    // 0xa2
        {"AND E",                   0, 1, ANDr_e},    // 0xa3
        {"AND H",                   0, 1, ANDr_h},    // 0xa4
        {"AND L",                   0, 1, ANDr_l},    // 0xa5
        {"AND (HL)",                0, 2, ANDHL},     // 0xa6
        {"AND A",                   0, 1, ANDr_a},    // 0xa7
        {"XOR B",                   0, 1, XORr_b},    // 0xa8
        {"XOR C",                   0, 1, XORr_c},    // 0xa9
        {"XOR D",                   0, 1, XORr_d},    // 0xaa
        {"XOR E",                   0, 1, XORr_e},    // 0xab
        {"XOR H",                   0, 1, XORr_h},    // 0xac
        {"XOR L",                   0, 1, XORr_l},    // 0xad
        {"XOR (HL)",                0, 2, XORHL},     // 0xae
        {"XOR A",                   0, 1, XORr_a},    // 0xaf
        {"OR B",                    0, 1, ORr_b},     // 0xb0
        {"OR C",                    0, 1, ORr_c},     // 0xb1
        {"OR D",                    0, 1, ORr_d},     // 0xb2
        {"OR E",                    0, 1, ORr_e},     // 0xb3
        {"OR H",                    0, 1, ORr_h},     // 0xb4
        {"OR L",                    0, 1, ORr_l},     // 0xb5
        {"OR (HL)",                 0, 2, ORHL},      // 0xb6
        {"OR A",                    0, 1, ORr_a},     // 0xb7
        {"CP B",                    0, 1, CPr_b},     // 0xb8
        {"CP C",                    0, 1, CPr_c},     // 0xb9
        {"CP D",                    0, 1, CPr_d},     // 0xba
        {"CP E",                    0, 1, CPr_e},     // 0xbb
        {"CP H",                    0, 1, CPr_h},     // 0xbc
        {"CP L",                    0, 1, CPr_l},     // 0xbd
        {"CP (HL)",                 0, 2, CPHL},      // 0xbe
        {"CP A",                    0, 1, CPr_a},     // 0xbf
        {"RET NZ",                  0, 2, RETNZ},     // 0xc0
        {"POP BC",                  0, 3, POPBC},     // 0xc1
        {"JP NZ, 0x%04X",           2, 3, JPNZnn},    // 0xc2
        {"JP 0x%04X",               2, 4, JPnn},      // 0xc3
        {"CALL NZ, 0x%04X",         2, 3, CALLNZnn},  // 0xc4
        {"PUSH BC",                 0, 4, PUSHBC},    // 0xc5
        {"ADD A, 0x%02X",           1, 2, ADDn},      // 0xc6
        {"RST 0x00",                0, 4, RST00},     // 0xc7
        {"RET Z",                   0, 2, RETZ},      // 0xc8
        {"RET",                     0, 4, RET},       // 0xc9
        {"JP Z, 0x%04X",            2, 3, JPZnn},     // 0xca
        {"CB %s",                   1, 1, MAPcb},     // 0xcb
        {"CALL Z, 0x%04X",          2, 3, CALLZnn},   // 0xcc
        {"CALL 0x%04X",             2, 6, CALLnn},    // 0xcd
        {"ADC 0x%02X",              1, 2, ADCn},      // 0xce
        {"RST 0x08",                0, 4, RST08},     // 0xcf
        {"RET NC",                  0, 2, RETNC},     // 0xd0
        {"POP DE",                  0, 3, POPDE},     // 0xd1
        {"JP NC, 0x%04X",           2, 3, JPNCnn},    // 0xd2
        {"UNKNOWN",                 0, 0, XX},        // 0xd3
        {"CALL NC, 0x%04X",         2, 3, CALLNCnn},  // 0xd4
        {"PUSH DE",                 0, 4, PUSHDE},    // 0xd5
        {"SUB 0x%02X",              1, 2, SUBn},      // 0xd6
        {"RST 0x10",                0, 4, RST10},     // 0xd7
        {"RET C",                   0, 2, RETC},      // 0xd8
        {"RETI",                    0, 4, RETI},      // 0xd9
        {"JP C, 0x%04X",            2, 3, JPCnn},     // 0xda
        {"UNKNOWN",                 0, 0, XX},        // 0xdb
        {"CALL C, 0x%04X",          2, 3, CALLCnn},  // 0xdc
        {"UNKNOWN",                 0, 0, XX},        // 0xdd
        {"SBC 0x%02X",              1, 2, SBCn},      // 0xde
        {"RST 0x18",                0, 4, RST18},     // 0xdf
        {"LD (0xFF00 + 0x%02X), A", 1, 3, LDIOnA},    // 0xe0
        {"POP HL",                  0, 3, POPHL},     // 0xe1
        {"LD (0xFF00 + C), A",      0, 2, LDIOCA},    // 0xe2
        {"UNKNOWN",                 0, 0, XX},        // 0xe3
        {"UNKNOWN",                 0, 0, XX},        // 0xe4
        {"PUSH HL",                 0, 4, PUSHHL},    // 0xe5
        {"AND 0x%02X",              1, 2, ANDn},      // 0xe6
        {"RST 0x20",                0, 4, RST20},     // 0xe7
        {"ADD SP,0x%02X",           1, 4, ADDSPn},    // 0xe8
        {"JP HL",                   0, 1, JPHL},      // 0xe9
        {"LD (0x%04X), A",          2, 4, LDmmA},     // 0xea
        {"UNKNOWN",                 0, 0, XX},        // 0xeb
        {"UNKNOWN",                 0, 0, XX},        // 0xec
        {"UNKNOWN",                 0, 0, XX},        // 0xed
        {"XOR 0x%02X",              1, 2, XORn},      // 0xee
        {"RST 0x28",                0, 4, RST28},     // 0xef
        {"LD A, (0xFF00 + 0x%02X)", 1, 3, LDAIOn},    // 0xf0
        {"POP AF",                  0, 3, POPAF},     // 0xf1
        {"LD A, (0xFF00 + C)",      0, 2, LDAIOC},    // 0xf2
        {"DI",                      0, 1, DI},        // 0xf3
        {"UNKNOWN",                 0, 0, XX},        // 0xf4
        {"PUSH AF",                 0, 4, PUSHAF},    // 0xf5
        {"OR 0x%02X",               1, 2, ORn},       // 0xf6
        {"RST 0x30",                0, 4, RST30},     // 0xf7
        {"LD HL, SP+0x%02X",        1, 3, LDHLSPn},   // 0xf8
        {"LD SP, HL",               0, 2, LDSPHL},    // 0xf9
        {"LD A, (0x%04X)",          2, 4, LDAmm},     // 0xfa
        {"EI",                      0, 1, EI},        // 0xfb
        {"UNKNOWN",                 0, 0, XX},        // 0xfc
        {"UNKNOWN",                 0, 0, XX},        // 0xfd
        {"CP 0x%02X",               1, 2, CPn},       // 0xfe
        {"RST 0x38",                0, 4, RST38},     // 0xff
};

Emu::Cpu::Ops::Op Emu::Cpu::Ops::cbTable[256] = {
        {"RLC B",       0, 2, RLCr_b},     // 0x00
        {"RLC C",       0, 2, RLCr_c},     // 0x01
        {"RLC D",       0, 2, RLCr_d},     // 0x02
        {"RLC E",       0, 2, RLCr_e},     // 0x03
        {"RLC H",       0, 2, RLCr_h},     // 0x04
        {"RLC L",       0, 2, RLCr_l},     // 0x05
        {"RLC (HL)",    0, 4, RLCHL},      // 0x06
        {"RLC A",       0, 2, RLCr_a},     // 0x07
        {"RRC B",       0, 2, RRCr_b},     // 0x08
        {"RRC C",       0, 2, RRCr_c},     // 0x09
        {"RRC D",       0, 2, RRCr_d},     // 0x0a
        {"RRC E",       0, 2, RRCr_e},     // 0x0b
        {"RRC H",       0, 2, RRCr_h},     // 0x0c
        {"RRC L",       0, 2, RRCr_l},     // 0x0d
        {"RRC (HL)",    0, 4, RRCHL},      // 0x0e
        {"RRC A",       0, 2, RRCr_a},     // 0x0f
        {"RL B",        0, 2, RLr_b},      // 0x10
        {"RL C",        0, 2, RLr_c},      // 0x11
        {"RL D",        0, 2, RLr_d},      // 0x12
        {"RL E",        0, 2, RLr_e},      // 0x13
        {"RL H",        0, 2, RLr_h},      // 0x14
        {"RL L",        0, 2, RLr_l},      // 0x15
        {"RL (HL)",     0, 4, RLHL},       // 0x16
        {"RL A",        0, 2, RLr_a},      // 0x17
        {"RR B",        0, 2, RRr_b},      // 0x18
        {"RR C",        0, 2, RRr_c},      // 0x19
        {"RR D",        0, 2, RRr_d},      // 0x1a
        {"RR E",        0, 2, RRr_e},      // 0x1b
        {"RR H",        0, 2, RRr_h},      // 0x1c
        {"RR L",        0, 2, RRr_l},      // 0x1d
        {"RR (HL)",     0, 4, RRHL},       // 0x1e
        {"RR A",        0, 2, RRr_a},      // 0x1f
        {"SLA B",       0, 2, SLAr_b},     // 0x20
        {"SLA C",       0, 2, SLAr_c},     // 0x21
        {"SLA D",       0, 2, SLAr_d},     // 0x22
        {"SLA E",       0, 2, SLAr_e},     // 0x23
        {"SLA H",       0, 2, SLAr_h},     // 0x24
        {"SLA L",       0, 2, SLAr_l},     // 0x25
        {"SLA (HL)",    0, 4, SLAHL},      // 0x26
        {"SLA A",       0, 2, SLAr_a},     // 0x27
        {"SRA B",       0, 2, SRAr_b},     // 0x28
        {"SRA C",       0, 2, SRAr_c},     // 0x29
        {"SRA D",       0, 2, SRAr_d},     // 0x2a
        {"SRA E",       0, 2, SRAr_e},     // 0x2b
        {"SRA H",       0, 2, SRAr_h},     // 0x2c
        {"SRA L",       0, 2, SRAr_l},     // 0x2d
        {"SRA (HL)",    0, 4, SRAHL},      // 0x2e
        {"SRA A",       0, 2, SRAr_a},     // 0x2f
        {"SWAP B",      0, 2, SWAPr_b},    // 0x30
        {"SWAP C",      0, 2, SWAPr_c},    // 0x31
        {"SWAP D",      0, 2, SWAPr_d},    // 0x32
        {"SWAP E",      0, 2, SWAPr_e},    // 0x33
        {"SWAP H",      0, 2, SWAPr_h},    // 0x34
        {"SWAP L",      0, 2, SWAPr_l},    // 0x35
        {"SWAP (HL)",   0, 4, SWAPHL},     // 0x36
        {"SWAP A",      0, 2, SWAPr_a},    // 0x37
        {"SRL B",       0, 2, SRLr_b},     // 0x38
        {"SRL C",       0, 2, SRLr_c},     // 0x39
        {"SRL D",       0, 2, SRLr_d},     // 0x3a
        {"SRL E",       0, 2, SRLr_e},     // 0x3b
        {"SRL H",       0, 2, SRLr_h},     // 0x3c
        {"SRL L",       0, 2, SRLr_l},     // 0x3d
        {"SRL (HL)",    0, 4, SRLHL},      // 0x3e
        {"SRL A",       0, 2, SRLr_a},     // 0x3f
        {"BIT 0, B",    0, 2, BIT0b},      // 0x40
        {"BIT 0, C",    0, 2, BIT0c},      // 0x41
        {"BIT 0, D",    0, 2, BIT0d},      // 0x42
        {"BIT 0, E",    0, 2, BIT0e},      // 0x43
        {"BIT 0, H",    0, 2, BIT0h},      // 0x44
        {"BIT 0, L",    0, 2, BIT0l},      // 0x45
        {"BIT 0, (HL)", 0, 4, BIT0m},      // 0x46
        {"BIT 0, A",    0, 2, BIT0a},      // 0x47
        {"BIT 1, B",    0, 2, BIT1b},      // 0x48
        {"BIT 1, C",    0, 2, BIT1c},      // 0x49
        {"BIT 1, D",    0, 2, BIT1d},      // 0x4a
        {"BIT 1, E",    0, 2, BIT1e},      // 0x4b
        {"BIT 1, H",    0, 2, BIT1h},      // 0x4c
        {"BIT 1, L",    0, 2, BIT1l},      // 0x4d
        {"BIT 1, (HL)", 0, 4, BIT1m},      // 0x4e
        {"BIT 1, A",    0, 2, BIT1a},      // 0x4f
        {"BIT 2, B",    0, 2, BIT2b},      // 0x50
        {"BIT 2, C",    0, 2, BIT2c},      // 0x51
        {"BIT 2, D",    0, 2, BIT2d},      // 0x52
        {"BIT 2, E",    0, 2, BIT2e},      // 0x53
        {"BIT 2, H",    0, 2, BIT2h},      // 0x54
        {"BIT 2, L",    0, 2, BIT2l},      // 0x55
        {"BIT 2, (HL)", 0, 4, BIT2m},      // 0x56
        {"BIT 2, A",    0, 2, BIT2a},      // 0x57
        {"BIT 3, B",    0, 2, BIT3b},      // 0x58
        {"BIT 3, C",    0, 2, BIT3c},      // 0x59
        {"BIT 3, D",    0, 2, BIT3d},      // 0x5a
        {"BIT 3, E",    0, 2, BIT3e},      // 0x5b
        {"BIT 3, H",    0, 2, BIT3h},      // 0x5c
        {"BIT 3, L",    0, 2, BIT3l},      // 0x5d
        {"BIT 3, (HL)", 0, 4, BIT3m},      // 0x5e
        {"BIT 3, A",    0, 2, BIT3a},      // 0x5f
        {"BIT 4, B",    0, 2, BIT4b},      // 0x60
        {"BIT 4, C",    0, 2, BIT4c},      // 0x61
        {"BIT 4, D",    0, 2, BIT4d},      // 0x62
        {"BIT 4, E",    0, 2, BIT4e},      // 0x63
        {"BIT 4, H",    0, 2, BIT4h},      // 0x64
        {"BIT 4, L",    0, 2, BIT4l},      // 0x65
        {"BIT 4, (HL)", 0, 4, BIT4m},      // 0x66
        {"BIT 4, A",    0, 2, BIT4a},      // 0x67
        {"BIT 5, B",    0, 2, BIT5b},      // 0x68
        {"BIT 5, C",    0, 2, BIT5c},      // 0x69
        {"BIT 5, D",    0, 2, BIT5d},      // 0x6a
        {"BIT 5, E",    0, 2, BIT5e},      // 0x6b
        {"BIT 6, H",    0, 2, BIT5h},      // 0x6c
        {"BIT 6, L",    0, 2, BIT5l},      // 0x6d
        {"BIT 5, (HL)", 0, 4, BIT5m},      // 0x6e
        {"BIT 5, A",    0, 2, BIT5a},      // 0x6f
        {"BIT 6, B",    0, 2, BIT6b},      // 0x70
        {"BIT 6, C",    0, 2, BIT6c},      // 0x71
        {"BIT 6, D",    0, 2, BIT6d},      // 0x72
        {"BIT 6, E",    0, 2, BIT6e},      // 0x73
        {"BIT 6, H",    0, 2, BIT6h},      // 0x74
        {"BIT 6, L",    0, 2, BIT6l},      // 0x75
        {"BIT 6, (HL)", 0, 4, BIT6m},      // 0x76
        {"BIT 6, A",    0, 2, BIT6a},      // 0x77
        {"BIT 7, B",    0, 2, BIT7b},      // 0x78
        {"BIT 7, C",    0, 2, BIT7c},      // 0x79
        {"BIT 7, D",    0, 2, BIT7d},      // 0x7a
        {"BIT 7, E",    0, 2, BIT7e},      // 0x7b
        {"BIT 7, H",    0, 2, BIT7h},      // 0x7c
        {"BIT 7, L",    0, 2, BIT7l},      // 0x7d
        {"BIT 7, (HL)", 0, 4, BIT7m},      // 0x7e
        {"BIT 7, A",    0, 2, BIT7a},      // 0x7f
        {"RES 0, B",    0, 2, RES0b},      // 0x80
        {"RES 0, C",    0, 2, RES0c},      // 0x81
        {"RES 0, D",    0, 2, RES0d},      // 0x82
        {"RES 0, E",    0, 2, RES0e},      // 0x83
        {"RES 0, H",    0, 2, RES0h},      // 0x84
        {"RES 0, L",    0, 2, RES0l},      // 0x85
        {"RES 0, (HL)", 0, 4, RES0m},      // 0x86
        {"RES 0, A",    0, 2, RES0a},      // 0x87
        {"RES 1, B",    0, 2, RES1b},      // 0x88
        {"RES 1, C",    0, 2, RES1c},      // 0x89
        {"RES 1, D",    0, 2, RES1d},      // 0x8a
        {"RES 1, E",    0, 2, RES1e},      // 0x8b
        {"RES 1, H",    0, 2, RES1h},      // 0x8c
        {"RES 1, L",    0, 2, RES1l},      // 0x8d
        {"RES 1, (HL)", 0, 4, RES1m},      // 0x8e
        {"RES 1, A",    0, 2, RES1a},      // 0x8f
        {"RES 2, B",    0, 2, RES2b},      // 0x90
        {"RES 2, C",    0, 2, RES2c},      // 0x91
        {"RES 2, D",    0, 2, RES2d},      // 0x92
        {"RES 2, E",    0, 2, RES2e},      // 0x93
        {"RES 2, H",    0, 2, RES2h},      // 0x94
        {"RES 2, L",    0, 2, RES2l},      // 0x95
        {"RES 2, (HL)", 0, 4, RES2m},      // 0x96
        {"RES 2, A",    0, 2, RES2a},      // 0x97
        {"RES 3, B",    0, 2, RES3b},      // 0x98
        {"RES 3, C",    0, 2, RES3c},      // 0x99
        {"RES 3, D",    0, 2, RES3d},      // 0x9a
        {"RES 3, E",    0, 2, RES3e},      // 0x9b
        {"RES 3, H",    0, 2, RES3h},      // 0x9c
        {"RES 3, L",    0, 2, RES3l},      // 0x9d
        {"RES 3, (HL)", 0, 4, RES3m},      // 0x9e
        {"RES 3, A",    0, 2, RES3a},      // 0x9f
        {"RES 4, B",    0, 2, RES4b},      // 0xa0
        {"RES 4, C",    0, 2, RES4c},      // 0xa1
        {"RES 4, D",    0, 2, RES4d},      // 0xa2
        {"RES 4, E",    0, 2, RES4e},      // 0xa3
        {"RES 4, H",    0, 2, RES4h},      // 0xa4
        {"RES 4, L",    0, 2, RES4l},      // 0xa5
        {"RES 4, (HL)", 0, 4, RES4m},      // 0xa6
        {"RES 4, A",    0, 2, RES4a},      // 0xa7
        {"RES 5, B",    0, 2, RES5b},      // 0xa8
        {"RES 5, C",    0, 2, RES5c},      // 0xa9
        {"RES 5, D",    0, 2, RES5d},      // 0xaa
        {"RES 5, E",    0, 2, RES5e},      // 0xab
        {"RES 5, H",    0, 2, RES5h},      // 0xac
        {"RES 5, L",    0, 2, RES5l},      // 0xad
        {"RES 5, (HL)", 0, 4, RES5m},      // 0xae
        {"RES 5, A",    0, 2, RES5a},      // 0xaf
        {"RES 6, B",    0, 2, RES6b},      // 0xb0
        {"RES 6, C",    0, 2, RES6c},      // 0xb1
        {"RES 6, D",    0, 2, RES6d},      // 0xb2
        {"RES 6, E",    0, 2, RES6e},      // 0xb3
        {"RES 6, H",    0, 2, RES6h},      // 0xb4
        {"RES 6, L",    0, 2, RES6l},      // 0xb5
        {"RES 6, (HL)", 0, 4, RES6m},      // 0xb6
        {"RES 6, A",    0, 2, RES6a},      // 0xb7
        {"RES 7, B",    0, 2, RES7b},      // 0xb8
        {"RES 7, C",    0, 2, RES7c},      // 0xb9
        {"RES 7, D",    0, 2, RES7d},      // 0xba
        {"RES 7, E",    0, 2, RES7e},      // 0xbb
        {"RES 7, H",    0, 2, RES7h},      // 0xbc
        {"RES 7, L",    0, 2, RES7l},      // 0xbd
        {"RES 7, (HL)", 0, 4, RES7m},      // 0xbe
        {"RES 7, A",    0, 2, RES7a},      // 0xbf
        {"SET 0, B",    0, 2, SET0b},      // 0xc0
        {"SET 0, C",    0, 2, SET0c},      // 0xc1
        {"SET 0, D",    0, 2, SET0d},      // 0xc2
        {"SET 0, E",    0, 2, SET0e},      // 0xc3
        {"SET 0, H",    0, 2, SET0h},      // 0xc4
        {"SET 0, L",    0, 2, SET0l},      // 0xc5
        {"SET 0, (HL)", 0, 4, SET0m},      // 0xc6
        {"SET 0, A",    0, 2, SET0a},      // 0xc7
        {"SET 1, B",    0, 2, SET1b},      // 0xc8
        {"SET 1, C",    0, 2, SET1c},      // 0xc9
        {"SET 1, D",    0, 2, SET1d},      // 0xca
        {"SET 1, E",    0, 2, SET1e},      // 0xcb
        {"SET 1, H",    0, 2, SET1h},      // 0xcc
        {"SET 1, L",    0, 2, SET1l},      // 0xcd
        {"SET 1, (HL)", 0, 4, SET1m},      // 0xce
        {"SET 1, A",    0, 2, SET1a},      // 0xcf
        {"SET 2, B",    0, 2, SET2b},      // 0xd0
        {"SET 2, C",    0, 2, SET2c},      // 0xd1
        {"SET 2, D",    0, 2, SET2d},      // 0xd2
        {"SET 2, E",    0, 2, SET2e},      // 0xd3
        {"SET 2, H",    0, 2, SET2h},      // 0xd4
        {"SET 2, L",    0, 2, SET2l},      // 0xd5
        {"SET 2, (HL)", 0, 4, SET2m},      // 0xd6
        {"SET 2, A",    0, 2, SET2a},      // 0xd7
        {"SET 3, B",    0, 2, SET3b},      // 0xd8
        {"SET 3, C",    0, 2, SET3c},      // 0xd9
        {"SET 3, D",    0, 2, SET3d},      // 0xda
        {"SET 3, E",    0, 2, SET3e},      // 0xdb
        {"SET 3, H",    0, 2, SET3h},      // 0xdc
        {"SET 3, L",    0, 2, SET3l},      // 0xdd
        {"SET 3, (HL)", 0, 4, SET3m},      // 0xde
        {"SET 3, A",    0, 2, SET3a},      // 0xdf
        {"SET 4, B",    0, 2, SET4b},      // 0xe0
        {"SET 4, C",    0, 2, SET4c},      // 0xe1
        {"SET 4, D",    0, 2, SET4d},      // 0xe2
        {"SET 4, E",    0, 2, SET4e},      // 0xe3
        {"SET 4, H",    0, 2, SET4h},      // 0xe4
        {"SET 4, L",    0, 2, SET4l},      // 0xe5
        {"SET 4, (HL)", 0, 4, SET4m},      // 0xe6
        {"SET 4, A",    0, 2, SET4a},      // 0xe7
        {"SET 5, B",    0, 2, SET5b},      // 0xe8
        {"SET 5, C",    0, 2, SET5c},      // 0xe9
        {"SET 5, D",    0, 2, SET5d},      // 0xea
        {"SET 5, E",    0, 2, SET5e},      // 0xeb
        {"SET 5, H",    0, 2, SET5h},      // 0xec
        {"SET 5, L",    0, 2, SET5l},      // 0xed
        {"SET 5, (HL)", 0, 4, SET5m},      // 0xee
        {"SET 5, A",    0, 2, SET5a},      // 0xef
        {"SET 6, B",    0, 2, SET6b},      // 0xf0
        {"SET 6, C",    0, 2, SET6c},      // 0xf1
        {"SET 6, D",    0, 2, SET6d},      // 0xf2
        {"SET 6, E",    0, 2, SET6e},      // 0xf3
        {"SET 6, H",    0, 2, SET6h},      // 0xf4
        {"SET 6, L",    0, 2, SET6l},      // 0xf5
        {"SET 6, (HL)", 0, 4, SET6m},      // 0xf6
        {"SET 6, A",    0, 2, SET6a},      // 0xf7
        {"SET 7, B",    0, 2, SET7b},      // 0xf8
        {"SET 7, C",    0, 2, SET7c},      // 0xf9
        {"SET 7, D",    0, 2, SET7d},      // 0xfa
        {"SET 7, E",    0, 2, SET7e},      // 0xfb
        {"SET 7, H",    0, 2, SET7h},      // 0xfc
        {"SET 7, L",    0, 2, SET7l},      // 0xfd
        {"SET 7, (HL)", 0, 4, SET7m},      // 0xfe
        {"SET 7, A",    0, 2, SET7a},      // 0xff
};

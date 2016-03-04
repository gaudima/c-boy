//
// Created by gaudima on 21.01.2016.
//

#ifndef C_BOY_OPS_H
#define C_BOY_OPS_H

#include "cpu.h"

class Emu::Cpu::Ops {
public:
    struct Op {
        std::string desc;
        uint8_t argsize;
        uint8_t m;

        void (*pf)(uint16_t);
    };

    static Op opTable[256];
    static Op cbTable[256];
    static Emu *emu;
//private:
    enum FlagType {
        Zero = 0x80,
        Neg = 0x40,
        HCarry = 0x20,
        Carry = 0x10
    };

    static void setF(FlagType flag, bool set);

    static bool isSetF(FlagType flag);

    static void resetF();

    static void LDrr(uint8_t &a, uint8_t b);

    static void LDrr_bb(uint16_t arg);

    static void LDrr_bc(uint16_t arg);

    static void LDrr_bd(uint16_t arg);

    static void LDrr_be(uint16_t arg);

    static void LDrr_bh(uint16_t arg);

    static void LDrr_bl(uint16_t arg);

    static void LDrr_ba(uint16_t arg);

    static void LDrr_cb(uint16_t arg);

    static void LDrr_cc(uint16_t arg);

    static void LDrr_cd(uint16_t arg);

    static void LDrr_ce(uint16_t arg);

    static void LDrr_ch(uint16_t arg);

    static void LDrr_cl(uint16_t arg);

    static void LDrr_ca(uint16_t arg);

    static void LDrr_db(uint16_t arg);

    static void LDrr_dc(uint16_t arg);

    static void LDrr_dd(uint16_t arg);

    static void LDrr_de(uint16_t arg);

    static void LDrr_dh(uint16_t arg);

    static void LDrr_dl(uint16_t arg);

    static void LDrr_da(uint16_t arg);

    static void LDrr_eb(uint16_t arg);

    static void LDrr_ec(uint16_t arg);

    static void LDrr_ed(uint16_t arg);

    static void LDrr_ee(uint16_t arg);

    static void LDrr_eh(uint16_t arg);

    static void LDrr_el(uint16_t arg);

    static void LDrr_ea(uint16_t arg);

    static void LDrr_hb(uint16_t arg);

    static void LDrr_hc(uint16_t arg);

    static void LDrr_hd(uint16_t arg);

    static void LDrr_he(uint16_t arg);

    static void LDrr_hh(uint16_t arg);

    static void LDrr_hl(uint16_t arg);

    static void LDrr_ha(uint16_t arg);

    static void LDrr_lb(uint16_t arg);

    static void LDrr_lc(uint16_t arg);

    static void LDrr_ld(uint16_t arg);

    static void LDrr_le(uint16_t arg);

    static void LDrr_lh(uint16_t arg);

    static void LDrr_ll(uint16_t arg);

    static void LDrr_la(uint16_t arg);

    static void LDrr_ab(uint16_t arg);

    static void LDrr_ac(uint16_t arg);

    static void LDrr_ad(uint16_t arg);

    static void LDrr_ae(uint16_t arg);

    static void LDrr_ah(uint16_t arg);

    static void LDrr_al(uint16_t arg);

    static void LDrr_aa(uint16_t arg);

    static void LDrHLm(uint8_t &a);

    static void LDrHLm_b(uint16_t arg);

    static void LDrHLm_c(uint16_t arg);

    static void LDrHLm_d(uint16_t arg);

    static void LDrHLm_e(uint16_t arg);

    static void LDrHLm_h(uint16_t arg);

    static void LDrHLm_l(uint16_t arg);

    static void LDrHLm_a(uint16_t arg);

    static void LDHLmr(uint8_t a);

    static void LDHLmr_b(uint16_t arg);

    static void LDHLmr_c(uint16_t arg);

    static void LDHLmr_d(uint16_t arg);

    static void LDHLmr_e(uint16_t arg);

    static void LDHLmr_h(uint16_t arg);

    static void LDHLmr_l(uint16_t arg);

    static void LDHLmr_a(uint16_t arg);

    static void LDrn(uint8_t &a, uint8_t arg);

    static void LDrn_b(uint16_t arg);

    static void LDrn_c(uint16_t arg);

    static void LDrn_d(uint16_t arg);

    static void LDrn_e(uint16_t arg);

    static void LDrn_h(uint16_t arg);

    static void LDrn_l(uint16_t arg);

    static void LDrn_a(uint16_t arg);

    static void LDHLmn(uint16_t arg);

    static void LDBCmA(uint16_t arg);

    static void LDDEmA(uint16_t arg);

    static void LDmmA(uint16_t arg);

    static void LDABCm(uint16_t arg);

    static void LDADEm(uint16_t arg);

    static void LDAmm(uint16_t arg);

    static void LDnn(uint16_t &a, uint16_t arg);

    static void LDBCnn(uint16_t arg);

    static void LDDEnn(uint16_t arg);

    static void LDHLnn(uint16_t arg);

    static void LDSPnn(uint16_t arg);

    static void LDHLmm(uint16_t arg);

    static void LDmmHL(uint16_t arg);

    static void LDmmSP(uint16_t arg);

    static void LDSPHL(uint16_t arg);

    static void LDHLIA(uint16_t arg);

    static void LDAHLI(uint16_t arg);

    static void LDHLDA(uint16_t arg);

    static void LDAHLD(uint16_t arg);

    static void LDAIOn(uint16_t arg);

    static void LDIOnA(uint16_t arg);

    static void LDAIOC(uint16_t arg);

    static void LDIOCA(uint16_t arg);

    static void LDHLSPn(uint16_t arg);

    static void SWAPr(uint8_t &a);

    static void SWAPr_b(uint16_t arg);

    static void SWAPr_c(uint16_t arg);

    static void SWAPr_d(uint16_t arg);

    static void SWAPr_e(uint16_t arg);

    static void SWAPr_h(uint16_t arg);

    static void SWAPr_l(uint16_t arg);

    static void SWAPr_a(uint16_t arg);

    static void SWAPHL(uint16_t arg);

/*--- Data processing ---*/
    static void ADD(uint8_t &a, uint8_t b);

    static void ADDr_b(uint16_t arg);

    static void ADDr_c(uint16_t arg);

    static void ADDr_d(uint16_t arg);

    static void ADDr_e(uint16_t arg);

    static void ADDr_h(uint16_t arg);

    static void ADDr_l(uint16_t arg);

    static void ADDr_a(uint16_t arg);

    static void ADDHL(uint16_t arg);

    static void ADDn(uint16_t arg);

    static void ADD(uint16_t &a, uint16_t b);

    static void ADDHLBC(uint16_t arg);

    static void ADDHLDE(uint16_t arg);

    static void ADDHLHL(uint16_t arg);

    static void ADDHLSP(uint16_t arg);

    static void ADDSPn(uint16_t arg);

    static void ADC(uint8_t &a, uint8_t b);

    static void ADCr_b(uint16_t arg);

    static void ADCr_c(uint16_t arg);

    static void ADCr_d(uint16_t arg);

    static void ADCr_e(uint16_t arg);

    static void ADCr_h(uint16_t arg);

    static void ADCr_l(uint16_t arg);

    static void ADCr_a(uint16_t arg);

    static void ADCHL(uint16_t arg);

    static void ADCn(uint16_t arg);

    static void SUB(uint8_t &a, uint8_t b);

    static void SUBr_b(uint16_t arg);

    static void SUBr_c(uint16_t arg);

    static void SUBr_d(uint16_t arg);

    static void SUBr_e(uint16_t arg);

    static void SUBr_h(uint16_t arg);

    static void SUBr_l(uint16_t arg);

    static void SUBr_a(uint16_t arg);

    static void SUBHL(uint16_t arg);

    static void SUBn(uint16_t arg);

    static void SBC(uint8_t &a, uint8_t b);

    static void SBCr_b(uint16_t arg);

    static void SBCr_c(uint16_t arg);

    static void SBCr_d(uint16_t arg);

    static void SBCr_e(uint16_t arg);

    static void SBCr_h(uint16_t arg);

    static void SBCr_l(uint16_t arg);

    static void SBCr_a(uint16_t arg);

    static void SBCHL(uint16_t arg);

    static void SBCn(uint16_t arg);

    static void CP(uint8_t &a, uint8_t b);

    static void CPr_b(uint16_t arg);

    static void CPr_c(uint16_t arg);

    static void CPr_d(uint16_t arg);

    static void CPr_e(uint16_t arg);

    static void CPr_h(uint16_t arg);

    static void CPr_l(uint16_t arg);

    static void CPr_a(uint16_t arg);

    static void CPHL(uint16_t arg);

    static void CPn(uint16_t arg);

    static void DAA(uint16_t arg);

    static void ANDr(uint8_t &a, uint8_t b);

    static void ANDr_b(uint16_t arg);

    static void ANDr_c(uint16_t arg);

    static void ANDr_d(uint16_t arg);

    static void ANDr_e(uint16_t arg);

    static void ANDr_h(uint16_t arg);

    static void ANDr_l(uint16_t arg);

    static void ANDr_a(uint16_t arg);

    static void ANDHL(uint16_t arg);

    static void ANDn(uint16_t arg);

    static void ORr(uint8_t &a, uint8_t b);

    static void ORr_b(uint16_t arg);

    static void ORr_c(uint16_t arg);

    static void ORr_d(uint16_t arg);

    static void ORr_e(uint16_t arg);

    static void ORr_h(uint16_t arg);

    static void ORr_l(uint16_t arg);

    static void ORr_a(uint16_t arg);

    static void ORHL(uint16_t arg);

    static void ORn(uint16_t arg);

    static void XORr(uint8_t &a, uint8_t b);

    static void XORr_b(uint16_t arg);

    static void XORr_c(uint16_t arg);

    static void XORr_d(uint16_t arg);

    static void XORr_e(uint16_t arg);

    static void XORr_h(uint16_t arg);

    static void XORr_l(uint16_t arg);

    static void XORr_a(uint16_t arg);

    static void XORHL(uint16_t arg);

    static void XORn(uint16_t arg);

    static void INCr(uint8_t &a);

    static void INCr_b(uint16_t arg);

    static void INCr_c(uint16_t arg);

    static void INCr_d(uint16_t arg);

    static void INCr_e(uint16_t arg);

    static void INCr_h(uint16_t arg);

    static void INCr_l(uint16_t arg);

    static void INCr_a(uint16_t arg);

    static void INCHLm(uint16_t arg);

    static void DECr(uint8_t &a);

    static void DECr_b(uint16_t arg);

    static void DECr_c(uint16_t arg);

    static void DECr_d(uint16_t arg);

    static void DECr_e(uint16_t arg);

    static void DECr_h(uint16_t arg);

    static void DECr_l(uint16_t arg);

    static void DECr_a(uint16_t arg);

    static void DECHLm(uint16_t arg);

    static void INC(uint16_t &a);

    static void INCBC(uint16_t arg);

    static void INCDE(uint16_t arg);

    static void INCHL(uint16_t arg);

    static void INCSP(uint16_t arg);

    static void DEC(uint16_t &a);

    static void DECBC(uint16_t arg);

    static void DECDE(uint16_t arg);

    static void DECHL(uint16_t arg);

    static void DECSP(uint16_t arg);

/*--- Bit manipulation ---*/
    static void BIT(uint8_t bit, uint8_t &a);

    static void RES(uint8_t bit, uint8_t &a);

    static void SET(uint8_t bit, uint8_t &a);

    static void RES(uint8_t bit, uint16_t addr);

    static void SET(uint8_t bit, uint16_t addr);

    static void BIT0b(uint16_t arg);

    static void BIT0c(uint16_t arg);

    static void BIT0d(uint16_t arg);

    static void BIT0e(uint16_t arg);

    static void BIT0h(uint16_t arg);

    static void BIT0l(uint16_t arg);

    static void BIT0a(uint16_t arg);

    static void BIT0m(uint16_t arg);

    static void RES0b(uint16_t arg);

    static void RES0c(uint16_t arg);

    static void RES0d(uint16_t arg);

    static void RES0e(uint16_t arg);

    static void RES0h(uint16_t arg);

    static void RES0l(uint16_t arg);

    static void RES0a(uint16_t arg);

    static void RES0m(uint16_t arg);

    static void SET0b(uint16_t arg);

    static void SET0c(uint16_t arg);

    static void SET0d(uint16_t arg);

    static void SET0e(uint16_t arg);

    static void SET0h(uint16_t arg);

    static void SET0l(uint16_t arg);

    static void SET0a(uint16_t arg);

    static void SET0m(uint16_t arg);

    static void BIT1b(uint16_t arg);

    static void BIT1c(uint16_t arg);

    static void BIT1d(uint16_t arg);

    static void BIT1e(uint16_t arg);

    static void BIT1h(uint16_t arg);

    static void BIT1l(uint16_t arg);

    static void BIT1a(uint16_t arg);

    static void BIT1m(uint16_t arg);

    static void RES1b(uint16_t arg);

    static void RES1c(uint16_t arg);

    static void RES1d(uint16_t arg);

    static void RES1e(uint16_t arg);

    static void RES1h(uint16_t arg);

    static void RES1l(uint16_t arg);

    static void RES1a(uint16_t arg);

    static void RES1m(uint16_t arg);

    static void SET1b(uint16_t arg);

    static void SET1c(uint16_t arg);

    static void SET1d(uint16_t arg);

    static void SET1e(uint16_t arg);

    static void SET1h(uint16_t arg);

    static void SET1l(uint16_t arg);

    static void SET1a(uint16_t arg);

    static void SET1m(uint16_t arg);

    static void BIT2b(uint16_t arg);

    static void BIT2c(uint16_t arg);

    static void BIT2d(uint16_t arg);

    static void BIT2e(uint16_t arg);

    static void BIT2h(uint16_t arg);

    static void BIT2l(uint16_t arg);

    static void BIT2a(uint16_t arg);

    static void BIT2m(uint16_t arg);

    static void RES2b(uint16_t arg);

    static void RES2c(uint16_t arg);

    static void RES2d(uint16_t arg);

    static void RES2e(uint16_t arg);

    static void RES2h(uint16_t arg);

    static void RES2l(uint16_t arg);

    static void RES2a(uint16_t arg);

    static void RES2m(uint16_t arg);

    static void SET2b(uint16_t arg);

    static void SET2c(uint16_t arg);

    static void SET2d(uint16_t arg);

    static void SET2e(uint16_t arg);

    static void SET2h(uint16_t arg);

    static void SET2l(uint16_t arg);

    static void SET2a(uint16_t arg);

    static void SET2m(uint16_t arg);

    static void BIT3b(uint16_t arg);

    static void BIT3c(uint16_t arg);

    static void BIT3d(uint16_t arg);

    static void BIT3e(uint16_t arg);

    static void BIT3h(uint16_t arg);

    static void BIT3l(uint16_t arg);

    static void BIT3a(uint16_t arg);

    static void BIT3m(uint16_t arg);

    static void RES3b(uint16_t arg);

    static void RES3c(uint16_t arg);

    static void RES3d(uint16_t arg);

    static void RES3e(uint16_t arg);

    static void RES3h(uint16_t arg);

    static void RES3l(uint16_t arg);

    static void RES3a(uint16_t arg);

    static void RES3m(uint16_t arg);

    static void SET3b(uint16_t arg);

    static void SET3c(uint16_t arg);

    static void SET3d(uint16_t arg);

    static void SET3e(uint16_t arg);

    static void SET3h(uint16_t arg);

    static void SET3l(uint16_t arg);

    static void SET3a(uint16_t arg);

    static void SET3m(uint16_t arg);

    static void BIT4b(uint16_t arg);

    static void BIT4c(uint16_t arg);

    static void BIT4d(uint16_t arg);

    static void BIT4e(uint16_t arg);

    static void BIT4h(uint16_t arg);

    static void BIT4l(uint16_t arg);

    static void BIT4a(uint16_t arg);

    static void BIT4m(uint16_t arg);

    static void RES4b(uint16_t arg);

    static void RES4c(uint16_t arg);

    static void RES4d(uint16_t arg);

    static void RES4e(uint16_t arg);

    static void RES4h(uint16_t arg);

    static void RES4l(uint16_t arg);

    static void RES4a(uint16_t arg);

    static void RES4m(uint16_t arg);

    static void SET4b(uint16_t arg);

    static void SET4c(uint16_t arg);

    static void SET4d(uint16_t arg);

    static void SET4e(uint16_t arg);

    static void SET4h(uint16_t arg);

    static void SET4l(uint16_t arg);

    static void SET4a(uint16_t arg);

    static void SET4m(uint16_t arg);

    static void BIT5b(uint16_t arg);

    static void BIT5c(uint16_t arg);

    static void BIT5d(uint16_t arg);

    static void BIT5e(uint16_t arg);

    static void BIT5h(uint16_t arg);

    static void BIT5l(uint16_t arg);

    static void BIT5a(uint16_t arg);

    static void BIT5m(uint16_t arg);

    static void RES5b(uint16_t arg);

    static void RES5c(uint16_t arg);

    static void RES5d(uint16_t arg);

    static void RES5e(uint16_t arg);

    static void RES5h(uint16_t arg);

    static void RES5l(uint16_t arg);

    static void RES5a(uint16_t arg);

    static void RES5m(uint16_t arg);

    static void SET5b(uint16_t arg);

    static void SET5c(uint16_t arg);

    static void SET5d(uint16_t arg);

    static void SET5e(uint16_t arg);

    static void SET5h(uint16_t arg);

    static void SET5l(uint16_t arg);

    static void SET5a(uint16_t arg);

    static void SET5m(uint16_t arg);

    static void BIT6b(uint16_t arg);

    static void BIT6c(uint16_t arg);

    static void BIT6d(uint16_t arg);

    static void BIT6e(uint16_t arg);

    static void BIT6h(uint16_t arg);

    static void BIT6l(uint16_t arg);

    static void BIT6a(uint16_t arg);

    static void BIT6m(uint16_t arg);

    static void RES6b(uint16_t arg);

    static void RES6c(uint16_t arg);

    static void RES6d(uint16_t arg);

    static void RES6e(uint16_t arg);

    static void RES6h(uint16_t arg);

    static void RES6l(uint16_t arg);

    static void RES6a(uint16_t arg);

    static void RES6m(uint16_t arg);

    static void SET6b(uint16_t arg);

    static void SET6c(uint16_t arg);

    static void SET6d(uint16_t arg);

    static void SET6e(uint16_t arg);

    static void SET6h(uint16_t arg);

    static void SET6l(uint16_t arg);

    static void SET6a(uint16_t arg);

    static void SET6m(uint16_t arg);

    static void BIT7b(uint16_t arg);

    static void BIT7c(uint16_t arg);

    static void BIT7d(uint16_t arg);

    static void BIT7e(uint16_t arg);

    static void BIT7h(uint16_t arg);

    static void BIT7l(uint16_t arg);

    static void BIT7a(uint16_t arg);

    static void BIT7m(uint16_t arg);

    static void RES7b(uint16_t arg);

    static void RES7c(uint16_t arg);

    static void RES7d(uint16_t arg);

    static void RES7e(uint16_t arg);

    static void RES7h(uint16_t arg);

    static void RES7l(uint16_t arg);

    static void RES7a(uint16_t arg);

    static void RES7m(uint16_t arg);

    static void SET7b(uint16_t arg);

    static void SET7c(uint16_t arg);

    static void SET7d(uint16_t arg);

    static void SET7e(uint16_t arg);

    static void SET7h(uint16_t arg);

    static void SET7l(uint16_t arg);

    static void SET7a(uint16_t arg);

    static void SET7m(uint16_t arg);

    static void RLr(uint8_t &a);

    static void RRr(uint8_t &a);

    static void RLCr(uint8_t &a);

    static void RRCr(uint8_t &a);

    static void RLA(uint16_t arg);

    static void RLCA(uint16_t arg);

    static void RRA(uint16_t arg);

    static void RRCA(uint16_t arg);

    static void RLr_b(uint16_t arg);

    static void RLr_c(uint16_t arg);

    static void RLr_d(uint16_t arg);

    static void RLr_e(uint16_t arg);

    static void RLr_h(uint16_t arg);

    static void RLr_l(uint16_t arg);

    static void RLr_a(uint16_t arg);

    static void RLHL(uint16_t arg);

    static void RLCr_b(uint16_t arg);

    static void RLCr_c(uint16_t arg);

    static void RLCr_d(uint16_t arg);

    static void RLCr_e(uint16_t arg);

    static void RLCr_h(uint16_t arg);

    static void RLCr_l(uint16_t arg);

    static void RLCr_a(uint16_t arg);

    static void RLCHL(uint16_t arg);

    static void RRr_b(uint16_t arg);

    static void RRr_c(uint16_t arg);

    static void RRr_d(uint16_t arg);

    static void RRr_e(uint16_t arg);

    static void RRr_h(uint16_t arg);

    static void RRr_l(uint16_t arg);

    static void RRr_a(uint16_t arg);

    static void RRHL(uint16_t arg);

    static void RRCr_b(uint16_t arg);

    static void RRCr_c(uint16_t arg);

    static void RRCr_d(uint16_t arg);

    static void RRCr_e(uint16_t arg);

    static void RRCr_h(uint16_t arg);

    static void RRCr_l(uint16_t arg);

    static void RRCr_a(uint16_t arg);

    static void RRCHL(uint16_t arg);

    static void SLAr(uint8_t &a);

    static void SRAr(uint8_t &a);

    static void SRLr(uint8_t &a);

    static void SLAr_b(uint16_t arg);

    static void SLAr_c(uint16_t arg);

    static void SLAr_d(uint16_t arg);

    static void SLAr_e(uint16_t arg);

    static void SLAr_h(uint16_t arg);

    static void SLAr_l(uint16_t arg);

    static void SLAr_a(uint16_t arg);

    static void SLAHL(uint16_t arg);

    static void SRAr_b(uint16_t arg);

    static void SRAr_c(uint16_t arg);

    static void SRAr_d(uint16_t arg);

    static void SRAr_e(uint16_t arg);

    static void SRAr_h(uint16_t arg);

    static void SRAr_l(uint16_t arg);

    static void SRAr_a(uint16_t arg);

    static void SRAHL(uint16_t arg);

    static void SRLr_b(uint16_t arg);

    static void SRLr_c(uint16_t arg);

    static void SRLr_d(uint16_t arg);

    static void SRLr_e(uint16_t arg);

    static void SRLr_h(uint16_t arg);

    static void SRLr_l(uint16_t arg);

    static void SRLr_a(uint16_t arg);

    static void SRLHL(uint16_t arg);

    static void CPL(uint16_t arg);

    static void NEG(uint16_t arg);

    static void CCF(uint16_t arg);

    static void SCF(uint16_t arg);

/*--- Stack ---*/
    static void PUSH(uint16_t a);

    static void PUSHBC(uint16_t arg);

    static void PUSHDE(uint16_t arg);

    static void PUSHHL(uint16_t arg);

    static void PUSHAF(uint16_t arg);

    static void POP(uint16_t &a);

    static void POPBC(uint16_t arg);

    static void POPDE(uint16_t arg);

    static void POPHL(uint16_t arg);

    static void POPAF(uint16_t arg);

/*--- Jump ---*/
    static void JPnn(uint16_t arg);

    static void JPHL(uint16_t arg);

    static void JPNZnn(uint16_t arg);

    static void JPZnn(uint16_t arg);

    static void JPNCnn(uint16_t arg);

    static void JPCnn(uint16_t arg);

    static void JRn(uint16_t arg);

    static void JRNZn(uint16_t arg);

    static void JRZn(uint16_t arg);

    static void JRNCn(uint16_t arg);

    static void JRCn(uint16_t arg);

    static void DJNZn(uint16_t arg);

    static void CALLnn(uint16_t arg);

    static void CALLNZnn(uint16_t arg);

    static void CALLZnn(uint16_t arg);

    static void CALLNCnn(uint16_t arg);

    static void CALLCnn(uint16_t arg);

    static void RET(uint16_t arg);

    static void RETI(uint16_t arg);

    static void RETNZ(uint16_t arg);

    static void RETZ(uint16_t arg);

    static void RETNC(uint16_t arg);

    static void RETC(uint16_t arg);

    static void RST(uint8_t addr);

    static void RST00(uint16_t arg);

    static void RST08(uint16_t arg);

    static void RST10(uint16_t arg);

    static void RST18(uint16_t arg);

    static void RST20(uint16_t arg);

    static void RST28(uint16_t arg);

    static void RST30(uint16_t arg);

    static void RST38(uint16_t arg);

    static void NOP(uint16_t arg);

    static void EI(uint16_t arg);

    static void DI(uint16_t arg);

    static void HALT(uint16_t arg);

    static void STOP(uint16_t arg);

    static void MAPcb(uint16_t arg);

    static void XX(uint16_t arg);
};


#endif //C_BOY_OPS_H

#pragma GCC optimize ("O3")

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

using uint = unsigned int;

enum COND_TYPE {
    COND_NONE = 0,
    COND_PLUS,
    COND_MINUS
};

enum INST_CODE_TYPE {
    INST_ADD,           /* 000 */
    INST_ADD_IMM,       /* 001 */
    INST_SUB,           /* 002 */
    INST_CMPCM,         /* 003 */
    INST_OR,            /* 004 */
    INST_OR_IMM,        /* 005 */
    INST_XOR,           /* 006 */
    INST_XOR_IMM,       /* 007 */ 
    INST_AND,           /* 010 */
    INST_AND_IMM,       /* 011 */   
    INST_SFT_IMM,       /* 012 */
    INST_SHL,           /* 013 */
    INST_SHR,           /* 014 */
    INST_MEM_LD,        /* 015 */
    INST_MEM_STR,       /* 016 */
    INST_LBL,           /* 017 */
    INST_JUP,           /* 020 */
    INST_JDN,           /* 021 */
    INST_IO,            /* 022 */
    INST_MUL,           /* 023 */
    INST_HALT           /* HALT */
};


static void decodeInst(int inst, COND_TYPE &eCond, INST_CODE_TYPE &eInst)
{
    if (0 == inst) {
        eCond = COND_NONE;
        eInst = INST_HALT;
        return;
    }

    int op = (inst - 1) % 21;
    int cond = (inst - 1 - op) / 21;

    eCond = COND_TYPE(cond);
    eInst = INST_CODE_TYPE(op);
}


struct ST_INSTRUCTION {
    int inst;
    int opA;
    int opB;
    int opC;

    COND_TYPE eCond;
    INST_CODE_TYPE  eInst;

    ST_INSTRUCTION (int i, int a, int b, int c) : inst(i), opA(a), opB(b), opC(c) {
        decodeInst(i, eCond, eInst);
    };
};

static int decodeBase64(char c)
{
    int val = 0;
    if (('A' <= c) && (c <= 'Z')) {
        val = c - 'A';
    } else if (('a' <= c) && (c <= 'z')) {
        val = 26 + (c - 'a');
    } else if (('0' <= c) && (c <= '9')) {
        val = 52 + (c - '0');
    } else if ('+' == c) {
        val = 62;
    } else if ('/' == c) {
        val = 63;
    } else {
        printf("ERROR[%c]\n", c);
    }
    if (63 < val) {
        printf("--%d\n", val);
    }

    return val;

}


static vector<ST_INSTRUCTION> vstInst;
#define INST_MASK   (0x3F)

static bool parseRomFile(const string strS)
{
    int size = strS.size();

    for (int instIdx = 0; instIdx < size; instIdx+= 4) {
        char c_inst = strS[instIdx];
        char c_opa = strS[instIdx + 1];
        char c_opb = strS[instIdx + 2];
        char c_opc = strS[instIdx + 3];

        int inst = decodeBase64(c_inst);
        int opA  = decodeBase64(c_opa);
        int opB  = decodeBase64(c_opb);
        int opC  = decodeBase64(c_opc);
        vstInst.emplace_back(inst, opA, opB, opC);
    }

    return true;
}



const char* s_aacInstChar[] =  {
    "ADD",      /* 000 INST_ADD */
    "ADDI",     /* 001 INST_ADD_IMM */
    "SUB",      /* 002 INST_SUB */
    "CMP",      /* 003 INST_CMPCM */
    "OR",       /* 004 INST_OR */
    "ORI",      /* 005 INST_OR_IMM */
    "XOR",      /* 006 INST_XOR */
    "XORI",     /* 007 INST_XOR_IMM */
    "AND",      /* 010 INST_AND */
    "ANDI",     /* 011 INST_AND_IMM */
    "SFTI",     /* INST_SFT_IMM */
    "SHL",      /* 013 INST_SHL */
    "SHR",      /* 014 INST_SHR */
    "LD",       /* INST_MEM_LD */
    "ST",       /* INST_MEM_STR */
    "LBL",      /* INST_LBL */
    "JUP",      /* INST_JUP */
    "JDN",      /* INST_JDN */
    "IO",       /* INST_IO */
    "MUL",      /* INST_MUL */
    "HALT"      /* INST_HALT */ 
};

static void printInst(int inst_code, INST_CODE_TYPE eInst, COND_TYPE eCond)
{
    if (COND_PLUS == eCond) {
        printf("+ ");
    } else if (COND_MINUS == eCond) {
        printf("- ");
    } else {
        printf("  ");
    }
    printf("%s(%03o)", s_aacInstChar[eInst], inst_code);
}

static void printInstruction(int addr)
{
    ST_INSTRUCTION &inst = vstInst[addr];
    printf("%d : ", addr);
    printInst(inst.inst, inst.eInst, inst.eCond);
    printf(" ");
    printf("%d %d %d\n", inst.opA, inst.opB, inst.opC);
}

static void printInstructionAll()
{
    for (int addr = 0; addr < vstInst.size(); addr++) {
        printInstruction(addr);
    }
}

#define FILEBUFSIZE  4096
static void readRomFile(string &strS, const char *filename)
{
    FILE *file;
    char buffer[FILEBUFSIZE];
    if ((file = fopen(filename, "r"))==NULL) {
        printf(u8"failed to open file\n");
        exit(1);
    }
    while((fgets(buffer, FILEBUFSIZE, file))!=NULL) {
        strS = strS + buffer;
    }
    fclose(file);
}

static const char s_acChar[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', ' ', '+', '-', '*', '/', '<', '=', '>', '(', ')', '[', ']',
    '{', '}', '#', '$', '_', '?', '|', '^', '&', '!', '~', ',', '.', ':', '\n'
};

static int decodeSerialInput(char c) 
{
    for (int idx = 0; idx < 63; idx++) {
        if (c == s_acChar[idx]) {
            return idx;
        }
    }
    return 0;
}

static char encodeSerialOutput(int val) 
{
    return s_acChar[val];
}


#define NUM_REGS    (64)
#define REGVAL_MASK (0x3F)
#define REGMASK_MSB (0x20)

struct ST_REGISTER {
    int pc;
    int aGen[NUM_REGS];
    bool bCond;
};

static ST_REGISTER s_stRegs;

static void execInstAdd(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = s_stRegs.aGen[stInst.opB] + s_stRegs.aGen[stInst.opC];
} 

static void execInstAddImm(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = s_stRegs.aGen[stInst.opB] + stInst.opC;
} 

static void execInstSub(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = s_stRegs.aGen[stInst.opB] - s_stRegs.aGen[stInst.opC];
}

enum {
    tr = 0,
    fa,
    eq,
    ne,
    sl,
    sg,
    ul,
    ug
} CC_CONDS;

static void execInstCmpCm(ST_INSTRUCTION &stInst)
{
    int reg_type = stInst.opA / 8;
    int cc_type = stInst.opA % 8;

    int val_a, val_b;
    if (0 == reg_type) {
        val_a = s_stRegs.aGen[stInst.opB];
        val_b = s_stRegs.aGen[stInst.opC];
    } else if (2 == reg_type) {
        val_a = s_stRegs.aGen[stInst.opB];
        val_b = stInst.opC;
    } else if (3 == reg_type) {
        val_a = stInst.opB;
        val_b = s_stRegs.aGen[stInst.opC];
    }

    switch(cc_type) {
    case tr:
        s_stRegs.bCond = true;
        break;
    case fa:
        s_stRegs.bCond = false;
        break;
    case eq:
        s_stRegs.bCond = (val_a == val_b);
        break;
    case ne:
        s_stRegs.bCond = (val_a != val_b);
        break;
    case sl:
        s_stRegs.bCond = (val_a < val_b);
        break;
    case sg:
        s_stRegs.bCond = (val_a > val_b);
        break;
    case ul:
        s_stRegs.bCond = ((uint)val_a < (uint)val_b);
        break;
    case ug:
        s_stRegs.bCond = ((uint)val_a > (uint)val_b);
        break;
    default:
        printf("COMP ERROR\n");
        exit(0);
    }


} 

static void execInstOr(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = (s_stRegs.aGen[stInst.opB] | s_stRegs.aGen[stInst.opC]);
} 

static void execInstOrImm(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = (s_stRegs.aGen[stInst.opB] | stInst.opC);
} 

static void execInstXor(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = (s_stRegs.aGen[stInst.opB] ^ s_stRegs.aGen[stInst.opC]);
} 

static void execInstXorImm(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = (s_stRegs.aGen[stInst.opB] ^ stInst.opC);
} 

static void execInstAnd(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = (s_stRegs.aGen[stInst.opB] & s_stRegs.aGen[stInst.opC]);
} 

static void execInstAndImm(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = (s_stRegs.aGen[stInst.opB] & stInst.opC);
} 

static void execInstSftImm(ST_INSTRUCTION &stInst)
{
    int opC = stInst.opC;
    int bits = opC % 8;
    switch (opC / 8) {
    case 0:
        /* shl */
        s_stRegs.aGen[stInst.opA] = s_stRegs.aGen[stInst.opB] << bits;
        s_stRegs.aGen[stInst.opA] &= REGVAL_MASK;
        break;
    case 1:
        /* shr */
        s_stRegs.aGen[stInst.opA] = s_stRegs.aGen[stInst.opB] >> bits;
        s_stRegs.aGen[stInst.opA] &= REGVAL_MASK;
        break;
    case 2:
        /* sar */
        {
            int tmpVal = s_stRegs.aGen[stInst.opB];
            bool bMsb = (tmpVal & REGMASK_MSB);
            for (int idx = 0; idx < bits; idx++) {
                tmpVal >>= 1;
                if (bMsb) {
                    tmpVal |= REGMASK_MSB;
                }
            }
            s_stRegs.aGen[stInst.opA] = tmpVal;
        }
        break;
    case 3:
        /* rol */
        {
            int tmpVal = s_stRegs.aGen[stInst.opB];
            for (int idx = 0; idx < bits; idx++) {
                bool bMsb = (tmpVal & REGMASK_MSB);
                tmpVal <<= 1;
                if (bMsb) {
                    tmpVal |= 1;
                }
                tmpVal &= REGVAL_MASK;
            }
            s_stRegs.aGen[stInst.opA] = tmpVal;
        }
        break;
    }
} 

static void execInstShl(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = (s_stRegs.aGen[stInst.opB] << s_stRegs.aGen[stInst.opC]);
    s_stRegs.aGen[stInst.opA] &= REGVAL_MASK;
} 

static void execInstShr(ST_INSTRUCTION &stInst)
{
    s_stRegs.aGen[stInst.opA] = (s_stRegs.aGen[stInst.opB] >> s_stRegs.aGen[stInst.opC]);
    s_stRegs.aGen[stInst.opA] &= REGVAL_MASK;
} 

static void execInstMemLd(ST_INSTRUCTION &stInst)
{
    int addr = (s_stRegs.aGen[stInst.opB] + stInst.opC) % NUM_REGS;
    s_stRegs.aGen[stInst.opA] = s_stRegs.aGen[addr]; 
} 

static void execInstMemSt(ST_INSTRUCTION &stInst)
{
    int addr = (s_stRegs.aGen[stInst.opB] + stInst.opC) % NUM_REGS;
    s_stRegs.aGen[addr] = s_stRegs.aGen[stInst.opA]; 
}

static void execInstJumpCommon(ST_INSTRUCTION &stInst, int dir)
{
    int j_lab = stInst.opA * 64 + stInst.opB;
    int j_lc = s_stRegs.aGen[stInst.opC];
    for (int pc = s_stRegs.pc; ; pc += dir) {
        ST_INSTRUCTION &cur_inst = vstInst[pc];
        int lab = cur_inst.opA * 64 + cur_inst.opB;
        int lc = cur_inst.opC;
        if ((cur_inst.eInst == INST_LBL) 
            && (lab == j_lab)
            && (lc == j_lc)) {
            s_stRegs.pc = pc;
            return;
        }

        if ((pc < 0) || (3000 < pc)) {
            printf("Jump ERROR\n");
            exit(0);
        }
    }
}


static void execInstJup(ST_INSTRUCTION &stInst)
{
    execInstJumpCommon(stInst, -1);
} 

static void execInstJdn(ST_INSTRUCTION &stInst)
{
    execInstJumpCommon(stInst, 1);
}

static void execInstIo(ST_INSTRUCTION &stInst)
{
    int dev = stInst.opB;
    if ((0 == stInst.opA) && (0 == stInst.opC)) {
        /* io ix */
        printf("IO ERROR\n");

    } else if (0 == stInst.opA) {
        /* io r0, ix, rs */
        putchar(encodeSerialOutput(s_stRegs.aGen[stInst.opC]));

    } else if (0 == stInst.opC) {
        /* io rd, ix, r0 */
        char c = getchar();
        s_stRegs.aGen[stInst.opA] = encodeSerialOutput(c);
    } else {
        /* io rd, ix, rs */
        putchar(encodeSerialOutput(s_stRegs.aGen[stInst.opC]));
        char c = getchar();
        s_stRegs.aGen[stInst.opA] = encodeSerialOutput(c);
    }
}

static void execInstMul(ST_INSTRUCTION &stInst)
{
    int type = stInst.opC / 16;
    int pr = stInst.opC % 16;

    if (0 == type) {
        /* fmu/pr rd, ra */
        unsigned int mul_val = (unsigned int)s_stRegs.aGen[stInst.opB] * (unsigned int)s_stRegs.aGen[stInst.opC];
        mul_val >>= pr;
        mul_val &= REGVAL_MASK;

    } else if (1 == type) {
        /* fms/pr rd, ra */
        int mul_val = s_stRegs.aGen[stInst.opB] * s_stRegs.aGen[stInst.opC];
        mul_val >>= pr;
        mul_val &= REGVAL_MASK;

    } else {
        printf("DECODE ERROR\n");
        exit(0);
    }

} 

static void printRegs(void)
{
    for (int idx = 0; idx < NUM_REGS; idx++) {
        printf("R[%02d]: %d ", idx, s_stRegs.aGen[idx]);
        if (idx % 8 == 7) {
            printf("\n");
        }
    }
    printf("cond: %d\n", s_stRegs.bCond);
}


static bool execInstructionOne()
{
    int pc = s_stRegs.pc;
    printf("pc = %d\n", pc);
    ST_INSTRUCTION &inst = vstInst[pc];
    COND_TYPE eCond = inst.eCond;

    bool bExec = true;
    if (COND_PLUS == eCond) {
        if (!s_stRegs.bCond) {
            bExec = false;
        }
    }
    if (COND_MINUS == eCond) {
        if (s_stRegs.bCond) {
            bExec = false;
        }
    }

    if (bExec) {
        switch (inst.eInst) { 
        case INST_ADD:           /* 000 */
            execInstAdd(inst);
            break;
        case INST_ADD_IMM:       /* 001 */
            execInstAddImm(inst);
            break;
        case INST_SUB:           /* 002 */
            execInstSub(inst);
            break;
        case INST_CMPCM:         /* 003 */
            execInstCmpCm(inst);
            break;
        case INST_OR:            /* 004 */
            execInstOr(inst);
            break;
        case INST_OR_IMM:        /* 005 */
            execInstOrImm(inst);
            break;
        case INST_XOR:           /* 006 */
            execInstXor(inst);
            break;
        case INST_XOR_IMM:       /* 007 */ 
            execInstXorImm(inst);
            break;
        case INST_AND:           /* 010 */
            execInstAnd(inst);
            break;
        case INST_AND_IMM:       /* 011 */   
            execInstAndImm(inst);
            break;
        case INST_SFT_IMM:       /* 012 */
            execInstSftImm(inst);
            break;
        case INST_SHL:           /* 013 */
            execInstShl(inst);
            break;
        case INST_SHR:           /* 014 */
            execInstShr(inst);
            break;
        case INST_MEM_LD:        /* 015 */
            execInstMemLd(inst);
            break;
        case INST_MEM_STR:       /* 016 */
            execInstMemSt(inst);
            break;
        case INST_LBL:           /* 017 */
            /* nothing */
            break;
        case INST_JUP:           /* 020 */
            execInstJup(inst);
            break;
        case INST_JDN:           /* 021 */
            execInstJdn(inst);
            break;
        case INST_IO:            /* 022 */
            execInstIo(inst);
            break;
        case INST_MUL:            /* 023 */    
            execInstMul(inst);
            break;
        case INST_HALT:
            printf("Halt\n");
            return false;
            break;
        default:
            printf("Ooops\n");
        }
    }
//    printRegs();
//    getchar();
    s_stRegs.pc++;
    return true;
}

static void execInstruction()
{
    for(;;) {
        if (!execInstructionOne()) {
            break;
        }
    } 
}


int main(int argc, char *argv[])
{
    string strS;
    readRomFile(strS, "../mandelflag.rom");
    printf("size = %d\n", strS.size());

    parseRomFile(strS.substr(0, strS.size()-1));
    printInstructionAll();

    execInstruction();
    return true;
}
#ifdef __cplusplus
extern "C"{
#endif

#ifndef InstructionCodes_h
#define InstructionCodes_h

/**
 * 
 * INS =  Boolean expression                     | GROUP
 *                                               |
 * BRK = /IR7 /IR6 /IR5 /IR4 /IR3 /IR2 /IR1 /IR0 |
 * ORA = /IR7 /IR6 /IR5 /IR1 IR0                 | ArithLogInst
 * ASL = /IR7 /IR6 /IR5 /IR3 IR2 IR1 /IR0        |
 *     + /IR7 /IR6 /IR5 IR3 IR2 /IR1 IR0         |
 *     + /IR7 /IR6 /IR5 /IR4 IR3 /IR2 IR1 /IR0   | ShftInst
 * PHP = /IR7 /IR6 /IR5 /IR4 IR3 /IR2 /IR1 /IR0  | LowNibble=8
 * BPL = /IR7 /IR6 /IR5 IR4 /IR3 /IR2 /IR1 /IR0  |
 * CLC = /IR7 /IR6 /IR5 IR4 IR3 /IR2 /IR1 /IR0   | LowNibble=8
 * JSR = /IR7 /IR6 IR5 /IR4 /IR3 /IR2 /IR1 /IR0  |
 * AND = /IR7 /IR6 IR5 /IR1 IR0                  | ArithLogInst
 * BIT = /IR7 /IR6 IR5 /IR4 IR2 /IR1 /IR0        |
 * ROL = /IR7 /IR6 IR5 /IR3 IR2 IR1 /IR0         |
 *     + /IR7 /IR6 IR5 IR3 IR2 /IR1 IR0          |
 *     + /IR7 /IR6 IR5 /IR4 IR3 /IR2 IR1 /IR0    | ShftInst
 * PLP = /IR7 /IR6 IR5 /IR4 IR3 /IR2 /IR1 /IR0   | LowNibble=8
 * BMI = /IR7 /IR6 IR5 IR4 /IR3 /IR2 /IR1 /IR0   |
 * SEC = /IR7 /IR6 IR5 IR4 IR3 /IR2 /IR1 /IR0    | LowNibble=8
 * RTI = /IR7 IR6 /IR5 /IR4 /IR3 /IR2 /IR1 /IR0  |
 * EOR = /IR7 IR6 /IR5 /IR1 IR0                  | ArithLogInst
 * LSR = /IR7 IR6 /IR5 /IR3 IR2 IR1 /IR0         |
 *     + /IR7 IR6 /IR5 IR3 IR2 /IR1 IR0          |
 *     + /IR7 IR6 /IR5 /IR4 IR3 /IR2 IR1 /IR0    | ShftInst
 * PHA = /IR7 IR6 /IR5 /IR4 IR3 /IR2 /IR1 /IR0   | LowNibble=8
 * JMP = /IR7 IR6 /IR4 IR3 IR2 /IR1 /IR0         |
 * BVC = /IR7 IR6 /IR5 IR4 /IR3 /IR2 /IR1 /IR0   |
 * CLI = /IR7 IR6 /IR5 IR4 IR3 /IR2 /IR1 /IR0    | LowNibble=8
 * RTS = /IR7 IR6 IR5 /IR4 /IR3 /IR2 /IR1 /IR0   |
 * ADC = /IR7 IR6 IR5 /IR1 IR0                   | ArithLogInst
 * ROR = /IR7 IR6 IR5 /IR3 IR2 IR1 /IR0          |
 *     + /IR7 IR6 IR5 IR3 IR2 /IR1 IR0           |
 *     + /IR7 IR6 IR5 /IR4 IR3 /IR2 IR1 /IR0     | ShftInst
 * CLI = /IR7 IR6 IR5 /IR4 IR3 /IR2 /IR1 /IR0    | LowNibble=8
 * BVS = /IR7 IR6 IR5 IR4 /IR3 /IR2 /IR1 /IR0    |
 * SEI = /IR7 IR6 IR5 IR4 IR3 /IR2 /IR1 /IR0     | LowNibble=8
 * STA = IR7 /IR6 /IR5 /IR1 IR0                  |
 *     - IR7 /IR6 /IR5 /IR4 IR3 /IR2 /IR1 IR0    | Cannot use immediate addressing with store
 * STY = IR7 /IR6 /IR5 /IR3 IR2 /IR1 /IR0        |
 *     + IR7 /IR6 /IR5 /IR4 IR3 IR2 /IR1 /IR0    |
 * STX = IR7 /IR6 /IR5 /IR3 IR2 IR1 /IR0         |
 *     + IR7 /IR6 /IR5 /IR4 IR3 IR2 IR1 /IR0     |
 * DEY = IR7 /IR6 /IR5 /IR4 IR3 /IR2 /IR1 /IR0   | LowNibble=8
 * TXA = IR7 /IR6 /IR5 /IR4 IR3 /IR2 IR1 /IR0    |
 * BCC = IR7 /IR6 /IR5 IR4 /IR3 /IR2 /IR1 /IR0   |
 * TYA = IR7 /IR6 /IR5 IR4 IR3 /IR2 /IR1 /IR0    | LowNibble=8
 * TXS = IR7 /IR6 /IR5 IR4 IR3 /IR2 IR1 /IR0     |
 * LDY = IR7 /IR6 IR5 IR2 /IR1 /IR0              |
 *     + IR7 /IR6 IR5 /IR4 /IR3 /IR2 /IR1 /IR0   |
 * LDA = IR7 /IR6 IR5 /IR1 IR0                   |
 * LDX = IR7 /IR6 IR5 IR2 IR1 /IR0               |
 *     + IR7 /IR6 IR5 /IR4 /IR3 /IR2 IR1 /IR0    |
 * TAY = IR7 /IR6 IR5 /IR4 IR3 /IR2 /IR1 /IR0    | LowNibble=8
 * TAX = IR7 /IR6 IR5 /IR4 IR3 /IR2 IR1 /IR0     |
 * BCS = IR7 /IR6 IR5 IR4 /IR3 /IR2 /IR1 /IR0    |
 * CLV = IR7 /IR6 IR5 IR4 IR3 /IR2 /IR1 /IR0     | LowNibble=8
 * TSX = IR7 /IR6 IR5 IR4 IR3 /IR2 IR1 /IR0      |
 * CPY = IR7 IR6 /IR5 /IR4 IR2 /IR1 /IR0         |
 *     + IR7 IR6 /IR5 /IR4 /IR3 /IR2 /IR1 /IR0   |
 * CMP = IR7 IR6 /IR5 /IR1 IR0                   |
 * DEC = IR7 IR6 /IR5 IR2 IR1 /IR0               |
 * INY = IR7 IR6 /IR5 /IR4 IR3 /IR2 /IR1 /IR0    | LowNibble=8
 * DEX = IR7 IR6 /IR5 /IR4 IR3 /IR2 IR1 /IR0     |
 * BNE = IR7 IR6 /IR5 IR4 /IR3 /IR2 /IR1 /IR0    |
 * CLD = IR7 IR6 /IR5 IR4 IR3 /IR2 /IR1 /IR0     | LowNibble=8
 * CPX = IR7 IR6 IR5 /IR4 IR2 /IR1 /IR0          |
 *     + IR7 IR6 IR5 /IR4 /IR3 /IR2 /IR1 /IR0    |
 * SBC = IR7 IR6 IR5 /IR1 IR0                    |
 * INC = IR7 IR6 IR5 IR2 IR1 /IR0                |
 * INX = IR7 IR6 IR5 /IR4 IR3 /IR2 /IR1 /IR0     | LowNibble=8
 * NOP = IR7 IR6 IR5 /IR4 IR3 /IR2 IR1 /IR0      | 
 * BEQ = IR7 IR6 IR5 IR4 /IR3 /IR2 /IR1 /IR0     |
 * SED = IR7 IR6 IR5 IR4 IR3 /IR2 /IR1 /IR0      |
 * 
*/

#endif

#ifdef __cplusplus
}
#endif
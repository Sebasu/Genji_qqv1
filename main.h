// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/uart2.h"
#include "mcc_generated_files/uart3.h"
#include "mcc_generated_files/spi2_types.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "../Comunic.h"
//#include "../delay.h"

#define seqCORE 0
#define seqMASK 1
#define seqFRONT 2
#define seqCRUZ1 3
#define seqCRUZ2 4
#define seqLEGS 5

#define GREEN 0
#define RED 1
#define BLUE 2
#define YELLOW 3
#define PURPLE 4
#define CYAN 8
#define WHITE 10

#define gState 0
#define gMask 1
#define gCore 2
#define gShouldFL 3
#define gShouldFR 4
#define gShouldDL 5
#define gShouldDR 6
#define gShouldBL 7
#define gShouldBR 8
#define gNeckL 9
#define gNeckR 10
#define gNeckBL 11
#define gNeckBR 12
#define gAbsUL 13
#define gAbsUR 14
#define gAbsML 15
#define gAbsMR 16
#define gAbsDL 17
#define gAbsDR 18
#define gBackUL 19
#define gBackUR 20
#define gBackM 21
#define gBackD 22
#define gLegUL 23
#define gLegUR 24
#define gLegDL 25
#define gLegDR 26
#define gShoeL 27
#define gShoeR 28

/*typedef union {
    long valDL;
    float valD;
    struct {
        unsigned char valDa;//LessSifnificant
        unsigned char valDb;
        unsigned char valDc;
        unsigned char valDd;//MostSignificant
    };
}DATA_ITEM;*/

char waiter = 0;

unsigned char arraySizes[1] = {0};

void pTMR1_ISR(void);
void pTMR2_ISR(void);
void pRX2_ISR(void);
void pRX3_ISR(void);

/*void setPWM1duty(short val1);
void setPWM2duty(short val1);
void setPWM3duty(short val1);*/

void maskOff(void);
void maskOn(void);
void seqByZone_On(char num, short time);
void seqByZone_Off(char num, short time);
void SeqPresOn(void);
void SeqPresOff(void);
void execMask_Sword(void);
void initStop(void);
void val2group(char group, char val);
void despShadow(void);
void translateShadows(void);
void merger(void);
//void sendPixel(char g, char r, char b);
void sendDotStar(char g, char r, char b);
void applyColor(char group, char color, char intensity);
void dragonCrash(void);
void refriShoulder(char on);
void seqApply(void);
void apply2Dummy(char out, char in);

void demoEfectOn(void);
void demoEfectOff(void);

void allBodyVal(char val);
void resetAndOff(char light);

void butt1Pres(char state);
void butt2Pres(char state);
void butt3Pres(char state);

void sendByte(char cha);
void EUSART_Write(char cha);
//void sendOrder(void);
//void sendOrder2(void);
void sendOrderX(void);
//void sendOrderX2(char what);
void sendOrderDot(void);

void musik(void);
void merger(void);

//uint16_t    writeData = 0x55AA;
/*uint16_t    flashAddr = 0x01C0;
uint16_t    Buf[ERASE_FLASH_BLOCKSIZE];

void miau(void) {
    if(deltaVal == 1)
        deltaVal = 2;
    else
        deltaVal = 1;
    FLASH_WriteWord(flashAddr,Buf,deltaVal);
}*/

/******************************************
char rcving = 0;
char cont = 0;
char vals[9] = {0,0,0,0,0,0,0,0,0};

void protocolX(char cha) {
    if(!rcving) {
        cont = 0;
        if(cha == 13)
            rcving = 1;
    }else {
        vals[cont] = cha;
        cont++;
        if(cont >= 7) {
            if(vals[6] == 10)
                sendOrder();
            rcving = 0;
        }
    }
}
void protocol(char cha) {
    if(!rcving) {
        cont = 0;
        if(cha == 13)
            rcving = 1;
    }else {
        vals[cont] = cha;
        cont++;
        if(cont >= 9) {
            if(vals[8] == 10) {
                sendByte(vals[0]);
                sendByte(vals[1]);
                sendByte(vals[2]);
                sendByte(vals[3]);
                sendByte(vals[4]);
                sendByte(vals[5]);
                sendByte(vals[6]);
                sendByte(vals[7]);
            }
            rcving = 0;
        }
    }
}
******************************************/

/*void configSPI(void) {
    SSP1CON1bits.SSPEN = 0; //DisSPI
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0;
    SSPCLKPPS = 0b10011; //SCK(IN) en C3
    SSPDATPPS = 0b10101; //SDI en C5
    //SSPSSPPS = 0b10001; //???
    RC3PPS = 0b10000; //SCK(OUT) en C3
    RC4PPS = 0b10001; //SDO en C4
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 1;
    TRISCbits.TRISC3 = 0; //SCK
    TRISCbits.TRISC4 = 0; //SDO
    TRISCbits.TRISC5 = 1; //SDI
    SSP1STATbits.SMP = 0; //MIDDLE
    SSP1STATbits.CKE = 0; //Iddle2Active Transmit
    SSP1CON1bits.CKP = 0; //IddleState = Low
    SSP1CON1bits.SSPM = 0b0011; //SPI MasterClock = T2m/2
    SSP1ADD = 0;
    SSP1CON1bits.SSPEN = 1; //EnSPI
}*/

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


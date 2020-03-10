// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_MAIN_H
#define	XC_MAIN_H

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
#define DRAGON 20
#define DRAGON2 21

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
#define gBridge 29

void waitX0ms(char X);
void dotTest(char cantDot);

void val2group(char group, char val);
void merger(void);
void sendOrderX(void);

void dotStart(char i);
void sendDotStar(char r, char g, char b);
void sendOrderDot(void);

void rstShadow(char start);
void despShadow(void);
void translateShadows(void);
void crashOn1(void);
void crashOff1(void);
void crashOn2(void);
void crashOff2(void);
void crashOff3(void);
void rstDragon(char start);
void dragonCrash(void);
void refriShoulder(char on);
void rstMaskOn(char start);
void maskOn(void);
void rstMaskOff(char start);
void maskOff(void);
void rstDemoOn(char start);
void demoEfectOn(void);
void rstMusik(char start);
void musik(void);
void rstDemoOff(char start);
void demoEfectOff(void);
void seqByZone_On(char num, short time);
void seqByZone_Off(char num, short time);
void rstPressOn(char start);
void SeqPresOn(void);
void rstPressOff(char start);
void SeqPresOff(void);
void seqApply(void);

//void apply2Dummy(char out, char in);
void applyColor(char group, char color, char intensity);
void rstSeq(void);
void allBodyVal(char val, char color);
void resetAndOff(char light);

void execMask_Sword(void);
void initStop(void);

void pTMR1_ISR(void);
void pTMR2_ISR(void);
void pRX2_ISR(void);
void pRX3_ISR(void);

void butt1Pres(char state);
void butt2Pres(char state);
void butt3Pres(char state);

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

/*uint16_t    writeData = 0x55AA;
uint16_t    flashAddr = 0x01C0;
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

/*void sendPixel(char r, char g, char b) {
    sendByte(g);sendByte(r);sendByte(b);sendByte(0);
}*/

/*void sendOrder(void) {
    char i = 0;
    for(i = 0; i < dummyCant; i++) {
        if(dummyColor[i] == RED)
            sendPixel(dummyValue[i],0,0);
        else if(dummyColor[i] == GREEN)
            sendPixel(0,dummyValue[i],0);
        else if(dummyColor[i] == BLUE)
            sendPixel(0,0,dummyValue[i]);
        else if(dummyColor[i] == YELLOW)
            sendPixel(dummyValue[i],dummyValue[i],0);
        else if(dummyColor[i] == PURPLE)
            sendPixel(dummyValue[i],0,dummyValue[i]);
        else if(dummyColor[i] == CYAN)
            sendPixel(0,dummyValue[i],dummyValue[i]);
        else if(dummyColor[i] == WHITE)
            sendPixel(dummyValue[i],dummyValue[i],dummyValue[i]);
    }
}*/

/*void sendOrder2(void) {
    char i = 0;
    for(i = 0; i < dummyCant2; i++) {
        if(dummyColor[i] == RED)
            sendPixel(shadowArray[i],0,0);
        else if(dummyColor[i] == GREEN)
            sendPixel(0,shadowArray[i],0);
        else if(dummyColor[i] == BLUE)
            sendPixel(0,0,shadowArray[i]);
        else if(dummyColor[i] == YELLOW)
            sendPixel(shadowArray[i],shadowArray[i],0);
        else if(dummyColor[i] == PURPLE)
            sendPixel(shadowArray[i],0,shadowArray[i]);
        else if(dummyColor[i] == CYAN)
            sendPixel(0,shadowArray[i],shadowArray[i]);
        else if(dummyColor[i] == WHITE)
            sendPixel(shadowArray[i],shadowArray[i],shadowArray[i]);
    }
}*/

/*void sendOrderY(void) {
    dummyValue[0] = (char)SeqVals[seqLEGS];//Leg Right
    dummyValue[1] = (char)SeqVals[seqCORE];//Core
    dummyValue[2] = (char)SeqVals[seqLEGS];//Leg Left
    dummyValue[3] = (char)SeqVals[seqCRUZ2];//ShoulBRight
    dummyValue[4] = (char)SeqVals[seqCRUZ1];//AbdRight
    dummyValue[5] = (char)SeqVals[seqCRUZ2];//AbdLeft
    dummyValue[6] = (char)SeqVals[seqCRUZ1];//ShoulBLeft
    dummyValue[7] = (char)SeqVals[seqCRUZ2];//Back
    dummyValue[8] = (char)SeqVals[seqFRONT];//ShoulFRight
    dummyValue[9] = (char)SeqVals[seqMASK];//Mask
    dummyValue[10] = (char)SeqVals[seqFRONT];//ShoulFLeft
    sendOrder();
}*/

/*void sendOrderX(void) {
    apply2Dummy(0, gLegUR);//Leg Right
    apply2Dummy(1, gCore);//Core
    apply2Dummy(2, gLegUL);//Leg Left
    apply2Dummy(3, gShouldBR);//ShoulBRight
    apply2Dummy(4, gAbsUR);//AbdRight
    apply2Dummy(5, gAbsUL);//AbdLeft
    apply2Dummy(6, gShouldBL);//ShoulBLeft
    apply2Dummy(7, gBackUR);//Back
    apply2Dummy(8, gShouldFR);//ShoulFRight
    apply2Dummy(9, gMask);//Mask
    apply2Dummy(10, gShouldFL);//ShoulFLeft
}*/

/***************Talk to ESP from HC-05***********************************/
/*char contRCV = 0;
char contRCV2 = 0;
char go = 0;*/

/*char sas = 0;//T2 ISR (500ms)
contRCV2 = contRCV;
contRCV = 0;
for(sas = 0; sas < contRCV2; sas++) {
    buff2[sas] = buff1[sas];
}
go = 1;*/
/*buff1[contRCV] = cha;//UART2 ISR
contRCV++;
if(contRCV > 99) {
    contRCV2 = contRCV;
    contRCV = 0;
    char sas = 0;
    for(sas = 0; sas < 100; sas++) {
        buff2[sas] = buff1[sas];
    }
    go = 1;
}*/
//UART2_Write(cha); //UART3 ISR

/*W_EN_SetLow(); //Main
W_BOOT_SetHigh();
W_EN_SetHigh();*/

/*char i = 0;
    if(go) {
    for(i = 0; i < contRCV2; i++) {
        EUSART_Write(buff2[i]);
    }
    go = 0;
}*/
/*sprintf(UART2_Write,"AT\r\n");
sprintf(UART2_Write,"AT+GMR\r\n");
printf(UART2_Write,"AT+CWJAP=\"WiFi Ahorus\",\"77775522\"\r\n");
//printf(UART2_Write,"AT+CIPSTART=\"TCP\",\"192.168.1.104\",1500\r\n");
printf(UART2_Write,"AT+CIPMODE=1\r\n");
printf(UART2_Write,"AT+CIPSEND\r\n");*/
/***************Talk to ESP from HC-05***********************************/

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_MAIN_H */
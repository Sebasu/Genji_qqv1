#include "main.h"

char bLs1 = 0;
char bLs2 = 0;
char bLs3 = 0;
char modoPress_nDemo = 0;
signed short SeqVals[6] = {0,0,0,0,0,0};
char soundASOn = 0;
char soundASOff = 0;
char run = 0;
char lightsOn = 0;
signed short fullBodyVal = 0;

char flagPressOn = 0;
unsigned short timPresOn = 0;

char flagPressOff = 0;
unsigned short timPresOff = 0;

char flagDemoOn = 0;
unsigned short timDemoOn = 0;

char flagDemoOff = 0;
unsigned short timDemoOff = 0;

char maskIsOn = 0;
unsigned char runMaskOn = 0;
unsigned short indexMaskOn = 0;
unsigned short contTimMaskOn = 0;
unsigned char seqMaskOn[10] = {77,0,77,128,102,51,0,102,179,255};
signed short MaskSeq[8] = {0,0,0,0,0,0,0,0};

char runMaskOff = 0;
unsigned char indexMaskOff = 0;
unsigned short contTimMaskOff = 0;
unsigned char subContMaskOff = 0;

char runShadow = 0;
unsigned char indexShadow = 0;
unsigned short contTimShadow = 0;
unsigned char subContShadow = 0;
signed short shadowArray[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

char runCrash = 0;
unsigned char indexCrash = 0;
unsigned short contCrash = 0;
unsigned char subContCrash = 0;
unsigned char dragonColor = 0;
unsigned char deltaCrash = 16;//17?
signed short intensityCrash = 0;
signed short intensityCrash2 = 0;
unsigned char dragonArray[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char intensityArray[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char dragonCrashDone = 0;

char refriShoulderDone = 0;

char musikRun = 0;
signed short valTempo = 0;
signed short valBip1 = 0;
signed short valBip2 = 0;
unsigned char stepsNote = 0;
unsigned char noteOnTempo = 0;
signed char noteNum = 0;
unsigned short ritmCont = 0;

/********Steps of 10.4_ms Nucleo, Mask, hombF, Cruz1, Cruz2, Parte Baja********/
unsigned short firstDelay = 152;
unsigned short delaysOn[6] = {0,4,28,36,44,52};
unsigned char seqDeltasOn[6] = {8,6,5,6,7,9};
//char durations[6] = {32,44,52,44,36,28};
unsigned short delaysOff[6] = {48,32,0,0,0,0};//short delaysOff[6] = {140,60,24,16,0};//10.4ms blocks
unsigned char seqDeltasOff[6] = {3,5,5,6,7,9};
unsigned short delaysDemo[6] = {0,0,0,28,36,52};
/**********************************************************************/

unsigned char waiter = 0;
unsigned long secCont = 0;
unsigned short minCont = 0;
unsigned char stepContDemo = 0;
unsigned char stepContPress = 0;

/*char dummyCant = 29;
char dummyValue[29] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char dummyColor[29] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};*/

unsigned short dotCant = 128;
unsigned char dotValue[128] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0/*,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*/};
unsigned char dotColor[128] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0/*,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*/};

unsigned char groupBuff[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned char groupCant = 30;
unsigned char groupSize[30] = {1,16,11,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,6,6,6,6,8,8,1};
unsigned char groupValue[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char groupColor[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned char State[1] = {0}; //0 (Nup)
unsigned char Mask[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //1
unsigned char Core[11] = {0,0,0,0,0,0,0,0,0,0,0}; //2
unsigned char ShouldFL[3] = {0,0,0}; //3
unsigned char ShouldFR[3] = {0,0,0}; //4
unsigned char ShouldDL[3] = {0,0,0}; //5
unsigned char ShouldDR[3] = {0,0,0}; //6
unsigned char ShouldBL[3] = {0,0,0}; //7
unsigned char ShouldBR[3] = {0,0,0}; //8
unsigned char NeckL[3] = {0,0,0}; //9
unsigned char NeckR[3] = {0,0,0}; //10
unsigned char NeckBL[4] = {0,0,0,0}; //11
unsigned char NeckBR[4] = {0,0,0,0}; //12
unsigned char NeckBRcolor[4] = {0,0,0,0}; //NeckBR Color for Effect
unsigned char AbsUL[4] = {0,0,0,0}; //13
unsigned char AbsUR[4] = {0,0,0,0}; //14
unsigned char AbsML[3] = {0,0,0}; //15
unsigned char AbsMR[3] = {0,0,0}; //16
unsigned char AbsDL[3] = {0,0,0}; //17
unsigned char AbsDR[3] = {0,0,0}; //18
unsigned char BackUL[3] = {0,0,0}; //19
unsigned char BackUR[3] = {0,0,0}; //20
unsigned char BackUM[3] = {0,0,0}; //21
unsigned char BackD[3] = {0,0,0}; //22 (Nup)
unsigned char LegUL[6] = {0,0,0,0,0,0}; //23
unsigned char LegUR[6] = {0,0,0,0,0,0}; //24
unsigned char LegDL[6] = {0,0,0,0,0,0}; //25
unsigned char LegDR[6] = {0,0,0,0,0,0}; //26
unsigned char ShoeL[8] = {0,0,0,0,0,0,0,0}; //27
unsigned char ShoeR[8] = {0,0,0,0,0,0,0,0}; //28
unsigned char Bridge[1] = {0}; //29

/************Management*******************************/
void valfromGroup(char groupID) {
    char i = 0;
    for(i = 0; i < groupSize[groupID]; i++) {
        switch (groupID) {
        case gState:
            groupBuff[i] = State[i];
            break;
        case gMask:
            groupBuff[i] = Mask[i];
            break;
        case gCore:
            groupBuff[i] = Core[i];
            break;
        case gShouldFL:
            groupBuff[i] = ShouldFL[i];
            break;
        case gShouldFR:
            groupBuff[i] = ShouldFR[i];
            break;
        case gShouldDL:
            groupBuff[i] = ShouldDL[i];
            break;
        case gShouldDR:
            groupBuff[i] = ShouldDR[i];
            break;
        case gShouldBL:
            groupBuff[i] = ShouldBL[i];
            break;
        case gShouldBR:
            groupBuff[i] = ShouldBR[i];
            break;
        case gNeckL:
            groupBuff[i] = NeckL[i];
            break;
        case gNeckR:
            groupBuff[i] = NeckR[i];
            break;
        case gNeckBL:
            groupBuff[i] = NeckBL[i];
            break;
        case gNeckBR:
            groupBuff[i] = NeckBR[i];
            break;
        case gAbsUL:
            groupBuff[i] = AbsUL[i];
            break;
        case gAbsUR:
            groupBuff[i] = AbsUR[i];
            break;
        case gAbsML:
            groupBuff[i] = AbsML[i];
            break;
        case gAbsMR:
            groupBuff[i] = AbsMR[i];
            break;
        case gAbsDL:
            groupBuff[i] = AbsDL[i];
            break;
        case gAbsDR:
            groupBuff[i] = AbsDR[i];
            break;
        case gBackUL:
            groupBuff[i] = BackUL[i];
            break;
        case gBackUR:
            groupBuff[i] = BackUR[i];
            break;
        case gBackM:
            groupBuff[i] = BackUM[i];
            break;
        case gBackD:
            groupBuff[i] = BackD[i];
            break;
        case gLegUL:
            groupBuff[i] = LegUL[i];
            break;
        case gLegUR:
            groupBuff[i] = LegUR[i];
            break;
        case gLegDL:
            groupBuff[i] = LegDL[i];
            break;
        case gLegDR:
            groupBuff[i] = LegDR[i];
            break;
        case gShoeL:
            groupBuff[i] = ShoeL[i];
            break;
        case gShoeR:
            groupBuff[i] = ShoeR[i];
            break;
        case gBridge:
            groupBuff[i] = Bridge[i];
            break;
        }
    }
}

void val2group(char groupID, char val) {
    char i = 0;
    for(i = 0; i < groupSize[groupID]; i++) {
        switch (groupID) {
        case gState:
            State[i] = val;
            break;
        case gMask:
            Mask[i] = val;
            break;
        case gCore:
            Core[i] = val;
            break;
        case gShouldFL:
            ShouldFL[i] = val;
            break;
        case gShouldFR:
            ShouldFR[i] = val;
            break;
        case gShouldDL:
            ShouldDL[i] = val;
            break;
        case gShouldDR:
            ShouldDR[i] = val;
            break;
        case gShouldBL:
            ShouldBL[i] = val;
            break;
        case gShouldBR:
            ShouldBR[i] = val;
            break;
        case gNeckL:
            NeckL[i] = val;
            break;
        case gNeckR:
            NeckR[i] = val;
            break;
        case gNeckBL:
            NeckBL[i] = val;
            break;
        case gNeckBR:
            NeckBR[i] = val;
            break;
        case gAbsUL:
            AbsUL[i] = val;
            break;
        case gAbsUR:
            AbsUR[i] = val;
            break;
        case gAbsML:
            AbsML[i] = val;
            break;
        case gAbsMR:
            AbsMR[i] = val;
            break;
        case gAbsDL:
            AbsDL[i] = val;
            break;
        case gAbsDR:
            AbsDR[i] = val;
            break;
        case gBackUL:
            BackUL[i] = val;
            break;
        case gBackUR:
            BackUR[i] = val;
            break;
        case gBackM:
            BackUM[i] = val;
            break;
        case gBackD:
            BackD[i] = val;
            break;
        case gLegUL:
            LegUL[i] = val;
            break;
        case gLegUR:
            LegUR[i] = val;
            break;
        case gLegDL:
            LegDL[i] = val;
            break;
        case gLegDR:
            LegDR[i] = val;
            break;
        case gShoeL:
            ShoeL[i] = val;
            break;
        case gShoeR:
            ShoeR[i] = val;
            break;
        case gBridge:
            Bridge[i] = val;
            break;
        }
    }
    groupValue[groupID] = val;
}

char mergeGroup(char groupID, char accum) {
    char i = 0;
    char size = groupSize[groupID];
    valfromGroup(groupID);
    for(i = 0; i < size; i++) {
        dotValue[i + accum] = groupBuff[i];
        dotColor[i + accum] = groupColor[groupID];
    }
    accum += size;
    return accum;
    /*for(i = 0; i < groupSize[gShouldBR]; i++) {
        dotValue[i + accum] = ShouldBR[i];
        dotColor[i + accum] = groupColor[gShouldBR];
    }
    accum += groupSize[gShouldBR];*/
}

void merger(void) {
    short preAccum = 0;
    short accum = 0;
    char i = 0;
    //accum = mergeGroup(gState, accum);
    //accum = mergeGroup(gBridge, accum);
    //accum = mergeGroup(gBackD, accum); //Nup
    accum = mergeGroup(gBackM, accum);
    accum = mergeGroup(gBackUL, accum);
    accum = mergeGroup(gBackUR, accum);
    accum = mergeGroup(gShouldBR, accum);
    accum = mergeGroup(gShouldDR, accum);
    accum = mergeGroup(gShouldFR, accum);
    accum = mergeGroup(gNeckR, accum);
    for(i = 0; i < groupSize[gNeckBR]; i++) { //accum = mergeGroup(gNeckBR, accum);
        dotValue[i + accum] = NeckBR[i];
        dotColor[i + accum] = NeckBRcolor[i];//groupColor[gNeckBR];
    }
    accum += groupSize[gNeckBR];
    accum = mergeGroup(gMask, accum);
    accum = mergeGroup(gNeckBL, accum);
    accum = mergeGroup(gNeckL, accum);
    accum = mergeGroup(gShouldBL, accum);
    accum = mergeGroup(gShouldDL, accum);
    accum = mergeGroup(gShouldFL, accum);
    accum = mergeGroup(gCore, accum);
    accum = mergeGroup(gAbsUL, accum);
    accum = mergeGroup(gAbsUR, accum);
    accum = mergeGroup(gAbsMR, accum);
    accum = mergeGroup(gAbsML, accum);
    accum = mergeGroup(gAbsDL, accum);
    accum = mergeGroup(gAbsDR, accum);
    accum = mergeGroup(gLegUL, accum);
    accum = mergeGroup(gLegUR, accum);
    accum = mergeGroup(gLegDL, accum);
    accum = mergeGroup(gLegDR, accum);
    accum = mergeGroup(gShoeL, accum);
    accum = mergeGroup(gShoeR, accum);
}

void sendOrderX(void) {
    /*apply2Dummy(0, gShoeR);
    apply2Dummy(1, gLegDR);
    apply2Dummy(2, gLegUR);
    apply2Dummy(3, gAbsDR);
    apply2Dummy(4, gAbsMR);
    apply2Dummy(5, gAbsUR);
    apply2Dummy(6, gBackUR);
    apply2Dummy(7, gShouldDR);
    apply2Dummy(8, gShouldFR);
    apply2Dummy(9, gShouldBR);
    apply2Dummy(10, gNeckR);
    apply2Dummy(11, gNeckBR);
    apply2Dummy(12, gBackM);
    apply2Dummy(13, gCore);
    apply2Dummy(14, gMask);
    apply2Dummy(15, gNeckBL);
    apply2Dummy(16, gNeckL);
    apply2Dummy(17, gShouldBL);
    apply2Dummy(18, gShouldFL);
    apply2Dummy(19, gShouldDL);
    apply2Dummy(20, gBackUL);
    apply2Dummy(21, gAbsUL);
    apply2Dummy(22, gAbsML);
    apply2Dummy(23, gAbsDL);
    apply2Dummy(24, gLegUL);
    apply2Dummy(25, gLegDL);
    apply2Dummy(26, gShoeL);
    
    apply2Dummy(27, gState);
    apply2Dummy(28, gBackD);*/
    
    //applyColor(gBridge, GREEN, 0);
    merger();
    sendOrderDot();
}
/************Management*******************************/

/************DotStar Drivers*******************************/
void dotStart(char i) {
    for(i = 0; i < 4; i++)
        spi2_exchangeByte(0);
}

void sendDotStar(char r, char g, char b) {
    spi2_exchangeByte(255);spi2_exchangeByte(b);
    spi2_exchangeByte(g);spi2_exchangeByte(r);
}

void sendOrderDot(void) {
    short i = 0;
    dotStart(i);
    for(i = 0; i < dotCant; i++) {
        if(dotColor[i] == RED)
            sendDotStar(dotValue[i],0,0);
        else if(dotColor[i] == GREEN)
            sendDotStar(0,dotValue[i],0);
        else if(dotColor[i] == BLUE)
            sendDotStar(0,0,dotValue[i]);
        else if(dotColor[i] == YELLOW)
            sendDotStar(dotValue[i],dotValue[i],0);
        else if(dotColor[i] == PURPLE)
            sendDotStar(dotValue[i],0,dotValue[i]);
        else if(dotColor[i] == CYAN)
            sendDotStar(0,dotValue[i],dotValue[i]);
        else if(dotColor[i] == WHITE)
            sendDotStar(dotValue[i],dotValue[i],dotValue[i]);
        else if(dotColor[i] == DRAGON)
            sendDotStar(0, dotValue[i], 255-dotValue[i]);
        else if(dotColor[i] == DRAGON2)
            sendDotStar(0, 255-dotValue[i], dotValue[i]);
    }
    sendDotStar(10,10,10); //One more Pixel on White???
}
/************DotStar Drivers*******************************/

/************Light Effects*********************************/
void rstShadow(char start) {
    subContShadow = 0;
    indexShadow = 0;
    contTimShadow = 0;
    runShadow = start;
}

void despShadow(void) {
    if(runShadow && contTimShadow < 600) {
        if(contTimShadow < 1) {
            char i = 0;
            for(i = 0; i < 21; i++)
                shadowArray[i] = 255;
        }
        subContShadow++;
        if(indexShadow < 24) {
            if(indexShadow < 21) {
                shadowArray[indexShadow] -= 6;
                if(shadowArray[indexShadow] < 0)
                    shadowArray[indexShadow] = 0;
            }
            if(indexShadow > 0 && indexShadow < 22) {
                shadowArray[indexShadow - 1] -= 6;
                if(shadowArray[indexShadow - 1] < 0)
                    shadowArray[indexShadow - 1] = 0;
            }
            if(indexShadow > 1 && indexShadow < 23) {
                shadowArray[indexShadow - 2] += 6;
                if(shadowArray[indexShadow - 2] > 255)
                    shadowArray[indexShadow - 2] = 255;
            }
            if(indexShadow > 2 && indexShadow < 24) {
                shadowArray[indexShadow - 3] += 6;
                if(shadowArray[indexShadow - 3] > 255)
                    shadowArray[indexShadow - 3] = 255;
            }
        }else {
            char i = 0;
            for(i = 0; i < 21; i++)
                shadowArray[i] = 255;
            rstShadow(0);
        }
        if(subContShadow >= 24) {
            indexShadow++;
            subContShadow = 0;
        }
        translateShadows();
        sendOrderX();
        contTimShadow++;
    }
}

void translateShadows(void) {
    char i = 0;
    for(i = 0; i < groupSize[gNeckBL]; i++) {
        NeckBL[i] = shadowArray[i];
        NeckBR[i] = shadowArray[i];
    }
    val2group(gNeckL, shadowArray[4]);
    val2group(gNeckR, shadowArray[4]);
    val2group(gBackUL, shadowArray[5]);
    val2group(gBackUR, shadowArray[5]);
    val2group(gShouldBL, shadowArray[6]);
    val2group(gShouldBR, shadowArray[6]);
    val2group(gShouldDL, shadowArray[7]);
    val2group(gShouldDR, shadowArray[7]);
    val2group(gShouldFL, shadowArray[8]);
    val2group(gShouldFR, shadowArray[8]);
    val2group(gAbsUL, shadowArray[9]);
    val2group(gAbsUR, shadowArray[9]);
    val2group(gAbsML, shadowArray[10]);
    val2group(gAbsMR, shadowArray[10]);
    val2group(gAbsDL, shadowArray[11]);
    val2group(gAbsDR, shadowArray[11]);
    val2group(gLegUL, shadowArray[12]);
    val2group(gLegUR, shadowArray[12]);
    val2group(gLegDL, shadowArray[13]);
    val2group(gLegDR, shadowArray[13]);
    for(i = 0; i < groupSize[gShoeL]; i++) {
        char sas = i + 14;
        ShoeL[i] = shadowArray[sas];
        ShoeR[i] = shadowArray[sas];
    }
}

void crashOn1(void) {
    if(subContCrash < 17) {
        dragonArray[indexCrash] = GREEN;
        intensityCrash -= deltaCrash;
        if(intensityCrash < 0)
            intensityCrash = 0;
    }else {
        dragonArray[indexCrash] = BLUE;
        intensityCrash += deltaCrash;
        if(intensityCrash > 255)
            intensityCrash = 255;
    }
    intensityArray[indexCrash] = intensityCrash;
}

void crashOff1(void) {
    if(subContCrash < 17) {
        dragonArray[32 - indexCrash] = BLUE;
        intensityCrash -= deltaCrash;
        if(intensityCrash < 0)
            intensityCrash = 0;
    }else {
        dragonArray[32 - indexCrash] = GREEN;
        intensityCrash += deltaCrash;
        if(intensityCrash > 255)
            intensityCrash = 255;
    }
    intensityArray[32 - indexCrash] = intensityCrash;
}

void crashOn2(void) {
    dragonArray[indexCrash] = DRAGON;
    intensityCrash -= deltaCrash;
    if(intensityCrash < 0)
        intensityCrash = 0;
    /*if(subContCrash >= 32) {
        dragonArray[indexCrash] = GREEN;
        intensityCrash = 255;
    }*/
    intensityArray[indexCrash] = intensityCrash;
}

void crashOff2(void) {
    dragonArray[32 - indexCrash] = DRAGON2;
    intensityCrash -= deltaCrash;
    if(intensityCrash < 0)
        intensityCrash = 0;
    intensityArray[32 - indexCrash] = intensityCrash;
}

void crashOff3(void) {
    intensityCrash2 -= 1;
    if(intensityCrash2 < 0)
        intensityCrash2 = 0;
    char ix = 0;
    for(ix = 0; ix < 15; ix++) {
        dragonArray[ix] = DRAGON2;
        intensityArray[ix] = intensityCrash2;
    }
}

void rstDragon(char start) {
    char i = 0;
    for(i = 0; i < 15; i++) {
        intensityArray[i] = 255;
        dragonArray[i] = GREEN;
    }
    intensityCrash = 255;
    subContCrash = 0;
    indexCrash = 0;
    contCrash = 0;
    runCrash = start;
}

void dragonCrash(void) {
    if(runCrash && contCrash < 1500) {
        subContCrash++;
        if(indexCrash < 15) {
            //crashOn1();//OBO Cut
            crashOn2();//OBO Smooth
        }else if(indexCrash < 18){
            //La lala lala
            intensityCrash2 = 255;
        }else if(indexCrash < 33){
            //crashOff1();//OBO Cut
            //crashOff2();//OBO Smooth
            crashOff3();//All Smooth
        }else {
            rstDragon(0);
            dragonCrashDone = 1;
        }
        if(subContCrash >= 32) {
            indexCrash++;
            intensityCrash = 255;
            subContCrash = 0;
        }
        applyColor(gShouldDR, dragonArray[0], intensityArray[0]);
        applyColor(gShouldFR, dragonArray[1], intensityArray[1]);
        applyColor(gShouldBR, dragonArray[2], intensityArray[2]);
        applyColor(gNeckR, dragonArray[3], intensityArray[3]);
        applyColor(gAbsUR, dragonArray[4], intensityArray[4]);
        applyColor(gBackUR, dragonArray[5], intensityArray[5]);
        NeckBR[0] = intensityArray[6]; NeckBRcolor[0] = dragonArray[6];
        applyColor(gAbsMR, dragonArray[7], intensityArray[7]);
        NeckBR[1] = intensityArray[8]; NeckBRcolor[1] = dragonArray[8];
        applyColor(gAbsDR, dragonArray[9], intensityArray[9]);
        NeckBR[2] = intensityArray[10]; NeckBRcolor[2] = dragonArray[10];
        applyColor(gLegUR, dragonArray[11], intensityArray[11]);
        NeckBR[3] = intensityArray[12]; NeckBRcolor[3] = dragonArray[12];
        applyColor(gLegDR, dragonArray[13], intensityArray[13]);
        applyColor(gShoeR, dragonArray[14], intensityArray[14]);
        sendOrderX();
        contCrash++;
    //}else if(runCrash) {
      //  rstDragon(0);
    }
}

void refriShoulder(char on) {
    char col = GREEN;
    if(on)
        col = WHITE;
    applyColor(gShouldBL, col, 255);
    applyColor(gShouldBR, col, 255);
    applyColor(gShouldDL, col, 255);
    applyColor(gShouldDR, col, 255);
    applyColor(gShouldFL, col, 255);
    applyColor(gShouldFR, col, 255);
}

void rstMaskOn(char start) {
    indexMaskOn = 0;
    contTimMaskOn = 0;
    runMaskOn = start;
}

void maskOn(void) {//CallOn Timer
    if(runMaskOn && contTimMaskOn < 60) {
        contTimMaskOn++;
        if(contTimMaskOn == (short)4*(indexMaskOn + 1)) {
            val2group(gMask, seqMaskOn[indexMaskOn]);
            indexMaskOn++;
            sendOrderX();
            if(indexMaskOn >= 10) {
                maskIsOn = 1;
                rstMaskOn(0);
            }
        }
    }
}

void rstMaskOff(char start) {
    contTimMaskOff = 0;
    subContMaskOff = 0;
    indexMaskOff = 0;
    runMaskOff = start;
}

void maskOff(void) {
    if(runMaskOff && contTimMaskOff < 130) {
        if(contTimMaskOff < 1) {
            char i = 0;
            for(i = 0; i < 8; i++)
                MaskSeq[i] = 255;
        }
        subContMaskOff++;
        if(indexMaskOff < 9) {
            if(indexMaskOff < 8) {
                MaskSeq[indexMaskOff] -= 16;
                if(MaskSeq[indexMaskOff] < 0)
                    MaskSeq[indexMaskOff] = 0;
            }
            if(indexMaskOff > 0) {
                MaskSeq[indexMaskOff-1] -= 16;
                if(MaskSeq[indexMaskOff-1] < 0)
                    MaskSeq[indexMaskOff-1] = 0;
            }
            if(indexMaskOff > 1) {
                MaskSeq[indexMaskOff-2] += 16;
                if(MaskSeq[indexMaskOff-2] > 255)
                    MaskSeq[indexMaskOff-2] = 255;
            }
            if(indexMaskOff > 2) {
                MaskSeq[indexMaskOff-3] += 16;
                if(MaskSeq[indexMaskOff-3] > 255)
                    MaskSeq[indexMaskOff-3] = 255; 
            }
        }else if(indexMaskOff < 16) {
            if(indexMaskOff < 15) {
                MaskSeq[14-indexMaskOff] -= 16;
                if(MaskSeq[14-indexMaskOff] < 0)
                    MaskSeq[14-indexMaskOff] = 0;
            }
            MaskSeq[15-indexMaskOff] -= 16;
            if(MaskSeq[15-indexMaskOff] < 0)
                MaskSeq[15-indexMaskOff] = 0;
        }else {
            char i = 0;
            for(i = 0; i < 6; i++)
                MaskSeq[i] = 0;
            maskIsOn = 0;
            rstMaskOff(0);
            /*for(char i = 0; i < 12; i++)
                Mask[i] = 0;
            //SeqVals[seqMASK] = 0;*/
            val2group(gMask, 0);
        }
        if(subContMaskOff == 8) {
            subContMaskOff = 0;
            indexMaskOff++;
        }
        char i = 0;
        for(i = 0; i < 6; i++) {
            Mask[i] = MaskSeq[i];
            Mask[11-i] = MaskSeq[i];
        }
        sendOrderX();
        /*for(char i = 0; i < 12; i++)//For Testing
            EUSART_Write(Mask[i]);*/
        contTimMaskOff++;
    }
}

void rstDemoOn(char start) {
    timDemoOn = 0;
    flagDemoOn = start;
}

void demoEfectOn(void) {//CallOn Timer
    if(timDemoOn < 600) {
        timDemoOn++;
        if(!lightsOn) {
            if(timDemoOn < 260) {
                fullBodyVal += 1;
                if(fullBodyVal >= 255) {
                    fullBodyVal = 255;
                    lightsOn = 1;
                }
                allBodyVal((char)fullBodyVal, GREEN);
                sendOrderX();
            }
        }else {
            rstDemoOn(0);
            UART3_Write('z');
            if(!musikRun)
                rstMusik(1);
        }
    }
}

void rstMusik(char start) {
    ritmCont = 0;
    noteNum = -5;
    stepsNote = 0;
    noteOnTempo = 0;
    musikRun = start;
}

void musik(void) {
    if(musikRun && ritmCont < 1100) {
        if(ritmCont < 1 && lightsOn) {
            valTempo = 255;
            valBip1 = 255;
            valBip2 = 255;
            UART3_Write('e');
        }
        stepsNote++;
        if(noteNum < 72) {
            if(noteOnTempo < 2) {
                valTempo -= 13;
                if(valTempo < 0)
                    valTempo = 0;
            }else if(noteOnTempo < 3){
                if(stepsNote > 4) {
                    valTempo += 13;
                    if(valTempo > 255)
                        valTempo = 255;
                }
            }else {
                valTempo += 13;
                if(valTempo > 255)
                    valTempo = 255;
            }
            if(noteNum == 5 || noteNum == 53) {
                valBip1 -= 20;
                valBip2 -= 20;
                if(valBip1 < 0) {
                    valBip1 = 0;
                    valBip2 = 0;
                }
            }else if(noteNum == 8 || noteNum == 56) {
                if(stepsNote < 1) {
                    valBip1 = 0;
                }else if(stepsNote < 7) {
                    valBip1 += 43;
                    if(valBip1 > 255)
                        valBip1 = 255;
                }else {
                    valBip1 -= 43;
                    if(valBip1 < 0)
                        valBip1 = 0;
                }
            }else if(noteNum == 11 || noteNum == 14 || 
                    noteNum == 59 || noteNum == 62){
                if(stepsNote < 5) {
                    if(stepsNote < 1) {
                        valBip1 = 0;
                    }else if(stepsNote < 3) {
                        valBip1 += 128;
                        if(valBip1 > 255)
                            valBip1 = 255;
                    }else {
                        valBip1 -= 128;
                        if(valBip1 < 0)
                            valBip1 = 0;
                    }
                }
            }else if(noteNum == 28/* || noteNum == 68*/) {
                valBip1 += 20;
                valBip2 += 20;
                if(valBip1 > 255) {
                    valBip1 = 255;
                    valBip2 = 255;
                }
            }else if(noteNum == 16 || noteNum == 17 || noteNum == 19 || 
                    noteNum == 20 || noteNum == 22 || noteNum == 64 || 
                    noteNum == 65 || noteNum == 67 || noteNum == 68 || 
                    noteNum == 70) {
                if(stepsNote < 5) {
                    if(stepsNote < 1) {
                        valBip2 = 0;
                    }else if(stepsNote < 3) {
                        valBip2 += 128;
                        if(valBip2 > 255)
                            valBip2 = 255;
                    }else {
                        valBip2 -= 128;
                        if(valBip2 < 0)
                            valBip2 = 0;
                    }
                }
            }
        }else {
            valBip1 += 20;
            valBip2 += 20;
            valTempo += 13;
            if(valTempo > 255)
                valTempo = 255;
            if(valBip1 > 255) {
                valBip1 = 255;
                valBip2 = 255;
                rstMusik(0);
            }
        }
        if(musikRun && stepsNote == 13) {
            stepsNote = 0;
            noteNum++;
            noteOnTempo++;
            if(noteOnTempo > 3)
                noteOnTempo = 0;
        }
        val2group(gBackUL, valTempo);
        val2group(gBackUR, valTempo);
        val2group(gBackM, valTempo);
        val2group(gBackD, valTempo);
        val2group(gNeckBL, valTempo);
        val2group(gNeckBR, valTempo);
        val2group(gNeckL, valTempo);
        val2group(gNeckR, valTempo);
        val2group(gShouldBL, valTempo);
        val2group(gShouldBR, valTempo);
        val2group(gCore, valBip2);
        val2group(gShouldFL, valBip2);//?
        val2group(gShouldFR, valBip2);//?
        val2group(gAbsUL, valBip1);
        val2group(gAbsUR, valBip1);
        val2group(gAbsML, valBip1);
        val2group(gAbsMR, valBip1);
        val2group(gAbsDL, valBip1);
        val2group(gAbsDR, valBip1);
        sendOrderX();
        ritmCont++;
    }
}

void rstDemoOff(char start) {
    timDemoOff = 0;
    flagDemoOff = start;
}

void demoEfectOff(void) {
    if(timDemoOff < 200) {
        timDemoOff++;
        if(timDemoOff <= 50) {
            fullBodyVal -= 5;
            if(fullBodyVal < 0)
                fullBodyVal = 0;
        }
        if(timDemoOff > 50 && timDemoOff <= 100) {
            fullBodyVal += 4;
            if(fullBodyVal > 100)
                fullBodyVal = 100;
        }
        if(timDemoOff > 100) {
            fullBodyVal -= 5;
            if(fullBodyVal < 0) {
                fullBodyVal = 0;
                resetAndOff(1);
            }
        }
        allBodyVal((char)fullBodyVal, GREEN);
        sendOrderX();
    }
}

void seqByZone_On(char num, short time) {
    if(time >= (firstDelay + delaysOn[num])) {
        SeqVals[num] += seqDeltasOn[num];
        if(SeqVals[num] >= 255)
            SeqVals[num] = 255;
    }
}

void seqByZone_Off(char num, short time) {
    if(time >= (130 + delaysOff[num])) {
        SeqVals[num] -= seqDeltasOff[num];
        if(SeqVals[num] < 0)
            SeqVals[num] = 0;
    }
}

void rstPressOn(char start) {
    timPresOn = 0;
    flagPressOn = start;
}

void SeqPresOn(void) {//CallOn Timer
    if(flagPressOn && timPresOn < 250) {
        timPresOn++;
        if(!soundASOn && timPresOn > 40/*/firstDelay/**/) {
            UART3_Write('g'); //Sound Press On
            soundASOn = 1;
        }
        seqByZone_On(seqCORE, timPresOn);
        seqByZone_On(seqMASK, timPresOn);
        seqByZone_On(seqFRONT, timPresOn);
        seqByZone_On(seqCRUZ1, timPresOn);
        seqByZone_On(seqCRUZ2, timPresOn);
        seqByZone_On(seqLEGS, timPresOn);
        if(timPresOn >= 240) {
            maskIsOn = 1;
            lightsOn = 1;
            fullBodyVal = 255;
            rstPressOn(0);
        }
        seqApply();
        sendOrderX();
    }
}

void rstPressOff(char start) {
    timPresOff = 0;
    flagPressOff = start;
}

void SeqPresOff(void) {//CallOn Timer
    if(flagPressOff && timPresOff < 320) {
        timPresOff++;
        if(!soundASOff && timPresOff > delaysOff[seqLEGS]) {
            UART3_Write('f'); //Sound Press Off
            soundASOff = 1;
        }
        seqByZone_Off(seqCORE, timPresOff);
        seqByZone_Off(seqMASK, timPresOff);
        seqByZone_Off(seqFRONT, timPresOff);
        seqByZone_Off(seqCRUZ1, timPresOff);
        seqByZone_Off(seqCRUZ2, timPresOff);
        seqByZone_Off(seqLEGS, timPresOff);
        if(timPresOff >= 305) {
            resetAndOff(1);
        }
        seqApply();
        sendOrderX();
    }
}

void seqApply(void) {
    //State[1] = {0};
    
    val2group(gCore, (char)SeqVals[seqCORE]);
    val2group(gMask, (char)SeqVals[seqMASK]);
    val2group(gShouldFL, (char)SeqVals[seqFRONT]);
    val2group(gShouldFR, (char)SeqVals[seqFRONT]);
    
    val2group(gAbsUR, (char)SeqVals[seqCRUZ1]);
    val2group(gAbsMR, (char)SeqVals[seqCRUZ1]);
    val2group(gAbsDR, (char)SeqVals[seqCRUZ1]);
    val2group(gShouldDR, (char)SeqVals[seqCRUZ1]);
    val2group(gNeckL, (char)SeqVals[seqCRUZ1]);
    val2group(gShouldBL, (char)SeqVals[seqCRUZ1]);
    val2group(gNeckBR, (char)SeqVals[seqCRUZ1]);
    val2group(gBackUL, (char)SeqVals[seqCRUZ1]);
    
    val2group(gAbsUL, (char)SeqVals[seqCRUZ2]);
    val2group(gAbsML, (char)SeqVals[seqCRUZ2]);
    val2group(gAbsDL, (char)SeqVals[seqCRUZ2]);
    val2group(gShouldDL, (char)SeqVals[seqCRUZ2]);
    val2group(gNeckR, (char)SeqVals[seqCRUZ2]);
    val2group(gShouldBR, (char)SeqVals[seqCRUZ2]);
    val2group(gNeckBL, (char)SeqVals[seqCRUZ2]);
    val2group(gBackUR, (char)SeqVals[seqCRUZ2]);
    val2group(gBackM, (char)SeqVals[seqCRUZ2]);
    //val2group(gBackD, (char)SeqVals[seqCRUZ2]);
    
    val2group(gLegUL, (char)SeqVals[seqLEGS]);
    val2group(gLegUR, (char)SeqVals[seqLEGS]);
    val2group(gLegDL, (char)SeqVals[seqLEGS]);
    val2group(gLegDR, (char)SeqVals[seqLEGS]);
    val2group(gShoeL, (char)SeqVals[seqLEGS]);
    val2group(gShoeR, (char)SeqVals[seqLEGS]);
}
/************Light Effects*********************************/

/************Light Resources*********************************/
/*void apply2Dummy(char out, char in) {
    dummyValue[out] = groupValue[in];
    dummyColor[out] = groupColor[in];
}*/

void applyColor(char group, char color, char intensity) {
    groupColor[group] = color;
    val2group(group, intensity);
}

void rstSeq(void) {
    char i = 0;
    for(i = 0; i < 6; i++)
        SeqVals[i] = 0;
}

void allBodyVal(char val, char color) {
    char i = 0;
    for(i = 0; i < 30; i++)
        applyColor(i, color, val);
}

void resetAndOff(char light) {
    soundASOn = 0;
    soundASOff = 0;
    maskIsOn = 0;
    lightsOn = 0;
    rstPressOn(0);
    rstPressOff(0);
    rstSeq();
    rstDemoOn(0);
    rstDemoOff(0);
    rstMaskOn(0);
    rstMaskOff(0);
    rstShadow(0);
    rstDragon(0);
    rstMusik(0);
    secCont = 0;
    stepContDemo = 0;
    stepContPress = 0;
    dragonCrashDone = 0;
    refriShoulderDone = 0;
    //applyColor(gBridge, GREEN, 0);
    run = 0;
    if(light) {
        fullBodyVal = 0;
        allBodyVal(0, GREEN);
    }
    sendOrderX();
}
/************Light Resources*********************************/

void execMask_Sword(void) {
    if(modoPress_nDemo) {
        if(lightsOn) {
            if(maskIsOn)
                rstMaskOff(1);
            else
                rstMaskOn(1);
        }
    }else
        UART3_Write('s');//Demo Sonido Sword en Celular
}

void initStop(void) {
    if(modoPress_nDemo) {
        rstPressOn(!run);
        rstPressOff(run);
        if(run) {
            lightsOn = 0;
            soundASOn = 0;
        }else
            soundASOff = 0;
    }else {
        if(!flagDemoOn && !musikRun)
            rstDemoOn(1);
    }
    if(!run)
        run = 1;
}

/************Interruptions*******************************/
void pTMR1_ISR(void) { //10.4 ms steps
    if(waiter < 10)
        waiter++;
    if(run) {
        if(flagPressOn)
            SeqPresOn();
        else if(flagPressOff)
            SeqPresOff();
        else if(flagDemoOn)
            demoEfectOn();
        else if(flagDemoOff)
            demoEfectOff();
        else if(modoPress_nDemo) {
            maskOn();
            maskOff();
            stepContPress++;
            if(stepContPress >= 96) {//96 = 1 sec
                secCont++;
                stepContPress = 0;
            }
            if(!dragonCrashDone) {
                if(!runCrash && secCont == 7) {
                    rstDragon(1);
                }
                dragonCrash();
            }
            if(!refriShoulderDone) {
                if(secCont == 150)
                    refriShoulder(1);
                if(secCont == 151)
                    refriShoulder(0);
                if(secCont == 153)
                    refriShoulder(1);
                if(secCont == 154)
                    refriShoulder(0);
                if(secCont == 156)
                    refriShoulder(1);
                if(secCont == 157) {
                    refriShoulder(0);
                    refriShoulderDone = 1;
                }
            }
            sendOrderX();
        }else {
            if(lightsOn && !runShadow) {
                stepContDemo++;
                if(stepContDemo >= 96) {//96 = 1 sec
                    secCont++;
                    stepContDemo = 0;
                }
                if(secCont >= 30) {
                    secCont = 0;
                    stepContDemo = 0;
                    rstShadow(1);
                }
            }
            if(!musikRun)
                despShadow();
            musik();
        }
    }
}

void pTMR2_ISR(void) { //500 ms steps
    STA_Toggle();
    //o3_Toggle();
    //o4_Toggle();
}

void pRX2_ISR(void) { //Antena ESP32
    char cha = U2RXREG;
    //STA_Toggle();
    //UART2_Write(cha);
    IFS1bits.U2RXIF = 0;
}

void pRX3_ISR(void) { //Antena HC-05, IO1 e IO3
    char cha = U3RXREG;
    if(cha == 'o')
        butt3Pres(1);
    else if(cha == 'd')
        butt3Pres(0);
    else if(cha == 'a')
        butt1Pres(0);
    else if(cha == 'b')
        butt2Pres(0);
    IFS1bits.U3RXIF = 0;
}
/************Interruptions*******************************/

void butt1Pres(char state) {
    UART3_Write('a');
    initStop();
}

void butt2Pres(char state) {
    execMask_Sword();
}

void butt3Pres(char state) {
    if(state) {
        UART3_Write('o');//demo off
        modoPress_nDemo = 1;
        if(lightsOn) {
            resetAndOff(0);
            rstDemoOff(1);
            run = 1;
            UART3_Write('f'); //Sound Press Off
        }else
            resetAndOff(1);
    }else {
        UART3_Write('d');//demo on
        modoPress_nDemo = 0;
        resetAndOff(1);
    }
}

/************Resources*******************************/
void waitX0ms(char X) { //Must be < 11 (X * 10.4 ms)
    waiter = 0;
    while(waiter < X);//__delay_ms(X0);
}

void dotTest(char cantDot) {
    char i = 0;
    for(i = 0; i < cantDot; i++) {
        char i2 = 0;
        dotStart(i2);
        for(i2 = 0; i2 < cantDot; i2++) {
            sendDotStar(0, dotValue[i2], 0);
            dotValue[i2] = 0;
        }
        sendDotStar(10,10,10);
        dotValue[i] = 255;
        waitX0ms(10);
    }
}
/************Resources*******************************/

int main(void) {
    SYSTEM_Initialize(); // initialize the device
    TMR1_SetInterruptHandler(pTMR1_ISR); //10.4ms Steps
    TMR2_SetInterruptHandler(pTMR2_ISR); //BlinkLED (500 ms)

    //UART2_SetRxInterruptHandler(pRX2_ISR);
    UART3_SetRxInterruptHandler(pRX3_ISR);
    spi2_open(MASTER0_CONFIG);
    
    /*W_EN_SetLow();
    W_BOOT_SetHigh();
    W_EN_SetHigh();*/
    
    resetAndOff(1);
    butt3Pres(!in3_GetValue());//Check Switch State
    
    while (1)
    {
        if(!bLs1) { //Boton 1 AKA On/Off
            if(!in1_GetValue()) {
                bLs1 = 1;
                butt1Pres(1);
            }
        }else {
            if(in1_GetValue())
                bLs1 = 0;
        }
        if(!bLs2) { //Boton 2 AKA Mask/Sword
            if(!in2_GetValue()) {
                bLs2 = 1;
                butt2Pres(1);
            }
        }else {
            if(in2_GetValue())
                bLs2 = 0;
        }
        if(!bLs3) { //Boton 3 AKA SelectDemo
            if(!in3_GetValue()) {
                bLs3 = 1;
                butt3Pres(1);
                waitX0ms(5);
            }
        }else {
            if(in3_GetValue()) {
                bLs3 = 0;
                butt3Pres(0);
                waitX0ms(5);
            }
        }
        if(bLs1)
            waitX0ms(5);
        if(bLs2)
            waitX0ms(5);
        //dotTest(71);
    }
    return 1; 
}
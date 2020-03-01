#include "main.h"

short fullBodyVal = 0;
char run = 0;
char runMaskOn = 0;
char runMaskOff = 0;
char flagPressOn = 0;
char flagPressOff = 0;
char flagDemoOn = 0;
char flagDemoOff = 0;
char bLs1 = 0;
char bLs2 = 0;
char bLs3 = 0;
short timPresOn = 0;
short timPresOff = 0;
short timDemoOn = 0;
short timDemoOff = 0;
char subContMaskOff = 0;
char subContShadow = 0;
short contTimMaskOn = 0;
short contTimMaskOff = 0;
short indexMaskOn = 0;
char indexMaskOff = 0;
char indexShadow = 0;
char runShadow = 0;
short contTimShadow = 0;
/****Steps of 10.4_ms Nucleo, Mask, hombF, Cruz1, Cruz2, Parte Baja****/
short firstDelay = 152;
short delaysOn[6] = {0,4,28,36,44,52};
char seqDeltasOn[6] = {8,6,5,6,7,9};
//char durations[6] = {32,44,52,44,36,28};
short delaysOff[6] = {48,32,0,0,0,0};//short delaysOff[6] = {140,60,24,16,0};//10.4ms blocks
char seqDeltasOff[6] = {3,5,5,6,7,9};
short delaysDemo[6] = {0,0,0,28,36,52};
signed short SeqVals[6] = {0,0,0,0,0,0};
char seqMaskOn[10] = {77,0,77,128,102,51,0,102,179,255};
/**********************************************************************/
char modoPress_nDemo = 0;
char lightsOn = 0;
char maskIsOn = 0;
char soundASOn = 0;
char soundASOff = 0;
unsigned long secCont = 0;
short minCont = 0;
char stepContDemo = 0;
char stepContPress = 0;
char dragonCrashDone = 0;
char refriShoulderDone = 0;

char dummyCant = 29;
char dummyValue[29] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char dummyColor[29] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

char dotCant = 124;
char dotValue[124] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0/*,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*/};
char dotColor[124] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0/*,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*/};

char buff1[124] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0/*,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*/};

char buff2[124] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0/*,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*/};

char State[1] = {0}; //0 (Nup)
char Mask[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; //1
char Core[11] = {0,0,0,0,0,0,0,0,0,0,0}; //2
char ShouldFL[3] = {0,0,0}; //3
char ShouldFR[3] = {0,0,0}; //4
char ShouldDL[3] = {0,0,0}; //5
char ShouldDR[3] = {0,0,0}; //6
char ShouldBL[3] = {0,0,0}; //7
char ShouldBR[3] = {0,0,0}; //8
char NeckL[3] = {0,0,0}; //9
char NeckR[3] = {0,0,0}; //10
char NeckBL[4] = {0,0,0,0}; //11
char NeckBR[4] = {0,0,0,0}; //12
char NeckBRcolor[4] = {0,0,0,0}; //NeckBR Color for Effect
char AbsUL[4] = {0,0,0,0}; //13
char AbsUR[4] = {0,0,0,0}; //14
char AbsML[3] = {0,0,0}; //15
char AbsMR[3] = {0,0,0}; //16
char AbsDL[3] = {0,0,0}; //17
char AbsDR[3] = {0,0,0}; //18
char BackUL[3] = {0,0,0}; //19
char BackUR[3] = {0,0,0}; //20
char BackUM[3] = {0,0,0}; //21
char BackD[3] = {0,0,0}; //22 (Nup)
char LegUL[6] = {0,0,0,0,0,0}; //23
char LegUR[6] = {0,0,0,0,0,0}; //24
char LegDL[6] = {0,0,0,0,0,0}; //25
char LegDR[6] = {0,0,0,0,0,0}; //26
char ShoeL[8] = {0,0,0,0,0,0,0,0}; //27
char ShoeR[8] = {0,0,0,0,0,0,0,0}; //28
char Bridge[1] = {0}; //29

//char groupCant = 30;
char groupSize[30] = {1,12,11,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,6,6,6,6,8,8,1};
char groupValue[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char groupColor[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

signed short shadowArray[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
signed short MaskSeq[6] = {0,0,0,0,0,0};
char dragonArray[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char dragonColor = 0;

char runCrash = 0;
char indexCrash = 0;
short contCrash = 0;
char subContCrash = 0;
signed short intensityCrash = 0;
char deltaCrash = 16;//17?

char musikRun = 0;
unsigned short ritmCont = 0;
char indexR = 0;
signed short valTempo = 0;
signed short valBip1 = 0;
signed short valBip2 = 0;
char stepsNote = 0;
char noteOnTempo = 0;
signed char noteNum = 0;

char waiter = 0;

char groupBuff[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
}

void merger(void) {
    char preAccum = 0;
    char accum = 0;
    char i = 0;
    accum = mergeGroup(gState, accum);
    accum = mergeGroup(gBridge, accum);
    accum = mergeGroup(gBackUL, accum);
    /*for(i = 0; i < groupSize[gBackUL]; i++) {
        dotValue[i + accum] = BackUL[i];
        dotColor[i + accum] = groupColor[gBackUL];
    }
    accum += groupSize[gBackUL];*/
    accum = mergeGroup(gBackM, accum);
    /*for(i = 0; i < groupSize[gBackM]; i++) {
        dotValue[i + accum] = BackUM[i];
        dotColor[i + accum] = groupColor[gBackM];
    }
    accum += groupSize[gBackM];*/
    accum = mergeGroup(gBackUR, accum);
    /*for(i = 0; i < groupSize[gBackUR]; i++) {
        dotValue[i + accum] = BackUR[i];
        dotColor[i + accum] = groupColor[gBackUR];
    }
    accum += groupSize[gBackUR];*/
    //accum = mergeGroup(gBackD, accum); //Nup
    accum = mergeGroup(gShouldBR, accum);
    /*for(i = 0; i < groupSize[gShouldBR]; i++) {
        dotValue[i + accum] = ShouldBR[i];
        dotColor[i + accum] = groupColor[gShouldBR];
    }
    accum += groupSize[gShouldBR];*/
    accum = mergeGroup(gShouldDR, accum);
    /*for(i = 0; i < groupSize[gShouldDR]; i++) {
        dotValue[i + accum] = ShouldDR[i];
        dotColor[i + accum] = groupColor[gShouldDR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gShouldFR, accum);
    /*for(i = 0; i < groupSize[gShouldFR]; i++) {
        dotValue[i + accum] = ShouldFR[i];
        dotColor[i + accum] = groupColor[gShouldFR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gNeckR, accum);
    /*for(i = 0; i < groupSize[gNeckR]; i++) {
        dotValue[i + accum] = NeckL[i];
        dotColor[i + accum] = groupColor[gNeckR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gNeckL, accum);
    /*for(i = 0; i < groupSize[gNeckL]; i++) {
        dotValue[i + accum] = NeckL[i];
        dotColor[i + accum] = groupColor[gNeckL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gShouldBL, accum);
    /*for(i = 0; i < groupSize[gShouldBL]; i++) {
        dotValue[i + accum] = ShouldBL[i];
        dotColor[i + accum] = groupColor[gShouldBL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gShouldDL, accum);
    /*for(i = 0; i < groupSize[gShouldDL]; i++) {
        dotValue[i + accum] = ShouldDL[i];
        dotColor[i + accum] = groupColor[gShouldDL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gShouldFL, accum);
    /*for(i = 0; i < groupSize[gShouldFL]; i++) {
        dotValue[i + accum] = ShouldFL[i];
        dotColor[i + accum] = groupColor[gShouldFL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gCore, accum);
    /*for(i = 0; i < groupSize[gCore]; i++) {
        dotValue[i + accum] = Core[i];
        dotColor[i + accum] = groupColor[gCore];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gAbsUL, accum);
    /*for(i = 0; i < groupSize[gAbsUL]; i++) {
        dotValue[i + accum] = AbsUL[i];
        dotColor[i + accum] = groupColor[gAbsUL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gAbsUR, accum);
    /*for(i = 0; i < groupSize[gAbsUR]; i++) {
        dotValue[i + accum] = AbsUR[i];
        dotColor[i + accum] = groupColor[gAbsUR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gAbsMR, accum);
    /*for(i = 0; i < groupSize[gAbsMR]; i++) {
        dotValue[i + accum] = AbsMR[i];
        dotColor[i + accum] = groupColor[gAbsMR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gAbsML, accum);
    /*for(i = 0; i < groupSize[gAbsML]; i++) {
        dotValue[i + accum] = AbsML[i];
        dotColor[i + accum] = groupColor[gAbsML];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gAbsDL, accum);
    /*for(i = 0; i < groupSize[gAbsDL]; i++) {
        dotValue[i + accum] = AbsDL[i];
        dotColor[i + accum] = groupColor[gAbsDL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gAbsDR, accum);
    /*for(i = 0; i < groupSize[gAbsDR]; i++) {
        dotValue[i + accum] = AbsDR[i];
        dotColor[i + accum] = groupColor[gAbsDR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    
    accum = mergeGroup(gMask, accum);
    /*for(i = 0; i < groupSize[gMask]; i++) {
        dotValue[i + accum] = Mask[i];
        dotColor[i + accum] = groupColor[gMask];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gNeckBL, accum);
    /*for(i = 0; i < groupSize[gNeckBL]; i++) {
        dotValue[i + accum] = NeckBL[i];
        dotColor[i + accum] = groupColor[gNeckBL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    for(i = 0; i < groupSize[gNeckBR]; i++) { //accum = mergeGroup(gNeckBR, accum);
        dotValue[i + accum] = NeckBR[i];
        dotColor[i + accum] = NeckBRcolor[i];//groupColor[gNeckBR];
    }
    accum += groupSize[gNeckBR];
    accum = mergeGroup(gLegUL, accum);
    /*for(i = 0; i < groupSize[gLegUL]; i++) {
        dotValue[i + accum] = LegUL[i];
        dotColor[i + accum] = groupColor[gLegUL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gLegUR, accum);
    /*for(i = 0; i < groupSize[gLegUR]; i++) {
        dotValue[i + accum] = LegUR[i];
        dotColor[i + accum] = groupColor[gLegUR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gLegDL, accum);
    /*for(i = 0; i < groupSize[gLegDL]; i++) {
        dotValue[i + accum] = LegDL[i];
        dotColor[i + accum] = groupColor[gLegDL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gLegDR, accum);
    /*for(i = 0; i < groupSize[gLegDR]; i++) {
        dotValue[i + accum] = LegDR[i];
        dotColor[i + accum] = groupColor[gLegDR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gShoeL, accum);
    /*for(i = 0; i < groupSize[gShoeL]; i++) {
        dotValue[i + accum] = ShoeL[i];
        dotColor[i + accum] = groupColor[gShoeL];
        preAccum = i + 1;
    }
    accum += preAccum;*/
    accum = mergeGroup(gShoeR, accum);
    /*for(i = 0; i < groupSize[gShoeR]; i++) {
        dotValue[i + accum] = ShoeR[i];
        dotColor[i + accum] = groupColor[gShoeR];
        preAccum = i + 1;
    }
    accum += preAccum;*/
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
    
    applyColor(gBridge, GREEN, 0);
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
    char i = 0;
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
    }
    sendDotStar(10,10,10); //One more Pixel on White???
}
/************DotStar Drivers*******************************/

/************Light Effects*********************************/
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
            subContShadow = 0;
            indexShadow = 0;
            contTimShadow = 0;
            runShadow = 0;
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

void dragonCrash(void) {
    if(runCrash && contCrash < 1500) {
        subContCrash++;
        if(indexCrash < 15) {
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
        }else if(indexCrash < 18){
            //La lala lala
        }else if(indexCrash < 33){
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
        }else {
            subContCrash = 0;
            indexCrash = 0;
            contCrash = 0;
            dragonCrashDone = 1;
            runCrash = 0; 
        }
        if(subContCrash >= 32) {
            indexCrash++;
            intensityCrash = 255;
            subContCrash = 0;
        }
        applyColor(gShouldDR, dragonArray[0], 255);
        applyColor(gShouldFR, dragonArray[1], 255);
        applyColor(gShouldBR, dragonArray[2], 255);
        applyColor(gNeckR, dragonArray[3], 255);
        applyColor(gAbsUR, dragonArray[4], 255);
        applyColor(gBackUR, dragonArray[5], 255);
        NeckBR[3] = 255; NeckBRcolor[3] = dragonArray[6];
        applyColor(gAbsMR, dragonArray[7], 255);
        NeckBR[2] = 255; NeckBRcolor[2] = dragonArray[8];
        applyColor(gAbsDR, dragonArray[9], 255);
        NeckBR[1] = 255; NeckBRcolor[1] = dragonArray[10];
        applyColor(gLegUR, dragonArray[11], 255);
        NeckBR[0] = 255; NeckBRcolor[0] = dragonArray[12];
        applyColor(gLegDR, dragonArray[13], 255);
        applyColor(gShoeR, dragonArray[14], 255);
        sendOrderX();
        contCrash++;
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

void maskOn(void) {//CallOn Timer
    if(runMaskOn && contTimMaskOn < 60) {
        contTimMaskOn ++;
        if(contTimMaskOn == (short)4*(indexMaskOn + 1)) {
            //SeqVals[seqMASK] = seqMaskOn[indexMaskOn];
            val2group(gMask, seqMaskOn[indexMaskOn]);
            indexMaskOn++;
            sendOrderX();
            if(indexMaskOn >= 10) {
                maskIsOn = 1;
                indexMaskOn = 0;
                contTimMaskOn = 0;
                runMaskOn = 0;
            }
        }
    }
}

void maskOff(void) {
    if(runMaskOff && contTimMaskOff < 100) {
        if(contTimMaskOff < 1) {
            char i = 0;
            for(i = 0; i < 6; i++)
                MaskSeq[i] = 255;
        }
        subContMaskOff++;
        if(indexMaskOff < 7) {
            /*for(char i = 0; i < 12; i++)
                Mask[i] = 255;*/
            if(indexMaskOff < 6) {
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
        }else if(indexMaskOff < 12) {
            if(indexMaskOff < 11) {
                MaskSeq[10-indexMaskOff] -= 16;
                if(MaskSeq[10-indexMaskOff] < 0)
                    MaskSeq[10-indexMaskOff] = 0;
            }
            MaskSeq[11-indexMaskOff] -= 16;
            if(MaskSeq[11-indexMaskOff] < 0)
                MaskSeq[11-indexMaskOff] = 0;
        }else {
            char i = 0;
            for(i = 0; i < 6; i++)
                MaskSeq[i] = 0;
            maskIsOn = 0;
            runMaskOff = 0;
            contTimMaskOff = 0;
            subContMaskOff = 0;
            indexMaskOff = 0;
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

void demoEfectOn(void) {//CallOn Timer
    if(flagDemoOn && timDemoOn < 600) {
        timDemoOn++;
        if(!lightsOn) {
            if(timDemoOn < 260) {
                fullBodyVal += 1;//8;
                if(fullBodyVal >= 255) {
                    fullBodyVal = 255;
                    timDemoOn = 0;
                    lightsOn = 1;
                    UART3_Write('z');
                }
                allBodyVal((char)fullBodyVal, GREEN);
                sendOrderX();
            }
        }else {
            if(!musikRun) {
                ritmCont = 0;
                indexR = 0;
                noteNum = -5;
                stepsNote = 0;
                noteOnTempo = 0;
                musikRun = 1;
                flagDemoOn = 0;
            }
        }
    }
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
                ritmCont = 0;
                indexR = 0;
                noteNum = -5;
                stepsNote = 0;
                noteOnTempo = 0;
                musikRun = 0;
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

void demoEfectOff(void) {
    if(flagDemoOff && timDemoOff < 200) {
        timDemoOff++;
        if(timDemoOff <= 50) {
            fullBodyVal -= 5;
            if(fullBodyVal <= 0)
                fullBodyVal = 0;
        }
        if(timDemoOff > 50 && timDemoOff <= 100) {
            fullBodyVal += 4;
            if(fullBodyVal >= 100)
                fullBodyVal = 100;
        }
        if(timDemoOff > 100) {
            fullBodyVal -= 5;
            if(fullBodyVal <= 0) {
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
        /*char num = 0;
        for(num = 0; num < 6; num++)
            EUSART_Write(SeqVals[num]);*/
        if(timPresOn >= 240) {
            maskIsOn = 1;
            lightsOn = 1;
            fullBodyVal = 255;
            flagPressOn = 0;
        }
        seqApply();
        sendOrderX();
    }
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
void apply2Dummy(char out, char in) {
    dummyValue[out] = groupValue[in];
    dummyColor[out] = groupColor[in];
}

void applyColor(char group, char color, char intensity) {
    groupColor[group] = color;
    val2group(group, intensity);
}

void allBodyVal(char val, char color) {
    char i = 0;
    for(i = 0; i < 29; i++)
        applyColor(i, color, val);
}

void resetAndOff(char light) {
    soundASOn = 0;
    soundASOff = 0;
    maskIsOn = 0;
    lightsOn = 0;
    flagPressOn = 0;
    flagPressOff = 0;
    flagDemoOn = 0;
    flagDemoOff = 0;
    runMaskOn = 0;
    runMaskOff = 0;
    runShadow = 0;
    musikRun = 0;
    subContShadow = 0;
    indexShadow = 0;
    contTimShadow = 0;
    secCont = 0;
    stepContDemo = 0;
    dragonCrashDone = 0;
    refriShoulderDone = 0;
    stepContPress = 0;
    subContCrash = 0;
    indexCrash = 0;
    contCrash = 0;
    dragonCrashDone = 0;
    runCrash = 0;
    applyColor(gBridge, GREEN, 0);
    run = 0;
    if(light) {
        fullBodyVal = 0;
        allBodyVal(0, GREEN);
        sendOrderX();
    }
}
/************Light Resources*********************************/

void execMask_Sword(void) {
    if(modoPress_nDemo) {
        if(lightsOn) {
            indexMaskOn = 0;
            contTimMaskOn = 0;
            runMaskOn = !maskIsOn;
            if(maskIsOn) {//mascara activa
                indexMaskOff = 0;
                contTimMaskOff = 0;
                runMaskOff = 1;
            }
        }
    }else
        UART3_Write('s');//Demo Sonido Sword en Celular
}

void initStop(void) {
    if(run) {
        if(modoPress_nDemo) {
            flagPressOn = 0;
            flagPressOff = 1;
            timPresOff = 0;
            lightsOn = 0;
            soundASOn = 0;
        }
    }else {
        if(modoPress_nDemo) {
            flagPressOff = 0;
            flagPressOn = 1;
            timPresOn = 0;
            soundASOff = 0;
        }
        run = 1;
    }
    if(!modoPress_nDemo && !flagDemoOn && !musikRun) {
        timDemoOn = 0;
        flagDemoOn = 1;
    }
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
                if(secCont == 50) {
                    subContCrash = 0;
                    indexCrash = 0;
                    contCrash = 0;
                    intensityCrash = 255;
                    runCrash = 1;
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
        }
        if(!modoPress_nDemo) {
            if(lightsOn && !runShadow) {
                stepContDemo++;
                if(stepContDemo >= 96) {//96 = 1 sec
                    secCont++;
                    stepContDemo = 0;
                }
                if(secCont >= 30) {
                    secCont = 0;
                    stepContDemo = 0;
                    subContShadow = 0;
                    contTimShadow = 0;
                    indexShadow = 0;
                    runShadow = 1;
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
    if(cha == 'W')
        musikRun = 1;
    if(cha == 'Y')
        musikRun = 0;
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
            timDemoOff = 0;
            flagDemoOff = 1;
            musikRun = 0;
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
    TMR2_SetInterruptHandler(pTMR2_ISR); //BlinkLED

    //UART2_SetRxInterruptHandler(pRX2_ISR);
    UART3_SetRxInterruptHandler(pRX3_ISR);
    spi2_open(MASTER0_CONFIG);
    
    /*W_EN_SetLow();
    W_BOOT_SetHigh();
    W_EN_SetHigh();*/
    
    resetAndOff(1);
    //butt3Pres(1);
    
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
        //dotTest(64);
    }
    return 1; 
}
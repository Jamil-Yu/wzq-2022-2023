#ifndef _WZQ_H
#define _WZQ_H
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 2
//first def of scores
#define FIVE 1000000 //11111
#define FOUR 10000 //011110
#define DEAD_FOUR 1000 //211110 011112 11101 11011 10111
#define THREE 1000 //011100 011010 010110 001110
#define DEAD_THREE 100 //211100 211010 210110 210101
#define TWO 100
#define DEAD_TWO 10
#define ONE 10
#define DEAD_ONE 1
//more specifically
#define WULIAN 100000
#define HUOSI 10000
#define LIANSI 1000
#define TIAOSI 1000
#define LIANHUOSAN 1000
#define TIAOHUOSAN 1000
#define JIAHUOSAN 100
#define MIANSAN 100
#define HUOER 100
#define MIANER 10
//structs
struct SingleInfo {
    int linkNum;
    int oppNum;
};
struct SingleScore
{
    struct SingleInfo info[4];
    int score;
};
struct point
{
    int x;
    int y;
};
//arrays
int arrayForInnerBoardLayout[SIZE][SIZE];
//functions
int BLACK_WHITE(int x,int y);
int black_x,black_y,white_x,white_y;
#endif
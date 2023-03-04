#include "wzq.h"

//this file: score of every point.

int updateScore(int n);
struct point best_choice(int n);//n=1 means ai is black, n=2 means ai is white
void initScore(void);
struct SingleScore myBoardScore[15][15];
struct SingleScore oppBoardScore[15][15];

void initScore(void)
{
    int i,j;
    for ( i = 0; i < 15; i++)
    {
        for ( j = 0; j < 15; j++)
        {
            myBoardScore[i][j].score = 0;
            oppBoardScore[i][j].score = 0;
        }
        
    }
    
}

int updateScore(int n)//n=1 means ai is black, n=2 means ai is white. return fullscore
{
    initScore();
    int x, y,i,j,k,opp,score,space;
    int allscore = 0;
    for ( x = 0; x < 15; x++)
    {
        for ( y = 0; y < 15; y++)
        {
            if (BLACK_WHITE(x,y)==0)
            {
                if (n==1)//ai is black
                {
                    //dim0
                    i=1;
                    j=1;
                    opp=0;
                    space=0;
                    while (y-i>=0 && BLACK_WHITE(x,y-i)==1)
                        i++;            
                    while (y+j<=14 && BLACK_WHITE(x,y+j)==1)
                        j++;
                    myBoardScore[x][y].info[0].linkNum = i+j-1;//LIANZI
                    if (y-i>=0 && BLACK_WHITE(x,y-i)==0 && y-i-1>=0 && BLACK_WHITE(x,y-i-1)==1){
                        i+=2;
                        myBoardScore[x][y].info[0].linkNum ++;
                        space++;
                        while (y-i>=0 && BLACK_WHITE(x,y-i)==1){
                            i++; 
                            myBoardScore[x][y].info[0].linkNum++;
                        }
                    }//jump 1
                    if (y+j<=14 && BLACK_WHITE(x,y+j)==0 && y+j+1<=14 && BLACK_WHITE(x,y+j+1)==1){
                        j+=2;
                        myBoardScore[x][y].info[0].linkNum ++;
                        space++;
                        while (y+j<=14 && BLACK_WHITE(x,y+j)==1){
                            j++;
                            myBoardScore[x][y].info[0].linkNum++;
                        }
                    }
                    if (space = 2)
                        myBoardScore[x][y].info[0].linkNum --;
                    if (y-i<0 || BLACK_WHITE(x,y-i)==2)
                        opp++;  
                    if (y+j>14 || BLACK_WHITE(x,y+j)==2)
                        opp++; 
                    if (opp!=2 && i+j<5) {
                        while (y-i>=0 && BLACK_WHITE(x,y-i)!=2)
                            i++;                    
                        while (y+j<=14 && BLACK_WHITE(x,y+j)!=2)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    myBoardScore[x][y].info[0].oppNum = opp;
                    /*
                    i=1;
                    j=1;
                    opp=0;
                    while (y-i>=0 && BLACK_WHITE(x,y-i)==2)
                        i++;
                    if (y-i<0 || BLACK_WHITE(x,y-i)==1)
                        opp++;
                    while (y+j<=14 && BLACK_WHITE(x,y+j)==2)
                        j++;
                    if (y+j>14 || BLACK_WHITE(x,y+j)==1)
                        opp++;
                    oppBoardScore[x][y].info[0].linkNum = i+j-1;
                    if (opp!=2 && i+j<5) {
                        while (y-i>=0 && BLACK_WHITE(x,y-i)!=1)
                            i++;                    
                        while (y+j<=14 && BLACK_WHITE(x,y+j)!=1)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    oppBoardScore[x][y].info[0].oppNum = opp;
                    */
                    //dim1
                    i=1;
                    j=1;
                    opp=0;
                    space=0;
                    while (x-i>=0 && BLACK_WHITE(x-i,y)==1)
                        i++;
                    
                    while (x+j<=14 && BLACK_WHITE(x+j,y)==1)
                        j++;
                    myBoardScore[x][y].info[1].linkNum = i+j-1;
                    if (x-i>=0 && BLACK_WHITE(x-i,y)==0 && x-i-1>=0 && BLACK_WHITE(x-i-1,y)==1){
                        i+=2;
                        myBoardScore[x][y].info[1].linkNum ++;
                        space++;
                        while (x-i>=0 && BLACK_WHITE(x-i,y)==1){
                            i++; 
                            myBoardScore[x][y].info[1].linkNum++;
                        }
                    }
                    if (x+j<=14 && BLACK_WHITE(x+j,y)==0 && x+j+1<=14 && BLACK_WHITE(x+j+1,y)==1){
                        j+=2;
                        myBoardScore[x][y].info[1].linkNum ++;
                        space++;
                        while (x+j<=14 && BLACK_WHITE(x+j,y)==1){
                            j++;
                            myBoardScore[x][y].info[1].linkNum++;
                        }
                    }
                    if (space = 2)
                        myBoardScore[x][y].info[1].linkNum --;
                    if (x-i<0 || BLACK_WHITE(x-i,y)==2)
                        opp++;
                    if (x+j>14 || BLACK_WHITE(x+j,y)==2)
                        opp++;
                    if (opp!=2 && i+j<5) {
                        while (x-i>=0 && BLACK_WHITE(x-i,y)!=2)
                            i++;                    
                        while (x+j<=14 && BLACK_WHITE(x+j,y)!=2)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    myBoardScore[x][y].info[1].oppNum = opp;
                    
                    //dim2
                    i=1;
                    j=1;
                    opp=0;
                    space=0;
                    while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)==1)
                        i++;
                    while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)==1)
                        j++;
                    myBoardScore[x][y].info[2].linkNum = i+j-1;
                    ///
                    if (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==0 && x-i-1>=0 && y-i-1>0 && BLACK_WHITE(x-i-1,y-i-1)==1){
                        i+=2;
                        myBoardScore[x][y].info[2].linkNum ++;
                        space++;
                        while (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==1){
                            i++; 
                            myBoardScore[x][y].info[2].linkNum++;
                        }
                    }
                    if (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==0 && x+j+1<=14 && y+j+1<=14 && BLACK_WHITE(x+j+1,y+j+1)==1){
                        j+=2;
                        myBoardScore[x][y].info[2].linkNum ++;
                        space++;
                        while (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==1){
                            j++;
                            myBoardScore[x][y].info[2].linkNum++;
                        }
                    }
                    if (space = 2)
                        myBoardScore[x][y].info[2].linkNum --;
                    if (y-i<0 || x-i<0 || BLACK_WHITE(x-i,y-i)==2)
                        opp++;
                    if (y+j>14 || x+j>14 || BLACK_WHITE(x+j,y+j)==2)
                        opp++;
                    if (opp!=2 && i+j<5) {
                        while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)!=2)
                            i++;                    
                        while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)!=2)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    myBoardScore[x][y].info[2].oppNum = opp;
                   
                    //dim3
                    i=1;
                    j=1;
                    opp=0;
                    space=0;
                    while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)==1)
                        i++;
                    while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)==1)
                        j++;
                    myBoardScore[x][y].info[3].linkNum = i+j-1;
                    //
                    if (x+i<=14 && y-i>=0 && BLACK_WHITE(x+i,y-i)==0 && x+i+1<=14 && y-i-1>0 && BLACK_WHITE(x+i+1,y-i-1)==1){
                        i+=2;
                        myBoardScore[x][y].info[3].linkNum ++;
                        space++;
                        while (x+i>=0 && y-i>=0 && BLACK_WHITE(x+i,y-i)==1){
                            i++; 
                            myBoardScore[x][y].info[3].linkNum++;
                        }
                    }
                    if (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==0 && x-j-1<=14 && y+j+1<=14 && BLACK_WHITE(x-j-1,y+j+1)==1){
                        j+=2;
                        myBoardScore[x][y].info[3].linkNum ++;
                        space++;
                        while (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==1){
                            j++;
                            myBoardScore[x][y].info[3].linkNum++;
                        }
                    }
                    if (space = 2)
                        myBoardScore[x][y].info[3].linkNum --;
                    if (y-i<0 || x+i>14 || BLACK_WHITE(x+i,y-i)==2)
                        opp++;
                    if (y+j>14 || x-j<0 || BLACK_WHITE(x-j,y+j)==2)
                        opp++;
                    if (opp!=2 && i+j<5) {
                        while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)!=2)
                            i++;                    
                        while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)!=2)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    myBoardScore[x][y].info[3].oppNum = opp;
                }
                if (n==2)
                {
                    //dim0
                    i=1;
                    j=1;
                    opp=0;
                    space=0;
                    while (y-i>=0 && BLACK_WHITE(x,y-i)==2)
                        i++;            
                    while (y+j<=14 && BLACK_WHITE(x,y+j)==2)
                        j++;
                    myBoardScore[x][y].info[0].linkNum = i+j-1;
                    if (y-i>=0 && BLACK_WHITE(x,y-i)==0 && y-i-1>=0 && BLACK_WHITE(x,y-i-1)==2){
                        i+=2;
                        myBoardScore[x][y].info[0].linkNum ++;
                        space++;
                        while (y-i>=0 && BLACK_WHITE(x,y-i)==2){
                            i++; 
                            myBoardScore[x][y].info[0].linkNum++;
                        }
                    }
                    if (y+j<=14 && BLACK_WHITE(x,y+j)==0 && y+j+1<=14 && BLACK_WHITE(x,y+j+1)==2){
                        j+=2;
                        myBoardScore[x][y].info[0].linkNum ++;
                        space++;
                        while (y+j<=14 && BLACK_WHITE(x,y+j)==2){
                            j++;
                            myBoardScore[x][y].info[0].linkNum++;
                        }
                    }
                    if (space = 2)
                        myBoardScore[x][y].info[0].linkNum --;
                    if (y-i<0 || BLACK_WHITE(x,y-i)==1)
                        opp++;  
                    if (y+j>14 || BLACK_WHITE(x,y+j)==1)
                        opp++; 
                    if (opp!=2 && i+j<5) {
                        while (y-i>=0 && BLACK_WHITE(x,y-i)!=1)
                            i++;                    
                        while (y+j<=14 && BLACK_WHITE(x,y+j)!=1)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    myBoardScore[x][y].info[0].oppNum = opp;
                    //dim1
                    i=1;
                    j=1;
                    opp=0;
                    space=0;
                    while (x-i>=0 && BLACK_WHITE(x-i,y)==2)
                        i++;
                    
                    while (x+j<=14 && BLACK_WHITE(x+j,y)==2)
                        j++;
                    myBoardScore[x][y].info[1].linkNum = i+j-1;
                    if (x-i>=0 && BLACK_WHITE(x-i,y)==0 && x-i-1>=0 && BLACK_WHITE(x-i-1,y)==2){
                        i+=2;
                        myBoardScore[x][y].info[1].linkNum ++;
                        space++;
                        while (x-i>=0 && BLACK_WHITE(x-i,y)==2){
                            i++; 
                            myBoardScore[x][y].info[1].linkNum++;
                        }
                    }
                    if (x+j<=14 && BLACK_WHITE(x+j,y)==0 && x+j+1<=14 && BLACK_WHITE(x+j+1,y)==2){
                        j+=2;
                        myBoardScore[x][y].info[1].linkNum ++;
                        space++;
                        while (x+j<=14 && BLACK_WHITE(x+j,y)==2){
                            j++;
                            myBoardScore[x][y].info[1].linkNum++;
                        }
                    }
                    if (space = 2)
                        myBoardScore[x][y].info[1].linkNum --;
                    if (x-i<0 || BLACK_WHITE(x-i,y)==1)
                        opp++;
                    if (x+j>14 || BLACK_WHITE(x+j,y)==1)
                        opp++;
                    if (opp!=2 && i+j<5) {
                        while (x-i>=0 && BLACK_WHITE(x-i,y)!=1)
                            i++;                    
                        while (x+j<=14 && BLACK_WHITE(x+j,y)!=1)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    myBoardScore[x][y].info[1].oppNum = opp;
                    //dim2
                    i=1;
                    j=1;
                    opp=0;
                    i=1;
                    j=1;
                    opp=0;
                    space=0;
                    while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)==2)
                        i++;
                    while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)==2)
                        j++;
                    myBoardScore[x][y].info[2].linkNum = i+j-1;
                    ///
                    if (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==0 && x-i-1>=0 && y-i-1>0 && BLACK_WHITE(x-i-1,y-i-1)==2){
                        i+=2;
                        myBoardScore[x][y].info[2].linkNum ++;
                        space++;
                        while (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==2){
                            i++; 
                            myBoardScore[x][y].info[2].linkNum++;
                        }
                    }
                    if (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==0 && x+j+1<=14 && y+j+1<=14 && BLACK_WHITE(x+j+1,y+j+1)==2){
                        j+=2;
                        myBoardScore[x][y].info[2].linkNum ++;
                        space++;
                        while (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==2){
                            j++;
                            myBoardScore[x][y].info[2].linkNum++;
                        }
                    }
                    if (space = 2)
                        myBoardScore[x][y].info[2].linkNum --;
                    if (y-i<0 || x-i<0 || BLACK_WHITE(x-i,y-i)==1)
                        opp++;
                    if (y+j>14 || x+j>14 || BLACK_WHITE(x+j,y+j)==1)
                        opp++;
                    if (opp!=2 && i+j<5) {
                        while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)!=1)
                            i++;                    
                        while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)!=1)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    myBoardScore[x][y].info[2].oppNum = opp;
                    //dim3
                    i=1;
                    j=1;
                    opp=0;
                    space=0;
                    while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)==2)
                        i++;
                    while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)==2)
                        j++;
                    myBoardScore[x][y].info[3].linkNum = i+j-1;
                    if (x+i<=14 && y-i>=0 && BLACK_WHITE(x+i,y-i)==0 && x+i+1<=14 && y-i-1>0 && BLACK_WHITE(x+i+1,y-i-1)==2){
                        i+=2;
                        myBoardScore[x][y].info[3].linkNum ++;
                        space++;
                        while (x+i>=0 && y-i>=0 && BLACK_WHITE(x+i,y-i)==2){
                            i++; 
                            myBoardScore[x][y].info[3].linkNum++;
                        }
                    }
                    if (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==0 && x-j-1<=14 && y+j+1<=14 && BLACK_WHITE(x-j-1,y+j+1)==2){
                        j+=2;
                        myBoardScore[x][y].info[3].linkNum ++;
                        space++;
                        while (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==2){
                            j++;
                            myBoardScore[x][y].info[3].linkNum++;
                        }
                    }
                    if (space = 2)
                        myBoardScore[x][y].info[3].linkNum --;
                    if (y-i<0 || x+i>14 || BLACK_WHITE(x+i,y-i)==1)
                        opp++;
                    if (y+j>14 || x-j<0 || BLACK_WHITE(x-j,y+j)==1)
                        opp++;
                    if (opp!=2 && i+j<5) {
                        while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)!=1)
                            i++;                    
                        while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)!=1)
                            j++;
                        if (i+j<6)
                            opp = 2;
                    }
                    myBoardScore[x][y].info[3].oppNum = opp;
                }
                //now has storage the info of LIANZI and opp. NOW Calculate the Score
                score = 0;
                for ( k = 0; k < 4; k++)
                {
                    if (myBoardScore[x][y].info[k].linkNum==5)
                        score += FIVE;
                    if (myBoardScore[x][y].info[k].linkNum==4){
                        if (myBoardScore[x][y].info[k].oppNum==0)
                            score += FOUR;
                        if (myBoardScore[x][y].info[k].oppNum==1)
                            score += DEAD_FOUR;
                    }
                    if (myBoardScore[x][y].info[k].linkNum==3){
                        if (myBoardScore[x][y].info[k].oppNum==0)
                            score += THREE;
                        if (myBoardScore[x][y].info[k].oppNum==1)
                            score += DEAD_THREE;
                    }
                    if (myBoardScore[x][y].info[k].linkNum==2){
                        if (myBoardScore[x][y].info[k].oppNum==0)
                            score += TWO;
                        if (myBoardScore[x][y].info[k].oppNum==1)
                            score += DEAD_TWO;
                    }
                    if (myBoardScore[x][y].info[k].linkNum==1){
                        if (myBoardScore[x][y].info[k].oppNum==0)
                            score += ONE;
                        if (myBoardScore[x][y].info[k].oppNum==1)
                            score += DEAD_ONE;
                    }
                }
                myBoardScore[x][y].score = score;
                allscore += score;
            }
            
        }
        
    }
    
    return allscore;
    
}



int BLACK_WHITE(int x,int y)
{
    if (x<0 || x>14 || y<0 || y>14)
        return -1;
    if (arrayForInnerBoardLayout[x][y]==1 || arrayForInnerBoardLayout[x][y]==3)
    {
        return 1;
    } else if (arrayForInnerBoardLayout[x][y]==2 || arrayForInnerBoardLayout[x][y]==4)
    {
        return 2;
    }
    return 0;
}
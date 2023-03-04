#include "wzq.h"
struct point best_choice(int n);//n=1 means ai is black, n=2 means ai is white
int dangerous[15][15];
int Score(int x, int y, int n)
{
    struct SingleScore the_point;
    int the_score,i,j,k,space;
    //space is used to record the situation like 10110
    int lenth = 0;
    int opp = 0;//opp is used to record how many sides has been blocked
    if (n==1)
    {
        //dim 0
        i=1;
        j=1;
        opp=0;
        space=0;
        while (y-i>=0 && BLACK_WHITE(x,y-i)==1)
            i++;
        while (y+j<=14 && BLACK_WHITE(x,y+j)==1)
            j++;
        the_point.info[0].linkNum = i+j-1;
        if (y-i>=0 && BLACK_WHITE(x,y-i)==0 && y-i-1>=0 && BLACK_WHITE(x,y-i-1)==1){
            i+=2;
            the_point.info[0].linkNum ++;
            space++;
            while (y-i>=0 && BLACK_WHITE(x,y-i)==1){
                i++; 
                the_point.info[0].linkNum++;
            }
        }
        if (y+j<=14 && BLACK_WHITE(x,y+j)==0 && y+j+1<=14 && BLACK_WHITE(x,y+j+1)==1){
            j+=2;
            the_point.info[0].linkNum ++;
            space++;
            while (y+j<=14 && BLACK_WHITE(x,y+j)==1){
                j++;
                the_point.info[0].linkNum++;
            }
        }
        if (space = 2)
            the_point.info[0].linkNum --;
        if (y-i<0 || BLACK_WHITE(x,y-i)==2)
            opp++;  
        if (y+j>14 || BLACK_WHITE(x,y+j)==2)
            opp++; 
        if (opp!=2 && i+j<5) {
            while (y-i>=0 && BLACK_WHITE(x,y-i)!=2)
                i++;                    
            while (y+j<=14 && BLACK_WHITE(x,y+j)!=2)
                j++;
            if (i+j<5)
                opp = 2;
        }
        the_point.info[0].oppNum = opp;
        //dim1
        i=1;
        j=1;
        opp=0;
        space=0;
        while (x-i>=0 && BLACK_WHITE(x-i,y)==1)
            i++;
        
        while (x+j<=14 && BLACK_WHITE(x+j,y)==1)
            j++;
        the_point.info[1].linkNum = i+j-1;
        if (x-i>=0 && BLACK_WHITE(x-i,y)==0 && x-i-1>=0 && BLACK_WHITE(x-i-1,y)==1){
            i+=2;
            the_point.info[1].linkNum ++;
            space++;
            while (x-i>=0 && BLACK_WHITE(x-i,y)==1){
                i++; 
                the_point.info[1].linkNum++;
            }
        }
        if (x+j<=14 && BLACK_WHITE(x+j,y)==0 && x+j+1<=14 && BLACK_WHITE(x+j+1,y)==1){
            j+=2;
            the_point.info[1].linkNum ++;
            space++;
            while (x+j<=14 && BLACK_WHITE(x+j,y)==1){
                j++;
                the_point.info[1].linkNum++;
            }
        }
        if (space = 2)
            the_point.info[1].linkNum --;
        if (x-i<0 || BLACK_WHITE(x-i,y)==2)
            opp++;
        if (x+j>14 || BLACK_WHITE(x+j,y)==2)
            opp++;
        if (opp!=2 && i+j<5) {
            while (x-i>=0 && BLACK_WHITE(x-i,y)!=2)
                i++;                    
            while (x+j<=14 && BLACK_WHITE(x+j,y)!=2)
                j++;
            if (i+j<5)
                opp = 2;
        }
        the_point.info[1].oppNum = opp;
        //dim2
        i=1;
        j=1;
        opp=0;
        space=0;
        while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)==1)
            i++;
        while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)==1)
            j++;
        the_point.info[2].linkNum = i+j-1;
        ///
        if (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==0 && x-i-1>=0 && y-i-1>0 && BLACK_WHITE(x-i-1,y-i-1)==1){
            i+=2;
            the_point.info[2].linkNum ++;
            space++;
            while (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==1){
                i++; 
                the_point.info[2].linkNum++;
            }
        }
        if (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==0 && x+j+1<=14 && y+j+1<=14 && BLACK_WHITE(x+j+1,y+j+1)==1){
            j+=2;
            the_point.info[2].linkNum ++;
            space++;
            while (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==1){
                j++;
                the_point.info[2].linkNum++;
            }
        }
        if (space = 2)
            the_point.info[2].linkNum --;
        ///
        if (y-i<0 || x-i<0 || BLACK_WHITE(x-i,y-i)==2)
            opp++;
        if (y+j>14 || x+j>14 || BLACK_WHITE(x+j,y+j)==2)
            opp++;
        if (opp!=2 && i+j<5) {
            while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)!=2)
                i++;                    
            while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)!=2)
                j++;
            if (i+j<5)
                opp = 2;
        }
        the_point.info[2].oppNum = opp;
        //dim3
        i=1;
        j=1;
        opp=0;
        space=0;
        while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)==1)
            i++;
        while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)==1)
            j++;
        the_point.info[3].linkNum = i+j-1;
        if (x+i<=14 && y-i>=0 && BLACK_WHITE(x+i,y-i)==0 && x+i+1<=14 && y-i-1>0 && BLACK_WHITE(x+i+1,y-i-1)==1){
            i+=2;
            the_point.info[3].linkNum ++;
            space++;
            while (x+i>=0 && y-i>=0 && BLACK_WHITE(x+i,y-i)==1){
                i++; 
                the_point.info[3].linkNum++;
            }
        }
        if (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==0 && x-j-1<=14 && y+j+1<=14 && BLACK_WHITE(x-j-1,y+j+1)==1){
            j+=2;
            the_point.info[3].linkNum ++;
            space++;
            while (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==1){
                j++;
                the_point.info[3].linkNum++;
            }
        }
        if (space = 2)
            the_point.info[3].linkNum --;
        if (y-i<0 || x+i>14 || BLACK_WHITE(x+i,y-i)==2)
            opp++;
        if (y+j>14 || x-j<0 || BLACK_WHITE(x-j,y+j)==2)
            opp++;
        if (opp!=2 && i+j<5) {
            while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)!=2)
                i++;                    
            while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)!=2)
                j++;
            if (i+j<5)
                opp = 2;
        }
        the_point.info[3].oppNum = opp;
    }
    if (n=2)
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
        the_point.info[0].linkNum = i+j-1;
        if (y-i>=0 && BLACK_WHITE(x,y-i)==0 && y-i-1>=0 && BLACK_WHITE(x,y-i-1)==2){
            i+=2;
            the_point.info[0].linkNum ++;
            space++;
            while (y-i>=0 && BLACK_WHITE(x,y-i)==2){
                i++; 
                the_point.info[0].linkNum++;
            }
        }
        if (y+j<=14 && BLACK_WHITE(x,y+j)==0 && y+j+1<=14 && BLACK_WHITE(x,y+j+1)==2){
            j+=2;
            the_point.info[0].linkNum ++;
            space++;
            while (y+j<=14 && BLACK_WHITE(x,y+j)==2){
                j++;
                the_point.info[0].linkNum++;
            }
        }
        if (space = 2)
            the_point.info[0].linkNum --;
        if (y-i<0 || BLACK_WHITE(x,y-i)==1)
            opp++;  
        if (y+j>14 || BLACK_WHITE(x,y+j)==1)
            opp++; 
        if (opp!=2 && i+j<5) {
            while (y-i>=0 && BLACK_WHITE(x,y-i)!=1)
                i++;                    
            while (y+j<=14 && BLACK_WHITE(x,y+j)!=1)
                j++;
            if (i+j<5)
                opp = 2;
        }
        the_point.info[0].oppNum = opp;
        //dim1
        i=1;
        j=1;
        opp=0;
        space=0;
        while (x-i>=0 && BLACK_WHITE(x-i,y)==2)
            i++;
        
        while (x+j<=14 && BLACK_WHITE(x+j,y)==2)
            j++;
        the_point.info[1].linkNum = i+j-1;
        if (x-i>=0 && BLACK_WHITE(x-i,y)==0 && x-i-1>=0 && BLACK_WHITE(x-i-1,y)==2){
            i+=2;
            the_point.info[1].linkNum ++;
            space++;
            while (x-i>=0 && BLACK_WHITE(x-i,y)==2){
                i++; 
                the_point.info[1].linkNum++;
            }
        }
        if (x+j<=14 && BLACK_WHITE(x+j,y)==0 && x+j+1<=14 && BLACK_WHITE(x+j+1,y)==2){
            j+=2;
            the_point.info[1].linkNum ++;
            space++;
            while (x+j<=14 && BLACK_WHITE(x+j,y)==2){
                j++;
                the_point.info[1].linkNum++;
            }
        }
        if (space = 2)
            the_point.info[1].linkNum --;
        if (x-i<0 || BLACK_WHITE(x-i,y)==1)
            opp++;
        if (x+j>14 || BLACK_WHITE(x+j,y)==1)
            opp++;
        if (opp!=2 && i+j<5) {
            while (x-i>=0 && BLACK_WHITE(x-i,y)!=1)
                i++;                    
            while (x+j<=14 && BLACK_WHITE(x+j,y)!=1)
                j++;
            if (i+j<5)
                opp = 2;
        }
        the_point.info[1].oppNum = opp;
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
        the_point.info[2].linkNum = i+j-1;
        if (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==0 && x-i-1>=0 && y-i-1>0 && BLACK_WHITE(x-i-1,y-i-1)==2){
            i+=2;
            the_point.info[2].linkNum ++;
            space++;
            while (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==2){
                i++; 
                the_point.info[2].linkNum++;
            }
        }
        if (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==0 && x+j+1<=14 && y+j+1<=14 && BLACK_WHITE(x+j+1,y+j+1)==2){
            j+=2;
            the_point.info[2].linkNum ++;
            space++;
            while (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==2){
                j++;
                the_point.info[2].linkNum++;
            }
        }
        if (space = 2)
            the_point.info[2].linkNum --;
        if (y-i<0 || x-i<0 || BLACK_WHITE(x-i,y-i)==1)
            opp++;
        if (y+j>14 || x+j>14 || BLACK_WHITE(x+j,y+j)==1)
            opp++;
        if (opp!=2 && i+j<5) {
            while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)!=1)
                i++;                    
            while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)!=1)
                j++;
            if (i+j<5)
                opp = 2;
        }
        the_point.info[2].oppNum = opp;
        //dim3
        i=1;
        j=1;
        opp=0;
        space=0;
        while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)==2)
            i++;
        while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)==2)
            j++;
        the_point.info[3].linkNum = i+j-1;
        if (x+i<=14 && y-i>=0 && BLACK_WHITE(x+i,y-i)==0 && x+i+1<=14 && y-i-1>0 && BLACK_WHITE(x+i+1,y-i-1)==2){
            i+=2;
            the_point.info[3].linkNum ++;
            space++;
            while (x+i>=0 && y-i>=0 && BLACK_WHITE(x+i,y-i)==2){
                i++; 
                the_point.info[3].linkNum++;
            }
        }
        if (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==0 && x-j-1<=14 && y+j+1<=14 && BLACK_WHITE(x-j-1,y+j+1)==2){
            j+=2;
            the_point.info[3].linkNum ++;
            space++;
            while (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==2){
                j++;
                the_point.info[3].linkNum++;
            }
        }
        if (space = 2)
            the_point.info[3].linkNum --;
        if (y-i<0 || x+i>14 || BLACK_WHITE(x+i,y-i)==1)
            opp++;
        if (y+j>14 || x-j<0 || BLACK_WHITE(x-j,y+j)==1)
            opp++;
        if (opp!=2 && i+j<5) {
            while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)!=1)
                i++;                    
            while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)!=1)
                j++;
            if (i+j<5)
                opp = 2;
        }
        the_point.info[3].oppNum = opp;
    }
    //now has storage the info of LIANZI and opp. NOW Calculate the Score
    int result = 0;
    for ( k = 0; k < 4; k++)
    {
        if (the_point.info[k].linkNum==5)
            result += FIVE;
        if (the_point.info[k].linkNum==4){
            if (the_point.info[k].oppNum==0)
                result += FOUR;
            if (the_point.info[k].oppNum==1)
                result += DEAD_FOUR;
        }
        if (the_point.info[k].linkNum==3){
            if (the_point.info[k].oppNum==0)
                result += THREE;
            if (the_point.info[k].oppNum==1)
                result += DEAD_THREE;
        }
        if (the_point.info[k].linkNum==2){
            if (the_point.info[k].oppNum==0)
                result += TWO;
            if (the_point.info[k].oppNum==1)
                result += DEAD_TWO;
        }
        if (the_point.info[k].linkNum==1){
            if (the_point.info[k].oppNum==0)
                result += ONE;
            if (the_point.info[k].oppNum==1)
                result += DEAD_ONE;
        }
    }
    the_point.score = result;
    return the_point.score;
}
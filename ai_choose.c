#include "wzq.h"
int updateScore(int n);
int Score(int x, int y, int n);
int isBANNED(int x, int y);
int isBANNED_2(int x, int y);
extern struct SingleScore myBoardScore[15][15];
extern int arrayForInnerBoardLayout[SIZE][SIZE];
struct tpoint {
//    int vaild;//1 means vaild, 0 means not
//    int mycolor;//1 means I'm     black, 2 means I'm white
    struct tpoint *subpoint[15][15];
//    int score;
    int allscore;
};
struct tpoint *p;
struct tpoint * talloc(void);
int vaildpoint(int x, int y);
struct point best_choice(int n)
//choose one that is best for self. n=1 means self black while n=2 means white. return by the form of "point"
{
    struct point bestpoint;
    struct point currentpoint;
    static int flag = 1;
    int x,y;
    int alpha,beta;
    int max;
    int max1;
    int max2;
    int min1;
    int min2;
    int myBoardScore1[15][15];
    int ini1, ini2, ini3;
    int x1, y1, x2, y2, x3, y3, x4, y4;//used to record the point of every layer
    int value1, value2, value3, value4;//the point score of every layer
    int Max1, Min2, Max3, Min4;//record the min/max value of every layer
    int break1, break2, break3, break4;//if we exit a 'loop', because we ergodic x and y, we should break twice. use them to record that
    break1 = 0;
    break2 = 0;
    break3 = 0;
    break4 = 0;
    //updateScore(n);
    if ( n == 1 && flag == 1){
        //the first step
        bestpoint.x = 7;
        bestpoint.y = 7;
        flag = 0;
    } else {
        //2 layers
        /*
        for ( x = 0; x < 15; x++)
        {
            for ( y = 0; y < 15; y++)
            {
                if (arrayForInnerBoardLayout[x][y]==0)
                    myBoardScore1[x][y] = Score(x,y,n);
            }
        }
        
        for ( x = 0; x < 15; x++)
        {
            for ( y = 0; y < 15; y++)
            {
                if (arrayForInnerBoardLayout[x][y]==0){
                    arrayForInnerBoardLayout[x][y] = n;
                    max1 = -1000000;
                    for ( x2 = 0; x2 < 15; x2++)
                    {
                        for ( y2 = 0; y2 < 15; y2++)
                        {
                            if (Score(x2,y2,3-n)>max1)
                                max1=Score(x2,y2,3-n);
                        }
                    }
                    myBoardScore1[x][y] -= max1;
                    arrayForInnerBoardLayout[x][y] = 0;
                }
            }
            
        }
        max2 = -10000000;
        for ( x = 0; x < 15; x++)
        {
            for ( y = 0; y < 15; y++)
            {
                if (arrayForInnerBoardLayout[x][y]==0){
                    if (myBoardScore1[x][y]>max2)
                    {
                        max2 = myBoardScore1[x][y];
                        bestpoint.x = x;
                        bestpoint.y = y;
                    }
                }
            }
            
        }
        */
        
        //4 layers
        
        Max1 = -200000;
        int flag_quit = 0;
        //the situation of form CHONGSI, return directly
        for ( x1 = 0; x1 < SIZE; ++x1){
            for ( y1 = 0; y1 < SIZE; ++y1)
            {
                if (BLACK_WHITE(x1,y1)==0 && vaildpoint(x1,y1))
                {
                    if (Score(x1,y1,n)>=100000 && (n==2 || !isBANNED(x1,y1)))
                    {
                        bestpoint.x = x1;
                        bestpoint.y = y1;
                        return bestpoint;
                    }
                }
            }
        }
        for ( x1 = 0; x1 < SIZE; ++x1){
            for ( y1 = 0; y1 < SIZE; ++y1)
            {
                if (BLACK_WHITE(x1,y1)==0 && vaildpoint(x1,y1) && (n==1 || !isBANNED(x1,y1)))
                {
                    if (Score(x1,y1,3-n)>=100000)
                    {
                        bestpoint.x = x1;
                        bestpoint.y = y1;
                        return bestpoint;
                    }
                }
            }
        }
        //reduce search scope with ab-cut
        if (n==1)//ai is black
        {
            for (x1 = white_x-2; x1 <= white_x+2; ++x1) {
            for (y1 = white_y-2; y1 <= white_y+2; ++y1) {
                if (BLACK_WHITE(x1,y1)==0 && vaildpoint(x1,y1)) {
                    Min2 = +200000;
                    ini1 = arrayForInnerBoardLayout[x1][y1];
                    value1 = Score(x1,y1,n);
                    //if someone will win, exit
                    if (value1 >= 100000) {
                        Max1 = value1;
                        flag_quit = 1;
                        break1 = 1;
                        break;
                    }
                    arrayForInnerBoardLayout[x1][y1] = n;
                    for (x2 = 0; x2 < SIZE; ++x2) {
                        for (y2 = 0; y2 < SIZE; ++y2) {
                            if (BLACK_WHITE(x2,y2)==0 && vaildpoint(x2,y2)) {
                                Max3 = -200000;
                                ini2 = arrayForInnerBoardLayout[x2][y2];
                                value2 = Score(x2,y2,3-n);
                                //just the same as before, if someone will win, exit
                                if (value2 >= 100000) {
                                    Min2 = value1 - value2;
                                    flag_quit = 1;
                                    break2 = 1;
                                    break;
                                }
                                arrayForInnerBoardLayout[x2][y2] = 3-n;
                                for (x3 = 0; x3 < SIZE; ++x3) {
                                    for (y3 = 0; y3 < SIZE; ++y3) {
                                        if (BLACK_WHITE(x3,y3)==0 && vaildpoint(x3,y3)) {
                                            Min4 = +200000;
                                            ini3 = arrayForInnerBoardLayout[x3][y3];
                                            value3 = Score(x3, y3, n);
                                            //judge if someone will win
                                            if (value3 >= 100000) {
                                                Max3 = value1 - value2 + value3;
                                                break3 = 1;
                                                break;
                                            }
                                            arrayForInnerBoardLayout[x3][y3] = n;
                                            for (x4 = 0; x4 < SIZE; ++x4) {
                                                for (y4 = 0; y4 < SIZE; ++y4) {
                                                    if (BLACK_WHITE(x4,y4)==0 && vaildpoint(x4,y4)) {
                                                        value4 = Score(x4, y4, 3-n);
                                                        if (Min4 > value1 - value2 + value3 - value4)
                                                        {
                                                            //minimax
                                                            Min4 = value1 - value2 + value3 - value4;
                                                        }
                                                        if (Min4 <= Max3) {
                                                            //alpha-beta cut
                                                            Min4 = -200000;
                                                            break4 = 1;
                                                            break;
                                                        }
                                                    }
                                                }
                                                if (break4 == 1) {
                                                    //break twice
                                                    break4 = 0;
                                                    break;
                                                }
                                            }
                                            arrayForInnerBoardLayout[x3][y3] = ini3;
                                            if (Max3 < Min4) {
                                                Max3 = Min4;
                                            }
                                            if (Min2 <= Max3) {
                                                //alpha-beta cut
                                                Max3 = +200000;
                                                break3 = 1;
                                                break;
                                            }
                                        }
                                    }
                                    if (break3 == 1) {
                                        //break twice
                                        break3 = 0;
                                        break;
                                    }
                                }
                                arrayForInnerBoardLayout[x2][y2] = ini2;
                                if (Max3 < Min2)
                                {
                                    Min2 = Max3;
                                }
                                if (Min2 <= Max1) {
                                    //alpha-beta cut
                                    Min2 = -200000;
                                    break2 = 1;
                                    break;
                                }
                            }
                        }
                        if (break2 == 1) {
                            //break twice
                            break2 = 0;
                            break;
                        }
                    }
                    arrayForInnerBoardLayout[x1][y1] = ini1;
                    if (Min2 > Max1) {
                        if (!isBANNED(x1,y1)){
                            bestpoint.x = x1;
                            bestpoint.y = y1;
                            Max1 = Min2;
                        }
                    }
                }
            }
            if (break1 == 1) {
                //break twice
                break1 = 0;
                break;
            }
        }
        }
        
        if (n==2)//ai is white
        {
            for (x1 = black_x-2; x1 <= black_x+2; ++x1) {
            for (y1 = black_y-2; y1 <= black_y+2; ++y1) {
                if (BLACK_WHITE(x1,y1)==0 && vaildpoint(x1,y1)) {
                    Min2 = +200000;
                    ini1 = arrayForInnerBoardLayout[x1][y1];
                    value1 = Score(x1,y1,n);
                    //if someone will win, exit
                    if (value1 >= 100000) {
                        Max1 = value1;
                        break1 = 1;
                        break;
                    }
                    arrayForInnerBoardLayout[x1][y1] = n;
                    for (x2 = 0; x2 < SIZE; ++x2) {
                        for (y2 = 0; y2 < SIZE; ++y2) {
                            if (BLACK_WHITE(x2,y2)==0 && vaildpoint(x2,y2)) {
                                Max3 = -200000;
                                ini2 = arrayForInnerBoardLayout[x2][y2];
                                value2 = Score(x2,y2,3-n);
                                //just the same as before, if someone will win, exit
                                if (value2 >= 100000) {
                                    Min2 = value1 - value2;
                                    break2 = 1;
                                    break;
                                }
                                arrayForInnerBoardLayout[x2][y2] = 3-n;
                                for (x3 = 0; x3 < SIZE; ++x3) {
                                    for (y3 = 0; y3 < SIZE; ++y3) {
                                        if (BLACK_WHITE(x3,y3)==0 && vaildpoint(x3,y3)) {
                                            Min4 = +200000;
                                            ini3 = arrayForInnerBoardLayout[x3][y3];
                                            value3 = Score(x3, y3, n);
                                            //judge if someone will win
                                            if (value3 >= 100000) {
                                                Max3 = value1 - value2 + value3;
                                                break3 = 1;
                                                break;
                                            }
                                            arrayForInnerBoardLayout[x3][y3] = n;
                                            for (x4 = 0; x4 < SIZE; ++x4) {
                                                for (y4 = 0; y4 < SIZE; ++y4) {
                                                    if (BLACK_WHITE(x4,y4)==0 && vaildpoint(x4,y4)) {
                                                        value4 = Score(x4, y4, 3-n);
                                                        if (Min4 > value1 - value2 + value3 - value4)
                                                        {
                                                            //minimax
                                                            Min4 = value1 - value2 + value3 - value4;
                                                        }
                                                        if (Min4 <= Max3) {
                                                            //alpha-beta cut
                                                            Min4 = -200000;
                                                            break4 = 1;
                                                            break;
                                                        }
                                                    }
                                                }
                                                if (break4 == 1) {
                                                    //break twice
                                                    break4 = 0;
                                                    break;
                                                }
                                            }
                                            arrayForInnerBoardLayout[x3][y3] = ini3;
                                            if (Max3 < Min4) {
                                                Max3 = Min4;
                                            }
                                            if (Min2 <= Max3) {
                                                //alpha-beta cut
                                                Max3 = +200000;
                                                break3 = 1;
                                                break;
                                            }
                                        }
                                    }
                                    if (break3 == 1) {
                                        //break twice
                                        break3 = 0;
                                        break;
                                    }
                                }
                                arrayForInnerBoardLayout[x2][y2] = ini2;
                                if (Max3 < Min2)
                                {
                                    Min2 = Max3;
                                }
                                if (Min2 <= Max1) {
                                    //alpha-beta cut
                                    Min2 = -200000;
                                    break2 = 1;
                                    break;
                                }
                            }
                        }
                        if (break2 == 1) {
                            //break twice
                            break2 = 0;
                            break;
                        }
                    }
                    arrayForInnerBoardLayout[x1][y1] = ini1;
                    if (Min2 > Max1) {
                        bestpoint.x = x1;
                        bestpoint.y = y1;
                        Max1 = Min2;
                    }
                }
            }
            if (break1 == 1) {
                //break twice
                break1 = 0;
                break;
            }
        }
        }
        
        if (flag_quit == 0){
            for (x1 = 0; x1 < SIZE; ++x1) {
                for (y1 = 0; y1 < SIZE; ++y1) {
                    
                    if (BLACK_WHITE(x1,y1)==0 && vaildpoint(x1,y1)) {
                        
                        Min2 = +200000;
                        ini1 = arrayForInnerBoardLayout[x1][y1];
                        value1 = Score(x1,y1,n);
                        //if someone will win, exit
                        if (value1 >= 100000) {
                            Max1 = value1;
                            bestpoint.x = x1;
                            bestpoint.y = y1;
                            break1 = 1;
                            break;
                        }
                        arrayForInnerBoardLayout[x1][y1] = n;
                        for (x2 = 0; x2 < SIZE; ++x2) {
                            for (y2 = 0; y2 < SIZE; ++y2) {
                                if (BLACK_WHITE(x2,y2)==0 && vaildpoint(x2,y2)) {
                                    Max3 = -200000;
                                    ini2 = arrayForInnerBoardLayout[x2][y2];
                                    value2 = Score(x2,y2,3-n);
                                    //just the same as before, if someone will win, exit
                                    if (value2 >= 100000) {
                                        Min2 = value1 - value2;
                                        break2 = 1;
                                        break;
                                    }
                                    arrayForInnerBoardLayout[x2][y2] = 3-n;
                                    for (x3 = 0; x3 < SIZE; ++x3) {
                                        for (y3 = 0; y3 < SIZE; ++y3) {
                                            if (BLACK_WHITE(x3,y3)==0 && vaildpoint(x3,y3)) {
                                                Min4 = +200000;
                                                ini3 = arrayForInnerBoardLayout[x3][y3];
                                                value3 = Score(x3, y3, n);
                                                //judge if someone will win
                                                if (value3 >= 100000) {
                                                    Max3 = value1 - value2 + value3;
                                                    break3 = 1;
                                                    break;
                                                }
                                                arrayForInnerBoardLayout[x3][y3] = n;
                                                for (x4 = 0; x4 < SIZE; ++x4) {
                                                    for (y4 = 0; y4 < SIZE; ++y4) {
                                                        if (BLACK_WHITE(x4,y4)==0 && vaildpoint(x4,y4)) {
                                                            value4 = Score(x4, y4, 3-n);
                                                            if (Min4 > value1 - value2 + value3 - value4)
                                                            {
                                                                //minimax
                                                                Min4 = value1 - value2 + value3 - value4;
                                                            }
                                                            if (Min4 <= Max3) {
                                                                //alpha-beta cut
                                                                Min4 = -200000;
                                                                break4 = 1;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    if (break4 == 1) {
                                                        //break twice
                                                        break4 = 0;
                                                        break;
                                                    }
                                                }
                                                arrayForInnerBoardLayout[x3][y3] = ini3;
                                                if (Max3 < Min4) {
                                                    Max3 = Min4;
                                                }
                                                if (Min2 <= Max3) {
                                                    //alpha-beta cut
                                                    Max3 = +200000;
                                                    break3 = 1;
                                                    break;
                                                }
                                            }
                                        }
                                        if (break3 == 1) {
                                            //break twice
                                            break3 = 0;
                                            break;
                                        }
                                    }
                                    arrayForInnerBoardLayout[x2][y2] = ini2;
                                    if (Max3 < Min2)
                                    {
                                        Min2 = Max3;
                                    }
                                    if (Min2 <= Max1) {
                                        //alpha-beta cut
                                        Min2 = -200000;
                                        break2 = 1;
                                        break;
                                    }
                                }
                            }
                            if (break2 == 1) {
                                //break twice
                                break2 = 0;
                                break;
                            }
                        }
                        arrayForInnerBoardLayout[x1][y1] = ini1;
                        if (Min2 > Max1) {
                            if (n==2 || !isBANNED(x1,y1)){
                                bestpoint.x = x1;
                                bestpoint.y = y1;
                                Max1 = Min2;
                            }
                        }
                    }
                }
                if (break1 == 1) {
                    //break twice
                    break1 = 0;
                    break;
                }
            }
        }
        

        return bestpoint;
        
        
    }
    
    return bestpoint;
}
struct tpoint * talloc(void){
    //for the first method
    return (struct tpoint*)malloc(sizeof(struct tpoint));
}
    

int vaildpoint(int x,int y)
{
    //get 5x5
    int i = 1;
    if ((x-i>=0 && BLACK_WHITE(x-i,y)!=0) || (y-i>=0 && BLACK_WHITE(x,y-i)!=0) || (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)!=0) || (x+i<=14 && y-i>=0 && BLACK_WHITE(x+i,y-i)!=0))
        return 1;
    i = -1;
    if ((x-i<=14 && BLACK_WHITE(x-i,y)!=0) || (y-i<=14 && BLACK_WHITE(x,y-i)!=0) || (x-i<=14 && y-i<=14 && BLACK_WHITE(x-i,y-i)!=0) || (x+i>=0 && y-i<=14 && BLACK_WHITE(x+i,y-i)!=0))
        return 1;
    i = 2;
    if ((x-i>=0 && BLACK_WHITE(x-i,y)!=0) || (y-i>=0 && BLACK_WHITE(x,y-i)!=0) || (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)!=0) || (x+i<=14 && y-i>=0 && BLACK_WHITE(x+i,y-i)!=0))
        return 1;
    i = -2;
    if ((x-i<=14 && BLACK_WHITE(x-i,y)!=0) || (y-i<=14 && BLACK_WHITE(x,y-i)!=0) || (x-i<=14 && y-i<=14 && BLACK_WHITE(x-i,y-i)!=0) || (x+i>=0 && y-i<=14 && BLACK_WHITE(x+i,y-i)!=0))
        return 1;
    return 0;
}
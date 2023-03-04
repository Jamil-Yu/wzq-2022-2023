#include "wzq.h"
int isCHANGLIAN(int x, int y);//more than 5
int isSANSAN(int x, int y);//form 2 HUOSAN
int isSISI(int x, int y);//form 2 CHONGSI or HUOSI
int formHUOSAN(int n,int x,int y);
int formHUOSI(int n, int x, int y);
int formCHONGSI(int n, int x, int y);
int isBANNED(int x, int y);
int isBANNED_2(int x, int y);
int isBANNED(int x, int y)
{
    //there are three JINSHOU
    int init = arrayForInnerBoardLayout[x][y];
    arrayForInnerBoardLayout[x][y]=1;
    //judge CHNAGLIAN
    if (isCHANGLIAN(x, y)==1)
    {
        printf("\nisCHANGLIAN!\n");
        arrayForInnerBoardLayout[x][y]=init;
        return 1;
    }
    //judge SANSAN
    if (isSANSAN(x, y)==1)
    {
        printf("\nisSANSAN!\n");
        arrayForInnerBoardLayout[x][y]=init;
        return 1;
    }
    //judge SISI
    if (isSISI(x,y)==1)
    {
        printf("\nisSISI!\n");
        arrayForInnerBoardLayout[x][y]=init;
        return 1;
    }
    arrayForInnerBoardLayout[x][y]=init;
    return 0;
}
int isCHANGLIAN(int x, int y)
{
    //CHNAG LIAN?
    //dim0
    int i = 1;
    int j = 1;
    while (y-i>=0 && BLACK_WHITE(x,y-i)==1)
        i++;
    while (y+j<=14 && BLACK_WHITE(x,y+j)==1)
        j++;
    //then i+j-1 means the lenth of one color
    if (i+j>=7)
        return 1;
    else {
        i = 1;
        j = 1;
    }
    //dim1
    while (x-i>=0 && BLACK_WHITE(x-i,y)==1)
        i++;
    while (x+j<=14 && BLACK_WHITE(x+j,y)==1)
        j++;
    if (i+j>=7)
        return 1;
    else {
        i = 1;
        j = 1;
    }
    //dim2
    while (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==1)
        i++;
    while (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==1)
        j++;
    if (i+j>=7)
        return 1;
    else {
        i = 1;
        j = 1;
    }
    //dim3
    while (x+i<=14 && y-i>=0 && BLACK_WHITE(x+i,y-i)==1)
        i++;
    while (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==1)
        j++;
    if (i+j>=7)
        return 1;
    else {
        i = 1;
        j = 1;
    }
    return 0;
}
int isSANSAN(int x, int y)
{
    int number = 0;
    int i;
    //sum up the number of HUOSAN in every dim
    for ( i = 1; i < 5; i++)
        number += formHUOSAN(i,x,y);
    if (number>=2)
        return 1;
    return 0;
}
int formHUOSAN(int n, int x, int y)
{        
    //HUOSAN has three situations:01110,011010,010110, so we should discuss the situation of 3,2,1!
    int i;
    int j;
    int left,right;
    //dim1
    if (n == 1)
    {
        i = 1;
        j = 1;
        while (y-i>=0 && BLACK_WHITE(x,y-i)==1)
            i++;
        while (y+j<=14 && BLACK_WHITE(x,y+j)==1)
            j++;
        left = y - i + 1;
        right = y + j - 1;
        //i+j-1 is the value of LIANZI, left and right means the boundry of the LIANZI
        if (i+j==4)
        {
            //form continue 3
            if ((left-1>=0 && formHUOSI(n,x,left-1)) || (right+1<=14 && formHUOSI(n,x,right+1)))
                return 1;
        }else if (i+j==2){
            //1
            if(y-1>=0 && y+1<=14 && BLACK_WHITE(x,y-1)==0 && BLACK_WHITE(x,y+1)==0)
            //010
            {
                if (y-4>=0 && BLACK_WHITE(x,y-3)==1 && BLACK_WHITE(x,y-2)==1 && BLACK_WHITE(x,y-4)==0)//0110'1'0
                {
                    if (formHUOSI(n,x,y-1)==1)
                    {
                        return 1;
                    }
                }
                if (y+4<=14 && BLACK_WHITE(x,y+3)==1 && BLACK_WHITE(x,y+2)==1 && BLACK_WHITE(x,y+4)==0)//0'1'0110
                {
                    if (formHUOSI(n,x,y+1)==1)
                    {
                        return 1;
                    }
                }
            }
        }else if (i+j==3){
            //form continue two '11'
            if (left-1>=0 && right+1<=14 && BLACK_WHITE(x,left-1)==0 && BLACK_WHITE(x,right+1)==0)
            {
                if (left-3>=0 && BLACK_WHITE(x,left-3)==0 && BLACK_WHITE(x,left-2)==1)
                {
                    if (formHUOSI(n,x,left-1))
                    {
                        return 1;
                    }
                    
                }
                if (right+3>=0 && BLACK_WHITE(x,right+3)==0 && BLACK_WHITE(x,right+2)==1)
                {
                    if (formHUOSI(n,x,right+1))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    if (n == 2)
    {
        i = 1;
        j = 1;
        while (x-i>=0 && BLACK_WHITE(x-i,y)==1)
        {
            i++;
        }
        while (x+j<=14 && BLACK_WHITE(x+j,y)==1 )
        {
            j++;
        }
        left = x - i + 1;
        right = x + j - 1;
        if (i+j==4)
        {
            //form continue 3
            
            if ((left-1>=0 && formHUOSI(n,left-1,y)) || (right+1<=14 && formHUOSI(n,right+1,y)))
            {
                return 1;
            }
            
        }else if (i+j==2){
            //island
            if(x-1>=0 && x+1<=14 && BLACK_WHITE(x-1,y)==0 && BLACK_WHITE(x+1,y)==0)
            {
                if (x-4>=0 && BLACK_WHITE(x-3,y)==1 && BLACK_WHITE(x-2,y)==1 && BLACK_WHITE(x-4,y)==0)
                {
                    if (formHUOSI(n,x-1,y)==1)
                    {
                        return 1;
                    }

                }
                if (x+4<=14 && BLACK_WHITE(x+3,y)==1 && BLACK_WHITE(x+2,y)==1 && BLACK_WHITE(x+4,y)==0)
                {
                    if (formHUOSI(n,x+1,y)==1)
                    {
                        return 1;
                    }
                    
                }
            }
        }else if (i+j==3){
            //two
            if (left-1>=0 && right+1<=14 && BLACK_WHITE(left-1,y)==0 && BLACK_WHITE(right+1,y)==0)
            {
                if (left-3>=0 && BLACK_WHITE(left-3,y)==0 && BLACK_WHITE(left-2,y)==1)
                {
                    if (formHUOSI(n,left-1,y))
                    {
                        return 1;
                    }
                    
                }
                if (right+3>=0 && BLACK_WHITE(right+3,y)==0 && BLACK_WHITE(right+2,y)==1)
                {
                    if (formHUOSI(n,right+1,y))
                    {
                        return 1;
                    }
                    
                }
                
            }
        }
        
    }
    if (n==3)
    {
        i = 1;
        j = 1;
        int left_x,left_y,right_x,right_y;
        while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)==1)
        {
            i++;
        }
        while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)==1)
        {
            j++;
        }
        left_x = x - i + 1;
        right_x = x + j - 1;
        left_y = y - i + 1;
        right_y = y + j - 1;
        if (i+j==4)
        {
            //form continue 3
            if ((left_x-1>=0 && left_y-1>=0 && formHUOSI(n,left_x-1,left_y-1)) ||
              (right_x+1<=14 && right_y+1<=14 && formHUOSI(n,right_x+1,right_y+1)))
            {
                return 1;
            }
            
        }else if (i+j==2){
            //isisland
            if(y-1>=0 && x-1>=0 && y+1<=14 && x+1<=14 && BLACK_WHITE(x-1,y-1)==0 && BLACK_WHITE(x+1,y+1)==0)
            {
                if (y-4>=0 && x-4>=0 && BLACK_WHITE(x-3,y-3)==1 && BLACK_WHITE(x-2,y-2)==1 && BLACK_WHITE(x-4,y-4)==0)
                {   
                    if (formHUOSI(n,x-1,y-1)==1)
                    {
                        return 1;
                    }

                }
                if (y+4<=14 && x+4<=14 && BLACK_WHITE(x+3,y+3)==1 && BLACK_WHITE(x+2,y+2)==1 && BLACK_WHITE(x+4,y+4)==0)
                {
                    if (formHUOSI(n,x+1,y+1)==1)
                    {
                        return 1;
                    }
                    
                }
            }
        }else if (i+j==3){
            //two
            if (left_x-1>=0 && left_y-1>=0 && right_x+1<=14 && right_y+1<=14 && BLACK_WHITE(left_x-1,left_y-1)==0 && BLACK_WHITE(right_x+1,right_y+1)==0)
            {
                if (left_x-3>=0 && left_y-3>=0 && BLACK_WHITE(left_x-3,left_y-3)==0 && BLACK_WHITE(left_x-2,left_y-2)==1)
                {
                    if (formHUOSI(n,left_x-1,left_y-1))
                    {
                        return 1;
                    }
                    
                }
                if (right_x+3>=0 && right_y+3>=0 && BLACK_WHITE(right_x+3,right_y+3)==0 && BLACK_WHITE(right_x+2,right_y+2)==1)
                {
                    if (formHUOSI(n,right_x+1,right_y+1))
                    {
                        return 1;
                    }
                    
                }
                
            }
        }
    }
    if (n==4)
    {
        i = 1;
        j = 1;
        int left_x,left_y,right_x,right_y;
        while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)==1)
        {
            i++;
        }
        while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)==1)
        {
            j++;
        }
        left_x = x + i - 1;
        right_x = x - j + 1;
        left_y = y - i + 1;
        right_y = y + j - 1;
        if (i+j==4)
        {
            //form continue 3
            if ((left_x+1<=14 && left_y-1>=0 && formHUOSI(n,left_x+1,left_y-1)) ||
              (right_x-1>=0 && right_y<=14 && formHUOSI(n,right_x-1,right_y+1)))
            {
                return 1;
            }
            
        }else if (i+j==2){
            //isisland
            if(y-1>=0 && x+1<=14 && y+1<=14 && x-1>=0 && BLACK_WHITE(x+1,y-1)==0 && BLACK_WHITE(x-1,y+1)==0)
            {
                if (y-4>=0 && x+4<=14 && BLACK_WHITE(x+3,y-3)==1 && BLACK_WHITE(x+2,y-2)==1 && BLACK_WHITE(x+4,y-4)==0)
                {
                    if (formHUOSI(n,x+1,y-1)==1)
                    {
                        return 1;
                    }

                }
                if (y+4<=14 && x-4>=0 && BLACK_WHITE(x-3,y+3)==1 && BLACK_WHITE(x-2,y+2)==1 && BLACK_WHITE(x-4,y+4)==0)
                {
                    if (formHUOSI(n,x-1,y+1)==1)
                    {
                        return 1;
                    }
                    
                }
            }
        }else if (i+j==3){
            //two
            if (left_x+1<=14 && left_y-1>=0 && right_x-1>=0 && right_y+1<=14 && BLACK_WHITE(left_x+1,left_y-1)==0 && BLACK_WHITE(right_x-1,right_y+1)==0)
            {
                if (left_x+3<=14 && left_y-3>=0 && BLACK_WHITE(left_x+3,left_y-3)==0 && BLACK_WHITE(left_x+2,left_y-2)==1)
                {
                    if (formHUOSI(n,left_x+1,left_y-1))
                    {
                        return 1;
                    }
                    
                }
                if (right_x-3>=0 && right_y+3<=14 && BLACK_WHITE(right_x-3,right_y+3)==0 && BLACK_WHITE(right_x-2,right_y+2)==1)
                {
                    if (formHUOSI(n,right_x-1,right_y+1))
                    {
                        return 1;
                    }
                    
                }
                
            }
        }

    
    }
    
    return 0;
}
int formHUOSI(int n, int x, int y)
{
    if (BLACK_WHITE(x,y)==2)
        return 0;
    int i = 1;
    int j = 1;
    int left,right;
    int flag = 0;
    if (BLACK_WHITE(x,y)!=1)
    {
        flag = 1;
    }
    //n from 1 to 4 means 4 dims
    arrayForInnerBoardLayout[x][y]=1;
    if (n==1) {
        while (y-i>=0 && BLACK_WHITE(x,y-i)==1)
        {
            i++;
        }
        while (y+j<=14 && BLACK_WHITE(x,y+j)==1)
        {
            j++;
        }
        left = y - i + 1;
        right = y + j - 1;
        if (i+j!=5)
        {
            if (flag==1)
                arrayForInnerBoardLayout[x][y]=0;    
            return 0;
        }
        if (i+j==5)//1111
        {
            if ((left-1>=0 && BLACK_WHITE(x,left-1)==0 && (!(isBANNED_2(x,left-1)==1))) &&
             (right+1<=14 && BLACK_WHITE(x,right+1)==0 && (!(isBANNED_2(x,right+1)==1))))
            {   
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return 1;
            }
        }
    }
    if (n==2) {
        while (x-i>=0 && BLACK_WHITE(x-i,y)==1)
        {
            i++;
        }
        while (y+j<=14 && BLACK_WHITE(x+j,y)==1)
        {
            j++;
        }
        if (i+j!=5)
        {
            if (flag==1)
                 arrayForInnerBoardLayout[x][y]=0; 
            return 0;
        }
        left = x - i + 1;
        right = x + j - 1;
        if (i+j==5)
        {
            
            if ((left-1>=0 && BLACK_WHITE(left-1,y)==0 && (!(isBANNED_2(left-1,y)==1))) &&
             (right+1<=14 && BLACK_WHITE(right+1,y)==0 && (!(isBANNED_2(right+1,y)==1))))
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return 1;
                
            }
        }
        
    }
    int left_x,left_y,right_x,right_y;
    if (n==3)
    {
        while (y-i>=0 && x-i>=0 && BLACK_WHITE(x-i,y-i)==1)
        {
            i++;
        }
        while (y+j<=14 && x+j<=14 && BLACK_WHITE(x+j,y+j)==1)
        {
            j++;
        }
        left_x = x - i + 1;
        right_x = x + j - 1;
        left_y = y - i + 1;
        right_y = y + j - 1;
        if (i+j!=5)
        {
            if (flag==1)
                arrayForInnerBoardLayout[x][y]=0; 
            return 0;
        }
        
        if (i+j==5)
        {
            if ((left_x-1>=0 && left_y-1>=0 && BLACK_WHITE(left_x-1,left_y-1)==0 && (!(isBANNED_2(left_x-1,left_y-1)==1))) &&
             (right_x+1<=14 && right_y+1<=14 && BLACK_WHITE(right_x+1,right_y+1)==0 && (!(isBANNED_2(right_x+1,right_y+1)==1))))
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0;
                return 1;
            }
        }
    }
    if (n==4)
    {
        while (y-i>=0 && x+i<=14 && BLACK_WHITE(x+i,y-i)==1)
        {
            i++;
        }
        while (y+j<=14 && x-j>=0 && BLACK_WHITE(x-j,y+j)==1)
        {
            j++;
        }
        left_x = x + i - 1;
        right_x = x - j + 1;
        left_y = y - i + 1;
        right_y = y + j - 1;
        if (i+j!=5)
        {
            if (flag==1)
                arrayForInnerBoardLayout[x][y]=0; 
            return 0;
        }
        
        if (i+j==5)
        {
            if ((left_x+1<=14 && left_y-1>=0 && BLACK_WHITE(left_x+1,left_y-1)==0 && (!(isBANNED_2(left_x+1,left_y-1)==1))) &&
             (right_x-1>=0 && right_y+1<=14 && BLACK_WHITE(right_x-1,right_y+1)==0 && (!(isBANNED_2(right_x-1,right_y+1)==1))))
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return 1;
            }
        }
    }

    if (flag==1)
        arrayForInnerBoardLayout[x][y]=0; 
    return 0;
}
int isSISI(int x, int y)
{
    int count=0;
    int n;
    for ( n = 1; n < 5; n++)
    {
        count+=formHUOSI(n,x,y);
        count+=formCHONGSI(n,x,y);   
    }
    if (count>=2)
    {
        return 1;
    }
    
    return 0;
}
int formCHONGSI(int n, int x, int y)
{
    if (BLACK_WHITE(x,y)==2)//white, no posibility to formCHONGSI
        return 0;
    int i = 1;
    int j = 1;
    int left,right;
    int flag=0;//flag = 1 means change
    if (arrayForInnerBoardLayout[x][y]!=1)
    {
        flag = 1;
        //use flag to note that we should change back (x, y) before we return something
    }
    arrayForInnerBoardLayout[x][y]=1;
    int count = 0;
    if (n==1)
    {
        while (y-i>=0 && BLACK_WHITE(x,y-i)==1)
        {
            i++;
        }
        while (y+j<=14 && BLACK_WHITE(x,y+j)==1)
        {
            j++;
        }
        left = y - i + 1;
        right = y + j - 1;
        //if i+j-1 == 1,2,3, not 4, we won't worry that it will form HUOSI, while there is only one point that can form 5
        if (i+j==2)//1
        {
            if (left-4>=0 && BLACK_WHITE(x,left-2)==1 && BLACK_WHITE(x,left-3)==1 && BLACK_WHITE(x,left-4)==1 && BLACK_WHITE(x,left-1)==0)
            //1110'1'
            {
                if (!isBANNED_2(x,left-1))
                {
                    count ++;
                }
            }
            if (right+4<=14 && BLACK_WHITE(x,right+2)==1 && BLACK_WHITE(x,right+3)==1 && BLACK_WHITE(x,right+4)==1 && BLACK_WHITE(x,right+1)==0)
            //'1'0111
            {
                if (!isBANNED_2(x,right+1))
                {
                    count++;
                }
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0;
                return count;
            }          
        }
        if (i+j==3)//11
        {
            if (left-3>=0 && BLACK_WHITE(x,left-3)==1 && BLACK_WHITE(x,left-2)==1 && BLACK_WHITE(x,left-1)==0)
            //110'11'
            {
                if (!isBANNED_2(x,left-1))
                {
                    count ++;
                }
            }
            if (right+3<=14 && BLACK_WHITE(x,right+3)==1 && BLACK_WHITE(x,right+2)==1 && BLACK_WHITE(x,right+1)==0)
            //'11'011
            {
                if (!isBANNED_2(x,right+1))
                {
                    count ++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0;
                return count;
            }
        }

        if (i+j==4)//111
        {
            if (left-2>=0 && BLACK_WHITE(x,left-2)==1 && BLACK_WHITE(x,left-1)==0)
            //10'111'
            {
                if (!isBANNED_2(x,left-1))
                {
                    count ++;
                }
                
            }
            if (right+2<=14 && BLACK_WHITE(x,right+2)==1 && BLACK_WHITE(x,right+1)==0)
            //'111'01
            {
                if (!isBANNED_2(x,right+1))
                {
                    count ++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0;    
                return count;
            }
        }
        
        if (i+j==5)//1111
        //now we should worry about whether it is a HUOSI.
        {
            if ((left-1>=0 && BLACK_WHITE(x,left-1)==0 && !(isBANNED_2(x,left-1)==1)) ^
                (right+1<=14 && BLACK_WHITE(x,right+1)==0 && !(isBANNED_2(x,right+1)==1)))
            //0'1111' xor '1111'0. so the “count” must be 1
            {
                if (flag==1)
                {
                    arrayForInnerBoardLayout[x][y]=0;    
                }
                return 1;
            }
            
        }
        if (flag==1)
        {
            arrayForInnerBoardLayout[x][y]=0;    
        }
        return 0;
    }
    if (n==2)
    //just the same as n==1
    {
        while (x-i>=0 && BLACK_WHITE(x-i,y)==1)
        {
            i++;
        }
        while (x+j<=14 && BLACK_WHITE(x+j,y)==1)
        {
            j++;
        }
        left = x - i + 1;
        right = x + j - 1;
        if (i+j==2)
        {
            if (left-4>=0 && BLACK_WHITE(left-2,y)==1 && BLACK_WHITE(left-3,y)==1 && BLACK_WHITE(left-4,y)==1 && BLACK_WHITE(left-1,y)==0)
            {
                if (!isBANNED_2(left-1,y))
                {
                    count ++;
                }
            }
            if (right+4<=14 && BLACK_WHITE(right+2,y)==1 && BLACK_WHITE(right+3,y)==1 && BLACK_WHITE(right+4,y)==1 && BLACK_WHITE(right+1,y)==0)
            {
                if (!isBANNED_2(right+1,y))
                {
                    count ++;
                }
            }
            if (count!=0)
            {
                if (flag==1)
                {
                    arrayForInnerBoardLayout[x][y]=0;    
                }
                return count;
            }
            count = 0;
        }
        if (i+j==3)
        {
            if (left-3>=0 && BLACK_WHITE(left-3,y)==1 && BLACK_WHITE(left-2,y)==1 && BLACK_WHITE(left-1,y)==0)
            {
                if (!isBANNED_2(left-1,y))
                {
                    count++;
                }
                
            }
            if (right++<=14 && BLACK_WHITE(right+3,y)==1 && BLACK_WHITE(right+2,y) && BLACK_WHITE(right+1,y)==0)
            {
                if (!isBANNED_2(right+1,y))
                {
                    count++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                {
                    arrayForInnerBoardLayout[x][y]=0;    
                }
                return count;
            }
            count = 0;
        }
        if (i+j==4)//OOO
        {
            if (left-2>=0 && BLACK_WHITE(left-2,y)==1 && BLACK_WHITE(left-1,y)==0)
            {
                if (!isBANNED_2(left-1,y))
                {
                    count ++;
                }
                
            }
            if (right+2<=14 && BLACK_WHITE(right+2,y)==1 && BLACK_WHITE(right+1,y)==0)
            {
                if (!isBANNED_2(right+1,y))
                {
                    count ++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                {
                    arrayForInnerBoardLayout[x][y]=0;    
                }
                return count;
            }
            count=0;
        }
        
        if (i+j==5)//form 4
        {
            if ((left-1>=0 && BLACK_WHITE(left-1,y)==0 && !(isBANNED_2(left-1,y)==1)) ^
             (right+1<=14 && BLACK_WHITE(right+1,y)==0 && !(isBANNED_2(right+1,y)==1)))
            {
                if (flag==1)
                {
                    arrayForInnerBoardLayout[x][y]=0;    
                }
                return 1;
            }
        }
        if (flag==1)
        {
            arrayForInnerBoardLayout[x][y]=0;    
        }
        return 0;
    }
    int left_x,left_y,right_x,right_y;
    if (n==3)
    {
        while (x-i>=0 && y-i>=0 && BLACK_WHITE(x-i,y-i)==1)
        {
            i++;
        }
        while (x+j<=14 && y+j<=14 && BLACK_WHITE(x+j,y+j)==1)
        {
            j++;
        }
        left_x = x - i + 1;
        right_x = x + j - 1;
        left_y = y - i + 1;
        right_y = y + j - 1;

        if (i+j==2)
        {
            if (left_x-4>=0 && left_y-4>=0 && BLACK_WHITE(left_x-2,left_y-2)==1 && BLACK_WHITE(left_x-3,left_y-3)==1 && BLACK_WHITE(left_x-4,left_y-4)==1 && BLACK_WHITE(left_x-1,left_y-1)==0)
            {
                if (!isBANNED_2(left_x-1,left_y-1))
                {
                    count ++;
                }
                
            }
            if (right_x+4<=14 && right_y+4<=14 && BLACK_WHITE(right_x+2,right_y+2)==1 && BLACK_WHITE(right_x+3,right_y+3)==1 && BLACK_WHITE(right_x+4,right_y+4)==1 && BLACK_WHITE(right_x+1,right_y+1)==0)
            {
                if (!isBANNED_2(right_x+1,right_y+1))
                {
                    count++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return count;
            }
            count = 0;
        }
        if (i+j==3)
        {
            if (left_x-3>=0 && left_y-3>=0 && BLACK_WHITE(left_x-3,left_y-3)==1 && BLACK_WHITE(left_x-2,left_y-2)==1 && BLACK_WHITE(left_x-1,left_y-1)==0)
            {
                if (!isBANNED_2(left_x-1,left_y-1))
                {
                    count ++;
                }
                
            }
            if (right_x+3<=14 && right_y+3<=14 && BLACK_WHITE(right_x+3,right_y+3)==1 && BLACK_WHITE(right_x+2,right_y+2) && BLACK_WHITE(right_x+1,right_y+1)==0)
            {
                if (!isBANNED_2(right_x+1,right_y+1))
                {
                    count++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return count;
            }
            count=0;
        }
        if (i+j==4)//OOO
        {
            if (left_x-2>=0 && left_y-2>=0 && BLACK_WHITE(left_x-2,left_y-2)==1 && BLACK_WHITE(left_x-1,left_y-1)==0)
            {
                if (!isBANNED_2(left_x-1,left_y-1))
                {
                    count++;
                }
                
            }
            if (right_x+2<=14 && right_y+2<=14 && BLACK_WHITE(right_x+2,right_y+2)==1 && BLACK_WHITE(right_x+1,right_y+1)==0)
            {
                if (!isBANNED_2(right_x+1,right_y+1))
                {
                    count++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return count;
            }
            count=0;
            
        }
    
        
        if (i+j==5)
        {
            if ((left_x-1>=0 && left_y-1>=0 && BLACK_WHITE(left_x-1,left_y-1)==0 && !(isBANNED_2(left_x-1,left_y-1)==1)) ^
             (right_x+1<=14 && right_y+1<=14 && BLACK_WHITE(right_x+1,right_y+1)==0 && !(isBANNED_2(right_x+1,right_y+1)==1)))
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return 1;
            }
        }
        if (flag==1)
            arrayForInnerBoardLayout[x][y]=0; 
        return 0;
    }
    if (n==4)
    {
        while (x+i<=14 && y-i>=0 && BLACK_WHITE(x+i,y-i)==1)
        {
            i++;
        }
        while (x-j>=0 && y+j<=14 && BLACK_WHITE(x-j,y+j)==1)
        {
            j++;
        }
        left_x = x + i - 1;
        right_x = x - j + 1;
        left_y = y - i + 1;
        right_y = y + j - 1;

        if (i+j==2)
        {
            if (left_x+4<=14 && left_y-4>=0 && BLACK_WHITE(left_x+2,left_y-2)==1 && BLACK_WHITE(left_x+3,left_y-3)==1 && BLACK_WHITE(left_x+4,left_y-4)==1 && BLACK_WHITE(left_x+1,left_y-1)==0)
            {
                if (!isBANNED_2(left_x+1,left_y-1))
                {
                    count ++;
                }
                
            }
            if (right_x-4>=0 && right_y+4<=14 && BLACK_WHITE(right_x-2,right_y+2)==1 && BLACK_WHITE(right_x-3,right_y+3)==1 && BLACK_WHITE(right_x-4,right_y+4)==1 && BLACK_WHITE(right_x-1,right_y+1)==0)
            {
                if (!isBANNED_2(right_x-1,right_y+1))
                {
                    count++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return count;
            }
            count=0;
        }
        if (i+j==3)
        {
            if (left_x+3<=0 && left_y-3>=0 && BLACK_WHITE(left_x+3,left_y-3)==1 && BLACK_WHITE(left_x+2,left_y-2)==1 && BLACK_WHITE(left_x+1,left_y-1)==0)
            {
                if (!isBANNED_2(left_x+1,left_y-1))
                {
                    count++;
                }
                
            }
            if (right_x-3>=0 && right_y+3<=14 && BLACK_WHITE(right_x-3,right_y+3)==1 && BLACK_WHITE(right_x-2,right_y+2) && BLACK_WHITE(right_x-1,right_y+1)==0)
            {
                if (!isBANNED_2(right_x-1,right_y+1))
                {
                    count++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return count;
            }
            count=0;
        }
        if (i+j==4)//OOO
        {
            if (left_x+2>=0 && left_y-2>=0 && BLACK_WHITE(left_x+2,left_y-2)==1 && BLACK_WHITE(left_x+1,left_y-1)==0)
            {
                if (!isBANNED_2(left_x+1,left_y-1))
                {
                    count++;
                }
                
            }
            if (right_x-2>=0 && right_y+2<=14 && BLACK_WHITE(right_x-2,right_y+2)==1 && BLACK_WHITE(right_x-1,right_y+1)==0)
            {
                if (!isBANNED_2(right_x-1,right_y+1))
                {
                    count++;
                }
                
            }
            if (count!=0)
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return count;
            }
            count=0;
        }

        if (i+j==5)
        {
            if ((left_x+1<=14 && left_y-1>=0 && BLACK_WHITE(left_x+1,left_y-1)==0 && !(isBANNED_2(left_x+1,left_y-1)==1)) ^
             (right_x-1>=0 && right_y+1<=14 && BLACK_WHITE(right_x-1,right_y+1)==0 && !(isBANNED_2(right_x-1,right_y+1)==1)))
            {
                if (flag==1)
                    arrayForInnerBoardLayout[x][y]=0; 
                return 1;
            }
        }
        if (flag==1)
            arrayForInnerBoardLayout[x][y]=0; 
        return 0;
    }
    if (flag==1)
        arrayForInnerBoardLayout[x][y]=0; 
    return 0;
}

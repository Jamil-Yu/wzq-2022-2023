#include "wzq.h"
void initRecordBorard(void);
void innerLayoutToDisplayArray(void);
void displayBoard(void);
int max(int x, int y);
int min(int x, int y);
int win(int n, int x, int y);
int isCHANGLIAN(int x, int y);
int isSANSAN(int x, int y);
int isSISI(int x, int y);
int formHUOSAN(int n,int x,int y);
int formHUOSI(int n, int x, int y);
int formCHONGSI(int n, int x, int y);
int isBANNED(int x, int y);
int black_x,black_y,white_x,white_y;
char arrayForDisplayBoard[SIZE][SIZE*CHARSIZE+1];
char arrayForEmptyBoard[SIZE][SIZE*CHARSIZE+1] = 
{
    "���өөөөөөөөөөөөө�",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "�ĩ��������������",
    "���۩۩۩۩۩۩۩۩۩۩۩۩۩�"
}; 
char play1Pic[]="��";
char play1CurrentPic[]="��"; 
char play2Pic[]="��";
char play2CurrentPic[]="��";
char s[10];
struct point best_choice(int n);//n=1 means ai is black, n=2 means ai is white
int updateScore(int n);
int main()

{
    int x,y,x1,x2,y1,y2,flag;
    int flag_quit = 1;
    struct point bestpoint;
    initRecordBorard();
    innerLayoutToDisplayArray();
    displayBoard();
    int i=0;
    int k=0;
    int flag_first_turn = 0;
    int flag_legal_1 = 1;
    int flag_legal_2 = 1;
    int mode = 0;
    int blackorwhite=0;
    printf("\nWELCOME!!!\n");
    printf("GoBang delivered by Yu Jian. Enjoy yourself!");
    printf("\nChoose mode: input 1 for PVP, input 2 for PVE:\n");
    //get the mode
    while (!(mode == 1 || mode == 2))
    {
        scanf("%s",s);
        if (isdigit(s[0])){
            if (s[i]-'0'==1){
                mode = 1;
            }else if (s[i]-'0'==2){
                mode = 2;
            } 
        }
    }
    
    if (mode == 2) {
        printf("Choose black/white: input 1 to play black, input 2 to play white:\n");
        while (!(blackorwhite == 1 || blackorwhite == 2))
        {
            scanf("%s",s);
            if (isdigit(s[0])){
                if (s[i]-'0'==1){
                    blackorwhite = 1;
                }else if (s[i]-'0'==2){
                    blackorwhite = 2;
                } 
            }
        }
    }
    
    while (flag_quit == 1)
    {
        if (flag_legal_2==1){
            printf("\n");
            if (mode == 1 || blackorwhite == 1){
                printf("player1's Turn\n");
                scanf("%s",s);
                x=0;y=0;

                //whether the player want to quit
                if (s[0]=='q' && s[1]=='u' && s[2]=='i' && s[3]=='t')
                {
                    flag_quit = 0;
                    printf("Game over\n");
                    break;
                }
                
                
                //trans s to x y 
                i = 0;
                if (isdigit(s[i]))
                {
                    while (isdigit(s[i])){
                        x = x * 10 + s[i] - '0';
                        i++;
                    }
                    x--;
                    if (islower(s[i]))
                    {
                        y = s[i] - 'a';
                        i++;
                    }else if (isupper(s[i]))
                    {
                        y = s[i] - 'A';
                        i++;
                    }  
                } else {
                    if (islower(s[i]))
                    {
                        y = s[i] - 'a';
                        i++;
                    }else if (isupper(s[i]))
                    {
                        y = s[i] - 'A';
                        i++;
                    }
                    while (isdigit(s[i])){
                        x = x * 10 + s[i] - '0';
                        i++;
                    }
                    x--;
                }
                

                //test whether the input is legal
                if ((x>14) || (x<0) || (y>14) || (y<0))
                {
                    printf("Out of the board, please input again.");
                    flag_legal_1 = 0;
                }else if(arrayForInnerBoardLayout[14-x][y]!=0){
                    printf("This place has been used. Please try again.");
                    flag_legal_1 = 0;
                }else {
                    flag_legal_1 = 1;
                }
                
            } else {
                bestpoint = best_choice(3-blackorwhite);
                x = 14 - bestpoint.x;
                y = bestpoint.y;
            }
        }
        if (flag_legal_1 == 1) {
            if (flag_legal_2 == 1){
                if(flag_first_turn == 1){
                    arrayForInnerBoardLayout[14-x2][y2]=2;
                }
                flag_first_turn = 1;
                arrayForInnerBoardLayout[14-x][y]=3;
                black_x = 14-x;//for inspire
                black_y = y;//for inspire
                x1=x;y1=y;
                innerLayoutToDisplayArray();
                displayBoard();
                printf("\n%c%d\n",y+'A',x+1);
                printf("\n");
            
                //banned?
                
                if (isBANNED(14-x, y) == 1)
                {
                    printf("\nBANNED place!\nPlayer2 WIN!!!\n");
                    flag_quit = 0;
                    break;
                }

                //player1 win?
                if (win(1,x,y)==1)
                {
                    printf("\nPlayer1 WIN!!!\n");
                    flag_quit = 0;
                    break;
                }
                
                printf("score: %d\n",updateScore(1));
            }
            if (mode==1 || blackorwhite==2){
                printf("player2's Turn\n");
                x=0;y=0;
                scanf("%s",s);
                if (s[0]=='q' && s[1]=='u' && s[2]=='i' && s[3]=='t')
                {
                    flag_quit = 0;
                    printf("Game over\n");
                    break;
                }
                i = 0;

                //trans s to x y
                if (isdigit(s[i]))
                {
                    while (isdigit(s[i])){
                        x = x * 10 + s[i] - '0';
                        i++;
                    }
                    x--;
                    if (islower(s[i]))
                    {
                        y = s[i] - 'a' ;
                        i++;
                    }else if (isupper(s[i]))
                    {
                        y = s[i] - 'A' ;
                        i++;
                    }  
                } else {
                    if (islower(s[i]))
                    {
                        y = s[i] - 'a' ;
                        i++;
                    }else if (isupper(s[i]))
                    {
                        y = s[i] - 'A' ;
                        i++;
                    }
                    while (isdigit(s[i])){
                        x = x * 10 + s[i] - '0';
                        i++;
                    }
                    x--;
                }
                
                //legal?
                if ((x>14) || (x<0) || (y>14) || (y<0))
                {
                    printf("Out of the board, please input again\n");
                    flag_legal_2 = 0;
                }else if (arrayForInnerBoardLayout[14-x][y]!=0){
                    printf("This place has been used. Please try again.\n");
                    flag_legal_2 = 0;
                }else {
                    flag_legal_2 = 1;
                }
                
            }else {
                bestpoint = best_choice(3-blackorwhite);
                x = 14 - bestpoint.x;
                y = bestpoint.y;
            }
            if (flag_legal_2 == 1){
                arrayForInnerBoardLayout[14-x1][y1]=1;
                arrayForInnerBoardLayout[14-x][y]=4;
                x2=x;y2=y;
                white_x = 14-x;
                white_y = y;
                innerLayoutToDisplayArray();
                displayBoard();
                printf("\n%c%d\n",y+'A',x+1);
                //player2 win?
                if (win(2,x,y)==1)
                {
                    printf("\nPlayer2 WIN!!!\n");
                    flag_quit = 0;
                }
                
                printf("\nscore: %d\n",updateScore(1));
            }
        }
        
    }
    system("pause");
    return 0;

}

void initRecordBorard(void){
    int i,j;
    for ( i = 0; i < SIZE; i++)
    {
        for ( j = 0; j < SIZE; j++)
        {
            arrayForInnerBoardLayout[i][j]=0;
        }
    }
    
}
//end inital the board

void innerLayoutToDisplayArray(void){
    int i,j;
    for ( i = 0; i < SIZE; i++)
    {
        for ( j = 0; j < SIZE*CHARSIZE+1; j++)
        {
            arrayForDisplayBoard[i][j] = arrayForEmptyBoard[i][j];
        }
    }

    for ( i = 0; i < SIZE; i++)
    {
        for ( j = 0; j < SIZE; j++)
        {
            if (arrayForInnerBoardLayout[i][j]==1)
            {
                arrayForDisplayBoard[i][j*CHARSIZE]=play1Pic[0];
                arrayForDisplayBoard[i][j*CHARSIZE+1]=play1Pic[1];
            }
            if (arrayForInnerBoardLayout[i][j]==2)
            {
                arrayForDisplayBoard[i][j*CHARSIZE]=play2Pic[0];
                arrayForDisplayBoard[i][j*CHARSIZE+1]=play2Pic[1];
            }
            if (arrayForInnerBoardLayout[i][j]==3)
            {
                arrayForDisplayBoard[i][j*CHARSIZE]=play1CurrentPic[0];
                arrayForDisplayBoard[i][j*CHARSIZE+1]=play1CurrentPic[1];
            }
            if (arrayForInnerBoardLayout[i][j]==4)
            {
                arrayForDisplayBoard[i][j*CHARSIZE]=play2CurrentPic[0];
                arrayForDisplayBoard[i][j*CHARSIZE+1]=play2CurrentPic[1];
            }
        }
    }
 
}


void displayBoard(void){
	int i,j;
	system("cls"); 
    printf("\nWork of Yu Jian\n");
    printf("\n");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%3d ",15-i);
        for ( j = 0; j < SIZE*CHARSIZE+1; j++)
        {
            printf("%c",arrayForDisplayBoard[i][j]);
        }
        printf("\n");
    } 
    printf("     ");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%c ",i+'A');
    }
} 
//End the show of the board

int win(int n, int x, int y)//full FIVE? WIN!!!
{
    //the situation of player1 becomes winner
    int i,j;
    int result = 0;
    if (n == 1)
    {
        x = 14 - x;
        i = 1;
        j = 1;
        while (y-i>=0 && (arrayForInnerBoardLayout[x][y-i]==1 || arrayForInnerBoardLayout[x][y-i]==3))
        {
            i++;
        }
        while (y+j<=14 && (arrayForInnerBoardLayout[x][y+j]==1 || arrayForInnerBoardLayout[x][y+j]==3))
        {
            j++;
        }
        if (i+j==6)//form five
        {
            return 1;
        } else {
            i = 1;
            j = 1;
        }
        
        while (x-i>=0 && (arrayForInnerBoardLayout[x-i][y]==1 || arrayForInnerBoardLayout[x-i][y]==3))
        {
            i++;
        }
        while (x+j<=14 && (arrayForInnerBoardLayout[x+j][y]==1 || arrayForInnerBoardLayout[x+j][y]==3))
        {
            j++;
        }
        if (i+j==6)
        {
            return 1;
        } else {
            i = 1;
            j = 1;
        }

        while (x-i>=0 && y-i>=0 && (arrayForInnerBoardLayout[x-i][y-i]==1 || arrayForInnerBoardLayout[x-i][y-i]==3))
        {
            i++;
        }
        while (x+j<=14 && y+j<=14 && (arrayForInnerBoardLayout[x+j][y+j]==1 || arrayForInnerBoardLayout[x+j][y+j]==3))
        {
            j++;
        }
        if (i+j==6)
        {
            return 1;
        } else {
            i = 1;
            j = 1;
        }
        while (x+i<=14 && y-i>=0 && (arrayForInnerBoardLayout[x+i][y-i]==1 || arrayForInnerBoardLayout[x+i][y-i]==1))
        {
            i++;
        }
        while (x-j>=0 && y+j<=14 && (arrayForInnerBoardLayout[x-j][y+j]==1 || arrayForInnerBoardLayout[x-j][y+j]==3))
        {
            j++;
        }
        if (i+j==6)
        {
            return 1;
        } else {
            i = 1;
            j = 1;
        }
        return 0;
        }
        
        
    
    //the situation of player2 becomes winner
    if (n == 2)
    {
        x=14-x;
        int i = 1;
        int j = 1;
        while (y-i>=0 && (arrayForInnerBoardLayout[x][y-i]==2 || arrayForInnerBoardLayout[x][y-i]==4))
        {
            i++;
        }
        while (y+j<=14 && (arrayForInnerBoardLayout[x][y+j]==2 || arrayForInnerBoardLayout[x][y+j]==4))
        {
            j++;
        }
        if (i+j==6)//form changlian in this dim
        {
            return 1;
        } else {
            i = 1;
            j = 1;
        }
        while (x-i>=0 && (arrayForInnerBoardLayout[x-i][y]==2 || arrayForInnerBoardLayout[x-i][y]==4))
        {
            i++;
        }
        while (x+j<=14 && (arrayForInnerBoardLayout[x+j][y]==2 || arrayForInnerBoardLayout[x+j][y]==4))
        {
            j++;
        }
        if (i+j==6)
        {
            return 1;
        } else {
            i = 1;
            j = 1;
        }
        while (x-i>=0 && y-i>=0 && (arrayForInnerBoardLayout[x-i][y-i]==2 || arrayForInnerBoardLayout[x-i][y-i]==4))
        {
            i++;
        }
        while (x+j<=14 && y+j<=14 && (arrayForInnerBoardLayout[x+j][y+j]==2 || arrayForInnerBoardLayout[x+j][y+j]==4))
        {
            j++;
        }
        if (i+j==6)
        {
            return 1;
        } else {
            i = 1;
            j = 1;
        }
        while (x+i<=14 && y-i>=0 && (arrayForInnerBoardLayout[x+i][y-i]==2 || arrayForInnerBoardLayout[x+i][y-i]==4))
        {
            i++;
        }
        while (x-j>=0 && y+j<=14 && (arrayForInnerBoardLayout[x-j][y+j]==2 || arrayForInnerBoardLayout[x-j][y+j]==4))
        {
            j++;
        }
        if (i+j==6)
        {
            return 1;
        } else {
            i = 1;
            j = 1;
        }
        return 0;
        
    }

}

int max(int x, int y)
{
    if (x>y){
        return x;
    }else {
        return y;
    }

}
int min(int x, int y)
{
    if (x<y){
        return x;
    }else {
        return y;
    }

}
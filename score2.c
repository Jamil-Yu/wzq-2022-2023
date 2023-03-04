#include "wzq.h"

int Score(int i, int j, int n)
{	
	if (n==1){
    int x, y;
	int n1, n2, n3, n4;//record the link numbe
	int b1, b2, b3, b4;//judge whether the chess is "live"("HUO" in chinese)
	int p1, p2, p3, p4;//judge jump 3
	int q1, q2, q3, q4, q;//judge jump 4
	int f1, f2, f3, f4;//judge fake HUOSAN
	int m1, m2, m3, m4;//judge MIANSAN
	int e1, e2, e3, e4;//judge HUOER
	int s1, s2, s3, s4;//judge MIANER
	int value;//record the score
	value = 0;
	x = i;
	y = j;
	//link in dim 1
	n1 = 0;
	b1 = 0;
	while (x+1 <= 14 && BLACK_WHITE(x + 1,j) == 1) {
		++x;
		++n1;
	}
	if (x == 14 || BLACK_WHITE(x + 1,j) == 2)
		++b1;
	x = i;
	y = j;
	while (x-1 >= 0 && BLACK_WHITE(x - 1,j) == 1) {
		--x;
		++n1;
	}
	if (x == 0 || BLACK_WHITE(x - 1,j) == 2)
		++b1;
	x = i;
	y = j;
	//link in dim 2
	n2 = 0;
	b2 = 0;
	while (y+1<=14 && BLACK_WHITE(i,y + 1) == 1) {
		++y;
		++n2;
	}
	if (y == 14 || BLACK_WHITE(i,y + 1) == 2)
		++b2;
	x = i;
	y = j;
	while (y-1>=0 && BLACK_WHITE(i,y - 1) == 1) {
		--y;
		++n2;
	}
	if (y == 0 || BLACK_WHITE(i,y - 1) == 2)
		++b2;
	x = i;
	y = j;
	//link in dim 3
	n3 = 0;
	b3 = 0;
	while (x+1<=14 && y+1<=14 && BLACK_WHITE(x + 1,y + 1) == 1) {
		++x;
		++y;
		++n3;
	}
	if (x == 14 || y == 14 || BLACK_WHITE(x + 1,y + 1) == 2)
		++b3;
	x = i;
	y = j;
	while (x-1>=0 && y-1>=0 && BLACK_WHITE(x - 1,y - 1) == 1) {
		--x;
		--y;
		++n3;
	}
	if (x == 0 || y == 0 || BLACK_WHITE(x - 1,y - 1) == 2)
		++b3;
	x = i;
	y = j;
	//link in dim 4
	n4 = 0;
	b4 = 0;
	while (x+1<=14 && y-1>=0 && BLACK_WHITE(x + 1,y - 1) == 1) {
		++x;
		--y;
		++n4;
	}
	if (x == 14 || y == 0 || BLACK_WHITE(x + 1,y - 1) == 2)
		++b4;
	x = i;
	y = j;
	while (x-1>=0 && y+1<=14 && BLACK_WHITE(x - 1,y + 1) == 1) {
		--x;
		++y;
		++n4;
	}
	if (x == 0 || y == 14 || BLACK_WHITE(x - 1,y + 1) == 2)
		++b4;
	x = i;
	y = j;
	//judge HUOER
	//dim1
	e1 = 0;
	if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 1,j) == 1)
		++e1;
	if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 1,j) == 1)
		++e1;
	//011000 
	if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i + 1,j) == 1)
		++e1;
	if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i - 1,j) == 1)
		++e1;
	if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i - 1,j) == 1)
		++e1;
	if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i + 1,j) == 1)
		++e1;
	//001010 
	if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 2,j) == 1)
		++e1;
	if (BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2,j) == 1)
		++e1;
	if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 2,j) == 1)
		++e1;
	if (BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2,j) == 1)
		++e1;
	//010010 
	if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i + 3,j) == 1)
		++e1;
	if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i - 3,j) == 1)
		++e1;
	//dim 2
	e2 = 0;
	//001100 
	if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i,j + 1) == 1)
		++e2;
	if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i,j - 1) == 1)
		++e2;
	//011000 
	if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i,j + 1) == 1)
		++e2;
	if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i,j - 1) == 1)
		++e2;
	if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i,j - 1) == 1)
		++e2;
	if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i,j + 1) == 1)
		++e2;
	//001010 
	if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i,j + 2) == 1)
		++e2;
	if (BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i,j - 2) == 1)
		++e2;
	if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i,j - 2) == 1)
		++e2;
	if (BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i,j + 2) == 1)
		++e2;
	//010010 
	if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i,j + 3) == 1)
		++e2;
	if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i,j - 3) == 1)
		++e2;
	//dim 3
	e3 = 0;
	//001100 
	if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 1,j + 1) == 1)
		++e3;
	if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 1,j - 1) == 1)
		++e3;
	//011000 
	if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i + 1,j + 1) == 1)
		++e3;
	if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i - 1,j - 1) == 1)
		++e3;
	if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i - 1,j - 1) == 1)
		++e3;
	if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i + 1,j + 1) == 1)
		++e3;
	//001010 
	if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 2,j + 2) == 1)
		++e3;
	if (BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2,j - 2) == 1)
		++e3;
	if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 2,j - 2) == 1)
		++e3;
	if (BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2,j + 2) == 1)
		++e3;
	//010010 
	if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i + 3,j + 3) == 1)
		++e3;
	if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i - 3,j - 3) == 1)
		++e3;
	//dim 4
	e4 = 0;
	//001100 
	if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 1,j - 1) == 1)
		++e4;
	if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 1,j + 1) == 1)
		++e4;
	//011000 
	if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i + 1,j - 1) == 1)
		++e4;
	if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i - 1,j + 1) == 1)
		++e4;
	if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i - 1,j + 1) == 1)
		++e4;
	if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i + 1,j - 1) == 1)
		++e4;
	//001010 

	if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 2,j - 2) == 1)
		++e4;
	if (BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2,j + 2) == 1)
		++e4;
	if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 2,j + 2) == 1)
		++e4;
	if (BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2,j - 2) == 1)
		++e4;
	//010010 
	if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i + 3,j - 3) == 1)
		++e4;
	if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i - 3,j + 3) == 1)
		++e4;
	//MIANER 
	//dim 1
	s1 = 0;
	//211000 
	if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i + 1,j) == 1)
		++s1;
	if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 1 && BLACK_WHITE(i - 1,j) == 1)
		++s1;
	if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i - 1,j) == 1)
		++s1;
	if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 1 && BLACK_WHITE(i + 1,j) == 1)
		++s1;
	//210100 
	if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i + 2,j) == 1)
		++s1;
	if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 1 && BLACK_WHITE(i - 2,j) == 1)
		++s1;
	if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i - 2,j) == 1)
		++s1;
	if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 1 && BLACK_WHITE(i + 2,j) == 1)
		++s1;
	//210010 
	if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i + 3,j) == 1)
		++s1;
	if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 1 && BLACK_WHITE(i - 3,j) == 1)
		++s1;
	if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i - 3,j) == 1)
		++s1;
	if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 1 && BLACK_WHITE(i + 3,j) == 1)
		++s1;
	//10001 
	if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4,j) == 1)
		++s1;
	if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4,j) == 1)
		++s1;
	//2001102 
	if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 1)
		++s1;
	if (BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 1)
		++s1;
	if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 1)
		++s1;
	if (BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 1)
		++s1;
	//2010102 
	if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 1)
		++s1;
	if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 1)
		++s1;
	//dim 2
	s2 = 0;
	//211000 
	if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j + 1) == 1)
		++s2;
	if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 1 && BLACK_WHITE(i,j - 1) == 1)
		++s2;
	if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j - 1) == 1)
		++s2;
	if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 1 && BLACK_WHITE(i,j + 1) == 1)
		++s2;
	//210100 
	if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j + 2) == 1)
		++s2;
	if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 1 && BLACK_WHITE(i,j - 2) == 1)
		++s2;
	if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j - 2) == 1)
		++s2;
	if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 1 && BLACK_WHITE(i,j + 2) == 1)
		++s2;
	//210010 
	if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j + 3) == 1)
		++s2;
	if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 1 && BLACK_WHITE(i,j - 3) == 1)
		++s2;
	if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j - 3) == 1)
		++s2;
	if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 1 && BLACK_WHITE(i,j + 3) == 1)
		++s2;
	//10001 
	if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i,j + 4) == 1)
		++s2;
	if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i,j - 4) == 1)
		++s2;
	//2001102 
	if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i , j- 1) == 0 && BLACK_WHITE(i , j+ 2) == 0 && BLACK_WHITE(i , j- 3) != 0 && BLACK_WHITE(i,j - 3) != 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i , j+ 3) != 0 && BLACK_WHITE(i ,j+ 3) != 1)
		++s1;
	if (BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i , j+ 1) == 0 && BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 1 && BLACK_WHITE(i ,j- 1) == 1 && BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 1)
		++s1;
	if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 1)
		++s2;
	if (BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 1)
		++s2;
	//2010102 
	if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 1)
		++s2;
	if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 1)
		++s2;
	//dim 3
	s3 = 0;
	//211000 
	if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i + 1,j + 1) == 1)
		++s3;
	if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 1 && BLACK_WHITE(i - 1,j - 1) == 1)
		++s3;
	if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i - 1,j - 1) == 1)
		++s3;
	if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 1 && BLACK_WHITE(i + 1,j + 1) == 1)
		++s3;
	//210100 
	if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i + 2,j + 2) == 1)
		++s3;
	if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 1 && BLACK_WHITE(i - 2,j - 2) == 1)
		++s3;
	if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i - 2,j - 2) == 1)
		++s3;
	if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 1 && BLACK_WHITE(i + 2,j + 2) == 1)
		++s3;
	//210010 
	if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i + 3,j + 3) == 1)
		++s3;
	if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 1 && BLACK_WHITE(i - 3,j - 3) == 1)
		++s3;
	if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i - 3,j - 3) == 1)
		++s3;
	if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 1 && BLACK_WHITE(i + 3,j + 3) == 1)
		++s3;
	//10001 
	if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4,j + 4) == 1)
		++s3;
	if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4,j - 4) == 1)
		++s3;
	//2001102 
	if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 1)
		++s3;
	if (BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 1)
		++s3;
	if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 1)
		++s3;
	if (BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 1)
		++s3;
	//2010102 
	if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 1)
		++s3;
	if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 1)
		++s3;
	//dim 4
	s4 = 0;
	//211000 
	if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i + 1,j - 1) == 1)
		++s4;
	if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 1 && BLACK_WHITE(i - 1,j + 1) == 1)
		++s4;
	if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i - 1,j + 1) == 1)
		++s4;
	if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 1 && BLACK_WHITE(i + 1,j - 1) == 1)
		++s4;
	//210100 
	if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i + 2,j - 2) == 1)
		++s4;
	if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 1 && BLACK_WHITE(i - 2,j + 2) == 1)
		++s4;
	if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i - 2,j + 2) == 1)
		++s4;
	if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 1 && BLACK_WHITE(i + 2,j - 2) == 1)
		++s4;
	//210010 
	if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i + 3,j - 3) == 1)
		++s4;
	if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 1 && BLACK_WHITE(i - 3,j + 3) == 1)
		++s4;
	if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i - 3,j + 3) == 1)
		++s4;
	if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 1 && BLACK_WHITE(i + 3,j - 3) == 1)
		++s4;
	//10001 
	if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4,j - 4) == 1)
		++s4;
	if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4,j + 4) == 1)
		++s4;
	//2001102 
	if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 1)
		++s4;
	if (BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 1)
		++s4;
	if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 1)
		++s4;
	if (BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 1)
		++s4;
	//2010102 
	if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 1)
		++s4;
	if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 1)
		++s4;
	//jump 3
	p1 = 0;
	if (b1 == 0) {
		if (n1 == 0) {
			if (BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 4,j) != 2 && BLACK_WHITE(i - 4,j) != 1 && i != 3 && BLACK_WHITE(i - 4, j) == 0)
				++p1;
			if (BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 4,j) != 2 && BLACK_WHITE(i + 4,j) != 1 && i != 11 && BLACK_WHITE(i + 4, j) == 0)
				++p1;
		}
		if (n1 == 1) {
			if (BLACK_WHITE(i - 1,j) == 1) {
				if (BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 4,j) != 2 && BLACK_WHITE(i - 4,j) != 1 && i != 3 && BLACK_WHITE(i - 4, j) == 0)
					++p1;
				if (BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 3,j) != 2 && BLACK_WHITE(i + 3,j) != 1 && i != 12 && BLACK_WHITE(i + 3, j) == 0)
					++p1;
			}
			if (BLACK_WHITE(i + 1,j) == 1) {
				if (BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 4,j) != 2 && BLACK_WHITE(i + 4,j) != 1 && i != 11 && BLACK_WHITE(i + 4, j) == 0)
					++p1;
				if (BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 3,j) != 2 && BLACK_WHITE(i - 3,j) != 1 && i != 2 && BLACK_WHITE(i - 3, j) == 0)
					++p1;
			}
		}
	}
	p2 = 0;
	if (b2 == 0) {
		if (n2 == 0) {
			if (BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i,j - 4) != 2 && BLACK_WHITE(i,j - 4) != 1 && i != 3 && BLACK_WHITE(i, j - 4) == 0)
				++p2;
			if (BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i,j + 4) != 2 && BLACK_WHITE(i,j + 4) != 1 && i != 11 && BLACK_WHITE(i, j + 4) == 0)
				++p2;
		}
		if (n2 == 1) {
			if (BLACK_WHITE(i,j - 1) == 1) {
				if (BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i,j - 4) != 2 && BLACK_WHITE(i,j - 4) != 1 && i != 3 && BLACK_WHITE(i, j - 4) == 0)
					++p2;
				if (BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 3) != 2 && BLACK_WHITE(i,j + 3) != 1 && i != 12 && BLACK_WHITE(i, j + 3) == 0)
					++p2;
			}
			if (BLACK_WHITE(i,j + 1) == 1) {
				if (BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i,j + 4) != 2 && BLACK_WHITE(i,j + 4) != 1 && i != 11 && BLACK_WHITE(i, j + 4) == 0)
					++p2;
				if (BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j - 3) != 2 && BLACK_WHITE(i,j - 3) != 1 && i != 2 && BLACK_WHITE(i, j - 3) == 0)
					++p2;
			}
		}
	}
	p3 = 0;
	if (b3 == 0) {
		if (n3 == 0) {
			if (BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 4,j - 4) != 2 && BLACK_WHITE(i - 4,j - 4) != 1 && i != 3 && j != 3 && BLACK_WHITE(i - 4, j - 4) == 0)
				++p3;
			if (BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 4,j + 4) != 2 && BLACK_WHITE(i + 4,j + 4) != 1 && i != 11 && j != 11 && BLACK_WHITE(i + 4, j + 4) == 0)
				++p3;
		}
		if (n3 == 1) {
			if (BLACK_WHITE(i - 1,j - 1) == 1) {
				if (BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 4,j - 4) != 2 && BLACK_WHITE(i - 4,j - 4) != 1 && i != 3 && j != 3 && BLACK_WHITE(i - 4, j - 4) == 0)
					++p3;
				if (BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 3,j + 3) != 2 && BLACK_WHITE(i + 3,j + 3) != 1 && i != 12 && j != 12 && BLACK_WHITE(i + 3, j + 3) == 0)
					++p3;
			}
			if (BLACK_WHITE(i + 1,j + 1) == 1) {
				if (BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 4,j + 4) != 2 && BLACK_WHITE(i + 4,j + 4) != 1 && i != 11 && j != 11 && BLACK_WHITE(i + 4, j + 4) == 0)
					++p3;
				if (BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 3,j - 3) != 2 && BLACK_WHITE(i - 3,j - 3) != 1 && i != 2 && j != 2 && BLACK_WHITE(i - 3, j - 3) == 0)
					++p3;
			}
		}
	}
	p4 = 0;
	if (b4 == 0) {
		if (n4 == 0) {
			if (BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 4,j + 4) != 2 && BLACK_WHITE(i - 4,j + 4) != 1 && i != 3 && j != 11 && BLACK_WHITE(i - 4, j + 4) == 0)
				++p4;
			if (BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 4,j - 4) != 2 && BLACK_WHITE(i + 4,j - 4) != 1 && i != 11 && j != 3 && BLACK_WHITE(i + 4, j - 4) == 0)
				++p4;
		}
		if (n4 == 1) {
			if (BLACK_WHITE(i - 1,j + 1) == 1) {
				if (BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 4,j + 4) != 2 && BLACK_WHITE(i - 4,j + 4) != 1 && i != 3 && j != 11 && BLACK_WHITE(i - 4, j + 4) == 0)
					++p4;
				if (BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 3,j - 3) != 2 && BLACK_WHITE(i + 3,j - 3) != 1 && i != 12 && j != 2 && BLACK_WHITE(i + 3, j - 3) == 0)
					++p4;
			}
			if (BLACK_WHITE(i + 1,j - 1) == 1) {
				if (BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 4,j - 4) != 2 && BLACK_WHITE(i + 4,j - 4) != 1 && i != 11 && j != 3 && BLACK_WHITE(i + 4, j - 4) == 0)
					++p4;
				if (BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 3,j + 3) != 2 && BLACK_WHITE(i - 3,j + 3) != 1 && i != 2 && j != 12 && BLACK_WHITE(i - 3, j + 3) == 0)
					++p4;
			}
		}
	}
	//fake 3
	f1 = 0;
	if (n1 == 2 && b1 == 0) {
		if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 1,j) == 1 && (BLACK_WHITE(i - 3,j) == 2 || i == 2) && (BLACK_WHITE(i + 3,j) == 2 || i == 12))
			f1 = 2;
		else if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 2,j) == 1 && (BLACK_WHITE(i - 4,j) == 2 || i == 3) && (BLACK_WHITE(i + 2,j) == 2 || i == 13))
			f1 = 2;
		else if (BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 2,j) == 1 && (BLACK_WHITE(i - 2,j) == 2 || i == 1) && (BLACK_WHITE(i + 4,j) == 2 || i == 11))
			f1 = 2;
		else if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i - 3,j) != 1 && BLACK_WHITE(i + 3,j) != 1)
			f1 = 1;
		else if (BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i - 2,j) != 1 && BLACK_WHITE(i + 4,j) != 1)
			f1 = 1;
		else if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i + 2,j) != 1 && BLACK_WHITE(i - 4,j) != 1)
			f1 = 1;
	}
	f2 = 0;
	if (n2 == 2 && b2 == 0) {
		if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j + 1) == 1 && (BLACK_WHITE(i,j - 3) == 2 || j == 2) && (BLACK_WHITE(i,j + 3) == 2 || j == 12))
			f2 = 2;
		else if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j - 2) == 1 && (BLACK_WHITE(i,j - 4) == 2 || j == 3) && (BLACK_WHITE(i,j + 2) == 2 || j == 13))
			f2 = 2;
		else if (BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j + 2) == 1 && (BLACK_WHITE(i,j - 2) == 2 || j == 1) && (BLACK_WHITE(i,j + 4) == 2 || j == 11))
			f2 = 2;
		else if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j - 3) != 1 && BLACK_WHITE(i,j + 3) != 1)
			f2 = 1;
		else if (BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j - 2) != 1 && BLACK_WHITE(i,j + 4) != 1)
			f2 = 1;
		else if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j + 2) != 1 && BLACK_WHITE(i,j - 4) != 1)
			f2 = 1;
	}
	f3 = 0;
	if (n3 == 2 && b3 == 0) {
		if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 1,j + 1) == 1 && (BLACK_WHITE(i - 3,j - 3) == 2 || i == 2 || j == 2) && (BLACK_WHITE(i + 3,j + 3) == 2 || i == 12 || j == 12))
			f3 = 2;
		else if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 2,j - 2) == 1 && (BLACK_WHITE(i - 4,j - 4) == 2 || i == 3 || j == 3) && (BLACK_WHITE(i + 2,j + 2) == 2 || i == 13 || j == 13))
			f3 = 2;
		else if (BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 2,j + 2) == 1 && (BLACK_WHITE(i - 2,j - 2) == 2 || i == 1 || j == 1) && (BLACK_WHITE(i + 4,j + 4) == 2 || i == 11 || j == 11))
			f3 = 2;
		else if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i - 3,j - 3) != 1 && BLACK_WHITE(i + 3,j + 3) != 1)
			f3 = 1;
		else if (BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i - 2,j - 2) != 1 && BLACK_WHITE(i + 4,j + 4) != 1)
			f3 = 1;
		else if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i + 2,j + 2) != 1 && BLACK_WHITE(i - 4,j - 4) != 1)
			f3 = 1;
	}
	f4 = 0;
	if (n4 == 2 && b4 == 0) {
		if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 1,j - 1) == 1 && (BLACK_WHITE(i - 3,j + 3) == 2 || i == 2 || j == 12) && (BLACK_WHITE(i + 3,j - 3) == 2 || i == 12 || j == 2))
			f4 = 2;
		else if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 2,j + 2) == 1 && (BLACK_WHITE(i - 4,j + 4) == 2 || i == 3 || j == 11) && (BLACK_WHITE(i + 2,j - 2) == 2 || i == 13 || j == 1))
			f4 = 2;
		else if (BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 2,j - 2) == 1 && (BLACK_WHITE(i - 2,j + 2) == 2 || i == 1 || j == 13) && (BLACK_WHITE(i + 4,j - 3) == 2 || i == 11 || j == 3))
			f4 = 2;
		else if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i - 3,j + 3) != 1 && BLACK_WHITE(i + 3,j - 3) != 1)
			f4 = 1;
		else if (BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i - 2,j + 2) != 1 && BLACK_WHITE(i + 4,j - 4) != 1)
			f4 = 1;
		else if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i + 2,j - 2) != 1 && BLACK_WHITE(i - 4,j + 4) != 1)
			f4 = 1;
	}
	//MIANSAN
	//dim 1 
	m1 = 0;
	//211100 
	if (BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0)
		++m1;
	//211010 
	if (BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 4, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 4, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0)
		++m1;
	//210110 
	if (BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 4, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 4, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0)
		++m1;
	//11001 
	if (BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 4,j) == 1 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 4,j) == 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 4,j) == 1 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0)
		++m1;
	if (BLACK_WHITE(i + 4,j) == 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0)
		++m1;
	//10101 
	if (BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 4,j) == 1 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0)
		++m1;
	if (BLACK_WHITE(i - 4,j) == 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0)
		++m1;
	//横dim 2
	m2 = 0;
	//211100 
	if (BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 4) == 0)
		++m2;
	if (BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0)
		++m2;
	if (BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 4) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0)
		++m2;
	//211010 
	if (BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 4) == 0)
		++m2;
	if (BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0)
		++m2;
	if (BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 4) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0)
		++m2;
	//210110 
	if (BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 4) == 0)
		++m2;
	if (BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 2) == 0)
		++m2;
	if (BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 1) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 4) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 2) == 0)
		++m2;
	if (BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 1) == 0)
		++m2;
	//11001 
	if (BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j + 4) == 1 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0)
		++m2;
	if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0)
		++m2;
	if (BLACK_WHITE(i,j - 4) == 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0)
		++m2;
	if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j - 4) == 1 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i, j - 3) == 0)
		++m2;
	if (BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0)
		++m2;
	if (BLACK_WHITE(i,j + 4) == 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0)
		++m2;
	//10101 
	if (BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 4) == 1 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0)
		++m2;
	if (BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0)
		++m2;
	if (BLACK_WHITE(i,j - 4) == 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0)
		++m2;
	//dim 3
	m3 = 0;
	//211100 
	if (BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4, j + 4) == 0)
		++m3;
	if (BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0)
		++m3;
	if (BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0)
		++m3;
	if (BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0)
		++m3;
	if (BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4, j - 4) == 0)
		++m3;
	if (BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0)
		++m3;
	//211010 
	if (BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 4, j + 4) == 0)
		++m3;
	if (BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0)
		++m3;
	if (BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0)
		++m3;
	if (BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 4, j - 4) == 0)
		++m3;
	if (BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0)
		++m3;
	if (BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0)
		++m3;
	//210110 
	if (BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 4, j + 4) == 0)
		++m3;
	if (BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 1 && BLACK_WHITE(i - 2,j - 3) == 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0)
		++m3;
	if (BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0)
		++m3;
	if (BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 4, j - 4) == 0)
		++m3;
	if (BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0)
		++m3;
	if (BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0)
		++m3;
	//11001 
	if (BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 4,j + 4) == 1 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0)
		++m3;
	if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0)
		++m3;
	if (BLACK_WHITE(i - 4,j - 4) == 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0)
		++m3;
	if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 4,j - 4) == 1 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0)
		++m3;
	if (BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0)
		++m3;
	if (BLACK_WHITE(i + 4,j + 4) == 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0)
		++m3;
	//10101 
	if (BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 4,j + 4) == 1 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0)
		++m3;
	if (BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0)
		++m3;
	if (BLACK_WHITE(i - 4,j - 4) == 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0)
		++m3;
	//dim 4
	m4 = 0;
	//211100 
	if (BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4, j - 4) == 0)
		++m4;
	if (BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0)
		++m4;
	if (BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0)
		++m4;
	if (BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0)
		++m4;
	if (BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4, j + 4) == 0)
		++m4;
	if (BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0)
		++m4;
	//211010 
	if (BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 4, j - 4) == 0)
		++m4;
	if (BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0)
		++m4;
	if (BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0)
		++m4;
	if (BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 4, j + 4) == 0)
		++m4;
	if (BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0)
		++m4;
	if (BLACK_WHITE(i + 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0)
		++m4;
	//210110 
	if (BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 4, j - 4) == 0)
		++m4;
	if (BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 1 && BLACK_WHITE(i - 2,j + 3) == 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0)
		++m4;
	if (BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0)
		++m4;
	if (BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 4, j + 4) == 0)
		++m4;
	if (BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0)
		++m4;
	if (BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0)
		++m4;
	//11001 
	if (BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 4,j - 4) == 1 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0)
		++m4;
	if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0)
		++m4;
	if (BLACK_WHITE(i - 4,j + 4) == 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0)
		++m4;
	if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 4,j + 4) == 1 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0)
		++m4;
	if (BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0)
		++m4;
	if (BLACK_WHITE(i + 4,j - 4) == 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0)
		++m4;
	//10101 
	if (BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 4,j - 4) == 1 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0)
		++m4;
	if (BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0)
		++m4;
	if (BLACK_WHITE(i - 4,j + 4) == 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0)
		++m4;
	//jump 4
	q = 0;
	//dim 1 
	q1 = 0;
	if (n1 == 0) {
		if (BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 4,j) == 1 && BLACK_WHITE(i - 5,j) != 1)
		{
			if (BLACK_WHITE(i - 1, j) == 0)
				++q1;
		}
		if (BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 4,j) == 1 && BLACK_WHITE(i + 5,j) != 1)
		{
			if (BLACK_WHITE(i + 1, j) == 0)
				++q1;
		}
	}
	if (n1 == 1) {
		if (BLACK_WHITE(i + 1,j) == 1) {
			if (BLACK_WHITE(i + 2,j) != 2 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 4,j) == 1 && BLACK_WHITE(i + 5,j) != 1)
			{
				if (BLACK_WHITE(i + 2, j) == 0)
					++q1;
			}
			if (BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 4,j) != 1)
			{
				if (BLACK_WHITE(i - 1, j) == 0)
					++q1;
			}
		}
		if (BLACK_WHITE(i - 1,j) == 1) {
			if (BLACK_WHITE(i - 2,j) != 2 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 4,j) == 1 && BLACK_WHITE(i - 5,j) != 1)
			{
				if (BLACK_WHITE(i - 2, j) == 0)
					++q1;
			}
			if (BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 4,j) != 1)
			{
				if (BLACK_WHITE(i + 1, j) == 0)
					++q1;
			}
		}
	}
	if (n1 == 2) {
		if (BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 3,j) != 2 && BLACK_WHITE(i + 4,j) == 1 && BLACK_WHITE(i + 5,j) != 1)
		{
			if (BLACK_WHITE(i + 3, j) == 0)
				++q1;
		}
		if (BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 2,j) != 2 && BLACK_WHITE(i - 3,j) == 1 && BLACK_WHITE(i - 4,j) != 1)
		{
			if (BLACK_WHITE(i + 2, j) == 0)
				++q1;
		}
		if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 2,j) != 2 && BLACK_WHITE(i + 3,j) == 1 && BLACK_WHITE(i + 4,j) != 1)
		{
			if (BLACK_WHITE(i - 2, j) == 0)
				++q1;
		}
		if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 3,j) != 2 && BLACK_WHITE(i - 4,j) == 1 && BLACK_WHITE(i - 5,j) != 1)
		{
			if (BLACK_WHITE(i - 3, j) == 0)
				++q1;
		}
		if (BLACK_WHITE(i - 1,j) == 1 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i + 3,j) != 1)
		{
			if (BLACK_WHITE(i + 1, j) == 0)
				++q1;
		}
		if (BLACK_WHITE(i + 1,j) == 1 && BLACK_WHITE(i + 2,j) == 1 && BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i - 2,j) == 1 && BLACK_WHITE(i - 3,j) != 1)
		{
			if (BLACK_WHITE(i - 1, j) == 0)
				++q1;
		}
	}
	//dim2
	q2 = 0;
	if (n2 == 0) {
		if (BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i,j - 4) == 1 && BLACK_WHITE(i,j - 5) != 1)
		{
			if (BLACK_WHITE(i, j - 1) == 0)
				++q2;
		}
		if (BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i,j + 4) == 1 && BLACK_WHITE(i,j + 5) != 1)
		{
			if (BLACK_WHITE(i, j + 1) == 0)
				++q2;
		}
	}
	if (n2 == 1) {
		if (BLACK_WHITE(i,j + 1) == 1) {
			if (BLACK_WHITE(i,j + 2) != 2 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i,j + 4) == 1 && BLACK_WHITE(i,j + 5) != 1)
			{
				if (BLACK_WHITE(i, j + 2) == 0)
					++q2;
			}
			if (BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i,j - 4) != 1)
			{
				if (BLACK_WHITE(i, j - 1) == 0)
					++q2;
			}
		}
		if (BLACK_WHITE(i,j - 1) == 1) {
			if (BLACK_WHITE(i,j - 2) != 2 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i,j - 4) == 1 && BLACK_WHITE(i,j - 5) != 1)
			{
				if (BLACK_WHITE(i, j - 2) == 0)
					++q2;
			}
			if (BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i,j + 4) != 1)
			{
				if (BLACK_WHITE(i, j + 1) == 0)
					++q2;
			}
		}
	}
	if (n2 == 2) {
		if (BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 3) != 2 && BLACK_WHITE(i,j + 4) == 1 && BLACK_WHITE(i,j + 5) != 1)
		{
			if (BLACK_WHITE(i, j + 3) == 0)
				++q2;
		}
		if (BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j + 2) != 2 && BLACK_WHITE(i,j + 3) == 1 && BLACK_WHITE(i,j + 4) != 1)
		{
			if (BLACK_WHITE(i, j + 2) == 0)
				++q2;
		}
		if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j - 2) != 2 && BLACK_WHITE(i,j - 3) == 1 && BLACK_WHITE(i,j - 4) != 1)
		{
			if (BLACK_WHITE(i, j - 2) == 0)
				++q2;
		}
		if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j - 3) != 2 && BLACK_WHITE(i,j - 4) == 1 && BLACK_WHITE(i,j - 5) != 1)
		{
			if (BLACK_WHITE(i, j - 3) == 0)
				++q2;
		}
		if (BLACK_WHITE(i,j - 1) == 1 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j + 3) != 1)
		{
			if (BLACK_WHITE(i, j + 1) == 0)
				++q2;
		}
		if (BLACK_WHITE(i,j + 1) == 1 && BLACK_WHITE(i,j + 2) == 1 && BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j - 2) == 1 && BLACK_WHITE(i,j - 3) != 1)
		{
			if (BLACK_WHITE(i, j - 1) == 0)
				++q2;
		}
	}
	//dim 3
	q3 = 0;
	if (n3 == 0) {
		if (BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 4,j - 4) == 1 && BLACK_WHITE(i - 5,j - 5) != 1)
		{
			if (BLACK_WHITE(i - 1, j - 1) == 0)
				++q3;
		}
		if (BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 4,j + 4) == 1 && BLACK_WHITE(i + 5,j + 5) != 1)
		{
			if (BLACK_WHITE(i + 1, j + 1) == 0)
				++q3;
		}
	}
	if (n3 == 1) {
		if (BLACK_WHITE(i + 1,j + 1) == 1) {
			if (BLACK_WHITE(i + 2,j + 2) != 2 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 4,j + 4) == 1 && BLACK_WHITE(i + 5,j + 5) != 1)
			{
				if (BLACK_WHITE(i + 2, j + 2) == 0)
					++q3;
			}
			if (BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 4,j - 4) != 1)
			{
				if (BLACK_WHITE(i - 1, j - 1) == 0)
					++q3;
			}
		}
		if (BLACK_WHITE(i - 1,j - 1) == 1) {
			if (BLACK_WHITE(i - 2,j - 2) != 2 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 4,j - 4) == 1 && BLACK_WHITE(i - 5,j - 5) != 1)
			{
				if (BLACK_WHITE(i - 2, j - 2) == 0)
					++q3;
			}
			if (BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 4,j + 4) != 1)
			{
				if (BLACK_WHITE(i + 1, j + 1) == 0)
					++q3;
			}
		}
	}
	if (n3 == 2) {
		if (BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 3,j + 3) != 2 && BLACK_WHITE(i + 4,j + 4) == 1 && BLACK_WHITE(i + 5,j + 5) != 1)
		{
			if (BLACK_WHITE(i + 3, j + 3) == 0)
				++q3;
		}
		if (BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 2,j - 2) != 2 && BLACK_WHITE(i - 3,j - 3) == 1 && BLACK_WHITE(i - 4,j - 4) != 1)
		{
			if (BLACK_WHITE(i - 2, j - 2) == 0)
				++q3;
		}
		if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 2,j + 2) != 2 && BLACK_WHITE(i + 3,j + 3) == 1 && BLACK_WHITE(i + 4,j + 4) != 1)
		{
			if (BLACK_WHITE(i + 2, j + 2) == 0)
				++q3;
		}
		if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 3,j - 3) != 2 && BLACK_WHITE(i - 4,j - 4) == 1 && BLACK_WHITE(i - 5,j - 5) != 1)
		{
			if (BLACK_WHITE(i - 3, j - 3) == 0)
				++q3;
		}
		if (BLACK_WHITE(i - 1,j - 1) == 1 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i + 3,j + 3) != 1)
		{
			if (BLACK_WHITE(i + 1, j + 1) == 0)
				++q3;
		}
		if (BLACK_WHITE(i + 1,j + 1) == 1 && BLACK_WHITE(i + 2,j + 2) == 1 && BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i - 2,j - 2) == 1 && BLACK_WHITE(i - 3,j - 3) != 1)
		{
			if (BLACK_WHITE(i - 1, j - 1) == 0)
				++q3;
		}
	}
	//dim 4 
	q4 = 0;
	if (n4 == 0) {
		if (BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 4,j - 4) == 1 && BLACK_WHITE(i + 5,j - 5) != 1)
		{
			if (BLACK_WHITE(i + 1, j - 1) == 0)
				++q4;
		}
		if (BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 4,j + 4) == 1 && BLACK_WHITE(i - 5,j + 5) != 1)
		{
			if (BLACK_WHITE(i - 1, j + 1) == 0)
				++q4;
		}
	}
	if (n4 == 1) {
		if (BLACK_WHITE(i - 1,j + 1) == 1) {
			if (BLACK_WHITE(i - 2,j + 2) != 2 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 4,j + 4) == 1 && BLACK_WHITE(i - 5,j + 5) != 1)
			{
				if (BLACK_WHITE(i - 2, j + 2) == 0)
					++q4;
			}
			if (BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 4,j - 4) != 1)
			{
				if (BLACK_WHITE(i + 1, j - 1) == 0)
					++q4;
			}
		}
		if (BLACK_WHITE(i + 1,j - 1) == 1) {
			if (BLACK_WHITE(i + 2,j - 2) != 2 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 4,j - 4) == 1 && BLACK_WHITE(i + 5,j - 5) != 1)
			{
				if (BLACK_WHITE(i + 2, j - 2) == 0)
					++q4;
			}
			if (BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 4,j + 4) != 1)
			{
				if (BLACK_WHITE(i - 1, j + 1) == 0)
					++q4;
			}
		}
	}
	if (n4 == 2) {
		if (BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 3,j - 3) != 2 && BLACK_WHITE(i + 4,j - 4) == 1 && BLACK_WHITE(i + 5,j - 5) != 1)
		{
			if (BLACK_WHITE(i + 3, j - 3) == 0)
				++q4;
		}
		if (BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 2,j + 2) != 2 && BLACK_WHITE(i - 3,j + 3) == 1 && BLACK_WHITE(i - 4,j + 4) != 1)
		{
			if (BLACK_WHITE(i - 2, j + 2) == 0)
				++q4;
		}
		if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 2,j - 2) != 2 && BLACK_WHITE(i + 3,j - 3) == 1 && BLACK_WHITE(i + 4,j - 4) != 1)
		{
			if (BLACK_WHITE(i + 2, j - 2) == 0)
				++q4;
		}
		if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 3,j + 3) != 2 && BLACK_WHITE(i - 4,j + 4) == 1 && BLACK_WHITE(i - 5,j + 5) != 1)
		{
			if (BLACK_WHITE(i - 3, j + 3) == 0)
				++q4;
		}
		if (BLACK_WHITE(i - 1,j + 1) == 1 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i + 3,j - 3) != 1)
		{
			if (BLACK_WHITE(i + 1, j - 1) == 0)
				++q4;
		}
		if (BLACK_WHITE(i + 1,j - 1) == 1 && BLACK_WHITE(i + 2,j - 2) == 1 && BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i - 2,j + 2) == 1 && BLACK_WHITE(i - 3,j + 3) != 1)
		{
			if (BLACK_WHITE(i - 1, j + 1) == 0)
				++q4;
		}
	}
	q = q1 + q2 + q3 + q4;
	//get value
	//WULIAN
	if (n1 == 4)
		value += WULIAN;
	if (n2 == 4)
		value += WULIAN;
	if (n3 == 4)
		value += WULIAN;
	if (n4 == 4)
		value += WULIAN;
	//HUOSI
	if (n1 == 3 && b1 == 0)
		value += HUOSI;
	if (n2 == 3 && b2 == 0)
		value += HUOSI;
	if (n3 == 3 && b3 == 0)
		value += HUOSI;
	if (n4 == 3 && b4 == 0)
		value += HUOSI;
	//LIANSI
	if (n1 == 3 && b1 == 1)
		value += LIANSI;
	if (n2 == 3 && b2 == 1)
		value += LIANSI;
	if (n3 == 3 && b3 == 1)
		value += LIANSI;
	if (n4 == 3 && b4 == 1)
		value += LIANSI;
	//jump 4
	value += q * TIAOSI;
	//LIANSAN 
	if (n1 == 2 && f1 == 1)
		value += LIANHUOSAN;
	if (n2 == 2 && f2 == 1)
		value += LIANHUOSAN;
	if (n3 == 2 && f3 == 1)
		value += LIANHUOSAN;
	if (n4 == 2 && f4 == 1)
		value += LIANHUOSAN;
	//fake 3 
	if (n1 == 2 && f1 == 2)
		value += JIAHUOSAN;
	if (n2 == 2 && f2 == 2)
		value += JIAHUOSAN;
	if (n3 == 2 && f3 == 2)
		value += JIAHUOSAN;
	if (n4 == 2 && f4 == 2)
		value += JIAHUOSAN;
	//jump 3
	if (p1 > 0)
		value += TIAOHUOSAN;
	if (p2 > 0)
		value += TIAOHUOSAN;
	if (p3 > 0)
		value += TIAOHUOSAN;
	if (p4 > 0)
		value += TIAOHUOSAN;
	//MIANSAN 
	if (m1 > 0)
		value += m1*MIANSAN;
	if (m2 > 0)
		value += m2*MIANSAN;
	if (m3 > 0)
		value += m3*MIANSAN;
	if (m4 > 0)
		value += m4*MIANSAN;
	//HUOER
	if (e1 > 0)
		value += e1 * HUOER;
	if (e2 > 0)
		value += e2 * HUOER;
	if (e3 > 0)
		value += e3 * HUOER;
	if (e4 > 0)
		value += e4 * HUOER;
	//MIANER
	if (s1 > 0)
		value += s1 * MIANER;
	if (s2 > 0)
		value += s2 * MIANER;
	if (s3 > 0)
		value += s3 * MIANER;
	if (s4 > 0)
		value += s4 * MIANER;
	return value;
	}
	if (n==2)
	{
		//same as n==1
		int x, y;
		int n1, n2, n3, n4;
		int b1, b2, b3, b4; 
		int p1, p2, p3, p4; 
		int q1, q2, q3, q4, q;
		int f1, f2, f3, f4;
		int m1, m2, m3, m4;
		int e1, e2, e3, e4;
		int s1, s2, s3, s4;
		int g1, g2, g3, g4;
		int value;
		value = 0;
		x = i;
		y = j; 
		//dim 1
		n1 = 0;
		b1 = 0;
		while (BLACK_WHITE(x + 1,j) == 2) {
			++x;
			++n1;
		}
		if (BLACK_WHITE(x + 1,j) == 1 || x == 14)
			++b1;
		x = i;
		y = j;
		while (BLACK_WHITE(x - 1,j) == 2) {
			--x;
			++n1;
		}
		if (BLACK_WHITE(x - 1,j) == 1 || x == 0)
			++b1;
		x = i;
		y = j;
		//dim2
		n2 = 0;
		b2 = 0;
		while (BLACK_WHITE(i,y + 1) == 2) {
			++y;
			++n2;
		}
		if (BLACK_WHITE(i,y + 1) == 1 || y == 14)
			++b2;
		x = i;
		y = j;
		while (BLACK_WHITE(i,y - 1) == 2) {
			--y;
			++n2;
		}
		if (BLACK_WHITE(i,y - 1) == 1 || y == 0)
			++b2;
		x = i;
		y = j;
		//dim 3
		n3 = 0;
		b3 = 0;
		while (BLACK_WHITE(x + 1,y + 1) == 2) {
			++x;
			++y;
			++n3;
		}
		if (BLACK_WHITE(x + 1,y + 1) == 1 || x == 14 || y == 14)
			++b3;
		x = i;
		y = j;
		while (BLACK_WHITE(x - 1,y - 1) == 2) {
			--x;
			--y;
			++n3;
		}
		if (BLACK_WHITE(x - 1,y - 1) == 1 || x == 0 || y == 0)
			++b3;
		x = i;
		y = j;
		//dim 4
		n4 = 0;
		b4 = 0;
		while (BLACK_WHITE(x + 1,y - 1) == 2) {
			++x;
			--y;
			++n4;
		}
		if (BLACK_WHITE(x + 1,y - 1) == 1 || x == 14 || y == 0)
			++b4;
		x = i;
		y = j;
		while (BLACK_WHITE(x - 1,y + 1) == 2) {
			--x;
			++y;
			++n4;
		}
		if (BLACK_WHITE(x - 1,y + 1) == 1 || x == 0 || y == 14)
			++b4;
		x = i;
		y = j;
		//HOUER 
		//dim 1 
		e1 = 0;
		//001100 
		if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 1,j) == 2)
			++e1;
		if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 1,j) == 2)
			++e1;
		//011000 
		if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i + 1,j) == 2)
			++e1;
		if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i - 1,j) == 2)
			++e1;
		if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i - 1,j) == 2)
			++e1;
		if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i + 1,j) == 2)
			++e1;
		//001010 
		if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 2,j) == 2)
			++e1;
		if (BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2,j) == 2)
			++e1;
		if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 2,j) == 2)
			++e1;
		if (BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2,j) == 2)
			++e1;
		//010010 
		if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i + 3,j) == 2)
			++e1;
		if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i - 3,j) == 2)
			++e1;
		//dim 2 
		e2 = 0;
		//001100 
		if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i,j + 1) == 2)
			++e2;
		if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i,j - 1) == 2)
			++e2;
		//011000 
		if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i,j + 1) == 2)
			++e2;
		if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i,j - 1) == 2)
			++e2;
		if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i,j - 1) == 2)
			++e2;
		if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i,j + 1) == 2)
			++e2;
		//001010 
		if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i,j + 2) == 2)
			++e2;
		if (BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i,j - 2) == 2)
			++e2;
		if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i,j - 2) == 2)
			++e2;
		if (BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i,j + 2) == 2)
			++e2;
		//010010 
		if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i,j + 3) == 2)
			++e2;
		if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i,j - 3) == 2)
			++e2;
		//dim 3 
		e3 = 0;
		//001100 
		if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 1,j + 1) == 2)
			++e3;
		if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 1,j - 1) == 2)
			++e3;
		//011000 
		if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i + 1,j + 1) == 2)
			++e3;
		if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i - 1,j - 1) == 2)
			++e3;
		if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i - 1,j - 1) == 2)
			++e3;
		if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i + 1,j + 1) == 2)
			++e3;
		//001010 
		if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 2,j + 2) == 2)
			++e3;
		if (BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2,j - 2) == 2)
			++e3;
		if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 2,j - 2) == 2)
			++e3;
		if (BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2,j + 2) == 2)
			++e3;
		//010010 
		if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i + 3,j + 3) == 2)
			++e3;
		if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i - 3,j - 3) == 2)
			++e3;
		//dim 4 
		e4 = 0;
		//001100 
		if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 1,j - 1) == 2)
			++e4;
		if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 1,j + 1) == 2)
			++e4;
		//011000 
		if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i + 1,j - 1) == 2)
			++e4;
		if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i - 1,j + 1) == 2)
			++e4;
		if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i - 1,j + 1) == 2)
			++e4;
		if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i + 1,j - 1) == 2)
			++e4;
		//001010 

		if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 2,j - 2) == 2)
			++e4;
		if (BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2,j + 2) == 2)
			++e4;
		if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 2,j + 2) == 2)
			++e4;
		if (BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2,j - 2) == 2)
			++e4;
		//010010 
		if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i + 3,j - 3) == 2)
			++e4;
		if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i - 3,j + 3) == 2)
			++e4;
		//MIANER
		s1 = s2 = s3 = s4 = 0;
		//dim 1 
		s1 = 0;
		//211000 
		if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i + 1,j) == 2)
			++s1;
		if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 2 && BLACK_WHITE(i - 1,j) == 2)
			++s1;
		if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i - 1,j) == 2)
			++s1;
		if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 2 && BLACK_WHITE(i + 1,j) == 2)
			++s1;
		//210100 
		if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i + 2,j) == 2)
			++s1;
		if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 2 && BLACK_WHITE(i - 2,j) == 2)
			++s1;
		if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i - 2,j) == 2)
			++s1;
		if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 2 && BLACK_WHITE(i + 2,j) == 2)
			++s1;
		//210010 
		if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 4, j) == 0 && BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i + 3,j) == 2)
			++s1;
		if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 2 && BLACK_WHITE(i - 3,j) == 2)
			++s1;
		if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 4, j) == 0 && BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i - 3,j) == 2)
			++s1;
		if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 2 && BLACK_WHITE(i + 3,j) == 2)
			++s1;
		//10001 
		if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4,j) == 2)
			++s1;
		if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4,j) == 2)
			++s1;
		//2001102 
		if (BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 2)
			++s1;
		if (BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 2)
			++s1;
		if (BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 2)
			++s1;
		if (BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 2)
			++s1;
		//2010102 
		if (BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 2)
			++s1;
		if (BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 2)
			++s1;
		//dim 2 
		s2 = 0;
		//211000 
		if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j + 1) == 2)
			++s2;
		if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 2 && BLACK_WHITE(i,j - 1) == 2)
			++s2;
		if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j - 1) == 2)
			++s2;
		if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 2 && BLACK_WHITE(i,j + 1) == 2)
			++s2;
		//210100 
		if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j + 2) == 2)
			++s2;
		if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 2 && BLACK_WHITE(i,j - 2) == 2)
			++s2;
		if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j - 2) == 2)
			++s2;
		if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 2 && BLACK_WHITE(i,j + 2) == 2)
			++s2;
		//210010 
		if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 4) == 0 && BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j + 3) == 2)
			++s2;
		if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 2 && BLACK_WHITE(i,j - 3) == 2)
			++s2;
		if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 4) == 0 && BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j - 3) == 2)
			++s2;
		if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 2 && BLACK_WHITE(i,j + 3) == 2)
			++s2;
		//10001 
		if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i,j + 4) == 2)
			++s2;
		if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i,j - 4) == 2)
			++s2;
		//2001102 
		if (BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 2)
			++s1;
		if (BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 2)
			++s1;
		if (BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 2)
			++s2;
		if (BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 2)
			++s2;
		//2010102 
		if (BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 2)
			++s2;
		if (BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 2)
			++s2;
		//dim 3 
		s3 = 0;
		//211000 
		if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i + 1,j + 1) == 2)
			++s3;
		if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 2 && BLACK_WHITE(i - 1,j - 1) == 2)
			++s3;
		if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i - 1,j - 1) == 2)
			++s3;
		if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 2 && BLACK_WHITE(i + 1,j + 1) == 2)
			++s3;
		//210100 
		if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i + 2,j + 2) == 2)
			++s3;
		if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 2 && BLACK_WHITE(i - 2,j - 2) == 2)
			++s3;
		if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i - 2,j - 2) == 2)
			++s3;
		if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 2 && BLACK_WHITE(i + 2,j + 2) == 2)
			++s3;
		//210010 
		if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 4, j + 4) == 0 && BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i + 3,j + 3) == 2)
			++s3;
		if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 2 && BLACK_WHITE(i - 3,j - 3) == 2)
			++s3;
		if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 4, j - 4) == 0 && BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i - 3,j - 3) == 2)
			++s3;
		if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 2 && BLACK_WHITE(i + 3,j + 3) == 2)
			++s3;
		//10001 
		if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4,j + 4) == 2)
			++s3;
		if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4,j - 4) == 2)
			++s3;
		//2001102 
		if (BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 2)
			++s3;
		if (BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 2)
			++s3;
		if (BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 2)
			++s3;
		if (BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 2)
			++s3;
		//2010102 
		if (BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 2)
			++s3;
		if (BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 2)
			++s3;
		//dim 4 
		s4 = 0;
		//211000 
		if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i + 1,j - 1) == 2)
			++s4;
		if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 2 && BLACK_WHITE(i - 1,j + 1) == 2)
			++s4;
		if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i - 1,j + 1) == 2)
			++s4;
		if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 2 && BLACK_WHITE(i + 1,j - 1) == 2)
			++s4;
		//210100 
		if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i + 2,j - 2) == 2)
			++s4;
		if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 2 && BLACK_WHITE(i - 2,j + 2) == 2)
			++s4;
		if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i - 2,j + 2) == 2)
			++s4;
		if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 2 && BLACK_WHITE(i + 2,j - 2) == 2)
			++s4;
		//210010 
		if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 4, j - 4) == 0 && BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i + 3,j - 3) == 2)
			++s4;
		if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 2 && BLACK_WHITE(i - 3,j + 3) == 2)
			++s4;
		if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 4, j + 4) == 0 && BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i - 3,j + 3) == 2)
			++s4;
		if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 2 && BLACK_WHITE(i + 3,j - 3) == 2)
			++s4;
		//10001 
		if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4,j - 4) == 2)
			++s4;
		if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4,j + 4) == 2)
			++s4;
		//2001102 
		if (BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 2)
			++s4;
		if (BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 2)
			++s4;
		if (BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 2)
			++s4;
		if (BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 2)
			++s4;
		//2010102 
		if (BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 2)
			++s4;
		if (BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 2)
			++s4;
		//jump 3 
		p1 = 0;
		if (b1 == 0) {
			if (n1 == 0) {
				if (BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 4,j) != 1 && BLACK_WHITE(i - 4,j) != 2 && i != 3 && BLACK_WHITE(i - 4, j) == 0)
					++p1;
				if (BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 4,j) != 1 && BLACK_WHITE(i + 4,j) != 2 && i != 11 && BLACK_WHITE(i + 4, j) == 0)
					++p1;
			}
			if (n1 == 1) {
				if (BLACK_WHITE(i - 1,j) == 2) {
					if (BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 4,j) != 1 && BLACK_WHITE(i - 4,j) != 2 && i != 3 && BLACK_WHITE(i - 4, j) == 0)
						++p1;
					if (BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 3,j) != 1 && BLACK_WHITE(i + 3,j) != 2 && i != 12 && BLACK_WHITE(i + 3, j) == 0)
						++p1;
				}
				if (BLACK_WHITE(i + 1,j) == 2) {
					if (BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 4,j) != 1 && BLACK_WHITE(i + 4,j) != 2 && i != 11 && BLACK_WHITE(i + 4, j) == 0)
						++p1;
					if (BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 3,j) != 1 && BLACK_WHITE(i - 3,j) != 2 && i != 2 && BLACK_WHITE(i - 3, j) == 0)
						++p1;
				}
			}
		}
		p2 = 0;
		if (b2 == 0) {
			if (n2 == 0) {
				if (BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i,j - 4) != 1 && BLACK_WHITE(i,j - 4) != 2 && i != 3 && BLACK_WHITE(i, j - 4) == 0)
					++p2;
				if (BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i,j + 4) != 1 && BLACK_WHITE(i,j + 4) != 2 && i != 11 && BLACK_WHITE(i, j + 4) == 0)
					++p2;
			}
			if (n2 == 1) {
				if (BLACK_WHITE(i,j - 1) == 2) {
					if (BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i,j - 4) != 1 && BLACK_WHITE(i,j - 4) != 2 && i != 3 && BLACK_WHITE(i, j - 4) == 0)
						++p2;
					if (BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 3) != 1 && BLACK_WHITE(i,j + 3) != 2 && i != 12 && BLACK_WHITE(i, j + 3) == 0)
						++p2;
				}
				if (BLACK_WHITE(i,j + 1) == 2) {
					if (BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i,j + 4) != 1 && BLACK_WHITE(i,j + 4) != 2 && i != 11 && BLACK_WHITE(i, j + 4) == 0)
						++p2;
					if (BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j - 3) != 1 && BLACK_WHITE(i,j - 3) != 2 && i != 2 && BLACK_WHITE(i, j - 3) == 0)
						++p2;
				}
			}
		}
		p3 = 0;
		if (b3 == 0) {
			if (n3 == 0) {
				if (BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 4,j - 4) != 1 && BLACK_WHITE(i - 4,j - 4) != 2 && i != 3 && j != 3 && BLACK_WHITE(i - 4, j - 4) == 0)
					++p3;
				if (BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 4,j + 4) != 1 && BLACK_WHITE(i + 4,j + 4) != 2 && i != 11 && j != 11 && BLACK_WHITE(i + 4, j + 4) == 0)
					++p3;
			}
			if (n3 == 1) {
				if (BLACK_WHITE(i - 1,j - 1) == 2) {
					if (BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 4,j - 4) != 1 && BLACK_WHITE(i - 4,j - 4) != 2 && i != 3 && j != 3 && BLACK_WHITE(i - 4, j - 4) == 0)
						++p3;
					if (BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 3,j + 3) != 1 && BLACK_WHITE(i + 3,j + 3) != 2 && i != 12 && j != 12 && BLACK_WHITE(i + 3, j + 3) == 0)
						++p3;
				}
				if (BLACK_WHITE(i + 1,j + 1) == 2) {
					if (BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 4,j + 4) != 1 && BLACK_WHITE(i + 4,j + 4) != 2 && i != 11 && j != 11 && BLACK_WHITE(i + 4, j + 4) == 0)
						++p3;
					if (BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 3,j - 3) != 1 && BLACK_WHITE(i - 3,j - 3) != 2 && i != 2 && j != 2 && BLACK_WHITE(i - 3, j - 3) == 0)
						++p3;
				}
			}
		}
		p4 = 0;
		if (b4 == 0) {
			if (n4 == 0) {
				if (BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 4,j + 4) != 1 && BLACK_WHITE(i - 4,j + 4) != 2 && i != 3 && j != 11 && BLACK_WHITE(i - 4, j + 4) == 0)
					++p4;
				if (BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 4,j - 4) != 1 && BLACK_WHITE(i + 4,j - 4) != 2 && i != 11 && j != 3 && BLACK_WHITE(i + 4, j - 4) == 0)
					++p4;
			}
			if (n4 == 1) {
				if (BLACK_WHITE(i - 1,j + 1) == 2) {
					if (BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 4,j + 4) != 1 && BLACK_WHITE(i - 4,j + 4) != 2 && i != 3 && j != 11 && BLACK_WHITE(i - 4, j + 4) == 0)
						++p4;
					if (BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 3,j - 3) != 1 && BLACK_WHITE(i + 3,j - 3) != 2 && i != 12 && j != 2 && BLACK_WHITE(i + 3, j - 3) == 0)
						++p4;
				}
				if (BLACK_WHITE(i + 1,j - 1) == 2) {
					if (BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 4,j - 4) != 1 && BLACK_WHITE(i + 4,j - 4) != 2 && i != 11 && j != 3 && BLACK_WHITE(i + 4, j - 4) == 0)
						++p4;
					if (BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 3,j + 3) != 1 && BLACK_WHITE(i - 3,j + 3) != 2 && i != 2 && j != 12 && BLACK_WHITE(i - 3, j + 3) == 0)
						++p4;
				}
			}
		}
		//fake
		f1 = 0;
		if (n1 == 2 && b1 == 0) {
			if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 1,j) == 2 && (BLACK_WHITE(i - 3,j) == 1 || i == 2) && (BLACK_WHITE(i + 3,j) == 1 || i == 12))
				f1 = 2;
			else if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 2,j) == 2 && (BLACK_WHITE(i - 4,j) == 1 || i == 3) && (BLACK_WHITE(i + 2,j) == 1 || i == 13))
				f1 = 2;
			else if (BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 2,j) == 2 && (BLACK_WHITE(i - 2,j) == 1 || i == 1) && (BLACK_WHITE(i + 4,j) == 1 || i == 11))
				f1 = 2;
			else if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i - 3,j) != 2 && BLACK_WHITE(i + 3,j) != 2)
				f1 = 1;
			else if (BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i - 2,j) != 2 && BLACK_WHITE(i + 4,j) != 2)
				f1 = 1;
			else if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i + 2,j) != 2 && BLACK_WHITE(i - 4,j) != 2)
				f1 = 1;
		}
		f2 = 0;
		if (n2 == 2 && b2 == 0) {
			if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j + 1) == 2 && (BLACK_WHITE(i,j - 3) == 1 || j == 2) && (BLACK_WHITE(i,j + 3) == 1 || j == 12))
				f2 = 2;
			else if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j - 2) == 2 && (BLACK_WHITE(i,j - 4) == 1 || j == 3) && (BLACK_WHITE(i,j + 2) == 1 || j == 13))
				f2 = 2;
			else if (BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j + 2) == 2 && (BLACK_WHITE(i,j - 2) == 1 || j == 1) && (BLACK_WHITE(i,j + 4) == 1 || j == 11))
				f2 = 2;
			else if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j - 3) != 2 && BLACK_WHITE(i,j + 3) != 2)
				f2 = 1;
			else if (BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j - 2) != 2 && BLACK_WHITE(i,j + 4) != 2)
				f2 = 1;
			else if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j + 2) != 2 && BLACK_WHITE(i,j - 4) != 2)
				f2 = 1;
		}
		f3 = 0;
		if (n3 == 2 && b3 == 0) {
			if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 1,j + 1) == 2 && (BLACK_WHITE(i - 3,j - 3) == 1 || i == 2 || j == 2) && (BLACK_WHITE(i + 3,j + 3) == 1 || i == 12 || j == 12))
				f3 = 2;
			else if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 2,j - 2) == 2 && (BLACK_WHITE(i - 4,j - 4) == 1 || i == 3 || j == 3) && (BLACK_WHITE(i + 2,j + 2) == 1 || i == 13 || j == 13))
				f3 = 2;
			else if (BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 2,j + 2) == 2 && (BLACK_WHITE(i - 2,j - 2) == 1 || i == 1 || j == 1) && (BLACK_WHITE(i + 4,j + 4) == 1 || i == 11 || j == 11))
				f3 = 2;
			else if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i - 3,j - 3) != 2 && BLACK_WHITE(i + 3,j + 3) != 2)
				f3 = 1;
			else if (BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i - 2,j - 2) != 2 && BLACK_WHITE(i + 4,j + 4) != 2)
				f3 = 1;
			else if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i + 2,j + 2) != 2 && BLACK_WHITE(i - 4,j - 4) != 2)
				f3 = 1;
		}
		f4 = 0;
		if (n4 == 2 && b4 == 0) {
			if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 1,j - 1) == 2 && (BLACK_WHITE(i - 3,j + 3) == 1 || i == 2 || j == 12) && (BLACK_WHITE(i + 3,j - 3) == 1 || i == 12 || j == 2))
				f4 = 2;
			else if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 2,j + 2) == 2 && (BLACK_WHITE(i - 4,j + 4) == 1 || i == 3 || j == 11) && (BLACK_WHITE(i + 2,j - 2) == 1 || i == 13 || j == 1))
				f4 = 2;
			else if (BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 2,j - 2) == 2 && (BLACK_WHITE(i - 2,j + 2) == 1 || i == 1 || j == 13) && (BLACK_WHITE(i + 4,j - 3) == 1 || i == 11 || j == 3))
				f4 = 2;
			else if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i - 3,j + 3) != 2 && BLACK_WHITE(i + 3,j - 3) != 2)
				f4 = 1;
			else if (BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i - 2,j + 2) != 2 && BLACK_WHITE(i + 4,j - 4) != 2)
				f4 = 1;
			else if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i + 2,j - 2) != 2 && BLACK_WHITE(i - 4,j + 4) != 2)
				f4 = 1;
		}
		//MIANSAN
		//dim 1 
		m1 = 0;
		//211100 
		if (BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 3, j) == 0 && BLACK_WHITE(i + 4, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 3, j) == 0 && BLACK_WHITE(i - 4, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0)
			++m1;
		//211010 
		if (BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 4, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 2, j) != 0 && BLACK_WHITE(i - 2,j) != 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 4, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 2, j) != 0 && BLACK_WHITE(i + 2,j) != 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 1, j) == 0)
			++m1;
		//210110 
		if (BLACK_WHITE(i - 1, j) != 0 && BLACK_WHITE(i - 1,j) != 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 4, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 3, j) != 0 && BLACK_WHITE(i - 3,j) != 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 4, j) != 0 && BLACK_WHITE(i - 4,j) != 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 1, j) != 0 && BLACK_WHITE(i + 1,j) != 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 4, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 3, j) != 0 && BLACK_WHITE(i + 3,j) != 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 4, j) != 0 && BLACK_WHITE(i + 4,j) != 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0)
			++m1;
		//11001 
		if (BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 4,j) == 2 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 3, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 2, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 4,j) == 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 1, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 4,j) == 2 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i - 3, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 2, j) == 0)
			++m1;
		if (BLACK_WHITE(i + 4,j) == 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 2, j) == 0 && BLACK_WHITE(i + 1, j) == 0)
			++m1;
		//10101 
		if (BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 4,j) == 2 && BLACK_WHITE(i + 1, j) == 0 && BLACK_WHITE(i + 3, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i + 1, j) == 0)
			++m1;
		if (BLACK_WHITE(i - 4,j) == 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 1, j) == 0 && BLACK_WHITE(i - 3, j) == 0)
			++m1;
		//dim 2 
		m2 = 0;
		//211100 
		if (BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i, j + 3) == 0 && BLACK_WHITE(i, j + 4) == 0)
			++m2;
		if (BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0)
			++m2;
		if (BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i, j - 3) == 0 && BLACK_WHITE(i, j - 4) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 3) == 0)
			++m2;
		//211010 
		if (BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 4) == 0)
			++m2;
		if (BLACK_WHITE(i, j - 2) != 0 && BLACK_WHITE(i,j - 2) != 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0)
			++m2;
		if (BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 4) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 2) != 0 && BLACK_WHITE(i,j + 2) != 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 1) == 0)
			++m2;
		//210110 
		if (BLACK_WHITE(i, j - 1) != 0 && BLACK_WHITE(i,j - 1) != 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 4) == 0)
			++m2;
		if (BLACK_WHITE(i, j - 3) != 0 && BLACK_WHITE(i,j - 3) != 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 2) == 0)
			++m2;
		if (BLACK_WHITE(i, j - 4) != 0 && BLACK_WHITE(i,j - 4) != 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j + 1) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 1) != 0 && BLACK_WHITE(i,j + 1) != 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 4) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 3) != 0 && BLACK_WHITE(i,j + 3) != 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j - 2) == 0)
			++m2;
		if (BLACK_WHITE(i, j + 4) != 0 && BLACK_WHITE(i,j + 4) != 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j - 1) == 0)
			++m2;
		//11001 
		if (BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j + 4) == 2 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 3) == 0)
			++m2;
		if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 2) == 0)
			++m2;
		if (BLACK_WHITE(i,j - 4) == 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i, j - 2) == 0 && BLACK_WHITE(i, j - 1) == 0)
			++m2;
		if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j - 4) == 2 && BLACK_WHITE(i - 2, j) == 0 && BLACK_WHITE(i, j - 3) == 0)
			++m2;
		if (BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 2) == 0)
			++m2;
		if (BLACK_WHITE(i,j + 4) == 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i, j + 2) == 0 && BLACK_WHITE(i, j + 1) == 0)
			++m2;
		//10101 
		if (BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 4) == 2 && BLACK_WHITE(i, j + 1) == 0 && BLACK_WHITE(i, j + 3) == 0)
			++m2;
		if (BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j + 1) == 0)
			++m2;
		if (BLACK_WHITE(i,j - 4) == 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i, j - 1) == 0 && BLACK_WHITE(i, j - 3) == 0)
			++m2;
		//dim 3 
		m3 = 0;
		//211100 
		if (BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 3, j + 3) == 0 && BLACK_WHITE(i + 4, j + 4) == 0)
			++m3;
		if (BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0)
			++m3;
		if (BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0)
			++m3;
		if (BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0)
			++m3;
		if (BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 3, j - 3) == 0 && BLACK_WHITE(i - 4, j - 4) == 0)
			++m3;
		if (BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0)
			++m3;
		//211010 
		if (BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 4, j + 4) == 0)
			++m3;
		if (BLACK_WHITE(i - 2, j - 2) != 0 && BLACK_WHITE(i - 2,j - 2) != 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0)
			++m3;
		if (BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0)
			++m3;
		if (BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 4, j - 4) == 0)
			++m3;
		if (BLACK_WHITE(i + 2, j + 2) != 0 && BLACK_WHITE(i + 2,j + 2) != 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0)
			++m3;
		if (BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 1, j - 1) == 0)
			++m3;
		//210110 
		if (BLACK_WHITE(i - 1, j - 1) != 0 && BLACK_WHITE(i - 1,j - 1) != 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 4, j + 4) == 0)
			++m3;
		if (BLACK_WHITE(i - 3, j - 3) != 0 && BLACK_WHITE(i - 3,j - 3) != 2 && BLACK_WHITE(i - 2,j - 3) == 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0)
			++m3;
		if (BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i - 4,j - 4) != 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0)
			++m3;
		if (BLACK_WHITE(i + 1, j + 1) != 0 && BLACK_WHITE(i + 1,j + 1) != 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 4, j - 4) == 0)
			++m3;
		if (BLACK_WHITE(i + 3, j + 3) != 0 && BLACK_WHITE(i + 3,j + 3) != 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0)
			++m3;
		if (BLACK_WHITE(i + 4, j + 4) != 0 && BLACK_WHITE(i + 4,j + 4) != 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0)
			++m3;
		//11001 
		if (BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 4,j + 4) == 2 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 3, j + 3) == 0)
			++m3;
		if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 2, j + 2) == 0)
			++m3;
		if (BLACK_WHITE(i - 4,j - 4) == 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 1, j - 1) == 0)
			++m3;
		if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 4,j - 4) == 2 && BLACK_WHITE(i - 2, j - 2) == 0 && BLACK_WHITE(i - 3, j - 3) == 0)
			++m3;
		if (BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 2, j - 2) == 0)
			++m3;
		if (BLACK_WHITE(i + 4,j + 4) == 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 2, j + 2) == 0 && BLACK_WHITE(i + 1, j + 1) == 0)
			++m3;
		//10101 
		if (BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 4,j + 4) == 2 && BLACK_WHITE(i + 1, j + 1) == 0 && BLACK_WHITE(i + 3, j + 3) == 0)
			++m3;
		if (BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i + 1, j + 1) == 0)
			++m3;
		if (BLACK_WHITE(i - 4,j - 4) == 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 1, j - 1) == 0 && BLACK_WHITE(i - 3, j - 3) == 0)
			++m3;
		//dim 4 
		m4 = 0;
		//211100 
		if (BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 3, j - 3) == 0 && BLACK_WHITE(i + 4, j - 4) == 0)
			++m4;
		if (BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0)
			++m4;
		if (BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0)
			++m4;
		if (BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0)
			++m4;
		if (BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 3, j + 3) == 0 && BLACK_WHITE(i - 4, j + 4) == 0)
			++m4;
		if (BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0)
			++m4;
		//211010 
		if (BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 4, j - 4) == 0)
			++m4;
		if (BLACK_WHITE(i - 2, j + 2) != 0 && BLACK_WHITE(i - 2,j + 2) != 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0)
			++m4;
		if (BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0)
			++m4;
		if (BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 4, j + 4) == 0)
			++m4;
		if (BLACK_WHITE(i + 2, j - 2) != 0 && BLACK_WHITE(i + 2,j - 2) != 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0)
			++m4;
		if (BLACK_WHITE(i + 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 1, j + 1) == 0)
			++m4;
		//210110 
		if (BLACK_WHITE(i - 1, j + 1) != 0 && BLACK_WHITE(i - 1,j + 1) != 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 4, j - 4) == 0)
			++m4;
		if (BLACK_WHITE(i - 3, j + 3) != 0 && BLACK_WHITE(i - 3,j + 3) != 2 && BLACK_WHITE(i - 2,j + 3) == 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0)
			++m4;
		if (BLACK_WHITE(i - 4, j + 4) != 0 && BLACK_WHITE(i - 4,j + 4) != 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0)
			++m4;
		if (BLACK_WHITE(i + 1, j - 1) != 0 && BLACK_WHITE(i + 1,j - 1) != 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 4, j + 4) == 0)
			++m4;
		if (BLACK_WHITE(i + 3, j - 3) != 0 && BLACK_WHITE(i + 3,j - 3) != 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0)
			++m4;
		if (BLACK_WHITE(i - 4, j - 4) != 0 && BLACK_WHITE(i + 4,j - 4) != 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0)
			++m4;
		//11001 
		if (BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 4,j - 4) == 2 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 3, j - 3) == 0)
			++m4;
		if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 2, j - 2) == 0)
			++m4;
		if (BLACK_WHITE(i - 4,j + 4) == 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 1, j + 1) == 0)
			++m4;
		if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 4,j + 4) == 2 && BLACK_WHITE(i - 2, j + 2) == 0 && BLACK_WHITE(i - 3, j + 3) == 0)
			++m4;
		if (BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 2, j + 2) == 0)
			++m4;
		if (BLACK_WHITE(i + 4,j - 4) == 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 2, j - 2) == 0 && BLACK_WHITE(i + 1, j - 1) == 0)
			++m4;
		//10101 
		if (BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 4,j - 4) == 2 && BLACK_WHITE(i + 1, j - 1) == 0 && BLACK_WHITE(i + 3, j - 3) == 0)
			++m4;
		if (BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i + 1, j - 1) == 0)
			++m4;
		if (BLACK_WHITE(i - 4,j + 4) == 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 1, j + 1) == 0 && BLACK_WHITE(i - 3, j + 3) == 0)
			++m4;
		//jump 4
		q = 0;
		//dim 1 
		q1 = 0;
		if (n1 == 0) {
			if (BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 4,j) == 2 && BLACK_WHITE(i - 5,j) != 2)
			{
				if (BLACK_WHITE(i - 1, j) == 0)
					++q1;
			}
			if (BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 4,j) == 2 && BLACK_WHITE(i + 5,j) != 2)
			{
				if (BLACK_WHITE(i + 1, j) == 0)
					++q1;
			}
		}
		if (n1 == 1) {
			if (BLACK_WHITE(i + 1,j) == 2) {
				if (BLACK_WHITE(i + 2,j) != 1 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 4,j) == 2 && BLACK_WHITE(i + 5,j) != 2)
				{
					if (BLACK_WHITE(i + 2, j) == 0)
						++q1;
				}
				if (BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 4,j) != 2)
				{
					if (BLACK_WHITE(i - 1, j) == 0)
						++q1;
				}
			}
			if (BLACK_WHITE(i - 1,j) == 2) {
				if (BLACK_WHITE(i - 2,j) != 1 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 4,j) == 2 && BLACK_WHITE(i - 5,j) != 2)
				{
					if (BLACK_WHITE(i - 2, j) == 0)
						++q1;
				}
				if (BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 4,j) != 2)
				{
					if (BLACK_WHITE(i + 1, j) == 0)
						++q1;
				}
			}
		}
		if (n1 == 2) {
			if (BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 3,j) != 1 && BLACK_WHITE(i + 4,j) == 2 && BLACK_WHITE(i + 5,j) != 2)
			{
				if (BLACK_WHITE(i + 3, j) == 0)
					++q1;
			}
			if (BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 2,j) != 1 && BLACK_WHITE(i - 3,j) == 2 && BLACK_WHITE(i - 4,j) != 2)
			{
				if (BLACK_WHITE(i + 2, j) == 0)
					++q1;
			}
			if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 2,j) != 1 && BLACK_WHITE(i + 3,j) == 2 && BLACK_WHITE(i + 4,j) != 2)
			{
				if (BLACK_WHITE(i - 2, j) == 0)
					++q1;
			}
			if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 3,j) != 1 && BLACK_WHITE(i - 4,j) == 2 && BLACK_WHITE(i - 5,j) != 2)
			{
				if (BLACK_WHITE(i - 3, j) == 0)
					++q1;
			}
			if (BLACK_WHITE(i - 1,j) == 2 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i + 1,j) != 1 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i + 3,j) != 2)
			{
				if (BLACK_WHITE(i + 1, j) == 0)
					++q1;
			}
			if (BLACK_WHITE(i + 1,j) == 2 && BLACK_WHITE(i + 2,j) == 2 && BLACK_WHITE(i - 1,j) != 1 && BLACK_WHITE(i - 2,j) == 2 && BLACK_WHITE(i - 3,j) != 2)
			{
				if (BLACK_WHITE(i - 1, j) == 0)
					++q1;
			}
		}
		//dim 2 
		q2 = 0;
		if (n2 == 0) {
			if (BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i,j - 4) == 2 && BLACK_WHITE(i,j - 5) != 2)
			{
				if (BLACK_WHITE(i, j - 1) == 0)
					++q2;
			}
			if (BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i,j + 4) == 2 && BLACK_WHITE(i,j + 5) != 2)
			{
				if (BLACK_WHITE(i, j + 1) == 0)
					++q2;
			}
		}
		if (n2 == 1) {
			if (BLACK_WHITE(i,j + 1) == 2) {
				if (BLACK_WHITE(i,j + 2) != 1 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i,j + 4) == 2 && BLACK_WHITE(i,j + 5) != 2)
				{
					if (BLACK_WHITE(i, j + 2) == 0)
						++q2;
				}
				if (BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i,j - 4) != 2)
				{
					if (BLACK_WHITE(i, j - 1) == 0)
						++q2;
				}
			}
			if (BLACK_WHITE(i,j - 1) == 2) {
				if (BLACK_WHITE(i,j - 2) != 1 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i,j - 4) == 2 && BLACK_WHITE(i,j - 5) != 2)
				{
					if (BLACK_WHITE(i, j - 2) == 0)
						++q2;
				}
				if (BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i,j + 4) != 2)
				{
					if (BLACK_WHITE(i, j + 1) == 0)
						++q2;
				}
			}
		}
		if (n2 == 2) {
			if (BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 3) != 1 && BLACK_WHITE(i,j + 4) == 2 && BLACK_WHITE(i,j + 5) != 2)
			{
				if (BLACK_WHITE(i, j + 3) == 0)
					++q2;
			}
			if (BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j + 2) != 1 && BLACK_WHITE(i,j + 3) == 2 && BLACK_WHITE(i,j + 4) != 2)
			{
				if (BLACK_WHITE(i, j + 2) == 0)
					++q2;
			}
			if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j - 2) != 1 && BLACK_WHITE(i,j - 3) == 2 && BLACK_WHITE(i,j - 4) != 2)
			{
				if (BLACK_WHITE(i, j - 2) == 0)
					++q2;
			}
			if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j - 3) != 1 && BLACK_WHITE(i,j - 4) == 2 && BLACK_WHITE(i,j - 5) != 2)
			{
				if (BLACK_WHITE(i, j - 3) == 0)
					++q2;
			}
			if (BLACK_WHITE(i,j - 1) == 2 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j + 1) != 1 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j + 3) != 2)
			{
				if (BLACK_WHITE(i, j + 1) == 0)
					++q2;
			}
			if (BLACK_WHITE(i,j + 1) == 2 && BLACK_WHITE(i,j + 2) == 2 && BLACK_WHITE(i,j - 1) != 1 && BLACK_WHITE(i,j - 2) == 2 && BLACK_WHITE(i,j - 3) != 2)
			{
				if (BLACK_WHITE(i, j - 1) == 0)
					++q2;
			}
		}
		//dim 4 
		q3 = 0;
		if (n3 == 0) {
			if (BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 4,j - 4) == 2 && BLACK_WHITE(i - 5,j - 5) != 2)
			{
				if (BLACK_WHITE(i - 1, j - 1) == 0)
					++q3;
			}
			if (BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 4,j + 4) == 2 && BLACK_WHITE(i + 5,j + 5) != 2)
			{
				if (BLACK_WHITE(i + 1, j + 1) == 0)
					++q3;
			}
		}
		if (n3 == 1) {
			if (BLACK_WHITE(i + 1,j + 1) == 2) {
				if (BLACK_WHITE(i + 2,j + 2) != 1 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 4,j + 4) == 2 && BLACK_WHITE(i + 5,j + 5) != 2)
				{
					if (BLACK_WHITE(i + 2, j + 2) == 0)
						++q3;
				}
				if (BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 4,j - 4) != 2)
				{
					if (BLACK_WHITE(i - 1, j - 1) == 0)
						++q3;
				}
			}
			if (BLACK_WHITE(i - 1,j - 1) == 2) {
				if (BLACK_WHITE(i - 2,j - 2) != 1 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 4,j - 4) == 2 && BLACK_WHITE(i - 5,j - 5) != 2)
				{
					if (BLACK_WHITE(i - 2, j - 2) == 0)
						++q3;
				}
				if (BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 4,j + 4) != 2)
				{
					if (BLACK_WHITE(i + 1, j + 1) == 0)
						++q3;
				}
			}
		}
		if (n3 == 2) {
			if (BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 3,j + 3) != 1 && BLACK_WHITE(i + 4,j + 4) == 2 && BLACK_WHITE(i + 5,j + 5) != 2)
			{
				if (BLACK_WHITE(i + 3, j + 3) == 0)
					++q3;
			}
			if (BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 2,j - 2) != 1 && BLACK_WHITE(i - 3,j - 3) == 2 && BLACK_WHITE(i - 4,j - 4) != 2)
			{
				if (BLACK_WHITE(i - 2, j - 2) == 0)
					++q3;
			}
			if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 2,j + 2) != 1 && BLACK_WHITE(i + 3,j + 3) == 2 && BLACK_WHITE(i + 4,j + 4) != 2)
			{
				if (BLACK_WHITE(i + 2, j + 2) == 0)
					++q3;
			}
			if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 3,j - 3) != 1 && BLACK_WHITE(i - 4,j - 4) == 2 && BLACK_WHITE(i - 5,j - 5) != 2)
			{
				if (BLACK_WHITE(i - 3, j - 3) == 0)
					++q3;
			}
			if (BLACK_WHITE(i - 1,j - 1) == 2 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i + 1,j + 1) != 1 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i + 3,j + 3) != 2)
			{
				if (BLACK_WHITE(i + 1, j + 1) == 0)
					++q3;
			}
			if (BLACK_WHITE(i + 1,j + 1) == 2 && BLACK_WHITE(i + 2,j + 2) == 2 && BLACK_WHITE(i - 1,j - 1) != 1 && BLACK_WHITE(i - 2,j - 2) == 2 && BLACK_WHITE(i - 3,j - 3) != 2)
			{
				if (BLACK_WHITE(i - 1, j - 1) == 0)
					++q3;
			}
		}
		//dim 3 
		q4 = 0;
		if (n4 == 0) {
			if (BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 4,j - 4) == 2 && BLACK_WHITE(i + 5,j - 5) != 2)
			{
				if (BLACK_WHITE(i + 1, j - 1) == 0)
					++q4;
			}
			if (BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 4,j + 4) == 2 && BLACK_WHITE(i - 5,j + 5) != 2)
			{
				if (BLACK_WHITE(i - 1, j + 1) == 0)
					++q4;
			}
		}
		if (n4 == 1) {
			if (BLACK_WHITE(i - 1,j + 1) == 2) {
				if (BLACK_WHITE(i - 2,j + 2) != 1 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 4,j + 4) == 2 && BLACK_WHITE(i - 5,j + 5) != 2)
				{
					if (BLACK_WHITE(i - 2, j + 2) == 0)
						++q4;
				}
				if (BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 4,j - 4) != 2)
				{
					if (BLACK_WHITE(i + 1, j - 1) == 0)
						++q4;
				}
			}
			if (BLACK_WHITE(i + 1,j - 1) == 2) {
				if (BLACK_WHITE(i + 2,j - 2) != 1 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 4,j - 4) == 2 && BLACK_WHITE(i + 5,j - 5) != 2)
				{
					if (BLACK_WHITE(i + 2, j - 2) == 0)
						++q4;
				}
				if (BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 4,j + 4) != 2)
				{
					if (BLACK_WHITE(i - 1, j + 1) == 0)
						++q4;
				}
			}
		}
		if (n4 == 2) {
			if (BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 3,j - 3) != 1 && BLACK_WHITE(i + 4,j - 4) == 2 && BLACK_WHITE(i + 5,j - 5) != 2)
			{
				if (BLACK_WHITE(i + 3, j - 3) == 0)
					++q4;
			}
			if (BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 2,j + 2) != 1 && BLACK_WHITE(i - 3,j + 3) == 2 && BLACK_WHITE(i - 4,j + 4) != 2)
			{
				if (BLACK_WHITE(i - 2, j + 2) == 0)
					++q4;
			}
			if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 2,j - 2) != 1 && BLACK_WHITE(i + 3,j - 3) == 2 && BLACK_WHITE(i + 4,j - 4) != 2)
			{
				if (BLACK_WHITE(i + 2, j - 2) == 0)
					++q4;
			}
			if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 3,j + 3) != 1 && BLACK_WHITE(i - 4,j + 4) == 2 && BLACK_WHITE(i - 5,j + 5) != 2)
			{
				if (BLACK_WHITE(i - 3, j + 3) == 0)
					++q4;
			}
			if (BLACK_WHITE(i - 1,j + 1) == 2 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i + 1,j - 1) != 1 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i + 3,j - 3) != 2)
			{
				if (BLACK_WHITE(i + 1, j - 1) == 0)
					++q4;
			}
			if (BLACK_WHITE(i + 1,j - 1) == 2 && BLACK_WHITE(i + 2,j - 2) == 2 && BLACK_WHITE(i - 1,j + 1) != 1 && BLACK_WHITE(i - 2,j + 2) == 2 && BLACK_WHITE(i - 3,j + 3) != 2)
			{
				if (BLACK_WHITE(i - 1, j + 1) == 0)
					++q4;
			}
		}
		q = q1 + q2 + q3 + q4;
		//value 
		//5 
		if (n1 >= 4)
			value += WULIAN;
		if (n2 >= 4)
			value += WULIAN;
		if (n3 >= 4)
			value += WULIAN;
		if (n4 >= 4)
			value += WULIAN;
		//HUOSI
		if (n1 == 3 && b1 == 0)
			value += HUOSI;
		if (n2 == 3 && b2 == 0)
			value += HUOSI;
		if (n3 == 3 && b3 == 0)
			value += HUOSI;
		if (n4 == 3 && b4 == 0)
			value += HUOSI;
		//LIANSI
		if (n1 == 3 && b1 == 1)
			value += LIANSI;
		if (n2 == 3 && b2 == 1)
			value += LIANSI;
		if (n3 == 3 && b3 == 1)
			value += LIANSI;
		if (n4 == 3 && b4 == 1)
			value += LIANSI;
		//JUMP 4 
		value += q * TIAOSI;
		//LIANHUOSAN
		if (n1 == 2 && f1 == 1)
			value += LIANHUOSAN;
		if (n2 == 2 && f2 == 1)
			value += LIANHUOSAN;
		if (n3 == 2 && f3 == 1)
			value += LIANHUOSAN;
		if (n4 == 2 && f4 == 1)
			value += LIANHUOSAN;
		//JIAHUOSAN
		if (n1 == 2 && f1 == 2)
			value += JIAHUOSAN;
		if (n2 == 2 && f2 == 2)
			value += JIAHUOSAN;
		if (n3 == 2 && f3 == 2)
			value += JIAHUOSAN;
		if (n4 == 2 && f4 == 2)
			value += JIAHUOSAN;
		//JUMP 3
		if (p1 > 0)
			value += TIAOHUOSAN;
		if (p2 > 0)
			value += TIAOHUOSAN;
		if (p3 > 0)
			value += TIAOHUOSAN;
		if (p4 > 0)
			value += TIAOHUOSAN;
		//MIANSAN 
		if (m1 > 0)
			value += m1 * MIANSAN;
		if (m2 > 0)
			value += m2 * MIANSAN;
		if (m3 > 0)
			value += m3 * MIANSAN;
		if (m4 > 0)
			value += m4 * MIANSAN;
		//HUOER
		if (e1 > 0)
			value += e1 * HUOER;
		if (e2 > 0)
			value += e2 * HUOER;
		if (e3 > 0)
			value += e3 * HUOER;
		if (e4 > 0)
			value += e4 * HUOER;
		//MIANER 
		if (s1 > 0)
			value += s1 * MIANER;
		if (s2 > 0)
			value += s2 * MIANER;
		if (s3 > 0)
			value += s3 * MIANER;
		if (s4 > 0)
			value += s4 * MIANER;
		return value;
	}
	return 0;
}


//1823274 ������

#include <cstdio>

typedef struct PlayInfo
{
	char name[200];
	int nMove;
	double tElapsed;
};

extern void readRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);
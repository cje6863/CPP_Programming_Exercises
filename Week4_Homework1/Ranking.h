#include <cstdio>

typedef struct PlayInfo
{
	char name[200] = "C++¡¡æ∆ø‰";
	int nMove = 1000;
	double tElapsed = 1000.0;
};

extern void readRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);
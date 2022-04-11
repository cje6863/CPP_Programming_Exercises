//1823274 ÃÖÁöÀ±

#include <cstdio>
#include <stdio.h>

struct PlayInfo
{
	char name[200];
	int nMove;
	double tEapsed;
};
extern void loadRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);
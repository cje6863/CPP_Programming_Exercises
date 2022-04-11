//1823274 ÃÖÁöÀ±

#pragma warning(disable:4996)
#include <Windows.h>
#include <stdio.h>
#include <cstdio>
#include "Ranking2.h"
#define NUM_MVP 10
static PlayInfo MVP[NUM_MVP];
static int nMVP = NUM_MVP;

static void initRanking()
{
	PlayInfo noname = { "C++ì¢‹ì•„?š”", 1000, 1000.0 };
	for (int i = 0; i < nMVP; i++) MVP[i] = noname;
}

void loadRanking(const char* fname)
{
	FILE* fp = fopen(fname, "r");
	if (fp == NULL) initRanking();
	else
	{
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);
		fclose(fp);
	}
}

void storeRanking(const char* fname)
{
	FILE* fp = fopen(fname, "w");
	if (fp == NULL) return;
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);
	fclose(fp);
}

void printRanking()
{
	for (int i = 0; i < nMVP; i++)
		printf(" [%2d ?œ„]  %4d  %-16s  %5.1f\n",
			i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tEapsed);
}

int addRanking(int nMove, double tElap)
{
	if (nMove < MVP[nMVP - 1].nMove)
	{
		int pos = nMVP - 1;
		for (; pos > 0; pos--)
		{
			if (nMove >= MVP[pos - 1].nMove) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;
		MVP[pos].tEapsed = tElap;
		printf(" %d?œ„ ?…?‹ˆ?‹¤. ?´ë¦„ì„ ?…? ¥?•˜?„¸?š” : ", pos + 1);
		scanf("%s", MVP[pos].name);
		return pos + 1;
	}
	return 0;
}
#include "Hangman2.h"
#include "MyDic.h"

void main()
{
	Hangman game;
	MyDic dic;

	dic.load("MyWord.txt");
	srand((unsigned int)time(NULL));
	int i = rand() % MAXWORD;
	game.play(dic.getEng(i), dic.getKor(i));
}
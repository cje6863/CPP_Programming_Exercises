#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define MAXWORD 10
using namespace std;

struct WordPair
{
	string eng;
	string kor;
};

class MyDic
{
	WordPair words[MAXWORD];
	int nWords;
public:
	MyDic() { nWords = 0; }

	void add(string eng, string kor)
	{
		for (; nWords < MAXWORD; nWords++)
		{
			cout << "���� �ܾ�� �ѱ� ������ �Է��ϼ��� : ";
			cin >> eng >> kor;
			words[nWords].eng = eng;
			words[nWords].kor = kor;
		}
	}

	void load(const char* filename)
	{
		ifstream f(filename);
		f >> nWords;
		for (int i = 0; i < nWords; i++)
			f >> words[i].eng >> words[i].kor;
		f.close();
	}

	void store(const char* filename)
	{
		ofstream f(filename);
		f << nWords << endl;
		for (int i = 0; i < nWords; i++)
			f << setw(20) << words[i].eng << " " << words[i].kor << endl;
		f.close();
	}

	void print()
	{
		cout << "[�� �ܾ���]\n";
		for (int i = 0; i < nWords; i++)
			cout << setw(20) << words[i].eng << "=" << words[i].kor << endl;
	}

	string getEng(int id) { return words[id].eng; }
	string getKor(int id) { return words[id].kor; }

	int count() { return nWords; }
};
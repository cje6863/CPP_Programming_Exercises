#pragma once
#include "Monster92.h"

class Zombie : public Monster {
public:
	Zombie(string n = "????????", string i = "??", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "?????̾?", string i = "??", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "ó???ͽ?", string i = "??", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
public:
	bool bHori;
public:
	Jiangshi(string n = "????????", string i = "??", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster {
public:
	Smombi(string n = "??????", string i = "??", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Smombi() { cout << " Smombi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		if (dir == 0) { x++; y++; }
		else { x--; y--; }
		clip(maxx, maxy);
		eat(map);
	}
};

class Siangshi : public Jiangshi {
	int count;
public:
	Siangshi(string n = "???۰???", string i = "??", int x = 0, int y = 0, bool bH = true)
		: Jiangshi(n, i, x, y, bH), count(30) {}
	~Siangshi() { cout << " Siangshi"; }

	void move(int** map, int maxx, int maxy) {
		Jiangshi::move(map, maxx, maxy);
		count--;
		if (count == 0)
		{
			bHori = !bHori;
			count = 30;
		}
	}
};

class Minion : public Monster {
public:
	Minion(string n = "?̴Ͼ?", string i = "??", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Minion() { cout << " Minion"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x = x - 2;
		else if (dir == 1) x = x + 2;
		else if (dir == 2) y = y - 2;
		else y = y + 2;
		clip(maxx, maxy);
		eat(map);
	}
};
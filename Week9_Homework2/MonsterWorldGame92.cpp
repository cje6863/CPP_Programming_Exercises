#include "MonsterWorld92.h"
#include "VariousMonsters92.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("??????????", "??", rand() % w, rand() % h));
	game.add(new Vampire("?????̾?¯", "??", rand() % w, rand() % h));
	game.add(new KGhost("??¼?ٱͽ?", "??", rand() % w, rand() % h));
	game.add(new Jiangshi("???Ծ??", "??", rand() % w, rand() % h, true));
	game.add(new Jiangshi("???Ծ??", "??", rand() % w, rand() % h, false));
	game.add(new Smombi("??????????", "??", rand() % w, rand() % h));
	game.add(new Siangshi("?ٸԾ??", "??", rand() % w, rand() % h, false));
	game.add(new Minion("?̴Ͼ?¯¯", "??", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------???? ????------------\n");
}
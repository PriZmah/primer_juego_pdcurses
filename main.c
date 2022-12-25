#include <curses.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 90
#define HEIGHT 40
#define SCR_WIDTH WIDTH / 1.4
#define SCR_HEIGHT HEIGHT / 1.4

int main(void) {
	const int start_x = 12, start_y = 6;
	const char player = '@';
	const char target = '*';
	int x = 1, y = 1;
	int puntaje = 0;
	int rand_x, rand_y;

	initscr();
	resize_term(HEIGHT, WIDTH);
	curs_set(0);
	noecho();
	cbreak();
	mvaddstr(3, (WIDTH - 35) / 2, "NO TENGO NOMBRE PARA ESTE JUEGO XD");
	mvaddstr(4, (WIDTH - 15) / 2, "Por PriZmah <3");

	WINDOW *ventana = newwin(SCR_HEIGHT, SCR_WIDTH, start_y, start_x);
	nodelay(ventana, true);

	rand_x = (rand() % (int) ((SCR_WIDTH - 4) + 1)) + 4;
	rand_y = (rand() % (int) ((SCR_HEIGHT - 4) + 1)) + 4;

	while (true) {		
		mvprintw(35, (WIDTH - 12) / 2, "PUNTAJE: %d", puntaje);
		refresh();
		
		mvwaddch(ventana, rand_y, rand_x, target);
		
		box(ventana, 0, 0);
		mvwaddch(ventana, y, x, player);
		
		
		switch (wgetch(ventana)) {
			case 'w': y--; break;
			case 's': y++; break;
			case 'd': x++; break;
			case 'a': x--; break;
		}
		wmove(ventana, y, x);
		
		if (winch(ventana) == target) {
			srand(time(NULL));
			
			waddch(ventana, player);
			rand_x = (rand() % (int) (((SCR_WIDTH - 2) - 4) + 1)) + 4;
			rand_y = (rand() % (int) (((SCR_HEIGHT - 2) - 4) + 1)) + 4;
			puntaje++;
		}

		wrefresh(ventana);
		werase(ventana);
	}
	endwin();
	return 0;
}
#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 35
#define HEIGHT 35
#define MINES 100

typedef struct {
    int revealed;
    int mine;
    int adjacent;
} Cell;

Cell grid[HEIGHT][WIDTH];

void initialize_grid() {
    srand(time(NULL));

    for (int i = 0; i < MINES; ) {
        int x = rand() % HEIGHT;
        int y = rand() % WIDTH;
        if (!grid[x][y].mine) {
            grid[x][y].mine = 1;
            i++;
        }
    }

    for (int x = 0; x < HEIGHT; x++) {
        for (int y = 0; y < WIDTH; y++) {
            if (grid[x][y].mine) {
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH) {
                            grid[nx][ny].adjacent++;
                        }
                    }
                }
            }
        }
    }
}

void reveal(int x, int y) {
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH || grid[x][y].revealed) {
        return;
    }

    grid[x][y].revealed = 1;

    if (grid[x][y].mine) {
        return;
    }

    if (grid[x][y].adjacent == 0) {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                reveal(x + dx, y + dy);
            }
        }
    }
}

void draw_grid(int cursor_x, int cursor_y) {
	int spasi = 3;
    for (int x = 0; x < HEIGHT; x++) {
        for (int y = 0; y < WIDTH; y++) {
        	int jarak = y * spasi;
            if (grid[x][y].revealed) {
                if (grid[x][y].mine) {
                    mvprintw(x, jarak, "*");
                } else {
                    mvprintw(x, jarak, "%d", grid[x][y].adjacent);
                }
            } else {
                if (x == cursor_x && y == cursor_y) {
                    attron(A_REVERSE);
                    mvprintw(x, jarak, ".");
                    attroff(A_REVERSE); 
                } else {
                    mvprintw(x, jarak, ".");
                }
            }
        }
    }
}

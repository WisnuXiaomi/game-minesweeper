#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

const int EASY = 8;   
const int MEDIUM = 16;  
const int HARD = 24; 

struct Cell {
    bool isMine;
    bool isRevealed;
    bool isFlagged;
    int adjacentMines;
};

class Minesweeper {
private:
    vector<vector<Cell>> grid;
    int rows, cols, totalMines;
    int revealedCells;

    void initializeGrid(int level) {
        switch (level) {
            case 1: 
                rows = cols = EASY;
                totalMines = 10;
                break;
            case 2: 
                rows = cols = MEDIUM;
                totalMines = 40;
                break;
            case 3: 
                rows = cols = HARD;
                totalMines = 99;
                break;
        }

        grid = vector<vector<Cell>>(rows, vector<Cell>(cols));
        revealedCells = 0;

        // Initialize grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                grid[i][j].isMine = false;
                grid[i][j].isRevealed = false;
                grid[i][j].isFlagged = false;
                grid[i][j].adjacentMines = 0;
            }
        }

        
        srand(time(0));
        for (int i = 0; i < totalMines; ++i) {
            int r = rand() % rows;
            int c = rand() % cols;
            if (grid[r][c].isMine) {
                --i;  // Retry if mine is already placed
            } else {
                grid[r][c].isMine = true;
            }
        }

    
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c].isMine) continue;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        int nr = r + i, nc = c + j;
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc].isMine) {
                            grid[r][c].adjacentMines++;
                        }
                    }
                }
            }
        }
    }

    void drawGrid(int cursorX, int cursorY) {
        clear();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == cursorX && j == cursorY) {
                    attron(A_REVERSE);
                }

                if (grid[i][j].isRevealed) {
                    if (grid[i][j].isMine) {
                        printw("* ");
                    } else {
                        printw("%d ", grid[i][j].adjacentMines);
                    }
                } else if (grid[i][j].isFlagged) {
                    printw("F ");
                } else {
                    printw(". ");
                }

                if (i == cursorX && j == cursorY) {
                    attroff(A_REVERSE);
                }
            }
            printw("\n");
        }
        refresh();
    }

    bool revealCell(int x, int y) {
        if (grid[x][y].isRevealed || grid[x][y].isFlagged) return false;
        grid[x][y].isRevealed = true;
        revealedCells++;

        if (grid[x][y].isMine) {
            return true; 
        }

        if (grid[x][y].adjacentMines == 0) {
            // Recursively reveal neighboring cells
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int nx = x + i, ny = y + j;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                        revealCell(nx, ny);
                    }
                }
            }
        }
        return false;
    }

public:
    Minesweeper(int level) {
        initializeGrid(level);
    }

    void playGame() {
        int cursorX = 0, cursorY = 0;
        bool gameOver = false;

        while (!gameOver && revealedCells < (rows * cols - totalMines)) {
            drawGrid(cursorX, cursorY);

            int ch = getch();
            switch (ch) {
                case KEY_UP: cursorX = (cursorX > 0) ? cursorX - 1 : cursorX; break;
                case KEY_DOWN: cursorX = (cursorX < rows - 1) ? cursorX + 1 : cursorX; break;
                case KEY_LEFT: cursorY = (cursorY > 0) ? cursorY - 1 : cursorY; break;
                case KEY_RIGHT: cursorY = (cursorY < cols - 1) ? cursorY + 1 : cursorY; break;
                case ' ': // Reveal cell
                    gameOver = revealCell(cursorX, cursorY);
                    break;
                case 'f': // Flag cell
                    if (!grid[cursorX][cursorY].isRevealed) {
                        grid[cursorX][cursorY].isFlagged = !grid[cursorX][cursorY].isFlagged;
                    }
                    break;
                default:
                    break;
            }
        }

        clear();
        if (gameOver) {
            printw("Game Over! You hit a mine.\n");
        } else {
            printw("You win! All non-mined cells revealed.\n");
        }
        refresh();
        getch(); 
    }
};

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int level;
    printw("Select difficulty level:\n");
    printw("1. Easy\n2. Medium\n3. Hard\n");
    refresh();
    scanw("%d", &level);

    Minesweeper game(level);
    game.playGame();

    endwin();
    return 0;
}

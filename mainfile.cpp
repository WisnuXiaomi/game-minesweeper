#include <ncurses/ncurses.h>
#include <windows.h>
using namespace std;

int main(){
	initscr();
	
	noecho();
	curs_set(0);
	
	for(int i = 0 ; i < 3 ; i++){
		mvprintw(19,75,"       Loading");
		mvprintw(20,75,"---------------------");
		mvprintw(21,75,"|                   |");
		mvprintw(22,75,"---------------------");
		
		for(int j = 1 ; j <= 19 ; j++){
			start_color();
			init_pair(1,COLOR_GREEN,COLOR_BLACK);
			attron(COLOR_PAIR(1));
			mvprintw(21,75 + j,"|");
			attroff(COLOR_PAIR(1));
			refresh();
			Sleep(200);
		}
	}
	clear();
	
	echo();
	curs_set(1);
	
	mvprintw(0,25,".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
	mvprintw(1,25,"|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
	mvprintw(2,25,"|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
	mvprintw(3,25,"|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
	mvprintw(4,25,"|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
	mvprintw(5,25,"|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");
	
	
	getch();
	endwin();
	return 0;
}

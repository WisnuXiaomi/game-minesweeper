#include <ncurses/ncurses.h>
#include <windows.h>
#include "fungsilogin.cpp"

void print_menu(WINDOW *menu_win, int pilTerpilih, const char *opsi[], int jumlahOpsi);

int main() {
    char username[50];
    char password[50];
	
    initscr();
    clear();
    cbreak();
    noecho();
    curs_set(0);

    mvprintw(19,75,"==== LOGIN ====");
    mvprintw(20,75,"Username :");
    echo();
	getstr(username);
    mvprintw(21,75,"Password :");
    noecho();
    getstr(password);
    clear();
    refresh();
	
	char hasil = login(username,password);
	
    if(hasil == 'Y') {
        mvprintw(20,75,"Login berhasil!");
        getch();
    }else{
        mvprintw(21,75,"Username atau Password Salah!");
        getch();
        return 0;
    }
    clear();
    refresh();
    

	for (int i = 0; i < 2; i++) {
	    mvprintw(19, 75, "       Loading");
	    mvprintw(20, 75, "---------------------");
	    mvprintw(21, 75, "|                   |");
	    mvprintw(22, 75, "---------------------");
	
	
	    for (int j = 1; j <= 19; j++) {
	        start_color(); 
	        init_pair(1, COLOR_GREEN, COLOR_BLACK);
	        attron(COLOR_PAIR(1));
	        mvprintw(21, 75 + j, "|");
	        attroff(COLOR_PAIR(1));
	        refresh();
	        Sleep(200);
	    }
	}


    clear();
    refresh();
    
    
    mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
    mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
    mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
    mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
    mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
    mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");
	



    int awalX = 0, awalY = 0;
	int lebar = 1000, tinggi = 100;
	
	 if (has_colors() == FALSE){
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE); 
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
	
	WINDOW *menu_win = newwin(tinggi, lebar, awalY, awalX);
	keypad(menu_win, TRUE);
	
	const char *opsi[] = {
	          "Easy",
		  "Normal",
		  "Hard",
		  "Keluar"	
	};
	int jumlahOpsi = sizeof(opsi) / sizeof(char *);
	int pilTerpilih = 0;
	int pilihan = -1;

    mvwprintw(menu_win, 19, 75, "[ Menu ]");
	mvwprintw(menu_win,0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
    mvwprintw(menu_win,1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
    mvwprintw(menu_win,2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
    mvwprintw(menu_win,3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
    mvwprintw(menu_win,4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
    mvwprintw(menu_win,5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");
	
	while (1){
		print_menu(menu_win, pilTerpilih, opsi, jumlahOpsi);
		int tombol = wgetch(menu_win);
		switch (tombol){
			case KEY_UP:
			    if (pilTerpilih == 0)
			        pilTerpilih = jumlahOpsi - 1;
			    else
			        --pilTerpilih;
			    break;
			case KEY_DOWN:
				if (pilTerpilih == jumlahOpsi-1)
				    pilTerpilih = 0;
				else
				    ++pilTerpilih;
				break;
			case 10:
				pilihan = pilTerpilih;
				break;
		}
		if (pilihan == 3) 
		   break;
	}

	clrtoeol();
	refresh();
	getch();
    endwin();
    return 0;
}

void print_menu(WINDOW *menu_win, int pilTerpilih, const char *opsi[], int jumlahOpsi){
	for (int i = 0; i < jumlahOpsi; i++){
		if (i == pilTerpilih)
		   wattron(menu_win, A_REVERSE);
		mvwprintw(menu_win, i+20, 75, opsi[i]);
		wattroff(menu_win, A_REVERSE);
	}
	wrefresh(menu_win);
}



#include <ncurses/curses.h>

void print_menu(WINDOW *menu_win, int pilTerpilih, const char *opsi[], int jumlahOpsi);

int main(){
	initscr();
	clear();
	noecho();
	cbreak();
	int awalX = 50, awalY = 10;
	int lebar = 20, tinggi = 10;
	
	 if (has_colors() == FALSE){
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE); 
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
	
	WINDOW *menu_win = newwin(tinggi, lebar, awalY, awalX);
	box(menu_win, 4, 6); 
        wbkgd(menu_win, COLOR_PAIR(2));
	keypad(menu_win, TRUE);
	
	const char *opsi[] = {
	          "Pilihan 1",
		  "Pilihan 2",
		  "Pilihan 3",
		  "Keluar"	
	};
	int jumlahOpsi = sizeof(opsi) / sizeof(char *);
	int pilTerpilih = 0;
	int pilihan = -1;

    wattron(menu_win, COLOR_PAIR(1));
    mvwprintw(menu_win, 0, (lebar - 10) / 2, "[ MENU ]");
    wattroff(menu_win, COLOR_PAIR(1));

	
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
	endwin();
	return 0;
}

void print_menu(WINDOW *menu_win, int pilTerpilih, const char *opsi[], int jumlahOpsi){
	for (int i = 0; i < jumlahOpsi; i++){
		if (i == pilTerpilih)
		   wattron(menu_win, A_REVERSE);
		mvwprintw(menu_win, i+1, 1, opsi[i]);
		wattroff(menu_win, A_REVERSE);
	}
	wrefresh(menu_win);
}

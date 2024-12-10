#include <ncurses/ncurses.h>
#include <windows.h>
#include <fstream>
#include <string>

void print_menu(WINDOW *menu_win, int pilTerpilih, const char *opsi[], int jumlahOpsi);
void registr();
void forgot();
using namespace std;

bool login() {
    char user[50], pass[50];
    string u, p;
    clear();
   	mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
	mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
   	mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
   	mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
   	mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
	mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");	
    mvprintw(19, 75, "Username: ");
    echo();
    getstr(user);
    mvprintw(20, 75, "Password: ");
    getstr(pass);
    noecho();

    ifstream input("minesweeper.txt");
    while (input >> u >> p) {
        if (u == user && p == pass) {
            clear();
            mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
			mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
   			mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
   			mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
   			mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
			mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");	
            mvprintw(19, 75, "Hello %s", user);
            mvprintw(20, 75, "<LOGIN SUKSES>");
            getch();
            return true;
        }
    }
    input.close();

    clear();
   	mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
	mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
   	mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
   	mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
   	mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
	mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");	
    mvprintw(19, 75, "LOGIN ERROR!!!!");
    mvprintw(20, 75, "Silahkan Cek Username dan Password Anda.");
    getch();
    return false;
}

int main() {
    char username[50];
    char password[50];
    char input;
    bool loggin = false;
	
    initscr();
    clear();
    cbreak();
    noecho();
    curs_set(0);

	    do {
        clear();
	    mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
	    mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
	    mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
	    mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
	    mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
	    mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");
	    
        mvprintw(19, 75, "1. Login");
        mvprintw(20, 75, "2. Register");
        mvprintw(21, 75, "3. Lupa username atau password");
        mvprintw(22, 75, "4. Keluar");
        mvprintw(23, 75, "Pilih Salah Satu: ");
        input = getch();

        switch (input) {
        	case '1':
        		if(login()){
                loggin = true;
                break;
            }
                break;
            case '2':
                registr();
                break;
            case '3':
                forgot();
                break;
            case '4':
            	mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
	    		mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
	    		mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
	    		mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
	    		mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
	    		mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");
                clear();
                mvprintw(10, 45, "Terima kasih telah menggunakan program ini.");
                break;
            default:
                mvprintw(9, 45, "Pilihan tidak valid! Coba lagi.");
                getch();
        }
    } while (input != '4' && !loggin);
    
    if(loggin){

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
	
	    int awalX = 0, awalY = 0;
		int lebar = 1000, tinggi = 100;
		
		 if (has_colors() == FALSE){
	        endwin();
	        printf("Terminalmu Tidak Support Warna Ini\n");
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

void registr() {
    char reguser[50], regpass[50];

    clear();
	mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
   	mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
   	mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
   	mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
   	mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
   	mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");
	    	
    mvprintw(19, 75, "Masukan Username: ");
    echo();
    getstr(reguser);
    mvprintw(20, 75, "Masukan Password: ");
    getstr(regpass);
    noecho();

    ofstream reg("minesweeper.txt", ios::app);
    reg << reguser << " " << regpass << endl;

    clear();
    mvprintw(19, 75, "Registrasi Sukses.");
    getch();
}

void forgot() {
    int ch;
    string searchuser, su, sp;

    clear();
	mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
   	mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
   	mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
   	mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
   	mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
   	mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");

    mvprintw(19, 75, "Lupa? Kami akan Membantu Anda");
    mvprintw(20, 75, "1. Cari password berdasarkan username");
    mvprintw(21, 75, "2. Kembali ke Menu Utama");
    mvprintw(22, 75, "Pilih: ");
    ch = getch();

    switch (ch) {
        case '1': {
            int count = 0;
            char user[50];

            clear();
			mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
	   		mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
	   		mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
	   		mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
   			mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
	   		mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");			        
        
            mvprintw(19, 75, "Masukkan username yang diingat: ");
            echo();
            getstr(user);
            noecho();

            ifstream searchu("minesweeper.txt");
            while (searchu >> su >> sp) {
                if (su == user) {
                    count = 1;
                    break;
                }
            }
            searchu.close();

            clear();
            mvprintw(0, 25, ".___  ___.  __  .__   __.  _______     _______.____    __    ____  _______  _______ .______    _______ .______      ");
	   		mvprintw(1, 25, "|   \\/   | |  | |  \\ |  | |   ____|   /       |\\   \\  /  \\  /   / |   ____||   ____||   _  \\  |   ____||   _  \\     ");
	   		mvprintw(2, 25, "|  \\  /  | |  | |   \\|  | |  |__     |   (----` \\   \\/    \\/   /  |  |__   |  |__   |  |_)  | |  |__   |  |_)  |    ");
	   		mvprintw(3, 25, "|  |\\/|  | |  | |  . `  | |   __|     \\   \\      \\            /   |   __|  |   __|  |   ___/  |   __|  |      /     ");
   			mvprintw(4, 25, "|  |  |  | |  | |  |\\   | |  |____.----)   |      \\    /\\    /    |  |____ |  |____ |  |      |  |____ |  |\\  \\----.");
	   		mvprintw(5, 25, "|__|  |__| |__| |__| \\__| |_______|_______/        \\__/  \\__/     |_______||_______|| _|      |_______|| _| `._____|");	
            if (count == 1) {
                mvprintw(19, 75, "Akun ditemukan.");
                mvprintw(20, 75, "Password Anda: %s", sp.c_str());
            } else {
                mvprintw(19, 75, "Maaf, username tidak ditemukan dalam database.");
            }
            getch();
            break;
        }
        case '2':
            break;
        default:
            mvprintw(19, 75, "Pilihan tidak valid! Coba lagi.");
            getch();
    }
}

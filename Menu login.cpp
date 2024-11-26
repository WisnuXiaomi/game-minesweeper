#include <ncurses.h>
#include <iostream>
#include <string>
#include "menusederhana.cpp"

using namespace std;

// Fungsi untuk memulai permainan
void startGame(string username, string difficulty) {
    clear();
    mvprintw(5, 10, "=== Memulai Permainan ===");
    mvprintw(6, 10, "Pemain: %s", username.c_str());
    mvprintw(7, 10, "Kesulitan: %s", difficulty.c_str());
    mvprintw(8, 10, "Selamat bermain!");
    refresh();  // Update the screen

    // Tambahkan logika Minesweeper di sini

    getch();  // Wait for user input before returning
}

// Fungsi untuk menampilkan menu kesulitan
void selectDifficulty(string username) {
    int choice;
    clear();
    mvprintw(5, 10, "=== Pilih Tingkat Kesulitan ===");
    mvprintw(6, 10, "1. Easy");
    mvprintw(7, 10, "2. Medium");
    mvprintw(8, 10, "3. Hard");
    mvprintw(9, 10, "Masukkan pilihan Anda (1/2/3): ");
    refresh();

    choice = getch() - '0';  // Read input as a number ('0', '1', etc.)

    switch (choice) {
        case 1:
            startGame(username, "Easy");
            break;
        case 2:
            startGame(username, "Medium");
            break;
        case 3:
            startGame(username, "Hard");
            break;
        default:
            mvprintw(10, 10, "Pilihan tidak valid. Coba lagi.");
            refresh();
            getch();  // Wait for a key press
            selectDifficulty(username);
    }
}

string username_base = "Player123", pass_base = "321Player";

// Fungsi untuk menampilkan menu login
void loginMenu() {
    int choice;
    string username, pass;

    // Clear screen and show login menu
    clear();
    mvprintw(5, 10, "=== MENU LOGIN MINESWEEPER ===");
    mvprintw(6, 10, "Masukkan Nama Pengguna: ");
    refresh();

    // Input username
    char username_input[50];
    echo();
    getstr(username_input);
    username = string(username_input);
    noecho();  // Turn off echoing for password input

    mvprintw(7, 10, "Masukkan Password: ");
    refresh();

    // Input password
    char pass_input[50];
    getstr(pass_input);
    pass = string(pass_input);

    // Validate login credentials
    if (username == username_base && pass == pass_base) {
        selectDifficulty(username);
    } else if (username == username_base && pass != pass_base) {
        mvprintw(8, 10, "Password Salah! Silahkan Login Kembali");
        refresh();
        getch();  // Wait for a key press
        loginMenu();
    } else if (username != username_base && pass == pass_base) {
        mvprintw(8, 10, "Username Salah! Silahkan Login Kembali");
        refresh();
        getch();  // Wait for a key press
        loginMenu();
    } else {
        mvprintw(8, 10, "Username dan Password Salah! Silahkan Login Kembali");
        refresh();
        getch();  // Wait for a key press
        loginMenu();
    }
}

// Fungsi utama
int main() {
    initscr();  // Initialize ncurses
    cbreak();   // Disable line buffering
    noecho();   // Do not echo input
    curs_set(0);  // Hide cursor

    loginMenu();  // Show login menu

    endwin();  // End ncurses mode
    return 0;
}

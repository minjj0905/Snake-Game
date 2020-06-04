#include "View.h"
#include <locale.h>

View::View() {
    Init();
}

void View::Init() {
    initscr();

    resize_term(30, 60);
    noecho();
    curs_set(0); 
    start_color();

    border(ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    bkgd(COLOR_PAIR(2));
}

// void View::Draw() {
//     DrawGame();
//     DrawScore();
//     refresh();
// }

void View::DrawGame() {

    gameWin = newwin(20, 20, 3, 3);
    wbkgd(gameWin, COLOR_PAIR(2));
    wattron(gameWin, COLOR_PAIR(2));

    mvwaddch(gameWin, 1, 1, 96|A_ALTCHARSET);

    setlocale(LC_ALL, "");
    mvwprintw(gameWin, 3, 3, "\u25A0");
    mvwprintw(gameWin, 3, 5, "되냐");
    wborder(gameWin, '~','~','~','~','~','~','~','~');

    int map[21][21] = {
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,3,4,4,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    };


    // for(int i=0; i<21; i++) {
    //     for(int j=0; j<42; j++) {

    //         int pos = map[i][j/2];

    //         if(pos == 0) {
    //             // mvaddch(i, j, ' ');
    //         }
    //         else if(pos == 1 || pos == 2) {
    //             // mvaddch(i, j, ACS_BOARD);
    //             mvwprintw(gameWin, i, j, "-");
    //         }
    //         else if(pos == 3) {
    //             // mvaddch(i, j, 'O');
    //         }
    //         else if(pos == 4) {
    //             // mvaddch(i, j, 'o');
    //         }
    //         // mvaddch(i, ++j, ' ');
    //     }
    // }
    refresh();
    wrefresh(gameWin);
}

/* 테스트용 코드 */
int main() {
    View test;
    test.Init();
    test.DrawGame();
    getch();
    delwin(test.gameWin);
    endwin();
}
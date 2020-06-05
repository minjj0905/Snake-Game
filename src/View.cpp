#include "View.h"

View::View() {
    Init();
}

void View::Init() {
    setlocale(LC_ALL, "");
    initscr();

    resize_term(30, 60);
    noecho();
    curs_set(0); 
    start_color();

    border(ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
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

    wborder(gameWin, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

    mvwaddch(gameWin, 1, 1, 96|A_ALTCHARSET);

    mvwprintw(gameWin, 3, 3, "\u25A0\u25A0\u25A0\u25A0 \u274C \u2665 \u2721 \u273A");
    wattron(gameWin, COLOR_PAIR(1));
    mvwaddstr(gameWin, 4, 3, "\u2588\u2588\u2588\u2588\u2588 \u266C \u266B \u266A \u2B50");
    mvwaddch(gameWin, 5, 3, ACS_CKBOARD);
    

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
    refresh();
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
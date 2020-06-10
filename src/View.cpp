#include <clocale>
#include <ncursesw/ncurses.h>
#include "View.h"

View::View() {
    setlocale(LC_ALL, "");
    initscr();

    resize_term(35, 100);
    noecho();
    curs_set(0); 
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    
    bkgd(COLOR_PAIR(1));
}

void View::draw(Map map, Snake snake) {
    drawMainWindow();
    drawGameWindow(map);
    drawScoreWindow(snake);
    drawBorder();
    refresh();
    wrefresh(gameWindow);
}

void View::drawMainWindow() {
    mvprintw(1, 3, "Preversion");
    mvprintw(2, 3, "Logo Space");
    mvprintw(3, 3, "margin");
    return;
}

void View::drawGameWindow(Map map) {
    gameWindow = newwin(25, 50, 5, 2);
    wbkgd(gameWindow, COLOR_PAIR(2));
    wattron(gameWindow, COLOR_PAIR(2));

    int margin = 2;

     for(int i=0; i<21; i++) {
        for(int j=0; j<21; j++) {
            int pos = map.getMapValue(i, j);
            wattron(gameWindow, COLOR_PAIR(2));
            if(pos == 0) {
                wattron(gameWindow, COLOR_PAIR(4));
                mvwprintw(gameWindow, margin+i, margin+j, "\u2B1B");
            }
            else if(pos == 1 || pos == 2) {
                mvwprintw(gameWindow, margin+i, margin+j, "\u2B1B");
            }
            else if(pos == 3) {
                mvwprintw(gameWindow, margin+i, margin+j, "\u25CF");
            }
            else if(pos == 4) {
                mvwprintw(gameWindow, margin+i, margin+j, "\u25CB");
            }
        }
    }

}

void View::drawScoreWindow(Snake snake) {
    /*미개발*/
    return;
}

void View::drawBorder() {
    border(0, 0, 0, 0, 0, 0, 0, 0);
}

/* 테스트용 코드, mainlogic 간단한 버전이라고 보면 될 듯*/
int main() {
    Level lv;
    lv.createMap();
    Snake snake;
    View test;
    Map map = lv.getCurrentMap();
    test.draw(map, snake);
    getch();
    delwin(test.gameWindow);
    endwin();
}
/* 테스트 끝 */
#include <clocale>
#include "View.h"
#include <string>
#include <wchar.h>

View::View() {
    setlocale(LC_ALL, "");
    initscr();

    resize_term(WINDOW_HEIGHT, WINDOW_WIDTH);
    noecho();
    curs_set(0); 
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    
    bkgd(COLOR_PAIR(1));
}

void View::drawStartScreen(){
    mvprintw(10, 10, "게임을 시작하려면 아무키나 누르세요");
    refresh();
}

void View::drawGameOver(){
    clear();
    nodelay(stdscr, FALSE);
    mvprintw(10, 10, "Gameover...");
    getch();
}

void View::draw(Map map, Snake snake) {
    drawMainWindow();
    drawGameWindow(map);
    drawSnake(snake);
    drawScoreWindow(snake);
    drawBorder();
    update();
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
    wattron(gameWindow, COLOR_PAIR(1));

    int margin = 2;
    wchar_t block[] = { 9632, L'\0' };

     for(int i=0; i<map.mapHeight; i++) {
        for(int j=0; j<map.mapWidth; j++) {
            int pos = map.getMapValue(i, j);
            wattron(gameWindow, COLOR_PAIR(1));
            if(pos == 0) {
                wattron(gameWindow, COLOR_PAIR(4));
                mvwaddwstr(gameWindow, margin+i, margin+j, block);
            }
            else if(pos == 1 || pos == 2) {
                mvwaddwstr(gameWindow, margin+i, margin+j, block);
            }

        }
    }
}

void View::drawSnake(Snake snake) {
    int margin = 2;
    std::vector<POSITION> snakepos = snake.getPosition();

    wattron(gameWindow, COLOR_PAIR(2));
    
    //head
    mvwprintw(gameWindow, margin+snakepos[0].y, margin+snakepos[0].x, "\u25CF");

    //body
    for(int i=1; i<snake.getLength(); i++) {
        POSITION pos = snakepos[i];
        mvwprintw(gameWindow, margin+pos.y, margin+pos.x, "\u25CB");
    }
}

void View::drawScoreWindow(Snake snake) {
    return;
}

void View::drawBorder() {
    border(0, 0, 0, 0, 0, 0, 0, 0);
}

void View::update()  {
    refresh();
    wrefresh(gameWindow);
}
/* 테스트용 코드, mainlogic 간단한 버전이라고 보면 될 듯*/
// int main() {
//     Level lv;
//     lv.createMap();
//     Snake snake;
//     View test;
//     Map map = lv.getCurrentMap();
//     test.draw(map, snake);
//     getch();
//     delwin(test.gameWindow);
//     endwin();
// }
/* 테스트 끝 */
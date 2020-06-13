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
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair('g', COLOR_GREEN, COLOR_BLACK);
    init_pair('r', COLOR_RED, COLOR_BLACK);
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

void View::draw(Map map, Snake snake, std::vector<Item> item) {
    drawMainWindow();
    drawGameWindow(map, snake, item);
    // drawSnake(snake);
    drawItem(item);
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

void View::drawGameWindow(Map map, Snake snake, std::vector<Item> item) {
    gameWindow = newwin(25, 50, 5, 2);
    wbkgd(gameWindow, COLOR_PAIR(2));
    wattron(gameWindow, COLOR_PAIR(1));

    int margin = 2;
    wchar_t block[] = L"■";
    wchar_t body[] = L"□";

    std::vector<POSITION> snakepos = snake.getPosition();

     for(int i=0; i<map.mapHeight; i++) {
        for(int j=0; j<map.mapWidth; j++) {
            int pos = map.getMapValue(i, j);
            wattron(gameWindow, COLOR_PAIR(1));
            if(pos == 0) {
                if((snakepos[0].y == i) && (snakepos[0].x == j)) {
                    wattron(gameWindow, COLOR_PAIR(2));
                    mvwaddwstr(gameWindow, margin+snakepos[0].y, margin+snakepos[0].x, block);
                }
                else{
                    for(int k=1; k<snake.getLength(); k++) {
                        if((snakepos[k].y == i) && (snakepos[k].x == j)) {
                            wattron(gameWindow, COLOR_PAIR(2));
                            mvwaddwstr(gameWindow, margin+snakepos[k].y, margin+snakepos[k].x, body);
                        }
                    }
                }
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
    wchar_t head[] = L"■";
    wchar_t body[] = L"□";

    //head
    mvwaddwstr(gameWindow, margin+snakepos[0].y, margin+snakepos[0].x, head);

    //body
    for(int i=1; i<snake.getLength(); i++) {
        POSITION pos = snakepos[i];
        mvwaddwstr(gameWindow, margin+pos.y, margin+pos.x, body);
    }
}

void View::drawItem(std::vector<Item> item) {
    wchar_t growitem[] = L"■";
    wchar_t poisonitem[] = L"■";

    int margin = 2;
    for(int i=0; i<item.size(); i++) {
        POSITION itempos = item[i].getItemPos();
        if(item[i].isGrowItem()) {
            wattron(gameWindow, COLOR_PAIR('g'));
            mvwaddwstr(gameWindow, itempos.y + margin, itempos.x + margin, growitem);
        }else{
            wattron(gameWindow, COLOR_PAIR('r'));
            mvwaddwstr(gameWindow, itempos.y + margin, itempos.x + margin, poisonitem);
        }
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
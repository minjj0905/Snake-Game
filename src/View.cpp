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
    init_pair('w', 15, COLOR_BLACK);
    init_pair(2, 14, COLOR_BLACK);
    init_pair('g', 10, COLOR_BLACK);
    init_pair('r', 9, COLOR_BLACK);
    init_pair('m', 5, COLOR_BLACK);
    init_pair('b', 8, COLOR_BLACK);
    init_pair('s', 11, COLOR_BLACK);
    
    bkgd(COLOR_PAIR('w'));
    attron(COLOR_PAIR('w'));
}

void View::drawStartScreen(){
    attron(COLOR_PAIR('b'));
    mvprintw(10, 10, "게임을 시작하려면 아무키나 누르세요");
    refresh();
}

void View::drawGameOver(){
    clear();
    nodelay(stdscr, FALSE);
    attron(COLOR_PAIR('b'));
    mvprintw(10, 10, "Gameover...");
    getch();
}

void View::drawNextStage() {
    clear();
    nodelay(stdscr, FALSE);
    attron(COLOR_PAIR('b'));
    mvprintw(10, 10, "Stage Clear!");
    mvprintw(12, 8, "Press any key...");
    getch();
    refresh();
}

void View::drawGameClear(){
    clear();
    nodelay(stdscr, FALSE);
    mvprintw(10, 10, "Clear!");
    getch();
    refresh();
}

void View::draw(Map map, Snake snake, std::vector<Item> item, std::vector<Gate> gate, Mission mission, int time) {
    drawMainWindow();
    drawGameWindow(map);
    drawSnake(snake);
    drawItem(item);
    drawGate(gate);
    drawScoreWindow(snake, mission, time);
    drawBorder();
    update();
}

void View::drawMainWindow() {
    //타이틀
    attron(COLOR_PAIR('g'));
    mvprintw(2, 5, "██    ██  ██  ██  ████████  ████████    ██ ██    ████    ██  ████████");
    mvprintw(3, 5, "████████  ██████  ██    ██        ██  ████ ██  ██    ██  ██  ██    ██");
    mvprintw(4, 5, "██    ██  ██  ██  ██    ██        ██    ██ ██  ██    ██  ██  ██    ██");
    mvprintw(5, 5, "████████  ██  ██  ████████        ██    ██ ██    ████    ██  ████████");
}

void View::drawGameWindow(Map map) {
    gameWindow = newwin(22, 44, 7, 2);
    wbkgd(gameWindow, COLOR_PAIR('w'));
    wattron(gameWindow, COLOR_PAIR('w'));

     for(int i=0; i<map.mapHeight; i++) {
        for(int j=0; j<map.mapWidth; j++) {
            int pos = map.getMapValue(i, j);
            if(pos == 0) {
                wattron(gameWindow, COLOR_PAIR('w'));
                wprintw(gameWindow, "  ");
            }
            else if(pos == 1 || pos == 2) {
                wattron(gameWindow, COLOR_PAIR('w'));
                wprintw(gameWindow, " ");
                mvwprintw(gameWindow, i, 2*j, "■");
            }
            else if(pos == 5) {
                wattron(gameWindow, COLOR_PAIR('b'));
                wprintw(gameWindow, " ");
                mvwprintw(gameWindow, i, 2*j, "■");
            }
        }
    }
}

void View::drawSnake(Snake snake) {
    std::vector<POSITION> snakepos = snake.getPosition();

    wattron(gameWindow, COLOR_PAIR(2));
    wchar_t head[] = L" ■";
    wchar_t body[] = L" □";

    //head
    wprintw(gameWindow, " ");
    mvwprintw(gameWindow, snakepos[0].y, 2*snakepos[0].x, "●");

    //body
    for(int i=1; i<snake.getLength(); i++) {
        POSITION pos = snakepos[i];
        wprintw(gameWindow, " ");
        mvwprintw(gameWindow, pos.y, 2*pos.x, "○");
    }
}

void View::drawItem(std::vector<Item> item) {
    for(int i=0; i<item.size(); i++) {
        POSITION itempos = item[i].getItemPos();
        if(item[i].isGrowItem()) {
            wattron(gameWindow, COLOR_PAIR('g'));
            mvwprintw(gameWindow, itempos.y, 2*itempos.x, "♣");
        }else{
            wattron(gameWindow, COLOR_PAIR('r'));
            mvwprintw(gameWindow, itempos.y, 2*itempos.x, "❌");
        }
    }
}

void View::drawGate(std::vector<Gate> gate) {
    wattron(gameWindow, COLOR_PAIR('s'));
    if(!gate.empty()) {
        POSITION gatepos1 = gate[0].getGatePos(1);
        POSITION gatepos2 = gate[0].getGatePos(2);
        mvwprintw(gameWindow, gatepos1.y, 2*gatepos1.x, "▦");
        mvwprintw(gameWindow, gatepos2.y, 2*gatepos2.x, "▦");
    }
    drawBorder();
}

void View::drawScoreWindow(Snake snake, Mission mission, int time) {
    scoreWindow = newwin(21, 30, 7, 48);
    wbkgd(scoreWindow, COLOR_PAIR('s'));
    wattron(scoreWindow, COLOR_PAIR('s'));
    for(int i=0; i<15; i++) {
        wprintw(scoreWindow, " ");
        mvwprintw(scoreWindow, 0, 2*i, "🟊");
    }

    //현재 값
    mvwprintw(scoreWindow, 2, 9, "Score Board");

    mvwprintw(scoreWindow, 4, 7, "T  I  M  E  : ");
    mvwprintw(scoreWindow, 4, 21, std::to_string(time).c_str());
    mvwprintw(scoreWindow, 5, 7, "Grow Item   : ");
    mvwprintw(scoreWindow, 5, 21, std::to_string(snake.getGrowCount()).c_str());
    mvwprintw(scoreWindow, 6, 7, "Poison Item : ");
    mvwprintw(scoreWindow, 6, 21, std::to_string(snake.getPoisonCount()).c_str());
    mvwprintw(scoreWindow, 7, 7, "Gate Used   : ");
    mvwprintw(scoreWindow, 7, 21, std::to_string(snake.getGateCount()).c_str());

    //구분선
    for(int i=0; i<15; i++) {
        wprintw(scoreWindow, " ");
        mvwprintw(scoreWindow, 10, 2*i, "🟊");
    }

    //목표값
    mvwprintw(scoreWindow, 12, 11, "Mission");

    mvwprintw(scoreWindow, 14, 7, "T  I  M  E  : ");
    mvwprintw(scoreWindow, 14, 21, std::to_string(mission.getGoalScore()).c_str());
    mvwprintw(scoreWindow, 15, 7, "Grow Item   : ");
    mvwprintw(scoreWindow, 15, 21, std::to_string(mission.getGoalGrow()).c_str());
    mvwprintw(scoreWindow, 16, 7, "Poison Item : ");
    mvwprintw(scoreWindow, 16, 21, std::to_string(mission.getGoalPoison()).c_str());
    mvwprintw(scoreWindow, 17, 7, "Gate Used   : ");
    mvwprintw(scoreWindow, 17, 21, std::to_string(mission.getGoalGate()).c_str());

    //구분선
    for(int i=0; i<15; i++) {
        wprintw(scoreWindow, " ");
        mvwprintw(scoreWindow, 20, 2*i, "🟊");
    }

}

void View::drawBorder() {
    border(0, 0, 0, 0, 0, 0, 0, 0);
}

void View::update()  {
    refresh();
    wrefresh(gameWindow);
    wrefresh(scoreWindow);
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
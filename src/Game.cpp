#include "Game.h"
#include <math.h>
#include <string>


void Game::newGame() {
    view = View();
    level = Level();
    level.createMap();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    cbreak();
    view.drawStartScreen();
    getch();
}

void Game::runGame() {
    while(!isGameClear()) {
        runLevel();
        if(level.getClear()) {
            level.upCurrentLevel();
        }
        else{
            view.drawGameOver();
            break;
        }
        
    }
    if(isGameClear()) {
        view.drawGameClear();
    }
}

void Game::runLevel() {
    srand((unsigned int)time(0));

    Timer levelTimer;
    Timer itemTimer;
    Timer gateTimer;
    Timer tickTimer;
    Timer eraseTimer;
    curMap = level.getCurrentMap();
    curSnake = Snake(curMap);
    gate.clear();
    item.clear();
    view.draw(curMap, curSnake, item, gate);

    levelTimer.startTimer();
    itemTimer.startTimer();
    gateTimer.startTimer();
    tickTimer.startTimer();

    double tick;
    double itemtime;
    double erasetime;
    double gatetime;
    int playtime;

    bool play = true;

    while(!isGameOver() && !isLevelClear()) {

        levelTimer.updateTime();
        itemTimer.updateTime();
        eraseTimer.updateTime();
        gateTimer.updateTime();
        tickTimer.updateTime();

        playtime = levelTimer.getPlayTime();
        tick = tickTimer.getTick();
        itemtime = itemTimer.getTick();
        erasetime = eraseTimer.getTick();
        gatetime = gateTimer.getTick();

        curSnake.setDirection();

        // 스네이크 움직이면서 아이템, 게이트 판단 및 그리기 
        if(tick > 0.4) {
            curSnake.moveSnake();

            if(!isGetItem()) {
                if((erasetime > rand() % 5 + 10) && !item.empty()) {
                    item.erase(item.begin());
                    eraseTimer.startTimer();
                }
            }
            if(isOnGate()) {
                gateTimer.startTimer();
            }
            level.setClear(isLevelClear());
            mvprintw(0, 40, "확인");
            view.draw(curMap, curSnake, item, gate);
            tickTimer.startTimer();
        }

        //아이템 생성
        if(itemtime > rand() % 3 + 4) {
            if(item.size() < 3) {
                Item newitem = Item(curMap, curSnake);
                for(int i=0; i<item.size(); i++) {
                    if(item[i] == newitem) {
                        newitem = Item(curMap, curSnake);
                        i = 0;
                    }
                }
                item.push_back(newitem);
            }
            itemTimer.startTimer();
        }

        //게이트 생성
        if(gatetime > 10) {
            if(gate.size() < 1) {
                Gate newgate = Gate(curMap);
                mvprintw(4, 4, std::to_string(newgate.pos2_udlr[0]).c_str());
                mvprintw(4, 5, std::to_string(newgate.pos2_udlr[1]).c_str());
                mvprintw(4, 6, std::to_string(newgate.pos2_udlr[2]).c_str());
                mvprintw(4, 7, std::to_string(newgate.pos2_udlr[3]).c_str());
                gate.push_back(newgate);
            }
            gateTimer.startTimer();
        }
    }
}

bool Game::isGameClear() {
    if(level.clear[3] == true) {
        return true;
    }
    return false;
}

bool Game::isGameOver() {
    //Snake 키보드 입력 체크
    if(curSnake.isFailed()) return true;
    if(isCollision()) return true;

    return false;
}

bool Game::isCollision() {
    POSITION headpos = curSnake.getPosition()[0];
    int posvalue = curMap.getMapValue(headpos.y, headpos.x);
    if((posvalue == 1) || (posvalue == 2)) {
        if(!gate.empty()) {
            if(headpos == gate[0].getGatePos(1) || headpos == gate[0].getGatePos(2)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Game::isGetItem() {
    POSITION headpos = curSnake.getPosition()[0];
    for(int i=0; i<item.size(); i++) {
        POSITION itempos = item[i].getItemPos();
        if(headpos.x == itempos.x && headpos.y == itempos.y) {
            if(item[i].isGrowItem()) {
                curSnake.eatGrowItem();
            }else {
                curSnake.eatPoisonItem();
            }
            item.erase(item.begin()+i);
            return true;
        }
    }
    return false;
}

bool Game::isOnGate() {
    // 게이트 체크해서 방향 바꾸고 pos 위치 변경
    if(gate.empty()) return false;
    std::vector<POSITION> snakepos = curSnake.getPosition();
    Gate curGate = gate[0];
    //나갈 방향 순서 u=0 d=1 l=2 r=3
    int updirSquence[4] = {0, 3, 2, 1};
    int downdirSquence[4] = {1, 2, 3, 0};
    int leftdirSquence[4] = {2, 0, 1, 3};
    int rightdirSquence[4] = {3, 1, 0, 2};

    int* dirSquence[4] = {updirSquence, downdirSquence, leftdirSquence, rightdirSquence}; 
    char udlr[4] = {'u', 'd', 'l', 'r'};

    //머리좌표 바꾸기
    if(snakepos[0] == gate[0].getGatePos(1)) {
        snakepos[0] = gate[0].getGatePos(2);
        char dir = curSnake.getDirection();
        int diridx;
        //dir 인덱스 지정
        for(int i=0; i<sizeof(udlr); i++) {
            if (dir == udlr[i]) {
                diridx = i;
                break;
            }
        }
        int* squence = dirSquence[diridx];

        char newdir;
        for (int i=0; i<4; i++) {
           if(curGate.getUdlr(2, squence[i]) == 0) {
               newdir = udlr[squence[i]];
               break;
           }
        }
        curSnake.makeDirectionThis(newdir);
        curSnake.setHeadPos(snakepos[0]);
        curSnake.usingGate(snakepos[0]);
    }

    //일단 양쪽 각각 걍 둘다 적어..
    else if(snakepos[0] == gate[0].getGatePos(2)) {
        snakepos[0] = gate[0].getGatePos(1);
        char dir = curSnake.getDirection();
        int diridx;
        //dir 인덱스 지정
        for(int i=0; i<sizeof(udlr); i++) {
            if (dir == udlr[i]) {
                diridx = i;
                break;
            }
        }
        int* squence = dirSquence[diridx];

        char newdir;
        for (int i=0; i<4; i++) {
           if(curGate.getUdlr(1, squence[i]) == 0) {
               newdir = udlr[squence[i]];
               break;
           }
        }
        curSnake.makeDirectionThis(newdir);
        curSnake.setHeadPos(snakepos[0]);
        curSnake.usingGate(snakepos[0]);
    }

    for(int i=0; i<curSnake.getLength(); i++) {
        if (snakepos[i] == curSnake.gatepos) {
            if (i==curSnake.getLength()-1) {
                curSnake.outGate();
                gate.erase(gate.begin());
            }
            return true;
        }
    }
    return false;

}

bool Game::isLevelClear() {
    Mission curmission = level.getMission();
    if(curSnake.getMaxLength() < curmission.getGoalScore()) return false;
    if(curSnake.getGrowCount() < curmission.getGoalGrow()) return false;
    if(curSnake.getPoisonCount() < curmission.getGoalPoison()) return false;
    if(curSnake.getGateCount() < curmission.getGoalGate()) return false;
    return true;
}

// Test
int main() {
    Game game = Game();
    game.newGame();
    game.runGame();
    endwin();
}
#ifndef __VIEW__
#define __VIEW__

#include <ncursesw/ncurses.h>
#include "Constant.h"
#include "Level.h"
#include "Snake.h"
#include "Item.h"

class View {
public:
    WINDOW *gameWindow;
    WINDOW *scoreWindow;

    /* Initialize */
    View();

    /* 게임 시작 화면 */
    void drawStartScreen();

    /* 게임 오버 화면 */
    void drawGameOver();

    /* 게임 클리어 화면 */
    void drawGameClear();

    /* 메인 플레이 화면을 그림 */
    void draw(Map map, Snake snake, std::vector<Item> item);

    /* MainWindow 그리기 */
    void drawMainWindow();

    /* gameWindow 그리기 */
    void drawGameWindow(Map map);

    /* 화면에 Snake 그리기 */
    void drawSnake(Snake snake);

    /* 화면에 Item 그리기 */
    void drawItem(std::vector<Item> item);

    /* 화면에 ScoreBoard 그리기 */
    void drawScoreWindow(Snake snake);

    /* Window Border */
    void drawBorder();

    /* View를 업데이트 */
    void update();    
};

#endif
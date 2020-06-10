#ifndef __VIEW__
#define __VIEW__

#include <ncursesw/ncurses.h>
#include "Level.h"
#include "Snake.h"

class View {
public:
    WINDOW *gameWindow;
    WINDOW *scoreWindow;

    /* Initialize */
    View();

    /* 화면을 그림 */
    void draw(Map map, Snake snake);

    /* MainWindow 그리기 */
    void drawMainWindow();

    /* gameWindow 그리기 */
    void drawGameWindow(Map map);

    /* 화면에 ScoreBoard 그리기 */
    void drawScoreWindow(Snake snake);

    /* Window Border */
    void drawBorder();

    /* View를 업데이트 */
    void update();    
};

#endif
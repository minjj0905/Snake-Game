#ifndef __VIEW__
#define __VIEW__

#include <ncurses.h>

class View {
public:
    WINDOW *gameWin;
    WINDOW *scoreWin;

    /* 생성자 */
    View();

    /* Initialize */
    void Init();

    /* 화면을 그림 */
    // void Draw();

    /* 화면에 Game 그리기 */
    void DrawGame();

    /* 화면에 ScoreBoard 그리기 */
    // void DrawScore();

    /* View를 업데이트 */
    // void Update();    
};

#endif
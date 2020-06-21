#ifndef __SNAKE__
#define __SNAKE__

#include <vector>
#include "Map.h"

struct POSITION {
    int x, y;
    POSITION(int y, int x);
    POSITION();

    bool operator==(POSITION p);
};

class Snake {
public:

    Snake() {};
    Snake(Map& m);

    /*스네이크의 좌표*/
    std::vector<POSITION> snakePos;

    /*grow아이템을 위한 꼬리*/
    std::vector<POSITION> tailPos;

    /*방향*/
    char direction;

    /*grow Item 먹은 횟수*/
    int growCount;

    /*poison Item 먹은 횟수*/
    int poisonCount;

    /* Gate count */
    int gateCount;

    /*Snake의 maxLength저장*/
    int maxLength;

    /*Snake의 currentLength저장*/
    int curLength;

    /*snake의 생사여부*/
    bool fail;

    /*게이트 이용중인지*/
    bool onGate;

    /* 게이트로 순간이동한 좌표*/
    POSITION gatepos;

    /*Snake의 maxLength 갱신*/
    void setMaxLength();

    /*snake의 생사 여부 반환*/
    bool isFailed();

    /*grow Item 을 먹은 횟수 반환*/
    int getGrowCount();

    /*poison Item 먹은 횟수 반환*/
    int getPoisonCount();

    /*Gate 이용 횟수 반환 */
    int getGateCount();

    /*snake의 길이 반환*/
    int getLength();

    /*snake의 maxlength 반환 */
    int getMaxLength();

    /*snake가 죽음*/
    void setFailed();

    /* 게이트 이용중인가요? */
    bool isOnGate();

    /* 게이트 이용한다고 알려주는거*/
    void usingGate(POSITION p);

    /* 게이트 탈출*/
    void outGate();

    /*키를 받고 snake 방향전환함*/
    void setDirection();

    /* 임의로 snake 방향 전환 */
    void makeDirectionThis(char c);

    /* Snake Direction 값*/
    char getDirection();

    /* Snake head pos 지정 */
    void setHeadPos(POSITION p);

    /*snake를 움직임*/
    void moveSnake();

    /* 스네이크 head 위치가 올바른지 확인 */
    void checkCorrectPos();

    /* 스네이크 길이가 3 이상인지 확인 */
    void checkLength();

    /* Snake Position */
    std::vector<POSITION> getPosition();

    /*snake가 grow 아이템먹었을때 길이 증가*/
    void eatGrowItem();

    /*snake가 grow 아이템먹었을때 길이 감소*/
    void eatPoisonItem();

    /*snake의 curLength를 설정*/
    void setCurLength();

    /* GrowCount 올리기 */
    void upGrowCount();
};
#endif
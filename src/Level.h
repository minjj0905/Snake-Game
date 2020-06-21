#ifndef __LEVEL__
#define __LEVEL__

#include "Map.h"
#include "Mission.h"

class Level {
public:
    /*현재 맵의 인덱스*/
    int currentLevel;
    
    /*Map 객체 array*/
    Map maps[4];

    Mission missions[4];

    /* 해당 맵 클리어했는지*/
    bool clear[4];

    /*생성자 currentLevel을 0으로 초기화*/
    Level();

    /*현재 레벨을 가져온다*/
    int getCurrentLevel();

    /*레벨을 1 올린다.*/
    void upCurrentLevel();

    /*레벨에 따른 현재 맵을 가져온다.*/
    Map getCurrentMap();

    /*Map 객체 array에 맵을 넣는다.*/
    void createMap();

    /* 현재 맵 클리어했는지 설정 */
    void setClear(bool b);

    /* 현재 맵 클리어했는지 확인 */
    bool getClear();

    /* 미션 반환 */
    Mission getMission();

};
#endif
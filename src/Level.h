#ifndef __LEVEL__
#define __LEVEL__

#include <iostream>
#include <Map.h>

class Level {
public:
    /*현재 맵의 인덱스*/
    int currentLevel;
    
    /*Map 객체 array*/
    Map* maps;


    /*생성자*/
    Level();

    /*현재 레벨을 가져온다*/
    int getCurrentLevel();

    /*레벨을 1 올린다.*/
    void upCurrentLevel();

    /*레벨에 따른 현재 맵을 가져온다.*/
    Map getCurrentMap();
};
#endif
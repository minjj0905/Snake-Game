#ifndef __Mission__
#define __Mission__

#include <iostream>

class Mission {
public:
    int goal[4];
    std::string missionPath;

    Mission() {};
    Mission(int stage);

    void loadMission();
    int getGoalScore();
    int getGoalGrow();
    int getGoalPoison();
    int getGoalGate();

};
#endif
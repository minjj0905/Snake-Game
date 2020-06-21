#include <fstream>
#include "Mission.h"
#include <string>
using namespace std;

#define MissionDir "../mission/"
#define missionfile "mission"

Mission::Mission(int stage) {
    missionPath = (string)MissionDir + missionfile + to_string(stage) + ".txt";
    loadMission();
}

void Mission::loadMission() {
    ifstream in(missionPath);
    for(int i=0; i<4; i++) {
        in >> goal[i];
    }
}

int Mission::getGoalScore() {
    return goal[0];
}

int Mission::getGoalGrow() {
    return goal[1];
}
int Mission::getGoalPoison() {
    return goal[2];
}
int Mission::getGoalGate() {
    return goal[3];
}
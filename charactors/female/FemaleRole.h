//
// Created by ujun on 2023/12/14.
//

#ifndef CXXNO_SEARVH_FEMALEROLE_H
#define CXXNO_SEARVH_FEMALEROLE_H

#include "../Character.h"
#include <vector>
#include "../Dialogue/DialogueM.h"
enum class emotion{
    HAPPY,
    SAD,
    ANGRY
};

class FemaleRole : Character{
    FemaleRole();


    ~FemaleRole();
private:
    //对话集
    DialogueM dialogueM;
    //好感度
    unsigned int lika;
    //是否是恋人
    bool islover;
    //是否被触发
    bool isActive;
    //当前情绪
    emotion curEmo;

};

#endif //CXXNO_SEARVH_FEMALEROLE_H

//
// Created by ujun on 2023/12/14.
//

#ifndef CXXNO_SEARVH_DIALOGUEM_H
#define CXXNO_SEARVH_DIALOGUEM_H
#include <iostream>
#include <vector>
#include "Dialogue.h"

class DialogueM {
public:

    DialogueM(std::vector<Dialogue> *dias, std::vector<Dialogue> *angrydias, std::vector<Dialogue> *stopdias,
              std::vector<Dialogue> *hDias);

    ~DialogueM();
    //初始化对话集
    void initDialogues();
    //跳转下一跳对话
    void goNextDia();
    //停止对话
    void stopDia();

private:
    std::string greet;
    std::vector<Dialogue> * dialogues;
    std::vector<Dialogue> * angryDias;
    std::vector<Dialogue> * happyDias;
    std::vector<Dialogue> * stopDias;
    Dialogue * curDia;
};


#endif //CXXNO_SEARVH_DIALOGUEM_H

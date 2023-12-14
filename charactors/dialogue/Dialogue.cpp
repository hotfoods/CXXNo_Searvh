//
// Created by ujun on 2023/12/14.
//

#include "Dialogue.h"

typedef struct answer{
    std::string answer;
    Dialogue * next;
    int weight;
}Answer;

//std::vector<answer> Dialogue::getAnswers(){
//
//}
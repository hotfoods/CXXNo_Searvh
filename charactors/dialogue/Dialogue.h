//
// Created by ujun on 2023/12/14.
//

#ifndef CXXNO_SEARVH_DIALOGUE_H
#define CXXNO_SEARVH_DIALOGUE_H
#include <iostream>
#include <vector>

class Dialogue {
public:
    struct answer;
    Dialogue();
    ~Dialogue();

    std::string  getDia(){
        return this->dia;
    }

    std::vector<answer> * getAnswers(){
        return this->answers;
    }
    int getAnswerSize(){
        return this->aSize;
    }
private:
//    struct dia;
//    struct answer;
    std::string dia;
    std::vector<answer> * answers;
    int weight;
    int aSize;
};


#endif //CXXNO_SEARVH_DIALOGUE_H

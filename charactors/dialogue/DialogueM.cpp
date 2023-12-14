//
// Created by ujun on 2023/12/14.
//

#include "DialogueM.h"

DialogueM::DialogueM(std::vector<Dialogue> * dias,
                     std::vector<Dialogue> * angrydias,
                     std::vector<Dialogue> * stopdias,
                     std::vector<Dialogue> * hDias) {
    this->angryDias=angrydias;
    this->stopDias=stopdias;
    this->happyDias=hDias;
    this->dialogues=dias;
    this->curDia=&dias->front();
}

void DialogueM::goNextDia() {
    std::cout<< this->curDia->getDia()<<std::endl;
    std::vector<Dialogue::answer> *aws= this->curDia->getAnswers();
    std::cout<<"选项:";
    for (int i = 0; i < this->curDia->getAnswerSize(); ++i) {
        std::cout<<i+1<<" : "<<&aws[i]<<std::endl;
    }
    int chose;
    std::cin>>chose;
//    auto ans = &aws[chose];
//    Dialogue nextDia=ans.
}

void DialogueM::stopDia() {

}


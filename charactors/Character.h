//
// Created by ujun on 2023/12/14.
//

#ifndef CXXNO_SEARVH_CHARACTER_H
#define CXXNO_SEARVH_CHARACTER_H
#include <iostream>

class Character {
public:
    void setName(std::string name){
        this->name=name;
    }
    void setAge(int age){
        this->age=age;
    }
    void setSex(char sex){
        this->sex=sex;
    }
    void setImgUrl(std::string imgUrl){
        this->imgUrl=imgUrl;
    }


private:
    std::string name;
    int age;
    char sex;
    std::string imgUrl;

};


#endif //CXXNO_SEARVH_CHARACTER_H

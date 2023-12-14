//
// Created by ujun on 2023/12/12.
//

#ifndef CXXNO_SEARVH_OBJECT_H
#define CXXNO_SEARVH_OBJECT_H

#include <iostream>
enum class ObjectType{
    OBJ_INT,
    OBJ_PAIR
};

class Object{
public:

    ObjectType type;
    unsigned char marked;

    struct Object * next;

    union{
        int value;

        struct{
            Object * head;
            Object * tail;
        };
    };


    void static objectPrint(Object * object);


private:
};
#endif //CXXNO_SEARVH_OBJECT_H

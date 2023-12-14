//
// Created by ujun on 2023/12/12.
//

#include "Object.h"

void Object::objectPrint(Object *object) {
    switch (object->type) {
        case ObjectType::OBJ_INT:
            std::cout<<object->value<<std::endl;
            break;
        case ObjectType::OBJ_PAIR:
            std::cout<<"(";
            Object::objectPrint(object->head);
            std::cout<<",";
            Object::objectPrint(object->tail);
            std::cout<<")";
            break;
    }
}


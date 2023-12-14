//
// Created by ujun on 2023/12/12.
//

#ifndef CXXNO_SEARVH_VM_H
#define CXXNO_SEARVH_VM_H
#include <iostream>
#include "Object.h"
#define STACK_MAX 256
#define INITIAL_GC_THRESHOLD 8


class VM {
public:
    Object *stack[STACK_MAX]{};
    int stackSize;

    Object *firstObject;

    int numObjects;

    int maxObjects;

    VM();

    ~VM();

    void  static assert(int condition,const char *message);

    void push(Object * value);

    Object * pop();

    void mark(Object * object);

    void  markAll();

    void sweep();

    void gc();

    Object * newObject(ObjectType type);

    void pushInt(int intValue);

    Object * pushPair();

    void freeVM();
};


#endif //CXXNO_SEARVH_VM_H

//
// Created by ujun on 2023/12/12.
//

#include "VM.h"

VM::VM() {
    std::cout<<"vm started"<<std::endl;
    this->stackSize=0;
    this->firstObject= nullptr;
    this->numObjects=0;
    this->maxObjects=INITIAL_GC_THRESHOLD;
}

VM::~VM(){
    std::cout<<"all objects cleaned,vm closed";
}

void VM::assert(int condition, const char *message) {
    if (!condition){
        std::cout<<message<<std::endl;
        exit(1);
    }
}

void VM::push(Object *value) {
    //栈溢出
    assert(this->stackSize<STACK_MAX,"Stack overflow");
    this->stack[this->stackSize++]=value;
}

Object * VM::pop() {
    assert(this->stackSize>0,"Stack underflow");
    return this->stack[--this->stackSize];
}

Object * VM::newObject(ObjectType type) {
    if (this->numObjects== this->maxObjects)
        gc();
    auto * object = new Object();
    object->type=type;
    object->next= this->firstObject;
    this->firstObject=object;
    object->marked=0;

    this->numObjects++;
    return object;
}


void VM::pushInt(int intValue) {
    Object * object = newObject(ObjectType::OBJ_INT);
    object->value=intValue;
    push(object);
}

Object * VM::pushPair() {
    Object * object = newObject(ObjectType::OBJ_PAIR);
    object->tail=pop();
    object->head=pop();
    push(object);
    return object;
}

/**
 * 清除阶段
 */
void VM::mark(Object *object) {
    if (object->marked)
        return;
    object->marked=1;
    if (object->type==ObjectType::OBJ_PAIR){
        mark(object->head);
        mark(object->tail);
    }
}

void VM::markAll() {
    for(int i=0;i<this->stackSize;i++){
        mark(this->stack[i]);
    }
}

void VM::sweep() {
    Object **pObject=&this->firstObject;
    while (*pObject){
        if (!(*pObject)->marked){
            Object * unreached=*pObject;
            *pObject=unreached->next;
            delete(unreached);

            this->numObjects--;
        } else{
            (*pObject)->marked=0;
            pObject=&(*pObject)->next;
        }
    }
}


void VM::gc(){
    int  i_numObjects= this->numObjects;

    markAll();
    sweep();

    this->maxObjects=this->numObjects==0?INITIAL_GC_THRESHOLD: this->numObjects*2;

    std::cout<<"Collected objects remaining"<<i_numObjects-this->numObjects<<" "<<this->numObjects;
}

void VM::freeVM() {
    this->stackSize=0;
    gc();
}
















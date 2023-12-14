#include <iostream>
#include "VM.h"
using namespace  std;

void test1(){
    cout<<"Test 1:Objects on stack are preserved\n"<<endl;
    auto vm =new VM();
    vm->pushInt(1);
    vm->pushInt(2);
}

int main() {
    std::cout << "Hello, World!" << std::endl;


    std::cout<<"this system is for reclaim the unuseable class."<<std::endl;
    return 0;
}

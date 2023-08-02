#include <stdio.h>
#include <stdint.h>
#include "chunk.h"
#include "common.h"
#include "value.h"
#include "vm.h"

VM vm;

void initVM(){

}

void freeVM(){

}

static IntrepretResult run(){
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    for(;;){
        uint8_t instuction;
        switch (instuction = READ_BYTE()) {
            case OP_RETURN:
                return INTERPRET_OK;
            case OP_CONSTANT:{
                                 Value constant = READ_CONSTANT();
                                 printValue(constant);
                                 printf("\n");
                                 break;
                             }
        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
}

IntrepretResult interpret(Chunk *chunk){
    vm.chunk = chunk;
    vm.ip = chunk->code;
    return run();
}

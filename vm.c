#include <stdio.h>
#include <stdint.h>
#include "chunk.h"
#include "common.h"
#include "value.h"
#include "debug.h"
#include "vm.h"

VM vm;

static void resetStack() {
    vm.stacktop = vm.stack;
}

void initVM(){
    resetStack();
}

void freeVM(){

}

void push(Value value){
    *vm.stacktop = value;
    vm.stacktop++ ;
}

Value pop(){
    vm.stacktop--;
    return *vm.stacktop;
}

static IntrepretResult run(){
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op) \
    do { \
        double b = pop(); \
        double a = pop(); \
        push(a op b); \
    } while (false)

    for(;;){
#ifdef DEBUG_TRACE_EXECUTION
        printf("       ");
        for(Value* slot = vm.stack; slot < vm.stacktop;slot++){
            printf("[");
            printValue(*slot);
            printf("]");
        }
        printf("\n");
        disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
        uint8_t instuction;
        switch (instuction = READ_BYTE()) {
            case OP_RETURN:{
                               printValue(pop());
                               printf("\n");
                               return INTERPRET_OK;
                           }
            case OP_CONSTANT:{
                                 Value constant = READ_CONSTANT();
                                 push(constant);
                                 break;
                             }
            case OP_NEGATE: {
                                push(-(pop()));
                                break;
                            }
            case OP_ADD:        BINARY_OP(+); break;
            case OP_SUBTRACT:   BINARY_OP(-); break;
            case OP_MULTIPLY:   BINARY_OP(*); break;
            case OP_DIVIDE:     BINARY_OP(/); break;
        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
}

IntrepretResult interpret(Chunk *chunk){
    vm.chunk = chunk;
    vm.ip = chunk->code;
    return run();
}

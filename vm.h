#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include <stdint.h>

typedef struct{
    Chunk* chunk;
    uint8_t* ip;
} VM;

typedef enum{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} IntrepretResult;

void initVM();
void freeVM();
IntrepretResult interpret(Chunk* chunk);

#endif

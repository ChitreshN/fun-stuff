#include <stdio.h>
#include <stdlib.h>
#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char* argv[]){
    initVM();
    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);

    writeChunk(&chunk, OP_CONSTANT,123);
    writeChunk(&chunk, constant,123);
    writeChunk(&chunk, OP_RETURN,123);

    disassembleChunk(&chunk,"test chunk");
    interpret(&chunk);

    freeChunk(&chunk);
    freeVM();

    return EXIT_SUCCESS;
}

#include "chunk.h"
#include "common.h"
#include "debug.h"
#include <stdlib.h>

int main(int argc, char* argv[]){
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk,"test chunk");
    freeChunk(&chunk);
    return 0;
}

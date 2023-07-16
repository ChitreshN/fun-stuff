#include <stdlib.h>
#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk* chunk){
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk* chunk,uint8_t byte){
    if(chunk->capacity < chunk->count + 1){
        int oldcap = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldcap);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldcap, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}

void freeChunk(Chunk *chunk){
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

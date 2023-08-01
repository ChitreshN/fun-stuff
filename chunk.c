#include <stdlib.h>
#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk* chunk){
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk* chunk,uint8_t byte,int line){
    if(chunk->capacity < chunk->count + 1){
        int oldcap = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldcap);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldcap, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldcap, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

void freeChunk(Chunk *chunk){
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

int addConstant(Chunk* chunk, Value value) {
  WriteValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}

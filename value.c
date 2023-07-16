#include <stdio.h>
#include "value.h"
#include "memory.h"

void initValueArray(ValueArray *array){
   array->values = NULL;
   array->capacity = 0;
   array->count = 0;
}

void WriteValueArray(ValueArray *array, Value value){
    if (array->capacity < array->count + 1){
        int oldcap = array->capacity;
        array->capacity = GROW_CAPACITY(oldcap);
        array->values = GROW_ARRAY(Value, array, oldcap, array->capacity);
    }

    array->values[array->count] = value;
    array->count++;
}

void freeValueArray(ValueArray *array){
    FREE_ARRAY(Value, array, array->capacity);
    initValueArray(array);
}

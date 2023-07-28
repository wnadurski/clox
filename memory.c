//
// Created by hyster on 6/20/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "memory.h"
#include "vm.h"
#include "object.h"

void *reallocate(void *pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void *result = realloc(pointer, newSize);
    if (result == NULL) exit(1);

    return result;
}

static void freeObject(Obj *obj) {
    switch (obj->type) {
        case OBJ_STRING: {
            ObjString *string = (ObjString *) obj;
            FREE_ARRAY(char, string->chars, string->length + 1);
            FREE(ObjString, obj);
            break;
        }
    }
}

void freeObjects() {
    Obj *object = vm.objects;

    while (object != NULL) {
        Obj *next = object->next;

        freeObject(object);

        object = next;
    }
}

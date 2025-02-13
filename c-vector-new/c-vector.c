#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct {
    uint elem; // element number
    uint size; // size of array in bytes
    void* buf[];
} vector;

void vector_init(vector* v) {
    *v->buf = malloc(0);
    v->elem = -1;
    v->size = 0;
}
void vector_realloc(vector * v, uint size) {
    v->size += size;
    realloc(*v->buf, v->size);
    
}
void vector_push(vector *v, void* element, uint size) {
    vector_realloc(v, size);
    v->elem++;
    v->buf[v->elem] = element;
}
void vector_pop() {}

void vector_free(vector* v) {
    free(*v->buf);
}


int main() {
    // demonstration
    vector v;
    vector_init(&v);
    vector_push(&v, (void*)1, sizeof(1)); // int vector
    //vector_push(&v, (void*)2, sizeof(2));
    //vector_push(&v, (void*)3, sizeof(3));

    for (uint i=0;i < v.elem; i++) {
        int num = *(int*)v.buf[i];
        printf("Vector elements: %d\n", num);
    }
    printf("Vector element number: %u\n", v.elem);
    printf("Vector size: %u\n", v.size);

    vector_free(&v);
    printf("Size after free: %d\n", v.size);
}

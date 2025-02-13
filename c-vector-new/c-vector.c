#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct {
    uint elem; // element number
    uint size; // size of array in bytes
    void** buf;
} vector;

void vector_init(vector* v) {
    v->buf = malloc(0);
    v->elem = 0;
    v->size = 0;
}
void vector_realloc(vector * v, uint size) {
    v->size += size;
    
    void* temp = realloc(v->buf, v->size);
        if (temp != NULL) {
        v->buf = temp;
    } else {
        printf("Mem realloc failed!\n");
        exit(1);
    }
    
}
void vector_push(vector *v, void* element, uint size) {
    vector_realloc(v, sizeof(void*));
    
    v->buf[v->elem] = malloc(size);
    
    memcpy(v->buf[v->elem], element, size);
    v->elem++;
}
void vector_pop(vector *v, uint size) {
    free(v->buf[v->elem -1]);
    v->elem--;
    v->size -= size;
}

void vector_free(vector* v) {
    for (uint i=0;i<v->elem;i++) {
        free(v->buf[i]);
    }
    free(v->buf);
    v->size = 0;
    v->elem = 0;
}


int main() {
    // demonstration
    vector v;
    int a = 1; int b = 2; int c = 3;
    vector_init(&v);
    vector_push(&v, (void*)&a, sizeof(a)); // int vector
    vector_push(&v, (void*)&b, sizeof(b));
    vector_push(&v, (void*)&c, sizeof(c));


    printf("Vector element number: %u\n", v.elem);
    printf("Vector size: %u\n", v.size);
    for (uint i=0;i < v.elem; i++) {
        int num = *(int*)v.buf[i];
        printf("Vector elements: %d, size: %ld\n", num, sizeof(v.buf[i]));
    }
    
    vector_pop(&v, sizeof(*(int*)v.buf[v.elem]));
    for (uint i=0;i < v.elem; i++) {
        int num = *(int*)v.buf[i];
        printf("Vec elements after pop: %d\n", num);
    }

    
    vector_free(&v);
    printf("Size after free: %d\n", v.size);
}

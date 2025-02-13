#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "c-vector.h"

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

void vector_free(vector* v) {
    for (uint i=0;i<v->elem;i++) {
        free(v->buf[i]);
    }
    free(v->buf);
    v->size = 0;
    v->elem = 0;
}

void vector_push_back(vector *v, void* element, uint size) {
    if (v->size == v->elem * sizeof(void*)) {
        vector_realloc(v, sizeof(void*));
    }
    v->buf[v->elem] = malloc(size);
    
    memcpy(v->buf[v->elem], element, size);
    v->elem++;
}

void vector_push_index(vector *v, void* element, uint size, uint index, uint shift) {
    void* temp = realloc(v->buf[index], size);
    if (temp != NULL) {
        v->buf[index] = temp;
    } else {
        printf("Mem realloc failed!\n");
        exit(1);
    }
    // we are not shifting
    if (shift == 0) {
        // realloc memory for the index
        // TODO HERE
        memcpy(v->buf[index], element, size);
    } else if (shift == 1) { // we are shifting elements to the right before inserting at index
        // adding spot for another element
        if (v->size == v->elem * sizeof(void*)) {
            vector_realloc(v, sizeof(void*));
        }
        // shifting elements to the right
        v->buf[v->elem] = malloc(size);// allocate memory for the spot we created at the end of vector
        for (int i=index; i < v->elem -1; i++) {
            // realloc memory for each part of the vector depending on what we will insert
            memcpy(v->buf[i+1], v->buf[i], sizeof(v->buf[i]));   
        }
        // inserting element at index

        v->elem++;
    }
}

void vector_pop_back(vector *v) {
    free(v->buf[v->elem -1]);
    v->elem--;
    v->size -= sizeof(void*);
}

int main() {
    // demonstration

    // init
    vector v;
    int a = 1; int b = 2;
    vector_init(&v);

    // push back
    vector_push_back(&v, (void*)&a, sizeof(a)); // int vector
    vector_push_back(&v, (void*)&b, sizeof(b));
    puts("Push back:\n");
    for (uint i=0; i < v.elem;i++) {
        int num = *(int*)v.buf[i];
        printf("The elements: %d\n", num);
    }
    // push index
    vector_push_index(&v, (void*)&a, sizeof(a), 1, 0);
    puts("Push index:\n");
    for (uint i=0; i < v.elem;i++) {
        int num = *(int*)v.buf[i];
        printf("The elements: %d\n", num);
    }

    // pop_back

    // pop_index


    vector_free(&v);
}

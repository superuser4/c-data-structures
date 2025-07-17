#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "c-vector.h"

void vector_init(vector* v, uint32_t size) {
    v->elem = 0;
    v->size = 0;
    v->type = size;
    v->buf = malloc(0);
}

void vector_realloc(vector * v, uint32_t size) {
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
    // check if buf[i] is already freed
    for (uint32_t i=0; i<v->elem; i++) {
        if (v->buf[i] != NULL) {free(v->buf[i]);}
    }
    free(v->buf);
    v->size = 0;
    v->elem = 0;
}

void vector_push_back(vector *v, void* element, uint32_t size) {
    if (v->size == v->elem * sizeof(void*)) {
        vector_realloc(v, sizeof(void*));
    }
    v->buf[v->elem] = malloc(size);
    
    memcpy(v->buf[v->elem], element, size);
    v->elem++;
}

void vector_push_index(vector *v, void* element, uint32_t size, uint32_t index, int shift) {
    void* temp = realloc(v->buf[index], size);
    if (temp == NULL) {
        fprintf(stderr, "realloc failure!\n");
        exit(1);
    }
    v->buf[index] = temp;
    
    if (shift == 0) {
        memcpy(v->buf[index], element, size);
    } else {
        if (v->size == v->elem * sizeof(void*)) {
            vector_realloc(v, sizeof(void*));
        }
        
        v->buf[v->elem] = malloc(size);
        for (uint32_t i=v->elem; i > index; i--) {
            if (v->type == 1) {
                size_t new_size = strlen((char*)v->buf[i-1]) + 1;
                void* tmp = realloc(v->buf[i], new_size);
                if (tmp == NULL) {
                    fprintf(stderr, "Memory allocation failed!\n");
                    exit(1);
                }
                v->buf[i] = tmp;
                strncpy(v->buf[i], v->buf[i-1], new_size);
            } else {
                memcpy(v->buf[i],v->buf[i-1], v->type);
            }
        }
        memcpy(v->buf[index], element, size);
        v->elem++;
    } 
    
}

void vector_pop_back(vector *v) {
    free(v->buf[v->elem -1]);
    v->elem--;
    v->size -= sizeof(void*);
}

void vector_pop_index(vector *v, uint32_t index) {
    if (v->size == v->elem * sizeof(void*)) {
        int x = (sizeof(void*));
        vector_realloc(v, -x);
    }

    for (uint32_t i=index; i < v->elem; i++) {
        if (v->type == 1) {
            size_t new_size = strlen((char*)v->buf[i+1]) + 1;
            void* tmp = realloc(v->buf[i], new_size);
            if (tmp == NULL) {
                fprintf(stderr, "Memory allocation failed!\n");
                exit(1);
            }
            v->buf[i] = tmp;
            strncpy(v->buf[i], v->buf[i+1], new_size);
        } else { 
            memcpy(v->buf[i], v->buf[i+1], v->type);
        }
    }
    free(v->buf[v->elem-1]);
    v->buf[v->elem-1] = NULL;
    v->elem--;
    v->size -= sizeof(void*);
}

void vector_pop_all(vector *v) {
    while (v->elem > 0) {
        vector_pop_back(v);
    }
}

#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "c-vector.h"

void vector_init(vector* v, uint size) {
    v->elem = 0;
    v->size = 0;
    v->type = size;
    v->buf = malloc(0);
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
    if (temp == NULL) {
        fprintf(stderr, "realloc failure!\n");
        exit(1);
    }
    v->buf[index] = temp;
    
    if (shift == 0) {
        memcpy(v->buf[index], element, size);

    } else if (shift == 1) {
        
        if (v->size == v->elem * sizeof(void*)) {
            vector_realloc(v, sizeof(void*));
        }
        
        v->buf[v->elem] = malloc(size);
        for (uint i=v->elem; i > index; i--) {
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

int main() {
    // demonstration


    // Integers
    // init
    vector v;
    int a = 1; int b = 2;
    vector_init(&v, sizeof(a));

    // push back
    vector_push_back(&v, (void*)&a, sizeof(a)); // int vector
    vector_push_back(&v, (void*)&b, sizeof(b));
    puts("Push back:\n");
    for (uint i=0; i < v.elem;i++) {
        int num = *(int*)v.buf[i];
        printf("The elements: %d\n", num);
    }
    // push index
    int x = 5;
    vector_push_index(&v, (void*)&x, sizeof(x), 0, 1);
    puts("Push index:\n");
    for (uint i=0; i < v.elem;i++) {
        int num = *(int*)v.buf[i];
        printf("The elements: %d\n", num);
    }

    // pop_back
    // pop_index
    vector_free(&v);
    puts("");
    // Strings / chars
    char mychar[20] = "Hello world";
    char mychar2[20] = "Whatups";
    char mychair[20] = "I was added in!";
    vector s;
    vector_init(&s, sizeof(char));
    vector_push_back(&s, (void*)&mychar, sizeof(mychar));
    vector_push_back(&s, (void*)&mychar2, sizeof(mychar2));
    
    puts("Pushback:");
    for (uint i=0;i < s.elem; i++) {
        char *e = (char*)v.buf[i];
        printf("Elements: %s\n", e);
    }

    puts("Pushback index:");
    vector_push_index(&s, (void*)&mychair, sizeof(mychair), 0, 1);
    for (uint i=0;i < s.elem; i++) {
        char *e = (char*)v.buf[i];
        printf("Elements: %s\n", e);
    }

    vector_free(&s);
}

#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "c-vector.h"

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
    puts("Push back:");
    for (uint i=0; i < v.elem;i++) {
        int num = *(int*)v.buf[i];
        printf("The elements: %d\n", num);
    }
    puts("");
    // push index
    int x = 5;
    vector_push_index(&v, (void*)&x, sizeof(x), 0, 1);
    puts("Push index:");
    for (uint i=0; i < v.elem;i++) {
        int num = *(int*)v.buf[i];
        printf("The elements: %d\n", num);
    }

    // pop_back
    puts("");
    printf("Pop back\n");
    vector_pop_back(&v);
    for (uint i=0; i < v.elem;i++) {
        int num = *(int*)v.buf[i];
        printf("The elements: %d\n", num);
    }

    // pop_index
    puts("");
    printf("Pop index\n");
    vector_pop_index(&v, 0);
    for (uint i=0; i < v.elem;i++) {
        int num = *(int*)v.buf[i];
        printf("The elements: %d\n", num);
    }

    vector_free(&v);
    puts("");
    
    
    // Strings / chars
    // init
    char mychar[20] = "Hello world";
    char mychar2[20] = "Whatups";
    char mychair[20] = "I was added in!";
    vector s;
    vector_init(&s, sizeof(char));
    
    // push back
    vector_push_back(&s, (void*)&mychar, sizeof(mychar));
    vector_push_back(&s, (void*)&mychar2, sizeof(mychar2));
    
    puts("Push back:");
    for (uint i=0;i < s.elem; i++) {
        char *e = (char*)s.buf[i];
        printf("Elements: %s\n", e);
    }
    puts("");
    // pushback index
    puts("Push index:");
    vector_push_index(&s, (void*)&mychair, sizeof(mychair), 0, 1);
    for (uint i=0;i < s.elem; i++) {
        char *e = (char*)s.buf[i];
        printf("Elements: %s\n", e);
    }

    // pop_back
    puts("");
    printf("Pop back\n");
    vector_pop_back(&s);
    for (uint i=0; i < s.elem;i++) {
        char *e = (char*)s.buf[i];
        printf("The elements: %s\n", e);
    }

    // pop_index
    puts("");
    printf("Pop index\n");
    vector_pop_index(&s, 0);
    for (uint i=0; i < s.elem;i++) {
        char *e = (char*)s.buf[i];
        printf("The elements: %s\n", e);
    }

    vector_free(&s);
}
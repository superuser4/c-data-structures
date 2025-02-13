typedef struct {
    uint elem; // element number
    uint size; // size of array in bytes
    void** buf;
} vector;

void vector_init(vector* v);
void vector_realloc(vector * v, uint size);
void vector_push(vector *v, void* element, uint size);
void vector_pop(vector *v);
void vector_free(vector* v);
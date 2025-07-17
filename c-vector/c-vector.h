typedef struct {
    uint32_t elem; // element number
    uint32_t size; // size of array in bytes
    uint32_t type; // type of data stored, only used for char which is 1
    void** buf;
} vector;

void vector_init(vector *v, uint32_t size);
void vector_realloc(vector *v, uint32_t size);
void vector_push_back(vector *v, void* element, uint32_t size);
void vector_pop_back(vector *v);
void vector_free(vector *v);
void vector_push_index(vector *v, void* element, uint32_t size, uint32_t index, int shift); // add an element at a given index. (shift elements depending on parameter) // only shift if shift == 1
void vector_pop_index(vector *v, uint32_t index);  //remove an element at a given index. (shift elements to the left and fill the gap)


// todo
//vector_resize - Preallocate memory for the vector (resize upfront).
//vector_clear - Remove all elements from the vector (but keep memory allocated).
//vector_shrink - Shrink the vector's memory to fit the current number of elements.
//vector_contains - Check if a specific element exists in the vector. and return its index(s)
//vector_copy - Create a copy of the vector (deep copy of elements).
//vector_reverse - Reverse the order of elements in the vector.
//vector_sort - Sort the vector's elements (you could implement sorting with a comparison function).
//vector_swap - Swap two elements at specific indices.
//vector_merge - Merge another vector into this one.

typedef struct {
    uint elem; // element number
    uint size; // size of array in bytes
    void** buf;
} vector;

void vector_init(vector* v);
void vector_realloc(vector * v, uint size);
void vector_push_back(vector *v, void* element, uint size);
void vector_pop_back(vector *v);
void vector_free(vector* v);

// todo
//vector_push_index - add an element at a given index. (don't shift elements)
//vector_pop_index - remove an element at a given index. (don't shift elements)
//vector_push_index_shift - Insert an element at a specified index (shift elements to the right).
//vector_pop_index_shift- Remove an element from a specific index (shift elements to the right).

//vector_resize - Preallocate memory for the vector (resize upfront).
//vector_clear - Remove all elements from the vector (but keep memory allocated).
//vector_shrink - Shrink the vector's memory to fit the current number of elements.
//vector_contains - Check if a specific element exists in the vector. and return its index(s)
//vector_copy - Create a copy of the vector (deep copy of elements).
//vector_reverse - Reverse the order of elements in the vector.
//vector_sort - Sort the vector's elements (you could implement sorting with a comparison function).
//vector_swap - Swap two elements at specific indices.
//vector_merge - Merge another vector into this one.
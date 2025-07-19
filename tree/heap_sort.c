#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void buildHeap(int a[], int);
void heapSort(int a[], int);
void heapify(int a[], int, int);


int partition(int a[], int p, int q) {
    int i = p - 1;
    int j = q + 1;
    int x = a[p];
    int flag = 1;

    while (flag) {
        do {
            i = i + 1;
        } while (a[i] < x);

        do {
            j = j - 1;
        } while (a[j] > x);

        if (i < j) {
            // Exchange a[i] and a[j]
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            flag = 0;
        }
    }

    return j;
}

void quickSort(int a[], int p, int q) {
    if (p < q) {
        int j = partition(a, p, q);
        quickSort(a, p, j);
        quickSort(a, j + 1, q);
    }
}


int main(void) {
    int listSize;
    printf("Enter list size: ");
    scanf("%d", &listSize);
    int *list = malloc((listSize +1) * sizeof(int));
    int *list1 = malloc((listSize + 1) *sizeof(int));
    memcpy(list1, list, (listSize +1) * sizeof(int));

    // Populate array with random integer values
    if (listSize < 1000)
    	printf("Array generated: \n");
    
    srand(time(NULL));
    for (int i=0; i < listSize; i++ ) {
	list[i] = rand() % (65 + 1 - 0) - 0;
	if (listSize < 1000) 
		printf(" %d ", list[i]);
    }
    printf("\n");

    clock_t begin1 = clock();
    heapSort(list1, listSize);
    clock_t end1 = clock();
    double time_spent1 = (double) (end1 - begin1) / CLOCKS_PER_SEC;

    clock_t begin = clock();
    quickSort(list, 0, listSize);
    clock_t end =clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    if (listSize <= 50) {
    	printf("Heap sorted array: \n");
    	for (int i=0; i < listSize; i++ ) {
    	        printf(" %d ", list[i]);
    	}
    	printf("\n");
    }

    printf("Heapsort time: %lf\n", time_spent1);
    printf("Quicksort time: %lf\n", time_spent);
}
void buildHeap(int a[], int n) {
	int i=n/2 -1;
	while (i >= 0) {
		heapify(a, i, n-1);
		i--;
	}
}

void heapSort(int a[], int n) {
	buildHeap(a, n);
	int i=n-1;
	while (i > 0) {	
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;

		i--;
		heapify(a, 0 , i);
	}
}

// Heapify the elements in the index range i to j
// Following the pseudocode given in the slides
void heapify(int a[], int i, int j) {
    if (i > j) {
	    return;
    }
    // Important note: children of a node with index i have indices 2i+1 and 2i+2
    // Since array indices start at 0
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int parent = i;

    int bigger = parent;
    if (left <= j && a[left] > a[bigger])
        bigger = left;
    if (right <= j && a[right] > a[bigger])
        bigger = right;

    if (bigger != parent) {
        int temp = a[parent];
        a[parent] = a[bigger];
        a[bigger] = temp;
        heapify(a, bigger, j);
    }
}

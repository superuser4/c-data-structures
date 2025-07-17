#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void quickSort(int list[], int, int);
void insertionSort(int list[], int);
int partition(int list[], int, int);

int main(void) {
    // Capture size
    srand(time(NULL)); 
    int size = 0;
    printf("Enter list size: ");
    scanf("%d", &size);


    // Generated both arrays
    int *arr = malloc(size * sizeof(int));
    for (int i=0; i < size; i++) {
	arr[i] = rand() % 131 - 65;
    }
    int *arr2 = malloc(size * sizeof(int));
    memcpy(arr2, arr, size*sizeof(int));
   
    // Print maybe
    if (size <= 100) {
    	    printf("Array before sorting: \n");
	    for (int i=0; i < size; i++) {
		    printf(" %d ", arr[i]);
	    }
	    printf("\n");
    }

    // perform sorting
    clock_t begin = clock();
    quickSort(arr, 0, size - 1);
    clock_t end =clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    clock_t begin1 = clock();
    insertionSort(arr2, size);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

    // Print maybe
    if (size <= 100) {
	    printf("Sorted array 1 (quick sort): \n");
	    for (int i=0; i < size; i++) {
		    printf(" %d ", arr[i]);
	    }
	    printf("\n");

	    printf("Sorted array 2 (insertion sort): \n");
	    for (int i=0; i < size; i++) {
		    printf(" %d ", arr2[i]);
	    }
	    printf("\n");
    } else if (size >= 100000) {
	    printf("Runtime for quiksort: %lf\n", time_spent);
	    printf("Runtime for insertionsort: %lf\n", time_spent1);
    }

     // free memry
     free(arr);
     free(arr2);
     return 0;
}

void insertionSort(int a[], int listSize) {
	for (int i=1 ; i < listSize; i++ ) {
		int key = a[i];
		int j;

		for (j=i-1 ; j >= 0; j-- ) {
			if (a[j] > key) {
				a[j+1] = a[j];
			} else {
				break;
			}
		}
		a[j+1] = key;
	}
}

void quickSort(int a[], int p, int q) {
    if (p < q) {
        int j = partition(a, p, q);
        quickSort(a, p, j);
        quickSort(a, j + 1, q);
    }
}

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

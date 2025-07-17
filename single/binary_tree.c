#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// returns -1 if not found, else returns index where key was found.
int binSearch(int arr[], int key, int size) {
	int left = 0;
	int right = size -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		if (arr[mid] < key) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}

int main(void) {
	int size = 0;
	printf("Enter size of array: ");
	scanf("%d", &size);
	int *list = malloc(size * sizeof(int));
	
	srand(time(NULL));
	int sign = (rand() % 2 ) ? 1 : -1;
	list[0] = sign * (rand() % 50);
	for (int i=1; i < size; i++ ) {
		int num = 1 + rand() % 10;
		list[i] = list[i-1] + num;
	}

	printf("Original array: \n");
	for (int i=0; i <size; i++ ) {
		printf(" %d ", list[i]);
	}
	printf("\n");
	
	printf("Bin array: \n");
	int *binarr = malloc(size * sizeof(int));
	for (int i=0; i < size ; i++ ) {
		binarr[i] = list[i] - i;
		printf(" %d ", binarr[i]);
	}
	printf("\n");

	int idx = binSearch(binarr, 0, size);
	if (idx >=0) {
		printf("Found value 0 at index: %d\n", idx);
	} else {
		printf("No index with value 0 was found\n");
	}
	free(list);
	free(binarr);
}

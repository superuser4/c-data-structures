#include <iostream>


int main() {
	//int arr[] = {-1,2,3,-6,7,8,-9,10,-11,6,4};
	int arr[] = {-1,3,7,-1,4,-11,3,7,-10};

	int best_sum = arr[0];
	int current_sum = arr[0];
	int start = 0;
	int end = 0;

	int len = sizeof(arr)/ sizeof(int);
	for (int i=1; i < len; i++) {	
		// If adding new element i in the array to current_sum results in negative number, restart fresh from i
		if (current_sum + arr[i] < arr[i]) {
			current_sum = arr[i];
			start = i;
		// if not then keep adding
		} else {
			current_sum += arr[i];
		}
		// if current_sum is greater then best sum, assign it and update end
		if (current_sum > best_sum) {
			best_sum = current_sum;
			end = i;
		}
	}

	std::cout << "Max Sum: " << best_sum << std::endl;
	std::cout << "Start Index: " << start << std::endl;
	std::cout << "End Index: " << end << std::endl;
}

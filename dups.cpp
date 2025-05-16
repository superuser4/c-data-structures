#include <iostream>
#include <map>

int main() {
	int arr[] = {1, 2, 3, 2, 3, 3, 4, 6, 9, 6};
	std::map<int, int> dups;
	bool repeated = false;

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		++dups[arr[i]]; // increment whether or not it exists
	}

	// print out the hashmap
	for (const auto& [key, value] : dups) {
		if (value > 1) {
			repeated = true;
		}
		std::cout << key << ':' << value << std::endl;
	}

	if (repeated) {
		std::cout << "List has repeated elements";
	} else {
		std::cout << "List does not contain repeated elements";
	}
	std::cout << std::endl;
}


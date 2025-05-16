#include "stdio.h"

int main() {
	int m = 25;
	int n = 15;
	
	// brute force
	for (int i=1; i < m; i++) {
		if (m % i == 0 && n % i == 0) {
			printf("Both divisible by %d\n", i);
		}
	}
	// euclid's algorithm for GCD
	m = 12;
	n = 7;
	int r = m % n;
	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	printf("Using Euclid's algorithm: %d\n", n);
}

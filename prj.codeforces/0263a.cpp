#include <iostream>
 

int main() {
	// центр: i, j: (2, 2)
	int x = 0, y = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int t = 0;
			std::cin >> t;
			if (t == 1) {
				x = i, y = j;
			}
		}
	}
	int count = std::fabs(x - 2) + std::fabs(y - 2);
	std::cout << count;
	return 0;
}

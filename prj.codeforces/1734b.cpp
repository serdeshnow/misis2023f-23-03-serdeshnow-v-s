#include <iostream>
 
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				int a = j;
				if (a == 0) {
					std::cout << "1 ";
				}
				else if (a == i) {
					std::cout << "1";
				}
				else {
					std::cout << "0 ";
				}
			}
			std::cout << std::endl;
		}
	}
	return 0;
}

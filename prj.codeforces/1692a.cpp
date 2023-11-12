#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int a = 0; // Timur
		int b = 0;
		int c = 0;
		int d = 0;
		std::cin >> a >> b >> c >> d;
		int count = 0;
		if (a < b) {
			count++;
		}
		if (a < c) {
			count++;
		}
		if (a < d) {
			count++;
		}
		std::cout << count << std::endl;
	}
	return 0;
}
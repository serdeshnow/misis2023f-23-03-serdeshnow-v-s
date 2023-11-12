#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if ((a + b == c) || (a + c == b) || (b + c == a)) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}

	return 0;
}

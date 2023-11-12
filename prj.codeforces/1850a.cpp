#include <iostream>


int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int a = 0, b = 0, c = 0;
		std::cin >> a >> b >> c;
		std::cout << (a + b >= 10 || a + c >= 10 || b + c >= 10 ? "YES\n" : "NO\n");
	}
	return 0;
}

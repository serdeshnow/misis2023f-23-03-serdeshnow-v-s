#include <iostream>
 
int main() {
	int t = 0;
	std::cin >> t;
	int count = 0;
	while (t--) {
		int a = 0, b = 0, c = 0;
		std::cin >> a >> b >> c;
		if ((a + b + c) > 1) {
			count++;
		}
	}
	std::cout << count;
	return 0;
}

#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		int winner = 0;
		int max_score = 0;
		for (int i = 0; i < n; i++) {
			int a = 0;
			int b = 0;
			std::cin >> a >> b;
			if (a <= 10 && max_score < b) {
				max_score = b;
				winner = a;
			}
		}
		std::cout << winner;
	}
	return 0;
}
//158a
#include <iostream>
#include <string>

int main() {
	int n = 8;
	std::cin >> n;
	int k = 5;
	std::cin >> k;
	int count = 0;
	int min_score = 100;
	for (int i = 0; i < n; i++) {
		int a = 0;
		std::cin >> a;
		if ((0 < a) && (i < k)) {
			count++;
			min_score = std::min(min_score, a);
		}
		else if (a == min_score) {
			count++;
		}
		else {
			break;
		}
	}
	std::cout << count;
	return 0;
}

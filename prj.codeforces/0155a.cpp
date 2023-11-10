#include <iostream>
 
int main() {
	int n, cnt = 0;
	std::cin >> n;
	int l_max = 0, l_min = 0, now = 0;
	std::cin >> now;
	l_min = now, l_max = now;
	for (int i = 0; i < n - 1; i++) {
		std::cin >> now;
		if (now > l_max) {
			cnt++;
			l_max = now;
		}
		else if (now < l_min){
			cnt++;
			l_min = now;
		}
		else {
			continue;
		}
	}
	std::cout << cnt;
	return 0;
}

#include <iostream>
 
int main() {
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	int min_hours = 100000;
	while (n--) {
		int a = 0;
		std::cin >> a;
		if ((k % a == 0) && ((k / a) < min_hours)) {
			min_hours = (k / a);
		}
	}
	std::cout << min_hours;
	return 0;
}

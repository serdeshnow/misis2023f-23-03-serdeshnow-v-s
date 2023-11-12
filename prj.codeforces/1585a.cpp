#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t != 0) {
		int hight = 1;
		int n = 0;
		std::cin >> n;
		int a = -1, a0 = -2;
		while (n != 0) {
			std::cin >> a;
			if (a == 0 && a0 == a) {
				hight = -1000;
			}
			else if (a == 1 && a0 != 1){
				hight++;
			}
			else if (a == 1 && a0 == a) {
				hight += 5;
			}
			a0 = a;
			n--;
		}
		if (hight < 0) {
			std::cout << -1 << std::endl;
		}
		else {
			std::cout << hight << std::endl;
		}
		t--;
	}
	return 0;
}

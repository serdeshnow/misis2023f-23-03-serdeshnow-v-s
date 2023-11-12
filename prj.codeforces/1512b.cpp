//1512b
#include <iostream>
#include <string>

int main() {
	int t = 1;
	std::cin >> t;
	while (t--) {
		int i1 = -1, j1 = -1, i2 = -1, j2 = -1;
		int n = 0;
		std::cin >> n;
		int count = 1;
		for (int i = 0; i < n; i++) {
			std::string str;
			std::cin >> str;
			for (int j = 0; j < n; j++) {
				if (str[j] == '*' && count == 1) {
					i1 = i;
					j1 = j;
					count = 2;
				}
				else if (str[j] == '*' && count == 2) {
					i2 = i;
					j2 = j;
				}
			}
		}
		if (j1 == j2 && j1 > 0) {
			j2 = 0;
		}
		else if (j1 == j2 && j1 == 0) {
			j2 = 1;
		}
		if (i1 == i2 && i1 > 0) {
			i2 = 0;
		}
		else if (i1 == i2 && i1 == 0) {
			i2 = 1;
		}


		for (int x = 0; x < n; x++) {
			std::string new_str;
			for (int y = 0; y < n; y++) {
				if ((x == i1 && y == j1) || (x == i1 && y == j2) || (x == i2 && y == j2) || (x == i2 && y == j1)) {
					new_str += '*';
				}
				else {
					new_str += '.';
				}
			}
			std::cout << new_str << std::endl;
		}


	}
	return 0;
}

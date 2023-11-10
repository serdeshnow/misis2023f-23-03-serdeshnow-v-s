#include <iostream>
//#include <string>
 
 
int main() {
	int t = 1;
	std::cin >> t;
	while (t--) {
		int count = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				char c;
				std::cin >> c;
				if (((i == 0 || i == 9) && (c == 'X')) || ((0 <= i <= 9) && (j == 0 || j == 9) && (c == 'X')) ){
					count += 1;
				}
				else if ( ((i == 1 || i == 8) && (1 <= j <= 8) && (c == 'X')) || ((1 <= i <= 8) && (j == 1 || j == 8) && (c == 'X'))) {
					count += 2;
				}
				else if (((i == 2 || i == 7) && (2 <= j <= 7) && (c == 'X')) || ((2 <= i <= 7) && (j == 2 || j == 7) && (c == 'X'))) {
					count += 3;
				}
				else if (((i == 3 || i == 6) && (3 <= j <= 6) && (c == 'X')) || ((3 <= i <= 6) && (j == 3 || j == 6) && (c == 'X'))) {
					count += 4;
				}
				else if ((i == 4 || i == 5) && (4 <= j <= 5) && (c == 'X')) {
					count += 5;
				}
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}

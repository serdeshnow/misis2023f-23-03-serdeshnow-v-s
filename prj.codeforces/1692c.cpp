//1692C
#include <iostream>
#include <string>
 
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int r = 0, c = 0;
		bool flag = false; // Нашел расположение?
		for (int i = 0; i < 8; i++) {
			std::string str;
			std::cin >> str;
			for (int j = 0; j < 8 - 2; j++) {
				if (str[j] == '#' && str[j + 2] == '#' && flag == false) {
					flag = true;
					r = i + 2;
					c = j + 2;
				}
			}
		}
		std::cout << r << ' ' << c << std::endl;
	}
	return 0;
}

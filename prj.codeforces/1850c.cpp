//1850c
#include <iostream>
#include <string>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		std::string word;
		//int line = -1;
		for (int i = 0; i < 8; i++) {
			std::string str;
			std::cin >> str;
			for (int j = 0; j < 8; j++) {
				if (str[j] != '.') {
					//line = j;
					word += str[j];
				}
			}
		}
		std::cout << word << std::endl;
	}

	return 0;
}

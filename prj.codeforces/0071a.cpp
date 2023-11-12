//71a
#include <iostream>
#include <string>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		std::string str;
		std::cin >> str;
		std::string new_str = str;
		if (str.size() > 10){
			new_str = str[0] + std::to_string(str.size() - 2) + str[str.size() - 1];
		}
		std::cout << new_str << std::endl;
	}
	return 0;
}


	#include <iostream>
	#include <string>
 
	int main() {
		std::string str;
		//std::string str = "zeus";
		std::cin >> str;
		str = "a" + str;
		int count = 0;
		for (int i = 1; i < str.size(); i++) {
			int diff = std::fabs(int(str[i]) - int(str[i - 1]));
			if (diff > 12) {
				count += std::fabs(26 - diff);
				//std::cout << std::fabs(26 - diff) << std::endl;
			}
			else {
				count += std::fabs(diff);
				//std::cout << std::fabs(diff) << std::endl;
			}
 
		}
		std::cout << count;
		return 0;
	}

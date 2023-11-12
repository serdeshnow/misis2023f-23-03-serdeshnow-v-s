#include <iostream>
#include <string>
 
int main() {
	std::string str;

	std::cin >> str;
	str = "a" + str;
	int count = 0;
	for (int i = 1; i < str.size(); i++) {
		int diff = std::fabs(int(str[i]) - int(str[i - 1]));
		if (diff > 12) {
			count += std::fabs(26 - diff);
		}
		else {
			count += std::fabs(diff);
		}
 
	}
	std::cout << count;
	return 0;
}
